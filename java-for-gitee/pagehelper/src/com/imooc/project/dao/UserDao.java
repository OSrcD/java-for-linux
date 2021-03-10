package com.imooc.project.dao;

import com.imooc.project.entity.User;

import java.util.List;

public interface UserDao {

    List<User> getAllUsers(int startIndex,int pageSize)throws Exception ;//Limit

    int totalRecords() throws Exception;

}

