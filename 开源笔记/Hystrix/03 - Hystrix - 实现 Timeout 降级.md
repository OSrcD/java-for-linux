

针对全局配置添加超时时间

![](https://tcs.teambition.net/storage/3121ecc164be941704440e0b67ec3b21b76f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUxNiwiaWF0IjoxNjExNDY1NzE2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlY2MxNjRiZTk0MTcwNDQ0MGUwYjY3ZWMzYjIxYjc2ZiJ9.jN9hW3MY2daAGz1OW1zrlKwsogl3rr4a70ObN7p1yyg&download=image.png "")



配置超时行为

超时以后终止线程

![](https://tcs.teambition.net/storage/31213fee4dd84ce33ae2e3cfd5380e0e0862?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUxNiwiaWF0IjoxNjExNDY1NzE2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzZmVlNGRkODRjZTMzYWUyZTNjZmQ1MzgwZTBlMDg2MiJ9.OMiqdiuwajRfo5kS3j6vJO3Ovy8BUkhBWuttDsxQlGQ&download=image.png "")



线程中断行为



hystrix的超时与ribbon的超时会有冲突



## 启动

![](https://tcs.teambition.net/storage/3121e4890a84f3ee6389423ef1139de25e1c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUxNiwiaWF0IjoxNjExNDY1NzE2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlNDg5MGE4NGYzZWU2Mzg5NDIzZWYxMTM5ZGUyNWUxYyJ9.Krp_ApP-RRcPBzjry1C2RTkC2c8xSavHdYmEW-Y1gZ4&download=image.png "")

![](https://tcs.teambition.net/storage/3121e9e3d2eea74d4fdf2f1abaef26a581fe?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUxNiwiaWF0IjoxNjExNDY1NzE2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlOWUzZDJlZWE3NGQ0ZmRmMmYxYWJhZWYyNmE1ODFmZSJ9.0o2aK4ZFG3EM4QrnjDq-2mrE2SFxrdS0gVpqc3pamrY&download=image.png "")

![](https://tcs.teambition.net/storage/31219b6653effc1807f0d8b53bb04d423f25?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUxNiwiaWF0IjoxNjExNDY1NzE2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5YjY2NTNlZmZjMTgwN2YwZDhiNTNiYjA0ZDQyM2YyNSJ9.NBvbQ8YCHJMjG3VxhFZXe_nHgxfPL8pBMgL20rudAS8&download=image.png "")



针对方法的配置

Service的类名#方法名(方法参数)

![](https://tcs.teambition.net/storage/3121116a6302711a391837315ab5f982ca3d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUxNiwiaWF0IjoxNjExNDY1NzE2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExMTZhNjMwMjcxMWEzOTE4MzczMTVhYjVmOTgyY2EzZCJ9.ybpoY1cASWLGYBh1jLnkePYKrqTezXX9vc82HSyuYTU&download=image.png "")



生成方法签名

int 也可以class

![](https://tcs.teambition.net/storage/312185c848a34f54069d28ca36b241b94a94?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUxNiwiaWF0IjoxNjExNDY1NzE2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4NWM4NDhhMzRmNTQwNjlkMjhjYTM2YjI0MWI5NGE5NCJ9.9R8As3UdlPPm4YUxMj4KcrPkxoITVa7MGWdQrIH_p1s&download=image.png "")

![](https://tcs.teambition.net/storage/31217368afd51bca392732b1e2fb131e9837?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUxNiwiaWF0IjoxNjExNDY1NzE2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3MzY4YWZkNTFiY2EzOTI3MzJiMWUyZmIxMzFlOTgzNyJ9.dtw6Jt7K_FYQK-GJNYw2rZTOiBk3PX6ysNTBLdAovRM&download=image.png "")

方法级别的超时优先级高



启动

![](https://tcs.teambition.net/storage/3121e21516f867063e1f7e160f3001752917?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUxNiwiaWF0IjoxNjExNDY1NzE2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlMjE1MTZmODY3MDYzZTFmN2UxNjBmMzAwMTc1MjkxNyJ9.mf3zahYbreAGJ85bi6n3P8JXUE3Rx710XvnnWEPKDro&download=image.png "")

![](https://tcs.teambition.net/storage/3121d6041133adc1e512154ee767d8185488?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUxNiwiaWF0IjoxNjExNDY1NzE2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkNjA0MTEzM2FkYzFlNTEyMTU0ZWU3NjdkODE4NTQ4OCJ9.1nUzPn8PoSSvF57xC4OLE03MoSI-E8g3-X4s2QxhPK8&download=image.png "")

![](https://tcs.teambition.net/storage/3121466dcd5e1eb613d9097c17d4354770bd?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUxNiwiaWF0IjoxNjExNDY1NzE2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0NjZkY2Q1ZTFlYjYxM2Q5MDk3YzE3ZDQzNTQ3NzBiZCJ9.Nm3UMPoPvaWr3lVZ6SoCDsmjTcUh2Y5rj4AUhJRrgQk&download=image.png "")



方法签名可以配置 command key



还可以在代码中配置



![](https://tcs.teambition.net/storage/3121762816f09050a261cee46610636aede4?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUxNiwiaWF0IjoxNjExNDY1NzE2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3NjI4MTZmMDkwNTBhMjYxY2VlNDY2MTA2MzZhZWRlNCJ9.D94zjCMSyR2EjVakQbc6jaxf75lJrMb_hPhmiLoztzY&download=image.png "")

```java
package com.imooc.springcloud.hystrix;

import com.imooc.springcloud.Friend;
import com.imooc.springcloud.MyService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Component;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestParam;

/**
 * Fallback 针对MyService容错类
 */
@Slf4j
@Component
public class Fallback implements MyService {

    /**
     * 回调降级方法
     * @return
     */
    @Override
    public String error() {
        log.info("Fallback：I'm not a black sheep any more");
        return "Fallback：I'm not a black sheep any more";
    }

    @Override
    public String sayHi() {
        return null;
    }

    @Override
    public Friend sayHiPost(@RequestBody Friend friend) {
        return null;
    }

    @Override
    public String retry(@RequestParam(name="timeout") int timeout) {
        return "You are late !";
    }

}

```



![](https://tcs.teambition.net/storage/3121fc253b00e8e006cdf27b70447b45aad0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUxNiwiaWF0IjoxNjExNDY1NzE2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmYzI1M2IwMGU4ZTAwNmNkZjI3YjcwNDQ3YjQ1YWFkMCJ9.hzHp1jvbIo1q4KB0G5RgeWMMCHc6-ZqsPJlo5tpwWjc&download=image.png "")

```java
package com.imooc.springcloud;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;


@RestController
public class Controller {

    @Autowired
    private MyService myService;


    @GetMapping("/fallback")
    public String fallback() {
        return myService.error();
    }

    @GetMapping("/timeout")
    public String timeout(Integer timeout) {
        return myService.retry(timeout);
    }


}

```

![](https://tcs.teambition.net/storage/312152960d1700053fa2e9e7bf82c84558bf?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUxNiwiaWF0IjoxNjExNDY1NzE2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1Mjk2MGQxNzAwMDUzZmEyZTllN2JmODJjODQ1NThiZiJ9.Fq0KmB1eGOVFNoEm15G-nk4cYzviT5m2LGvcg6P7dEQ&download=image.png "")

```java
package com.imooc.springcloud;

import org.springframework.boot.WebApplicationType;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.builder.SpringApplicationBuilder;
import org.springframework.cloud.client.circuitbreaker.EnableCircuitBreaker;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import org.springframework.cloud.openfeign.EnableFeignClients;


@EnableDiscoveryClient
@SpringBootApplication
@EnableFeignClients
@EnableCircuitBreaker // 开启断路器
public class HystrixFallbackApplication {

    public static void main(String[] args) throws NoSuchMethodException {
        new SpringApplicationBuilder(HystrixFallbackApplication.class)
                .web(WebApplicationType.SERVLET)
                .run(args);
        /**
         * 生成方法签名
         * int 也可以class
         */
//        System.out.println(Feign.configKey(MyService.class,
//                MyService.class.getMethod("retry", int.class)));
    }

}

```

![](https://tcs.teambition.net/storage/312178b5acf366a08d736f946bd3898884f0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUxNiwiaWF0IjoxNjExNDY1NzE2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3OGI1YWNmMzY2YTA4ZDczNmY5NDZiZDM4OTg4ODRmMCJ9.rLbpOZW4EIM7u86Wwqbdyy2FKxhtX7GtRRyZ2effLao&download=image.png "")

```java
package com.imooc.springcloud;

import com.imooc.springcloud.hystrix.Fallback;
import org.springframework.cloud.openfeign.FeignClient;

/**
 * fallback  指定一个类来处理降级异常
 * MyService会将用户请求重新导到了当前Fallback类中 error方法
 */
@FeignClient(name = "feign-client", fallback = Fallback.class)
public interface MyService extends IService {

}

```

![](https://tcs.teambition.net/storage/3121f742ed05440e0469ea4e2795048be644?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUxNiwiaWF0IjoxNjExNDY1NzE2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmNzQyZWQwNTQ0MGUwNDY5ZWE0ZTI3OTUwNDhiZTY0NCJ9.JpMRhbSIhI1bDNH2CWs3mkAc3wyF-rWPDASaq-w-nAc&download=image.png "")

```text
spring.application.name=hystrix-consumer
server.port=50000
spring.main.allow-bean-definition-overriding=true
eureka.client.serviceUrl.defaultZone=http://localhost:20000/eureka/

# 开启Feign下面的Hystrix功能
feign.hystrix.enabled=true
# 是否开启服务降级
hystrix.command.default.fallback.enabled=true

# 全局超时
hystrix.command.default.execution.timeout.enabled=true
# 超时时间 针对全局配置添加超时时间
hystrix.command.default.execution.isolation.thread.timeoutInMilliseconds=1000

# 线程中断行为
# 超时以后终止线程 配置超时行为
hystrix.command.default.execution.isolation.thread.interruptOnTimeout=true

# 取消的时候终止线程
hystrix.command.default.execution.isolation.thread.interruptOnFutureCancel=true

# 针对方法的配置
# Service的类名#方法名(方法参数)
# 方法级别的超时优先级高
hystrix.command.MyService#retry(int).execution.isolation.thread.timeoutInMilliseconds=3000

# hystrix的超时与ribbon的超时会有冲突

# 每台机器最大重试次数
feign-client.ribbon.MaxAutoRetries=0
# 可以再重试几台机器
feign-client.ribbon.MaxAutoRetriesNextServer=0
# 连接超时
feign-client.ribbon.ConnectTimeout=1000
# 业务处理超时
feign-client.ribbon.ReadTimeout=8000
# 在所有HTTP Method进行重试
feign-client.ribbon.OkToRetryOnAllOperations=false


```

![](https://tcs.teambition.net/storage/3121e15eac52566a86a1168ecd4523d47ebe?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUxNiwiaWF0IjoxNjExNDY1NzE2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlMTVlYWM1MjU2NmE4NmExMTY4ZWNkNDUyM2Q0N2ViZSJ9.p46vv-nvvxyMxNYBx9TpOOlMca6Oo5aLQ9FAugjiKDY&download=image.png "")

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
    <artifactId>hystrix-fallback</artifactId>

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
            <groupId>com.imooc</groupId>
            <artifactId>feign-client-intf</artifactId>
            <version>${project.version}</version>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-hystrix</artifactId>
        </dependency>
    </dependencies>

</project>
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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjA3MDUxNiwiaWF0IjoxNjExNDY1NzE2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.mfULCvq9h9FQNGHVEZ9D_wBqB4LSddOTiybq7im55YY&download=image.png "")

