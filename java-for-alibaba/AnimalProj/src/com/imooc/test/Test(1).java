package com.imooc.test;

import com.imooc.animal.*;

public class Test {

    public static void main(String[] args) {

        String[] mystr = new String[]{"12"};
        ITest iTest = new ImplementsITest();
        System.out.println(iTest.TEMP);
        System.out.println(ITest.TEMP);
        Animal one = new Cat();
        one.setName("123");
        System.out.println(one.getName());
        System.out.println(one.testString);
        one.setName("花花");
        one.setSpecies("中华田园猫");
        one.eat(); //父类的方法


        System.out.println("============================");

        Dog two = new Dog();
        two.setName("妞妞");
        two.setMonth(1);
        two.eat();
        two.sleep();
        one.eat();


        SuperClass subClass = new SubClass();
        subClass.getName();



    }
}
