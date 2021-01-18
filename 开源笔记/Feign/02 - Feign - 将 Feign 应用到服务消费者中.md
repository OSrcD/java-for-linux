![](https://tcs.teambition.net/storage/312103bc0bdf50f5108f91097cc73b79b97f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMTU2NjI0NywiaWF0IjoxNjEwOTYxNDQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwM2JjMGJkZjUwZjUxMDhmOTEwOTdjYzczYjc5Yjk3ZiJ9.k7APoasPOOIOgN_zk3vve5vXGvMSJlaweQl7koDtA-s&download=2020-09-17%20053531.png "")

![](https://tcs.teambition.net/storage/312133013512e6765153bfb1d6f08f604f5e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMTU2NjI0NywiaWF0IjoxNjEwOTYxNDQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzMzAxMzUxMmU2NzY1MTUzYmZiMWQ2ZjA4ZjYwNGY1ZSJ9.eNo10m0t8D0DbMC-bl3w1xtOizvKFG28M3Cl6MzssZE&download=image.png "")

比较

![](https://tcs.teambition.net/storage/31211682abecf83638481bdab8e04fa33e49?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMTU2NjI0NywiaWF0IjoxNjEwOTYxNDQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExNjgyYWJlY2Y4MzYzODQ4MWJkYWI4ZTA0ZmEzM2U0OSJ9.GHg1yYenrQRDX00BecUmZg6-WMas2hq4g6F5P7Bzqnc&download=image.png "")

![](https://tcs.teambition.net/storage/31213a0743f11778da1d49acb3fc7fff71d7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMTU2NjI0NywiaWF0IjoxNjEwOTYxNDQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzYTA3NDNmMTE3NzhkYTFkNDlhY2IzZmM3ZmZmNzFkNyJ9.iACK9-n6_dlR2tmIfn7KSsu2T_Z_k5R4l7z1VkkQ0Bw&download=image.png "")

服务提供者的service name 告诉这个接口 你接下来在里面尝试调用的方法 都发到eureka-client 上 会生成一个代理类

![](https://tcs.teambition.net/storage/312142b2a7cdb6b361829f38e15db719b2a3?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMTU2NjI0NywiaWF0IjoxNjEwOTYxNDQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0MmIyYTdjZGI2YjM2MTgyOWYzOGUxNWRiNzE5YjJhMyJ9.Lwo2pjzQw3YPGmQijEvmsvOodlI3hpKGV9SpmFsCZRc&download=image.png "")

@GetMapping 发送到 sayHi方法之上

![](https://tcs.teambition.net/storage/31213a5c0e601c2dcfaecf92c01ab63cc3b6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMTU2NjI0NywiaWF0IjoxNjEwOTYxNDQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzYTVjMGU2MDFjMmRjZmFlY2Y5MmMwMWFiNjNjYzNiNiJ9.DMkXqwiT0HE1jEscg3oH6XHvGP1UCPKpgNtYvVXcRq4&download=image.png "")

接口背后的代理类

![](https://tcs.teambition.net/storage/31216ecc38bac5f849190e74d5117abe4994?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMTU2NjI0NywiaWF0IjoxNjEwOTYxNDQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2ZWNjMzhiYWM1Zjg0OTE5MGU3NGQ1MTE3YWJlNDk5NCJ9.K7JBlnkehniXEJ5RDXVKuj6FHTzHOpvb6RP_j39D8zI&download=image.png "")

![](https://tcs.teambition.net/storage/3121b33c49732466b6871f1bea5eb807c49c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMTU2NjI0NywiaWF0IjoxNjEwOTYxNDQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiMzNjNDk3MzI0NjZiNjg3MWYxYmVhNWViODA3YzQ5YyJ9.nUyutzjGn8VNpDO8lIvjLxdmDmPQ3aGX2jZU_xVYt78&download=image.png "")

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

    <artifactId>feign-consumer</artifactId>
    <packaging>jar</packaging>
    <name>feign-consumer</name>

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
            <artifactId>spring-cloud-starter-openfeign</artifactId>
        </dependency>

    </dependencies>

</project>
```

![](https://tcs.teambition.net/storage/3121441988d7f29d985aeb658bdf4c87846c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMTU2NjI0NywiaWF0IjoxNjEwOTYxNDQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0NDE5ODhkN2YyOWQ5ODVhZWI2NThiZGY0Yzg3ODQ2YyJ9.wIe2vd_FKrWftsET2RpI8SrhlrJaLoYSohIpEEeRsNs&download=image.png "")

```java
package com.imooc.springcloud;

import org.springframework.boot.WebApplicationType;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.builder.SpringApplicationBuilder;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import org.springframework.cloud.openfeign.EnableFeignClients;


@EnableDiscoveryClient
@SpringBootApplication
// 启动扫描声明为 @FeignClient的接口
@EnableFeignClients
public class FeignConsumerApplication {

    public static void main(String[] args) {
        new SpringApplicationBuilder(FeignConsumerApplication.class)
                .web(WebApplicationType.SERVLET)
                .run(args);
    }

}

```

![](https://tcs.teambition.net/storage/31218d5790ea96657a908d14a1ab458f75b8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMTU2NjI0NywiaWF0IjoxNjEwOTYxNDQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4ZDU3OTBlYTk2NjU3YTkwOGQxNGExYWI0NThmNzViOCJ9.YMN_RESf_knaoxGWZQPsbnn4rHGWGDDtCCZ1sKGiO-Q&download=image.png "")

```java
package com.imooc.springcloud;

import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.GetMapping;

/**
 * 服务提供者的service name 告诉这个接口
 * 你接下来在里面尝试调用的方法
 * 都发到eureka-client 上 会生成一个代理类
 */
@FeignClient("eureka-client")
public interface IService {

    // @GetMapping 发送到 sayHi方法之上
    @GetMapping("/sayHi")
    String sayHi();
}

```

![](https://tcs.teambition.net/storage/31218fecd64703d98acf281cebb91375df8d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMTU2NjI0NywiaWF0IjoxNjEwOTYxNDQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4ZmVjZDY0NzAzZDk4YWNmMjgxY2ViYjkxMzc1ZGY4ZCJ9.O9fS9xNQ1qzX6FSJom-_w3z8_2YCiHBApXhxqgp1gZg&download=image.png "")

```java
package com.imooc.springcloud;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class Controller {

    @Autowired
    private IService service;

    @GetMapping("/sayHi")
    public String sayHi() {
        return service.sayHi();
    }
}

```

![](https://tcs.teambition.net/storage/3121c62207b8e404daea9d0e3294d1360080?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMTU2NjI0NywiaWF0IjoxNjEwOTYxNDQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjNjIyMDdiOGU0MDRkYWVhOWQwZTMyOTRkMTM2MDA4MCJ9.eJqDMBXfUoMixqMApqYn_hkA4QmW-3b9I2gkCJMAAlE&download=image.png "")

```none
spring.application.name=feign-consumer
server.port=40001

eureka.client.serviceUrl.defaultZone=http://localhost:20000/eureka/



```



开源笔记

可 Pull Requests 协作写开源笔记

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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMTU2NjI0NywiaWF0IjoxNjEwOTYxNDQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.ud-nNvzoAkfFbreq4oLSgmsbHzT5dAEoMbY-fwPXmYE&download=image.png "")

