package com.opendev;


public final class App {
  

  
    public static void main(String[] args) {
        demo mydemo = new demo();
        System.out.println("实例化对象的地址：" + Integer.toHexString(mydemo.test(1,1)));
        System.out.println("对象的hashCode值："+ Integer.toHexString(mydemo.hashCode()));
        System.out.println();
    }
}
