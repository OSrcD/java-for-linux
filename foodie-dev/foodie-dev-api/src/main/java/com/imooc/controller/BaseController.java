package com.imooc.controller;

import org.springframework.stereotype.Controller;

@Controller
public class BaseController {
    protected static final String FOODIE_SHOPCART = "shopcart";

    protected static final Integer COMMENT_PAGE_SIZE = 10;
    protected static final Integer PAGE_SIZE = 20;

    // 微信支付成功 -> 支付中心 -> 天天吃货平台
    //                       -> 回调通知的url
    String payReturnUrl = "http://localhost:8088/orders/notifyMerchantOrderPaid";
}
