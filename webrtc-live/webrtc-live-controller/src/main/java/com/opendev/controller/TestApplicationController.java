package com.opendev.controller;

import com.opendev.domain.bo.UserBO;
import com.opendev.utils.IMOOCJSONResult;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("user")
public class TestApplicationController {

    @GetMapping("/app")
    public String app() {
        return "testApp";
    }

    @PostMapping("/login")
    public IMOOCJSONResult login(@RequestBody UserBO userBO) {
        System.out.println(userBO.getUsername());
        System.out.println(userBO.getPassword());
        return IMOOCJSONResult.ok("登录成功");
    }
}



