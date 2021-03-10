package com.imooc.springcloud;

import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

@FeignClient("auth-service")
public interface AuthService {

    @PostMapping("/login")
    @ResponseBody
    AuthResponse login(@RequestParam("username") String username,
                       @RequestParam("password") String password);


    @GetMapping("/verify")
    AuthResponse verify(@RequestParam("token") String token,
                        @RequestParam("username") String username);


    /**
     * 当你token在签发的时候 会给你一个有效期 比如说 2 3 天
     * 过期了就不能再使用了 不想重新登录 就可以使用 refresh 方法
     * 可以理解为备用的 token
     * 通过refresh token 生成一个新的token
     */
    @PostMapping("/refresh")
    @ResponseBody
    AuthResponse refresh(@RequestParam("refresh") String refresh);


}
