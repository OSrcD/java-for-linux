package com.imooc.test;

public interface IFather2 {
    void fly();

    default void connection(){
        System.out.println("IFather2中的connections");
    }

    static void stop(){
        System.out.println("我是接口中的静态方法");
    }
}
