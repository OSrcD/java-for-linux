package com.imooc.project.service;

import com.imooc.project.entity.Person;
import com.imooc.project.util.PageUtil;

import java.util.List;

public interface UserService {
    public PageUtil getAllUsers(String num) throws Exception;


    public List<Person> getAllUsersBypageHelper();
}
