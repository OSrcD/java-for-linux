![](https://tcs.teambition.net/storage/31223bb438f3b17db8666ab0112a2457af23?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIyNCwiaWF0IjoxNjEyMTkwNDI0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzYmI0MzhmM2IxN2RiODY2NmFiMDExMmEyNDU3YWYyMyJ9.YvgPSDSj_hk1lXhLgtVLlp6r_gFbzjkSVkY90BZaMG4&download=image.png "")

![](https://tcs.teambition.net/storage/3122e8ad9e4a5fcbc95a61b97b5386058020?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIyNCwiaWF0IjoxNjEyMTkwNDI0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJlOGFkOWU0YTVmY2JjOTVhNjFiOTdiNTM4NjA1ODAyMCJ9.66uAZbT3Vx2gAC3XYsLfEbCXOmP5jUA87EvZP191w_s&download=image.png "")

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

    <artifactId>zipkin-server</artifactId>

    <dependencies>
        <dependency>
            <groupId>io.zipkin.java</groupId>
            <artifactId>zipkin-server</artifactId>
            <version>2.8.4</version>
        </dependency>

        <dependency>
            <groupId>io.zipkin.java</groupId>
            <artifactId>zipkin-autoconfigure-ui</artifactId>
            <version>2.8.4</version>
        </dependency>

        <!-- 高可用 -->
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-client</artifactId>
        </dependency>

        <!-- WEB -->
        <!-- 也可以通过rabbitmq接收客户端信息 -->
        <!-- zipkin-autoconfigure-collector-rabbitmq -->
        <!-- 也可以借助ES来保存信息 -->
        <!-- zipkin-autoconfigure-storage-elasticsearch-http -->
    </dependencies>

    <build>
        <plugins>
            <plugin>
                <groupId>org.springframework.boot</groupId>
                <artifactId>spring-boot-maven-plugin</artifactId>
                <configuration>
                    <mainClass>com.imooc.ZipkinApplication</mainClass>
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

![](https://tcs.teambition.net/storage/31221e3a43330da9fe6d6914069e8ddfecaa?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIyNCwiaWF0IjoxNjEyMTkwNDI0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxZTNhNDMzMzBkYTlmZTZkNjkxNDA2OWU4ZGRmZWNhYSJ9.IyEkm209eK_OZzbqVGf7nfjPwW2sGFITuQvIJVbJP7U&download=image.png "")

```java
package com.imooc;

import org.springframework.boot.WebApplicationType;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.builder.SpringApplicationBuilder;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import zipkin.server.internal.EnableZipkinServer;

@SpringBootApplication
@EnableZipkinServer
@EnableDiscoveryClient
public class ZipkinApplication {

    public static void main(String[] args) {
        new SpringApplicationBuilder(ZipkinApplication.class)
                .web(WebApplicationType.SERVLET)
                .run(args);
    }
}

```

![](https://tcs.teambition.net/storage/31227ac94ee02ff5d032d871efa0d09d7fe8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIyNCwiaWF0IjoxNjEyMTkwNDI0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI3YWM5NGVlMDJmZjVkMDMyZDg3MWVmYTBkMDlkN2ZlOCJ9.U11tC2gFoSQ3Cb7HmYWSBGMMAKGuKeOWh-KbT6tnytQ&download=image.png "")

```yaml
spring:
  application:
    name: zipkin-server
  main:
    allow-bean-definition-overriding: true

server:
  port: 20005

############################################################
#
# Eureka注册中心
#
############################################################
eureka:
  client:
    serviceUrl:
      defaultZone: http://localhost:20000/eureka/

management:
  metrics:
    web:
      server:
        auto-time-requests: false


```

zipkin 是接收客户端发来的信息的

客户端通过 http 这些信息 发送给zipkin

也可以使用消息队列

![](https://tcs.teambition.net/storage/31222408aff52c083ea9eebc461dc347a099?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIyNCwiaWF0IjoxNjEyMTkwNDI0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIyNDA4YWZmNTJjMDgzZWE5ZWViYzQ2MWRjMzQ3YTA5OSJ9.9AFSGce_WDmf3rqBlengarlJ8gP19Vzqbsj4997ngjE&download=image.png "")

![](https://tcs.teambition.net/storage/3122d01902856ef9f5514845f981cba8953a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIyNCwiaWF0IjoxNjEyMTkwNDI0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkMDE5MDI4NTZlZjlmNTUxNDg0NWY5ODFjYmE4OTUzYSJ9.IZVa9HuTgETAuIi_Ye8fIyU7cK_MrCK4KrNkuVaGs0c&download=image.png "")

![](https://tcs.teambition.net/storage/3122b860350732aa564e909311467504f4bb?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIyNCwiaWF0IjoxNjEyMTkwNDI0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJiODYwMzUwNzMyYWE1NjRlOTA5MzExNDY3NTA0ZjRiYiJ9.bMFx19vBIfgbvIpdlUrJEQeOUu-xIaieVJWB5w2nOcI&download=image.png "")

![](https://tcs.teambition.net/storage/312233911e227cdf969727a8adb6ee61eb28?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIyNCwiaWF0IjoxNjEyMTkwNDI0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzMzkxMWUyMjdjZGY5Njk3MjdhOGFkYjZlZTYxZWIyOCJ9.2by3cY0eNwV1C0YaWaFRofvA-9uaY33RipC2lYcNv4U&download=image.png "")



 启动

![](https://tcs.teambition.net/storage/3122fdfc651d660ebca3524efd10120ed66a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIyNCwiaWF0IjoxNjEyMTkwNDI0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJmZGZjNjUxZDY2MGViY2EzNTI0ZWZkMTAxMjBlZDY2YSJ9.HI1Y-Kb0JFQoGeXmDVxR74H3s0yoNaciQ4NBlVmlXQE&download=image.png "")

![](https://tcs.teambition.net/storage/3122dcc3207f831ebc252f826ce919291ba3?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIyNCwiaWF0IjoxNjEyMTkwNDI0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkY2MzMjA3ZjgzMWViYzI1MmY4MjZjZTkxOTI5MWJhMyJ9.MXWJKL4WcteV6I_rBJ48V8KzA0LIbDGzHOe2SzUeVRw&download=image.png "")

![](https://tcs.teambition.net/storage/312237ebe671fdd69c661b6fda1a0db4a7b1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIyNCwiaWF0IjoxNjEyMTkwNDI0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzN2ViZTY3MWZkZDY5YzY2MWI2ZmRhMWEwZGI0YTdiMSJ9.JAbdSaHXKr_qHeyEbz2lFQPfM5DSuK_OUXbOuQOmp1s&download=image.png "")







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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIyNCwiaWF0IjoxNjEyMTkwNDI0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.9Vfd6zYCrdThCxzYyPnRCu53s10-ahYO4ankB_DUk14&download=image.png "")

