package com.imooc.array;

public class ArrayDemo6 {
    public static void main(String[] args) {
        int[][] num = {{1,2,3},{4,5,6},{7,8,9}};
        System.out.println(num.length);
        System.out.println(num[0].length);
        int[][] num1 = {{1,2},{3,4,5},{6,7,8,94}};
        System.out.println(num1[0].length);
        System.out.println(num1[1].length);

        for(int i=0;i<num1.length;i++){
            for(int j=0;j<num1[i].length;j++){
                System.out.print(num1[i][j] + " ");
            }
            System.out.println();
        }

        ArrayDemo6.search(5,5,5);
    }

    /**
     *
     * 只能有一个
     * 不能放在第一位
     * 与数组兼容
     * 不能与数组重载
     *
     */
    public static void search(int a, int... b){
        for(int i : b){
            System.out.println(i);
        }
    }
}
