package com.imooc.array;

public class ArrayDemo {
    public static void main(String[] args) {
       int[] intArray;
       String strArray[];
       intArray = new int[5];
       strArray = new String[5];
       float[] floatArray = new float[4];
       char[] ch = {'A','B','C','D'};
       System.out.println(floatArray[floatArray.length-1]);
       int[] myArray = new int[]{1,2,3,4,50};
       for(int i=0;i<5;i++){
           System.out.println(myArray[i]);
       }
       for(int i=0;i<5;i++){
           intArray[i] = i+1;
       }

       for(int i=0;i<5;i++){
           System.out.println(intArray[i]);
       }

    }
}
