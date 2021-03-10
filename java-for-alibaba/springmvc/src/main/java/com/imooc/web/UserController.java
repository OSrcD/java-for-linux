package com.imooc.web;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

import javax.servlet.http.HttpSession;

@Controller
@RequestMapping("/user")
public class UserController {

    @RequestMapping("/search")
    public String search() {
        System.out.println("2:keketip======-----search------");
        return "user/search";
    }

    @RequestMapping("/updatepwd")
    public String updatepwd() {
        System.out.println("2:keketip======-----updatepwd------");
        return "user/updatepwd";
    }

    @RequestMapping("/updateheaderPic")
    public String updateheaderPic() {
        System.out.println("2:keketip======-----updateheaderPic------");
        return "user/updateheaderPic";
    }

    @RequestMapping("/updatebackground/{id}")
    public String updatebackground(HttpSession httpSession){
        System.out.println("2:keketip======-----updatebackground");
        return "user/test";
    }


}
