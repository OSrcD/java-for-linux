package com.imooc.config;

import com.imooc.service.OrderService;
import com.imooc.utils.DateUtil;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Component;

@Component
public class OrderJob {

    @Autowired
    private OrderService orderService;

    /**
     * 生产环境订单数据量很大，可能达到上万，十万、百万
     * 时间复杂度为n^2（两个循环），只能处理上万数据、十万数据被卡死（小型项目）
     * 时间复杂度为n（一个循环），只能处理亿级数据、十亿将卡死
     * 时间复杂度为nlogn，只能处理千万级数据，亿级数据将卡死
     * 所谓的时间复杂度就是程序的执行语句次数简化结果
     *
     * 使用定时任务关闭超期未支付订单，会存在弊端：
     * 1. 会有时间差，程序不严谨
     *      10:39下单，11:00检查不足1小时，12:00检查，超过1小时多余39分钟
     * 2. 不支持集群
     *      单机没毛病，使用集群后，就会有多个定时任务
     *      解决方案：只使用一台计算机节点，单独用来运行所有的定时任务
     * 3. 会对数据库全表搜索，及其影响数据库性能 select * from order where orderStatus = 10;
     * 定时任务，仅仅只适用小型轻量级项目，传统项目
     *
     * 后续课程会涉及到消息队列：MQ-> RabbitMQ，RocketMQ，Kafka，ZeroMQ...
     *      延时任务（队列）
     *      10:12分下单，未付款（10）状态，11:12分检查，如果当前状态还是10，则直接关闭订单即可
     *
     */

//    @Scheduled(cron = "0/3 * * * * ?")
//    @Scheduled(cron = "0 0 0/1 * * ?")
    public void autoCloseOrder(){
        orderService.closeOrder();
        System.out.println("执行定时任务，当前时间为：" + DateUtil.getCurrentDateString(DateUtil.DATETIME_PATTERN));
    }

}
