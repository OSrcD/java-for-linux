package com.imooc.generic;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Map;

public class NumGeneric<T extends Integer> {



    public  <T extends String> void setNum(T num, Class<T> l){

        T cast = l.cast(new Integer(1));



    }

    public static void main(String[] args){
        NumGeneric numGeneric = new NumGeneric();
        numGeneric.setNum(null,Integer.class);

    }


}
