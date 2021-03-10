package com.imooc.aop.demo6;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import javax.annotation.Resource;


@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration("classpath:applicationContext4.xml")
public class SprinDemo6 {
    @Resource(name = "studentDao")
    private StudentDao studentDao;
    @Resource(name = "customerDao")
    private CustomerDao customerDao;

    @Test
    public void demo1(){
        studentDao.find();
        studentDao.save();

        studentDao.delete();

        customerDao.find();
        customerDao.save();
        customerDao.update();
        customerDao.delete();
    }



}
