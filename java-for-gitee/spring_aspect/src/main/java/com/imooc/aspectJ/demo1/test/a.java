package com.imooc.aspectJ.demo1.test;

import org.junit.Test;

public class a {
   private double radius =0;
   private  static  int count =1;



   class Draw{


       public void drawSahpe(){

           System.out.println(radius);
           System.out.println(count);
       }
   }

    public static void main(String[] args) {
        System.out.println(1%3);
    }

}
