package com.imooc.controller;


import com.imooc.dao.CourseDAO;
import com.imooc.entity.Course;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.ModelAndView;

@Controller
public class CourseController {
    @Autowired
    private CourseDAO courseDAO;

    /**
     * 添加课程
     */
    @PostMapping(value = "/add")
    public String add(Course course){
        courseDAO.add(course);
        return "redirect:/getAll";
    }

    /**
     * 查询全部课程
     * @return
     */

    @GetMapping(value = "/getAll")
    public ModelAndView getAll(){
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("index");
        modelAndView.addObject("courses",courseDAO.getAll());

        return modelAndView;
    }

    /**
     * 通过id查询课程
     */

    @GetMapping(value="/getById/{id}")
    public ModelAndView getById(@PathVariable(value = "id") int id){

        ModelAndView modelAndView = new ModelAndView();

        modelAndView.setViewName("edit");
        modelAndView.addObject("course",courseDAO.getById(id));

        return modelAndView;
    }

    /**
     * 修改课程
     * @param course
     * @return
     */

    @PutMapping(value = "/update")
    public String update(Course course){
        courseDAO.update(course);
        return "redirect:/getAll";
    }

    /**
     * 删除课程
     */
    @DeleteMapping(value = "/delete/{id}")
    public String delete(@PathVariable(value="id") int id){
        courseDAO.deleteById(id);

        return "redirect:/getAll";

    }











}
