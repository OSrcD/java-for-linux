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
