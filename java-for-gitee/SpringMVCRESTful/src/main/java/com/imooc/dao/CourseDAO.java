package com.imooc.dao;

import com.imooc.entity.Course;
import org.springframework.stereotype.Repository;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

@Repository
public class CourseDAO {
    private Map<Integer, Course> courses = new HashMap<>();

    public void add(Course course){
        courses.put(course.getId(),course);
    }

    public Collection<Course> getAll(){
        return courses.values();
    }

    public Course getById(int id){
        return courses.get(id);
    }

    public void update(Course course){
        courses.put(course.getId(),course);

    }

    public void deleteById(int id){
        courses.remove(id);
    }

}
