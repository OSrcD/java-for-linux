package com.imooc.thread;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class MyThread extends Thread{
    static int staticProperties = 0;
    List<Integer> myList = new ArrayList<Integer>();
    public void run(){

        System.out.println(this.getName());
    }
}

public class demo1 {
    public static void main(String[] args) {
        new MyThread().start();
        Scanner sc = new Scanner(System.in);
        while(true){
            System.out.println("请输入");
            sc.next();
            MyThread.staticProperties++;
        }
    }
}
