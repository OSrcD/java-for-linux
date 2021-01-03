package com.itmuch.contentcenter.rocketmq;

import com.alibaba.fastjson.JSON;
import com.itmuch.contentcenter.dao.messaging.RocketmqTransactionLogMapper;
import com.itmuch.contentcenter.domain.dto.content.ShareAuditDTO;
import com.itmuch.contentcenter.domain.entity.messaging.RocketmqTransactionLog;
import com.itmuch.contentcenter.service.content.ShareService;
import lombok.RequiredArgsConstructor;
import org.apache.rocketmq.spring.annotation.RocketMQTransactionListener;
import org.apache.rocketmq.spring.core.RocketMQLocalTransactionListener;
import org.apache.rocketmq.spring.core.RocketMQLocalTransactionState;
import org.apache.rocketmq.spring.support.RocketMQHeaders;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.messaging.Message;
import org.springframework.messaging.MessageHeaders;

// 与sendMessageInTransaction第一个参数对应
@RocketMQTransactionListener(txProducerGroup = "tx-add-bonus-group")
@RequiredArgsConstructor(onConstructor = @__(@Autowired))
public class AddBonusTransactionListener implements RocketMQLocalTransactionListener {

    private final ShareService shareService;
    private final RocketmqTransactionLogMapper rocketmqTransactionLogMapper;
    /**
     * 半消息发送成功后MQ会进行二次确认执行方法是提交事务还是回滚事务，也会发送到MQServer
     * @param msg MessageBuilder的消息体和消息头
     * @param arg args里面的参数
     * @return
     */
    @Override
    public RocketMQLocalTransactionState executeLocalTransaction(Message msg, Object arg) {
        // 拿到消息头
        MessageHeaders headers = msg.getHeaders();

        // 拿到消息头的transactionId
        String transactionId = (String)headers.get(RocketMQHeaders.TRANSACTION_ID);

        // 拿到share_id
        Integer shareId = Integer.valueOf((String)headers.get("share_id"));

        String dtoString = (String)headers.get("dto");

        // 反序列化为对象
        ShareAuditDTO auditDTO = JSON.parseObject(dtoString,ShareAuditDTO.class);

        try {
            //提交事务
            // this.shareService.auditByIdInDB(shareId, (ShareAuditDTO) arg);
            // 方法被封装到WithRocketMqLog里面
            this.shareService.auditByIdWithRocketMqLog(shareId,auditDTO,transactionId);
            //提交Commit状态给MQ
            return RocketMQLocalTransactionState.COMMIT;
        }catch(Exception e){
            //回滚事务状态给MQ
            return RocketMQLocalTransactionState.ROLLBACK;
        }

    }

    /**
     * 没有收到半消息二次确认会回调这个方法
     * @param msg
     * @return
     */
    @Override
    public RocketMQLocalTransactionState checkLocalTransaction(Message msg) {

        // 拿到消息头
        MessageHeaders headers = msg.getHeaders();
        // 拿到消息头的transactionId
        String transactionId = (String)headers.get(RocketMQHeaders.TRANSACTION_ID);

        //查询一条事务表日志数据
        //select * from xxx where transaction_id = xxx
        RocketmqTransactionLog rocketmqTransactionLog = this.rocketmqTransactionLogMapper.selectOne(
                RocketmqTransactionLog.builder()
                        .transactionId(transactionId)
                        .build()
        );

        //再次提交已经提交事务过的消息到MQServicer
        if(rocketmqTransactionLog != null){
            return RocketMQLocalTransactionState.COMMIT;
        }

        //没有查询到数据就回滚
        return RocketMQLocalTransactionState.ROLLBACK;
    }
}
