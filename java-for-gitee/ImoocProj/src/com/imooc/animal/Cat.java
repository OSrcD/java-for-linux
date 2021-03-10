package com.imooc.animal;

public class Cat {

    String name;

    static String staticString;

    {
        System.out.println("我是构造代码块2");
    }

    {
        System.out.println("我是构造代码块1");
    }

    static{
        System.out.println("我是静态代码块");
        Cat.staticString = "wqeqw";
        Cat cat = new Cat();
        cat.name = "I am cat";
        cat.staticString = "";
    }

    public Cat(){
        final String i;
    }


    public void run(){

//        int temp = 15;


        {
            int temp = 12;

        }

        {
            System.out.println("我是普通代码块1");

        }

//        System.out.println("快跑"+ temp);
//        int temp = 15;
//        System.out.println(temp);
        {
            System.out.println("我是普通代码块2");
        }

        {
//            int temp = 13;
        }

    }



}
