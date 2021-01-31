package com.imooc.springcloud.topic;

import org.springframework.cloud.stream.annotation.Input;
import org.springframework.cloud.stream.annotation.Output;
import org.springframework.messaging.MessageChannel;
import org.springframework.messaging.SubscribableChannel;

/**
 * input 指的是接收消息的那一端
 * 也就是消费者
 * output 指生产消息的那一端
 * 也就是生产者
 */
public interface DlqTopic {

    /**
     * 把两个 信道绑定在一起
     */
    String INPUT = "dlq-consumer";

    String OUTPUT = "dlq-producer";

    // topic的名称
    @Input(INPUT)
    SubscribableChannel input();

    /**
     * INPUT 会当成一个 Bean 的 name
     * 相当于声明了 2 个 Bean 都有同样的 name Spring 启动的时候就会报错
     */
    @Output(OUTPUT)
    MessageChannel output();

}
