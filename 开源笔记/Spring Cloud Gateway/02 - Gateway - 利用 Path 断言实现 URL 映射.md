

![](https://tcs.teambition.net/storage/3121a0a83a3b61614e32766997ac8da72626?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYwNywiaWF0IjoxNjExODQzODA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhMGE4M2EzYjYxNjE0ZTMyNzY2OTk3YWM4ZGE3MjYyNiJ9.nXpuU9d-9Sq8Hx8ZaXv2CXL1ccE8UBfm3mcdzlhhErE&download=2020-09-17%20060655.png "")

![](https://tcs.teambition.net/storage/31219dd49ad919f6f2d4868e6d1118a5e269?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYwNywiaWF0IjoxNjExODQzODA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5ZGQ0OWFkOTE5ZjZmMmQ0ODY4ZTZkMTExOGE1ZTI2OSJ9.UKgnoiLx5OJlc2xiWUqQchxw-_3yFq30KtCng-HL_S8&download=2020-09-17%20060719.png "")

![](https://tcs.teambition.net/storage/31214bf69129c10f1e33ea1ab5087e8b9c1b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYwNywiaWF0IjoxNjExODQzODA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0YmY2OTEyOWMxMGYxZTMzZWExYWI1MDg3ZThiOWMxYiJ9.0SRUIvqfKoA1DDOIYzt9jqaO4ehYYOcRxQG2lWQ6FeA&download=image.png "")

![](https://tcs.teambition.net/storage/31211499788b2b1d2f50b06684dfbdc61c64?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYwNywiaWF0IjoxNjExODQzODA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExNDk5Nzg4YjJiMWQyZjUwYjA2Njg0ZGZiZGM2MWM2NCJ9.Ny_9KuTZY8FiHS_3Q4jXYNA7llcrMFRgTLyppCYiLJ0&download=image.png "")

```yaml
spring:
  application:
    name: gateway-service
  cloud:
    gateway:
      # 利用服务发现机制 自动创建路由规则 跟 Eureka 相关
      discovery:
        # 定位器 通过 discovery 的服务发现 把你的服务 在 Eureka 注册中心
        # 注册好的 所有服务 统统的给它定位到 怎么定位好的 gateway 的问题
        locator:
          # 自动创建服务路由开关给它打开
          enabled: true
          # 小写 路由寻址 调用服务 大写失效
          lower-case-service-id: true
      # 定义 路由 过滤器
      routes:
      # yml 格式 一个 list 元素 或 数组 以什么开头 以一个短横杆开头
      # id 当前路由的唯一标识
      - id: feignclient
        # 如果匹配上了所有的断言 那么这个用户请求将要转发到哪里
        uri: lb://FEIGN-CLIENT
        # 配置断言集合
        predicates:
        # 配置匹配的路径 ** 表示所有以 yml开头的都转发到这里
        - Path=/yml/**
        # 定义过滤器集合 也是一个数组
        filters:
        # //localhost:9000/yml/sayHi 切断它的前缀 //localhost:9000/sayHi
        # 转发到的地址会变成 //FEIGN-CLIENT/sayHi
        - StripPrefix=1



server:
  port: 65000

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
        include: "*"
  endpoint:
    health:
      show-details: always
```

![](https://tcs.teambition.net/storage/3121cc75bb3e348e5505637022f814819a26?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYwNywiaWF0IjoxNjExODQzODA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjYzc1YmIzZTM0OGU1NTA1NjM3MDIyZjgxNDgxOWEyNiJ9.xN8PgC4BQz_zjoigETOXZkZfuc_oQJUvaRxu3ZNkA28&download=image.png "")

```java
package com.imooc.springcloud;

import org.springframework.cloud.gateway.route.RouteLocator;
import org.springframework.cloud.gateway.route.builder.RouteLocatorBuilder;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.core.annotation.Order;
import org.springframework.http.HttpMethod;

@Configuration
public class GatewayConfiguration {

    /**
     * RouteLocator 地址定位
     * Bean 注解 会作为初始化的一部分 自然有一个在当前上下文中已经初始化好的 builder 传给你
     * Order 默认加载顺序为 2147483647
     */
    @Bean
    @Order
    public RouteLocator customizedRoutes(RouteLocatorBuilder builder) {
        return builder.routes()
                // 每一个 route 相当于 yml 配置的 element
                .route(r -> r.path("/java/**")
                        .and().method(HttpMethod.GET)
                        .and().header("name")
                        .filters(f -> f.stripPrefix(1)
                            .addResponseHeader("java-param","gateway-config")
                        )
                        .uri("lb://FEIGN-CLIENT")
                )
                // 把当前 builder 所有的属性全部组装最终返回一个完整的 RouteLocator 对象
                .build();

    }

}

```

![](https://tcs.teambition.net/storage/312113aff7d27638cd254f701926c5bec931?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYwNywiaWF0IjoxNjExODQzODA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExM2FmZjdkMjc2MzhjZDI1NGY3MDE5MjZjNWJlYzkzMSJ9.u896nt7nihmj4g7CMqUGVMguhVWtuNaqRMdI_US5t70&download=image.png "")

![](https://tcs.teambition.net/storage/3121cc12315b56c44678105f63bd3029a13b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYwNywiaWF0IjoxNjExODQzODA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjYzEyMzE1YjU2YzQ0Njc4MTA1ZjYzYmQzMDI5YTEzYiJ9.k7jpOD3VpPWxa5WpdtRY2607p1JIGDXLCEC75CJYFuc&download=image.png "")

![](https://tcs.teambition.net/storage/31219d7a9d61a9562032ca752a566ccd13f9?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYwNywiaWF0IjoxNjExODQzODA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5ZDdhOWQ2MWE5NTYyMDMyY2E3NTJhNTY2Y2NkMTNmOSJ9.lROjevOcmPZxHTT1c-QxRZz2YTQ-kaANdr5Py1NsR0Y&download=image.png "")

![](https://tcs.teambition.net/storage/3121285c9d8bbbcffcd5d524e7bd8b709aa9?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYwNywiaWF0IjoxNjExODQzODA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyODVjOWQ4YmJiY2ZmY2Q1ZDUyNGU3YmQ4YjcwOWFhOSJ9.SJedsqWVetk__f0qF70vaM0tISrn_gkFwe9T097HKOk&download=image.png "")

![](https://tcs.teambition.net/storage/3121abeaa38fdc0f3de712af1e3658e0aa93?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYwNywiaWF0IjoxNjExODQzODA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhYmVhYTM4ZmRjMGYzZGU3MTJhZjFlMzY1OGUwYWE5MyJ9.Mc0qyK2bDf2sEHgn1KPrBWlMaI3OyFQAiJyTlDvJKvw&download=image.png "")

![](https://tcs.teambition.net/storage/312128cfffc587ad30fc08d2d6fa31bc048d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYwNywiaWF0IjoxNjExODQzODA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyOGNmZmZjNTg3YWQzMGZjMDhkMmQ2ZmEzMWJjMDQ4ZCJ9.wraW_P2bpDnUYQiQxolBKQzQ4VNNlmeseWM3l_yYyhA&download=image.png "")

java 定义的路由 会自动生成 route_id

filters 中的是toString 生成的内容

![](https://tcs.teambition.net/storage/3121c1d6ce9d7098f1ab5d66364369624068?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYwNywiaWF0IjoxNjExODQzODA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjMWQ2Y2U5ZDcwOThmMWFiNWQ2NjM2NDM2OTYyNDA2OCJ9.D8rVFXZQNJUO5KdklIxu4UNA8DnsQJhleD_LDLkAePU&download=image.png "")



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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYwNywiaWF0IjoxNjExODQzODA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.WsJzVKoKFfjmGkrVqAgGhNwU4M5olBauMpM0QcNO_ts&download=image.png "")

