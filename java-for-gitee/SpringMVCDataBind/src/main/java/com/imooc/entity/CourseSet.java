package com.imooc.entity;

import java.util.HashSet;
import java.util.Set;

public class CourseSet {
    private Set<Course> courses = new HashSet<>();

    public Set<Course> getCourses() {
        return courses;
    }

    public void setCourses(Set<Course> courses) {
        this.courses = courses;
    }

    public CourseSet(){
        courses.add(new Course());
        courses.add(new Course());
    }

}
