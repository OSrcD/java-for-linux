package com.imooc.sort;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class GoodsTest {
    public static void main(String[] args) {
        Goods g1 = new Goods("s00001","手机",2000);
        Goods g2 = new Goods("s00002","冰箱",5000);
        Goods g3 = new Goods("s00003","电视机",3000);
        List<Goods> goodsList = new ArrayList<>();
        goodsList.add(g1);
        goodsList.add(g2);
        goodsList.add(g3);
        System.out.println("排序前");
        for (Goods goods : goodsList) {
            System.out.println(goods);
        }


        System.out.println("排序后");

        Collections.sort(goodsList);

        for (Goods goods : goodsList) {
            System.out.println(goods);
        }
    }
}
