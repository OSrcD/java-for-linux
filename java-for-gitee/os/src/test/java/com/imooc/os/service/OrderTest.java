package com.imooc.os.service;

import com.imooc.os.entity.Order;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration("classpath:spring-service6.xml")
public class OrderTest {

    @Autowired
    private OrderService orderService;

    @Test
    public void testAddOrder(){
        Order order = new Order("100014","100002",2,1799,"","","");
        orderService.addOrder(order);
    }
}
