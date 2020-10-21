package com.imooc.controller.center;

import com.imooc.controller.BaseController;
import com.imooc.pojo.Orders;
import com.imooc.service.OrderService;
import com.imooc.service.center.MyOrdersService;
import com.imooc.utils.IMOOCJSONResult;
import com.imooc.utils.PagedGridResult;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.web.bind.annotation.*;

@Api(value="用户中心我的订单",tags={"用户中心我的订单相关接口"})
@RestController
@RequestMapping("myorders")
public class MyOrdersController extends BaseController {

    @Autowired
    private MyOrdersService myOrdersService;


    @ApiOperation(value="查询订单列表",notes="查询订单列表",httpMethod="POST")
    @PostMapping("query")
    public IMOOCJSONResult query(
            @ApiParam(name="userId",value="用户id",required=true)
            @RequestParam String userId,
            @ApiParam(name="orderStatus",value="订单状态",required=false)
            @RequestParam Integer orderStatus,
            @ApiParam(name="page",value="查询下一页的第几页",required=false)
            @RequestParam Integer page,
            @ApiParam(name="pageSize",value="分页的每一页显示的条数",required=false)
            @RequestParam Integer pageSize){

        if (StringUtils.isBlank(userId)) {
            return IMOOCJSONResult.errorMsg(null);
        }

        if(page == null){
            page = 1;
        }

        if(pageSize == null){
            pageSize = COMMON_PAGE_SIZE;
        }

        PagedGridResult grid = myOrdersService.queryMyOrders(userId,orderStatus,page,pageSize);

        return IMOOCJSONResult.ok(grid);
    }

    // 商家发货没有后端，所以这个接口仅仅只是用于模拟
    @ApiOperation(value = "商家发货",notes="商家发货",httpMethod="GET")
    @GetMapping("/deliver")
    public IMOOCJSONResult deliver(
            @ApiParam(name="orderId",value="订单id",required = true)
            @RequestParam String orderId) {

        if (StringUtils.isBlank(orderId)) {
            return IMOOCJSONResult.errorMsg("订单ID不能为空");
        }

        myOrdersService.updateDeliverOrderStatus(orderId);
        return IMOOCJSONResult.ok();
    }


    @ApiOperation(value = "用户确认收货",notes="用户确认收货",httpMethod="POST")
    @PostMapping("/confirmReceiver")
    public IMOOCJSONResult confirmReceiver(
            @ApiParam(name="orderID",value="订单id",required = true)
            @RequestParam String orderId ,
            @ApiParam(name="userId",value="用户id",required = true)
            @RequestParam  String userId) {


        IMOOCJSONResult checkResult = checkUserOrder(userId, orderId);

        if (checkResult.getStatus() != HttpStatus.OK.value()) {
            return checkResult;
        }

        return IMOOCJSONResult.ok();

    }




    /**
     * 用于验证用户和订单是否有关联关系，避免非法用户调用
     * @return
     */
    public IMOOCJSONResult checkUserOrder(String userId,String orderId) {
        Orders orders = myOrdersService.queryMyOrder(userId,orderId);
        if(orders == null){
            return IMOOCJSONResult.errorMsg("订单Id不存在！");
        }
        return IMOOCJSONResult.ok();
    }

    @ApiOperation(value = "用户删除订单",notes="用户删除订单",httpMethod="POST")
    @PostMapping("/delete")
    public IMOOCJSONResult delete(
            @ApiParam(name="orderID",value="订单id",required = true)
            @RequestParam String orderId ,
            @ApiParam(name="userId",value="用户id",required = true)
            @RequestParam  String userId) {


        IMOOCJSONResult checkResult = checkUserOrder(userId, orderId);
        if (checkResult.getStatus() != HttpStatus.OK.value()) {
            return checkResult;
        }


        return IMOOCJSONResult.ok();

    }


}
