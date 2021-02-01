![](https://tcs.teambition.net/storage/312240188ce978f0bc91acb045d1b40b2270?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI2NywiaWF0IjoxNjEyMTkwNDY3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI0MDE4OGNlOTc4ZjBiYzkxYWNiMDQ1ZDFiNDBiMjI3MCJ9.QDQ83E1Ej6C8QpFQ-jgL1t7ru-OS-M0PrU3LV4_4_Qo&download=2020-09-17%20061148.png "")

![](https://tcs.teambition.net/storage/312215450ab8d3cf5eee994f328bc86d4cd8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI2NywiaWF0IjoxNjEyMTkwNDY3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxNTQ1MGFiOGQzY2Y1ZWVlOTk0ZjMyOGJjODZkNGNkOCJ9.CT1_6ZSHKKSUTowAHNPrKrupK_TfanWxTOQVKz03uy4&download=2020-09-17%20061218.png "")

![](https://tcs.teambition.net/storage/3122b52612d3eb3f21bbe84c80f3ab976f4d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI2NywiaWF0IjoxNjEyMTkwNDY3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJiNTI2MTJkM2ViM2YyMWJiZTg0YzgwZjNhYjk3NmY0ZCJ9.tNGn-hUZgDBBuPtxjYKes-P0z3OYFpVFjhDZBw0Sc5w&download=image.png "")

![](https://tcs.teambition.net/storage/31222e82761e6a21ff90aa3058f2f0851c8b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI2NywiaWF0IjoxNjEyMTkwNDY3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIyZTgyNzYxZTZhMjFmZjkwYWEzMDU4ZjJmMDg1MWM4YiJ9.INAdpaP63iziLCweHC4oVcxvk782uZF_JdFIxGEwpiE&download=image.png "")

![](https://tcs.teambition.net/storage/3122f8d2d370bf084ac0a5852eb9a48ebe52?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI2NywiaWF0IjoxNjEyMTkwNDY3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJmOGQyZDM3MGJmMDg0YWMwYTU4NTJlYjlhNDhlYmU1MiJ9.vIJxKllsUZVyB-pauIM0AcZtnA15QEWjoTZ0mTBxD7U&download=image.png "")

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
    </dependencies>

    <build>
        <plugins>
            <plugin>
                <groupId>org.springframework.boot</groupId>
                <artifactId>spring-boot-maven-plugin</artifactId>
                <configuration>
                    <mainClass></mainClass>
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

![](https://tcs.teambition.net/storage/31221a97f1bf2be594329d2130daefe1d574?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI2NywiaWF0IjoxNjEyMTkwNDY3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxYTk3ZjFiZjJiZTU5NDMyOWQyMTMwZGFlZmUxZDU3NCJ9.SwcGxq_ukUbT1tyB_NSg8p68A0DQmMufg2nOP-fcSuw&download=image.png "")

```text
spring.application.name=zipkin-server
server.port=62100

spring.main.allow-bean-definition-overriding=true

eureka.client.serviceUrl.defaultZone=http://localhost:20000/eureka/

# 在后台启动窗口的时候 禁止看到错误日志
management.metrics.web.server.auto-time-requests=false

```

![](https://tcs.teambition.net/storage/3122a2b92a01b7a34c028c66692082b363b2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI2NywiaWF0IjoxNjEyMTkwNDY3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhMmI5MmEwMWI3YTM0YzAyOGM2NjY5MjA4MmIzNjNiMiJ9.bfBfBAvLiN5O_JUQ1EgcD84-skn5RTbEhavtSv4E1Tc&download=image.png "")

```java
package com.imooc.springcloud;

import org.springframework.boot.WebApplicationType;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.builder.SpringApplicationBuilder;
import zipkin.server.internal.EnableZipkinServer;


@SpringBootApplication
// 开启 ZipkinServer 服务端 自动装配
@EnableZipkinServer
public class ZipkinApplication {

    public static void main(String[] args) {
        new SpringApplicationBuilder(ZipkinApplication.class)
                .web(WebApplicationType.SERVLET)
                .run(args);
    }
}

```

启动

![](https://tcs.teambition.net/storage/31221d53d6bec8fdd7240143243217eb3f04?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI2NywiaWF0IjoxNjEyMTkwNDY3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxZDUzZDZiZWM4ZmRkNzI0MDE0MzI0MzIxN2ViM2YwNCJ9.MaAYW29SklSoKtO4-0Ba80jfefQsj05siG8iPc3IgqU&download=image.png "")

![](https://tcs.teambition.net/storage/312263dfaa56d529c1a4515d525d37d6ab0a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI2NywiaWF0IjoxNjEyMTkwNDY3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI2M2RmYWE1NmQ1MjljMWE0NTE1ZDUyNWQzN2Q2YWIwYSJ9.6dJ2MMo4X4XdgjidCLDTVW5hJSpkTcH6HSaM9OvzTjQ&download=image.png "")

![](https://tcs.teambition.net/storage/312219909a49e8c8250d5fdd438a9ff714d5?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI2NywiaWF0IjoxNjEyMTkwNDY3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxOTkwOWE0OWU4YzgyNTBkNWZkZDQzOGE5ZmY3MTRkNSJ9.TjU8zC5ABTxIodNAAMtww95G3vPMfcdpoSqswrEpcuc&download=image.png "")





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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI2NywiaWF0IjoxNjEyMTkwNDY3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.MsHZanM9T7UaMPEaiftKXTKZ8LHPg0A8JPRJ_1n38G4&download=image.png "")

