package com.imooc.test;

public interface IFather {
    void say();

    static void stop(){
        System.out.println("我是接口中的静态方法");
    }
}
