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
