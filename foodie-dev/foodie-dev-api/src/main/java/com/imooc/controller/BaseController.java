package com.imooc.controller;

import org.springframework.stereotype.Controller;

@Controller
public class BaseController {
    protected static final String FOODIE_SHOPCART = "shopcart";

    protected static final Integer COMMENT_PAGE_SIZE = 10;
    protected static final Integer PAGE_SIZE = 20;

    // 支付中心的调用地址
    String paymenUrl = "http://payment.t.mukewang.com/foodie-payment/payment/createMerchantOrder";

    // 微信支付成功 -> 支付中心 -> 天天吃货平台
    //                       -> 回调通知的url
    String payReturnUrl = "http://120.77.47.215:8080/orders/notifyMerchantOrderPaid";

}
