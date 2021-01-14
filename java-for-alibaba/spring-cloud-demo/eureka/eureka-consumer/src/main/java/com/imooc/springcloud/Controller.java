package com.imooc.springcloud;

import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cloud.client.ServiceInstance;
import org.springframework.cloud.client.loadbalancer.LoadBalancerClient;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.client.RestTemplate;

@RestController
@Slf4j
public class Controller {

    @Autowired
    // 简易的LBC
    private LoadBalancerClient client;

    @Autowired
    private RestTemplate restTemplate;


    @GetMapping("/hello")
    public String hello() {
        /**
         * 拿到服务提供者实例
         * client.choose 从注册中心拉取到服务列表中 挑选一个 可用的 服务提供者
         * 参数就是服务名称
         **/
        ServiceInstance instance = client.choose("eureka-client");

        if (instance == null) {
            return "No available instances";
        }

        // 目标地址
        String target = String.format("http://%s:%s/sayHi",
                instance.getHost(),
                instance.getPort());
        log.info("url is {}", target);

        /**
         * 发起 Get 请求
         * 类型是 String 类型
         */
        return restTemplate.getForObject(target, String.class);

    }

    @PostMapping("/hello")
    public Friend helloPost() {
        ServiceInstance instance = client.choose("eureka-client");

        if (instance == null) {
            return null;
        }

        String target = String.format("http://%s:%s/sayHi",
                instance.getHost(),
                instance.getPort());
        log.info("url is {}", target);

        Friend friend = new Friend();
        friend.setName("Eureka Consumer");
        // 发起Post方法调用 参数值为friend 参数类型为Friend
        return restTemplate.postForObject(target, friend, Friend.class);
    }

}
