![](https://tcs.teambition.net/storage/31228520726d63e3cd6d9be0dd3b6d76e4e8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA5OSwiaWF0IjoxNjEyMTkwMjk5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI4NTIwNzI2ZDYzZTNjZDZkOWJlMGRkM2I2ZDc2ZTRlOCJ9.rMRD0jpz1KqBvDYybmVOfXXbp_7T5c2b7cvFs4t7QwQ&download=image.png "")

![](https://tcs.teambition.net/storage/3122f59f473e080e4b5724eebaac3cfda418?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA5OSwiaWF0IjoxNjEyMTkwMjk5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJmNTlmNDczZTA4MGU0YjU3MjRlZWJhYWMzY2ZkYTQxOCJ9.KD6nWkXDI22x3aKPtmyFNFa7bzpSUKtkHk-ZCT87AIE&download=image.png "")

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
public interface ErrorTopic {

    /**
     * 把两个 信道绑定在一起
     */
    String INPUT = "error-consumer";

    String OUTPUT = "error-producer";

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

![](https://tcs.teambition.net/storage/31229f4f2408027218310d334dc8f3f9c862?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA5OSwiaWF0IjoxNjEyMTkwMjk5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5ZjRmMjQwODAyNzIxODMxMGQzMzRkYzhmM2Y5Yzg2MiJ9.teV86vINM5xSR4IhB0nflK-IBqRUDgSiIXvuEcvg_NA&download=image.png "")

```java
package com.imooc.springcloud.biz;

import com.imooc.springcloud.topic.DelayedTopic;
import com.imooc.springcloud.topic.ErrorTopic;
import com.imooc.springcloud.topic.GroupTopic;
import com.imooc.springcloud.topic.MyTopic;
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



}

```

![](https://tcs.teambition.net/storage/312217a15e83842655d15a1c7e3bbad90181?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA5OSwiaWF0IjoxNjEyMTkwMjk5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxN2ExNWU4Mzg0MjY1NWQxNWExYzdlM2JiYWQ5MDE4MSJ9.Q4uHHqCWQwSvcatchNNMvunkBlJUZO5xsBHYNsKN79Y&download=image.png "")

```java
package com.imooc.springcloud.biz;

import com.imooc.springcloud.topic.DelayedTopic;
import com.imooc.springcloud.topic.ErrorTopic;
import com.imooc.springcloud.topic.GroupTopic;
import com.imooc.springcloud.topic.MyTopic;
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
        ErrorTopic.class
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

}

```

![](https://tcs.teambition.net/storage/3122bf9e1a39727632a73c16c0c338881acf?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA5OSwiaWF0IjoxNjEyMTkwMjk5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJiZjllMWEzOTcyNzYzMmE3M2MxNmMwYzMzODg4MWFjZiJ9.ZzEEe2C_47TUUDM5EQKqaQtdq9alMMrWryCjKrGr5oA&download=image.png "")

```text
spring.application.name=stream-sample
#server.port=63001
#server.port=63000
server.port=63002

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

![](https://tcs.teambition.net/storage/3122a59562102c14e7606b31d6e42e3002cb?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA5OSwiaWF0IjoxNjEyMTkwMjk5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhNTk1NjIxMDJjMTRlNzYwNmIzMWQ2ZTQyZTMwMDJjYiJ9.WIaJ5QS-a3NCw214Y6CFYP3qgBoADgMMUyqvUbwDwzc&download=image.png "")

![](https://tcs.teambition.net/storage/3122f3b62a9a3d27e4ff392cc5e3d58a1de7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA5OSwiaWF0IjoxNjEyMTkwMjk5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJmM2I2MmE5YTNkMjdlNGZmMzkyY2M1ZTNkNThhMWRlNyJ9.8W0dXW5klvBNJ-kkHDFv77rVG-Tg2to8QfCnVWYAraQ&download=image.png "")

如果被成功消费 异常是不会抛出的

![](https://tcs.teambition.net/storage/312288337ac310380b3118c23fff99b5a4bf?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA5OSwiaWF0IjoxNjEyMTkwMjk5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI4ODMzN2FjMzEwMzgwYjMxMThjMjNmZmY5OWI1YTRiZiJ9.xzhnww0AFmEcYXsSWp5auptttLBQKwWEI-aj0QDOjfs&download=image.png "")

```text
2021-01-31 14:45:31.554  WARN 2001 --- [io-63002-exec-2] .w.s.m.s.DefaultHandlerExceptionResolver : Resolved [org.springframework.web.bind.MissingServletRequestParameterException: Required String parameter 'body' is not present]
2021-01-31 14:45:46.733  INFO 2001 --- [io-63002-exec-4] o.s.a.r.c.CachingConnectionFactory       : Attempting to connect to: [localhost:5672]
2021-01-31 14:45:46.757  INFO 2001 --- [io-63002-exec-4] o.s.a.r.c.CachingConnectionFactory       : Created new connection: rabbitConnectionFactory.publisher#9795d0c:0/SimpleConnection@77f7d502 [delegate=amqp://guest@127.0.0.1:5672/, localPort= 63517]
2021-01-31 14:45:46.763  INFO 2001 --- [io-63002-exec-4] o.s.amqp.rabbit.core.RabbitAdmin         : Auto-declaring a non-durable, auto-delete, or exclusive Queue (input.anonymous.2umGZfxXRXuyJ5wmgoG_Qg) durable:false, auto-delete:true, exclusive:true. It will be redeclared if the broker stops and is restarted while the connection factory is alive, but all messages will be lost.
2021-01-31 14:45:46.764  INFO 2001 --- [io-63002-exec-4] o.s.amqp.rabbit.core.RabbitAdmin         : Auto-declaring a non-durable, auto-delete, or exclusive Queue (broadcast.anonymous.bBfWArfRS1eyZHhOQ4PurA) durable:false, auto-delete:true, exclusive:true. It will be redeclared if the broker stops and is restarted while the connection factory is alive, but all messages will be lost.
2021-01-31 14:45:46.764  INFO 2001 --- [io-63002-exec-4] o.s.amqp.rabbit.core.RabbitAdmin         : Auto-declaring a non-durable, auto-delete, or exclusive Queue (delayed-topic.anonymous.nP5SgzOqRNOmKymGDkjbDg) durable:false, auto-delete:true, exclusive:true. It will be redeclared if the broker stops and is restarted while the connection factory is alive, but all messages will be lost.
2021-01-31 14:45:46.764  INFO 2001 --- [io-63002-exec-4] o.s.amqp.rabbit.core.RabbitAdmin         : Auto-declaring a non-durable, auto-delete, or exclusive Queue (error-out-topic.anonymous.tjaPbO2rQzWh3zli1irHdQ) durable:false, auto-delete:true, exclusive:true. It will be redeclared if the broker stops and is restarted while the connection factory is alive, but all messages will be lost.
2021-01-31 14:45:46.889  INFO 2001 --- [zWh3zli1irHdQ-1] c.imooc.springcloud.biz.StreamConsumer   : Are you OK?
2021-01-31 14:45:46.889  INFO 2001 --- [zWh3zli1irHdQ-1] c.imooc.springcloud.biz.StreamConsumer   : What's your problem?
2021-01-31 14:45:47.902  INFO 2001 --- [zWh3zli1irHdQ-1] c.imooc.springcloud.biz.StreamConsumer   : Are you OK?
2021-01-31 14:45:47.903  INFO 2001 --- [zWh3zli1irHdQ-1] c.imooc.springcloud.biz.StreamConsumer   : Fine, thank you. And you?


```

不能被成功消费将抛出异常

![](https://tcs.teambition.net/storage/31223d77fbe4f9af737951f51d80a1543e4c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA5OSwiaWF0IjoxNjEyMTkwMjk5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzZDc3ZmJlNGY5YWY3Mzc5NTFmNTFkODBhMTU0M2U0YyJ9.N9EAeRhxGwqATSHxQN_w8e7x62arnCmFOmyiG9sC7qk&download=image.png "")

![](https://tcs.teambition.net/storage/3122e9ecbd8f31cd169449aff86dd003096b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA5OSwiaWF0IjoxNjEyMTkwMjk5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJlOWVjYmQ4ZjMxY2QxNjk0NDlhZmY4NmRkMDAzMDk2YiJ9.o2O4IjUKtT78GR9AMsOH204NKGc_rv_Ox6OhtKo35S8&download=image.png "")

```text
2021-01-31 14:50:02.820  INFO 2001 --- [zWh3zli1irHdQ-1] c.imooc.springcloud.biz.StreamConsumer   : Are you OK?
2021-01-31 14:50:02.822  INFO 2001 --- [zWh3zli1irHdQ-1] c.imooc.springcloud.biz.StreamConsumer   : What's your problem?
2021-01-31 14:50:03.825  INFO 2001 --- [zWh3zli1irHdQ-1] c.imooc.springcloud.biz.StreamConsumer   : Are you OK?
2021-01-31 14:50:03.826  INFO 2001 --- [zWh3zli1irHdQ-1] c.imooc.springcloud.biz.StreamConsumer   : What's your problem?
2021-01-31 14:50:03.889 ERROR 2001 --- [zWh3zli1irHdQ-1] o.s.integration.handler.LoggingHandler   : org.springframework.messaging.MessagingException: Exception thrown while invoking com.imooc.springcloud.biz.StreamConsumer#consumeErrorMessage[1 args]; nested exception is java.lang.RuntimeException: I'm not OK, failedMessage=GenericMessage [payload=byte[18], headers={amqp_receivedDeliveryMode=PERSISTENT, amqp_receivedExchange=error-out-topic, amqp_deliveryTag=2, deliveryAttempt=2, amqp_consumerQueue=error-out-topic.anonymous.tjaPbO2rQzWh3zli1irHdQ, amqp_redelivered=false, amqp_receivedRoutingKey=error-out-topic, amqp_timestamp=Sun Jan 31 14:50:02 CST 2021, amqp_messageId=63272622-2d14-60d0-bb01-35a11e3ca73d, id=2ac60587-0db5-8e0f-522a-bf13fb6eb1f9, amqp_consumerTag=amq.ctag-_SGNnI1QbpeJ3tziMTuv_Q, contentType=application/json, timestamp=1612075802814}]
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
	at com.imooc.springcloud.biz.StreamConsumer.consumeErrorMessage(StreamConsumer.java:96)
	at sun.reflect.NativeMethodAccessorImpl.invoke0(Native Method)
	at sun.reflect.NativeMethodAccessorImpl.invoke(NativeMethodAccessorImpl.java:62)
	at sun.reflect.DelegatingMethodAccessorImpl.invoke(DelegatingMethodAccessorImpl.java:43)
	at java.lang.reflect.Method.invoke(Method.java:498)
	at org.springframework.messaging.handler.invocation.InvocableHandlerMethod.doInvoke(InvocableHandlerMethod.java:171)
	at org.springframework.messaging.handler.invocation.InvocableHandlerMethod.invoke(InvocableHandlerMethod.java:120)
	at org.springframework.cloud.stream.binding.StreamListenerMessageHandler.handleRequestMessage(StreamListenerMessageHandler.java:55)
	... 29 more

2021-01-31 14:50:03.949  WARN 2001 --- [zWh3zli1irHdQ-1] o.s.a.r.r.RejectAndDontRequeueRecoverer  : Retries exhausted for message (Body:'{"payload":"test"}' MessageProperties [headers={}, timestamp=Sun Jan 31 14:50:02 CST 2021, messageId=63272622-2d14-60d0-bb01-35a11e3ca73d, contentType=application/json, contentLength=0, receivedDeliveryMode=PERSISTENT, priority=0, redelivered=false, receivedExchange=error-out-topic, receivedRoutingKey=error-out-topic, deliveryTag=2, consumerTag=amq.ctag-_SGNnI1QbpeJ3tziMTuv_Q, consumerQueue=error-out-topic.anonymous.tjaPbO2rQzWh3zli1irHdQ])

org.springframework.messaging.MessagingException: Exception thrown while invoking com.imooc.springcloud.biz.StreamConsumer#consumeErrorMessage[1 args]; nested exception is java.lang.RuntimeException: I'm not OK
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
	at com.imooc.springcloud.biz.StreamConsumer.consumeErrorMessage(StreamConsumer.java:96) ~[classes/:na]
	at sun.reflect.NativeMethodAccessorImpl.invoke0(Native Method) ~[na:1.8.0_181]
	at sun.reflect.NativeMethodAccessorImpl.invoke(NativeMethodAccessorImpl.java:62) ~[na:1.8.0_181]
	at sun.reflect.DelegatingMethodAccessorImpl.invoke(DelegatingMethodAccessorImpl.java:43) ~[na:1.8.0_181]
	at java.lang.reflect.Method.invoke(Method.java:498) ~[na:1.8.0_181]
	at org.springframework.messaging.handler.invocation.InvocableHandlerMethod.doInvoke(InvocableHandlerMethod.java:171) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.messaging.handler.invocation.InvocableHandlerMethod.invoke(InvocableHandlerMethod.java:120) ~[spring-messaging-5.1.16.RELEASE.jar:5.1.16.RELEASE]
	at org.springframework.cloud.stream.binding.StreamListenerMessageHandler.handleRequestMessage(StreamListenerMessageHandler.java:55) ~[spring-cloud-stream-2.1.2.RELEASE.jar:2.1.2.RELEASE]
	... 29 common frames omitted

2021-01-31 14:50:03.971  WARN 2001 --- [zWh3zli1irHdQ-1] s.a.r.l.ConditionalRejectingErrorHandler : Execution of Rabbit message listener failed.

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
Caused by: org.springframework.messaging.MessageDeliveryException: failed to send Message to channel 'error-out-topic.anonymous.tjaPbO2rQzWh3zli1irHdQ.errors'; nested exception is org.springframework.amqp.rabbit.listener.exception.ListenerExecutionFailedException: Retry Policy Exhausted
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
Caused by: org.springframework.messaging.MessagingException: Exception thrown while invoking com.imooc.springcloud.biz.StreamConsumer#consumeErrorMessage[1 args]; nested exception is java.lang.RuntimeException: I'm not OK
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
	at com.imooc.springcloud.biz.StreamConsumer.consumeErrorMessage(StreamConsumer.java:96) ~[classes/:na]
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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA5OSwiaWF0IjoxNjEyMTkwMjk5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.6OcyVw7xjf--oY0PWbY3ApSsa3KZzoi-De6-njTp_SQ&download=image.png "")

