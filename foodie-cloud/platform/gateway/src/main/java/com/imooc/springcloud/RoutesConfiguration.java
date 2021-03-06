package com.imooc.springcloud;

import com.imooc.springcloud.filter.AuthFilter;
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

    /**
     * AuthFilter 会自动被注入
     * @param builder
     * @param authFilter
     * @return
     */
    @Bean
    public RouteLocator routes(RouteLocatorBuilder builder, AuthFilter authFilter) {
        return builder.routes()
                // FIXME search服务自己实现
                // Auth在网关层有很多种做法，我用了种最丑的，同学们可以试试其他姿势
                // 1) 【最常用】网关层或微服务自己本地校验jwt token有效性，不向auth-service发起远程调用
                // 2) 【路由配置最简单】可以把AuthFilter注册为global filter，
                //     然后在AuthFilter里配置需要过滤的url pattern(也可以从config-server动态拉取)
                // 3) 【路由配置也简单】也可以采用interceptor的形式
                // 4) 【路由配置最丑】这就是我选的路，只是为了演示下自定义过滤器，才走了这条不归路
                // 要注意声明URL Pattern的先后顺序，一个URL可能匹配多个路由，先来后到
                //
                // FIXME
                // 1) 将其他需要登录校验的地址添加在下面，或者采用上面提到的其他方案改造登录检测过程
                // 2) 修改前端JS代码，记得把login后返回的jwt-token和refresh-token带到每个请求的header里
                // 3) 前端JS依据header中的Authorization来判断是否登录
                /**
                 * 验证与鉴权
                 */
                .route(r -> r.path("/address/list",
                        "/address/add",
                        "/address/update",
                        "/address/setDefault",
                        "/address/delete",
                        "/userInfo/**", "/center/**")
                        .filters(f -> f.filter(authFilter))
                        // 不会 js 就让他不起作用
//                        .filters(f -> f.filter(authFilter))
                        .uri("lb://FOODIE-USER-SERVICE")
                )

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
