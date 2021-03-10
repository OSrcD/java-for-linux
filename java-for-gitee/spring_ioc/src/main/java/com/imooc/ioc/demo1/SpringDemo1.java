package com.imooc.ioc.demo1;

import org.junit.Test;
import org.springframework.beans.factory.BeanFactory;
import org.springframework.beans.factory.xml.XmlBeanFactory;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import org.springframework.context.support.FileSystemXmlApplicationContext;
import org.springframework.core.io.ClassPathResource;
import org.springframework.core.io.FileSystemResource;

import javax.swing.*;

public class SpringDemo1 {


    @Test
    public void demo1() {
//        UserService userService = new UserServiceImpl();
        UserServiceImpl userServiceImpl = new UserServiceImpl();
        userServiceImpl.setName("李四");
        userServiceImpl.sayHello();
    }

    @Test
    public void demo2() {
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("applicationContext.xml");
        UserService userService = (UserService) applicationContext.getBean("userService");
        userService.sayHello();
    }

    @Test
    public void demo3() {

        ApplicationContext applicationContext = new FileSystemXmlApplicationContext("//Users/virtualman/Downloads/applicationContext.xml");

        UserService userService = (UserService)applicationContext.<UserService>getBean("userService");
        userService.sayHello();
    }

    @Test
    public void demo4(){
        BeanFactory beanFactory = new XmlBeanFactory(new ClassPathResource("applicationContext.xml"));
        UserService userService = (UserService)beanFactory.getBean("userService");
        userService.sayHello();
    }

    @Test
    public void demo5(){
        BeanFactory beanFactory = new XmlBeanFactory(new FileSystemResource("//Users/virtualman/Downloads/applicationContext.xml"));
        UserService userService = (UserService)beanFactory.getBean("userService");
        userService.sayHello();
    }
}