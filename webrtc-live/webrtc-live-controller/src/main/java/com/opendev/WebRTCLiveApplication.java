package com.opendev;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;

@SpringBootApplication
@ComponentScan(basePackages = {"com.opendev"})
@EnableWebSecurity
public class WebRTCLiveApplication {

    public static void main(String[] args) {
        SpringApplication.run(WebRTCLiveApplication.class, args);
    }
}
