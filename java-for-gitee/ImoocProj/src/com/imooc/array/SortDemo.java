package com.imooc.array;

public class SortDemo {
    public static void main(String[] args) {
//        34 53 12 32 56 17
        /**
         * 冒泡排序
         */
        int[] arr = {34,53,12,32,56,17};
        int temp;
        for(int i=0;i<arr.length-1;i++){ // arr.length-1 最后一个元素不用比较了 不-1也行，会执行到内层循环判断0<0

            /**
             * 下标是从0开始的，-1是防止j+1越界，两两比较，5次的下标就是4，j+1就是=5最大下标，<号不包括5本身了
             * 不-1就是6，6次下标就是5，不包括6本身，如果j+1下标就是6了，会发生下标越界
             * -i就是每趟排序后的需待排的次数，后面已经排序好的不用在内层循环里面排序了
             */
            for(int j=0;j<arr.length-i-1;j++){
                if(arr[j] > arr[j+1]){ // > 表示前面的元素大于后面的元素

                    temp = arr[j]; // 前面大的元素存放到temp中
                    arr[j] = arr[j+1]; // 后面小的元素向前移
                    arr[j+1] = temp; // 前面大的元素向后移

                }
            }
        }

        for(int a:arr){
            System.out.print(a+" ");
        }
    }
}
