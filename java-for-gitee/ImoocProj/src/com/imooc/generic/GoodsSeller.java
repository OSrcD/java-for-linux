package com.imooc.generic;

import java.util.ArrayList;
import java.util.List;

public class GoodsSeller {

    public void sellGoods(List<? super Object> goods){

    }

    public <T extends Integer> void sellGoods2( T goods){

    }

    public static void main(String[] args) {
        ArrayList<?> iqwqwq = new ArrayList<Float>();
        iqwqwq.get(0);
    }



}
