package com.imooc.controller.center;

import com.imooc.controller.BaseController;
import com.imooc.service.center.MyOrdersService;
import com.imooc.utils.IMOOCJSONResult;
import com.imooc.utils.PagedGridResult;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

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

}
