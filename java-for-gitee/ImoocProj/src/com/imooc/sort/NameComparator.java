package com.imooc.sort;

import java.util.Comparator;

public class NameComparator implements Comparator<Cat> {

    @Override
    public int compare(Cat o1,Cat o2){
        String name1 = o1.getName();
        String name2 = o2.getName();

        int n = name1.compareTo(name2);
        System.out.println("n= "+n+" name1= " + name1 + " name2= "+ name2);
        return n;

    }
}
