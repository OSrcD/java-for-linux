package com.imooc.method;

import java.util.InputMismatchException;
import java.util.Scanner;

public class ArgsDemo3 {

    public static void test(int a,int b){
        System.out.println("不可变参数");
    }

    public static void test(int... a){
        System.out.println("可变参数");
    }


    public static void main(String[] args)   {
        ArgsDemo3.test(1,3,4,5);
        Scanner sc = new Scanner(System.in);

            for (; ; ) {

                System.out.println("继续输入");
                try {
                    try {
                        sc.nextInt();
                    } catch (InputMismatchException e) {
                        System.out.println("123");
                        try{
                            throw new InputMismatchException();
                        }catch(InputMismatchException d){

                        }


                    }
                }catch(InputMismatchException e){
                    System.out.println("123");
                    sc.next();
                }



        }


    }
}
