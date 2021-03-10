package com.imooc.sort;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class StringSort {
    public static void main(String[] args) {
        /**
         * orange blue yellow gray
         */
        List<String> arrayList = new ArrayList<String>();

        arrayList.add("orange");
        arrayList.add("blue");
        arrayList.add("yellow");
        arrayList.add("gray");

        Collections.sort(arrayList);
        for (String s : arrayList) {
            System.out.println(s);
        }
    }

}
