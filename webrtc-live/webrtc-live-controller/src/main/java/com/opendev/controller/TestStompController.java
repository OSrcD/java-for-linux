package com.opendev.controller;

import com.opendev.domain.Users;
import com.opendev.domain.manager.UserManager;
import org.springframework.messaging.handler.annotation.MessageMapping;
import org.springframework.messaging.handler.annotation.SendTo;
import org.springframework.stereotype.Controller;

import java.security.Principal;

@Controller
public class TestStompController {

    @MessageMapping("/test")
    @SendTo("/topic/test")
    public String test(String body, Principal principal) {
        System.out.println("body = " + body + "principal = " + principal.getName());
        Users users = UserManager.users.get(principal.getName());
        System.out.println(users);
        return "test";
    }



}
