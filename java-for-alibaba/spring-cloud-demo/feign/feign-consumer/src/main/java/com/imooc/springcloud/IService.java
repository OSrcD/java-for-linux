package com.imooc.springcloud;

import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.GetMapping;

/**
 * 服务提供者的service name 告诉这个接口
 * 你接下来在里面尝试调用的方法
 * 都发到eureka-client 上 会生成一个代理类
 */
@FeignClient("eureka-client")
public interface IService {

    // @GetMapping 发送到 sayHi方法之上
    @GetMapping("/sayHi")
    String sayHi();
}
