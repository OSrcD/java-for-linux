package com.imooc.aop.demo2;

import org.junit.Test;

public class SpringDemo2 {

    @Test
    public void demo1(){
        ProductDao productDao = new ProductDao();
        ProductDao proxy = (ProductDao)new MyCglibProxy(productDao).createProxy();

        proxy.save();
        proxy.update();
        proxy.delete();
        proxy.find();
    }
}
