package com.imooc.controller;

import com.imooc.pojo.Orders;
import com.imooc.service.center.MyOrdersService;
import com.imooc.utils.IMOOCJSONResult;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;

import java.io.File;

@Controller
public class BaseController {
    public static final String FOODIE_SHOPCART = "shopcart";

    public static final Integer COMMON_PAGE_SIZE = 10;
    public static final Integer PAGE_SIZE = 20;

    // 支付中心的调用地址
    public String paymenUrl = "http://payment.t.mukewang.com/foodie-payment/payment/createMerchantOrder";

    // 微信支付成功 -> 支付中心 -> 天天吃货平台
    //                       -> 回调通知的url
    public String payReturnUrl = "http://api.z.opendevel.gq:8088/foodie-dev-api/orders/notifyMerchantOrderPaid";

    public final String IMAGE_USER_FACE_LOCATION = File.separator + "Users"+
                                                    File.separator + "virtualman"+
                                                    File.separator + "Downloads" +
                                                    File.separator + "temp"+
                                                    File.separator + "workspace" +
                                                    File.separator + "images" +
                                                    File.separator + "foodie" +
                                                    File.separator + "faces";


    @Autowired
    public MyOrdersService myOrdersService;

    public IMOOCJSONResult checkUserOrder(String userId, String orderId) {
        Orders orders = myOrdersService.queryMyOrder(userId,orderId);
        if(orders == null){
            return IMOOCJSONResult.errorMsg("订单Id不存在！");
        }
        return IMOOCJSONResult.ok(orders);
    }

}
