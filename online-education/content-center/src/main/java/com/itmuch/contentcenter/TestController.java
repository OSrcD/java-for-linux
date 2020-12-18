package com.itmuch.contentcenter;


import com.alibaba.csp.sentinel.annotation.SentinelResource;
import com.alibaba.csp.sentinel.slots.block.RuleConstant;
import com.alibaba.csp.sentinel.slots.block.flow.FlowRule;
import com.alibaba.csp.sentinel.slots.block.flow.FlowRuleManager;
import com.itmuch.contentcenter.dao.content.ShareMapper;


import com.itmuch.contentcenter.domain.dto.user.UserDTO;
import com.itmuch.contentcenter.domain.entity.content.Share;
import com.itmuch.contentcenter.feignclient.TestBaiduFeignClient;
import com.itmuch.contentcenter.feignclient.TestUserCenterFeignClient;
import com.itmuch.contentcenter.sentineltest.TestControllerBlockHandlerClass;
import lombok.extern.slf4j.Slf4j;
import org.apache.commons.lang.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.cloud.context.config.annotation.RefreshScope;
import org.springframework.cloud.stream.messaging.Source;
import org.springframework.http.HttpEntity;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpMethod;
import org.springframework.http.ResponseEntity;
import org.springframework.messaging.support.MessageBuilder;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import org.springframework.cloud.client.discovery.DiscoveryClient;
import org.springframework.cloud.client.ServiceInstance;
import org.springframework.web.client.RestTemplate;

import javax.servlet.http.HttpServletRequest;

@Slf4j
@RestController
@RefreshScope
public class TestController {

    @Autowired
    private ShareMapper shareMapper;


    @Autowired
    private DiscoveryClient discoveryClient;

    @GetMapping("/test")
    public List<Share> testInsert(){

        Share share = new Share();
        share.setCreateTime(new Date());
        share.setUpdateTime(new Date());
        share.setCover("xxx");
        share.setTitle("xxx");
        share.setAuthor("大目");
        share.setBuyCount(3);
        this.shareMapper.insertSelective(share);

        List<Share> shares = this.shareMapper.selectAll();

        return shares;
    }

    /**
     * 测试：服务发现，证明内容中心总能找到用户中心
     * @return 用户中心所有实例的地址信息
     */
    @GetMapping("/test2")
    public List<ServiceInstance> getInstances(){
        // 查询指定服务的所有实例的信息
        // consul/eureka/zookeeper...
        return this.discoveryClient.getInstances("user-center");
    }



    @Autowired
    private TestUserCenterFeignClient testUserCenterFeignClient;

    @GetMapping("/test-get")
    public UserDTO query(UserDTO userDTO){
        return this.testUserCenterFeignClient.query(userDTO);
    }


    @Autowired
    private TestBaiduFeignClient testBaiduFeignClient;

    @GetMapping("baidu")
    public String Baiduindex(){
        return this.testBaiduFeignClient.index();
    }


    @Autowired
    private TestService testService;

    @GetMapping("test-a")
    public String testA(){
        this.testService.common();
        return "test-a";
    }

    @GetMapping("test-b")
    public String testB(){
        this.testService.common();
        return "test-b";
    }

    @GetMapping("test-hot")
    @SentinelResource("hot")
    public String testhot(
            @RequestParam(required = false) String a,
            @RequestParam(required = false) String b
    ){
        return a+" "+b;
    }


    @GetMapping("test-add-flow-rule")
    public String testhot(){
        this.initFlowOpsRule();
        return "success";
    }

    private void initFlowOpsRule(){

       List<FlowRule> rules = new ArrayList<>();
       FlowRule rule = new FlowRule("/shares/1");
       rule.setCount(20);
       rule.setGrade(RuleConstant.FLOW_GRADE_QPS);
       rule.setLimitApp("default");
       rules.add(rule);
       FlowRuleManager.loadRules(rules);

    }


    @GetMapping("/test-sentinel-resource")
    @SentinelResource(value = "test-sentinel-api",blockHandler = "block",
                    blockHandlerClass = TestControllerBlockHandlerClass.class,
                    fallback = "fallback")
    public String testSentinelApi(
            @RequestParam(required = false)String a){

        if(StringUtils.isEmpty(a)){
            throw new IllegalArgumentException("a cannot be blank");
        }

        return a;

    }

    /**
     * 处理限流或者降级
     * @param a
     * @param e
     * @return
     */
//    public String block(String a,BlockException e){
//        log.warn("限流或者降级 block",e);
//        return "限流或者降级 block";
//    }

    /**
     * 处理降级
     * @param a
     * @return
     */

    public String fallback(String a){
        log.warn("限流或者降级 fallback");
        return "限流或者降级 fallback";
    }

    @Autowired
    private RestTemplate restTemplate;

    @GetMapping("/test-rest-template-sentinel/{userId}")
    public UserDTO test(@PathVariable Integer userId){
        return this.restTemplate.getForObject(
                "http://user-center/users/{userId}",
                UserDTO.class,
                userId);
    }

    @GetMapping("/tokenRelay/{userId}")
    public ResponseEntity<UserDTO> tokenRelay(@PathVariable Integer userId,HttpServletRequest reuqest){
        String token = reuqest.getHeader("X-Token");

        HttpHeaders headers = new HttpHeaders();
        headers.add("X-Token",token);

        return this.restTemplate.exchange(
                "http://user-center/users/{userId}",
                HttpMethod.GET,
                new HttpEntity<>(headers),
                UserDTO.class,
                userId
        );
    }


    @Value("${spring.datasource.url}")
    private String YourConfiguration;

    @GetMapping("/test-config")
    public String testConfig(){

        return this.YourConfiguration;
    }



}
