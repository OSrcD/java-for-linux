![](https://tcs.teambition.net/storage/312239b0d8827a32da79482fcae9b39c9585?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTMzMCwiaWF0IjoxNjEyMTkwNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzOWIwZDg4MjdhMzJkYTc5NDgyZmNhZTliMzljOTU4NSJ9.kSy31YMp40UiGJYKwDfJGrDm13VcZjVbTI-taJQxtT4&download=image.png "")

可以指定限流的脚本

![](https://tcs.teambition.net/storage/31226792833c678e29683f2d625707579582?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTMzMCwiaWF0IjoxNjEyMTkwNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI2NzkyODMzYzY3OGUyOTY4M2YyZDYyNTcwNzU3OTU4MiJ9.BV6pEiM_lQvcecyzDVM6GBHuraklfih_dSnTKtyNoCo&download=image.png "")

![](https://tcs.teambition.net/storage/31220536ccc0fb663ae456f80775d1bb325d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTMzMCwiaWF0IjoxNjEyMTkwNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIwNTM2Y2NjMGZiNjYzYWU0NTZmODA3NzVkMWJiMzI1ZCJ9.St2EUCDWUYEWDnA0-SInWWY4ZTM-qLAIvacpCBmRfqo&download=image.png "")

```java
package com.imooc.springcloud;

import org.springframework.cloud.gateway.filter.ratelimit.KeyResolver;
import org.springframework.cloud.gateway.filter.ratelimit.RedisRateLimiter;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Primary;
import reactor.core.publisher.Mono;

@Configuration
public class RedisLimiterConfiguration {


    /**
     * ID : KEY 它是代表着 你当前这个request 特征量
     * 比如说基于 IP 地址限流 所有进来的 Request 不管它是
     * 访问那个 请求 这里都会带上一个 以 IP 地址 为KEY的
     * 一个参数 利用这个参数到Redis 中 去查找对应的 IP 地址
     * 流量数据 以方法的名称 作为限流 KEY 就应该是方法的名称
     * 所以它会根据具体的业务不同来 使用不同的 KEY
     * KeyResolve 就是具体的业务逻辑 它来用去定位 你一个方法请求的 KEY
     */

    @Bean
    /**
     * 在真正的项目当中 不止会声明一个 KeyResolver 会为具体不同的
     * 业务 指定不同的 Resolver 比如说 你的用户模块 想以 IP 地址限流
     * 商品模块想以用户的登录名称限流 这些规则都要声明一个不同的KeyResolver
     * 加上@Primary 是为了 避免 我们Gateway 框架 在自动装配的过程中
     * 如果它引用了 KeyResolver 哪我们这里定义多个 KeyResolver 不知道该使用哪个
     */
    @Primary
    public KeyResolver remoteAddrKeyResolver() {

        // 把用户的 IP 地址 作为限流的 Key
        return exchange -> Mono.just(
                exchange.getRequest()
                        .getRemoteAddress()
                        .getAddress()
                        .getHostAddress()

        );
    }

    /**
     * 第一个参数是限流桶的速率 比如 每秒给你发3个 令牌
     * 或者每秒 发5个令牌 允许每秒处理多少个请求
     * 第二个参数 桶的数量 这个令牌桶 容量 是有多大
     * 允许在一秒钟内完成的最大请求数
     */
    @Bean("redisLimiterUser")
    @Primary
    public RedisRateLimiter redisLimiterUser() {
        /**
         * 每秒钟放行 1个令牌 桶子最多放两个令牌
         */
        return new RedisRateLimiter(1, 2);
//        return new RedisRateLimiter(10, 20);
    }

    @Bean("redisLimiterItem")
    public RedisRateLimiter redisLimiterItem() {
        return new RedisRateLimiter(20, 50);
    }



}


```

![](https://tcs.teambition.net/storage/3122153b540a579af5d482de5adc5e8517f9?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTMzMCwiaWF0IjoxNjEyMTkwNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxNTNiNTQwYTU3OWFmNWQ0ODJkZTVhZGM1ZTg1MTdmOSJ9.bo-beAAbr3rOKzL_1zKzLCQO5QfU2n3gb8SkUUqLg9s&download=image.png "")

```yaml
# 可以尝试集成config-server来配置
spring:
  application:
    name: platform-gateway
  redis:
    host: 192.168.245.138
    port: 6379
    database: 0
  main:
    allow-bean-definition-overriding: true
  cloud:
    gateway:
      locator:
        # 在生产环境下会关闭 不会自动创建默认路由规则
        enabled: false
        lower-case-service-id: true


server:
  port: 20004


eureka:
  client:
    serviceUrl:
      defaultZone: http://localhost:20000/eureka/

## 开启所有actuator-endpoint
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

![](https://tcs.teambition.net/storage/3122950c977321b0f36d8471cfc850760b94?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTMzMCwiaWF0IjoxNjEyMTkwNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5NTBjOTc3MzIxYjBmMzZkODQ3MWNmYzg1MDc2MGI5NCJ9.0FBF3cec4YMV6Qy6MNea54seY_KSlwgfwFp1I_Nzz8I&download=image.png "")

```java
package com.imooc.springcloud;


import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;


@EnableDiscoveryClient
@SpringBootApplication
public class GatewayApplication {

    public static void main(String[] args) {
        SpringApplication.run(GatewayApplication.class);
    }

}

```

![](https://tcs.teambition.net/storage/31221010436f7acfb86d84d0a8e93d2057cc?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTMzMCwiaWF0IjoxNjEyMTkwNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxMDEwNDM2ZjdhY2ZiODZkODRkMGE4ZTkzZDIwNTdjYyJ9.ZDF68W-Y5UPLjBgszTu_yvejhzbF9J9uzNLvvit8_Hc&download=image.png "")

```java
package com.imooc.springcloud;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.cloud.gateway.filter.ratelimit.KeyResolver;
import org.springframework.cloud.gateway.filter.ratelimit.RateLimiter;
import org.springframework.cloud.gateway.route.RouteLocator;
import org.springframework.cloud.gateway.route.builder.RouteLocatorBuilder;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.http.HttpStatus;

@Configuration
public class RoutesConfiguration {

    @Autowired
    private KeyResolver hostNameResolver;

    @Autowired
    @Qualifier("redisLimiterUser") // 指定加载哪个bean
    private RateLimiter rateLimiterUser;

    @Bean
    public RouteLocator routes(RouteLocatorBuilder builder) {
        return builder.routes()
                // FIXME search服务自己实现
                .route(r -> r.path("/search/**", "/index/**", "/items/search", "/items/catItems")

                        .uri("lb://FOODIE-SEARCH-SERVICE")
                )

                .route(r -> r.path("/address/**", "/passport/**", "/userInfo/**", "/center/**")
                        // 指定 requestRateLimiter 过滤器
                        .filters(f -> f.requestRateLimiter(c -> {
                            // 指定限流Key
                            c.setKeyResolver(hostNameResolver);
                            // 指定限流规则
                            c.setRateLimiter(rateLimiterUser);
                            c.setStatusCode(HttpStatus.BAD_GATEWAY);
                        }))
                        .uri("lb://FOODIE-USER-SERVICE")
                )

                .route(r -> r.path("/items/**")
                        .uri("lb://FOODIE-ITEM-SERVICE")
                )

                .route(r -> r.path("/shopcart/**")
                        .uri("lb://FOODIE-CART-SERVICE")
                )

                .route(r -> r.path("/orders/**", "/myorders/**", "/mycomments/**")
                        .uri("lb://FOODIE-ORDER-SERVICE")
                )
                .build();
    }

}

```

![](https://tcs.teambition.net/storage/3122d3f3171c72ab1a8a8928f98acde5e96c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTMzMCwiaWF0IjoxNjEyMTkwNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkM2YzMTcxYzcyYWIxYThhODkyOGY5OGFjZGU1ZTk2YyJ9.ulPpltOCO4OGQwC0Kq2sc-l1De_k-2i0jN_eZAUoaq8&download=image.png "")

```yaml
# 可以尝试集成config-server来配置
spring:
  application:
    name: platform-gateway
  redis:
    host: 192.168.245.138
    port: 6379
    database: 0
  main:
    allow-bean-definition-overriding: true
  cloud:
    gateway:
      locator:
        # 在生产环境下会关闭 不会自动创建默认路由规则
        enabled: false
        lower-case-service-id: true


server:
  port: 20004


eureka:
  client:
    serviceUrl:
      defaultZone: http://localhost:20000/eureka/

## 开启所有actuator-endpoint
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

启动配置中心 注册中心 User微服务 网关微服务 Redis

![](https://tcs.teambition.net/storage/3122167a99a955abb017fc74cb987407a9be?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTMzMCwiaWF0IjoxNjEyMTkwNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxNjdhOTlhOTU1YWJiMDE3ZmM3NGNiOTg3NDA3YTliZSJ9.aOZ47GnmcjbppGfr3fmzmZfYxFU-JrpWLwY3CXFKjy0&download=image.png "")



每秒钟放行 1个 没问题

![](https://tcs.teambition.net/storage/3122a40df4e7cfeade66a77174d37c95c080?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTMzMCwiaWF0IjoxNjEyMTkwNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhNDBkZjRlN2NmZWFkZTY2YTc3MTc0ZDM3Yzk1YzA4MCJ9.IEigAKoxZAbAM_3PZtYNy177J3GZgdL8tK_omCtQouA&download=image.png "")

发的太多

![](https://tcs.teambition.net/storage/3122af9af90af661b5bf5bcd26ee49523448?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTMzMCwiaWF0IjoxNjEyMTkwNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhZjlhZjkwYWY2NjFiNWJmNWJjZDI2ZWU0OTUyMzQ0OCJ9.QLcq0OL-ANC9_FpQlBeORkKk63kynmktLEBzEfU1_Uk&download=image.png "")

![](https://tcs.teambition.net/storage/31229901137d582db12ac46b24e6233f674e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTMzMCwiaWF0IjoxNjEyMTkwNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5OTAxMTM3ZDU4MmRiMTJhYzQ2YjI0ZTYyMzNmNjc0ZSJ9.0pOuHMivLhrovS4XSwn-tWDTkWAqEG7r7TB8fOcCMzA&download=image.png "")

如果超时调用  失败 可以重新启动

![](https://tcs.teambition.net/storage/3122f38ced756a0ed8806a4727e030bc9911?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTMzMCwiaWF0IjoxNjEyMTkwNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJmMzhjZWQ3NTZhMGVkODgwNmE0NzI3ZTAzMGJjOTkxMSJ9.awX5hyJzHPsjJ3NMpkofY2OaaW3Bpgy8Bc4sZA5yynw&download=image.png "")

![](https://tcs.teambition.net/storage/3122767653db0181ccb14741c971a14e48e2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTMzMCwiaWF0IjoxNjEyMTkwNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI3Njc2NTNkYjAxODFjY2IxNDc0MWM5NzFhMTRlNDhlMiJ9.hQuBbU-FhFpecSvkp1MnEZUOcjhIAOo4saySJrvr8yo&download=image.png "")

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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTMzMCwiaWF0IjoxNjEyMTkwNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.ABIGXmutOx3X_FlD9efA9-nva483lIqNByfRj0IZRo4&download=image.png "")

