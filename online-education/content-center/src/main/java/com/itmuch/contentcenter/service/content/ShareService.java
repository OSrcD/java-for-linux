package com.itmuch.contentcenter.service.content;

import com.alibaba.fastjson.JSON;
import com.github.pagehelper.PageHelper;
import com.github.pagehelper.PageInfo;
import com.itmuch.contentcenter.dao.content.MidUserShareMapper;
import com.itmuch.contentcenter.dao.content.ShareMapper;
import com.itmuch.contentcenter.dao.messaging.RocketmqTransactionLogMapper;
import com.itmuch.contentcenter.domain.dto.content.ShareAuditDTO;
import com.itmuch.contentcenter.domain.dto.content.ShareDTO;
import com.itmuch.contentcenter.domain.dto.messaging.UserAddBonusMsgDTO;
import com.itmuch.contentcenter.domain.dto.user.UserAddBonusDTO;
import com.itmuch.contentcenter.domain.dto.user.UserDTO;
import com.itmuch.contentcenter.domain.entity.content.MidUserShare;
import com.itmuch.contentcenter.domain.entity.content.Share;

import com.itmuch.contentcenter.domain.entity.messaging.RocketmqTransactionLog;
import com.itmuch.contentcenter.enums.AuditStatusEnum;
import com.itmuch.contentcenter.feignclient.UserCenterFeignClient;
import lombok.extern.slf4j.Slf4j;

import org.apache.rocketmq.spring.core.RocketMQTemplate;
import org.apache.rocketmq.spring.support.RocketMQHeaders;
import org.springframework.beans.BeanUtils;
import org.springframework.cloud.client.ServiceInstance;
import org.springframework.cloud.client.discovery.DiscoveryClient;

import org.springframework.cloud.stream.messaging.Source;
import org.springframework.messaging.support.MessageBuilder;
import org.springframework.stereotype.Service;
import lombok.RequiredArgsConstructor;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.client.RestTemplate;

import javax.servlet.http.HttpServletRequest;
import java.util.List;
import java.util.Objects;
import java.util.UUID;
import java.util.stream.Collectors;
import java.util.concurrent.ThreadLocalRandom;
@Service
@RequiredArgsConstructor(onConstructor = @__(@Autowired))
@Slf4j
public class ShareService {

    private final ShareMapper shareMapper;
    private final RestTemplate restTemplate;
    private final UserCenterFeignClient userCenterFeignClient;
    private final RocketMQTemplate rocketMQTemplate;
    private final RocketmqTransactionLogMapper rocketmqTransactionLogMapper;
    private final Source source;
    private final MidUserShareMapper midUserShareMapper;

    public ShareDTO findById(Integer id){

        // 获取分享详情
       Share share = this.shareMapper.selectByPrimaryKey(id);
        // 发布人Id
       Integer userId = share.getUserId();




        UserDTO userDTO = this.userCenterFeignClient.findById(userId);

        ShareDTO shareDTO = new ShareDTO();

        //消息装配
        BeanUtils.copyProperties(share,shareDTO);

        shareDTO.setWxNickname(userDTO.getWxNickname());


        return shareDTO;

    }



    public static void main(String[] args) {


    }

//    @Transactional(rollbackFor = Exception.class) 因为这里没有执行数据库插入更新操作
    public Share auditById(Integer id, ShareAuditDTO auditDTO) {

        // 1.查询share是否存在，不存在或者当前audit_status != NOT_YET，那么抛异常
        Share share = this.shareMapper.selectByPrimaryKey(id);
        if(share == null){
            throw new IllegalArgumentException("参数非法！该分享不存在！");
        }
        if(!Objects.equals("NOT_YET",share.getAuditStatus())){
            throw new IllegalArgumentException("参数非法！该分享已审核通过或审核不通过！");
        }


        // 3.如果是PASS，那么发送消息给rocketmq，认用户中心去消费，并为发布人添加积分

        // 判断是否为PASS
        if(AuditStatusEnum.PASS.equals(auditDTO.getAuditStatusEnum())){

            // 1.获得随机的UUID,作为transactionId
            String transactionId = UUID.randomUUID().toString();

            /**
             * 作用：在分布式事务发送半消息，发给MQ，数据库里没有执行，半消息发送成功会
             * 回调executeLocalTransaction方法
             * txProducerGroup：事务生产者组名称
             * destination：消息种类名称
             * Message：建立一个消息体内容，消息头对象
             * arg：附带的额外参数传递
             */
            this.source.output().send(
                    MessageBuilder.withPayload(
                            // 发送的消息体接收是一个String
                            UserAddBonusMsgDTO.builder()
                                    .userId(share.getUserId())
                                    .bonus(50)
                                    .build()
                    )
                            .setHeader(RocketMQHeaders.TRANSACTION_ID,transactionId)
                            .setHeader("share_id",id)
                            // 把对象转成json
                            .setHeader("dto", JSON.toJSONString(auditDTO))
                            .build()
            );

        }else{
            // 不是PASS的情况直接提交到数据库即可
            this.auditByIdInDB(id,auditDTO);
        }



        return share;
    }

