package com.imooc.sort;

import javax.xml.transform.Source;
import java.util.Comparator;

public class AgeComparator implements Comparator<Cat> {

    @Override
    public int compare(Cat o1,Cat o2){
        int age1 = o1.getMonth();
        int age2 = o2.getMonth();
        int n = age2 - age1;
        System.out.println("n= "+n+" age1="+age1 + " age2=" + age2);
        return n;
    }
}
