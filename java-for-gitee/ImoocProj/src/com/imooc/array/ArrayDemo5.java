package com.imooc.array;

import javax.xml.transform.Source;
import java.util.Scanner;

public class ArrayDemo5 {

    public static void main(String[] args) {
        int[][] intArr;
        String str[][];
        double[] doubleArr[];

        intArr = new int[][]{{1,2,3},{12,3}};
        intArr = new int[4][4];
        // 第3行 第3列元素
        System.out.println(intArr[2][2]);

        intArr[1][0] = 5;
        System.out.println(intArr[1][0]);

        float[][] floatArr;
        floatArr = new float[][]{{},{},{},{}};// 指定4行 各行空列
        int[][] myar = {{1,2},{3,4,5}}; // 2行 第一行 2列 第二行 3列

        floatArr = new float[][]{}; // 指定空行 空列 空数组
        floatArr = new float[3][]; // 指定 3行

        floatArr[0] = new float[3]; // 第一行，创建3列
        floatArr[1] = new float[4];
        System.out.println(floatArr[0][0]);



        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
    }
}
