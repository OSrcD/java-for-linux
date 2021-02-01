![](https://tcs.teambition.net/storage/3121d5e9649d68c20e8c950795572a193467?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTQ3OCwiaWF0IjoxNjEyMTkwNjc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkNWU5NjQ5ZDY4YzIwZThjOTUwNzk1NTcyYTE5MzQ2NyJ9.ckcHy9AK_xtOJW8qW8FddcJ3x4slInRDEvVlQtabgLA&download=2020-09-17%20060202.png "")

![](https://tcs.teambition.net/storage/31214b78d3b906222613a8a21575946b5c8f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTQ3OCwiaWF0IjoxNjEyMTkwNjc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0Yjc4ZDNiOTA2MjIyNjEzYThhMjE1NzU5NDZiNWM4ZiJ9.UfRN1acNuwFKmm1JMnPzwOA84JHZpxVM_LLUlt0Uk_c&download=2020-09-17%20060230.png "")

![]( "")

![](https://tcs.teambition.net/storage/312108ee406eb211da01643aa59cc21cbd9e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTQ3OCwiaWF0IjoxNjEyMTkwNjc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwOGVlNDA2ZWIyMTFkYTAxNjQzYWE1OWNjMjFjYmQ5ZSJ9.sbfDVxigFik6ED-yID_ILmy9mPuVOg5rg4SCpuuPpjM&download=image.png "")

![](https://tcs.teambition.net/storage/312121d8e7bd4d83f2023ea2e29ee9c0cfe5?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTQ3OCwiaWF0IjoxNjEyMTkwNjc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyMWQ4ZTdiZDRkODNmMjAyM2VhMmUyOWVlOWMwY2ZlNSJ9.jekiw1ft8m_tF7KlxD0FWJn98_Maw9EMyUzyjLsYa-s&download=image.png "")

```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <parent>
        <artifactId>spring-cloud-demo</artifactId>
        <groupId>com.imooc</groupId>
        <version>1.0-SNAPSHOT</version>
        <relativePath>../../pom.xml</relativePath>
    </parent>
    <modelVersion>4.0.0</modelVersion>
    <packaging>jar</packaging>
    <artifactId>config-bus-client</artifactId>

    <dependencies>
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-web</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-config</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-actuator</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-client</artifactId>
        </dependency>

        <!-- rabbit mq -->
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-bus-amqp</artifactId>
        </dependency>

        <!-- kafka -->
        <!--<dependency>-->
        <!--<groupId>org.springframework.cloud</groupId>-->
        <!--<artifactId>spring-cloud-starter-bus-kafka</artifactId>-->
        <!--</dependency>-->
    </dependencies>

</project>
```

![](https://tcs.teambition.net/storage/312125d08de7bb875472764227aac393bf32?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTQ3OCwiaWF0IjoxNjEyMTkwNjc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyNWQwOGRlN2JiODc1NDcyNzY0MjI3YWFjMzkzYmYzMiJ9.bARE28pP_Fu_BM8RqgxXOF0o7DtRccbCB9b_36CZjn8&download=image.png "")

两个MQ 一起用的问题

![](https://tcs.teambition.net/storage/31216261841a492add70c5402faef5b434b2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTQ3OCwiaWF0IjoxNjEyMTkwNjc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2MjYxODQxYTQ5MmFkZDcwYzU0MDJmYWVmNWI0MzRiMiJ9.yxOut-NjyhugtBHBQ94j51-UswwdVXEDjnHq6GQ4hUE&download=image.png "")

默认的 default binder

![](https://tcs.teambition.net/storage/312147396f0ea7262f2213102c07dfbf7dd5?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTQ3OCwiaWF0IjoxNjEyMTkwNjc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0NzM5NmYwZWE3MjYyZjIyMTMxMDJjMDdkZmJmN2RkNSJ9.gGQ7OZ8h6Uhqjuf-11dWbDawbQ2rkPDaUQeOHMHfQBk&download=image.png "")

![](https://tcs.teambition.net/storage/31213d895072cea5b97d34fcf52c7190ec27?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTQ3OCwiaWF0IjoxNjEyMTkwNjc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzZDg5NTA3MmNlYTViOTdkMzRmY2Y1MmM3MTkwZWMyNyJ9.FG8hY_uqqZw8Didhw2a5oZtoS0kYRFQV0zDQ1EPv1FI&download=image.png "")

```java
package com.imooc.springcloud;

import org.springframework.boot.WebApplicationType;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.builder.SpringApplicationBuilder;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;


@SpringBootApplication
@EnableDiscoveryClient
public class ConfigBusClientApplication {

    public static void main(String[] args) {
        new SpringApplicationBuilder(ConfigBusClientApplication.class)
                .web(WebApplicationType.SERVLET)
                .run(args);
    }

}

```

![](https://tcs.teambition.net/storage/31213f72f1f9a93a5cafdf8e39bc9156ae4a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTQ3OCwiaWF0IjoxNjEyMTkwNjc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzZjcyZjFmOWE5M2E1Y2FmZGY4ZTM5YmM5MTU2YWU0YSJ9.EaRJdzydefIuIrRdwxtNsZRlNd3eu3HwrjfzzOpupxY&download=image.png "")

```java
package com.imooc.springcloud;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class Controller {

    @Value("${name}")
    private String name;

    @Value("${myWords}")
    private String words;

    @GetMapping("/name")
    public String getName() {
        return name;
    }

    @GetMapping("/words")
    public String getWords() {
        return words;
    }

}

```

![](https://tcs.teambition.net/storage/312111c326b269928b972df6f0187714da2e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTQ3OCwiaWF0IjoxNjEyMTkwNjc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExMWMzMjZiMjY5OTI4Yjk3MmRmNmYwMTg3NzE0ZGEyZSJ9.EajU1ZvrV2uI3hHvXRi3SjlfsLDMX6CRk_O8EkW6LNI&download=image.png "")

```java
package com.imooc.springcloud;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.cloud.context.config.annotation.RefreshScope;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;


@RestController
@RequestMapping("/refresh")
@RefreshScope
public class RefreshController {

    @Value("${words}")
    private String words;

    @Value("${food}")
    private String food;


    @GetMapping("/words")
    public String getWords() {
        return words;
    }

    @GetMapping("/dinner")
    public String dinner() {
        return "May I have one " + food;
    }

}

```

![](https://tcs.teambition.net/storage/3121499f5a674739f9022d4e60e664b141f9?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTQ3OCwiaWF0IjoxNjEyMTkwNjc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0OTlmNWE2NzQ3MzlmOTAyMmQ0ZTYwZTY2NGIxNDFmOSJ9.xMxzKCJH4ihAHFyKG-qE5re_8x604KOWUJ3mZkNggJw&download=image.png "")

```yaml
spring:
  application:
    name: config-bus-client
  # rabbitmq 连接字符串
  rabbitmq:
    host: localhost
    port: 5672
    username: guest
    password: guest
  cloud:
    stream:
      # 默认 绑定器 用于与消息中间件通信的组件 引入了多个binder 一定要设置
      default-binder: rabbit
    config:
      # spring.application.name 与 github 的 文件夹或文件不一致的时候
      # 可以强制指定一个 name
      name: config-consumer
#      uri: http://localhost:60000
      discovery:
        enabled: true
        service-id: config-bus-server
      profile: prod
      label: main

server:
  port: 61002

myWords: ${words}

eureka:
  client:
    serviceUrl:
      defaultZone: http://localhost:20000/eureka/

management:
  security:
    user:
      name: gitee
      password: gitee
      roles: ADMIN
  endpoints:
    web:
      exposure:
        # 使用"" 才能识别 *
        include: "*"
  endpoint:
    health:
      show-details: always








```

![](https://tcs.teambition.net/storage/31217e8085fcf79d46172b5ce9d3130b5e1d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTQ3OCwiaWF0IjoxNjEyMTkwNjc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3ZTgwODVmY2Y3OWQ0NjE3MmI1Y2U5ZDMxMzBiNWUxZCJ9.8sjP6aVK0rDjCUGkt1CERqOlYV_BZ3x9OrgtagRdEMk&download=image.png "")

```xml
<?xml version="1.0" encoding="UTF-8" ?>
<configuration>
    <appender name="consoleLog" class="ch.qos.logback.core.ConsoleAppender">
        <filter class="ch.qos.logback.classic.filter.ThresholdFilter">
            <level>INFO</level>
        </filter>
        <layout class="ch.qos.logback.classic.PatternLayout">
            <pattern>
                [%d{HH:mm:ss.SSS}] %-5level %logger{15} - %msg%n
            </pattern>
        </layout>
    </appender>

    <appender name="fileLog" class="ch.qos.logback.core.rolling.RollingFileAppender">
        <encoder>
            <pattern>
                [%d{HH:mm:ss.SSS}] %-5level [%thread]%logger{15} - %msg%n
            </pattern>
        </encoder>
        <rollingPolicy class="ch.qos.logback.core.rolling.TimeBasedRollingPolicy">
            <fileNamePattern>logs/%d.log</fileNamePattern>
            <maxHistory>30</maxHistory>
        </rollingPolicy>
    </appender>
    <root level="DEBUG">
        <appender-ref ref = "consoleLog"/>
        <appender-ref ref = "fileLog"/>
    </root>
</configuration>
```

启动

![](https://tcs.teambition.net/storage/312154d34753799c5a16b47bede923782416?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTQ3OCwiaWF0IjoxNjEyMTkwNjc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1NGQzNDc1Mzc5OWM1YTE2YjQ3YmVkZTkyMzc4MjQxNiJ9.jbwHJlCpYnIZuu8fqBpHVDl9D3fZOZGKrY-VJqa6PUs&download=image.png "")

![](https://tcs.teambition.net/storage/3121b17f5fb11932db2ca04449b42727e904?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTQ3OCwiaWF0IjoxNjEyMTkwNjc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiMTdmNWZiMTE5MzJkYjJjYTA0NDQ5YjQyNzI3ZTkwNCJ9.LCODdaRU4jXIP6xm76_ZybUBm20mEWzOITH2WwH1660&download=image.png "")

![](https://tcs.teambition.net/storage/312167751091a966c36bd60dcd519a795c60?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTQ3OCwiaWF0IjoxNjEyMTkwNjc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2Nzc1MTA5MWE5NjZjMzZiZDYwZGNkNTE5YTc5NWM2MCJ9.5P4dB_tK_5v-Iq7f5lXa863IMy3F8iSsXqYV78HijTw&download=image.png "")

![](https://tcs.teambition.net/storage/312169b96acfcbd8a80e772838b042d80b3e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTQ3OCwiaWF0IjoxNjEyMTkwNjc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2OWI5NmFjZmNiZDhhODBlNzcyODM4YjA0MmQ4MGIzZSJ9.cuh7WuK__M3HFfS3Hf58O9VGGfYmZjJJVgF1Bj8q9wQ&download=image.png "")

![](https://tcs.teambition.net/storage/3121f3d94aa8da20cede29412153f133b13f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTQ3OCwiaWF0IjoxNjEyMTkwNjc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmM2Q5NGFhOGRhMjBjZWRlMjk0MTIxNTNmMTMzYjEzZiJ9.m6DU5P-oqupszdpROxnL8vo2ShCLgEMnDqa1-aRt1V0&download=image.png "")

![](https://tcs.teambition.net/storage/312199d65bafcfe22a2a9bea5725a84974d0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTQ3OCwiaWF0IjoxNjEyMTkwNjc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5OWQ2NWJhZmNmZTIyYTJhOWJlYTU3MjVhODQ5NzRkMCJ9.pfZHNYPmoKdmciZ2sIiXNgm6CX4bjW_l0aTwQzONoyI&download=image.png "")

![](https://tcs.teambition.net/storage/31216d8f5118236cb04ed18c0ea25a60b06c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTQ3OCwiaWF0IjoxNjEyMTkwNjc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2ZDhmNTExODIzNmNiMDRlZDE4YzBlYTI1YTYwYjA2YyJ9.XPR0cjj4fEfW4d-nLrPt_VtMKG1dL4cI9idxQYJPnIo&download=image.png "")

![](https://tcs.teambition.net/storage/3121c861fa6eea7fcfa083fb2112d1d08641?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTQ3OCwiaWF0IjoxNjEyMTkwNjc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjODYxZmE2ZWVhN2ZjZmEwODNmYjIxMTJkMWQwODY0MSJ9.UBFWWKEtJPf10emtr9U4wvO_4eD4_aUyFgLdanvCdtY&download=image.png "")

![](https://tcs.teambition.net/storage/3121bade8623e2a44030bd412be5d46c41dd?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTQ3OCwiaWF0IjoxNjEyMTkwNjc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiYWRlODYyM2UyYTQ0MDMwYmQ0MTJiZTVkNDZjNDFkZCJ9.GwRe8zAMadFSTJrq1Q83mL5LG6mjCEVSqLa1j4LV1CA&download=image.png "")

![](https://tcs.teambition.net/storage/31219e8bc08c6226b917b031b2cf8b9a9653?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTQ3OCwiaWF0IjoxNjEyMTkwNjc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5ZThiYzA4YzYyMjZiOTE3YjAzMWIyY2Y4YjlhOTY1MyJ9.QJfvVV3gB2_HJK_0zR4xWAI6wrORyeSzxVtfoeb7KNg&download=image.png "")

204 代表批量刷新动作已经完成了

![](https://tcs.teambition.net/storage/312109b0608ae5e34c74a70a351420c25ee2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTQ3OCwiaWF0IjoxNjEyMTkwNjc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwOWIwNjA4YWU1ZTM0Yzc0YTcwYTM1MTQyMGMyNWVlMiJ9.QHszdNha4UTRl10pAcPWwlFz0jZOHQndA71kaUNMS_8&download=image.png "")

![](https://tcs.teambition.net/storage/3121a13ce74020811c230784a735e6c2dae2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTQ3OCwiaWF0IjoxNjEyMTkwNjc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhMTNjZTc0MDIwODExYzIzMDc4NGE3MzVlNmMyZGFlMiJ9.w5Htu3KZnbwZbz7YbPhQI3jwBvH5g3dDI-1oVECCEZM&download=image.png "")

![](https://tcs.teambition.net/storage/3121ffb11213481d6b34fb0d814fa84dbe06?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTQ3OCwiaWF0IjoxNjEyMTkwNjc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmZmIxMTIxMzQ4MWQ2YjM0ZmIwZDgxNGZhODRkYmUwNiJ9.LC4ckmXaUndyBKChStviiiU6iIWAkOboKA3pUBnkQo4&download=image.png "")

针对 某个节点进行刷新 

![](https://tcs.teambition.net/storage/3121f3b0351c46d48fafe64d0ed00271b771?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTQ3OCwiaWF0IjoxNjEyMTkwNjc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmM2IwMzUxYzQ2ZDQ4ZmFmZTY0ZDBlZDAwMjcxYjc3MSJ9.tDiVOuytlpbsKiQCimt6rOWnL2tAGsRMsvsaDie2Dis&download=image.png "")

![](https://tcs.teambition.net/storage/3121f45075c9b1b33b8bd9416eb95b6c0432?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTQ3OCwiaWF0IjoxNjEyMTkwNjc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmNDUwNzVjOWIxYjMzYjhiZDk0MTZlYjk1YjZjMDQzMiJ9.RJG9a0_M2wuRGJeXepMhzH-wsk700NWBpgctzbG_g0o&download=image.png "")

两个都会刷新

![](https://tcs.teambition.net/storage/3121ef7f70206992788d59fdab297ff9edb8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTQ3OCwiaWF0IjoxNjEyMTkwNjc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlZjdmNzAyMDY5OTI3ODhkNTlmZGFiMjk3ZmY5ZWRiOCJ9.PR9O1sABPzApBgQh7EaKoxj45vD0QI-20HArJy-6YpM&download=image.png "")

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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTQ3OCwiaWF0IjoxNjEyMTkwNjc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.F4g6FwyZTcgk02e36C2XL3X6AkIBvmh8AyetiJFiUXs&download=image.png "")

