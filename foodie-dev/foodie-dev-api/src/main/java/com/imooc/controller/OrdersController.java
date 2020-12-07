package com.imooc.controller;

import com.imooc.enums.OrderStatusEnum;
import com.imooc.enums.PlayMethod;
import com.imooc.pojo.OrderStatus;
import com.imooc.pojo.bo.ShopcartBO;
import com.imooc.pojo.bo.SubmitOrderBO;
import com.imooc.pojo.vo.MerchantOrdersVO;
import com.imooc.pojo.vo.OrderVO;
import com.imooc.service.OrderService;
import com.imooc.utils.CookieUtils;
import com.imooc.utils.IMOOCJSONResult;
import com.imooc.utils.JsonUtils;
import com.imooc.utils.RedisOperator;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.*;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.client.RestTemplate;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.util.List;

@Api(value="订单相关",tags={"订单相关的api接口"})

@RequestMapping("orders")
@RestController
public class OrdersController extends BaseController{

    @Autowired
    private OrderService orderService;

    @Autowired
    private RestTemplate restTemplate;

    @Autowired
    private RedisOperator redisOperator;

    @ApiOperation(value="用户下单",notes="用户下单",httpMethod="POST")
    @PostMapping("/create")
    public IMOOCJSONResult create(
            @RequestBody SubmitOrderBO submitOrderBO,
            HttpServletRequest  request,
            HttpServletResponse response){


        if(submitOrderBO.getPayMethod() != PlayMethod.WEIXIN.type
                && submitOrderBO.getPayMethod() != PlayMethod.ALIPAY.type){
            return IMOOCJSONResult.errorMsg("支付方式不支持！");
        }

//        System.out.println(submitOrderBO.toString());


        String shopcartJson = redisOperator.get(FOODIE_SHOPCART + ":" + submitOrderBO.getUserId());
        if (StringUtils.isBlank(shopcartJson)) {
            return IMOOCJSONResult.errorMsg("购物车数据不正确");
        }

        List<ShopcartBO> shopcartList = JsonUtils.jsonToList(shopcartJson, ShopcartBO.class);

        // 1. 创建订单
        OrderVO orderVO = orderService.createOrder(shopcartList,submitOrderBO);
        String orderId = orderVO.getOrderId();

        // 2. 创建订单以后，移除购物车中已结算（已提交）的商品
        /**
         * 1001
         * 2002 -> 用户购买
         * 3003 -> 用户购买
         * 4004
         */

        // 清理覆盖现有的redis汇总的购物数据
        shopcartList.removeAll(orderVO.getToBeRemovedShopcartList());
        redisOperator.set(FOODIE_SHOPCART + ":" + submitOrderBO.getUserId(), JsonUtils.objectToJson(shopcartList));
        // 整合redis之后，完善购物车中的已结算商品清除，并且同步到前端的cookie
        CookieUtils.setCookie(request, response, FOODIE_SHOPCART, JsonUtils.objectToJson(shopcartList), true);

        // 3. 向支付中心发送当前订单，用于保存支付中心的订单数据
        MerchantOrdersVO merchantOrdersVO = orderVO.getMerchantOrdersVO();
        merchantOrdersVO.setReturnUrl(payReturnUrl);

        // 为了方便测试购买，所有的支付金额都统一改为1分钱
        merchantOrdersVO.setAmount(1);

        HttpHeaders headers = new HttpHeaders();
        headers.setContentType(MediaType.APPLICATION_JSON);
        headers.add("imoocUserId","5450049-1004108488");
        headers.add("password","4t43-09oi-rejo-i309");

        HttpEntity<MerchantOrdersVO> entity =
                new HttpEntity<>(merchantOrdersVO,headers);

        ResponseEntity<IMOOCJSONResult> responseEntity =
                restTemplate.postForEntity(paymenUrl,
                                            entity,
                                            IMOOCJSONResult.class);

        IMOOCJSONResult paymenResult = responseEntity.getBody();
        if(paymenResult.getStatus() != 200){
            return IMOOCJSONResult.errorMsg("支付中心订单创建失败，请联系管理员！");
        }

        return IMOOCJSONResult.ok(orderId);
    }

    @PostMapping("notifyMerchantOrderPaid")
    @ApiOperation(value="支付中心回调用户的订单是否已付款",notes="支付中心回调后端用户的订单是否已付款",httpMethod="POST")
    public Integer notifyMerchantOrderPaid(@RequestParam String merchantOrderId){
        orderService.updateOrderStatus(merchantOrderId, OrderStatusEnum.WAIT_DELIVER.type);
        return HttpStatus.OK.value();
    }

    @PostMapping("getPaidOrderInfo")
    @ApiOperation(value="前端轮询查询是否付款",notes="前端轮询查询是否付款",httpMethod="POST")
    public IMOOCJSONResult getPaidOrderInfo(@RequestParam String orderId){
        OrderStatus orderStatus = orderService.queryOrderStatusInfo(orderId);
        return IMOOCJSONResult.ok(orderStatus);
    }

}
