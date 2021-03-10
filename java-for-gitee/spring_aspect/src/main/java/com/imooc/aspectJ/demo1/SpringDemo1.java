package com.imooc.aspectJ.demo1;


import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.Objects;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReadWriteLock;
import java.util.concurrent.locks.ReentrantReadWriteLock;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration("classpath:applicationContext.xml")
public class SpringDemo1 {

    @Resource(name="productDao")
    private ProductDao productDao;

    @Test
    public void demo1(){
        productDao.save();
        productDao.update();
        productDao.delete();
        productDao.findAll();
        productDao.findOne();

    }







}
