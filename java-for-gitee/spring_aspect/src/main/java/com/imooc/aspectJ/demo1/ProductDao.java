package com.imooc.aspectJ.demo1;

import java.util.Map;

public class ProductDao {

    public void save(){
        System.out.println("保存商品...");
    }

    public String update(){
        System.out.println("修改商品...");

        return "hello";
    }

    public void delete(){
        System.out.println("删除商品...");
    }
    public void findOne(){
        System.out.println("查询一个商品...");
//        int i = 1/0;
    }

    public void findAll(){
        System.out.println("查询所有商品...");
//        int j = 1/0;
    }




}
