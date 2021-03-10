package com.imooc.os.service.impl1;

import com.imooc.os.dao.OrderDao;
import com.imooc.os.dao.ProductDao;
import com.imooc.os.entity.Order;
import com.imooc.os.entity.Product;
import com.imooc.os.service.OrderService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.PlatformTransactionManager;
import org.springframework.transaction.TransactionDefinition;
import org.springframework.transaction.TransactionStatus;

import java.util.Date;

@Service
public class OrderServiceImpl implements OrderService {

    @Autowired
    private OrderDao orderDao;

    @Autowired
    private ProductDao productDao;

    @Autowired
    private PlatformTransactionManager transactionManager;

    @Autowired
    private TransactionDefinition transactionDefinition;



    public void addOrder(Order order) {
        order.setCreateTime(new Date());
        order.setStatus("待付款");

        // 开启一个事务，获取一个运行的事务状态，相当于MySQL中的Begin
        TransactionStatus transactionStatus = transactionManager.getTransaction(transactionDefinition);
        try {
            orderDao.insert(order);
            Product product = productDao.select(order.getProductsId());
            product.setStock(product.getStock() - order.getNumber());
            productDao.update(product);

            // 提交事务
            transactionManager.commit(transactionStatus);
        }catch(Exception e){
            e.printStackTrace();
            // 出现异常则回滚事务
            transactionManager.rollback(transactionStatus);
        }

    }
}
