package com.imooc.handler;

import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.mvc.Controller;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class MyHandler implements Controller {

    @Override
    public ModelAndView handleRequest(HttpServletRequest httpServletRequest ,HttpServletResponse httpServletResponse) throws Exception{
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.addObject("name","Tom");
        modelAndView.setViewName("show");
        return modelAndView;
    }



}
