package com.imooc.animal;

public interface ITest2 {

    int TEMP = 20;

    void network();

    default void connection(){
        System.out.println("我是接口中的默认方法");
    }

    static void stop(){
        System.out.println("我是接口中的静态方法");
    }
}
