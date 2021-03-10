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


    @Autowired
    private AuthFilter authFilter;

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
                                .filter(authFilter)
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
