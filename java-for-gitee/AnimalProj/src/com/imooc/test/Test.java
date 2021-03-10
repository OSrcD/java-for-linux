package com.imooc.test;

import com.imooc.animal.Animal;
import com.imooc.animal.Cat;
import com.imooc.animal.Dog;

public class Test {

    public static void main(String[] args) {

        String[] mystr = new String[]{"12"};

        Animal one = new Cat();

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
    }
}
