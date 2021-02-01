![](https://tcs.teambition.net/storage/31229346835bc400ed1fae2bd3b88d084fe0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA2NCwiaWF0IjoxNjEyMTkwMjY0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5MzQ2ODM1YmM0MDBlZDFmYWUyYmQzYjg4ZDA4NGZlMCJ9.Eiw36CEmDwsOFFBnAzNlXf7ECsoU4tKE0YN0GEBL3_g&download=image.png "")

![](https://tcs.teambition.net/storage/3122fb44c354cca1cf88e2caefe6a14c84c8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA2NCwiaWF0IjoxNjEyMTkwMjY0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJmYjQ0YzM1NGNjYTFjZjg4ZTJjYWVmZTZhMTRjODRjOCJ9.yIeLdJuG7mDsjxDlIrLx52o-D52YB1JA0EHbeeZHMX8&download=image.png "")

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
public interface FallbackTopic {

    /**
     * 把两个 信道绑定在一起
     */
    String INPUT = "fallback-consumer";

    String OUTPUT = "fallback-producer";

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

![](https://tcs.teambition.net/storage/3122deaeda47f60f5c7ee3a043b46e67c606?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA2NCwiaWF0IjoxNjEyMTkwMjY0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkZWFlZGE0N2Y2MGY1YzdlZTNhMDQzYjQ2ZTY3YzYwNiJ9.Lq-XW6O4skvAgw-ZeP1bS4Fz7GGKsTiOgxInF8aJvBw&download=image.png "")

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


```

![](https://tcs.teambition.net/storage/312216cc68c26e811e587bdc338a1987370a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA2NCwiaWF0IjoxNjEyMTkwMjY0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxNmNjNjhjMjZlODExZTU4N2JkYzMzOGExOTg3MzcwYSJ9.YFVMQ2zdbTZp_fz4IVOHUstPyqfLoJardgrZhPqwi-o&download=image.png "")

```java
package com.imooc.springcloud.biz;

import com.imooc.springcloud.topic.*;
import lombok.extern.slf4j.Slf4j;
import org.springframework.cloud.stream.annotation.EnableBinding;
import org.springframework.cloud.stream.annotation.StreamListener;
import org.springframework.cloud.stream.messaging.Sink;
import org.springframework.integration.annotation.ServiceActivator;
import org.springframework.messaging.Message;
import org.springframework.messaging.handler.annotation.Header;

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
        DlqTopic.class,
        FallbackTopic.class
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

    // Fallback + 升级版本
    @StreamListener(FallbackTopic.INPUT)
    public void goodbyeBadGuy(MessageBean bean,
                              // 接收从上游传下来的version
                              @Header("version")String version) {
        log.info("Fallback - Are you OK?");

        if ("1.0".equalsIgnoreCase(version)) {
            log.info("Fallback - Fine, thank you. And you?");
        } else if ("2.0".equalsIgnoreCase(version)) {
            log.info("unsupported version");
            throw new RuntimeException("I'm not OK");
        } else {
            log.info("Fallback - version={}", version);
        }

    }

    /**
     * 使用 spring intergration 组件
     * 指定一个 input channel 信道的名称
     * 降级逻辑
     * goodbyeBadGuy 业务请求抛出异常 并且重试次数 达到上限了 以后
     * 就会转到fallback 逻辑里面
     */
    @ServiceActivator(inputChannel = "fallback-topic.fallback-group.errors")
    public void fallback(Message<?> message) {
        log.info("fallback entered");
    }


}


```

![](https://tcs.teambition.net/storage/3122f46583b668e40f580510c2b343815c73?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA2NCwiaWF0IjoxNjEyMTkwMjY0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJmNDY1ODNiNjY4ZTQwZjU4MDUxMGMyYjM0MzgxNWM3MyJ9.U2Lr5C9yeS2ZZ3LVO_NmogdPw2XiSw2FxlPnECdyZNU&download=image.png "")

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


# 死信队列配置
spring.cloud.stream.bindings.dlq-consumer.destination=dlq-topic
spring.cloud.stream.bindings.dlq-producer.destination=dlq-topic
# 这里可以理解为尝试次数 在接收消息后 消费一次以后 还要重新尝试retry一次 这里不是requeue
spring.cloud.stream.bindings.dlq-consumer.consumer.max-attempts=2
spring.cloud.stream.bindings.dlq-consumer.group=dlq-group
# 专门给死信队列的一个配置 在初始化项目的时候 stream 就会向mq 添加一个死信队列
# 死信队列的名称 默认就是topic.dlq
# 开启死信队列，会创建一个默认死信队列 名称就是 topic.dlq
spring.cloud.stream.rabbit.bindings.dlq-consumer.consumer.auto-bind-dlq=true

# Fallback配置
spring.cloud.stream.bindings.fallback-consumer.destination=fallback-topic
spring.cloud.stream.bindings.fallback-producer.destination=fallback-topic
# 这里可以理解为尝试次数 在接收消息后 消费一次以后 还要重新尝试retry一次 这里不是requeue
spring.cloud.stream.bindings.fallback-consumer.consumer.max-attempts=2
spring.cloud.stream.bindings.fallback-consumer.group=fallback-group
# input channel -> fallback-topic.fallback-group.errors 特殊的标记 errors

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

![](https://tcs.teambition.net/storage/312202d9cc19c8f873fddadb480e1f5f68ae?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA2NCwiaWF0IjoxNjEyMTkwMjY0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIwMmQ5Y2MxOWM4Zjg3M2ZkZGFkYjQ4MGUxZjVmNjhhZSJ9.ApBA8OThQliD53HdySEagvu96ExYXfJvPuL-1WPmHOo&download=image.png "")

![](https://tcs.teambition.net/storage/3122ffa46d3914c8be4bf3fff06cf072f0d2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA2NCwiaWF0IjoxNjEyMTkwMjY0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJmZmE0NmQzOTE0YzhiZTRiZjNmZmYwNmNmMDcyZjBkMiJ9.JtM2hIxCfCySDh0uxmEzJXL_GSo8GeFx8-ZBdWGBPtw&download=image.png "")

![](https://tcs.teambition.net/storage/312226eba7fc4bc96664a3ddf2ba9e91554a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA2NCwiaWF0IjoxNjEyMTkwMjY0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIyNmViYTdmYzRiYzk2NjY0YTNkZGYyYmE5ZTkxNTU0YSJ9.zwB1_RWFTp59cYIOrCizAy8qH6sAggzQdaO0oEpwOWU&download=image.png "")

```text
2021-01-31 20:23:57.532  INFO 20920 --- [allback-group-1] c.imooc.springcloud.biz.StreamConsumer   : Fallback - Are you OK?
2021-01-31 20:23:57.533  INFO 20920 --- [allback-group-1] c.imooc.springcloud.biz.StreamConsumer   : Fallback - Fine, thank you. And you?


```

![](https://tcs.teambition.net/storage/3122504f99e7211422bdb80deda51f5f3f64?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA2NCwiaWF0IjoxNjEyMTkwMjY0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI1MDRmOTllNzIxMTQyMmJkYjgwZGVkYTUxZjVmM2Y2NCJ9.q1EYdIa_oo9YcGTuQqIHMZbeq12eRG_amSSXvWmwsEk&download=image.png "")

![](https://tcs.teambition.net/storage/3122512f02bb5bc2b75ff1ecb31b7793fe25?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA2NCwiaWF0IjoxNjEyMTkwMjY0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI1MTJmMDJiYjViYzJiNzVmZjFlY2IzMWI3NzkzZmUyNSJ9.3XsTGtdJ-DSMi5AwgBptMX65iNkP8O2FwiJkW6QnQ70&download=image.png "")

```text
2021-01-31 20:27:01.524  INFO 20920 --- [allback-group-1] c.imooc.springcloud.biz.StreamConsumer   : Fallback - Are you OK?
2021-01-31 20:27:01.526  INFO 20920 --- [allback-group-1] c.imooc.springcloud.biz.StreamConsumer   : Fallback - version=3.0


```

![](https://tcs.teambition.net/storage/31223742a0acdeeede0478a6cbc9a2e86343?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA2NCwiaWF0IjoxNjEyMTkwMjY0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzNzQyYTBhY2RlZWVkZTA0NzhhNmNiYzlhMmU4NjM0MyJ9.WA58EHn-8SpLnqG3AFl_WVnte6LhH3R7EirZbIeCE80&download=image.png "")

![](https://tcs.teambition.net/storage/31223290f7d9014cf5e44a01edd67dd9b326?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA2NCwiaWF0IjoxNjEyMTkwMjY0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzMjkwZjdkOTAxNGNmNWU0NGEwMWVkZDY3ZGQ5YjMyNiJ9.R6SpKuNIipDJgFmnVDNLOVF7kgI7SDqr_egwgS58KBo&download=image.png "")

```text
2021-01-31 20:27:52.684  INFO 20920 --- [allback-group-1] c.imooc.springcloud.biz.StreamConsumer   : Fallback - Are you OK?
2021-01-31 20:27:52.684  INFO 20920 --- [allback-group-1] c.imooc.springcloud.biz.StreamConsumer   : unsupported version
2021-01-31 20:27:53.711  INFO 20920 --- [allback-group-1] c.imooc.springcloud.biz.StreamConsumer   : Fallback - Are you OK?
2021-01-31 20:27:53.711  INFO 20920 --- [allback-group-1] c.imooc.springcloud.biz.StreamConsumer   : unsupported version
2021-01-31 20:27:53.729  INFO 20920 --- [allback-group-1] c.imooc.springcloud.biz.StreamConsumer   : fallback entered


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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA2NCwiaWF0IjoxNjEyMTkwMjY0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.WAzwKXZxgcX_rue1HPiZ8y2wJfFBmVxH7yiM3HUEwt4&download=image.png "")

