![](https://tcs.teambition.net/storage/31213be01d593407ca3a8e0bc2c8b86c7e7b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTcxNSwiaWF0IjoxNjEyMTkwOTE1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzYmUwMWQ1OTM0MDdjYTNhOGUwYmMyYzhiODZjN2U3YiJ9.e-e1UslJkRGhUeQbZpycckv2K55rM2vx_kR8YHCup9k&download=image.png "")

![](https://tcs.teambition.net/storage/3121ad208a72d00175b13fee1061c6d7560a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTcxNSwiaWF0IjoxNjEyMTkwOTE1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZDIwOGE3MmQwMDE3NWIxM2ZlZTEwNjFjNmQ3NTYwYSJ9.NNCKAoBKEX99QcNkTA4csp9Lc21DduokhkFGNJxQTPM&download=image.png "")

![](https://tcs.teambition.net/storage/3121c3df9b2d3c490104a5efcf70d2a8e12f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTcxNSwiaWF0IjoxNjEyMTkwOTE1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjM2RmOWIyZDNjNDkwMTA0YTVlZmNmNzBkMmE4ZTEyZiJ9.qkPkxspOI-ekhj5g1KqAymdUSaRtSD5I5a-AbOfD8cU&download=image.png "")

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

    <artifactId>hystrix-turbine</artifactId>

    <properties>
        <maven.compiler.source>8</maven.compiler.source>
        <maven.compiler.target>8</maven.compiler.target>
    </properties>


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
            <artifactId>spring-cloud-starter-netflix-hystrix</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-turbine</artifactId>
        </dependency>

    </dependencies>

    <build>
        <plugins>
            <plugin>
                <groupId>org.springframework.boot</groupId>
                <artifactId>spring-boot-maven-plugin</artifactId>
                <configuration>
                    <mainClass>com.imooc.HystrixTurbineApplication</mainClass>
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

![](https://tcs.teambition.net/storage/312136427095bdcf41d813ecba12dd55ddac?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTcxNSwiaWF0IjoxNjEyMTkwOTE1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzNjQyNzA5NWJkY2Y0MWQ4MTNlY2JhMTJkZDU1ZGRhYyJ9.-rTyVLEnDRIUh6cQ7O4_vv8ecmzIDolhP-RgzfBt-Yw&download=image.png "")

```java
package com.imooc;

import org.springframework.boot.WebApplicationType;
import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.boot.builder.SpringApplicationBuilder;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import org.springframework.cloud.netflix.turbine.EnableTurbine;


@EnableDiscoveryClient
@EnableTurbine
@EnableAutoConfiguration
public class HystrixTurbineApplication {

    public static void main(String[] args) {
        new SpringApplicationBuilder(HystrixTurbineApplication.class)
                .web(WebApplicationType.SERVLET)
                .run(args);
    }

}

```

如果我们Spring cloud 微服务 在我们服务提供者 做服务注册的时候 在Eureka注册信息 当中 配置了元数据 Metadata 来 指定了 它的集群 哪我们这里就可以根据 服务提供者 的元数据 配置 来指定 相应的聚合逻辑 我们这里只有一个单节点的服务集群 

![](https://tcs.teambition.net/storage/3121e5353ced1a647d04af358103cfd59327?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTcxNSwiaWF0IjoxNjEyMTkwOTE1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlNTM1M2NlZDFhNjQ3ZDA0YWYzNTgxMDNjZmQ1OTMyNyJ9.AKVebJrmJ7cLZ7cERtIG742wTDMW2EWV6lOwA0E3cyg&download=image.png "")

![](https://tcs.teambition.net/storage/3121c03bd6fae60b0dc0c9daa3bf93cfe335?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTcxNSwiaWF0IjoxNjEyMTkwOTE1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjMDNiZDZmYWU2MGIwZGMwYzlkYWEzYmY5M2NmZTMzNSJ9.Ex2HZDOGoONu8QbaRATYQsRU6F2fDDj8PkBUdi5lutI&download=image.png "")

![](https://tcs.teambition.net/storage/3121708818cc4d5cf0661776afb667291ccf?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTcxNSwiaWF0IjoxNjEyMTkwOTE1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3MDg4MThjYzRkNWNmMDY2MTc3NmFmYjY2NzI5MWNjZiJ9.IAwLn1kaPYPdycUnpksnqywJ8d3w-zbr1QdLigx3XQE&download=image.png "")

在服务注册的时候 自己去定义一个元数据 metadata-map 是一个可扩展的结构 

服务器提供者 做了这样的配置 并且 我们想把它 读取出来 

![](https://tcs.teambition.net/storage/3121588c6b6559161f82f9cc0e2f14b730f1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTcxNSwiaWF0IjoxNjEyMTkwOTE1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1ODhjNmI2NTU5MTYxZjgyZjljYzBlMmYxNGI3MzBmMSJ9.DzWDsTFLzoBUNEOA58MujBrkasslWZykdObJH2URvW8&download=image.png "")

可以聚合多个集群的Hystrix多个调用信息

![](https://tcs.teambition.net/storage/3121928f8c66a342090b45821909a432d219?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTcxNSwiaWF0IjoxNjEyMTkwOTE1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5MjhmOGM2NmEzNDIwOTBiNDU4MjE5MDlhNDMyZDIxOSJ9.HWnbO2rBBtnG1igKkrUCvof-rJsL4mYKLQ-qlnfm5p4&download=image.png "")

![](https://tcs.teambition.net/storage/31210fcdaf38984db4008428e88ca66e8cec?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTcxNSwiaWF0IjoxNjEyMTkwOTE1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwZmNkYWYzODk4NGRiNDAwODQyOGU4OGNhNjZlOGNlYyJ9.LFwfRjIVaRESVODiQvD3yDDN8FdMmGL2XtGwVj9b-w4&download=image.png "")

![](https://tcs.teambition.net/storage/31215631e83bd29864fd5785ddd31adae3bf?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTcxNSwiaWF0IjoxNjEyMTkwOTE1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1NjMxZTgzYmQyOTg2NGZkNTc4NWRkZDMxYWRhZTNiZiJ9.3rk7mxW8zpl2jXhW5TsN99xxasq7g4TSUj2eHmqCXzU&download=image.png "")

![](https://tcs.teambition.net/storage/3121dfed20c1911795d3277d3e1328af2c92?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTcxNSwiaWF0IjoxNjEyMTkwOTE1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkZmVkMjBjMTkxMTc5NWQzMjc3ZDNlMTMyOGFmMmM5MiJ9.aRtgNMemjxt8KTqzo3Pp8OWIdrvpZIJX1oTCti8QwJs&download=image.png "")

```yaml
############################################################
#
# Eureka注册中心
#
############################################################
eureka:
  client:
    serviceUrl:
      defaultZone: http://localhost:20000/eureka/

server:
  port: 20001

management:
  server:
    port: 52001

spring:
  application:
    name: hystrix-turbine

turbine:
  aggregator:
  # cluster1,cluster2
    clusterConfig: default
  #  app-config: foodie-user-service,foodie-item-service,foodie-order-service
  app-config: foodie-order-service
  # 集群名称叫default
  # eureka: instance: metadata-map: abcd-> imooc
  # metadata['abcd']
  cluster-name-expression: '"default"'
  # 根据host + port的形式组合来进行区分
  combine-host-port: true
  # 从哪个actuator的端点拉取方法调用信息
  instanceUrlSuffix:
    default: actuator/hystrix.stream
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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTcxNSwiaWF0IjoxNjEyMTkwOTE1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.6hyemjqfofKXJX2oym-Hd485EpEh4wJfCVYjSHKGv20&download=image.png "")

