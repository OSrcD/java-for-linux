package com.imooc.demo1;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

import javax.annotation.Resource;

@Component("userService")
public class UserService {

    @Value("米饭")
    private String someting;

//    @Autowired
//    @Qualifier("userDao")
    @Resource(name="userDao")
    private UserDao userDao;


    public String sayHello(String name) {
        return "Hello" + name;
    }

    public void eat() {
        System.out.println("eat:" + someting);
    }

    public void save() {
        System.out.println("Service中保存用户...");
        userDao.save();
    }

}
