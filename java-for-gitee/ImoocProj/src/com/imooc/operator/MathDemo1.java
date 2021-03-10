package com.imooc.operator;



public class MathDemo1 {
    public static void main(String[] args){
        int x = 4;
        int y = x++ + 5; // x+5相加为9赋值给y，x再自增为5
        System.out.println(y);

        x = 4;
        y = ++x + 5; // x先自增为5，再与5相加为10，赋值给y
        System.out.println(y);

    }
}
