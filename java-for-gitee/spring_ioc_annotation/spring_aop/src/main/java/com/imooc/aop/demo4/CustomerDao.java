package com.imooc.aop.demo4;

import org.junit.Test;

import java.util.Optional;

public class CustomerDao {




    public void find(){
        System.out.println("查询客户...");
    }

    public void save(){
        System.out.println("保存客户...");
    }

    public void update(){
        System.out.println("修改客户...");
    }

    public void delete(){
        System.out.println("删除客户...");
    }
}
