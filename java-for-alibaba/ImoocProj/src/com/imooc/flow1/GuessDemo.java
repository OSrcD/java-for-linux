package com.imooc.flow1;

public class GuessDemo {
    public static void main(String[] args) {
        int number = (int)(Math.random()*10+1); // [0,1)*10 [0,10)+1 [1,11)
        System.out.println(number);
    }
}
