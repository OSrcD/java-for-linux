package com.itmuch.contentcenter;


import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import org.springframework.cloud.alibaba.sentinel.annotation.SentinelRestTemplate;
import org.springframework.cloud.client.loadbalancer.LoadBalanced;

import org.springframework.cloud.openfeign.EnableFeignClients;

import org.springframework.cloud.stream.annotation.EnableBinding;
import org.springframework.cloud.stream.messaging.Source;
import org.springframework.context.annotation.Bean;
import org.springframework.web.client.RestTemplate;


import tk.mybatis.spring.annotation.MapperScan;

import java.util.Collections;


@MapperScan("com.itmuch.contentcenter.dao")
@SpringBootApplication
@EnableFeignClients //(defaultConfiguration = GlobalFeignConfiguration.class)
@EnableBinding(Source.class)
public class ContentCenterApplication {
    public static void main(String[] args) {

        SpringApplication.run(ContentCenterApplication.class);


    }

    @Bean
    @LoadBalanced
    @SentinelRestTemplate
    public RestTemplate restTemplate(){

        RestTemplate restTemplate = new RestTemplate();

        restTemplate.setInterceptors(
                Collections.singletonList(
                        new TestRestTemplateTokenRelayInterceptor()
                )
        );

        return restTemplate;

    }

}

