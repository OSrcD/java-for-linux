package com.imooc.springcloud;

import lombok.extern.slf4j.Slf4j;
import org.springframework.web.bind.annotation.*;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

@RestController
@Slf4j
@RequestMapping("gateway")
public class GatewayController {

    public static final Map<Long, Product> items = new ConcurrentHashMap<>();

    @RequestMapping(value = "details", method = RequestMethod.GET)
    @ResponseBody
    public Product get(@RequestParam("pid") Long pid) {
        if (!items.containsKey(pid)) {
            Product prod = Product.builder()
                    .productId(pid)
                    .description("好吃不贵")
                    .stock(100L)
                    .build();
            /**
             * 不存在的时候 才 put 有可能两个方法同时执行到了这里 会产生线程不安全的操作
             * 在业务层次上 这可不是线程安全的
             */
            items.putIfAbsent(pid, prod);
        }

        return items.get(pid);

    }

    @RequestMapping(value = "placeOrder", method = RequestMethod.POST)
    public String buy(@RequestParam("pid") Long pid) {
        Product prod = items.get(pid);

        if (prod == null) {
            return "Product not found";
        } else if (prod.getStock() <= 0L) {
            return "Sold out";
        }
        /**
         * 有两个线程同时执行到了这里
         * 哪它接下来 执行 synchronized 的时候 如果不加 if 判断 哪都可能会处于有货状态
         * 就会发生超卖
         */
        synchronized (prod) {
            if (prod.getStock() <= 0L) {
                return "Sold out";
            }
            prod.setStock(prod.getStock() - 1);

        }
        return "Order Placed";
    }
}
