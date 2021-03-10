package com.imooc.sort;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class CatTest {
    public static void main(String[] args) {
        Cat huahua = new Cat("huahua",5,"英国短毛猫");
        Cat fanfan = new Cat("fanfan",2,"中华田园猫");
        Cat maomao = new Cat("maomao",3,"中华田园猫");
        List<Cat> catList = new ArrayList<>();
        catList.add(huahua);
        catList.add(fanfan);
        catList.add(maomao);

        Collections.sort(catList,new NameComparator());


        for (Cat cat : catList) {
            System.out.println(cat);
        }

        System.out.println("******************************");
        Collections.sort(catList,new AgeComparator());

        for (Cat cat : catList) {
            System.out.println(cat);
        }
    }
}
