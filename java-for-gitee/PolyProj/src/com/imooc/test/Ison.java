package com.imooc.test;

public interface Ison extends IFather,IFather2 {
    void run();

    @Override
    default void say() {
        this.connection();
        IFather.stop();

    }

    static void stop(){
        System.out.println("我是接口中的静态方法");
    }


    @Override
    default void fly() {

    }
}
