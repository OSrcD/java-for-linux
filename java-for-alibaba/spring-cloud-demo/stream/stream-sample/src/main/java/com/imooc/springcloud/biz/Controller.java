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



}
