package com.opendevel.jdbc.service;


import com.opendevel.jdbc.bean.User;
import com.opendevel.jdbc.dao.UserDAO;

/**
 * UserService
 */

public class UserService {

    private UserDAO userDAO;

    public UserService(){
        userDAO = new UserDAO();
    }


    public User login(String username,String password){
        return userDAO.login(username, password);
    }

    /**
     * 根据Id查询用户信息
     * @return
     */
    public  User getUserById(Long id){

        return userDAO.getUserById(id);

    }


    /**
     * 修改用户信息
     * @param user
     * @return
     */

    public boolean updateUser(User user){
        return userDAO.updateUser(user);
    }


}

