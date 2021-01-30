package com.imooc.springcloud.biz;

import lombok.extern.slf4j.Slf4j;
import org.springframework.cloud.stream.annotation.EnableBinding;
import org.springframework.cloud.stream.annotation.StreamListener;
import org.springframework.cloud.stream.messaging.Sink;

@Slf4j
/**
 * 启动绑定信道
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
        Sink.class

    }
)
public class StreamConsumer {

    /**
     * 怎么知道 该去rabbitmq 拿那个消息信道中的消息呢？给它指示
     * 传入一个信道的名称
     * sink 它是messaging 给我们提供的一个默认信道
     * @Input("input") 会自动为我们创建一个
     * SubscribableChannel 一个可被订阅的 channel通信通道
     * 通道的名称就是 Sink.INPUT  指定的值 默认为input
     * @StreamListener 将信道绑定到当前的这个方法上 和 RabbitMQ中的主题进行关联
     * 我们的方法体也就能够监听这个信道生成的消息去进行消费
     * 默认信道接口 Sink
     */
    @StreamListener(Sink.INPUT)
    public void consume(Object payload) {

        log.info("message consumed successfully，payload={}", payload);
    }
}
