![](https://tcs.teambition.net/storage/312247440a470188f2b20ed2a9ac46be1cba?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIzMCwiaWF0IjoxNjEyMTkwNDMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI0NzQ0MGE0NzAxODhmMmIyMGVkMmE5YWM0NmJlMWNiYSJ9.R030tgdy_cXQY23tijDAERghH5fbJcWnamedLYYDOz0&download=image.png "")

![](https://tcs.teambition.net/storage/31220984e832998417eaecd0f17b89c6b9c0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIzMCwiaWF0IjoxNjEyMTkwNDMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIwOTg0ZTgzMjk5ODQxN2VhZWNkMGYxN2I4OWM2YjljMCJ9.xT-4K-EzcaCI-VZ44zgS1eVa1QhFgRgfhNA_CZQv5GU&download=image.png "")

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

    <artifactId>sleuth-traceA</artifactId>

    <dependencies>
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-client</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-web</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-actuator</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-sleuth</artifactId>
        </dependency>

        <!-- Zipkin -->
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-zipkin</artifactId>
        </dependency>

        <!-- Logstash for ELK -->
        <dependency>
            <groupId>net.logstash.logback</groupId>
            <artifactId>logstash-logback-encoder</artifactId>
            <version>5.2</version>
        </dependency>

    </dependencies>

</project>
```

![](https://tcs.teambition.net/storage/31228c62fe2a4dd4ae415625341bf3ab12d8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIzMCwiaWF0IjoxNjEyMTkwNDMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI4YzYyZmUyYTRkZDRhZTQxNTYyNTM0MWJmM2FiMTJkOCJ9.QbXl2dTC5NPFj0VH3mYN-qYHbFH5M1RfWu9C-FirOfs&download=image.png "")

![](https://tcs.teambition.net/storage/31220df7dbe64ac1955deb575b61c68278d8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIzMCwiaWF0IjoxNjEyMTkwNDMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIwZGY3ZGJlNjRhYzE5NTVkZWI1NzViNjFjNjgyNzhkOCJ9.Nqm1msIrzO-lXfsDoYYmoOvKE6XIbKDN8FeZAMU8fwM&download=image.png "")

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!--该日志将日志级别不同的log信息保存到不同的文件中 -->
<configuration>
    <include resource="org/springframework/boot/logging/logback/defaults.xml" />

    <springProperty scope="context" name="springAppName"
                    source="spring.application.name" />

    <!-- 日志输出位置 -->
    <property name="LOG_FILE" value="${BUILD_FOLDER:-build}/${springAppName}" />

    <!-- 日志格式 -->
    <!-- %clr(${LOG_LEVEL_PATTERN:-%5p}) sleuth 的输出 -->
    <property name="CONSOLE_LOG_PATTERN"
              value="%clr(%d{HH:mm:ss.SSS}){faint} %clr(${LOG_LEVEL_PATTERN:-%5p}) %clr(${PID:- }){magenta} %clr(---){faint} %clr([%15.15t]){faint} %m%n${LOG_EXCEPTION_CONVERSION_WORD:-%wEx}}" />

    <!-- 控制台输出 -->
    <appender name="console" class="ch.qos.logback.core.ConsoleAppender">
        <filter class="ch.qos.logback.classic.filter.ThresholdFilter">
            <level>INFO</level>
        </filter>
        <!-- 日志输出编码 -->
        <encoder>
            <pattern>${CONSOLE_LOG_PATTERN}</pattern>
            <charset>utf8</charset>
        </encoder>
    </appender>

    <!-- 在log 文件 每一个输出都是一个appender -->
    <!-- Logstash -->
    <!-- 为logstash输出的JSON格式的Appender -->
    <appender name="logstash"
              class="net.logstash.logback.appender.LogstashTcpSocketAppender">
        <!-- appender 目标地址 Logstash 的端口 -->
        <destination>127.0.0.1:5044</destination>
        <!-- 日志输出编码 对log信息做一个encoder -->
        <encoder
                class="net.logstash.logback.encoder.LoggingEventCompositeJsonEncoder">
            <providers>
                <timestamp>
                    <!--标准的 UTC timeZone-->
                    <timeZone>UTC</timeZone>
                </timestamp>
                <pattern>

                    <pattern>
                        {
                        <!-- log的级别 -->
                        "severity": "%level",
                        <!-- service的名称 -->
                        "service": "${springAppName:-}",
                        <!-- trace id -->
                        "trace": "%X{X-B3-TraceId:-}",
                        <!-- span id -->
                        "span": "%X{X-B3-SpanId:-}",
                        "exportable": "%X{X-Span-Export:-}",
                        "pid": "${PID:-}",
                        <!-- 线程的名称 -->
                        "thread": "%thread",
                        "class": "%logger{40}",
                        <!-- 真实的log信息 -->
                        "rest": "%message"
                        }
                    </pattern>
                </pattern>
            </providers>
        </encoder>
    </appender>

    <!-- 日志输出级别 -->
    <root level="INFO">
        <appender-ref ref="console" />
        <!-- 让logstash 起作用 输出到root节点下 -->
        <appender-ref ref="logstash" />
    </root>

</configuration>
```

![](https://tcs.teambition.net/storage/3122bc49347c4080a90ff5e61d88f58a0902?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIzMCwiaWF0IjoxNjEyMTkwNDMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJiYzQ5MzQ3YzQwODBhOTBmZjVlNjFkODhmNThhMDkwMiJ9.qGtX-h8dKvhaI4z-p5oDkkDI6z5OaBdJ7nglD6hcfCo&download=image.png "")

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

    <artifactId>sleuth-traceB</artifactId>

    <dependencies>
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-client</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-web</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-actuator</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-sleuth</artifactId>
        </dependency>

        <!-- Zipkin -->
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-zipkin</artifactId>
        </dependency>

        <!-- Logstash for ELK -->
        <dependency>
            <groupId>net.logstash.logback</groupId>
            <artifactId>logstash-logback-encoder</artifactId>
            <version>5.2</version>
        </dependency>

    </dependencies>

</project>
```

![](https://tcs.teambition.net/storage/3122c2e9ba005f0804d95f77dc3f383fc616?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIzMCwiaWF0IjoxNjEyMTkwNDMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJjMmU5YmEwMDVmMDgwNGQ5NWY3N2RjM2YzODNmYzYxNiJ9.8xNrLhb23y4w5eHTmgZ7KL93QhYYe-MQr5y6thbqs2Q&download=image.png "")

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!--该日志将日志级别不同的log信息保存到不同的文件中 -->
<configuration>
    <include resource="org/springframework/boot/logging/logback/defaults.xml" />

    <springProperty scope="context" name="springAppName"
                    source="spring.application.name" />

    <!-- 日志输出位置 -->
    <property name="LOG_FILE" value="${BUILD_FOLDER:-build}/${springAppName}" />

    <!-- 日志格式 -->
    <property name="CONSOLE_LOG_PATTERN"
              value="%clr(%d{HH:mm:ss.SSS}){faint} %clr(${LOG_LEVEL_PATTERN:-%5p}) %clr(${PID:- }){magenta} %clr(---){faint} %clr([%15.15t]){faint} %m%n${LOG_EXCEPTION_CONVERSION_WORD:-%wEx}}" />

    <!-- 控制台输出 -->
    <appender name="console" class="ch.qos.logback.core.ConsoleAppender">
        <filter class="ch.qos.logback.classic.filter.ThresholdFilter">
            <level>INFO</level>
        </filter>
        <!-- 日志输出编码 -->
        <encoder>
            <pattern>${CONSOLE_LOG_PATTERN}</pattern>
            <charset>utf8</charset>
        </encoder>
    </appender>

    <!-- 在log 文件 每一个输出都是一个appender -->
    <!-- Logstash -->
    <!-- 为logstash输出的JSON格式的Appender -->
    <appender name="logstash"
              class="net.logstash.logback.appender.LogstashTcpSocketAppender">
        <!-- appender 目标地址 Logstash 的端口 -->
        <destination>127.0.0.1:5044</destination>
        <!-- 日志输出编码 对log信息做一个encoder -->
        <encoder
                class="net.logstash.logback.encoder.LoggingEventCompositeJsonEncoder">
            <providers>
                <timestamp>
                    <!--标准的 UTC timeZone-->
                    <timeZone>UTC</timeZone>
                </timestamp>
                <pattern>

                    <pattern>
                        {
                        <!-- log的级别 -->
                        "severity": "%level",
                        <!-- service的名称 -->
                        "service": "${springAppName:-}",
                        <!-- trace id -->
                        "trace": "%X{X-B3-TraceId:-}",
                        <!-- span id -->
                        "span": "%X{X-B3-SpanId:-}",
                        "exportable": "%X{X-Span-Export:-}",
                        "pid": "${PID:-}",
                        <!-- 线程的名称 -->
                        "thread": "%thread",
                        "class": "%logger{40}",
                        <!-- 真实的log信息 -->
                        "rest": "%message"
                        }
                    </pattern>
                </pattern>
            </providers>
        </encoder>
    </appender>

    <!-- 日志输出级别 -->
    <root level="INFO">
        <appender-ref ref="console" />
        <!-- 让logstash 起作用 输出到root节点下 -->
        <appender-ref ref="logstash" />
    </root>

</configuration>
```

![](https://tcs.teambition.net/storage/3122e24f66fdf513add8d04af5eb3db3e8e4?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIzMCwiaWF0IjoxNjEyMTkwNDMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJlMjRmNjZmZGY1MTNhZGQ4ZDA0YWY1ZWIzZGIzZThlNCJ9.9VVd2-uXmbovG2g9RehbOqK3MouRioRcIA2qicErG4Q&download=image.png "")

启动

这个就像代号一样 

![](https://tcs.teambition.net/storage/3122b8ec3ef1483d4c1090625fa3ec166d5c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIzMCwiaWF0IjoxNjEyMTkwNDMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJiOGVjM2VmMTQ4M2Q0YzEwOTA2MjVmYTNlYzE2NmQ1YyJ9.u6pfx4SevkC9VVuBvpTYKn_J6IojT75mK2Us9yZv5eo&download=image.png "")

打印 log 具体信息

![](https://tcs.teambition.net/storage/3122613ef078c992378b1b265b123f1911fe?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIzMCwiaWF0IjoxNjEyMTkwNDMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI2MTNlZjA3OGM5OTIzNzhiMWIyNjViMTIzZjE5MTFmZSJ9.LVn-2AzV_nT_eKLOWztv2LZnERZAMVD_BZecAZvzxu8&download=image.png "")

key id 1590

![](https://tcs.teambition.net/storage/312293ac12c77511618e5eb2478a3e5d7691?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIzMCwiaWF0IjoxNjEyMTkwNDMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5M2FjMTJjNzc1MTE2MThlNWViMjQ3OGEzZTVkNzY5MSJ9.dHC6WS7UaPQTr53Ewc75EDYSGR45gQMzGdLtCZ54e_4&download=image.png "")

![](https://tcs.teambition.net/storage/3122cd44adc374308b6c12b0653f64657296?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIzMCwiaWF0IjoxNjEyMTkwNDMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJjZDQ0YWRjMzc0MzA4YjZjMTJiMDY1M2Y2NDY1NzI5NiJ9.k5A7Tz20dppGJsbN4tokn30paMJlaK8cSeTZZcTz0WA&download=image.png "")

![](https://tcs.teambition.net/storage/3122fba79e9cca7b5b23a4607dbf65396270?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIzMCwiaWF0IjoxNjEyMTkwNDMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJmYmE3OWU5Y2NhN2I1YjIzYTQ2MDdkYmY2NTM5NjI3MCJ9.9ntbs5lf-GjHhQ8KezxE10d7lnh85oHQey3GgPrmG30&download=image.png "")

![](https://tcs.teambition.net/storage/3122a3c59f52072e44893baf8b39742258dc?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIzMCwiaWF0IjoxNjEyMTkwNDMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhM2M1OWY1MjA3MmU0NDg5M2JhZjhiMzk3NDIyNThkYyJ9.qP6_515P8OXPqik6ZbCz2Smbm3ENCamLWPm9EaNnWZI&download=image.png "")

![](https://tcs.teambition.net/storage/312237686f7bb4aefc63849549c0f38431f1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIzMCwiaWF0IjoxNjEyMTkwNDMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzNzY4NmY3YmI0YWVmYzYzODQ5NTQ5YzBmMzg0MzFmMSJ9._F1NuFiCBnAIZnPB4ZJbBDyhDNtlR965Nq5-I3LGEKs&download=image.png "")

```text
0331517ff2053bd6

```

![](https://tcs.teambition.net/storage/3122daa1fa6b5c4f5e33ff6cf89eec5ae342?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIzMCwiaWF0IjoxNjEyMTkwNDMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkYWExZmE2YjVjNGY1ZTMzZmY2Y2Y4OWVlYzVhZTM0MiJ9.tHXL5KGa_TPQE3k0PQ-UINhuhCH1Qso5n9Dfa24ursw&download=image.png "")

![](https://tcs.teambition.net/storage/31221caf490b4d6e76af52e7bccf3536a074?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIzMCwiaWF0IjoxNjEyMTkwNDMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxY2FmNDkwYjRkNmU3NmFmNTJlN2JjY2YzNTM2YTA3NCJ9.vFJ4AVsGJk7RhRR8_yC_xx25XzN8VO1UpU6fQCnKQ94&download=image.png "")

![](https://tcs.teambition.net/storage/3122a020b9f0d485b4fee2fbe003674001cf?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIzMCwiaWF0IjoxNjEyMTkwNDMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhMDIwYjlmMGQ0ODViNGZlZTJmYmUwMDM2NzQwMDFjZiJ9.MuoyHRZb8nRHFu5iQ5pRXvqwCvsHX_jGa39AEunP_p4&download=image.png "")

显示了多次 在所有的链路追踪系统中 有一个非常重要的属性 叫 _index 是我们创建的搜索索引

那么你的一行 log 有可能被匹配到多个索引 当中 

要指定index



根据属性名称搜索

![](https://tcs.teambition.net/storage/312299a35e53d99afa8669d30e47588df903?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIzMCwiaWF0IjoxNjEyMTkwNDMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5OWEzNWU1M2Q5OWFmYTg2NjlkMzBlNDc1ODhkZjkwMyJ9.LwkD9lNTpxTwWSxFzr0x5dS13Y4GYMYsfw9oZ_DOxTk&download=image.png "")

![](https://tcs.teambition.net/storage/312290e1be553c7c3ef6a44dbd6d0f29664a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIzMCwiaWF0IjoxNjEyMTkwNDMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5MGUxYmU1NTNjN2MzZWY2YTQ0ZGJkNmQwZjI5NjY0YSJ9.b5pG1S6wktEYVDDWRo7v_uPkfsCTozN-OSu56kqiNms&download=image.png "")

复杂搜索

![](https://tcs.teambition.net/storage/3122dcdef6f05332a7393e823df40befed9c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIzMCwiaWF0IjoxNjEyMTkwNDMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkY2RlZjZmMDUzMzJhNzM5M2U4MjNkZjQwYmVmZWQ5YyJ9.CfhR2mJ44lnH-jj4JzujjsuD7dcHWlT1zfyHqRNesPU&download=image.png "")

缩短时间

![](https://tcs.teambition.net/storage/312213612aab974a579a68e19fa3a15668f7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIzMCwiaWF0IjoxNjEyMTkwNDMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxMzYxMmFhYjk3NGE1NzlhNjhlMTlmYTNhMTU2NjhmNyJ9.TO_xeLz9fLfI0wa00rfWpIn7Fp7WIlCwBmu4yDVRbsM&download=image.png "")

常用查询需求可以创建一个 

![](https://tcs.teambition.net/storage/312268d52aad3b0a15eac4d0967eae86370f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIzMCwiaWF0IjoxNjEyMTkwNDMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI2OGQ1MmFhZDNiMGExNWVhYzRkMDk2N2VhZTg2MzcwZiJ9.RGE8ExrbI333AeiJiYcAigbKoEmoA4o4scCxVPlPOmQ&download=image.png "")

![](https://tcs.teambition.net/storage/31222d1ffa96472982754f140776caea7ef4?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIzMCwiaWF0IjoxNjEyMTkwNDMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIyZDFmZmE5NjQ3Mjk4Mjc1NGYxNDA3NzZjYWVhN2VmNCJ9.KsGzg_LPCq93ytEIJz91kjBtUynxkFouzapK-MElEl0&download=image.png "")

![](https://tcs.teambition.net/storage/31220f7b3daad848cf762c2ce799f7721071?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIzMCwiaWF0IjoxNjEyMTkwNDMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIwZjdiM2RhYWQ4NDhjZjc2MmMyY2U3OTlmNzcyMTA3MSJ9.4IJ4JkoeBogNdIU5WK_ovsFC4yje9P8chILKTjuJXPc&download=image.png "")

![](https://tcs.teambition.net/storage/3122e4c54866ff1a02a94449b1fa6396f325?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIzMCwiaWF0IjoxNjEyMTkwNDMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJlNGM1NDg2NmZmMWEwMmE5NDQ0OWIxZmE2Mzk2ZjMyNSJ9.jk13dGtzDdIKlFwGWSdSJ4Ab21eNeyt1X38nCfDbQnU&download=image.png "")

![](https://tcs.teambition.net/storage/3122b012a2d970dd971d944dcf20d98c349c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIzMCwiaWF0IjoxNjEyMTkwNDMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJiMDEyYTJkOTcwZGQ5NzFkOTQ0ZGNmMjBkOThjMzQ5YyJ9.2IQdt6VqzTPzSikUwL-XFasGdYUhmj7wCu9Qr2ODCbM&download=image.png "")

![](https://tcs.teambition.net/storage/312245a10056f76f0d8e667b796d935d7f5e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIzMCwiaWF0IjoxNjEyMTkwNDMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI0NWExMDA1NmY3NmYwZDhlNjY3Yjc5NmQ5MzVkN2Y1ZSJ9.EIBpTzDyd8iXrvMQ0AKk9HpABzc_1SY4HVUI2euFFJQ&download=image.png "")



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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIzMCwiaWF0IjoxNjEyMTkwNDMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.a5XGlONSEWHnwexC44ebUHfASbFnnEXv6goDy5TNatY&download=image.png "")

