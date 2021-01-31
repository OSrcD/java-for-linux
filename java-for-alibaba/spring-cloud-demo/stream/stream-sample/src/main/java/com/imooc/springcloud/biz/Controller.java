package com.imooc.springcloud.biz;

import com.imooc.springcloud.topic.*;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.messaging.support.MessageBuilder;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
@Slf4j
public class Controller {

    @Autowired
    private MyTopic producer;

    @Autowired
    private GroupTopic groupTopicProducer;

    @Autowired
    private DelayedTopic delayedTopicProducer;

    @Autowired
    private ErrorTopic errorTopicProducer;

    @Autowired
    private RequeueTopic requeueTopicProducer;

    @Autowired
    private DlqTopic dlqTopicProducer;

    @Autowired
    private FallbackTopic fallbackTopicProducer;


    @PostMapping("send")
    public void sendMessage(@RequestParam(value = "body") String body) {
        producer.output().send(MessageBuilder.withPayload(body).build());
    }

    @PostMapping("sendToGroup")
    public void sendMessageToGroup(@RequestParam(value = "body") String body) {
        groupTopicProducer.output().send(MessageBuilder.withPayload(body).build());
    }

    @PostMapping("sendDM")
    public void sendDelayedMessage(@RequestParam(value = "body") String body,
                                   @RequestParam(value = "seconds") Integer seconds) {
        MessageBean msg = new MessageBean();
        msg.setPayload(body);
        log.info("ready to send delayed message");
        delayedTopicProducer.output().send(
                MessageBuilder.withPayload(msg)
                        /**
                         * x-delay 延迟消息就会把它延迟多少秒之后 送达到消费者这里
                         */
                        .setHeader("x-delay",1000 * seconds)
                        .build());
    }


    /**
     * 异常重试（单机版）
     * 只会在本机重试 也就是说是在Consumer 范围内的重试
     */
    @PostMapping("sendError")
    public void sendErrorMessage(@RequestParam(value = "body") String body) {
        MessageBean msg = new MessageBean();
        msg.setPayload(body);
        errorTopicProducer.output().send(MessageBuilder.withPayload(msg).build());
    }

    /**
     * 异常重试（联机版 - 重新入队）
     */
    @PostMapping("requeue")
    public void sendErrorMessageToMQ(@RequestParam(value = "body") String body) {
        MessageBean msg = new MessageBean();
        msg.setPayload(body);
        requeueTopicProducer.output().send(MessageBuilder.withPayload(msg).build());
    }

    /**
     * 死信队列测试
     */
    @PostMapping("dlq")
    public void sendMessageToDlq(@RequestParam(value = "body") String body) {
        MessageBean msg = new MessageBean();
        msg.setPayload(body);
        dlqTopicProducer.output().send(MessageBuilder.withPayload(msg).build());
    }

    /**
     * fallback + 升版
     */
    @PostMapping("fallback")
    public void sendMessageToFallback(
            @RequestParam(value = "body") String body,
            @RequestParam(value = "version", defaultValue = "1.0") String version) {
        MessageBean msg = new MessageBean();
        msg.setPayload(body);

        /**
         * 假设现在是一个电商场景 我们要调用下单接口
         * 不同的手机APP 可能调用接口的版本 不同的
         * 比如我的老版本 调用的接口可能是叫 下单v1
         * 升级过后的app 可能是调用 下单v2
         * 在调用的时候 我可以决定去调用哪个逻辑
         * 把这些接口的方案 类比到我们消息驱动场景中
         * 我们在调用下游方法（客户端） 也就是说 我们在生成
         * 这条message的时候 一定要指定好接下来要调用哪个版本
         * 我们可以把这个message 发送到不同的queue
         * 比如 queue 1
         * 新的业务逻辑可能发到 queue 2
         * 还有一种更简单的
         * 它不需要你上游（服务器）代码做更多的改动 只用传递一个信息到下游
         *
         */

        fallbackTopicProducer.output().send(
                MessageBuilder.withPayload(msg)
                .setHeader("version", version)
                .build());
    }



}
