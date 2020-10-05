package com.imooc.controller;

import com.imooc.mapper.UsersMapper;
import com.imooc.pojo.bo.UserBO;
import com.imooc.service.UserService;
import com.imooc.utils.IMOOCJSONResult;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.web.bind.annotation.*;

@Api(value="注册登录",tags = {"用于注册登录的相关接口"}) // tags是导航的标题 value不知道
@RestController
@RequestMapping("/passport")
public class PassportController {

    @Autowired
    private UserService userService;

    @ApiOperation(value = "用户名是否存在",notes = "用户名是否存在",httpMethod = "GET") // value是接口名称，可在导航标题下面显示 notes是说明
    @GetMapping("/usernameIsExist")
    public IMOOCJSONResult usernameIsExist(@RequestParam String username) {

        // 1. 判断用户不能为空
        if(StringUtils.isBlank(username)){
            return IMOOCJSONResult.errorMsg("用户名不能为空");
        }

        // 2. 查找用户名是否存在
        boolean isExist = userService.queryUsernameIsExist(username);

        if(isExist){
            return IMOOCJSONResult.errorMsg("用户名已经存在");
        }

        // 3. 请求成功，用户名没有重复
        return IMOOCJSONResult.ok();

    }

    @ApiOperation(value = "用户注册", notes = "用户注册", httpMethod = "POST") // value是接口名称，可在导航标题下面显示 notes是说明
    @PostMapping("/regist")
    public IMOOCJSONResult regist(@RequestBody UserBO userBO){
        String username = userBO.getUsername();
        String password = userBO.getPassword();
        String confirmPwd = userBO.getConfirmPassword();

        // 0. 判断用户名和密码必须不为空
        if(StringUtils.isBlank(username) ||
                StringUtils.isBlank(password) ||
                StringUtils.isBlank(confirmPwd)){

            return IMOOCJSONResult.errorMsg("用户名或密码不能为空");
        }
        // 1. 查询用户名是否存在
        boolean isExist = userService.queryUsernameIsExist(username);
        if(isExist){
            return IMOOCJSONResult.errorMsg("用户名已经存在");
        }

        // 2. 密码长度不能少于6位
        if(password.length() < 6){
            return IMOOCJSONResult.errorMsg("密码长度不能少于6");
        }

        // 3. 判断两次密码是否一致
        if(!password.equals(confirmPwd)){
            return IMOOCJSONResult.errorMsg("两次密码输入不一致");
        }

        // 4.实现注册
        userService.createUser(userBO);

        return IMOOCJSONResult.ok();

    }

}
