package com.imooc.web;

import com.imooc.bean.User;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import javax.servlet.http.HttpSession;

@Controller
public class LoginController {

    @RequestMapping("/login")
    public String login(){
        return "login";
    }

    @RequestMapping("/logined")
    public String logined(@RequestParam("account")String account,
                          @RequestParam("password")String password,
                          HttpSession session){

        if(account.equals("xuke") && password.equals("123456")){
            User user = new User();
            user.setAccount(account);
            user.setPassword(password);
            session.setAttribute("session_user", user);
            return "redirect:user/search";
        }else{
            return "redirect:login";
        }


    }
}
