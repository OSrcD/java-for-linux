package com.imooc.enums;

/**
 * @Description: 订单状态 枚举
 */
public enum OrderStatusEnum {

    WAIT_PAY(10,"待付款"),
    WAIT_DELIVER(20,"已付款，待发货"),
    WAI_RECEIVE(30,"已发货，待收货"),
    SUCCESS(40,"交易成功"),
    CLOSE(50,"交易失败");

    public final Integer type;
    public final String value;

    OrderStatusEnum(Integer type,String value){
        this.type = type;
        this.value = value;
    }
}
