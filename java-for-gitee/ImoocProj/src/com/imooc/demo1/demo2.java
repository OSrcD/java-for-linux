package com.imooc.demo1;

import com.sun.media.sound.SoftTuning;

import java.io.FileDescriptor;
import java.util.Scanner;

public class demo2 {
    public static int age;

    public Object getHeart(){

        class Heart{
            public int age = 13;
            int temp = 22;

            public void say(){
                System.out.println("say");
            }

            public void eat(){
                System.out.println("eat");
            }

            public String beant(){
                return "I am bean";
            }

            @Override
            public String toString() {
                return "Heart{" +
                        "age=" + age +
                        ", temp=" + temp +
                        '}';
            }
        }
        return new Heart();
    }

    public static void main(String[] args) {
        Object heart = new demo2().getHeart();
        System.out.println(heart.toString());
        new Runnable(){

            {


            }

            @Override
            public void run() {

            }
        };
    }
}
