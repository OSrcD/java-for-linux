package com.imooc.os.dao;

import com.imooc.os.entity.Order;

import java.util.List;

public interface OrderDao {
    void insert(Order order);
    void update(Order order);
    void delete(String id);
    Order select(String id);
    List<Order> select();
}
