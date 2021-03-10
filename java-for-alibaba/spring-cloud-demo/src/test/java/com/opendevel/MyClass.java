package com.opendevel;

public class MyClass {

    static {
        System.out.println("静态代码块");
    }

    public static Integer integer = null;

    {
        System.out.println("构造代码块");
    }

}
