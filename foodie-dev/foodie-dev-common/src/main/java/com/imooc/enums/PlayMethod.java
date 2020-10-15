package com.imooc.enums;

/**
 * @Description: 支付方式 枚举
 */

public enum PlayMethod {

    WEIXIN(1,"微信"),
    ALIPAY(2,"支付宝");

    public final Integer type;
    public final String value;

    PlayMethod(Integer type, String value) {
        this.type = type;
        this.value = value;
    }
}
