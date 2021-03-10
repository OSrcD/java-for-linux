package com.itmuch.boot;

import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.bind.annotation.GetMapping;


@RestController
public class TestController {

    @GetMapping("/test")
    public String test(){

        return "test";
    }
}
