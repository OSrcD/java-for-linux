![](https://tcs.teambition.net/storage/312149c941f4e8dc01c944828325f950755c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU2NSwiaWF0IjoxNjEyMTkwNzY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0OWM5NDFmNGU4ZGMwMWM5NDQ4MjgzMjVmOTUwNzU1YyJ9.HaTSPPADLgylhqZ2Mv_Y1POJP6riUVzW_RWIGuUK4mo&download=image.png "")

![](https://tcs.teambition.net/storage/31217467ab895ff56c21c10c9aa781ac3892?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU2NSwiaWF0IjoxNjEyMTkwNzY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3NDY3YWI4OTVmZjU2YzIxYzEwYzlhYTc4MWFjMzg5MiJ9.Zt9YArdACZe05_1RGiBhT9dY6eu1Q98YV76qx9f5rH8&download=image.png "")

![](https://tcs.teambition.net/storage/3121082f847fff26ec6dcc6e5d14d48a47e7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU2NSwiaWF0IjoxNjEyMTkwNzY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwODJmODQ3ZmZmMjZlYzZkY2M2ZTVkMTRkNDhhNDdlNyJ9.OzwkRNFhbt8WLRcF2svdv_2xGfu9y8rcz8xPgBqiTps&download=image.png "")

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

    <artifactId>config-server</artifactId>

    <dependencies>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-config-server</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-client</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-actuator</artifactId>
        </dependency>
    </dependencies>

    <build>
        <plugins>
            <plugin>
                <groupId>org.springframework.boot</groupId>
                <artifactId>spring-boot-maven-plugin</artifactId>
                <configuration>
                    <mainClass>com.imooc.ConfigServerApplication</mainClass>
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

![](https://tcs.teambition.net/storage/3121066c987bb0c0cc02619cec86db2e9514?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU2NSwiaWF0IjoxNjEyMTkwNzY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwNjZjOTg3YmIwYzBjYzAyNjE5Y2VjODZkYjJlOTUxNCJ9.cKhsEQ5C0QcD_3PbTJSxkmwaDEurbDlt1Ll9rXWdgaA&download=image.png "")

```java
package com.imooc;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.WebApplicationType;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.builder.SpringApplicationBuilder;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import org.springframework.cloud.config.server.EnableConfigServer;

@SpringBootApplication
@EnableConfigServer
@EnableDiscoveryClient
public class ConfigServerApplication {

    public static void main(String[] args) {
        new SpringApplicationBuilder(ConfigServerApplication.class)
                .web(WebApplicationType.SERVLET)
                .run();
    }
}

```

![](https://tcs.teambition.net/storage/312169e44a7fd20ea0f07e7ff3334c0edf7b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU2NSwiaWF0IjoxNjEyMTkwNzY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2OWU0NGE3ZmQyMGVhMGYwN2U3ZmYzMzM0YzBlZGY3YiJ9.WJgrBeEPT7pyh-7rKAZnCZf6CP5WQV06ZFd0n_3jwu4&download=image.png "")

```yaml
encrypt:
  key: superNewBee
  
```



![](https://tcs.teambition.net/storage/3121460eb21a949c5e2eecf363f2a7ad51db?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU2NSwiaWF0IjoxNjEyMTkwNzY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0NjBlYjIxYTk0OWM1ZTJlZWNmMzYzZjJhN2FkNTFkYiJ9.RyJYB3MY-euvXpBhU7dbbcPsiGizEKW_-hhHtwSu7-I&download=image.png "")

![](https://tcs.teambition.net/storage/31218305d56ad3b45665e0f524e9e80e7741?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU2NSwiaWF0IjoxNjEyMTkwNzY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4MzA1ZDU2YWQzYjQ1NjY1ZTBmNTI0ZTllODBlNzc0MSJ9.1XbAkYVK4XIDtSs6SbwbtXg4OPy8WRxynpjxo8bMpqI&download=image.png "")

```yaml
server:
  port: 20003


spring:
  application:
    name: config-server

  cloud:
    config:
      server:
        overrides:
          # 属性重载 也就是把属性覆盖掉吧
          test: mytest
        git:
          uri: https://github.com/OSrcD/config-repo.git
          force-pull: true
          # 在主目录创建不同的文件夹 管理配置文件
          # 将配置文件放到接入方服务名称对应文件夹下
          search-paths: '{application}'
          # username:
          # password:

eureka:
  client:
    serviceUrl:
      defaultZone: http://localhost:20000/eureka/

## 开启所有actuator-endpoint
management:
  endpoint:
    health:
      show-details: always
  endpoints:
    web:
      exposure:
        include: '*'
  security:
    enabled: false
```

![](https://tcs.teambition.net/storage/3121b931d44978fcc69c2bcbfeab341346e1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU2NSwiaWF0IjoxNjEyMTkwNzY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiOTMxZDQ0OTc4ZmNjNjljMmJjYmZlYWIzNDEzNDZlMSJ9.GjkSFejxqgZmFTXwi1zj7wLtr1KrpaMGMqfvp-WWKGI&download=image.png "")

![](https://tcs.teambition.net/storage/31214ff1888f09faaa8fd6ebc9b63dbe103e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU2NSwiaWF0IjoxNjEyMTkwNzY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0ZmYxODg4ZjA5ZmFhYThmZDZlYmM5YjYzZGJlMTAzZSJ9.iPmKYX6aCT3UDTlVz6suSif5OjspvVRAlbsoyQxp0RY&download=image.png "")

![](https://tcs.teambition.net/storage/3121f37f372229a87ee4416aa6fc00893b3b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU2NSwiaWF0IjoxNjEyMTkwNzY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmMzdmMzcyMjI5YTg3ZWU0NDE2YWE2ZmMwMDg5M2IzYiJ9.Roaafd7FhK1yp2SfbyrK08XZ6Itzy5kwbCn3oRUU3M8&download=image.png "")

![](https://tcs.teambition.net/storage/3121155dc604e2c41132a491b7b3e7b0422a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU2NSwiaWF0IjoxNjEyMTkwNzY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExNTVkYzYwNGUyYzQxMTMyYTQ5MWI3YjNlN2IwNDIyYSJ9.MktRgeZQTeGaE-hclnD8HDMnKxnZyr0z0TfNjo_JPcw&download=image.png "")

```yaml
server:
  port: 20003


spring:
  application:
    name: config-server

  cloud:
    config:
      server:
        overrides:
          # 属性重载 也就是把属性覆盖掉吧
          test: mytest
        git:
          uri: https://github.com/OSrcD/foodie-cloud-config.git
          force-pull: true
          # 在主目录创建不同的文件夹 管理配置文件
          # 将配置文件放到接入方服务名称对应文件夹下
          search-paths: '{application}'
          # username:
          # password:

eureka:
  client:
    serviceUrl:
      defaultZone: http://localhost:20000/eureka/

## 开启所有actuator-endpoint
management:
  endpoint:
    health:
      show-details: always
  endpoints:
    web:
      exposure:
        include: '*'
  security:
    enabled: false
```

![](https://tcs.teambition.net/storage/3121665d6f01dd6c1f2f5561e85a6d448772?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU2NSwiaWF0IjoxNjEyMTkwNzY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2NjVkNmYwMWRkNmMxZjJmNTU2MWU4NWE2ZDQ0ODc3MiJ9.xImmblCUWFbHQnoa9NuOSraraA8UeRfApdewPKDG4AQ&download=image.png "")

```json
{
    "name": "foodie-search",
    "profiles": [
        "dev"
    ],
    "label": "main",
    "version": "e8879e46238bdc445376fa8713da3e99211dfcba",
    "state": null,
    "propertySources": [
        {
            "name": "overrides",
            "source": {
                "test": "mytest"
            }
        },
        {
            "name": "https://github.com/OSrcD/foodie-cloud-config.git/foodie-search/foodie-search-dev.yml",
            "source": {
                "search.enabled": true
            }
        }
    ]
}

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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU2NSwiaWF0IjoxNjEyMTkwNzY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.lqv_lI_EwGeVZN1l9ePfh_HFnQ-xm49toVLus9XFQNU&download=image.png "")

