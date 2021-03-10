package com.imooc.aop.demo5;

public class StudentDaoImpl implements StudentDao {
    @Override
    public void save() {
        System.out.println("学生保存...");
    }

    @Override
    public void delete() {
        System.out.println("学生删除...");
    }

    @Override
    public void update() {
        System.out.println("学生修改...");
    }

    @Override
    public void find() {
        System.out.println("学生查询...");
    }
}
