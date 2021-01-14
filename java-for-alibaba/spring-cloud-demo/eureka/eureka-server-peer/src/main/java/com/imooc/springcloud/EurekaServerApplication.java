package com.imooc.springcloud;

import org.springframework.boot.WebApplicationType;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.builder.SpringApplicationBuilder;
import org.springframework.cloud.netflix.eureka.server.EnableEurekaServer;

@SpringBootApplication
// 识别为 EurekaServer 注册中心
@EnableEurekaServer
public class EurekaServerApplication {
    public static void main(String[] args) {

        // 从Builder 构建一个启动类
        new SpringApplicationBuilder(EurekaServerApplication.class)
                // 定义启动方式 为 SERVLET形式
                .web(WebApplicationType.SERVLET)
                .run(args);

    }
}
