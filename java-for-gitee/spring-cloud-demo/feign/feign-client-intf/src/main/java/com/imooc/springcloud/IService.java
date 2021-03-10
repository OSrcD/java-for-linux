package com.imooc.springcloud;

import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestParam;

@FeignClient("feign-client")
public interface IService {

    @GetMapping("/error")
    String error();

    @GetMapping("/sayHi")
    String sayHi();

    @PostMapping("/sayHi")
    Friend sayHiPost(@RequestBody Friend friend);

    @GetMapping("/retry")
    String retry(@RequestParam(name = "timeout") int timeout);
}