    /**
     * 审核资源，将状态设为PASS/REJECT，在executeLocalTransaction方法里面执行这个事务
     * @param id 用户id
     * @param auditDTO 审核状态、理由对象
     */
    @Transactional(rollbackFor = Exception.class)
    public void auditByIdInDB(Integer id,ShareAuditDTO auditDTO) {


        //从浏览器传过来的id、auditDTO，构造一个share对象
        Share share = Share
                      .builder()
                      .id(id)
                      .auditStatus(auditDTO.getAuditStatusEnum().toString())
                      .reason(auditDTO.getReason())
                      .build();
        //提交更新到share数据库
        this.shareMapper.updateByPrimaryKeySelective(share);
    }

        /**
         * 执行事务，记录到事务日志数据库
         * @param id
         * @param shareAuditDTO
         * @param transactionId
         */
        @Transactional(rollbackFor = Exception.class)
        public void auditByIdWithRocketMqLog(Integer id,ShareAuditDTO shareAuditDTO,String transactionId){

            //执行事务
            this.auditByIdInDB(id,shareAuditDTO);
            this.rocketmqTransactionLogMapper.insertSelective(
              RocketmqTransactionLog.builder()
                      .transactionId(transactionId)
                      .log("审核分享...")
                      .build()
            );



        }

    public PageInfo<Share> q(String title, Integer pageNo, Integer pageSize, Integer userId) {

        //插入自动分页sql
        PageHelper.startPage(pageNo,pageSize);

        //不分页的自定义sql
        List<Share> shares = this.shareMapper.selectByParam(title);
        List<Share> sharesDeal;

        // 1.如果用户未登录，那么downloadUrl全部设为null
        if(userId == null){
            sharesDeal = shares.stream()
                    .peek(share -> {
                        share.setDownloadUrl(null);
                    }).collect(Collectors.toList());

        }else{
            // 2.如果用户登录了，那么查询一下mid_user_share,如果没有数据，
            // 那么这条share的downloadUrl也设为null
            sharesDeal = shares.stream()
                    .peek(share -> {
                        MidUserShare midUserShare = this.midUserShareMapper.selectOne(
                                MidUserShare
                                        .builder()
                                        .shareId(share.getId())
                                        .userId(userId)
                                        .build()
                        );

                        if(midUserShare == null){
                            share.setDownloadUrl(null);
                        }

                    }).collect(Collectors.toList());

        }








        return new PageInfo<>(sharesDeal);
    }

    public Share exchangeById(Integer id, HttpServletRequest request) {

        Object userId = request.getAttribute("id");
        Integer integerUserId = (Integer) userId;


        // 1.根据id查询share，校验是否存在
        Share share = this.shareMapper.selectByPrimaryKey(id);
        if(share==null){
            throw new IllegalArgumentException("该分享不存在！");
        }
        Integer price = share.getPrice();

        // 2.如果当前用户已经兑换过该分享，则直接返回
        MidUserShare midUserShare = this.midUserShareMapper.selectOne(
                MidUserShare.builder()
                        .shareId(id)
                        .userId(integerUserId)
                        .build()
        );


        if(midUserShare != null){
            return share;
        }

        // 3.根据当前登录的用户Id，查询积分是否够

        UserDTO userDTO = this.userCenterFeignClient.findById(integerUserId);


        if(price > userDTO.getBonus()){
            throw new IllegalArgumentException("用户积分不够！");
        }

        // 4.扣除积分并往mid_user_share里插入一条数据
         this.userCenterFeignClient.addBonus(
                 UserAddBonusDTO.builder()
                         .userId(integerUserId)
                         .bonus(0- price)
                         .build()
         );

        /**
         * 插入中间表数据库
         */
        this.midUserShareMapper.insert(
           MidUserShare
                   .builder()
                   .userId(integerUserId)
                   .shareId(id)
                   .build()
         );

        // 返回兑换的分享
        return share;
    }
}
