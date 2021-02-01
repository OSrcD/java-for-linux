

![](https://tcs.teambition.net/storage/31221660415c687bb8b17175ae6ce6c2ac64?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxNjYwNDE1YzY4N2JiOGIxNzE3NWFlNmNlNmMyYWM2NCJ9.jTkElt70YVeSAEkdcNvIarWKR6x403tP-zdBbyr67VY&download=2020-09-17%20061535.png "")

![](https://tcs.teambition.net/storage/31221738c4e89eb5ec3cacacd6c71b9e56d5?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxNzM4YzRlODllYjVlYzNjYWNhY2Q2YzcxYjllNTZkNSJ9.JHhG56fs8NEeDLwzCCMWiY4p8XWCdbTxLF0CIYnrHBU&download=2020-09-17%20061557.png "")

![](https://tcs.teambition.net/storage/312254d8aae2fd848228ff2f2515aa4e6020?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI1NGQ4YWFlMmZkODQ4MjI4ZmYyZjI1MTVhYTRlNjAyMCJ9.dXwEVgVINMSvTc_bqkJd7uutLvl-I4WuhqJYOUPodhY&download=image.png "")

![](https://tcs.teambition.net/storage/312204418c3deec8106dc1f3c83cefdec892?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIwNDQxOGMzZGVlYzgxMDZkYzFmM2M4M2NlZmRlYzg5MiJ9.ZrUeS_Q_iJ7UC_gtExPy0f6FDeZS1u2TzDN5XbuHDeM&download=image.png "")

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
public interface GroupTopic {

    /**
     * 把两个 信道绑定在一起
     */
    String INPUT = "group-consumer";

    String OUTPUT = "group-producer";

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

![](https://tcs.teambition.net/storage/31223db1176aaf00561c66993203ca8a13be?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzZGIxMTc2YWFmMDA1NjFjNjY5OTMyMDNjYThhMTNiZSJ9.l1rNXWaqdAL9oOcmYGXpLPINTE7fVmUQSjqC28vlkcM&download=image.png "")

```java
package com.imooc.springcloud.biz;

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

    @PostMapping("send")
    public void sendMessage(@RequestParam(value = "body") String body) {
        producer.output().send(MessageBuilder.withPayload(body).build());
    }

    @PostMapping("sendToGroup")
    public void sendMessageToGroup(@RequestParam(value = "body") String body) {
        groupTopicProducer.output().send(MessageBuilder.withPayload(body).build());
    }






}

```

![](https://tcs.teambition.net/storage/312281835a7f73366639f5c87c939895ea5d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI4MTgzNWE3ZjczMzY2NjM5ZjVjODdjOTM5ODk1ZWE1ZCJ9.-QGZByeVnLBAvfhHfkOrYmeUAR5JA5nCrK2rQjKOpIA&download=image.png "")

```java
package com.imooc.springcloud.biz;

import com.imooc.springcloud.topic.GroupTopic;
import com.imooc.springcloud.topic.MyTopic;
import lombok.extern.slf4j.Slf4j;
import org.springframework.cloud.stream.annotation.EnableBinding;
import org.springframework.cloud.stream.annotation.StreamListener;
import org.springframework.cloud.stream.messaging.Sink;

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
        GroupTopic.class
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
     * 默认目的地信道接口 Sink 翻译为目的地
     * 被注解之后通道与这个类通过反射绑定起来 从应用程序绑定到一起 多个
     * 当binder与消息中间件通信 发送消息过来 通过反射实例化对象执行这些方法
     *
     */
    @StreamListener(Sink.INPUT) // 这里的值就是 "input"
    public void consume(Object payload) {

        log.info("message consumed successfully，payload={}", payload);
    }
    @StreamListener(MyTopic.INPUT) // 这里的值就是 "input"
    public void consumeMyMessage(Object payload) {

        log.info("My message consumed successfully，payload={}", payload);
    }

    @StreamListener(GroupTopic.INPUT) // 这里的值就是 "input"
    public void consumeGroupMyMessage(Object payload) {
        log.info("Group message consumed successfully，payload={}", payload);
    }


}

```

![](https://tcs.teambition.net/storage/3122a75f2fc25543555c2ec8cd2bf16a8384?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhNzVmMmZjMjU1NDM1NTVjMmVjOGNkMmJmMTZhODM4NCJ9.Pm2rhc8XYyIESNdGhYqM_0v9SRPN4pkpRmtMm9mklA0&download=image.png "")

```text
spring.application.name=stream-sample
server.port=63001
#server.port=63000

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


management.endpoints.web.exposure.include=*
management.endpoint.health.show-details=always
```

![](https://tcs.teambition.net/storage/312291699f9417b0a8094549a3479222524f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5MTY5OWY5NDE3YjBhODA5NDU0OWEzNDc5MjIyNTI0ZiJ9.8ZGVt-5DgMf63HuYDhfq6H4xKcbZN-PsnmA6eRT0uTk&download=image.png "")

![](https://tcs.teambition.net/storage/312233bde5f9ac8128cd08c5ef1e6c489b4c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzM2JkZTVmOWFjODEyOGNkMDhjNWVmMWU2YzQ4OWI0YyJ9.5WyscwjVl2UoZWLHs6sUPrVrzfD1SDuL90aAADsbJjg&download=image.png "")

![](https://tcs.teambition.net/storage/3122dd8a991d63de882655e8fb52f72e3a1d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkZDhhOTkxZDYzZGU4ODI2NTVlOGZiNTJmNzJlM2ExZCJ9._WkqvYRvk2_fUpo7ZL78tNKWj8g_9uDgTROMTp7fTCU&download=image.png "")

![](https://tcs.teambition.net/storage/312202f0b56d843dada3da3ea93106154935?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIwMmYwYjU2ZDg0M2RhZGEzZGEzZWE5MzEwNjE1NDkzNSJ9.JB1ExygnBlIHRFpBwGuclRYmp8-wbYTmlM_liYsZd6M&download=image.png "")

![](https://tcs.teambition.net/storage/3122a8c4ba8d96f7c57f413b788bc7d4a184?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhOGM0YmE4ZDk2ZjdjNTdmNDEzYjc4OGJjN2Q0YTE4NCJ9.9aHFeORL1CDmR__ksXt4OFr3JSKT6HTODc5akoN0HSk&download=image.png "")

被组内一台服务器消费掉了

![](https://tcs.teambition.net/storage/31224787ce2bfbd5ffa75707169706280790?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI0Nzg3Y2UyYmZiZDVmZmE3NTcwNzE2OTcwNjI4MDc5MCJ9.U8HJpWIi8iICLuuI_luTXsrZEiDi_S7g5ciHCjgTY2g&download=image.png "")

```text
/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/bin/java -agentlib:jdwp=transport=dt_socket,address=127.0.0.1:59150,suspend=y,server=n -XX:TieredStopAtLevel=1 -noverify -Dspring.output.ansi.enabled=always -javaagent:/Users/virtualman/Library/Caches/JetBrains/IntelliJIdea2021.1/groovyHotSwap/gragent.jar -javaagent:/Users/virtualman/Library/Caches/JetBrains/IntelliJIdea2021.1/captureAgent/debugger-agent.jar -agentpath:/private/var/folders/f7/h5k23k254y14yl9frqxjmjzh0000gn/T/libmemory_agent.dylib= -Dcom.sun.management.jmxremote -Dspring.jmx.enabled=true -Dspring.liveBeansView.mbeanDomain -Dspring.application.admin.enabled=true -Dfile.encoding=UTF-8 -classpath /Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/charsets.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/deploy.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/ext/cldrdata.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/ext/dnsns.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/ext/jaccess.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/ext/jfxrt.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/ext/localedata.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/ext/nashorn.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/ext/sunec.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/ext/sunjce_provider.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/ext/sunpkcs11.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/ext/zipfs.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/javaws.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/jce.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/jfr.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/jfxswt.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/jsse.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/management-agent.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/plugin.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/resources.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/rt.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/lib/ant-javafx.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/lib/dt.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/lib/javafx-mx.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/lib/jconsole.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/lib/packager.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/lib/sa-jdi.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/lib/tools.jar:/Users/virtualman/IdeaProjects/java-for-linux/java-for-alibaba/spring-cloud-demo/stream/stream-sample/target/classes:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-starter-web/2.1.15.RELEASE/spring-boot-starter-web-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-starter/2.1.15.RELEASE/spring-boot-starter-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot/2.1.15.RELEASE/spring-boot-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-autoconfigure/2.1.15.RELEASE/spring-boot-autoconfigure-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-starter-logging/2.1.15.RELEASE/spring-boot-starter-logging-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/ch/qos/logback/logback-classic/1.2.3/logback-classic-1.2.3.jar:/Users/virtualman/.m2/repository/ch/qos/logback/logback-core/1.2.3/logback-core-1.2.3.jar:/Users/virtualman/.m2/repository/org/slf4j/slf4j-api/1.7.30/slf4j-api-1.7.30.jar:/Users/virtualman/.m2/repository/org/apache/logging/log4j/log4j-to-slf4j/2.11.2/log4j-to-slf4j-2.11.2.jar:/Users/virtualman/.m2/repository/org/apache/logging/log4j/log4j-api/2.11.2/log4j-api-2.11.2.jar:/Users/virtualman/.m2/repository/org/slf4j/jul-to-slf4j/1.7.30/jul-to-slf4j-1.7.30.jar:/Users/virtualman/.m2/repository/javax/annotation/javax.annotation-api/1.3.2/javax.annotation-api-1.3.2.jar:/Users/virtualman/.m2/repository/org/springframework/spring-core/5.1.16.RELEASE/spring-core-5.1.16.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/spring-jcl/5.1.16.RELEASE/spring-jcl-5.1.16.RELEASE.jar:/Users/virtualman/.m2/repository/org/yaml/snakeyaml/1.23/snakeyaml-1.23.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-starter-json/2.1.15.RELEASE/spring-boot-starter-json-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/com/fasterxml/jackson/core/jackson-databind/2.9.10.4/jackson-databind-2.9.10.4.jar:/Users/virtualman/.m2/repository/com/fasterxml/jackson/core/jackson-annotations/2.9.10/jackson-annotations-2.9.10.jar:/Users/virtualman/.m2/repository/com/fasterxml/jackson/core/jackson-core/2.9.10/jackson-core-2.9.10.jar:/Users/virtualman/.m2/repository/com/fasterxml/jackson/datatype/jackson-datatype-jdk8/2.9.10/jackson-datatype-jdk8-2.9.10.jar:/Users/virtualman/.m2/repository/com/fasterxml/jackson/datatype/jackson-datatype-jsr310/2.9.10/jackson-datatype-jsr310-2.9.10.jar:/Users/virtualman/.m2/repository/com/fasterxml/jackson/module/jackson-module-parameter-names/2.9.10/jackson-module-parameter-names-2.9.10.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-starter-tomcat/2.1.15.RELEASE/spring-boot-starter-tomcat-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/org/apache/tomcat/embed/tomcat-embed-core/9.0.36/tomcat-embed-core-9.0.36.jar:/Users/virtualman/.m2/repository/org/apache/tomcat/embed/tomcat-embed-el/9.0.36/tomcat-embed-el-9.0.36.jar:/Users/virtualman/.m2/repository/org/apache/tomcat/embed/tomcat-embed-websocket/9.0.36/tomcat-embed-websocket-9.0.36.jar:/Users/virtualman/.m2/repository/org/hibernate/validator/hibernate-validator/6.0.20.Final/hibernate-validator-6.0.20.Final.jar:/Users/virtualman/.m2/repository/javax/validation/validation-api/2.0.1.Final/validation-api-2.0.1.Final.jar:/Users/virtualman/.m2/repository/org/jboss/logging/jboss-logging/3.3.3.Final/jboss-logging-3.3.3.Final.jar:/Users/virtualman/.m2/repository/com/fasterxml/classmate/1.4.0/classmate-1.4.0.jar:/Users/virtualman/.m2/repository/org/springframework/spring-web/5.1.16.RELEASE/spring-web-5.1.16.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/spring-beans/5.1.16.RELEASE/spring-beans-5.1.16.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/spring-webmvc/5.1.16.RELEASE/spring-webmvc-5.1.16.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/spring-aop/5.1.16.RELEASE/spring-aop-5.1.16.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/spring-context/5.1.16.RELEASE/spring-context-5.1.16.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/spring-expression/5.1.16.RELEASE/spring-expression-5.1.16.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-starter-actuator/2.1.15.RELEASE/spring-boot-starter-actuator-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-actuator-autoconfigure/2.1.15.RELEASE/spring-boot-actuator-autoconfigure-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-actuator/2.1.15.RELEASE/spring-boot-actuator-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/io/micrometer/micrometer-core/1.1.14/micrometer-core-1.1.14.jar:/Users/virtualman/.m2/repository/org/hdrhistogram/HdrHistogram/2.1.9/HdrHistogram-2.1.9.jar:/Users/virtualman/.m2/repository/org/latencyutils/LatencyUtils/2.0.3/LatencyUtils-2.0.3.jar:/Users/virtualman/.m2/repository/org/springframework/cloud/spring-cloud-starter-stream-rabbit/2.1.2.RELEASE/spring-cloud-starter-stream-rabbit-2.1.2.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/cloud/spring-cloud-stream-binder-rabbit/2.1.2.RELEASE/spring-cloud-stream-binder-rabbit-2.1.2.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/cloud/spring-cloud-stream-binder-rabbit-core/2.1.2.RELEASE/spring-cloud-stream-binder-rabbit-core-2.1.2.RELEASE.jar:/Users/virtualman/.m2/repository/com/rabbitmq/http-client/2.1.0.RELEASE/http-client-2.1.0.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/cloud/spring-cloud-stream/2.1.2.RELEASE/spring-cloud-stream-2.1.2.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-starter-validation/2.1.15.RELEASE/spring-boot-starter-validation-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/spring-messaging/5.1.16.RELEASE/spring-messaging-5.1.16.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/spring-tuple/1.0.0.RELEASE/spring-tuple-1.0.0.RELEASE.jar:/Users/virtualman/.m2/repository/com/esotericsoftware/kryo-shaded/3.0.3/kryo-shaded-3.0.3.jar:/Users/virtualman/.m2/repository/com/esotericsoftware/minlog/1.3.0/minlog-1.3.0.jar:/Users/virtualman/.m2/repository/org/objenesis/objenesis/2.1/objenesis-2.1.jar:/Users/virtualman/.m2/repository/org/springframework/integration/spring-integration-tuple/1.0.0.RELEASE/spring-integration-tuple-1.0.0.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/retry/spring-retry/1.2.5.RELEASE/spring-retry-1.2.5.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/cloud/spring-cloud-function-context/2.0.1.RELEASE/spring-cloud-function-context-2.0.1.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/cloud/spring-cloud-function-core/2.0.1.RELEASE/spring-cloud-function-core-2.0.1.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-starter-amqp/2.1.15.RELEASE/spring-boot-starter-amqp-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/amqp/spring-rabbit/2.1.15.RELEASE/spring-rabbit-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/com/rabbitmq/amqp-client/5.4.3/amqp-client-5.4.3.jar:/Users/virtualman/.m2/repository/org/springframework/amqp/spring-amqp/2.1.15.RELEASE/spring-amqp-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/integration/spring-integration-amqp/5.1.11.RELEASE/spring-integration-amqp-5.1.11.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/integration/spring-integration-core/5.1.11.RELEASE/spring-integration-core-5.1.11.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/spring-tx/5.1.16.RELEASE/spring-tx-5.1.16.RELEASE.jar:/Users/virtualman/.m2/repository/io/projectreactor/reactor-core/3.2.18.RELEASE/reactor-core-3.2.18.RELEASE.jar:/Users/virtualman/.m2/repository/org/reactivestreams/reactive-streams/1.0.3/reactive-streams-1.0.3.jar:/Users/virtualman/.m2/repository/org/springframework/integration/spring-integration-jmx/5.1.11.RELEASE/spring-integration-jmx-5.1.11.RELEASE.jar:/Users/virtualman/.m2/repository/org/apache/httpcomponents/httpclient/4.5.12/httpclient-4.5.12.jar:/Users/virtualman/.m2/repository/org/apache/httpcomponents/httpcore/4.4.13/httpcore-4.4.13.jar:/Users/virtualman/.m2/repository/commons-codec/commons-codec/1.11/commons-codec-1.11.jar:/Users/virtualman/.m2/repository/org/projectlombok/lombok/1.18.8/lombok-1.18.8.jar:/Users/virtualman/Library/Application Support/JetBrains/Toolbox/apps/IDEA-U/ch-0/211.4961.33/IntelliJ IDEA 2021.1 EAP.app/Contents/lib/idea_rt.jar com.imooc.springcloud.StreamApplication
Connected to the target VM, address: '127.0.0.1:59150', transport: 'socket'

  .   ____          _            __ _ _
 /\\ / ___'_ __ _ _(_)_ __  __ _ \ \ \ \
( ( )\___ | '_ | '_| | '_ \/ _` | \ \ \ \
 \\/  ___)| |_)| | | | | || (_| |  ) ) ) )
  '  |____| .__|_| |_|_| |_\__, | / / / /
 =========|_|==============|___/=/_/_/_/
 :: Spring Boot ::       (v2.1.15.RELEASE)

2021-01-31 10:58:52.102  INFO 27048 --- [           main] com.imooc.springcloud.StreamApplication  : Starting StreamApplication on OpenDevel.local with PID 27048 (/Users/virtualman/IdeaProjects/java-for-linux/java-for-alibaba/spring-cloud-demo/stream/stream-sample/target/classes started by virtualman in /Users/virtualman/IdeaProjects/java-for-linux)
2021-01-31 10:58:52.113  INFO 27048 --- [           main] com.imooc.springcloud.StreamApplication  : No active profile set, falling back to default profiles: default
2021-01-31 10:58:57.928  INFO 27048 --- [           main] faultConfiguringBeanFactoryPostProcessor : No bean named 'errorChannel' has been explicitly defined. Therefore, a default PublishSubscribeChannel will be created.
2021-01-31 10:58:57.959  INFO 27048 --- [           main] faultConfiguringBeanFactoryPostProcessor : No bean named 'taskScheduler' has been explicitly defined. Therefore, a default ThreadPoolTaskScheduler will be created.
2021-01-31 10:58:57.982  INFO 27048 --- [           main] faultConfiguringBeanFactoryPostProcessor : No bean named 'integrationHeaderChannelRegistry' has been explicitly defined. Therefore, a default DefaultHeaderChannelRegistry will be created.
2021-01-31 10:58:58.162  INFO 27048 --- [           main] trationDelegate$BeanPostProcessorChecker : Bean 'integrationDisposableAutoCreatedBeans' of type [org.springframework.integration.config.annotation.Disposables] is not eligible for getting processed by all BeanPostProcessors (for example: not eligible for auto-proxying)
2021-01-31 10:58:58.204  INFO 27048 --- [           main] trationDelegate$BeanPostProcessorChecker : Bean 'org.springframework.integration.config.IntegrationManagementConfiguration' of type [org.springframework.integration.config.IntegrationManagementConfiguration$$EnhancerBySpringCGLIB$$ce1b208d] is not eligible for getting processed by all BeanPostProcessors (for example: not eligible for auto-proxying)
2021-01-31 10:58:58.241  INFO 27048 --- [           main] trationDelegate$BeanPostProcessorChecker : Bean 'org.springframework.boot.autoconfigure.integration.IntegrationAutoConfiguration$IntegrationJmxConfiguration' of type [org.springframework.boot.autoconfigure.integration.IntegrationAutoConfiguration$IntegrationJmxConfiguration$$EnhancerBySpringCGLIB$$a9ad2bad] is not eligible for getting processed by all BeanPostProcessors (for example: not eligible for auto-proxying)
2021-01-31 10:58:58.265  INFO 27048 --- [           main] trationDelegate$BeanPostProcessorChecker : Bean 'org.springframework.boot.autoconfigure.jmx.JmxAutoConfiguration' of type [org.springframework.boot.autoconfigure.jmx.JmxAutoConfiguration$$EnhancerBySpringCGLIB$$e294d47a] is not eligible for getting processed by all BeanPostProcessors (for example: not eligible for auto-proxying)
2021-01-31 10:58:58.275  INFO 27048 --- [           main] trationDelegate$BeanPostProcessorChecker : Bean 'mbeanServer' of type [com.sun.jmx.mbeanserver.JmxMBeanServer] is not eligible for getting processed by all BeanPostProcessors (for example: not eligible for auto-proxying)
2021-01-31 10:58:59.145  INFO 27048 --- [           main] o.s.b.w.embedded.tomcat.TomcatWebServer  : Tomcat initialized with port(s): 63001 (http)
2021-01-31 10:58:59.212  INFO 27048 --- [           main] o.apache.catalina.core.StandardService   : Starting service [Tomcat]
2021-01-31 10:58:59.213  INFO 27048 --- [           main] org.apache.catalina.core.StandardEngine  : Starting Servlet engine: [Apache Tomcat/9.0.36]
2021-01-31 10:58:59.402  INFO 27048 --- [           main] o.a.c.c.C.[Tomcat].[localhost].[/]       : Initializing Spring embedded WebApplicationContext
2021-01-31 10:58:59.402  INFO 27048 --- [           main] o.s.web.context.ContextLoader            : Root WebApplicationContext: initialization completed in 6955 ms
2021-01-31 10:59:01.214  INFO 27048 --- [           main] o.s.s.c.ThreadPoolTaskScheduler          : Initializing ExecutorService 'taskScheduler'
2021-01-31 10:59:02.436  INFO 27048 --- [           main] o.s.s.concurrent.ThreadPoolTaskExecutor  : Initializing ExecutorService 'applicationTaskExecutor'
2021-01-31 10:59:05.356  INFO 27048 --- [           main] o.s.b.a.e.web.EndpointLinksResolver      : Exposing 18 endpoint(s) beneath base path '/actuator'
2021-01-31 10:59:05.801  INFO 27048 --- [           main] o.s.c.s.m.DirectWithAttributesChannel    : Channel 'stream-sample.input' has 1 subscriber(s).
2021-01-31 10:59:05.802  INFO 27048 --- [           main] o.s.c.s.m.DirectWithAttributesChannel    : Channel 'stream-sample.myTopic-consumer' has 1 subscriber(s).
2021-01-31 10:59:05.802  INFO 27048 --- [           main] o.s.c.s.m.DirectWithAttributesChannel    : Channel 'stream-sample.group-consumer' has 1 subscriber(s).
2021-01-31 10:59:06.483  INFO 27048 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageChannel input
2021-01-31 10:59:06.717  INFO 27048 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageChannel myTopic-producer
2021-01-31 10:59:06.756  INFO 27048 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageChannel myTopic-consumer
2021-01-31 10:59:06.780  INFO 27048 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageChannel group-producer
2021-01-31 10:59:06.798  INFO 27048 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageChannel nullChannel
2021-01-31 10:59:06.858  INFO 27048 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageChannel errorChannel
2021-01-31 10:59:07.075  INFO 27048 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageChannel group-consumer
2021-01-31 10:59:07.104  INFO 27048 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageHandler org.springframework.cloud.stream.binding.StreamListenerMessageHandler@4b4a2fa8
2021-01-31 10:59:07.818  INFO 27048 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageHandler org.springframework.cloud.stream.binding.StreamListenerMessageHandler@179ee36b
2021-01-31 10:59:07.840  INFO 27048 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageHandler errorLogger
2021-01-31 10:59:07.916  INFO 27048 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageHandler org.springframework.cloud.stream.binding.StreamListenerMessageHandler@67763ebe
2021-01-31 10:59:08.112  INFO 27048 --- [           main] o.s.i.endpoint.EventDrivenConsumer       : Adding {logging-channel-adapter:_org.springframework.integration.errorLogger} as a subscriber to the 'errorChannel' channel
2021-01-31 10:59:08.112  INFO 27048 --- [           main] o.s.i.channel.PublishSubscribeChannel    : Channel 'stream-sample.errorChannel' has 1 subscriber(s).
2021-01-31 10:59:08.112  INFO 27048 --- [           main] o.s.i.endpoint.EventDrivenConsumer       : started _org.springframework.integration.errorLogger
2021-01-31 10:59:09.344  INFO 27048 --- [           main] o.s.a.r.c.CachingConnectionFactory       : Attempting to connect to: [localhost:5672]
2021-01-31 10:59:09.468  INFO 27048 --- [           main] o.s.a.r.c.CachingConnectionFactory       : Created new connection: rabbitConnectionFactory#6411504a:0/SimpleConnection@1736c1e4 [delegate=amqp://guest@127.0.0.1:5672/, localPort= 59166]
2021-01-31 10:59:09.659  INFO 27048 --- [           main] o.s.c.s.m.DirectWithAttributesChannel    : Channel 'stream-sample.myTopic-producer' has 1 subscriber(s).
2021-01-31 10:59:09.740  INFO 27048 --- [           main] o.s.c.s.m.DirectWithAttributesChannel    : Channel 'stream-sample.group-producer' has 1 subscriber(s).
2021-01-31 10:59:09.846  INFO 27048 --- [           main] c.s.b.r.p.RabbitExchangeQueueProvisioner : declaring queue for inbound: input.anonymous.zUqGLHnUQKiichN6Vt5q7Q, bound to: input
2021-01-31 10:59:09.934  INFO 27048 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageChannel input.anonymous.zUqGLHnUQKiichN6Vt5q7Q.errors
2021-01-31 10:59:10.589  INFO 27048 --- [           main] o.s.c.stream.binder.BinderErrorChannel   : Channel 'stream-sample.input.anonymous.zUqGLHnUQKiichN6Vt5q7Q.errors' has 1 subscriber(s).
2021-01-31 10:59:10.591  INFO 27048 --- [           main] o.s.c.stream.binder.BinderErrorChannel   : Channel 'stream-sample.input.anonymous.zUqGLHnUQKiichN6Vt5q7Q.errors' has 2 subscriber(s).
2021-01-31 10:59:10.637  INFO 27048 --- [           main] o.s.i.a.i.AmqpInboundChannelAdapter      : started inbound.input.anonymous.zUqGLHnUQKiichN6Vt5q7Q
2021-01-31 10:59:10.680  INFO 27048 --- [           main] c.s.b.r.p.RabbitExchangeQueueProvisioner : declaring queue for inbound: broadcast.anonymous.TZxUuOi0ThCHFyrft6SMYQ, bound to: broadcast
2021-01-31 10:59:10.698  INFO 27048 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageChannel broadcast.anonymous.TZxUuOi0ThCHFyrft6SMYQ.errors
2021-01-31 10:59:10.718  INFO 27048 --- [           main] o.s.c.stream.binder.BinderErrorChannel   : Channel 'stream-sample.broadcast.anonymous.TZxUuOi0ThCHFyrft6SMYQ.errors' has 1 subscriber(s).
2021-01-31 10:59:10.719  INFO 27048 --- [           main] o.s.c.stream.binder.BinderErrorChannel   : Channel 'stream-sample.broadcast.anonymous.TZxUuOi0ThCHFyrft6SMYQ.errors' has 2 subscriber(s).
2021-01-31 10:59:10.726  INFO 27048 --- [           main] o.s.i.a.i.AmqpInboundChannelAdapter      : started inbound.broadcast.anonymous.TZxUuOi0ThCHFyrft6SMYQ
2021-01-31 10:59:10.772  INFO 27048 --- [           main] c.s.b.r.p.RabbitExchangeQueueProvisioner : declaring queue for inbound: group-topic.Group-A, bound to: group-topic
2021-01-31 10:59:10.859  INFO 27048 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageChannel group-topic.Group-A.errors
2021-01-31 10:59:10.930  INFO 27048 --- [           main] o.s.c.stream.binder.BinderErrorChannel   : Channel 'stream-sample.group-topic.Group-A.errors' has 1 subscriber(s).
2021-01-31 10:59:10.931  INFO 27048 --- [           main] o.s.c.stream.binder.BinderErrorChannel   : Channel 'stream-sample.group-topic.Group-A.errors' has 2 subscriber(s).
2021-01-31 10:59:10.947  INFO 27048 --- [           main] o.s.i.a.i.AmqpInboundChannelAdapter      : started inbound.group-topic.Group-A
2021-01-31 10:59:11.298  INFO 27048 --- [           main] o.s.b.w.embedded.tomcat.TomcatWebServer  : Tomcat started on port(s): 63001 (http) with context path ''
2021-01-31 10:59:11.308  INFO 27048 --- [           main] com.imooc.springcloud.StreamApplication  : Started StreamApplication in 20.711 seconds (JVM running for 23.744)
2021-01-31 10:59:11.987  INFO 27048 --- [on(5)-127.0.0.1] o.a.c.c.C.[Tomcat].[localhost].[/]       : Initializing Spring DispatcherServlet 'dispatcherServlet'
2021-01-31 10:59:11.987  INFO 27048 --- [on(5)-127.0.0.1] o.s.web.servlet.DispatcherServlet        : Initializing Servlet 'dispatcherServlet'
2021-01-31 10:59:12.084  INFO 27048 --- [on(5)-127.0.0.1] o.s.web.servlet.DispatcherServlet        : Completed initialization in 97 ms
2021-01-31 11:00:39.995  INFO 27048 --- [topic.Group-A-1] c.imooc.springcloud.biz.StreamConsumer   : Group message consumed successfully，payload=Test


```

![](https://tcs.teambition.net/storage/3122b0909345766e80335187f91790bff76e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJiMDkwOTM0NTc2NmU4MDMzNTE4N2Y5MTc5MGJmZjc2ZSJ9.8Wbvw8rn0CRzG5aiu1NtmjnMVxOx5B-eioRsV2wh6J0&download=image.png "")

![](https://tcs.teambition.net/storage/3122dd276161d55dfa3b04b33b86fc8ccf00?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkZDI3NjE2MWQ1NWRmYTNiMDRiMzNiODZmYzhjY2YwMCJ9.b04Yv1srb-vLyc4NN8B4eQREGLEca9-3sTvNrxCHt1Q&download=image.png "")

```text
/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/bin/java -agentlib:jdwp=transport=dt_socket,address=127.0.0.1:59150,suspend=y,server=n -XX:TieredStopAtLevel=1 -noverify -Dspring.output.ansi.enabled=always -javaagent:/Users/virtualman/Library/Caches/JetBrains/IntelliJIdea2021.1/groovyHotSwap/gragent.jar -javaagent:/Users/virtualman/Library/Caches/JetBrains/IntelliJIdea2021.1/captureAgent/debugger-agent.jar -agentpath:/private/var/folders/f7/h5k23k254y14yl9frqxjmjzh0000gn/T/libmemory_agent.dylib= -Dcom.sun.management.jmxremote -Dspring.jmx.enabled=true -Dspring.liveBeansView.mbeanDomain -Dspring.application.admin.enabled=true -Dfile.encoding=UTF-8 -classpath /Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/charsets.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/deploy.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/ext/cldrdata.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/ext/dnsns.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/ext/jaccess.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/ext/jfxrt.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/ext/localedata.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/ext/nashorn.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/ext/sunec.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/ext/sunjce_provider.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/ext/sunpkcs11.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/ext/zipfs.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/javaws.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/jce.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/jfr.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/jfxswt.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/jsse.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/management-agent.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/plugin.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/resources.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/rt.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/lib/ant-javafx.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/lib/dt.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/lib/javafx-mx.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/lib/jconsole.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/lib/packager.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/lib/sa-jdi.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/lib/tools.jar:/Users/virtualman/IdeaProjects/java-for-linux/java-for-alibaba/spring-cloud-demo/stream/stream-sample/target/classes:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-starter-web/2.1.15.RELEASE/spring-boot-starter-web-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-starter/2.1.15.RELEASE/spring-boot-starter-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot/2.1.15.RELEASE/spring-boot-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-autoconfigure/2.1.15.RELEASE/spring-boot-autoconfigure-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-starter-logging/2.1.15.RELEASE/spring-boot-starter-logging-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/ch/qos/logback/logback-classic/1.2.3/logback-classic-1.2.3.jar:/Users/virtualman/.m2/repository/ch/qos/logback/logback-core/1.2.3/logback-core-1.2.3.jar:/Users/virtualman/.m2/repository/org/slf4j/slf4j-api/1.7.30/slf4j-api-1.7.30.jar:/Users/virtualman/.m2/repository/org/apache/logging/log4j/log4j-to-slf4j/2.11.2/log4j-to-slf4j-2.11.2.jar:/Users/virtualman/.m2/repository/org/apache/logging/log4j/log4j-api/2.11.2/log4j-api-2.11.2.jar:/Users/virtualman/.m2/repository/org/slf4j/jul-to-slf4j/1.7.30/jul-to-slf4j-1.7.30.jar:/Users/virtualman/.m2/repository/javax/annotation/javax.annotation-api/1.3.2/javax.annotation-api-1.3.2.jar:/Users/virtualman/.m2/repository/org/springframework/spring-core/5.1.16.RELEASE/spring-core-5.1.16.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/spring-jcl/5.1.16.RELEASE/spring-jcl-5.1.16.RELEASE.jar:/Users/virtualman/.m2/repository/org/yaml/snakeyaml/1.23/snakeyaml-1.23.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-starter-json/2.1.15.RELEASE/spring-boot-starter-json-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/com/fasterxml/jackson/core/jackson-databind/2.9.10.4/jackson-databind-2.9.10.4.jar:/Users/virtualman/.m2/repository/com/fasterxml/jackson/core/jackson-annotations/2.9.10/jackson-annotations-2.9.10.jar:/Users/virtualman/.m2/repository/com/fasterxml/jackson/core/jackson-core/2.9.10/jackson-core-2.9.10.jar:/Users/virtualman/.m2/repository/com/fasterxml/jackson/datatype/jackson-datatype-jdk8/2.9.10/jackson-datatype-jdk8-2.9.10.jar:/Users/virtualman/.m2/repository/com/fasterxml/jackson/datatype/jackson-datatype-jsr310/2.9.10/jackson-datatype-jsr310-2.9.10.jar:/Users/virtualman/.m2/repository/com/fasterxml/jackson/module/jackson-module-parameter-names/2.9.10/jackson-module-parameter-names-2.9.10.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-starter-tomcat/2.1.15.RELEASE/spring-boot-starter-tomcat-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/org/apache/tomcat/embed/tomcat-embed-core/9.0.36/tomcat-embed-core-9.0.36.jar:/Users/virtualman/.m2/repository/org/apache/tomcat/embed/tomcat-embed-el/9.0.36/tomcat-embed-el-9.0.36.jar:/Users/virtualman/.m2/repository/org/apache/tomcat/embed/tomcat-embed-websocket/9.0.36/tomcat-embed-websocket-9.0.36.jar:/Users/virtualman/.m2/repository/org/hibernate/validator/hibernate-validator/6.0.20.Final/hibernate-validator-6.0.20.Final.jar:/Users/virtualman/.m2/repository/javax/validation/validation-api/2.0.1.Final/validation-api-2.0.1.Final.jar:/Users/virtualman/.m2/repository/org/jboss/logging/jboss-logging/3.3.3.Final/jboss-logging-3.3.3.Final.jar:/Users/virtualman/.m2/repository/com/fasterxml/classmate/1.4.0/classmate-1.4.0.jar:/Users/virtualman/.m2/repository/org/springframework/spring-web/5.1.16.RELEASE/spring-web-5.1.16.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/spring-beans/5.1.16.RELEASE/spring-beans-5.1.16.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/spring-webmvc/5.1.16.RELEASE/spring-webmvc-5.1.16.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/spring-aop/5.1.16.RELEASE/spring-aop-5.1.16.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/spring-context/5.1.16.RELEASE/spring-context-5.1.16.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/spring-expression/5.1.16.RELEASE/spring-expression-5.1.16.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-starter-actuator/2.1.15.RELEASE/spring-boot-starter-actuator-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-actuator-autoconfigure/2.1.15.RELEASE/spring-boot-actuator-autoconfigure-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-actuator/2.1.15.RELEASE/spring-boot-actuator-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/io/micrometer/micrometer-core/1.1.14/micrometer-core-1.1.14.jar:/Users/virtualman/.m2/repository/org/hdrhistogram/HdrHistogram/2.1.9/HdrHistogram-2.1.9.jar:/Users/virtualman/.m2/repository/org/latencyutils/LatencyUtils/2.0.3/LatencyUtils-2.0.3.jar:/Users/virtualman/.m2/repository/org/springframework/cloud/spring-cloud-starter-stream-rabbit/2.1.2.RELEASE/spring-cloud-starter-stream-rabbit-2.1.2.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/cloud/spring-cloud-stream-binder-rabbit/2.1.2.RELEASE/spring-cloud-stream-binder-rabbit-2.1.2.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/cloud/spring-cloud-stream-binder-rabbit-core/2.1.2.RELEASE/spring-cloud-stream-binder-rabbit-core-2.1.2.RELEASE.jar:/Users/virtualman/.m2/repository/com/rabbitmq/http-client/2.1.0.RELEASE/http-client-2.1.0.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/cloud/spring-cloud-stream/2.1.2.RELEASE/spring-cloud-stream-2.1.2.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-starter-validation/2.1.15.RELEASE/spring-boot-starter-validation-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/spring-messaging/5.1.16.RELEASE/spring-messaging-5.1.16.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/spring-tuple/1.0.0.RELEASE/spring-tuple-1.0.0.RELEASE.jar:/Users/virtualman/.m2/repository/com/esotericsoftware/kryo-shaded/3.0.3/kryo-shaded-3.0.3.jar:/Users/virtualman/.m2/repository/com/esotericsoftware/minlog/1.3.0/minlog-1.3.0.jar:/Users/virtualman/.m2/repository/org/objenesis/objenesis/2.1/objenesis-2.1.jar:/Users/virtualman/.m2/repository/org/springframework/integration/spring-integration-tuple/1.0.0.RELEASE/spring-integration-tuple-1.0.0.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/retry/spring-retry/1.2.5.RELEASE/spring-retry-1.2.5.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/cloud/spring-cloud-function-context/2.0.1.RELEASE/spring-cloud-function-context-2.0.1.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/cloud/spring-cloud-function-core/2.0.1.RELEASE/spring-cloud-function-core-2.0.1.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-starter-amqp/2.1.15.RELEASE/spring-boot-starter-amqp-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/amqp/spring-rabbit/2.1.15.RELEASE/spring-rabbit-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/com/rabbitmq/amqp-client/5.4.3/amqp-client-5.4.3.jar:/Users/virtualman/.m2/repository/org/springframework/amqp/spring-amqp/2.1.15.RELEASE/spring-amqp-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/integration/spring-integration-amqp/5.1.11.RELEASE/spring-integration-amqp-5.1.11.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/integration/spring-integration-core/5.1.11.RELEASE/spring-integration-core-5.1.11.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/spring-tx/5.1.16.RELEASE/spring-tx-5.1.16.RELEASE.jar:/Users/virtualman/.m2/repository/io/projectreactor/reactor-core/3.2.18.RELEASE/reactor-core-3.2.18.RELEASE.jar:/Users/virtualman/.m2/repository/org/reactivestreams/reactive-streams/1.0.3/reactive-streams-1.0.3.jar:/Users/virtualman/.m2/repository/org/springframework/integration/spring-integration-jmx/5.1.11.RELEASE/spring-integration-jmx-5.1.11.RELEASE.jar:/Users/virtualman/.m2/repository/org/apache/httpcomponents/httpclient/4.5.12/httpclient-4.5.12.jar:/Users/virtualman/.m2/repository/org/apache/httpcomponents/httpcore/4.4.13/httpcore-4.4.13.jar:/Users/virtualman/.m2/repository/commons-codec/commons-codec/1.11/commons-codec-1.11.jar:/Users/virtualman/.m2/repository/org/projectlombok/lombok/1.18.8/lombok-1.18.8.jar:/Users/virtualman/Library/Application Support/JetBrains/Toolbox/apps/IDEA-U/ch-0/211.4961.33/IntelliJ IDEA 2021.1 EAP.app/Contents/lib/idea_rt.jar com.imooc.springcloud.StreamApplication
Connected to the target VM, address: '127.0.0.1:59150', transport: 'socket'

  .   ____          _            __ _ _
 /\\ / ___'_ __ _ _(_)_ __  __ _ \ \ \ \
( ( )\___ | '_ | '_| | '_ \/ _` | \ \ \ \
 \\/  ___)| |_)| | | | | || (_| |  ) ) ) )
  '  |____| .__|_| |_|_| |_\__, | / / / /
 =========|_|==============|___/=/_/_/_/
 :: Spring Boot ::       (v2.1.15.RELEASE)

2021-01-31 10:58:52.102  INFO 27048 --- [           main] com.imooc.springcloud.StreamApplication  : Starting StreamApplication on OpenDevel.local with PID 27048 (/Users/virtualman/IdeaProjects/java-for-linux/java-for-alibaba/spring-cloud-demo/stream/stream-sample/target/classes started by virtualman in /Users/virtualman/IdeaProjects/java-for-linux)
2021-01-31 10:58:52.113  INFO 27048 --- [           main] com.imooc.springcloud.StreamApplication  : No active profile set, falling back to default profiles: default
2021-01-31 10:58:57.928  INFO 27048 --- [           main] faultConfiguringBeanFactoryPostProcessor : No bean named 'errorChannel' has been explicitly defined. Therefore, a default PublishSubscribeChannel will be created.
2021-01-31 10:58:57.959  INFO 27048 --- [           main] faultConfiguringBeanFactoryPostProcessor : No bean named 'taskScheduler' has been explicitly defined. Therefore, a default ThreadPoolTaskScheduler will be created.
2021-01-31 10:58:57.982  INFO 27048 --- [           main] faultConfiguringBeanFactoryPostProcessor : No bean named 'integrationHeaderChannelRegistry' has been explicitly defined. Therefore, a default DefaultHeaderChannelRegistry will be created.
2021-01-31 10:58:58.162  INFO 27048 --- [           main] trationDelegate$BeanPostProcessorChecker : Bean 'integrationDisposableAutoCreatedBeans' of type [org.springframework.integration.config.annotation.Disposables] is not eligible for getting processed by all BeanPostProcessors (for example: not eligible for auto-proxying)
2021-01-31 10:58:58.204  INFO 27048 --- [           main] trationDelegate$BeanPostProcessorChecker : Bean 'org.springframework.integration.config.IntegrationManagementConfiguration' of type [org.springframework.integration.config.IntegrationManagementConfiguration$$EnhancerBySpringCGLIB$$ce1b208d] is not eligible for getting processed by all BeanPostProcessors (for example: not eligible for auto-proxying)
2021-01-31 10:58:58.241  INFO 27048 --- [           main] trationDelegate$BeanPostProcessorChecker : Bean 'org.springframework.boot.autoconfigure.integration.IntegrationAutoConfiguration$IntegrationJmxConfiguration' of type [org.springframework.boot.autoconfigure.integration.IntegrationAutoConfiguration$IntegrationJmxConfiguration$$EnhancerBySpringCGLIB$$a9ad2bad] is not eligible for getting processed by all BeanPostProcessors (for example: not eligible for auto-proxying)
2021-01-31 10:58:58.265  INFO 27048 --- [           main] trationDelegate$BeanPostProcessorChecker : Bean 'org.springframework.boot.autoconfigure.jmx.JmxAutoConfiguration' of type [org.springframework.boot.autoconfigure.jmx.JmxAutoConfiguration$$EnhancerBySpringCGLIB$$e294d47a] is not eligible for getting processed by all BeanPostProcessors (for example: not eligible for auto-proxying)
2021-01-31 10:58:58.275  INFO 27048 --- [           main] trationDelegate$BeanPostProcessorChecker : Bean 'mbeanServer' of type [com.sun.jmx.mbeanserver.JmxMBeanServer] is not eligible for getting processed by all BeanPostProcessors (for example: not eligible for auto-proxying)
2021-01-31 10:58:59.145  INFO 27048 --- [           main] o.s.b.w.embedded.tomcat.TomcatWebServer  : Tomcat initialized with port(s): 63001 (http)
2021-01-31 10:58:59.212  INFO 27048 --- [           main] o.apache.catalina.core.StandardService   : Starting service [Tomcat]
2021-01-31 10:58:59.213  INFO 27048 --- [           main] org.apache.catalina.core.StandardEngine  : Starting Servlet engine: [Apache Tomcat/9.0.36]
2021-01-31 10:58:59.402  INFO 27048 --- [           main] o.a.c.c.C.[Tomcat].[localhost].[/]       : Initializing Spring embedded WebApplicationContext
2021-01-31 10:58:59.402  INFO 27048 --- [           main] o.s.web.context.ContextLoader            : Root WebApplicationContext: initialization completed in 6955 ms
2021-01-31 10:59:01.214  INFO 27048 --- [           main] o.s.s.c.ThreadPoolTaskScheduler          : Initializing ExecutorService 'taskScheduler'
2021-01-31 10:59:02.436  INFO 27048 --- [           main] o.s.s.concurrent.ThreadPoolTaskExecutor  : Initializing ExecutorService 'applicationTaskExecutor'
2021-01-31 10:59:05.356  INFO 27048 --- [           main] o.s.b.a.e.web.EndpointLinksResolver      : Exposing 18 endpoint(s) beneath base path '/actuator'
2021-01-31 10:59:05.801  INFO 27048 --- [           main] o.s.c.s.m.DirectWithAttributesChannel    : Channel 'stream-sample.input' has 1 subscriber(s).
2021-01-31 10:59:05.802  INFO 27048 --- [           main] o.s.c.s.m.DirectWithAttributesChannel    : Channel 'stream-sample.myTopic-consumer' has 1 subscriber(s).
2021-01-31 10:59:05.802  INFO 27048 --- [           main] o.s.c.s.m.DirectWithAttributesChannel    : Channel 'stream-sample.group-consumer' has 1 subscriber(s).
2021-01-31 10:59:06.483  INFO 27048 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageChannel input
2021-01-31 10:59:06.717  INFO 27048 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageChannel myTopic-producer
2021-01-31 10:59:06.756  INFO 27048 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageChannel myTopic-consumer
2021-01-31 10:59:06.780  INFO 27048 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageChannel group-producer
2021-01-31 10:59:06.798  INFO 27048 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageChannel nullChannel
2021-01-31 10:59:06.858  INFO 27048 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageChannel errorChannel
2021-01-31 10:59:07.075  INFO 27048 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageChannel group-consumer
2021-01-31 10:59:07.104  INFO 27048 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageHandler org.springframework.cloud.stream.binding.StreamListenerMessageHandler@4b4a2fa8
2021-01-31 10:59:07.818  INFO 27048 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageHandler org.springframework.cloud.stream.binding.StreamListenerMessageHandler@179ee36b
2021-01-31 10:59:07.840  INFO 27048 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageHandler errorLogger
2021-01-31 10:59:07.916  INFO 27048 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageHandler org.springframework.cloud.stream.binding.StreamListenerMessageHandler@67763ebe
2021-01-31 10:59:08.112  INFO 27048 --- [           main] o.s.i.endpoint.EventDrivenConsumer       : Adding {logging-channel-adapter:_org.springframework.integration.errorLogger} as a subscriber to the 'errorChannel' channel
2021-01-31 10:59:08.112  INFO 27048 --- [           main] o.s.i.channel.PublishSubscribeChannel    : Channel 'stream-sample.errorChannel' has 1 subscriber(s).
2021-01-31 10:59:08.112  INFO 27048 --- [           main] o.s.i.endpoint.EventDrivenConsumer       : started _org.springframework.integration.errorLogger
2021-01-31 10:59:09.344  INFO 27048 --- [           main] o.s.a.r.c.CachingConnectionFactory       : Attempting to connect to: [localhost:5672]
2021-01-31 10:59:09.468  INFO 27048 --- [           main] o.s.a.r.c.CachingConnectionFactory       : Created new connection: rabbitConnectionFactory#6411504a:0/SimpleConnection@1736c1e4 [delegate=amqp://guest@127.0.0.1:5672/, localPort= 59166]
2021-01-31 10:59:09.659  INFO 27048 --- [           main] o.s.c.s.m.DirectWithAttributesChannel    : Channel 'stream-sample.myTopic-producer' has 1 subscriber(s).
2021-01-31 10:59:09.740  INFO 27048 --- [           main] o.s.c.s.m.DirectWithAttributesChannel    : Channel 'stream-sample.group-producer' has 1 subscriber(s).
2021-01-31 10:59:09.846  INFO 27048 --- [           main] c.s.b.r.p.RabbitExchangeQueueProvisioner : declaring queue for inbound: input.anonymous.zUqGLHnUQKiichN6Vt5q7Q, bound to: input
2021-01-31 10:59:09.934  INFO 27048 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageChannel input.anonymous.zUqGLHnUQKiichN6Vt5q7Q.errors
2021-01-31 10:59:10.589  INFO 27048 --- [           main] o.s.c.stream.binder.BinderErrorChannel   : Channel 'stream-sample.input.anonymous.zUqGLHnUQKiichN6Vt5q7Q.errors' has 1 subscriber(s).
2021-01-31 10:59:10.591  INFO 27048 --- [           main] o.s.c.stream.binder.BinderErrorChannel   : Channel 'stream-sample.input.anonymous.zUqGLHnUQKiichN6Vt5q7Q.errors' has 2 subscriber(s).
2021-01-31 10:59:10.637  INFO 27048 --- [           main] o.s.i.a.i.AmqpInboundChannelAdapter      : started inbound.input.anonymous.zUqGLHnUQKiichN6Vt5q7Q
2021-01-31 10:59:10.680  INFO 27048 --- [           main] c.s.b.r.p.RabbitExchangeQueueProvisioner : declaring queue for inbound: broadcast.anonymous.TZxUuOi0ThCHFyrft6SMYQ, bound to: broadcast
2021-01-31 10:59:10.698  INFO 27048 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageChannel broadcast.anonymous.TZxUuOi0ThCHFyrft6SMYQ.errors
2021-01-31 10:59:10.718  INFO 27048 --- [           main] o.s.c.stream.binder.BinderErrorChannel   : Channel 'stream-sample.broadcast.anonymous.TZxUuOi0ThCHFyrft6SMYQ.errors' has 1 subscriber(s).
2021-01-31 10:59:10.719  INFO 27048 --- [           main] o.s.c.stream.binder.BinderErrorChannel   : Channel 'stream-sample.broadcast.anonymous.TZxUuOi0ThCHFyrft6SMYQ.errors' has 2 subscriber(s).
2021-01-31 10:59:10.726  INFO 27048 --- [           main] o.s.i.a.i.AmqpInboundChannelAdapter      : started inbound.broadcast.anonymous.TZxUuOi0ThCHFyrft6SMYQ
2021-01-31 10:59:10.772  INFO 27048 --- [           main] c.s.b.r.p.RabbitExchangeQueueProvisioner : declaring queue for inbound: group-topic.Group-A, bound to: group-topic
2021-01-31 10:59:10.859  INFO 27048 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageChannel group-topic.Group-A.errors
2021-01-31 10:59:10.930  INFO 27048 --- [           main] o.s.c.stream.binder.BinderErrorChannel   : Channel 'stream-sample.group-topic.Group-A.errors' has 1 subscriber(s).
2021-01-31 10:59:10.931  INFO 27048 --- [           main] o.s.c.stream.binder.BinderErrorChannel   : Channel 'stream-sample.group-topic.Group-A.errors' has 2 subscriber(s).
2021-01-31 10:59:10.947  INFO 27048 --- [           main] o.s.i.a.i.AmqpInboundChannelAdapter      : started inbound.group-topic.Group-A
2021-01-31 10:59:11.298  INFO 27048 --- [           main] o.s.b.w.embedded.tomcat.TomcatWebServer  : Tomcat started on port(s): 63001 (http) with context path ''
2021-01-31 10:59:11.308  INFO 27048 --- [           main] com.imooc.springcloud.StreamApplication  : Started StreamApplication in 20.711 seconds (JVM running for 23.744)
2021-01-31 10:59:11.987  INFO 27048 --- [on(5)-127.0.0.1] o.a.c.c.C.[Tomcat].[localhost].[/]       : Initializing Spring DispatcherServlet 'dispatcherServlet'
2021-01-31 10:59:11.987  INFO 27048 --- [on(5)-127.0.0.1] o.s.web.servlet.DispatcherServlet        : Initializing Servlet 'dispatcherServlet'
2021-01-31 10:59:12.084  INFO 27048 --- [on(5)-127.0.0.1] o.s.web.servlet.DispatcherServlet        : Completed initialization in 97 ms
2021-01-31 11:00:39.995  INFO 27048 --- [topic.Group-A-1] c.imooc.springcloud.biz.StreamConsumer   : Group message consumed successfully，payload=Test


```

另外一个consumer被消费

![](https://tcs.teambition.net/storage/3122aedc26595a75f1a041f502a1e3ece8dc?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhZWRjMjY1OTVhNzVmMWEwNDFmNTAyYTFlM2VjZThkYyJ9.fqTrN9nh4B0lO5hjOjbU-WxeunN1qslPpViyX1nII4U&download=image.png "")

```text
/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/bin/java -agentlib:jdwp=transport=dt_socket,address=127.0.0.1:59176,suspend=y,server=n -XX:TieredStopAtLevel=1 -noverify -Dspring.output.ansi.enabled=always -javaagent:/Users/virtualman/Library/Caches/JetBrains/IntelliJIdea2021.1/groovyHotSwap/gragent.jar -javaagent:/Users/virtualman/Library/Caches/JetBrains/IntelliJIdea2021.1/captureAgent/debugger-agent.jar -agentpath:/private/var/folders/f7/h5k23k254y14yl9frqxjmjzh0000gn/T/libmemory_agent.dylib= -Dcom.sun.management.jmxremote -Dspring.jmx.enabled=true -Dspring.liveBeansView.mbeanDomain -Dspring.application.admin.enabled=true -Dfile.encoding=UTF-8 -classpath /Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/charsets.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/deploy.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/ext/cldrdata.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/ext/dnsns.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/ext/jaccess.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/ext/jfxrt.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/ext/localedata.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/ext/nashorn.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/ext/sunec.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/ext/sunjce_provider.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/ext/sunpkcs11.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/ext/zipfs.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/javaws.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/jce.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/jfr.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/jfxswt.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/jsse.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/management-agent.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/plugin.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/resources.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/jre/lib/rt.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/lib/ant-javafx.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/lib/dt.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/lib/javafx-mx.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/lib/jconsole.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/lib/packager.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/lib/sa-jdi.jar:/Users/virtualman/Downloads/temp/jdk1.8.0_181.jdk/Contents/Home/lib/tools.jar:/Users/virtualman/IdeaProjects/java-for-linux/java-for-alibaba/spring-cloud-demo/stream/stream-sample/target/classes:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-starter-web/2.1.15.RELEASE/spring-boot-starter-web-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-starter/2.1.15.RELEASE/spring-boot-starter-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot/2.1.15.RELEASE/spring-boot-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-autoconfigure/2.1.15.RELEASE/spring-boot-autoconfigure-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-starter-logging/2.1.15.RELEASE/spring-boot-starter-logging-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/ch/qos/logback/logback-classic/1.2.3/logback-classic-1.2.3.jar:/Users/virtualman/.m2/repository/ch/qos/logback/logback-core/1.2.3/logback-core-1.2.3.jar:/Users/virtualman/.m2/repository/org/slf4j/slf4j-api/1.7.30/slf4j-api-1.7.30.jar:/Users/virtualman/.m2/repository/org/apache/logging/log4j/log4j-to-slf4j/2.11.2/log4j-to-slf4j-2.11.2.jar:/Users/virtualman/.m2/repository/org/apache/logging/log4j/log4j-api/2.11.2/log4j-api-2.11.2.jar:/Users/virtualman/.m2/repository/org/slf4j/jul-to-slf4j/1.7.30/jul-to-slf4j-1.7.30.jar:/Users/virtualman/.m2/repository/javax/annotation/javax.annotation-api/1.3.2/javax.annotation-api-1.3.2.jar:/Users/virtualman/.m2/repository/org/springframework/spring-core/5.1.16.RELEASE/spring-core-5.1.16.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/spring-jcl/5.1.16.RELEASE/spring-jcl-5.1.16.RELEASE.jar:/Users/virtualman/.m2/repository/org/yaml/snakeyaml/1.23/snakeyaml-1.23.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-starter-json/2.1.15.RELEASE/spring-boot-starter-json-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/com/fasterxml/jackson/core/jackson-databind/2.9.10.4/jackson-databind-2.9.10.4.jar:/Users/virtualman/.m2/repository/com/fasterxml/jackson/core/jackson-annotations/2.9.10/jackson-annotations-2.9.10.jar:/Users/virtualman/.m2/repository/com/fasterxml/jackson/core/jackson-core/2.9.10/jackson-core-2.9.10.jar:/Users/virtualman/.m2/repository/com/fasterxml/jackson/datatype/jackson-datatype-jdk8/2.9.10/jackson-datatype-jdk8-2.9.10.jar:/Users/virtualman/.m2/repository/com/fasterxml/jackson/datatype/jackson-datatype-jsr310/2.9.10/jackson-datatype-jsr310-2.9.10.jar:/Users/virtualman/.m2/repository/com/fasterxml/jackson/module/jackson-module-parameter-names/2.9.10/jackson-module-parameter-names-2.9.10.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-starter-tomcat/2.1.15.RELEASE/spring-boot-starter-tomcat-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/org/apache/tomcat/embed/tomcat-embed-core/9.0.36/tomcat-embed-core-9.0.36.jar:/Users/virtualman/.m2/repository/org/apache/tomcat/embed/tomcat-embed-el/9.0.36/tomcat-embed-el-9.0.36.jar:/Users/virtualman/.m2/repository/org/apache/tomcat/embed/tomcat-embed-websocket/9.0.36/tomcat-embed-websocket-9.0.36.jar:/Users/virtualman/.m2/repository/org/hibernate/validator/hibernate-validator/6.0.20.Final/hibernate-validator-6.0.20.Final.jar:/Users/virtualman/.m2/repository/javax/validation/validation-api/2.0.1.Final/validation-api-2.0.1.Final.jar:/Users/virtualman/.m2/repository/org/jboss/logging/jboss-logging/3.3.3.Final/jboss-logging-3.3.3.Final.jar:/Users/virtualman/.m2/repository/com/fasterxml/classmate/1.4.0/classmate-1.4.0.jar:/Users/virtualman/.m2/repository/org/springframework/spring-web/5.1.16.RELEASE/spring-web-5.1.16.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/spring-beans/5.1.16.RELEASE/spring-beans-5.1.16.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/spring-webmvc/5.1.16.RELEASE/spring-webmvc-5.1.16.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/spring-aop/5.1.16.RELEASE/spring-aop-5.1.16.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/spring-context/5.1.16.RELEASE/spring-context-5.1.16.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/spring-expression/5.1.16.RELEASE/spring-expression-5.1.16.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-starter-actuator/2.1.15.RELEASE/spring-boot-starter-actuator-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-actuator-autoconfigure/2.1.15.RELEASE/spring-boot-actuator-autoconfigure-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-actuator/2.1.15.RELEASE/spring-boot-actuator-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/io/micrometer/micrometer-core/1.1.14/micrometer-core-1.1.14.jar:/Users/virtualman/.m2/repository/org/hdrhistogram/HdrHistogram/2.1.9/HdrHistogram-2.1.9.jar:/Users/virtualman/.m2/repository/org/latencyutils/LatencyUtils/2.0.3/LatencyUtils-2.0.3.jar:/Users/virtualman/.m2/repository/org/springframework/cloud/spring-cloud-starter-stream-rabbit/2.1.2.RELEASE/spring-cloud-starter-stream-rabbit-2.1.2.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/cloud/spring-cloud-stream-binder-rabbit/2.1.2.RELEASE/spring-cloud-stream-binder-rabbit-2.1.2.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/cloud/spring-cloud-stream-binder-rabbit-core/2.1.2.RELEASE/spring-cloud-stream-binder-rabbit-core-2.1.2.RELEASE.jar:/Users/virtualman/.m2/repository/com/rabbitmq/http-client/2.1.0.RELEASE/http-client-2.1.0.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/cloud/spring-cloud-stream/2.1.2.RELEASE/spring-cloud-stream-2.1.2.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-starter-validation/2.1.15.RELEASE/spring-boot-starter-validation-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/spring-messaging/5.1.16.RELEASE/spring-messaging-5.1.16.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/spring-tuple/1.0.0.RELEASE/spring-tuple-1.0.0.RELEASE.jar:/Users/virtualman/.m2/repository/com/esotericsoftware/kryo-shaded/3.0.3/kryo-shaded-3.0.3.jar:/Users/virtualman/.m2/repository/com/esotericsoftware/minlog/1.3.0/minlog-1.3.0.jar:/Users/virtualman/.m2/repository/org/objenesis/objenesis/2.1/objenesis-2.1.jar:/Users/virtualman/.m2/repository/org/springframework/integration/spring-integration-tuple/1.0.0.RELEASE/spring-integration-tuple-1.0.0.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/retry/spring-retry/1.2.5.RELEASE/spring-retry-1.2.5.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/cloud/spring-cloud-function-context/2.0.1.RELEASE/spring-cloud-function-context-2.0.1.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/cloud/spring-cloud-function-core/2.0.1.RELEASE/spring-cloud-function-core-2.0.1.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/boot/spring-boot-starter-amqp/2.1.15.RELEASE/spring-boot-starter-amqp-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/amqp/spring-rabbit/2.1.15.RELEASE/spring-rabbit-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/com/rabbitmq/amqp-client/5.4.3/amqp-client-5.4.3.jar:/Users/virtualman/.m2/repository/org/springframework/amqp/spring-amqp/2.1.15.RELEASE/spring-amqp-2.1.15.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/integration/spring-integration-amqp/5.1.11.RELEASE/spring-integration-amqp-5.1.11.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/integration/spring-integration-core/5.1.11.RELEASE/spring-integration-core-5.1.11.RELEASE.jar:/Users/virtualman/.m2/repository/org/springframework/spring-tx/5.1.16.RELEASE/spring-tx-5.1.16.RELEASE.jar:/Users/virtualman/.m2/repository/io/projectreactor/reactor-core/3.2.18.RELEASE/reactor-core-3.2.18.RELEASE.jar:/Users/virtualman/.m2/repository/org/reactivestreams/reactive-streams/1.0.3/reactive-streams-1.0.3.jar:/Users/virtualman/.m2/repository/org/springframework/integration/spring-integration-jmx/5.1.11.RELEASE/spring-integration-jmx-5.1.11.RELEASE.jar:/Users/virtualman/.m2/repository/org/apache/httpcomponents/httpclient/4.5.12/httpclient-4.5.12.jar:/Users/virtualman/.m2/repository/org/apache/httpcomponents/httpcore/4.4.13/httpcore-4.4.13.jar:/Users/virtualman/.m2/repository/commons-codec/commons-codec/1.11/commons-codec-1.11.jar:/Users/virtualman/.m2/repository/org/projectlombok/lombok/1.18.8/lombok-1.18.8.jar:/Users/virtualman/Library/Application Support/JetBrains/Toolbox/apps/IDEA-U/ch-0/211.4961.33/IntelliJ IDEA 2021.1 EAP.app/Contents/lib/idea_rt.jar com.imooc.springcloud.StreamApplication
Connected to the target VM, address: '127.0.0.1:59176', transport: 'socket'

  .   ____          _            __ _ _
 /\\ / ___'_ __ _ _(_)_ __  __ _ \ \ \ \
( ( )\___ | '_ | '_| | '_ \/ _` | \ \ \ \
 \\/  ___)| |_)| | | | | || (_| |  ) ) ) )
  '  |____| .__|_| |_|_| |_\__, | / / / /
 =========|_|==============|___/=/_/_/_/
 :: Spring Boot ::       (v2.1.15.RELEASE)

2021-01-31 10:59:39.950  INFO 27224 --- [           main] com.imooc.springcloud.StreamApplication  : Starting StreamApplication on OpenDevel.local with PID 27224 (/Users/virtualman/IdeaProjects/java-for-linux/java-for-alibaba/spring-cloud-demo/stream/stream-sample/target/classes started by virtualman in /Users/virtualman/IdeaProjects/java-for-linux)
2021-01-31 10:59:40.005  INFO 27224 --- [           main] com.imooc.springcloud.StreamApplication  : No active profile set, falling back to default profiles: default
2021-01-31 10:59:47.993  INFO 27224 --- [           main] faultConfiguringBeanFactoryPostProcessor : No bean named 'errorChannel' has been explicitly defined. Therefore, a default PublishSubscribeChannel will be created.
2021-01-31 10:59:48.009  INFO 27224 --- [           main] faultConfiguringBeanFactoryPostProcessor : No bean named 'taskScheduler' has been explicitly defined. Therefore, a default ThreadPoolTaskScheduler will be created.
2021-01-31 10:59:48.028  INFO 27224 --- [           main] faultConfiguringBeanFactoryPostProcessor : No bean named 'integrationHeaderChannelRegistry' has been explicitly defined. Therefore, a default DefaultHeaderChannelRegistry will be created.
2021-01-31 10:59:48.174  INFO 27224 --- [           main] trationDelegate$BeanPostProcessorChecker : Bean 'integrationDisposableAutoCreatedBeans' of type [org.springframework.integration.config.annotation.Disposables] is not eligible for getting processed by all BeanPostProcessors (for example: not eligible for auto-proxying)
2021-01-31 10:59:48.244  INFO 27224 --- [           main] trationDelegate$BeanPostProcessorChecker : Bean 'org.springframework.integration.config.IntegrationManagementConfiguration' of type [org.springframework.integration.config.IntegrationManagementConfiguration$$EnhancerBySpringCGLIB$$8f755ed1] is not eligible for getting processed by all BeanPostProcessors (for example: not eligible for auto-proxying)
2021-01-31 10:59:48.288  INFO 27224 --- [           main] trationDelegate$BeanPostProcessorChecker : Bean 'org.springframework.boot.autoconfigure.integration.IntegrationAutoConfiguration$IntegrationJmxConfiguration' of type [org.springframework.boot.autoconfigure.integration.IntegrationAutoConfiguration$IntegrationJmxConfiguration$$EnhancerBySpringCGLIB$$6b0769f1] is not eligible for getting processed by all BeanPostProcessors (for example: not eligible for auto-proxying)
2021-01-31 10:59:48.311  INFO 27224 --- [           main] trationDelegate$BeanPostProcessorChecker : Bean 'org.springframework.boot.autoconfigure.jmx.JmxAutoConfiguration' of type [org.springframework.boot.autoconfigure.jmx.JmxAutoConfiguration$$EnhancerBySpringCGLIB$$a3ef12be] is not eligible for getting processed by all BeanPostProcessors (for example: not eligible for auto-proxying)
2021-01-31 10:59:48.327  INFO 27224 --- [           main] trationDelegate$BeanPostProcessorChecker : Bean 'mbeanServer' of type [com.sun.jmx.mbeanserver.JmxMBeanServer] is not eligible for getting processed by all BeanPostProcessors (for example: not eligible for auto-proxying)
2021-01-31 10:59:49.896  INFO 27224 --- [           main] o.s.b.w.embedded.tomcat.TomcatWebServer  : Tomcat initialized with port(s): 63000 (http)
2021-01-31 10:59:49.991  INFO 27224 --- [           main] o.apache.catalina.core.StandardService   : Starting service [Tomcat]
2021-01-31 10:59:49.992  INFO 27224 --- [           main] org.apache.catalina.core.StandardEngine  : Starting Servlet engine: [Apache Tomcat/9.0.36]
2021-01-31 10:59:50.354  INFO 27224 --- [           main] o.a.c.c.C.[Tomcat].[localhost].[/]       : Initializing Spring embedded WebApplicationContext
2021-01-31 10:59:50.354  INFO 27224 --- [           main] o.s.web.context.ContextLoader            : Root WebApplicationContext: initialization completed in 10074 ms
2021-01-31 10:59:52.441  INFO 27224 --- [           main] o.s.s.c.ThreadPoolTaskScheduler          : Initializing ExecutorService 'taskScheduler'
2021-01-31 10:59:54.399  INFO 27224 --- [           main] o.s.s.concurrent.ThreadPoolTaskExecutor  : Initializing ExecutorService 'applicationTaskExecutor'
2021-01-31 10:59:58.194  INFO 27224 --- [           main] o.s.b.a.e.web.EndpointLinksResolver      : Exposing 18 endpoint(s) beneath base path '/actuator'
2021-01-31 10:59:58.675  INFO 27224 --- [           main] o.s.c.s.m.DirectWithAttributesChannel    : Channel 'stream-sample.group-consumer' has 1 subscriber(s).
2021-01-31 10:59:58.676  INFO 27224 --- [           main] o.s.c.s.m.DirectWithAttributesChannel    : Channel 'stream-sample.input' has 1 subscriber(s).
2021-01-31 10:59:58.677  INFO 27224 --- [           main] o.s.c.s.m.DirectWithAttributesChannel    : Channel 'stream-sample.myTopic-consumer' has 1 subscriber(s).
2021-01-31 10:59:59.360  INFO 27224 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageChannel myTopic-producer
2021-01-31 10:59:59.896  INFO 27224 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageChannel group-consumer
2021-01-31 10:59:59.938  INFO 27224 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageChannel myTopic-consumer
2021-01-31 10:59:59.975  INFO 27224 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageChannel nullChannel
2021-01-31 11:00:00.027  INFO 27224 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageChannel errorChannel
2021-01-31 11:00:00.186  INFO 27224 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageChannel group-producer
2021-01-31 11:00:00.275  INFO 27224 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageChannel input
2021-01-31 11:00:00.302  INFO 27224 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageHandler errorLogger
2021-01-31 11:00:00.346  INFO 27224 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageHandler org.springframework.cloud.stream.binding.StreamListenerMessageHandler@78d92eef
2021-01-31 11:00:00.771  INFO 27224 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageHandler org.springframework.cloud.stream.binding.StreamListenerMessageHandler@6e95973c
2021-01-31 11:00:00.814  INFO 27224 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageHandler org.springframework.cloud.stream.binding.StreamListenerMessageHandler@61d60e38
2021-01-31 11:00:00.960  INFO 27224 --- [           main] o.s.i.endpoint.EventDrivenConsumer       : Adding {logging-channel-adapter:_org.springframework.integration.errorLogger} as a subscriber to the 'errorChannel' channel
2021-01-31 11:00:00.967  INFO 27224 --- [           main] o.s.i.channel.PublishSubscribeChannel    : Channel 'stream-sample.errorChannel' has 1 subscriber(s).
2021-01-31 11:00:00.968  INFO 27224 --- [           main] o.s.i.endpoint.EventDrivenConsumer       : started _org.springframework.integration.errorLogger
2021-01-31 11:00:01.590  INFO 27224 --- [           main] o.s.a.r.c.CachingConnectionFactory       : Attempting to connect to: [localhost:5672]
2021-01-31 11:00:01.700  INFO 27224 --- [           main] o.s.a.r.c.CachingConnectionFactory       : Created new connection: rabbitConnectionFactory#889a8a8:0/SimpleConnection@3babcaed [delegate=amqp://guest@127.0.0.1:5672/, localPort= 59188]
2021-01-31 11:00:01.887  INFO 27224 --- [           main] o.s.c.s.m.DirectWithAttributesChannel    : Channel 'stream-sample.myTopic-producer' has 1 subscriber(s).
2021-01-31 11:00:01.918  INFO 27224 --- [           main] o.s.c.s.m.DirectWithAttributesChannel    : Channel 'stream-sample.group-producer' has 1 subscriber(s).
2021-01-31 11:00:01.962  INFO 27224 --- [           main] c.s.b.r.p.RabbitExchangeQueueProvisioner : declaring queue for inbound: input.anonymous.GdM59hpIQZO1q3ill9saiw, bound to: input
2021-01-31 11:00:02.007  INFO 27224 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageChannel input.anonymous.GdM59hpIQZO1q3ill9saiw.errors
2021-01-31 11:00:02.356  INFO 27224 --- [           main] o.s.c.stream.binder.BinderErrorChannel   : Channel 'stream-sample.input.anonymous.GdM59hpIQZO1q3ill9saiw.errors' has 1 subscriber(s).
2021-01-31 11:00:02.358  INFO 27224 --- [           main] o.s.c.stream.binder.BinderErrorChannel   : Channel 'stream-sample.input.anonymous.GdM59hpIQZO1q3ill9saiw.errors' has 2 subscriber(s).
2021-01-31 11:00:02.404  INFO 27224 --- [           main] o.s.i.a.i.AmqpInboundChannelAdapter      : started inbound.input.anonymous.GdM59hpIQZO1q3ill9saiw
2021-01-31 11:00:02.427  INFO 27224 --- [           main] c.s.b.r.p.RabbitExchangeQueueProvisioner : declaring queue for inbound: broadcast.anonymous.aS62IIqERpiSa8R2gwkhkg, bound to: broadcast
2021-01-31 11:00:02.438  INFO 27224 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageChannel broadcast.anonymous.aS62IIqERpiSa8R2gwkhkg.errors
2021-01-31 11:00:02.479  INFO 27224 --- [           main] o.s.c.stream.binder.BinderErrorChannel   : Channel 'stream-sample.broadcast.anonymous.aS62IIqERpiSa8R2gwkhkg.errors' has 1 subscriber(s).
2021-01-31 11:00:02.479  INFO 27224 --- [           main] o.s.c.stream.binder.BinderErrorChannel   : Channel 'stream-sample.broadcast.anonymous.aS62IIqERpiSa8R2gwkhkg.errors' has 2 subscriber(s).
2021-01-31 11:00:02.549  INFO 27224 --- [           main] o.s.i.a.i.AmqpInboundChannelAdapter      : started inbound.broadcast.anonymous.aS62IIqERpiSa8R2gwkhkg
2021-01-31 11:00:02.629  INFO 27224 --- [           main] c.s.b.r.p.RabbitExchangeQueueProvisioner : declaring queue for inbound: group-topic.Group-A, bound to: group-topic
2021-01-31 11:00:02.664  INFO 27224 --- [           main] o.s.i.monitor.IntegrationMBeanExporter   : Registering MessageChannel group-topic.Group-A.errors
2021-01-31 11:00:02.693  INFO 27224 --- [           main] o.s.c.stream.binder.BinderErrorChannel   : Channel 'stream-sample.group-topic.Group-A.errors' has 1 subscriber(s).
2021-01-31 11:00:02.694  INFO 27224 --- [           main] o.s.c.stream.binder.BinderErrorChannel   : Channel 'stream-sample.group-topic.Group-A.errors' has 2 subscriber(s).
2021-01-31 11:00:02.700  INFO 27224 --- [           main] o.s.i.a.i.AmqpInboundChannelAdapter      : started inbound.group-topic.Group-A
2021-01-31 11:00:03.054  INFO 27224 --- [           main] o.s.b.w.embedded.tomcat.TomcatWebServer  : Tomcat started on port(s): 63000 (http) with context path ''
2021-01-31 11:00:03.064  INFO 27224 --- [           main] com.imooc.springcloud.StreamApplication  : Started StreamApplication in 25.677 seconds (JVM running for 29.847)
2021-01-31 11:00:03.655  INFO 27224 --- [on(4)-127.0.0.1] o.a.c.c.C.[Tomcat].[localhost].[/]       : Initializing Spring DispatcherServlet 'dispatcherServlet'
2021-01-31 11:00:03.655  INFO 27224 --- [on(4)-127.0.0.1] o.s.web.servlet.DispatcherServlet        : Initializing Servlet 'dispatcherServlet'
2021-01-31 11:00:03.674  INFO 27224 --- [on(4)-127.0.0.1] o.s.web.servlet.DispatcherServlet        : Completed initialization in 19 ms
2021-01-31 11:00:39.886  INFO 27224 --- [io-63000-exec-1] o.s.a.r.c.CachingConnectionFactory       : Attempting to connect to: [localhost:5672]
2021-01-31 11:00:39.901  INFO 27224 --- [io-63000-exec-1] o.s.a.r.c.CachingConnectionFactory       : Created new connection: rabbitConnectionFactory.publisher#580ec34a:0/SimpleConnection@73a29beb [delegate=amqp://guest@127.0.0.1:5672/, localPort= 59197]
2021-01-31 11:00:39.906  INFO 27224 --- [io-63000-exec-1] o.s.amqp.rabbit.core.RabbitAdmin         : Auto-declaring a non-durable, auto-delete, or exclusive Queue (input.anonymous.GdM59hpIQZO1q3ill9saiw) durable:false, auto-delete:true, exclusive:true. It will be redeclared if the broker stops and is restarted while the connection factory is alive, but all messages will be lost.
2021-01-31 11:00:39.907  INFO 27224 --- [io-63000-exec-1] o.s.amqp.rabbit.core.RabbitAdmin         : Auto-declaring a non-durable, auto-delete, or exclusive Queue (broadcast.anonymous.aS62IIqERpiSa8R2gwkhkg) durable:false, auto-delete:true, exclusive:true. It will be redeclared if the broker stops and is restarted while the connection factory is alive, but all messages will be lost.
2021-01-31 11:04:47.191  INFO 27224 --- [topic.Group-A-1] c.imooc.springcloud.biz.StreamConsumer   : Group message consumed successfully，payload=Test


```

![](https://tcs.teambition.net/storage/31223787f866a4cefe0861bc6ace0e73a257?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzNzg3Zjg2NmE0Y2VmZTA4NjFiYzZhY2UwZTczYTI1NyJ9.mEKrpofKAOZKr8Ipaz7L7N3W0o5FryQW1JVPicoRuSk&download=image.png "")

![](https://tcs.teambition.net/storage/3122ae7377f994c25665c323111456e36c97?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhZTczNzdmOTk0YzI1NjY1YzMyMzExMTQ1NmUzNmM5NyJ9.Mah2kzIBj4V19o0YlQya0GgMOF5_JddiTKG6dBzErNI&download=image.png "")

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
spring.cloud.stream.bindings.group-consumer.group=Group-B


management.endpoints.web.exposure.include=*
management.endpoint.health.show-details=always

```

启动

![](https://tcs.teambition.net/storage/312248013669208e6bb00277a213815d350d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI0ODAxMzY2OTIwOGU2YmIwMDI3N2EyMTM4MTVkMzUwZCJ9.LSi5eORzksqqSy5a3w6GK8z8TJNzt-dt8m2qfXInSsU&download=image.png "")

![](https://tcs.teambition.net/storage/3122fdd9313a2b20a4c417fa97bd7a9181f1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJmZGQ5MzEzYTJiMjBhNGM0MTdmYTk3YmQ3YTkxODFmMSJ9.Og_AyUTU53IGmqvgXxrh3wjOXVsoL89aDl-rqwW1AGU&download=image.png "")

![](https://tcs.teambition.net/storage/3122cb86cc1df5d70e94ba75a64a334292bf?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJjYjg2Y2MxZGY1ZDcwZTk0YmE3NWE2NGEzMzQyOTJiZiJ9.qCm9G27R4nX7rroO4y6ejbmGwjXnDHkMWW4pSF8i2Vg&download=image.png "")

```text
2021-01-31 11:09:28.022  INFO 30008 --- [topic.Group-B-1] c.imooc.springcloud.biz.StreamConsumer   : Group message consumed successfully，payload=Test


```

![](https://tcs.teambition.net/storage/3122e2217fe76387e09f78de9a0bc4bbcd8d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJlMjIxN2ZlNzYzODdlMDlmNzhkZTlhMGJjNGJiY2Q4ZCJ9.o4EkgmZQGWV8fbPPqyDHF4dpqPL3nVwVLUP_OCkjGUc&download=image.png "")

```text
2021-01-31 11:09:27.941  INFO 27048 --- [topic.Group-A-1] c.imooc.springcloud.biz.StreamConsumer   : Group message consumed successfully，payload=Test


```

![](https://tcs.teambition.net/storage/3122171164273719482f4089b6f7e816159b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxNzExNjQyNzM3MTk0ODJmNDA4OWI2ZjdlODE2MTU5YiJ9.eb54vM2vOOJL9JbjCwH54-tobY4z_FbPZt9IbJz6L6Q&download=image.png "")

![](https://tcs.teambition.net/storage/3122d2ca94ebfa1dec8fc61ca2e5b56c3e66?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkMmNhOTRlYmZhMWRlYzhmYzYxY2EyZTViNTZjM2U2NiJ9.iPqpBzEFB9C_G0ydK9lZXph2eDPRi_-YPxgtlS8n4uc&download=image.png "")

```text
spring.application.name=stream-sample
#server.port=63001
server.port=63000
#server.port=63002

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
spring.cloud.stream.bindings.group-consumer.group=Group-B

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
spring.cloud.stream.instanceIndex=0

management.endpoints.web.exposure.include=*
management.endpoint.health.show-details=always
```

![](https://tcs.teambition.net/storage/3122cce994430e783b114a1cf4ba60ae089f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJjY2U5OTQ0MzBlNzgzYjExNGExY2Y0YmE2MGFlMDg5ZiJ9.zMgL-kJWOM0Z24Uvrj4Jkze0UF2MPIMK63LOZVyBCws&download=image.png "")

![](https://tcs.teambition.net/storage/312216eee6aca26d8114df764374e87132d1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxNmVlZTZhY2EyNmQ4MTE0ZGY3NjQzNzRlODcxMzJkMSJ9.9dj1195ChKtoG5xSdM7xM2zjDqCOjiQ1FTj0Q3I_8E4&download=image.png "")

![](https://tcs.teambition.net/storage/3122187a0754e9ab3c410aa7f56bb4c53781?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxODdhMDc1NGU5YWIzYzQxMGFhN2Y1NmJiNGM1Mzc4MSJ9.K8LboKSmxeWugKOXzLSURufVbBd1sGUbHCj0zyj5aWM&download=image.png "")

![](https://tcs.teambition.net/storage/3122918e32bff6e9afe497ea1381e79f0ee8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5MThlMzJiZmY2ZTlhZmU0OTdlYTEzODFlNzlmMGVlOCJ9.IM_nEtAR-4mjso6Pmiy4gAXhun1YnW2v_08BjmA7ik4&download=image.png "")

```text
spring.application.name=stream-sample
server.port=63001
#server.port=63000
#server.port=63002

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
spring.cloud.stream.bindings.group-consumer.group=Group-B

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

![](https://tcs.teambition.net/storage/31225e26c9fd9031869e5c8dab96b7b9b497?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI1ZTI2YzlmZDkwMzE4NjllNWM4ZGFiOTZiN2I5YjQ5NyJ9.bUJT90Hvy25e1Kuqol4mPYSrRE-gtEUclRv6vQa_SAI&download=image.png "")

![](https://tcs.teambition.net/storage/3122d933d5a81d67138a85f6e9aa1a7754b0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkOTMzZDVhODFkNjcxMzhhODVmNmU5YWExYTc3NTRiMCJ9.T2TjxjPgKzi3TsI26VgIHjgtwBgoRrsCd8PJM5hGg_I&download=image.png "")

![](https://tcs.teambition.net/storage/3122b1161cfe4eea2de8817282938cfb4cab?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJiMTE2MWNmZTRlZWEyZGU4ODE3MjgyOTM4Y2ZiNGNhYiJ9.Yxm6Nb-uLnQA7_8EgfIAzAq_dpIKyVHgBB62yQr2co4&download=image.png "")

```text
2021-01-31 11:30:14.648  INFO 35968 --- [io-63000-exec-2] o.s.a.r.c.CachingConnectionFactory       : Attempting to connect to: [localhost:5672]
2021-01-31 11:30:14.675  INFO 35968 --- [io-63000-exec-2] o.s.a.r.c.CachingConnectionFactory       : Created new connection: rabbitConnectionFactory.publisher#6510b31e:0/SimpleConnection@31896015 [delegate=amqp://guest@127.0.0.1:5672/, localPort= 59675]
2021-01-31 11:30:14.697  INFO 35968 --- [io-63000-exec-2] o.s.amqp.rabbit.core.RabbitAdmin         : Auto-declaring a non-durable, auto-delete, or exclusive Queue (input.anonymous.3M3ouhGLSyqoGxUk8bEW7A) durable:false, auto-delete:true, exclusive:true. It will be redeclared if the broker stops and is restarted while the connection factory is alive, but all messages will be lost.
2021-01-31 11:30:14.698  INFO 35968 --- [io-63000-exec-2] o.s.amqp.rabbit.core.RabbitAdmin         : Auto-declaring a non-durable, auto-delete, or exclusive Queue (broadcast.anonymous.Xf3XtKkzQje3fKKpgGWKbQ) durable:false, auto-delete:true, exclusive:true. It will be redeclared if the broker stops and is restarted while the connection factory is alive, but all messages will be lost.


```



![](https://tcs.teambition.net/storage/3122d5a4ada149426861a7e691c801ccc968?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkNWE0YWRhMTQ5NDI2ODYxYTdlNjkxYzgwMWNjYzk2OCJ9.ushSxkaxLABL_Bm52HyU6FHKdDKk5UQ15C2eS9Q2kmU&download=image.png "")

```text
2021-01-31 11:30:14.804  INFO 36272 --- [pic.Group-B-1-1] c.imooc.springcloud.biz.StreamConsumer   : Group message consumed successfully，payload=Test


```

发送3次

![](https://tcs.teambition.net/storage/31229a320dba3e5453b27594ac65864bfc7d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5YTMyMGRiYTNlNTQ1M2IyNzU5NGFjNjU4NjRiZmM3ZCJ9.fm4pK3xrmQmbp_UkpqYzJXaLIpdNUKqJq-XKaUeLRlk&download=image.png "")

![](https://tcs.teambition.net/storage/31228304df171f09abea422e6d9cc0c7c3cf?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI4MzA0ZGYxNzFmMDlhYmVhNDIyZTZkOWNjMGM3YzNjZiJ9.aYMnSaeU4mgpsxfPFpBX_3urxTaoR2EcRHo8fY1dC2w&download=image.png "")

```text
2021-01-31 11:30:14.648  INFO 35968 --- [io-63000-exec-2] o.s.a.r.c.CachingConnectionFactory       : Attempting to connect to: [localhost:5672]
2021-01-31 11:30:14.675  INFO 35968 --- [io-63000-exec-2] o.s.a.r.c.CachingConnectionFactory       : Created new connection: rabbitConnectionFactory.publisher#6510b31e:0/SimpleConnection@31896015 [delegate=amqp://guest@127.0.0.1:5672/, localPort= 59675]
2021-01-31 11:30:14.697  INFO 35968 --- [io-63000-exec-2] o.s.amqp.rabbit.core.RabbitAdmin         : Auto-declaring a non-durable, auto-delete, or exclusive Queue (input.anonymous.3M3ouhGLSyqoGxUk8bEW7A) durable:false, auto-delete:true, exclusive:true. It will be redeclared if the broker stops and is restarted while the connection factory is alive, but all messages will be lost.
2021-01-31 11:30:14.698  INFO 35968 --- [io-63000-exec-2] o.s.amqp.rabbit.core.RabbitAdmin         : Auto-declaring a non-durable, auto-delete, or exclusive Queue (broadcast.anonymous.Xf3XtKkzQje3fKKpgGWKbQ) durable:false, auto-delete:true, exclusive:true. It will be redeclared if the broker stops and is restarted while the connection factory is alive, but all messages will be lost.


```

![](https://tcs.teambition.net/storage/31224e4356826fe9dedb18c4e0549335362d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI0ZTQzNTY4MjZmZTlkZWRiMThjNGUwNTQ5MzM1MzYyZCJ9.nrM8fh1OUlJgfZgo2bJYUDwgvV0qjch0X8oi-gZcn_A&download=image.png "")

```text
2021-01-31 11:30:14.804  INFO 36272 --- [pic.Group-B-1-1] c.imooc.springcloud.biz.StreamConsumer   : Group message consumed successfully，payload=Test
2021-01-31 11:31:27.180  INFO 36272 --- [pic.Group-B-1-1] c.imooc.springcloud.biz.StreamConsumer   : Group message consumed successfully，payload=Test
2021-01-31 11:31:35.423  INFO 36272 --- [pic.Group-B-1-1] c.imooc.springcloud.biz.StreamConsumer   : Group message consumed successfully，payload=Test
2021-01-31 11:31:36.642  INFO 36272 --- [pic.Group-B-1-1] c.imooc.springcloud.biz.StreamConsumer   : Group message consumed successfully，payload=Test


```

![](https://tcs.teambition.net/storage/3122d74fd1cf86c1a3189f475ecd6556860f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkNzRmZDFjZjg2YzFhMzE4OWY0NzVlY2Q2NTU2ODYwZiJ9.5vVsYG5aNp1GTkCVEixisMXyiVrssHpDV6TJFgyGh3E&download=image.png "")

```none
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
spring.cloud.stream.bindings.group-consumer.group=Group-B

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

![](https://tcs.teambition.net/storage/3122543b6c0ef9064a6bf9f5073c9c6fd5be?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI1NDNiNmMwZWY5MDY0YTZiZjlmNTA3M2M5YzZmZDViZSJ9.qgH1kMb5EkYcL4x3O9Ig7RzkkZuc9YnU7WFDsiyxAk0&download=image.png "")

![](https://tcs.teambition.net/storage/3122ef8077509e02d0aebf55b24121823014?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJlZjgwNzc1MDllMDJkMGFlYmY1NWIyNDEyMTgyMzAxNCJ9.8Er0ugeazNhAAsDsGrhGVewEa_OoIqaOlI-qoUererU&download=image.png "")

![](https://tcs.teambition.net/storage/31225a240b9bbe6bec06a1198661e0ed1a85?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI1YTI0MGI5YmJlNmJlYzA2YTExOTg2NjFlMGVkMWE4NSJ9.8_wSTcz72jb_ULmfLDO-X5gI7bmMuxVwUg0N4Ii4afE&download=image.png "")

```text
2021-01-31 11:35:17.181  INFO 36272 --- [pic.Group-B-1-1] c.imooc.springcloud.biz.StreamConsumer   : Group message consumed successfully，payload=Test


```

![](https://tcs.teambition.net/storage/31223308b36aacb25ff96cbb445b89295039?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzMzA4YjM2YWFjYjI1ZmY5NmNiYjQ0NWI4OTI5NTAzOSJ9.QtCCXLHxIZ5Q20BoZllcRGIUQ-ZKofybbkHZregWh7E&download=image.png "")

![](https://tcs.teambition.net/storage/3122b3627309902968e69069a8e39d90e29f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJiMzYyNzMwOTkwMjk2OGU2OTA2OWE4ZTM5ZDkwZTI5ZiJ9.txc3ZUgbkf0WM0ChhfxwHV95BkA33VnyUk6jftgRpMg&download=image.png "")

![](https://tcs.teambition.net/storage/312227350733b50affb30d18f1999a2b9d44?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIyNzM1MDczM2I1MGFmZmIzMGQxOGYxOTk5YTJiOWQ0NCJ9.aat_6nhDArw7L9xn7bYZTyMRDiXnqP10eGFxKTtqX5E&download=image.png "")

![](https://tcs.teambition.net/storage/3122ec6332e6d52efbd6a6cdaee7918c3936?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJlYzYzMzJlNmQ1MmVmYmQ2YTZjZGFlZTc5MThjMzkzNiJ9.XUt41iUCSdF4UbPNo4cUdu_8p4-6y3kKaI3fFTSTk9c&download=image.png "")

```text
2021-01-31 11:35:17.181  INFO 36272 --- [pic.Group-B-1-1] c.imooc.springcloud.biz.StreamConsumer   : Group message consumed successfully，payload=Test


```

![](https://tcs.teambition.net/storage/31222030d99831a8af36d8b1f9f74484cdf3?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIyMDMwZDk5ODMxYThhZjM2ZDhiMWY5Zjc0NDg0Y2RmMyJ9.7Bsn7J0swJP6xdMVPtgbp2fIewkPZzev16eITmK09hY&download=image.png "")

```text
2021-01-31 11:36:02.897  INFO 37416 --- [pic.Group-B-1-1] c.imooc.springcloud.biz.StreamConsumer   : Group message consumed successfully，payload=Test


```

发送了很多条

![](https://tcs.teambition.net/storage/312278ddb043368a3182ee5721ab423e1cde?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI3OGRkYjA0MzM2OGEzMTgyZWU1NzIxYWI0MjNlMWNkZSJ9.eCudj70sM7iQRJxnxOMoSSe1dM_BGHa6qU7xn6R19_o&download=image.png "")

![](https://tcs.teambition.net/storage/31222d4eb43c8ff929258cc8a6ad67b69bbe?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIyZDRlYjQzYzhmZjkyOTI1OGNjOGE2YWQ2N2I2OWJiZSJ9.57roh39WEZ4RIhZEWpT-0jTCqHDtXFaPuH4m9chms2s&download=image.png "")

![](https://tcs.teambition.net/storage/312257e0fc7ac639e19fb63edaa218a50a69?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI1N2UwZmM3YWM2MzllMTlmYjYzZWRhYTIxOGE1MGE2OSJ9.KyfthkBEcwJmbbKV_3sqxKa5bLwZbAXM_kgjS-hGKrQ&download=image.png "")

```text
2021-01-31 11:35:17.181  INFO 36272 --- [pic.Group-B-1-1] c.imooc.springcloud.biz.StreamConsumer   : Group message consumed successfully，payload=Test
2021-01-31 11:36:53.655  INFO 36272 --- [pic.Group-B-1-1] c.imooc.springcloud.biz.StreamConsumer   : Group message consumed successfully，payload=Test
2021-01-31 11:36:57.878  INFO 36272 --- [pic.Group-B-1-1] c.imooc.springcloud.biz.StreamConsumer   : Group message consumed successfully，payload=Test


```

![](https://tcs.teambition.net/storage/3122c3a41b34ac122d4d184039a588c03ef6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJjM2E0MWIzNGFjMTIyZDRkMTg0MDM5YTU4OGMwM2VmNiJ9.MSLHsW9MX_HB5UF3YCVxf0MQEF9dRl7cz8LGYLEMRVE&download=image.png "")

```text
2021-01-31 11:36:02.897  INFO 37416 --- [pic.Group-B-1-1] c.imooc.springcloud.biz.StreamConsumer   : Group message consumed successfully，payload=Test
2021-01-31 11:36:54.616  INFO 37416 --- [pic.Group-B-1-1] c.imooc.springcloud.biz.StreamConsumer   : Group message consumed successfully，payload=Test
2021-01-31 11:36:58.835  INFO 37416 --- [pic.Group-B-1-1] c.imooc.springcloud.biz.StreamConsumer   : Group message consumed successfully，payload=Test


```

可以发现是轮询交替来处理数据 

消费分区和消费组可以合起来共同作用 轮询的作用可以理解为消费者提供的 功能

而消费的功能可以理解为是消费分区的 功能









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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTExMiwiaWF0IjoxNjEyMTkwMzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.BqTmz9sSmERe0Da-R5LIgUsXkqQV9PerJNT63mKD27o&download=image.png "")

