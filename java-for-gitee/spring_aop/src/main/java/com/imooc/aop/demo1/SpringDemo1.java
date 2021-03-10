package com.imooc.aop.demo1;

import org.junit.Test;

public class SpringDemo1 {

    @Test
    public void demo1(){
        UserDao userDao = new UserDaoImpl();//目标类

        UserDao proxy =(UserDao) new MyJdkProxy(userDao).createProxy();

        proxy.save();
        proxy.update();
        proxy.delete();
        proxy.find();
    }
}
