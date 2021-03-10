package com.imooc.ioc.demo1;

public class UserServiceImpl implements UserService {

    private String name;

    @Override
    public void sayHello() {
        System.out.println("Hello Spring" + name);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
