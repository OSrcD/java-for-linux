package com.imooc.flow1;

public class ForDemo1 {
    public static void main(String[] args) {
        int i = 1;
        for(;;){
            System.out.println(i);
            i++;
            if(i==5){
              break;
            }
        }

        System.out.println("test");
        System.out.println("test2");
    }
}
