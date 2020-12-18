package com.itmuch.gateway;

import lombok.extern.slf4j.Slf4j;
import org.springframework.cloud.gateway.filter.GatewayFilter;
import org.springframework.cloud.gateway.filter.OrderedGatewayFilter;
import org.springframework.cloud.gateway.filter.factory.AbstractNameValueGatewayFilterFactory;
import org.springframework.http.server.reactive.ServerHttpRequest;
import org.springframework.stereotype.Component;
import org.springframework.web.server.ServerWebExchange;

@Slf4j
@Component
public class PreLogGatewayFilterFactory extends AbstractNameValueGatewayFilterFactory {

    @Override
    public GatewayFilter apply(NameValueConfig config) {

        GatewayFilter filter = ((exchange,chain) -> {
            log.info("请求进来了...{},{}",config.getName(),config.getValue());
            ServerHttpRequest serverHttpRequest = exchange.getRequest()
                    .mutate()
                    .build();
            ServerWebExchange serverWebExchange = exchange.mutate()
                    .request(serverHttpRequest)
                    .build();
            return chain.filter(serverWebExchange);
        });

        return new OrderedGatewayFilter(filter,10000);
    }
}
