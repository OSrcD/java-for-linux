package com.imooc.controller;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@Controller
public class SSOController {

    @GetMapping("/login")
    public String login(String returnUrl ,
                        Model model,
                        HttpServletRequest request,
                        HttpServletResponse response) {

        model.addAttribute("returnUrl", returnUrl);

        // TODO 后续完善校验是否登录

        // 用户从未登录过，第一次进入侧跳转到CAS的统一登录页面

        return "login";
    }
}
