package com.itmuch.contentcenter.feignclient;

import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.GetMapping;

// 脱离ribbon的使用
@FeignClient(name = "baidu",url = "https://www.baidu.com")
public interface TestBaiduFeignClient {
    @GetMapping("")
    String index();
}
