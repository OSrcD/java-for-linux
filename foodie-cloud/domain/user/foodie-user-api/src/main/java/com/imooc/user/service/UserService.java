package com.imooc.user.service;

import com.imooc.user.pojo.Users;
import com.imooc.user.pojo.bo.UserBO;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.*;

@FeignClient("foodie-user-service")
@RequestMapping("user-api")
public interface UserService {

    /**
     * 判断用户名是否存在
     * @param username
     * @return
     */
    @GetMapping("user/exists")
    public boolean queryUsernameIsExist(@RequestParam("username") String username);

    /**
     * 创建用户
     * @param userBo
     * @return
     */
    @PostMapping("user")
    public Users createUser(@RequestBody UserBO userBo);

    /**
     * 检索用户名和密码是否匹配，用于登录
     */
    @GetMapping("verify")
    public Users queryUserForLogin(@RequestParam("username") String username,
                                   @RequestParam("password") String password);
}
