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
