package com.imooc.anonymous;

import javax.xml.transform.Source;
import java.sql.SQLOutput;
import java.util.HashMap;
import java.util.*;
import java.util.Map.Entry;

public class GenericClass {
    private  int w=5;

    public static class mystaticClass{
         int i=5;
         int b = i;

         public void test(){

         }

         public void test2(){
             test();
         }
    }

    public static  void main(String[] args) {
        int[] arr = {2,1,4};

        Arrays.sort(arr);

        for (int i : arr) {
            System.out.println(i);
        }

    }


}


