package com.imooc.handler;

import com.imooc.handler.entity.Goods;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;

import java.util.Map;

@Controller
public class AnnotationHandler {

    @RequestMapping("/modelAndViewTest")
    public ModelAndView modelAndView(){
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.addObject("name","Tom");
        modelAndView.setViewName("show");
        return modelAndView;
    }

    @RequestMapping("/ModelTest")
    public String ModelTest(Model model){
        model.addAttribute("name","Jerry");
        return "show";
    }

    @RequestMapping("/MapTest")
    public String MapTest(Map<String,String> map){
        map.put("name","Cat");
        return "show";
    }

    @RequestMapping("/addGoods")
    public ModelAndView addGoods(Goods goods){
        System.out.println(goods);
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("show");
        return modelAndView;
    }
}
