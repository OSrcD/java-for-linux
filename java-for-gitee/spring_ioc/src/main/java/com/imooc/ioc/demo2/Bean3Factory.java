package com.imooc.ioc.demo2;

public class Bean3Factory {

    public Bean3 createBean3(){
        System.out.println("Bean3Factory执行了...");
        return new Bean3();
    }
}
