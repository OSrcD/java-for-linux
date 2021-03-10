package com.imooc.array;

import javax.xml.transform.Source;

public class ArrayDemo2 {
    public static void main(String[] args) {
//        34 23 78 56 31
        int[] arr = {34,23,78,56,31};
        int max = arr[0];

        for(int i=1;i<arr.length;i++){
            if(max < arr[i]){
               max = arr[i];
            }
        }

        System.out.println(max);
    }

}
