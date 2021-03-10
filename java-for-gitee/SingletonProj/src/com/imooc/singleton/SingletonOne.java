package com.imooc.singleton;

public class SingletonOne {

    private SingletonOne(){

    }

    private static SingletonOne instance = new SingletonOne();

    public static SingletonOne getInstance(){
        return SingletonOne.instance;
    }

}
