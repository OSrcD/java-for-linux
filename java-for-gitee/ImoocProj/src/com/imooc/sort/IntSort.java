package com.imooc.sort;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class IntSort {
    public static void main(String[] args) {
        List<Integer> arrayList = new ArrayList<>();

        arrayList.add(8);
        arrayList.add(4);
        arrayList.add(2);
        arrayList.add(1);
        ((List)arrayList).add("123");
        Collections.<Integer>sort(arrayList);

        for (Integer integer : arrayList) {
            System.out.println(integer);
        }


    }
}
