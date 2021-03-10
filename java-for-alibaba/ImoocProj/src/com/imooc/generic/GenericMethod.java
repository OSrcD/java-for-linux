package com.imooc.generic;


import java.util.Scanner;

public class GenericMethod {

    static{
        System.out.println("我是外部类静态");
    }

    public static int w=1;





    public static class myclass{

        public static int g = w;

        {
            System.out.println("构造代码块");
        }

        public myclass(){
            System.out.println("我是myclass构造方法");
        }

        static{
            System.out.println("静态代码块");
        }
    }

    public static void main(String[] args) {
        myclass qw = new myclass();

        Scanner sc = new Scanner(System.in);

        while(true){
            System.out.println("输入b");
            w = sc.nextInt();
            System.out.println("输入a");
            myclass.g = sc.nextInt();
            System.out.println(" a="+myclass.g+" b="+w);
        }
    }

}
