package com.imooc.oa.controller;

import com.imooc.oa.biz.GlobalBiz;
import com.imooc.oa.entity.Employee;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import javax.servlet.http.HttpSession;

@Controller("globalController")
public class GlobalController {

    @Autowired
    private GlobalBiz globalBiz;

    @RequestMapping("/to_login")
    public String toLogin(){
        return "login";
    }


    @RequestMapping("/login")
    public String login(HttpSession httpSession,@RequestParam String sn,@RequestParam String password){
        Employee employee = globalBiz.login(sn, password);

        if(employee == null){
            return "redirect:to_login";
        }

        httpSession.setAttribute("employee",employee);

        return "redirect:self";
    }

    @RequestMapping("/self")
    public String self(){
        return "self";
    }

    @RequestMapping("/quit")
    public String quit(HttpSession httpSession){
        httpSession.setAttribute("employee","null");

        return "redirect:to_login";
    }


    @RequestMapping("/to_change_password")
    public String toChangePassword(){
        return "change_password";
    }


    @RequestMapping("/change_password")
    public String changePssword(HttpSession httpSession,@RequestParam String old,@RequestParam String new1,@RequestParam String new2){
        Employee employee = (Employee) httpSession.getAttribute("employee");
        if(employee.getPassword().equals(old)){
            if(new1.equals(new2)){
                globalBiz.changePassword(employee);
                return "redirect:self";
            }
        }
        return "redirect:to_change_passowrd";

    }





}
