package com.imooc.controller;

import com.imooc.dao.CourseDao;
import com.imooc.entity.Course;
import com.imooc.entity.CourseList;
import com.imooc.entity.CourseMap;
import com.imooc.entity.CourseSet;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.servlet.ModelAndView;

@Controller
public class DataBindController {

    @Autowired
    private CourseDao courseDao;

    @RequestMapping(value="/baseType")
    @ResponseBody
    public String baseType(@RequestParam(value="id") int id){
        return "id:" + id;
    }

    @RequestMapping(value="/packageType")
    @ResponseBody
    public String packageType(@RequestParam(value="id") Integer id){
        return "id:" + id;
    }

    @RequestMapping(value="/arrayType")
    @ResponseBody
    public String arrayType(String name[]){

        StringBuffer sb = new StringBuffer();
        for(String item : name){
            sb.append(item).append(" ");
        }

        return sb.toString();
    }


    @RequestMapping(value="/pojoType")
    public ModelAndView pojoType(Course course){
        courseDao.add(course);
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("index");
        modelAndView.addObject("courses",courseDao.getAll());
        return modelAndView;
    }

    @RequestMapping(value="/listType")
    public ModelAndView listType(CourseList courseList){

        for(Course course:courseList.getCourses()){
            courseDao.add(course);
        }

        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("index");
        modelAndView.addObject("courses",courseDao.getAll());
        return modelAndView;

    }

    @RequestMapping(value="/mapType")
    public ModelAndView mapType(CourseMap courseMap){
        for(String key : courseMap.getCourses().keySet()){
            Course course = courseMap.getCourses().get(key);
            courseDao.add(course);
        }

        ModelAndView modelAndView = new ModelAndView();

        modelAndView.setViewName("index");

        modelAndView.addObject("courses",courseDao.getAll());

        return modelAndView;


    }


    @RequestMapping(value="/setType")
    public ModelAndView setType(CourseSet courseSet){
        for (Course course : courseSet.getCourses()) {
            courseDao.add(course);
        }
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.addObject("courses",courseDao.getAll());
        modelAndView.setViewName("index");
        return modelAndView;
    }

    @RequestMapping(value="/jsonType")
    @ResponseBody
    public Course jsonType(@RequestBody Course course){
        course.setPrice(course.getPrice()+100);
        return course;
    }

}
