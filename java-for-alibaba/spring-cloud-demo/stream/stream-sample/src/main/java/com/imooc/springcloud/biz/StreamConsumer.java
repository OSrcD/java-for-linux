package com.imooc.springcloud.biz;

import com.imooc.springcloud.topic.*;
import lombok.extern.slf4j.Slf4j;
import org.springframework.cloud.stream.annotation.EnableBinding;
import org.springframework.cloud.stream.annotation.StreamListener;
import org.springframework.cloud.stream.messaging.Sink;

import java.util.concurrent.atomic.AtomicInteger;

@Slf4j
/**
 * 启动绑定信道
 * 就是说 Binder与中间件之间绑定的信道接口 接口可以理解为规定好的行为类型的地址
 * 单纯的配置项 不定义在这里也可以 定义到启动类里面都可以
 */
@EnableBinding(value = {

        /**
         * value 可以绑定信道名称
         * Stream 的上下文就会把这个类当做一个可绑定的信道
         * 加入进初始化流程当中
         * 信道跟Topic（主题） 类似的功能 可以看成同一种概念
         * MyTopic.class 通过这种方式我们可以自定义一个信道，将
         * 自定义的主题绑定到EnableBinding注解的下面，这样我们就可以通过Controller触发生产者消息发送，
         * 然后在看消费者是如何消费这个消息的
         * 并且把它加入到上下文当中
         *
         */
        Sink.class,
        MyTopic.class,
        GroupTopic.class,
        DelayedTopic.class,
        ErrorTopic.class,
        RequeueTopic.class,
        DlqTopic.class
    }
)
public class StreamConsumer {

    // 线程安全的计数器变量
    private AtomicInteger count = new AtomicInteger(1); // 起始值


    /**
     * 怎么知道 该去rabbitmq 拿那个消息信道中的消息呢？给它指示
     * 传入一个信道的名称
     * sink 它是messaging 给我们提供的一个默认信道
     * @Input("input") 会自动为我们创建一个
     * SubscribableChannel 一个可被订阅的 channel通信通道
     * 通道的名称就是 Sink.INPUT  指定的值 默认为input
     * @StreamListener 将信道绑定到当前的这个方法上 和 RabbitMQ中的主题进行关联
     * 我们的方法体也就能够监听这个信道生成的消息去进行消费
     * 默认目的地信道接口 Sink 翻译为目的地
     * 被注解之后通道与这个类通过反射绑定起来 从应用程序绑定到一起 多个
     * 当binder与消息中间件通信 发送消息过来 通过反射实例化对象执行这些方法
     *
     */
    @StreamListener(Sink.INPUT) // 这里的值就是 "input"
    public void consume(Object payload) {

        log.info("message consumed successfully，payload={}", payload);
    }
    @StreamListener(MyTopic.INPUT)
    public void consumeMyMessage(Object payload) {

        log.info("My message consumed successfully，payload={}", payload);
    }

    @StreamListener(GroupTopic.INPUT)
    public void consumeGroupMyMessage(Object payload) {
        log.info("Group message consumed successfully，payload={}", payload);
    }

    @StreamListener(DelayedTopic.INPUT)
    public void consumeDelayedMessage(MessageBean bean) {
        log.info("Delayed message consumed successfully，payload={}", bean.getPayload());
    }





    // 异常重试（单机版）
    @StreamListener(ErrorTopic.INPUT)
    public void consumeErrorMessage(MessageBean bean) {
        log.info("Are you OK?");

        // 自增 1 如果能被 3 整除 才能消费这条消息
        if (count.incrementAndGet() % 3 == 0) {
            log.info("Fine, thank you. And you?");
            // 成功消息以后 计数器 清 0
            count.set(0);
        } else {
            log.info("What's your problem?");
            throw new RuntimeException("I'm not OK");
        }

    }

    /**
     * 异常重试（联机版-重新入队）
     */
    @StreamListener(RequeueTopic.INPUT)
    public void requeueErrorMessage(MessageBean bean) {
        log.info("Are you OK?");
        try {
            Thread.sleep(3000L);
        } catch (Exception e) {
        }
        throw new RuntimeException("I'm not OK");
    }

    // 死信队列
    @StreamListener(DlqTopic.INPUT)
    public void consumeDlqMessage(MessageBean bean) {
        log.info("Dlq - Are you OK?");

        // 自增 1 如果能被 3 整除 才能消费这条消息
        if (count.incrementAndGet() % 3 == 0) {
            log.info("Dlq - Fine, thank you. And you?");
        } else {
            log.info("Dlq - What's your problem?");
            throw new RuntimeException("I'm not OK");
        }

    }


}
