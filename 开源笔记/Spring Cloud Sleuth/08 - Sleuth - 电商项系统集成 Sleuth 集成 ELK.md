![](https://tcs.teambition.net/storage/3122f689adca199c95f2e93b66dcf3fc7102?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTE5NywiaWF0IjoxNjEyMTkwMzk3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJmNjg5YWRjYTE5OWM5NWYyZTkzYjY2ZGNmM2ZjNzEwMiJ9.446sLYRBw4G3qZ3X8LlC7OMu_7ILbtpMRAcrKoxFct4&download=2020-09-17%20061248.png "")

![](https://tcs.teambition.net/storage/3122406f398fe5622e6c5e051b523ebb4d6b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTE5NywiaWF0IjoxNjEyMTkwMzk3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI0MDZmMzk4ZmU1NjIyZTZjNWUwNTFiNTIzZWJiNGQ2YiJ9.aQHfiOj7yT-om95quCL8auJFIz06khYCG_9Xg_lh_6I&download=2020-09-17%20061306.png "")

![](https://tcs.teambition.net/storage/312285316f3fa51691e2905a69ba5f61aee9?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTE5NywiaWF0IjoxNjEyMTkwMzk3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI4NTMxNmYzZmE1MTY5MWUyOTA1YTY5YmE1ZjYxYWVlOSJ9._1yHb2E5qfC65ifJEPT92s-nS9DLj7gVRd14UXkYCZs&download=image.png "")

```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <parent>
        <artifactId>foodie-cloud</artifactId>
        <groupId>com.imooc</groupId>
        <version>1.0-SNAPSHOT</version>
        <relativePath>../../../pom.xml</relativePath>
    </parent>
    <modelVersion>4.0.0</modelVersion>

    <artifactId>foodie-auth-service</artifactId>

    <dependencies>
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-web</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-client</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-actuator</artifactId>
        </dependency>

        <!-- redis -->
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-data-redis</artifactId>
        </dependency>

        <!-- jwt -->
        <dependency>
            <groupId>com.auth0</groupId>
            <artifactId>java-jwt</artifactId>
            <version>3.7.0</version>
        </dependency>

        <dependency>
            <groupId>com.imooc</groupId>
            <artifactId>foodie-auth-api</artifactId>
            <version>${project.version}</version>
        </dependency>

        <!-- 链路追踪 -->
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-sleuth</artifactId>
        </dependency>
        <!-- Zipkin -->
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-zipkin</artifactId>
        </dependency>

        <!-- Logstash for ELK-->
        <dependency>
            <groupId>net.logstash.logback</groupId>
            <artifactId>logstash-logback-encoder</artifactId>
            <version>5.2</version>
        </dependency>

    </dependencies>

    <build>
        <plugins>
            <plugin>
                <groupId>org.springframework.boot</groupId>
                <artifactId>spring-boot-maven-plugin</artifactId>
                <configuration>
                    <mainClass>com.imooc.auth.service.impl.AuthApplication</mainClass>
                </configuration>
                <executions>
                    <execution>
                        <goals>
                            <goal>repackage</goal>
                        </goals>
                    </execution>
                </executions>
            </plugin>
        </plugins>
    </build>

</project>
```

![](https://tcs.teambition.net/storage/31225cd12d0a40326c5e68d7623a1c0bdd83?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTE5NywiaWF0IjoxNjEyMTkwMzk3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI1Y2QxMmQwYTQwMzI2YzVlNjhkNzYyM2ExYzBiZGQ4MyJ9.7gOupaDDQLZmrR0amUoPMcT0sRrNyTEP30Hzt11xTZM&download=image.png "")

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

    <!-- Logstash -->
    <!-- 为logstash输出的JSON格式的Appender -->
    <appender name="logstash"
              class="net.logstash.logback.appender.LogstashTcpSocketAppender">
        <destination>127.0.0.1:5044</destination>
        <!-- 日志输出编码 -->
        <encoder
                class="net.logstash.logback.encoder.LoggingEventCompositeJsonEncoder">
            <providers>
                <timestamp>
                    <timeZone>UTC</timeZone>
                </timestamp>
                <pattern>
                    <pattern>
                        {
                        "severity": "%level",
                        "service": "${springAppName:-}",
                        "trace": "%X{X-B3-TraceId:-}",
                        "span": "%X{X-B3-SpanId:-}",
                        "exportable": "%X{X-Span-Export:-}",
                        "pid": "${PID:-}",
                        "thread": "%thread",
                        "class": "%logger{40}",
                        "rest": "%message"
                        }
                    </pattern>
                </pattern>
            </providers>
        </encoder>
    </appender>

    <root level="DEBUG">
        <appender-ref ref = "consoleLog"/>
        <appender-ref ref = "fileLog"/>
        <appender-ref ref = "logstash"/>
    </root>
</configuration>
```

启动

![](https://tcs.teambition.net/storage/31226de7cc47dc2a45d7edc61ee412039afb?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTE5NywiaWF0IjoxNjEyMTkwMzk3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI2ZGU3Y2M0N2RjMmE0NWQ3ZWRjNjFlZTQxMjAzOWFmYiJ9.IQdH1f8994_YW3lnn7JXhNeDuusXXaWRsEYjfv3FIKg&download=image.png "")

![](https://tcs.teambition.net/storage/3122c4dc4285b1dd6ff52d770e5ab82590d7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTE5NywiaWF0IjoxNjEyMTkwMzk3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJjNGRjNDI4NWIxZGQ2ZmY1MmQ3NzBlNWFiODI1OTBkNyJ9.SjwTIjmJZq_OVOJwUD-6W0O6pNVuVx4EwSEYvYheLmk&download=image.png "")

复制

![](https://tcs.teambition.net/storage/31227ffd7c145f9bf601656f947180f0d779?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTE5NywiaWF0IjoxNjEyMTkwMzk3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI3ZmZkN2MxNDVmOWJmNjAxNjU2Zjk0NzE4MGYwZDc3OSJ9.P3np-HdArp4aYGiTguSOyXfVuKapW3xGQU4J43ykZJU&download=image.png "")

![](https://tcs.teambition.net/storage/312234ddbc1ca7218dd98e83e7afa8899b68?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTE5NywiaWF0IjoxNjEyMTkwMzk3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzNGRkYmMxY2E3MjE4ZGQ5OGU4M2U3YWZhODg5OWI2OCJ9.rLaK-3Fr34sReyPPjOhLPfQ2s_kVAF--msfsiGcfyVI&download=image.png "")

![](https://tcs.teambition.net/storage/31225952dc6073c467126124cc222f1f000d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTE5NywiaWF0IjoxNjEyMTkwMzk3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI1OTUyZGM2MDczYzQ2NzEyNjEyNGNjMjIyZjFmMDAwZCJ9.Q1sWNFwlDTiJZBxdv0liC0BGkyLb1OyW5YdnVpFSl8g&download=image.png "")

```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <parent>
        <artifactId>foodie-cloud</artifactId>
        <groupId>com.imooc</groupId>
        <version>1.0-SNAPSHOT</version>
        <relativePath>../../../pom.xml</relativePath>
    </parent>
    <modelVersion>4.0.0</modelVersion>

    <artifactId>foodie-user-web</artifactId>

    <dependencies>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-user-service</artifactId>
            <version>${project.version}</version>
        </dependency>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-cloud-web-components</artifactId>
            <version>${project.version}</version>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-client</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-config</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-bus-amqp</artifactId>
        </dependency>

        <dependency>
            <groupId>com.imooc</groupId>
            <artifactId>foodie-auth-api</artifactId>
            <version>${project.version}</version>
        </dependency>

        <!-- 链路追踪 -->
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-sleuth</artifactId>
        </dependency>
        <!-- Zipkin -->
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-zipkin</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-logging</artifactId>
        </dependency>

        <!-- Logstash for ELK-->
        <dependency>
            <groupId>net.logstash.logback</groupId>
            <artifactId>logstash-logback-encoder</artifactId>
            <version>5.2</version>
        </dependency>
    </dependencies>

    <build>
        <plugins>
            <plugin>
                <groupId>org.springframework.boot</groupId>
                <artifactId>spring-boot-maven-plugin</artifactId>
                <configuration>
                    <mainClass>com.imooc.user.UserApplication</mainClass>
                </configuration>
                <executions>
                    <execution>
                        <goals>
                            <goal>repackage</goal>
                        </goals>
                    </execution>
                </executions>
            </plugin>
        </plugins>
    </build>

</project>
```

![](https://tcs.teambition.net/storage/3122e2acaf029709a0e5d40f2449bdfb2365?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTE5NywiaWF0IjoxNjEyMTkwMzk3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJlMmFjYWYwMjk3MDlhMGU1ZDQwZjI0NDliZGZiMjM2NSJ9.eZoqQRbCttGuLUM4uXvxoRvvFKuEA27c7lspsKHDmJs&download=image.png "")

```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <parent>
        <artifactId>foodie-cloud</artifactId>
        <groupId>com.imooc</groupId>
        <version>1.0-SNAPSHOT</version>
        <relativePath>../../pom.xml</relativePath>
    </parent>
    <modelVersion>4.0.0</modelVersion>

    <artifactId>gateway</artifactId>

    <dependencies>
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-gateway</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-client</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-actuator</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-data-redis-reactive</artifactId>
        </dependency>

        <!-- 因为spring cloud gateway是基于webflux的，
        如果非要web支持的话需要导入spring-boot-starter-webflux而不是spring-boot-start-web-->
        <dependency>
            <groupId>com.imooc</groupId>
            <artifactId>foodie-auth-api</artifactId>
            <version>${project.version}</version>
            <exclusions>
                <exclusion>
                    <groupId>org.springframework.boot</groupId>
                    <artifactId>spring-boot-starter-web</artifactId>
                </exclusion>
            </exclusions>
        </dependency>

        <!-- 链路追踪 -->
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-sleuth</artifactId>
        </dependency>
        <!-- Zipkin -->
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-zipkin</artifactId>
        </dependency>

        <!-- Logstash for ELK-->
        <dependency>
            <groupId>net.logstash.logback</groupId>
            <artifactId>logstash-logback-encoder</artifactId>
            <version>5.2</version>
        </dependency>
    </dependencies>

    <build>
        <plugins>
            <plugin>
                <groupId>org.springframework.boot</groupId>
                <artifactId>spring-boot-maven-plugin</artifactId>
                <configuration>
                    <mainClass>com.imooc.GatewayApplication</mainClass>
                </configuration>
                <executions>
                    <execution>
                        <goals>
                            <goal>repackage</goal>
                        </goals>
                    </execution>
                </executions>
            </plugin>
        </plugins>
    </build>

</project>
```

![](https://tcs.teambition.net/storage/3122ebdfc1114a0377f5d4346a2a657e6fb2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTE5NywiaWF0IjoxNjEyMTkwMzk3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJlYmRmYzExMTRhMDM3N2Y1ZDQzNDZhMmE2NTdlNmZiMiJ9.j8LkP58ymGYkCj29XMICjXzJMRz9UwFGk9l0MgAMRgk&download=image.png "")

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

    <!-- Logstash -->
    <!-- 为logstash输出的JSON格式的Appender -->
    <appender name="logstash"
              class="net.logstash.logback.appender.LogstashTcpSocketAppender">
        <destination>127.0.0.1:5044</destination>
        <!-- 日志输出编码 -->
        <encoder
                class="net.logstash.logback.encoder.LoggingEventCompositeJsonEncoder">
            <providers>
                <timestamp>
                    <timeZone>UTC</timeZone>
                </timestamp>
                <pattern>
                    <pattern>
                        {
                        "severity": "%level",
                        "service": "${springAppName:-}",
                        "trace": "%X{X-B3-TraceId:-}",
                        "span": "%X{X-B3-SpanId:-}",
                        "exportable": "%X{X-Span-Export:-}",
                        "pid": "${PID:-}",
                        "thread": "%thread",
                        "class": "%logger{40}",
                        "rest": "%message"
                        }
                    </pattern>
                </pattern>
            </providers>
        </encoder>
    </appender>

    <root level="DEBUG">
        <appender-ref ref = "consoleLog"/>
        <appender-ref ref = "fileLog"/>
        <appender-ref ref = "logstash"/>
    </root>
</configuration>
```

启动 user 

![](https://tcs.teambition.net/storage/31225f9b48597039b67949a77c3a692c7468?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTE5NywiaWF0IjoxNjEyMTkwMzk3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI1ZjliNDg1OTcwMzliNjc5NDlhNzdjM2E2OTJjNzQ2OCJ9.SGDvzDKbXt5Jel8NOUD-sTKWK1cqogrWckyBmWf-sYE&download=image.png "")

启动 elk

![](https://tcs.teambition.net/storage/3122c4e1826d6897936e920e8388f3fe678a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTE5NywiaWF0IjoxNjEyMTkwMzk3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJjNGUxODI2ZDY4OTc5MzZlOTIwZTgzODhmM2ZlNjc4YSJ9.zLgsdq448BiJW_Rhps0UETJ77ALQWBrqwSWc0bh0TIs&download=image.png "")

启动网关

![](https://tcs.teambition.net/storage/31223b71bc03dbbd0086bb4e1dbbbdd15537?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTE5NywiaWF0IjoxNjEyMTkwMzk3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzYjcxYmMwM2RiYmQwMDg2YmI0ZTFkYmJiZGQxNTUzNyJ9.1fOZhf1qyfxKULTjhU0iNWDBhR7rdg3i7JBkmAjIrOw&download=image.png "")

 

![](https://tcs.teambition.net/storage/3122f96f35c21d6fcb2fae6daba85bfdd30b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTE5NywiaWF0IjoxNjEyMTkwMzk3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJmOTZmMzVjMjFkNmZjYjJmYWU2ZGFiYTg1YmZkZDMwYiJ9.XyIMQRVsmwXzqyVAlub1nmq2sEaq2waZdYsZT8JlM_U&download=image.png "")

![](https://tcs.teambition.net/storage/31223ea1e182c76cc815ded763e662625ee6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTE5NywiaWF0IjoxNjEyMTkwMzk3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzZWExZTE4MmM3NmNjODE1ZGVkNzYzZTY2MjYyNWVlNiJ9.lytsEGoJ12M8QO3dsTe2vq-V9cvLWf8pE5aehpggDd4&download=image.png "")

![](https://tcs.teambition.net/storage/3122182f688fc7b9d3495aaecb8d3f9f913b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTE5NywiaWF0IjoxNjEyMTkwMzk3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxODJmNjg4ZmM3YjlkMzQ5NWFhZWNiOGQzZjlmOTEzYiJ9.WSTyPjTfMW2Yn_oH0Au-ep3mxI5vyRvwUgDfIRfpDMk&download=image.png "")

![](https://tcs.teambition.net/storage/3122d571ee46aa77ca8fcfccad6d32852ccb?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTE5NywiaWF0IjoxNjEyMTkwMzk3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkNTcxZWU0NmFhNzdjYThmY2ZjY2FkNmQzMjg1MmNjYiJ9.6sMD1fAPKUFr8ByqtrCHApUnB1KBsIABM3_0XWfDZ7s&download=image.png "")

![](https://tcs.teambition.net/storage/312296e4677bfd32611da798a028e2ff0f6d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTE5NywiaWF0IjoxNjEyMTkwMzk3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5NmU0Njc3YmZkMzI2MTFkYTc5OGEwMjhlMmZmMGY2ZCJ9.JuHsVa5zRPnIdBcAlgad9Vg3UeHp4dL9SYB2ihwaosg&download=image.png "")

![](https://tcs.teambition.net/storage/31220608891f82c8bf1af1416de10059890b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTE5NywiaWF0IjoxNjEyMTkwMzk3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIwNjA4ODkxZjgyYzhiZjFhZjE0MTZkZTEwMDU5ODkwYiJ9.pvZbEF4dp0K0B63DnJcE33UOKi1XENjB8zfLxemqCm0&download=image.png "")

![](https://tcs.teambition.net/storage/3122c3c43754c572ad4272d83215e224f534?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTE5NywiaWF0IjoxNjEyMTkwMzk3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJjM2M0Mzc1NGM1NzJhZDQyNzJkODMyMTVlMjI0ZjUzNCJ9.NwSBkUO1oAiK_m3iMJ47OU9N2fi8N6kFf1OQwcYa6WM&download=image.png "")

![](https://tcs.teambition.net/storage/3122990494dea9aabb69d2941e92fc736c07?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTE5NywiaWF0IjoxNjEyMTkwMzk3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5OTA0OTRkZWE5YWFiYjY5ZDI5NDFlOTJmYzczNmMwNyJ9.E-jzEmUD3fRBS3OX3dBRpRZQVGsjBpXqzlrasmD4W2w&download=image.png "")

![](https://tcs.teambition.net/storage/3122a01bdae5f8b07f2af03e87ebe2d63dd0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTE5NywiaWF0IjoxNjEyMTkwMzk3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhMDFiZGFlNWY4YjA3ZjJhZjAzZTg3ZWJlMmQ2M2RkMCJ9.7JMSGM02zTnEKGVb92F_j1QPL25jTqB-Na7r-90sU5s&download=image.png "")

![](https://tcs.teambition.net/storage/31222752d34b867f3a7149e2e01a22b73927?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTE5NywiaWF0IjoxNjEyMTkwMzk3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIyNzUyZDM0Yjg2N2YzYTcxNDllMmUwMWEyMmI3MzkyNyJ9.aBmvBVV5ofplTi_rUOmdZvxFllfLAgK69m0f4HxjrcE&download=image.png "")

![]( "")

![](https://tcs.teambition.net/storage/31227656da17eb409011411f01b05d451f40?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTE5NywiaWF0IjoxNjEyMTkwMzk3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI3NjU2ZGExN2ViNDA5MDExNDExZjAxYjA1ZDQ1MWY0MCJ9.PzL01LpRURsrPGaady1J2hDR8CYU5ycx2_oMGAzJ5k8&download=image.png "")

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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTE5NywiaWF0IjoxNjEyMTkwMzk3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.oYkahEISR0c7lBtUV83Y-F313wgpr1ta1StwPvtNcNI&download=image.png "")

