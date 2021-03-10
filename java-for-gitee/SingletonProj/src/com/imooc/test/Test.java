package com.imooc.test;

import com.imooc.singleton.SingletonOne;
import com.imooc.singleton.SingletonTwo;

public class Test {


    public static void main(String[] args) {
        SingletonOne singletonOne = SingletonOne.getInstance();
        SingletonOne singletonTwo = SingletonOne.getInstance();
        System.out.println(singletonOne);
        System.out.println(singletonTwo);

        SingletonTwo singleonTwo = SingletonTwo.getInstance();
        SingletonTwo singleonTwo2 = SingletonTwo.getInstance();

        System.out.println(singleonTwo);
        System.out.println(singleonTwo2);
    }

}
