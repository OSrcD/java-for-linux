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
