

![](https://tcs.teambition.net/storage/312116841777e8a84d7f34484e932c73b89d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYzNSwiaWF0IjoxNjExODQzODM1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExNjg0MTc3N2U4YTg0ZDdmMzQ0ODRlOTMyYzczYjg5ZCJ9.Rv605E3bLSNcxRz8j04d6DlsJ7ezZa3DhjH8uC3xyDE&download=2020-09-17%20060743.png "")

![](https://tcs.teambition.net/storage/3121e5be15203ec9a94f36c9b26cb0c00f04?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYzNSwiaWF0IjoxNjExODQzODM1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlNWJlMTUyMDNlYzlhOTRmMzZjOWIyNmNiMGMwMGYwNCJ9.NEkPWFlxNXXG0EBvMn2mzYI3M5nlKNXvUAY2nI02SoU&download=image.png "")

![](https://tcs.teambition.net/storage/312116873a749aa62aa0dbe68aa008c796c6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYzNSwiaWF0IjoxNjExODQzODM1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExNjg3M2E3NDlhYTYyYWEwZGJlNjhhYTAwOGM3OTZjNiJ9.95DerCe3HMlyxjJot1TpFg6pCBY7SVMQb2Ukx3pk1xQ&download=image.png "")

```java
package com.imooc.springcloud;

import lombok.extern.slf4j.Slf4j;
import org.springframework.cloud.gateway.filter.GatewayFilter;
import org.springframework.cloud.gateway.filter.GatewayFilterChain;
import org.springframework.core.Ordered;
import org.springframework.stereotype.Component;
import org.springframework.util.StopWatch;
import org.springframework.web.server.ServerWebExchange;
import reactor.core.publisher.Mono;

/**
 * 实现 GatewayFilter 过滤器接口
 * 实现 过滤器执行顺序接口
 */
@Slf4j
@Component
public class TimerFilter implements GatewayFilter, Ordered {

    @Override
    public Mono<Void> filter(ServerWebExchange exchange, GatewayFilterChain chain) {
        /**
         * 给接口计时 打出 log
         */
        StopWatch timer = new StopWatch();

        //
        //
        /**
         * getURI localhost:65000/xxx/sayHi
         * getRawPath 获得访问路径 sayHi
         */
        timer.start(exchange.getRequest().getURI().getRawPath());

        // 获得所有Attributes 向 Attributes 添加新属性
//        exchange.getAttributes().put("requestTimeBegin", System.currentTimeMillis());

        /**
         * then 前面的方法处理完了 在最后调用 then 方法
         */
        return chain.filter(exchange).then(
                /**
                 * 实际底层用钩子做回调
                 * 开启一个新的线程
                 */
                Mono.fromRunnable(()->{
                    // 计时停止
                    timer.stop();

                    log.info(timer.prettyPrint());
                })
        );
    }

    @Override
    public int getOrder() {
        return 0;
    }
}


```

![](https://tcs.teambition.net/storage/3121fd0a76262c3b69388634bdc8c700b6ce?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYzNSwiaWF0IjoxNjExODQzODM1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmZDBhNzYyNjJjM2I2OTM4ODYzNGJkYzhjNzAwYjZjZSJ9.-wfligV_wfpNIbFc8e9qAids9NvJkkuQV7wa2321wgc&download=image.png "")

```java
package com.imooc.springcloud;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cloud.gateway.route.RouteLocator;
import org.springframework.cloud.gateway.route.builder.RouteLocatorBuilder;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.core.annotation.Order;
import org.springframework.http.HttpMethod;

import java.time.ZonedDateTime;

@Configuration
public class GatewayConfiguration {


    @Autowired
    private TimerFilter timerFilter;

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
                                .addResponseHeader("java-param", "gateway-config")
                                /**
                                 * 添加自定义 filter
                                 */
                                .filter(timerFilter)
                        )
                        .uri("lb://FEIGN-CLIENT")
                )
                .route(r -> r.path("/seckill/**")
                                .and()
                                /**
                                 * 告诉 Gateway 当前的这个路由规则 只在某个时间点以后生效
                                 * now 也就是当前的时间点
                                 * 它是说 当你服务启动加载完成以后 往后推迟一分钟生效
                                 * 也就是 一分钟后才生效的秒杀场景
                                 * before 是说在某个时间点以前 路由规则才生效 过了这个时间点就生效
                                 * between 这个路由规则 会在这两个时间段生效
                                 */
                                .after(ZonedDateTime.now().plusMinutes(1))
//                        .and().before()
//                        .and().between()
                                .filters(f -> f.stripPrefix(1))
                                .uri("lb://FEIGN-CLIENT")
                )
                // 把当前 builder 所有的属性全部组装最终返回一个完整的 RouteLocator 对象
                .build();

    }

}

```

启动

![](https://tcs.teambition.net/storage/312139a1336b581da70e394c80542443f38b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYzNSwiaWF0IjoxNjExODQzODM1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzOWExMzM2YjU4MWRhNzBlMzk0YzgwNTQyNDQzZjM4YiJ9.Y_oScAPXSf13A6e_E2fv-9gwiSZO_wAazBDlmhSDKqk&download=image.png "")

![](https://tcs.teambition.net/storage/312177d3ab59af20d1f5fe916ef215c4a11d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYzNSwiaWF0IjoxNjExODQzODM1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3N2QzYWI1OWFmMjBkMWY1ZmU5MTZlZjIxNWM0YTExZCJ9.4sgxtKksS5ZqeicHW55E1YzT3wDPPqviY-neDkzvWjY&download=image.png "")

ms 所占用的 毫秒数 花了多毫秒

100% 在这个整个环节中 它会记录你每一次 开始停止所占的时间 占整个链路的时间比例

Task name 调用的接口路径

```text

2021-01-28 14:31:37.716  INFO 46209 --- [ctor-http-nio-3] c.netflix.config.ChainedDynamicProperty  : Flipping property: FEIGN-CLIENT.ribbon.ActiveConnectionsLimit to use NEXT property: niws.loadbalancer.availabilityFilteringRule.activeConnectionsLimit = 2147483647
2021-01-28 14:31:38.100  INFO 46209 --- [ctor-http-nio-3] c.n.u.concurrent.ShutdownEnabledTimer    : Shutdown hook installed for: NFLoadBalancer-PingTimer-FEIGN-CLIENT
2021-01-28 14:31:38.103  INFO 46209 --- [ctor-http-nio-3] c.netflix.loadbalancer.BaseLoadBalancer  : Client: FEIGN-CLIENT instantiated a LoadBalancer: DynamicServerListLoadBalancer:{NFLoadBalancer:name=FEIGN-CLIENT,current list of Servers=[],Load balancer stats=Zone stats: {},Server stats: []}ServerList:null
2021-01-28 14:31:38.194  INFO 46209 --- [ctor-http-nio-3] c.n.l.DynamicServerListLoadBalancer      : Using serverListUpdater PollingServerListUpdater
2021-01-28 14:31:38.323  INFO 46209 --- [ctor-http-nio-3] c.netflix.config.ChainedDynamicProperty  : Flipping property: FEIGN-CLIENT.ribbon.ActiveConnectionsLimit to use NEXT property: niws.loadbalancer.availabilityFilteringRule.activeConnectionsLimit = 2147483647
2021-01-28 14:31:38.356  INFO 46209 --- [ctor-http-nio-3] c.n.l.DynamicServerListLoadBalancer      : DynamicServerListLoadBalancer for client FEIGN-CLIENT initialized: DynamicServerListLoadBalancer:{NFLoadBalancer:name=FEIGN-CLIENT,current list of Servers=[192.168.4.100:40005],Load balancer stats=Zone stats: {defaultzone=[Zone:defaultzone;	Instance count:1;	Active connections count: 0;	Circuit breaker tripped count: 0;	Active connections per server: 0.0;]
},Server stats: [[Server:192.168.4.100:40005;	Zone:defaultZone;	Total Requests:0;	Successive connection failure:0;	Total blackout seconds:0;	Last connection made:Thu Jan 01 08:00:00 CST 1970;	First connection made: Thu Jan 01 08:00:00 CST 1970;	Active Connections:0;	total failure count in last (1000) msecs:0;	average resp time:0.0;	90 percentile resp time:0.0;	95 percentile resp time:0.0;	min resp time:0.0;	max resp time:0.0;	stddev resp time:0.0]
]}ServerList:org.springframework.cloud.netflix.ribbon.eureka.DomainExtractingServerList@68ae57a0
2021-01-28 14:31:38.898  INFO 46209 --- [ctor-http-nio-3] com.imooc.springcloud.TimerFilter        : StopWatch '': running time (millis) = 3461
-----------------------------------------
ms     %     Task name
-----------------------------------------
03461  100%  /sayHi

2021-01-28 14:31:39.208  INFO 46209 --- [erListUpdater-0] c.netflix.config.ChainedDynamicProperty  : Flipping property: FEIGN-CLIENT.ribbon.ActiveConnectionsLimit to use NEXT property: niws.loadbalancer.availabilityFilteringRule.activeConnectionsLimit = 2147483647


```

全局过滤器

![](https://tcs.teambition.net/storage/3121cec7bfa3a1815544252892fc4bc62bec?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYzNSwiaWF0IjoxNjExODQzODM1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjZWM3YmZhM2ExODE1NTQ0MjUyODkyZmM0YmM2MmJlYyJ9.GeSka16Og5WB8e2SVoofH2vL4L6FfVxA6jJc0zsCr4A&download=image.png "")

```java
package com.imooc.springcloud;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cloud.gateway.route.RouteLocator;
import org.springframework.cloud.gateway.route.builder.RouteLocatorBuilder;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.core.annotation.Order;
import org.springframework.http.HttpMethod;

import java.time.ZonedDateTime;

@Configuration
public class GatewayConfiguration {


    @Autowired
    private TimerFilter timerFilter;

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
                                .addResponseHeader("java-param", "gateway-config")
                                /**
                                 * 添加自定义 filter
                                 */
//                                .filter(timerFilter)
                        )
                        .uri("lb://FEIGN-CLIENT")
                )
                .route(r -> r.path("/seckill/**")
                                .and()
                                /**
                                 * 告诉 Gateway 当前的这个路由规则 只在某个时间点以后生效
                                 * now 也就是当前的时间点
                                 * 它是说 当你服务启动加载完成以后 往后推迟一分钟生效
                                 * 也就是 一分钟后才生效的秒杀场景
                                 * before 是说在某个时间点以前 路由规则才生效 过了这个时间点就生效
                                 * between 这个路由规则 会在这两个时间段生效
                                 */
                                .after(ZonedDateTime.now().plusMinutes(1))
//                        .and().before()
//                        .and().between()
                                .filters(f -> f.stripPrefix(1))
                                .uri("lb://FEIGN-CLIENT")
                )
                // 把当前 builder 所有的属性全部组装最终返回一个完整的 RouteLocator 对象
                .build();

    }

}

```

![](https://tcs.teambition.net/storage/3121b3a53477de1be42fc97f1ac55f70813a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYzNSwiaWF0IjoxNjExODQzODM1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiM2E1MzQ3N2RlMWJlNDJmYzk3ZjFhYzU1ZjcwODEzYSJ9.OHkVYQI3L8s_grYTA4r5wxZ1qS_nEO-E2-qc7JeLTkM&download=image.png "")

```java
package com.imooc.springcloud;

import lombok.extern.slf4j.Slf4j;
import org.springframework.cloud.gateway.filter.GatewayFilter;
import org.springframework.cloud.gateway.filter.GatewayFilterChain;
import org.springframework.cloud.gateway.filter.GlobalFilter;
import org.springframework.core.Ordered;
import org.springframework.stereotype.Component;
import org.springframework.util.StopWatch;
import org.springframework.web.server.ServerWebExchange;
import reactor.core.publisher.Mono;

/**
 * 实现 GatewayFilter 过滤器接口
 * GlobalFilter 全局过滤器 会作用全局的路由规则当中
 * 实现 过滤器执行顺序接口
 */
@Slf4j
@Component
public class TimerFilter implements GlobalFilter, Ordered {

    @Override
    public Mono<Void> filter(ServerWebExchange exchange, GatewayFilterChain chain) {
        /**
         * 给接口计时 打出 log
         */
        StopWatch timer = new StopWatch();

        //
        //
        /**
         * getURI localhost:65000/xxx/sayHi
         * getRawPath 获得访问路径 sayHi
         */
        timer.start(exchange.getRequest().getURI().getRawPath());

        // 获得所有Attributes 向 Attributes 添加新属性
//        exchange.getAttributes().put("requestTimeBegin", System.currentTimeMillis());

        /**
         * then 前面的方法处理完了 在最后调用 then 方法
         */
        return chain.filter(exchange).then(
                /**
                 * 实际底层用钩子做回调
                 * 开启一个新的线程
                 */
                Mono.fromRunnable(()->{
                    // 计时停止
                    timer.stop();

                    log.info(timer.prettyPrint());
                })
        );
    }

    @Override
    public int getOrder() {
        return 0;
    }
}


```

重新启动

![](https://tcs.teambition.net/storage/3121091ebf476c71662ed459fc4210289e5f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYzNSwiaWF0IjoxNjExODQzODM1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwOTFlYmY0NzZjNzE2NjJlZDQ1OWZjNDIxMDI4OWU1ZiJ9.EOxNzjEdeEjVw9qX0eQP3j8OFC0Jq_zNQ7cxLytes6k&download=image.png "")

![](https://tcs.teambition.net/storage/31218cd970a8a3dccbc6f5e4375562d02e07?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYzNSwiaWF0IjoxNjExODQzODM1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4Y2Q5NzBhOGEzZGNjYmM2ZjVlNDM3NTU2MmQwMmUwNyJ9.7v_vs1_G5HNQFaEOx9w56bce6cMTqFabpLk5MBIel20&download=image.png "")

![](https://tcs.teambition.net/storage/312177551fcb18d21a3be50811b536079eea?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYzNSwiaWF0IjoxNjExODQzODM1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3NzU1MWZjYjE4ZDIxYTNiZTUwODExYjUzNjA3OWVlYSJ9._cnbgm24-3YUWlWIhjpzDhjVWANUEpi_rjsOePurSwQ&download=image.png "")

全局filter 会带上java

普通的filter 不会带上java

![](https://tcs.teambition.net/storage/3121918cd0ab06e2794c93fe9f9c449370ae?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYzNSwiaWF0IjoxNjExODQzODM1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5MThjZDBhYjA2ZTI3OTRjOTNmZTlmOWM0NDkzNzBhZSJ9.Gh3kaoObqMlFYKAHF_iolCLD9tJJRSr_aUGrI9ACpYM&download=image.png "")

```java
package com.imooc.springcloud;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cloud.gateway.route.RouteLocator;
import org.springframework.cloud.gateway.route.builder.RouteLocatorBuilder;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.core.annotation.Order;
import org.springframework.http.HttpMethod;

import java.time.ZonedDateTime;

@Configuration
public class GatewayConfiguration {


    @Autowired
    private TimerFilter timerFilter;

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
                                .addResponseHeader("java-param", "gateway-config")
                                /**
                                 * 添加自定义 filter
                                 */
                                .filter(timerFilter)
//                                .filter(timerFilter)
                        )
                        .uri("lb://FEIGN-CLIENT")
                )
                .route(r -> r.path("/seckill/**")
                                .and()
                                /**
                                 * 告诉 Gateway 当前的这个路由规则 只在某个时间点以后生效
                                 * now 也就是当前的时间点
                                 * 它是说 当你服务启动加载完成以后 往后推迟一分钟生效
                                 * 也就是 一分钟后才生效的秒杀场景
                                 * before 是说在某个时间点以前 路由规则才生效 过了这个时间点就生效
                                 * between 这个路由规则 会在这两个时间段生效
                                 */
                                .after(ZonedDateTime.now().plusMinutes(1))
//                        .and().before()
//                        .and().between()
                                .filters(f -> f.stripPrefix(1))
                                .uri("lb://FEIGN-CLIENT")
                )
                // 把当前 builder 所有的属性全部组装最终返回一个完整的 RouteLocator 对象
                .build();

    }

}

```

![](https://tcs.teambition.net/storage/312112b133b20cbde92216b7c36f7857397c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYzNSwiaWF0IjoxNjExODQzODM1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExMmIxMzNiMjBjYmRlOTIyMTZiN2MzNmY3ODU3Mzk3YyJ9.5ZvG8p-HRc5Y_hjdyplYzUmLfwQicRTGYGJkf1IXmEg&download=image.png "")

```java
package com.imooc.springcloud;

import lombok.extern.slf4j.Slf4j;
import org.springframework.cloud.gateway.filter.GatewayFilter;
import org.springframework.cloud.gateway.filter.GatewayFilterChain;
import org.springframework.cloud.gateway.filter.GlobalFilter;
import org.springframework.core.Ordered;
import org.springframework.stereotype.Component;
import org.springframework.util.StopWatch;
import org.springframework.web.server.ServerWebExchange;
import reactor.core.publisher.Mono;

/**
 * 实现 GatewayFilter 过滤器接口
 * GlobalFilter 全局过滤器 会作用全局的路由规则当中
 * 实现 过滤器执行顺序接口
 */
@Slf4j
@Component
//public class TimerFilter implements GlobalFilter, Ordered {
public class TimerFilter implements GatewayFilter, Ordered {

    @Override
    public Mono<Void> filter(ServerWebExchange exchange, GatewayFilterChain chain) {
        /**
         * 给接口计时 打出 log
         */
        StopWatch timer = new StopWatch();

        //
        //
        /**
         * getURI localhost:65000/xxx/sayHi
         * getRawPath 获得访问路径 sayHi
         */
        timer.start(exchange.getRequest().getURI().getRawPath());

        // 获得所有Attributes 向 Attributes 添加新属性
//        exchange.getAttributes().put("requestTimeBegin", System.currentTimeMillis());

        /**
         * then 前面的方法处理完了 在最后调用 then 方法
         */
        return chain.filter(exchange).then(
                /**
                 * 实际底层用钩子做回调
                 * 开启一个新的线程
                 */
                Mono.fromRunnable(()->{
                    // 计时停止
                    timer.stop();

                    log.info(timer.prettyPrint());
                })
        );
    }

    @Override
    public int getOrder() {
        return 0;
    }
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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYzNSwiaWF0IjoxNjExODQzODM1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.9kvS9N2Oc1jteRzHyKBfbq-blPx1wFNRQ93sDeJyj_k&download=image.png "")

