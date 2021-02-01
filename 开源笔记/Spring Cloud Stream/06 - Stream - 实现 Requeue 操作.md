![](https://tcs.teambition.net/storage/31228521c1847d183c15167e098a71e78fbb?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA4MywiaWF0IjoxNjEyMTkwMjgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI4NTIxYzE4NDdkMTgzYzE1MTY3ZTA5OGE3MWU3OGZiYiJ9.bSuulTC6blaNOjU9Jf9pofMPSQlBjL98llAPG1FE0bU&download=2020-09-17%20061715.png "")

死信队列 就是一些无法被消费的消息了

![](https://tcs.teambition.net/storage/3122e73b9e5c2a9fa09beb148cd19f91e6ad?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA4MywiaWF0IjoxNjEyMTkwMjgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJlNzNiOWU1YzJhOWZhMDliZWIxNDhjZDE5ZjkxZTZhZCJ9.QJAwhFBXJZR67xsz37tXPVvVHHOMt0hOvCR2VtdCw1Q&download=image.png "")

![](https://tcs.teambition.net/storage/3122f9b70354aea6593bd1d49e9770eed070?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA4MywiaWF0IjoxNjEyMTkwMjgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJmOWI3MDM1NGFlYTY1OTNiZDFkNDllOTc3MGVlZDA3MCJ9.Yv22YfDrcMIMnQKhmiyRpHtRWrnlkoHefxfjBkPFdy8&download=image.png "")

```java
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
public interface RequeueTopic {

    /**
     * 把两个 信道绑定在一起
     */
    String INPUT = "requeue-consumer";

    String OUTPUT = "requeue-producer";

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

```

![](https://tcs.teambition.net/storage/3122215dfdd05a6a542e693b314ed2582b57?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA4MywiaWF0IjoxNjEyMTkwMjgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIyMTVkZmRkMDVhNmE1NDJlNjkzYjMxNGVkMjU4MmI1NyJ9.Y-NEtQRJl9c-Y8a51G4H1Im3YQHGbZHTt1w_a70qLuM&download=image.png "")

```java
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

}

```

![](https://tcs.teambition.net/storage/31225000972e5e64d33e72c9c17de01711d0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA4MywiaWF0IjoxNjEyMTkwMjgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI1MDAwOTcyZTVlNjRkMzNlNzJjOWMxN2RlMDE3MTFkMCJ9.Z2q0QjioLdxabGCXnc19Mwx4Zm8US4s0lUYyhjKeB8g&download=image.png "")

```java
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
        RequeueTopic.class
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

}

```

![](https://tcs.teambition.net/storage/31225a9fcbf0ba2d2c4ab4a2dfe47b873980?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA4MywiaWF0IjoxNjEyMTkwMjgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI1YTlmY2JmMGJhMmQyYzRhYjRhMmRmZTQ3Yjg3Mzk4MCJ9.pgHwj6SZLn92do6L7LiwgQUJixKq_sGR99mjWsPve0g&download=image.png "")

```text
spring.application.name=stream-sample
#server.port=63001
#server.port=63000
#server.port=63002
server.port=63003

# RabbitMQ连接字符串
spring.rabbitmq.host=localhost
spring.rabbitmq.port=5672
spring.rabbitmq.username=guest
spring.rabbitmq.password=guest

# 把两个不同名称的信道 绑定 在一起 重定向到 目的地 一个真正的 Topic
# 不同的信道 绑定到相同的 Topic当中 当生产者发送消息 到指定的 Topic 消费者就可以消费
# 绑定Channel到broadcast
spring.cloud.stream.bindings.myTopic-consumer.destination=broadcast
spring.cloud.stream.bindings.myTopic-producer.destination=broadcast

# 消息分组示例
spring.cloud.stream.bindings.group-consumer.destination=group-topic
spring.cloud.stream.bindings.group-producer.destination=group-topic
# 消息分组是对与消费者来说 划分到组A当中
spring.cloud.stream.bindings.group-consumer.group=Group-A

# 延迟消息配置
spring.cloud.stream.bindings.delayed-consumer.destination=delayed-topic
spring.cloud.stream.bindings.delayed-producer.destination=delayed-topic

# 声明 Queue exchange 类型 创建延迟队列 指定producer exchange类型 delayed Queue 看会有一个DM标签
# 显示为 x-delayed-message
spring.cloud.stream.rabbit.bindings.delayed-producer.producer.delayed-exchange=true

# 异常消息（单机版重试）
spring.cloud.stream.bindings.error-consumer.destination=error-out-topic
spring.cloud.stream.bindings.error-producer.destination=error-out-topic
# 重试次数（本机重试）在当前的Consumer当中不断的重试消息 而不会把消息重新发回给 rabbitmq 是在客户端消费者这里
# 次数=1相当于不重试 最大尝试次数 1 没有重试 它消费这条消息当次 就算是第一次了
spring.cloud.stream.bindings.error-consumer.consumer.max-attempts=2



# 异常消息（requeue重试）
spring.cloud.stream.bindings.requeue-consumer.destination=requeue-topic
spring.cloud.stream.bindings.requeue-producer.destination=requeue-topic
# 冲突问题 retry的次数 如果配置了retry次数 也就是指定了 它在原地retry 失败以后 还会把它添加queue里面吗？
# 不会了 要强制的它的retry次数 指定成 1 也就是说 我不让你在原地 retry 失败了就立马 把这个失败消息 退回到rabbitmq当中
# 重新添加进去 让其他consumer 可以消费它
# 必须把max-attempts 设置为 1，否则requeue功能就不能生效
spring.cloud.stream.bindings.error-consumer.consumer.max-attempts=1
spring.cloud.stream.bindings.group-consumer.group=requeue-group
# 开启requeue 功能
# 仅对当前requeue-consumer，开启requeue
spring.cloud.stream.rabbit.bindings.requeue-consumer.consumer.requeueRejected=true



# 在全局范围内开启重新入队
# 默认全局开启requeue
# spring.rabbitmq.listener.default-requeue-rejected=true

# 消费分区配置
# 消费分区最终会落实在consumer里 所以要把consumer的消费分区功能打开
# 打开消费者的消费分区功能
spring.cloud.stream.bindings.group-consumer.consumer.partitioned=true

# 使用生产者来配置消费分区数量
# 两个消费分区
spring.cloud.stream.bindings.group-producer.producer.partition-count=2

# 如何识别消费分区
# SpEL表达式（Key resolver）
# 只有索引参数为1的节点（消费者），才能消费消息
# 通过生产者的 key expression配置 只有参数为1的节点消费者才能接收到数据
spring.cloud.stream.bindings.group-producer.producer.partition-key-expression=1

# 当前消费者实例总数
spring.cloud.stream.instanceCount=2

# 索引参数 跟上面搭配使用 最大值是 instanceCount-1
# 表示当前实例的索引号
#spring.cloud.stream.instanceIndex=0
spring.cloud.stream.instanceIndex=1

management.endpoints.web.exposure.include=*
management.endpoint.health.show-details=always

```

启动

![](https://tcs.teambition.net/storage/3122e52eae9593eb568593c6b1607312a869?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA4MywiaWF0IjoxNjEyMTkwMjgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJlNTJlYWU5NTkzZWI1Njg1OTNjNmIxNjA3MzEyYTg2OSJ9.48dsCF-7LLS29Lveh1gDc2r30sZFvO6erMV0YreBakM&download=image.png "")

![](https://tcs.teambition.net/storage/31228a31898232deeb0702c45e4e66a5781a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA4MywiaWF0IjoxNjEyMTkwMjgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI4YTMxODk4MjMyZGVlYjA3MDJjNDVlNGU2NmE1NzgxYSJ9.XmiPNXb4LSKk9rSgYOLrMYI0-WpyygTZENVUlDjk9G8&download=image.png "")

![](https://tcs.teambition.net/storage/3122d4a632fc0c22f76be81669208fe0bd1b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA4MywiaWF0IjoxNjEyMTkwMjgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkNGE2MzJmYzBjMjJmNzZiZTgxNjY5MjA4ZmUwYmQxYiJ9.jCy0VWul9JqKwEHR4z0lozZ_Dp8DVLTJJIbIADuZi14&download=image.png "")



22 秒 收到消息 

在 3秒钟以后 抛出了异常 25秒 

28秒又接收到了一条消息

为什么我在 25 秒抛出这个异常 哪消息已经被加 回到rabbitmq了 可是我在28秒才再次去消费了这条消息

中间的 3秒钟 另外一台消费者去消费了

都会被另外一台机器所消费

同一个组的消费者 会轮询的去消费一条消息

retry只 在当前的consumer retry 并 不会把消息重新加回到MQ

![](https://tcs.teambition.net/storage/312248a4888a7b85cc5b876ee348aa06c211?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA4MywiaWF0IjoxNjEyMTkwMjgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI0OGE0ODg4YTdiODVjYzViODc2ZWUzNDhhYTA2YzIxMSJ9.U0JXz-emTSMheZfZVBGXGv_bgrgEhsB2T2KhX8idgu0&download=image.png "")

![](https://tcs.teambition.net/storage/3122cd9532acc3fa8d477c11f91239949482?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA4MywiaWF0IjoxNjEyMTkwMjgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJjZDk1MzJhY2MzZmE4ZDQ3N2MxMWY5MTIzOTk0OTQ4MiJ9.lIbBQcEt0-_35r-5GWzcgSqQtbAtID7tDUCJv0o5EPo&download=image.png "")

```text
2021-01-31 15:54:25.942  INFO 19166 --- [l22FBOM3FTlqQ-1] c.imooc.springcloud.biz.StreamConsumer   : Are you OK?
2021-01-31 15:54:29.969  INFO 19166 --- [l22FBOM3FTlqQ-1] c.imooc.springcloud.biz.StreamConsumer   : Are you OK?
2021-01-31 15:54:34.972  INFO 19166 --- [l22FBOM3FTlqQ-1] c.imooc.springcloud.biz.StreamConsumer   : Are you OK?
2021-01-31 15:54:37.998 ERROR 19166 --- [l22FBOM3FTlqQ-1] o.s.integration.handler.LoggingHandler   : org.springframework.messaging.MessagingException: Exception thrown while invoking com.imooc.springcloud.biz.StreamConsumer#requeueErrorMessage[1 args]; nested exception is java.lang.RuntimeException: I'm not OK, failedMessage=GenericMessage [payload=byte[18], headers={amqp_receivedDeliveryMode=PERSISTENT, amqp_receivedExchange=requeue-topic, amqp_deliveryTag=1, deliveryAttempt=3, amqp_consumerQueue=requeue-topic.anonymous.Jn8jeJ6jQl22FBOM3FTlqQ, amqp_redelivered=false, amqp_receivedRoutingKey=requeue-topic, amqp_timestamp=Sun Jan 31 15:54:24 CST 2021, amqp_messageId=ae904431-abbb-5be5-6884-886d516c426c, id=3678e5c0-fc0a-b54e-25d7-d31998fbd33a, amqp_consumerTag=amq.ctag-TizqR-WKaRtWWbFVN3jNQw, contentType=application/json, timestamp=1612079665696}]
	at org.springframework.cloud.stream.binding.StreamListenerMessageHandler.handleRequestMessage(StreamListenerMessageHandler.java:64)
	at org.springframework.integration.handler.AbstractReplyProducingMessageHandler.handleMessageInternal(AbstractReplyProducingMessageHandler.java:123)
	at org.springframework.integration.handler.AbstractMessageHandler.handleMessage(AbstractMessageHandler.java:169)
	at org.springframework.integration.dispatcher.AbstractDispatcher.tryOptimizedDispatch(AbstractDispatcher.java:115)
	at org.springframework.integration.dispatcher.UnicastingDispatcher.doDispatch(UnicastingDispatcher.java:132)
	at org.springframework.integration.dispatcher.UnicastingDispatcher.dispatch(UnicastingDispatcher.java:105)
	at org.springframework.integration.channel.AbstractSubscribableChannel.doSend(AbstractSubscribableChannel.java:73)
	at org.springframework.integration.channel.AbstractMessageChannel.send(AbstractMessageChannel.java:453)
	at org.springframework.integration.channel.AbstractMessageChannel.send(AbstractMessageChannel.java:401)
	at org.springframework.messaging.core.GenericMessagingTemplate.doSend(GenericMessagingTemplate.java:187)
	at org.springframework.messaging.core.GenericMessagingTemplate.doSend(GenericMessagingTemplate.java:166)
	at org.springframework.messaging.core.GenericMessagingTemplate.doSend(GenericMessagingTemplate.java:47)
	at org.springframework.messaging.core.AbstractMessageSendingTemplate.send(AbstractMessageSendingTemplate.java:109)
	at org.springframework.integration.endpoint.MessageProducerSupport.sendMessage(MessageProducerSupport.java:205)
	at org.springframework.integration.amqp.inbound.AmqpInboundChannelAdapter.access$1200(AmqpInboundChannelAdapter.java:57)
	at org.springframework.integration.amqp.inbound.AmqpInboundChannelAdapter$Listener.lambda$onMessage$0(AmqpInboundChannelAdapter.java:223)
	at org.springframework.retry.support.RetryTemplate.doExecute(RetryTemplate.java:287)
	at org.springframework.retry.support.RetryTemplate.execute(RetryTemplate.java:180)
	at org.springframework.integration.amqp.inbound.AmqpInboundChannelAdapter$Listener.onMessage(AmqpInboundChannelAdapter.java:220)
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.doInvokeListener(AbstractMessageListenerContainer.java:1542)
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.actualInvokeListener(AbstractMessageListenerContainer.java:1468)
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.invokeListener(AbstractMessageListenerContainer.java:1456)
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.doExecuteListener(AbstractMessageListenerContainer.java:1451)
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.executeListener(AbstractMessageListenerContainer.java:1400)
	at org.springframework.amqp.rabbit.listener.SimpleMessageListenerContainer.doReceiveAndExecute(SimpleMessageListenerContainer.java:875)
	at org.springframework.amqp.rabbit.listener.SimpleMessageListenerContainer.receiveAndExecute(SimpleMessageListenerContainer.java:859)
	at org.springframework.amqp.rabbit.listener.SimpleMessageListenerContainer.access$1600(SimpleMessageListenerContainer.java:78)
	at org.springframework.amqp.rabbit.listener.SimpleMessageListenerContainer$AsyncMessageProcessingConsumer.mainLoop(SimpleMessageListenerContainer.java:1142)
	at org.springframework.amqp.rabbit.listener.SimpleMessageListenerContainer$AsyncMessageProcessingConsumer.run(SimpleMessageListenerContainer.java:1048)
	at java.lang.Thread.run(Thread.java:748)
Caused by: java.lang.RuntimeException: I'm not OK
	at com.imooc.springcloud.biz.StreamConsumer.requeueErrorMessage(StreamConsumer.java:109)
	at sun.reflect.NativeMethodAccessorImpl.invoke0(Native Method)
	at sun.reflect.NativeMethodAccessorImpl.invoke(NativeMethodAccessorImpl.java:62)
	at sun.reflect.DelegatingMethodAccessorImpl.invoke(DelegatingMethodAccessorImpl.java:43)
	at java.lang.reflect.Method.invoke(Method.java:498)
	at org.springframework.messaging.handler.invocation.InvocableHandlerMethod.doInvoke(InvocableHandlerMethod.java:171)
	at org.springframework.messaging.handler.invocation.InvocableHandlerMethod.invoke(InvocableHandlerMethod.java:120)
	at org.springframework.cloud.stream.binding.StreamListenerMessageHandler.handleRequestMessage(StreamListenerMessageHandler.java:55)
	... 29 more

2021-01-31 15:54:38.022  WARN 19166 --- [l22FBOM3FTlqQ-1] o.s.a.r.r.RejectAndDontRequeueRecoverer  : Retries exhausted for message (Body:'{"payload":"test"}' MessageProperties [headers={}, timestamp=Sun Jan 31 15:54:24 CST 2021, messageId=ae904431-abbb-5be5-6884-886d516c426c, contentType=application/json, contentLength=0, receivedDeliveryMode=PERSISTENT, priority=0, redelivered=false, receivedExchange=requeue-topic, receivedRoutingKey=requeue-topic, deliveryTag=1, consumerTag=amq.ctag-TizqR-WKaRtWWbFVN3jNQw, consumerQueue=requeue-topic.anonymous.Jn8jeJ6jQl22FBOM3FTlqQ])

org.springframework.messaging.MessagingException: Exception thrown while invoking com.imooc.springcloud.biz.StreamConsumer#requeueErrorMessage[1 args]; nested exception is java.lang.RuntimeException: I'm not OK
	at org.springframework.cloud.stream.binding.StreamListenerMessageHandler.handleRequestMessage(StreamListenerMessageHandler.java:64) ~[spring-cloud-stream-2.1.2.RELEASE.jar:2.1.2.RELEASE]
	at org.springframework.integration.handler.AbstractReplyProducingMessageHandler.handleMessageInternal(AbstractReplyProducingMessageHandler.java:123) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.handler.AbstractMessageHandler.handleMessage(AbstractMessageHandler.java:169) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.dispatcher.AbstractDispatcher.tryOptimizedDispatch(AbstractDispatcher.java:115) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.dispatcher.UnicastingDispatcher.doDispatch(UnicastingDispatcher.java:132) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.dispatcher.UnicastingDispatcher.dispatch(UnicastingDispatcher.java:105) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.channel.AbstractSubscribableChannel.doSend(AbstractSubscribableChannel.java:73) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.channel.AbstractMessageChannel.send(AbstractMessageChannel.java:453) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.channel.AbstractMessageChannel.send(AbstractMessageChannel.java:401) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.messaging.core.GenericMessagingTemplate.doSend(GenericMessagingTemplate.java:187) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.messaging.core.GenericMessagingTemplate.doSend(GenericMessagingTemplate.java:166) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.messaging.core.GenericMessagingTemplate.doSend(GenericMessagingTemplate.java:47) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.messaging.core.AbstractMessageSendingTemplate.send(AbstractMessageSendingTemplate.java:109) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.integration.endpoint.MessageProducerSupport.sendMessage(MessageProducerSupport.java:205) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.amqp.inbound.AmqpInboundChannelAdapter.access$1200(AmqpInboundChannelAdapter.java:57) ~[spring-integration-amqp-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.amqp.inbound.AmqpInboundChannelAdapter$Listener.lambda$onMessage$0(AmqpInboundChannelAdapter.java:223) [spring-integration-amqp-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.retry.support.RetryTemplate.doExecute(RetryTemplate.java:287) [spring-retry-1.2.5.RELEASE.jar:na]
	at org.springframework.retry.support.RetryTemplate.execute(RetryTemplate.java:180) [spring-retry-1.2.5.RELEASE.jar:na]
	at org.springframework.integration.amqp.inbound.AmqpInboundChannelAdapter$Listener.onMessage(AmqpInboundChannelAdapter.java:220) [spring-integration-amqp-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.doInvokeListener(AbstractMessageListenerContainer.java:1542) [spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.actualInvokeListener(AbstractMessageListenerContainer.java:1468) [spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.invokeListener(AbstractMessageListenerContainer.java:1456) [spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.doExecuteListener(AbstractMessageListenerContainer.java:1451) [spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.executeListener(AbstractMessageListenerContainer.java:1400) [spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.SimpleMessageListenerContainer.doReceiveAndExecute(SimpleMessageListenerContainer.java:875) ~[spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.SimpleMessageListenerContainer.receiveAndExecute(SimpleMessageListenerContainer.java:859) ~[spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.SimpleMessageListenerContainer.access$1600(SimpleMessageListenerContainer.java:78) ~[spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.SimpleMessageListenerContainer$AsyncMessageProcessingConsumer.mainLoop(SimpleMessageListenerContainer.java:1142) ~[spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.SimpleMessageListenerContainer$AsyncMessageProcessingConsumer.run(SimpleMessageListenerContainer.java:1048) ~[spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at java.lang.Thread.run(Thread.java:748) ~[na:1.8.0_181]
Caused by: java.lang.RuntimeException: I'm not OK
	at com.imooc.springcloud.biz.StreamConsumer.requeueErrorMessage(StreamConsumer.java:109) ~[classes/:na]
	at sun.reflect.NativeMethodAccessorImpl.invoke0(Native Method) ~[na:1.8.0_181]
	at sun.reflect.NativeMethodAccessorImpl.invoke(NativeMethodAccessorImpl.java:62) ~[na:1.8.0_181]
	at sun.reflect.DelegatingMethodAccessorImpl.invoke(DelegatingMethodAccessorImpl.java:43) ~[na:1.8.0_181]
	at java.lang.reflect.Method.invoke(Method.java:498) ~[na:1.8.0_181]
	at org.springframework.messaging.handler.invocation.InvocableHandlerMethod.doInvoke(InvocableHandlerMethod.java:171) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.messaging.handler.invocation.InvocableHandlerMethod.invoke(InvocableHandlerMethod.java:120) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.cloud.stream.binding.StreamListenerMessageHandler.handleRequestMessage(StreamListenerMessageHandler.java:55) ~[spring-cloud-stream-2.1.2.RELEASE.jar:2.1.2.RELEASE]
	... 29 common frames omitted

2021-01-31 15:54:38.032  WARN 19166 --- [l22FBOM3FTlqQ-1] s.a.r.l.ConditionalRejectingErrorHandler : Execution of Rabbit message listener failed.

org.springframework.amqp.rabbit.listener.exception.ListenerExecutionFailedException: Listener threw exception
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.wrapToListenerExecutionFailedExceptionIfNeeded(AbstractMessageListenerContainer.java:1641) ~[spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.doInvokeListener(AbstractMessageListenerContainer.java:1545) ~[spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.actualInvokeListener(AbstractMessageListenerContainer.java:1468) ~[spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.invokeListener(AbstractMessageListenerContainer.java:1456) ~[spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.doExecuteListener(AbstractMessageListenerContainer.java:1451) ~[spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.executeListener(AbstractMessageListenerContainer.java:1400) ~[spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.SimpleMessageListenerContainer.doReceiveAndExecute(SimpleMessageListenerContainer.java:875) [spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.SimpleMessageListenerContainer.receiveAndExecute(SimpleMessageListenerContainer.java:859) [spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.SimpleMessageListenerContainer.access$1600(SimpleMessageListenerContainer.java:78) [spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.SimpleMessageListenerContainer$AsyncMessageProcessingConsumer.mainLoop(SimpleMessageListenerContainer.java:1142) [spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.SimpleMessageListenerContainer$AsyncMessageProcessingConsumer.run(SimpleMessageListenerContainer.java:1048) [spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at java.lang.Thread.run(Thread.java:748) [na:1.8.0_181]
Caused by: org.springframework.messaging.MessageDeliveryException: failed to send Message to channel 'requeue-topic.anonymous.Jn8jeJ6jQl22FBOM3FTlqQ.errors'; nested exception is org.springframework.amqp.rabbit.listener.exception.ListenerExecutionFailedException: Retry Policy Exhausted
	at org.springframework.integration.support.utils.IntegrationUtils.wrapInDeliveryExceptionIfNecessary(IntegrationUtils.java:166) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.channel.AbstractMessageChannel.send(AbstractMessageChannel.java:483) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.channel.AbstractMessageChannel.send(AbstractMessageChannel.java:401) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.messaging.core.GenericMessagingTemplate.doSend(GenericMessagingTemplate.java:187) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.messaging.core.GenericMessagingTemplate.doSend(GenericMessagingTemplate.java:166) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.messaging.core.GenericMessagingTemplate.doSend(GenericMessagingTemplate.java:47) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.messaging.core.AbstractMessageSendingTemplate.send(AbstractMessageSendingTemplate.java:109) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.messaging.core.AbstractMessageSendingTemplate.send(AbstractMessageSendingTemplate.java:99) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.integration.core.ErrorMessagePublisher.publish(ErrorMessagePublisher.java:168) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.handler.advice.ErrorMessageSendingRecoverer.recover(ErrorMessageSendingRecoverer.java:83) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.retry.support.RetryTemplate.handleRetryExhausted(RetryTemplate.java:512) ~[spring-retry-1.2.5.RELEASE.jar:na]
	at org.springframework.retry.support.RetryTemplate.doExecute(RetryTemplate.java:351) ~[spring-retry-1.2.5.RELEASE.jar:na]
	at org.springframework.retry.support.RetryTemplate.execute(RetryTemplate.java:180) ~[spring-retry-1.2.5.RELEASE.jar:na]
	at org.springframework.integration.amqp.inbound.AmqpInboundChannelAdapter$Listener.onMessage(AmqpInboundChannelAdapter.java:220) ~[spring-integration-amqp-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.doInvokeListener(AbstractMessageListenerContainer.java:1542) ~[spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	... 10 common frames omitted
Caused by: org.springframework.amqp.rabbit.listener.exception.ListenerExecutionFailedException: Retry Policy Exhausted
	at org.springframework.amqp.rabbit.retry.RejectAndDontRequeueRecoverer.recover(RejectAndDontRequeueRecoverer.java:45) ~[spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.cloud.stream.binder.rabbit.RabbitMessageChannelBinder$3.handleMessage(RabbitMessageChannelBinder.java:628) ~[spring-cloud-stream-binder-rabbit-2.1.2.RELEASE.jar:2.1.2.RELEASE]
	at org.springframework.integration.dispatcher.BroadcastingDispatcher.invokeHandler(BroadcastingDispatcher.java:224) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.dispatcher.BroadcastingDispatcher.dispatch(BroadcastingDispatcher.java:180) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.channel.AbstractSubscribableChannel.doSend(AbstractSubscribableChannel.java:73) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.channel.AbstractMessageChannel.send(AbstractMessageChannel.java:453) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	... 23 common frames omitted
Caused by: org.springframework.amqp.AmqpRejectAndDontRequeueException: null
	... 29 common frames omitted
Caused by: org.springframework.messaging.MessagingException: Exception thrown while invoking com.imooc.springcloud.biz.StreamConsumer#requeueErrorMessage[1 args]; nested exception is java.lang.RuntimeException: I'm not OK
	at org.springframework.cloud.stream.binding.StreamListenerMessageHandler.handleRequestMessage(StreamListenerMessageHandler.java:64) ~[spring-cloud-stream-2.1.2.RELEASE.jar:2.1.2.RELEASE]
	at org.springframework.integration.handler.AbstractReplyProducingMessageHandler.handleMessageInternal(AbstractReplyProducingMessageHandler.java:123) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.handler.AbstractMessageHandler.handleMessage(AbstractMessageHandler.java:169) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.dispatcher.AbstractDispatcher.tryOptimizedDispatch(AbstractDispatcher.java:115) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.dispatcher.UnicastingDispatcher.doDispatch(UnicastingDispatcher.java:132) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.dispatcher.UnicastingDispatcher.dispatch(UnicastingDispatcher.java:105) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.channel.AbstractSubscribableChannel.doSend(AbstractSubscribableChannel.java:73) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.channel.AbstractMessageChannel.send(AbstractMessageChannel.java:453) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.channel.AbstractMessageChannel.send(AbstractMessageChannel.java:401) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.messaging.core.GenericMessagingTemplate.doSend(GenericMessagingTemplate.java:187) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.messaging.core.GenericMessagingTemplate.doSend(GenericMessagingTemplate.java:166) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.messaging.core.GenericMessagingTemplate.doSend(GenericMessagingTemplate.java:47) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.messaging.core.AbstractMessageSendingTemplate.send(AbstractMessageSendingTemplate.java:109) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.integration.endpoint.MessageProducerSupport.sendMessage(MessageProducerSupport.java:205) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.amqp.inbound.AmqpInboundChannelAdapter.access$1200(AmqpInboundChannelAdapter.java:57) ~[spring-integration-amqp-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.amqp.inbound.AmqpInboundChannelAdapter$Listener.lambda$onMessage$0(AmqpInboundChannelAdapter.java:223) ~[spring-integration-amqp-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.retry.support.RetryTemplate.doExecute(RetryTemplate.java:287) ~[spring-retry-1.2.5.RELEASE.jar:na]
	... 13 common frames omitted
Caused by: java.lang.RuntimeException: I'm not OK
	at com.imooc.springcloud.biz.StreamConsumer.requeueErrorMessage(StreamConsumer.java:109) ~[classes/:na]
	at sun.reflect.NativeMethodAccessorImpl.invoke0(Native Method) ~[na:1.8.0_181]
	at sun.reflect.NativeMethodAccessorImpl.invoke(NativeMethodAccessorImpl.java:62) ~[na:1.8.0_181]
	at sun.reflect.DelegatingMethodAccessorImpl.invoke(DelegatingMethodAccessorImpl.java:43) ~[na:1.8.0_181]
	at java.lang.reflect.Method.invoke(Method.java:498) ~[na:1.8.0_181]
	at org.springframework.messaging.handler.invocation.InvocableHandlerMethod.doInvoke(InvocableHandlerMethod.java:171) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.messaging.handler.invocation.InvocableHandlerMethod.invoke(InvocableHandlerMethod.java:120) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.cloud.stream.binding.StreamListenerMessageHandler.handleRequestMessage(StreamListenerMessageHandler.java:55) ~[spring-cloud-stream-2.1.2.RELEASE.jar:2.1.2.RELEASE]
	... 29 common frames omitted

```



![](https://tcs.teambition.net/storage/3122aa0822d664b50a607af8ccd2b578df8d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA4MywiaWF0IjoxNjEyMTkwMjgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhYTA4MjJkNjY0YjUwYTYwN2FmOGNjZDJiNTc4ZGY4ZCJ9.vemIGodqZ7Kbim3X5rax1c4Ajz7kr8xshmYexrfpYVA&download=image.png "")

```text
2021-01-31 15:54:25.687  INFO 19314 --- [xazLN4ce36irw-1] c.imooc.springcloud.biz.StreamConsumer   : Are you OK?
2021-01-31 15:54:29.699  INFO 19314 --- [xazLN4ce36irw-1] c.imooc.springcloud.biz.StreamConsumer   : Are you OK?
2021-01-31 15:54:34.702  INFO 19314 --- [xazLN4ce36irw-1] c.imooc.springcloud.biz.StreamConsumer   : Are you OK?
2021-01-31 15:54:37.716 ERROR 19314 --- [xazLN4ce36irw-1] o.s.integration.handler.LoggingHandler   : org.springframework.messaging.MessagingException: Exception thrown while invoking com.imooc.springcloud.biz.StreamConsumer#requeueErrorMessage[1 args]; nested exception is java.lang.RuntimeException: I'm not OK, failedMessage=GenericMessage [payload=byte[18], headers={amqp_receivedDeliveryMode=PERSISTENT, amqp_receivedExchange=requeue-topic, amqp_deliveryTag=1, deliveryAttempt=3, amqp_consumerQueue=requeue-topic.anonymous.hCGZdLb0QxazLN4ce36irw, amqp_redelivered=false, amqp_receivedRoutingKey=requeue-topic, amqp_timestamp=Sun Jan 31 15:54:24 CST 2021, amqp_messageId=ae904431-abbb-5be5-6884-886d516c426c, id=b38846d0-0b16-aba5-b8d0-ecc596c799db, amqp_consumerTag=amq.ctag-830tyrR9ozyiz4UuFLKM4w, contentType=application/json, timestamp=1612079665599}]
	at org.springframework.cloud.stream.binding.StreamListenerMessageHandler.handleRequestMessage(StreamListenerMessageHandler.java:64)
	at org.springframework.integration.handler.AbstractReplyProducingMessageHandler.handleMessageInternal(AbstractReplyProducingMessageHandler.java:123)
	at org.springframework.integration.handler.AbstractMessageHandler.handleMessage(AbstractMessageHandler.java:169)
	at org.springframework.integration.dispatcher.AbstractDispatcher.tryOptimizedDispatch(AbstractDispatcher.java:115)
	at org.springframework.integration.dispatcher.UnicastingDispatcher.doDispatch(UnicastingDispatcher.java:132)
	at org.springframework.integration.dispatcher.UnicastingDispatcher.dispatch(UnicastingDispatcher.java:105)
	at org.springframework.integration.channel.AbstractSubscribableChannel.doSend(AbstractSubscribableChannel.java:73)
	at org.springframework.integration.channel.AbstractMessageChannel.send(AbstractMessageChannel.java:453)
	at org.springframework.integration.channel.AbstractMessageChannel.send(AbstractMessageChannel.java:401)
	at org.springframework.messaging.core.GenericMessagingTemplate.doSend(GenericMessagingTemplate.java:187)
	at org.springframework.messaging.core.GenericMessagingTemplate.doSend(GenericMessagingTemplate.java:166)
	at org.springframework.messaging.core.GenericMessagingTemplate.doSend(GenericMessagingTemplate.java:47)
	at org.springframework.messaging.core.AbstractMessageSendingTemplate.send(AbstractMessageSendingTemplate.java:109)
	at org.springframework.integration.endpoint.MessageProducerSupport.sendMessage(MessageProducerSupport.java:205)
	at org.springframework.integration.amqp.inbound.AmqpInboundChannelAdapter.access$1200(AmqpInboundChannelAdapter.java:57)
	at org.springframework.integration.amqp.inbound.AmqpInboundChannelAdapter$Listener.lambda$onMessage$0(AmqpInboundChannelAdapter.java:223)
	at org.springframework.retry.support.RetryTemplate.doExecute(RetryTemplate.java:287)
	at org.springframework.retry.support.RetryTemplate.execute(RetryTemplate.java:180)
	at org.springframework.integration.amqp.inbound.AmqpInboundChannelAdapter$Listener.onMessage(AmqpInboundChannelAdapter.java:220)
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.doInvokeListener(AbstractMessageListenerContainer.java:1542)
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.actualInvokeListener(AbstractMessageListenerContainer.java:1468)
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.invokeListener(AbstractMessageListenerContainer.java:1456)
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.doExecuteListener(AbstractMessageListenerContainer.java:1451)
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.executeListener(AbstractMessageListenerContainer.java:1400)
	at org.springframework.amqp.rabbit.listener.SimpleMessageListenerContainer.doReceiveAndExecute(SimpleMessageListenerContainer.java:875)
	at org.springframework.amqp.rabbit.listener.SimpleMessageListenerContainer.receiveAndExecute(SimpleMessageListenerContainer.java:859)
	at org.springframework.amqp.rabbit.listener.SimpleMessageListenerContainer.access$1600(SimpleMessageListenerContainer.java:78)
	at org.springframework.amqp.rabbit.listener.SimpleMessageListenerContainer$AsyncMessageProcessingConsumer.mainLoop(SimpleMessageListenerContainer.java:1142)
	at org.springframework.amqp.rabbit.listener.SimpleMessageListenerContainer$AsyncMessageProcessingConsumer.run(SimpleMessageListenerContainer.java:1048)
	at java.lang.Thread.run(Thread.java:748)
Caused by: java.lang.RuntimeException: I'm not OK
	at com.imooc.springcloud.biz.StreamConsumer.requeueErrorMessage(StreamConsumer.java:109)
	at sun.reflect.NativeMethodAccessorImpl.invoke0(Native Method)
	at sun.reflect.NativeMethodAccessorImpl.invoke(NativeMethodAccessorImpl.java:62)
	at sun.reflect.DelegatingMethodAccessorImpl.invoke(DelegatingMethodAccessorImpl.java:43)
	at java.lang.reflect.Method.invoke(Method.java:498)
	at org.springframework.messaging.handler.invocation.InvocableHandlerMethod.doInvoke(InvocableHandlerMethod.java:171)
	at org.springframework.messaging.handler.invocation.InvocableHandlerMethod.invoke(InvocableHandlerMethod.java:120)
	at org.springframework.cloud.stream.binding.StreamListenerMessageHandler.handleRequestMessage(StreamListenerMessageHandler.java:55)
	... 29 more

2021-01-31 15:54:37.732  WARN 19314 --- [xazLN4ce36irw-1] o.s.a.r.r.RejectAndDontRequeueRecoverer  : Retries exhausted for message (Body:'{"payload":"test"}' MessageProperties [headers={}, timestamp=Sun Jan 31 15:54:24 CST 2021, messageId=ae904431-abbb-5be5-6884-886d516c426c, contentType=application/json, contentLength=0, receivedDeliveryMode=PERSISTENT, priority=0, redelivered=false, receivedExchange=requeue-topic, receivedRoutingKey=requeue-topic, deliveryTag=1, consumerTag=amq.ctag-830tyrR9ozyiz4UuFLKM4w, consumerQueue=requeue-topic.anonymous.hCGZdLb0QxazLN4ce36irw])

org.springframework.messaging.MessagingException: Exception thrown while invoking com.imooc.springcloud.biz.StreamConsumer#requeueErrorMessage[1 args]; nested exception is java.lang.RuntimeException: I'm not OK
	at org.springframework.cloud.stream.binding.StreamListenerMessageHandler.handleRequestMessage(StreamListenerMessageHandler.java:64) ~[spring-cloud-stream-2.1.2.RELEASE.jar:2.1.2.RELEASE]
	at org.springframework.integration.handler.AbstractReplyProducingMessageHandler.handleMessageInternal(AbstractReplyProducingMessageHandler.java:123) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.handler.AbstractMessageHandler.handleMessage(AbstractMessageHandler.java:169) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.dispatcher.AbstractDispatcher.tryOptimizedDispatch(AbstractDispatcher.java:115) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.dispatcher.UnicastingDispatcher.doDispatch(UnicastingDispatcher.java:132) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.dispatcher.UnicastingDispatcher.dispatch(UnicastingDispatcher.java:105) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.channel.AbstractSubscribableChannel.doSend(AbstractSubscribableChannel.java:73) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.channel.AbstractMessageChannel.send(AbstractMessageChannel.java:453) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.channel.AbstractMessageChannel.send(AbstractMessageChannel.java:401) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.messaging.core.GenericMessagingTemplate.doSend(GenericMessagingTemplate.java:187) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.messaging.core.GenericMessagingTemplate.doSend(GenericMessagingTemplate.java:166) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.messaging.core.GenericMessagingTemplate.doSend(GenericMessagingTemplate.java:47) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.messaging.core.AbstractMessageSendingTemplate.send(AbstractMessageSendingTemplate.java:109) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.integration.endpoint.MessageProducerSupport.sendMessage(MessageProducerSupport.java:205) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.amqp.inbound.AmqpInboundChannelAdapter.access$1200(AmqpInboundChannelAdapter.java:57) ~[spring-integration-amqp-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.amqp.inbound.AmqpInboundChannelAdapter$Listener.lambda$onMessage$0(AmqpInboundChannelAdapter.java:223) [spring-integration-amqp-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.retry.support.RetryTemplate.doExecute(RetryTemplate.java:287) [spring-retry-1.2.5.RELEASE.jar:na]
	at org.springframework.retry.support.RetryTemplate.execute(RetryTemplate.java:180) [spring-retry-1.2.5.RELEASE.jar:na]
	at org.springframework.integration.amqp.inbound.AmqpInboundChannelAdapter$Listener.onMessage(AmqpInboundChannelAdapter.java:220) [spring-integration-amqp-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.doInvokeListener(AbstractMessageListenerContainer.java:1542) [spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.actualInvokeListener(AbstractMessageListenerContainer.java:1468) [spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.invokeListener(AbstractMessageListenerContainer.java:1456) [spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.doExecuteListener(AbstractMessageListenerContainer.java:1451) [spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.executeListener(AbstractMessageListenerContainer.java:1400) [spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.SimpleMessageListenerContainer.doReceiveAndExecute(SimpleMessageListenerContainer.java:875) ~[spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.SimpleMessageListenerContainer.receiveAndExecute(SimpleMessageListenerContainer.java:859) ~[spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.SimpleMessageListenerContainer.access$1600(SimpleMessageListenerContainer.java:78) ~[spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.SimpleMessageListenerContainer$AsyncMessageProcessingConsumer.mainLoop(SimpleMessageListenerContainer.java:1142) ~[spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.SimpleMessageListenerContainer$AsyncMessageProcessingConsumer.run(SimpleMessageListenerContainer.java:1048) ~[spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at java.lang.Thread.run(Thread.java:748) ~[na:1.8.0_181]
Caused by: java.lang.RuntimeException: I'm not OK
	at com.imooc.springcloud.biz.StreamConsumer.requeueErrorMessage(StreamConsumer.java:109) ~[classes/:na]
	at sun.reflect.NativeMethodAccessorImpl.invoke0(Native Method) ~[na:1.8.0_181]
	at sun.reflect.NativeMethodAccessorImpl.invoke(NativeMethodAccessorImpl.java:62) ~[na:1.8.0_181]
	at sun.reflect.DelegatingMethodAccessorImpl.invoke(DelegatingMethodAccessorImpl.java:43) ~[na:1.8.0_181]
	at java.lang.reflect.Method.invoke(Method.java:498) ~[na:1.8.0_181]
	at org.springframework.messaging.handler.invocation.InvocableHandlerMethod.doInvoke(InvocableHandlerMethod.java:171) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.messaging.handler.invocation.InvocableHandlerMethod.invoke(InvocableHandlerMethod.java:120) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.cloud.stream.binding.StreamListenerMessageHandler.handleRequestMessage(StreamListenerMessageHandler.java:55) ~[spring-cloud-stream-2.1.2.RELEASE.jar:2.1.2.RELEASE]
	... 29 common frames omitted
2021-01-31 15:54:37.738  WARN 19314 --- [xazLN4ce36irw-1] s.a.r.l.ConditionalRejectingErrorHandler : Execution of Rabbit message listener failed.

org.springframework.amqp.rabbit.listener.exception.ListenerExecutionFailedException: Listener threw exception
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.wrapToListenerExecutionFailedExceptionIfNeeded(AbstractMessageListenerContainer.java:1641) ~[spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.doInvokeListener(AbstractMessageListenerContainer.java:1545) ~[spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.actualInvokeListener(AbstractMessageListenerContainer.java:1468) ~[spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.invokeListener(AbstractMessageListenerContainer.java:1456) ~[spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.doExecuteListener(AbstractMessageListenerContainer.java:1451) ~[spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.executeListener(AbstractMessageListenerContainer.java:1400) ~[spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.SimpleMessageListenerContainer.doReceiveAndExecute(SimpleMessageListenerContainer.java:875) [spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.SimpleMessageListenerContainer.receiveAndExecute(SimpleMessageListenerContainer.java:859) [spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.SimpleMessageListenerContainer.access$1600(SimpleMessageListenerContainer.java:78) [spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.SimpleMessageListenerContainer$AsyncMessageProcessingConsumer.mainLoop(SimpleMessageListenerContainer.java:1142) [spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.amqp.rabbit.listener.SimpleMessageListenerContainer$AsyncMessageProcessingConsumer.run(SimpleMessageListenerContainer.java:1048) [spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at java.lang.Thread.run(Thread.java:748) [na:1.8.0_181]
Caused by: org.springframework.messaging.MessageDeliveryException: failed to send Message to channel 'requeue-topic.anonymous.hCGZdLb0QxazLN4ce36irw.errors'; nested exception is org.springframework.amqp.rabbit.listener.exception.ListenerExecutionFailedException: Retry Policy Exhausted
	at org.springframework.integration.support.utils.IntegrationUtils.wrapInDeliveryExceptionIfNecessary(IntegrationUtils.java:166) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.channel.AbstractMessageChannel.send(AbstractMessageChannel.java:483) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.channel.AbstractMessageChannel.send(AbstractMessageChannel.java:401) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.messaging.core.GenericMessagingTemplate.doSend(GenericMessagingTemplate.java:187) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.messaging.core.GenericMessagingTemplate.doSend(GenericMessagingTemplate.java:166) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.messaging.core.GenericMessagingTemplate.doSend(GenericMessagingTemplate.java:47) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.messaging.core.AbstractMessageSendingTemplate.send(AbstractMessageSendingTemplate.java:109) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.messaging.core.AbstractMessageSendingTemplate.send(AbstractMessageSendingTemplate.java:99) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.integration.core.ErrorMessagePublisher.publish(ErrorMessagePublisher.java:168) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.handler.advice.ErrorMessageSendingRecoverer.recover(ErrorMessageSendingRecoverer.java:83) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.retry.support.RetryTemplate.handleRetryExhausted(RetryTemplate.java:512) ~[spring-retry-1.2.5.RELEASE.jar:na]
	at org.springframework.retry.support.RetryTemplate.doExecute(RetryTemplate.java:351) ~[spring-retry-1.2.5.RELEASE.jar:na]
	at org.springframework.retry.support.RetryTemplate.execute(RetryTemplate.java:180) ~[spring-retry-1.2.5.RELEASE.jar:na]
	at org.springframework.integration.amqp.inbound.AmqpInboundChannelAdapter$Listener.onMessage(AmqpInboundChannelAdapter.java:220) ~[spring-integration-amqp-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.amqp.rabbit.listener.AbstractMessageListenerContainer.doInvokeListener(AbstractMessageListenerContainer.java:1542) ~[spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	... 10 common frames omitted
Caused by: org.springframework.amqp.rabbit.listener.exception.ListenerExecutionFailedException: Retry Policy Exhausted
	at org.springframework.amqp.rabbit.retry.RejectAndDontRequeueRecoverer.recover(RejectAndDontRequeueRecoverer.java:45) ~[spring-rabbit-2.1.15.RELEASE.jar:2.1.15.RELEASE]
	at org.springframework.cloud.stream.binder.rabbit.RabbitMessageChannelBinder$3.handleMessage(RabbitMessageChannelBinder.java:628) ~[spring-cloud-stream-binder-rabbit-2.1.2.RELEASE.jar:2.1.2.RELEASE]
	at org.springframework.integration.dispatcher.BroadcastingDispatcher.invokeHandler(BroadcastingDispatcher.java:224) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.dispatcher.BroadcastingDispatcher.dispatch(BroadcastingDispatcher.java:180) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.channel.AbstractSubscribableChannel.doSend(AbstractSubscribableChannel.java:73) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.channel.AbstractMessageChannel.send(AbstractMessageChannel.java:453) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	... 23 common frames omitted
Caused by: org.springframework.amqp.AmqpRejectAndDontRequeueException: null
	... 29 common frames omitted
Caused by: org.springframework.messaging.MessagingException: Exception thrown while invoking com.imooc.springcloud.biz.StreamConsumer#requeueErrorMessage[1 args]; nested exception is java.lang.RuntimeException: I'm not OK
	at org.springframework.cloud.stream.binding.StreamListenerMessageHandler.handleRequestMessage(StreamListenerMessageHandler.java:64) ~[spring-cloud-stream-2.1.2.RELEASE.jar:2.1.2.RELEASE]
	at org.springframework.integration.handler.AbstractReplyProducingMessageHandler.handleMessageInternal(AbstractReplyProducingMessageHandler.java:123) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.handler.AbstractMessageHandler.handleMessage(AbstractMessageHandler.java:169) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.dispatcher.AbstractDispatcher.tryOptimizedDispatch(AbstractDispatcher.java:115) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.dispatcher.UnicastingDispatcher.doDispatch(UnicastingDispatcher.java:132) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.dispatcher.UnicastingDispatcher.dispatch(UnicastingDispatcher.java:105) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.channel.AbstractSubscribableChannel.doSend(AbstractSubscribableChannel.java:73) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.channel.AbstractMessageChannel.send(AbstractMessageChannel.java:453) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.channel.AbstractMessageChannel.send(AbstractMessageChannel.java:401) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.messaging.core.GenericMessagingTemplate.doSend(GenericMessagingTemplate.java:187) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.messaging.core.GenericMessagingTemplate.doSend(GenericMessagingTemplate.java:166) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.messaging.core.GenericMessagingTemplate.doSend(GenericMessagingTemplate.java:47) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.messaging.core.AbstractMessageSendingTemplate.send(AbstractMessageSendingTemplate.java:109) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.integration.endpoint.MessageProducerSupport.sendMessage(MessageProducerSupport.java:205) ~[spring-integration-core-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.amqp.inbound.AmqpInboundChannelAdapter.access$1200(AmqpInboundChannelAdapter.java:57) ~[spring-integration-amqp-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.integration.amqp.inbound.AmqpInboundChannelAdapter$Listener.lambda$onMessage$0(AmqpInboundChannelAdapter.java:223) ~[spring-integration-amqp-5.1.11.RELEASE.jar:5.1.11.RELEASE]
	at org.springframework.retry.support.RetryTemplate.doExecute(RetryTemplate.java:287) ~[spring-retry-1.2.5.RELEASE.jar:na]
	... 13 common frames omitted
Caused by: java.lang.RuntimeException: I'm not OK
	at com.imooc.springcloud.biz.StreamConsumer.requeueErrorMessage(StreamConsumer.java:109) ~[classes/:na]
	at sun.reflect.NativeMethodAccessorImpl.invoke0(Native Method) ~[na:1.8.0_181]
	at sun.reflect.NativeMethodAccessorImpl.invoke(NativeMethodAccessorImpl.java:62) ~[na:1.8.0_181]
	at sun.reflect.DelegatingMethodAccessorImpl.invoke(DelegatingMethodAccessorImpl.java:43) ~[na:1.8.0_181]
	at java.lang.reflect.Method.invoke(Method.java:498) ~[na:1.8.0_181]
	at org.springframework.messaging.handler.invocation.InvocableHandlerMethod.doInvoke(InvocableHandlerMethod.java:171) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.messaging.handler.invocation.InvocableHandlerMethod.invoke(InvocableHandlerMethod.java:120) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.cloud.stream.binding.StreamListenerMessageHandler.handleRequestMessage(StreamListenerMessageHandler.java:55) ~[spring-cloud-stream-2.1.2.RELEASE.jar:2.1.2.RELEASE]
	... 29 common frames omitted

```





开源笔记

可 Pull Requests 协作写开源笔记

如果笔记图片无法访问 请访问 [teambition](https://tburl.in/0jDNvpbK) 原版开源笔记

gitee

[https://gitee.com/opendevel/java-for-linux](https://gitee.com/opendevel/java-for-linux)

github

[https://github.com/OSrcD/java-for-linux](https://github.com/OSrcD/java-for-linux)

teambition

[https://tburl.in/0jDNvpbK](https://tburl.in/0jDNvpbK)

开源视频

bilibili

[https://space.bilibili.com/77266754](https://space.bilibili.com/77266754)

开源博客

oschina

[https://my.oschina.net/u/4675154](https://my.oschina.net/u/4675154)

csdn

[https://blog.csdn.net/OpenDevel](https://blog.csdn.net/OpenDevel)

开源项目

gitee

[https://gitee.com/opendevel](https://gitee.com/opendevel)

github

[https://github.com/OSrcD](https://github.com/OSrcD)

开源赞赏

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA4MywiaWF0IjoxNjEyMTkwMjgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.ULFx_bMGAGxf0-YggJ60_tVblrF6xefPtHIXgHhv6qo&download=image.png "")

