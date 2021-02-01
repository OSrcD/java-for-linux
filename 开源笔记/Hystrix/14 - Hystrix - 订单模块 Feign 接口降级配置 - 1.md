

![](https://tcs.teambition.net/storage/31211d3c82674274c6e5fc1429bcb803ec4b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc1MywiaWF0IjoxNjEyMTkwOTUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExZDNjODI2NzQyNzRjNmU1ZmMxNDI5YmNiODAzZWM0YiJ9.w1U-GQVvPo84PootW-22HR8XwYm0sJjFcG4h6hjwCMc&download=image.png "")

```yaml
server:
  port: 10003

spring:
  datasource:                                           # 数据源的相关配置
    # 拆分数据源到独立database instance，或者独立schema
#    url: jdbc:mysql://localhost:3306/foodie-cloud-item?useUnicode=true&characterEncoding=UTF-8&autoReconnect=true
    url: jdbc:mysql://localhost:3306/foodie-shop-dev?useUnicode=true&characterEncoding=UTF-8&autoReconnect=true
    password: SocialPG
  redis:
    # Redis 单机单实例
    database: 0
    host: 192.168.245.138
    port: 6379
    password: imooc
    # Redis 哨兵模式
#    database: 1
#    password: imooc
#    sentinel:
#      master: imooc-master
#      nodes: 192.168.245.138:26379,192.168.245.139:26379,192.168.245.140:26379
#    password: imooc
#    cluster:
#      nodes: 192.168.245.141:6379,192.168.245.142:6379,192.168.245.143:6379,192.168.245.144:6379,192.168.245.145:6379,192.168.245.146:6379

mybatis:
  configuration:
    log-impl: org.apache.ibatis.logging.stdout.StdOutImpl

# Ribbon 全局配置
ribbon:
  ConnectTimeout: 1000
  ReadTimeout: 3000

# Ribbon 指定服务配置超时判定 优先级更高
foodie-user-service:
  ribbon:
    ConnectTiemout: 1000
    ReadTimeout: 3000
    MaxAutoRetries: 1
    MaxAutoRetriesNextServer: 2
    OkToRetryOnAllOperations: true

# Feign 超时判定 优先级高于Ribbon
# 可以通过这里控制Feign 接口上 降级 是否开启 或者是关闭
feign:
  hystrix:
    enabled: true
  client:
    config:
      # 全局配置
      default:
        connectTimeout: 1000
        readTimeout: 5000
      # 优先级比上面那伙计高
      foodie-user-service:
        connectTimeout: 1000
        readTimeout: 5000

## 开启所有actuator-endpoint
management:
  endpoint:
    health:
      show-details: always
  endpoints:
    web:
      exposure:
        include: '*'
  #        include: health,info,xxx
  security:
    user:
      name: gitee
      password: gitee
      roles: ADMIN

hystrix:
  command:
    # 有的属性是默认值，写不写都行
    default:
      fallback:
        enabled: true
      circuitBreaker:
        enabled: true
        # 超过50%错误，那么开启熔断
        errorThresholdPercentage: 50
        # 5个request之后才进行统计
        requestVolumeThreshold: 5
        # 10秒之后进入半开状态
        sleepWindowInMilliseconds: 10000
        # forceClosed, forceOpen 强制关闭/开启熔断开关
      execution:
        timeout:
          enabled: true
        # 可以指定隔离方式是线程池还是信号量
        isolation:
          thread:
            interruptOnTimeout: true
            interruptOnFutureCancel: true
            timeoutInMilliseconds: 10000
      metrics:
        rollingStats:
          # 时间窗口统计
          timeInMilliseconds: 20000
```

如果我作为商品研发中心团队来说 如果我想对自己的服务 定制 特定的 降级逻辑 通常来讲 当然是 会在我具体的 Service 或者是 Controller 里面 在咱们的服务的内部 就已经通过 HystrixCommand 来已经指定好了 哪我这个降级 并不需要暴露给别的上下游服务 也就是说 上下游服务 根本不知道 我在这个服务 背后做了那些降级流程 只管调用你的服务 然后你的服务 如果发现超时 或者 出现异常 哪你把降级后的结果 再返回给 我  这就是微服务的内部降级

作为调用方想也指定特殊的降级服务 假如 我这个订单中心 调用 你的商品服务 哪我也想对你某个特定接口 指定降级流程 我这里想指定 降级策略 是在我订单中心 这边 控制的 不属于商品域

所以不要修改商品域暴露出来的接口 我们应该在咱们订单中心 单独声明 一套Feign 接口 来指定它的降级流程 



![](https://tcs.teambition.net/storage/3121fc24044d2a4ddb4690416efc8ee9fc0b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc1MywiaWF0IjoxNjEyMTkwOTUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmYzI0MDQ0ZDJhNGRkYjQ2OTA0MTZlZmM4ZWU5ZmMwYiJ9.tZo6HZfbtWBmtufEnMYfLRdRjYTBPnf4Z0msCybE0_w&download=image.png "")

```java
package com.imooc.item.service;

import com.imooc.pojo.PagedGridResult;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.*;

import java.util.Map;


/**
 * 内部的降级（商品中心） 放到item-server里面实现
 * 调用方降级（订单中心，调用商品中心服务） 由订单中心定义降级逻辑
 */


@FeignClient("foodie-item-service")
@RequestMapping("item-comments-api")
public interface ItemCommentsService {


    /**
     * 我的评价查询 分页
     * @param userId
     * @param page
     * @param pageSize
     * @return
     */
    @GetMapping("myComments")
    public PagedGridResult queryMyComments(@RequestParam("userId") String userId,
                                           @RequestParam(value = "page",required = false) Integer page,
                                           @RequestParam(value = "pageSize",required = false) Integer pageSize);

    /**
     * 会被订单中心调用
     * 看订单中心的源代码
     * @param map
     */
    @PostMapping("saveComments")
    public void saveComments(@RequestBody Map<String, Object> map);
}

```

![](https://tcs.teambition.net/storage/3121be8d7771ed2ef3f574f2ef948ac2fee6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc1MywiaWF0IjoxNjEyMTkwOTUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiZThkNzc3MWVkMmVmM2Y1NzRmMmVmOTQ4YWMyZmVlNiJ9.BNb9AI0R62zW4X7XIK6BPPf8NoWmKBVNqxLoQuDALvA&download=image.png "")

```java
package com.imooc.order.fallback.itemservice;

import com.imooc.item.service.ItemCommentsService;
import org.springframework.cloud.openfeign.FeignClient;

@FeignClient("foodie-item-service")
public interface ItemCommentsFeignClient extends ItemCommentsService {

}

```

![](https://tcs.teambition.net/storage/3121cac99a05e4ffa2bd1477c8b759820f12?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc1MywiaWF0IjoxNjEyMTkwOTUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjYWM5OWEwNWU0ZmZhMmJkMTQ3N2M4Yjc1OTgyMGYxMiJ9.ZdVcwGu5q3dX4LgMjBBsF2_g5cBVJSVruOA_Fs-G_AY&download=image.png "")

```java
package com.imooc.order.service.impl.center;

import com.imooc.enums.YesOrNo;
import com.imooc.item.service.ItemCommentsService;
import com.imooc.order.fallback.itemservice.ItemCommentsFeignClient;
import com.imooc.order.mapper.OrderItemsMapper;
import com.imooc.order.mapper.OrderStatusMapper;
import com.imooc.order.mapper.OrdersMapper;
import com.imooc.order.pojo.OrderItems;
import com.imooc.order.pojo.OrderStatus;
import com.imooc.order.pojo.Orders;
import com.imooc.order.pojo.bo.center.OrderItemsCommentBO;
import com.imooc.order.service.center.MyCommentsService;
import com.imooc.pojo.PagedGridResult;
import com.imooc.service.BaseService;
import org.n3r.idworker.Sid;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cloud.client.ServiceInstance;
import org.springframework.cloud.client.loadbalancer.LoadBalancerClient;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.client.RestTemplate;

import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


@Service
@RestController
public class MyCommentsServiceImpl extends BaseService implements MyCommentsService {

    @Autowired
    public OrderItemsMapper orderItemsMapper;

    @Autowired
    public OrdersMapper ordersMapper;

    @Autowired
    public OrderStatusMapper orderStatusMapper;

    //    @Autowired
//    public ItemsCommentsMapperCustom itemsCommentsMapperCustom;
    // TODO feign章节里改成item-api
//    @Autowired
//    private LoadBalancerClient client;
//    @Autowired
//    private RestTemplate restTemplate;
    @Autowired
//    private ItemCommentsService itemCommentsService;
    private ItemCommentsFeignClient itemCommentsService;

    @Autowired
    private Sid sid;

    @Transactional(propagation = Propagation.SUPPORTS)
    @Override
    public List<OrderItems> queryPendingComment(String orderId) {
        OrderItems query = new OrderItems();
        query.setOrderId(orderId);
        return orderItemsMapper.select(query);
    }

    @Transactional(propagation = Propagation.REQUIRED)
    @Override
    public void saveComments(String orderId, String userId,
                             List<OrderItemsCommentBO> commentList) {

        // 1. 保存评价 items_comments
        for (OrderItemsCommentBO oic : commentList) {
            oic.setCommentId(sid.nextShort());
        }
        Map<String, Object> map = new HashMap<>();
        map.put("userId", userId);
        map.put("commentList", commentList);
//        itemsCommentsMapperCustom.saveComments(map);

//        ServiceInstance instance = client.choose("FOODIE-ITEM-SERVICE");
//        String url = String.format("http://%s:%s/item-comments-api/saveComments",
//                instance.getHost(),
//                instance.getPort());
//        // TODO 偷个懒，不判断返回status，等下个章节用Feign重写
//        restTemplate.postForLocation(url, map);

        itemCommentsService.saveComments(map);

        // 2. 修改订单表改已评价 orders
        Orders order = new Orders();
        order.setId(orderId);
        order.setIsComment(YesOrNo.YES.type);
        ordersMapper.updateByPrimaryKeySelective(order);

        // 3. 修改订单状态表的留言时间 order_status
        OrderStatus orderStatus = new OrderStatus();
        orderStatus.setOrderId(orderId);
        orderStatus.setCommentTime(new Date());
        orderStatusMapper.updateByPrimaryKeySelective(orderStatus);
    }

    // TODO 移到了itemCommentService
//    @Transactional(propagation = Propagation.SUPPORTS)
//    @Override
//    public PagedGridResult queryMyComments(String userId,
//                                           Integer page,
//                                           Integer pageSize) {
//
//        Map<String, Object> map = new HashMap<>();
//        map.put("userId", userId);
//
//        PageHelper.startPage(page, pageSize);
//        List<MyCommentVO> list = itemsCommentsMapperCustom.queryMyComments(map);
//
//        return setterPagedGrid(list, page);
//    }
}

```

![](https://tcs.teambition.net/storage/31218cdcd17f41c3d5ca24c2756ddb102b7a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc1MywiaWF0IjoxNjEyMTkwOTUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4Y2RjZDE3ZjQxYzNkNWNhMjRjMjc1NmRkYjEwMmI3YSJ9.1n3qi1tVNqSNsjBp6soDwSxP8mhsAq_Q0jeP8Nm_r1c&download=image.png "")

```java
package com.imooc.order.controller.center;

import com.imooc.controller.BaseController;
import com.imooc.enums.YesOrNo;
import com.imooc.item.service.ItemCommentsService;
import com.imooc.order.fallback.itemservice.ItemCommentsFeignClient;
import com.imooc.order.pojo.OrderItems;
import com.imooc.order.pojo.Orders;
import com.imooc.order.pojo.bo.center.OrderItemsCommentBO;
import com.imooc.order.service.center.MyCommentsService;
import com.imooc.order.service.center.MyOrdersService;
import com.imooc.pojo.IMOOCJSONResult;
import com.imooc.pojo.PagedGridResult;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cloud.client.ServiceInstance;
import org.springframework.cloud.client.loadbalancer.LoadBalancerClient;
import org.springframework.http.HttpStatus;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.client.RestTemplate;

import java.util.List;

@Api(value = "用户中心评价模块", tags = {"用户中心评价模块相关接口"})
@RestController
@RequestMapping("mycomments")
public class MyCommentsController extends BaseController {

    @Autowired
    private MyCommentsService myCommentsService;

    @Autowired
    private MyOrdersService myOrdersService;

    @Autowired
//    private ItemCommentsService itemCommentsService;
    private ItemCommentsFeignClient itemCommentsService;
//    @Autowired
//    private LoadBalancerClient client;
//
//    @Autowired
//    private RestTemplate restTemplate;

    @ApiOperation(value = "查询订单列表", notes = "查询订单列表", httpMethod = "POST")
    @PostMapping("/pending")
    public IMOOCJSONResult pending(
            @ApiParam(name = "userId", value = "用户id", required = true)
            @RequestParam String userId,
            @ApiParam(name = "orderId", value = "订单id", required = true)
            @RequestParam String orderId) {

        // 判断用户和订单是否关联
        IMOOCJSONResult checkResult = myOrdersService.checkUserOrder(userId, orderId);
        if (checkResult.getStatus() != HttpStatus.OK.value()) {
            return checkResult;
        }
        // 判断该笔订单是否已经评价过，评价过了就不再继续
        Orders myOrder = (Orders)checkResult.getData();
        if (myOrder.getIsComment() == YesOrNo.YES.type) {
            return IMOOCJSONResult.errorMsg("该笔订单已经评价");
        }

        List<OrderItems> list = myCommentsService.queryPendingComment(orderId);

        return IMOOCJSONResult.ok(list);
    }


    @ApiOperation(value = "保存评论列表", notes = "保存评论列表", httpMethod = "POST")
    @PostMapping("/saveList")
    public IMOOCJSONResult saveList(
            @ApiParam(name = "userId", value = "用户id", required = true)
            @RequestParam String userId,
            @ApiParam(name = "orderId", value = "订单id", required = true)
            @RequestParam String orderId,
            @RequestBody List<OrderItemsCommentBO> commentList) {

        System.out.println(commentList);

        // 判断用户和订单是否关联
        IMOOCJSONResult checkResult = myOrdersService.checkUserOrder(userId, orderId);
        if (checkResult.getStatus() != HttpStatus.OK.value()) {
            return checkResult;
        }
        // 判断评论内容list不能为空
        if (commentList == null || commentList.isEmpty() || commentList.size() == 0) {
            return IMOOCJSONResult.errorMsg("评论内容不能为空！");
        }

        myCommentsService.saveComments(orderId, userId, commentList);
        return IMOOCJSONResult.ok();
    }

    @ApiOperation(value = "查询我的评价", notes = "查询我的评价", httpMethod = "POST")
    @PostMapping("/query")
    public IMOOCJSONResult query(
            @ApiParam(name = "userId", value = "用户id", required = true)
            @RequestParam String userId,
            @ApiParam(name = "page", value = "查询下一页的第几页", required = false)
            @RequestParam Integer page,
            @ApiParam(name = "pageSize", value = "分页的每一页显示的条数", required = false)
            @RequestParam Integer pageSize) {

        if (StringUtils.isBlank(userId)) {
            return IMOOCJSONResult.errorMsg(null);
        }
        if (page == null) {
            page = 1;
        }
        if (pageSize == null) {
            pageSize = COMMON_PAGE_SIZE;
        }

        // TODO 前方施工，学完Feign再来改造
        PagedGridResult grid = itemCommentsService.queryMyComments(userId,
                page,
                pageSize);
//        ServiceInstance instance = client.choose("FOODIE-ITEM-SERVICE");
//        String target = String.format("http://%s:%s/item-comments-api/myComments" +
//                        "?userId=%s&page=%s&pageSize=%s",
//                instance.getHost(),
//                instance.getPort(),
//                userId,
//                page,
//                pageSize);
//        // 偷个懒，不判断返回status，等下个章节用Feign重写
//        PagedGridResult grid = restTemplate.getForObject(target, PagedGridResult.class);
//
        return IMOOCJSONResult.ok(grid);
//
//        PagedGridResult grid = myCommentsService.queryMyComments(userId,
//                page,
//                pageSize);
//
//        return IMOOCJSONResult.ok(grid);
    }

}

```

![](https://tcs.teambition.net/storage/3121aafc181f6ef6f1fe397ffc7fd568469d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc1MywiaWF0IjoxNjEyMTkwOTUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhYWZjMTgxZjZlZjZmMWZlMzk3ZmZjN2ZkNTY4NDY5ZCJ9.abrk4NGR15uPd74CB9Pf0-72iZmW3DY1MN3OmQDStOk&download=image.png "")

```java
package com.imooc.order;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import org.springframework.cloud.openfeign.EnableFeignClients;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.scheduling.annotation.EnableScheduling;
import tk.mybatis.spring.annotation.MapperScan;

/**
 * Created by 半仙.
 */
@SpringBootApplication
// 扫描 mybatis 通用 mapper 所在的包
@MapperScan(basePackages = "com.imooc.order.mapper")
// 扫描所有包以及相关组件包
@ComponentScan(basePackages = {"com.imooc", "org.n3r.idworker"})
@EnableDiscoveryClient
@EnableScheduling
// TODO feign注解
@EnableFeignClients(basePackages = {
        "com.imooc.user.service",
        "com.imooc.item.service",
        "com.imooc.order.fallback.itemservice"
})
public class OrderApplication {

    public static void main(String[] args) {
        SpringApplication.run(OrderApplication.class, args);
    }

}

```

![](https://tcs.teambition.net/storage/3121f49299ee9692e43a7e4a892baabf77e8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc1MywiaWF0IjoxNjEyMTkwOTUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmNDkyOTllZTk2OTJlNDNhN2U0YTg5MmJhYWJmNzdlOCJ9.PIC5taW8F7dL3a2lstmMXAmuZ4XJvQDh5kplXdgpr5w&download=image.png "")

![](https://tcs.teambition.net/storage/31218af7d15bc887e47f51368396fcb9a537?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc1MywiaWF0IjoxNjEyMTkwOTUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4YWY3ZDE1YmM4ODdlNDdmNTEzNjgzOTZmY2I5YTUzNyJ9.f3XDx88fC6FgkK0lqfBoD-Ttm9rKovlRHajodKw8pHE&download=image.png "")

形成 http访问路径 

![](https://tcs.teambition.net/storage/31214f5d81cb42344bdda39f787b0e1e22ed?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc1MywiaWF0IjoxNjEyMTkwOTUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0ZjVkODFjYjQyMzQ0YmRkYTM5Zjc4N2IwZTFlMjJlZCJ9.7XFaRFP7L25WCXalJ-rHeQs0b5RrjWkKFqaNUUp0CoM&download=image.png "")

也继承了 注解 



![](https://tcs.teambition.net/storage/3121367d6d60083f7e65e1b30d0370fdb4d6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc1MywiaWF0IjoxNjEyMTkwOTUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzNjdkNmQ2MDA4M2Y3ZTY1ZTFiMzBkMDM3MGZkYjRkNiJ9.UcO1bRKk_CIT6UVio8uvyNgcUg1uw53162C7Uo1b5Og&download=image.png "")

Spring Boot 在加载整个上下文的时候 它发现 你的这个方法 已经在其中某个接口里面实现了  同时在加载 两个接口的时候 它加载了两个同样访问路径的方法 就会报 Ambiguous mapping  

两个接口 同时加载到 上下文 当中 但是 它们定义了 对同样方法 相同访问路径的两个实例

![](https://tcs.teambition.net/storage/3121b1e2366a344b71b6949475e280be3bfe?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc1MywiaWF0IjoxNjEyMTkwOTUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiMWUyMzY2YTM0NGI3MWI2OTQ5NDc1ZTI4MGJlM2JmZSJ9.Co0hFprDy9UVsv6eOLfM22IMLSu2C_sGaGYC4BGQVbU&download=image.png "")

![](https://tcs.teambition.net/storage/3121e502af4e5745c536b940171caf9c9013?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc1MywiaWF0IjoxNjEyMTkwOTUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlNTAyYWY0ZTU3NDVjNTM2Yjk0MDE3MWNhZjljOTAxMyJ9.FpR9pgn0P_r-5uRfurnuIPO9oNOrYtMxaNKE7Di1W-s&download=image.png "")

服务提供者 和调用者 都需要在自己头上加RequestMapping 



 作为服务调用者来说 即时不需要重新定义一个Feign接口指定 fallback类

依然要在服务调用者 这里 声明一个 独立的接口  声明RequestMapping 

![](https://tcs.teambition.net/storage/3121b27e144c02365ee0b7776c81fede7038?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc1MywiaWF0IjoxNjEyMTkwOTUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiMjdlMTQ0YzAyMzY1ZWUwYjc3NzZjODFmZWRlNzAzOCJ9.-9l8qh-YoNLEyc-ICAE0Y2Maksw9MvpUO2gws-iy2vE&download=image.png "")





很多人喜欢在每个服务调用者这里 声明一个独立的Feign接口 

![](https://tcs.teambition.net/storage/31213f87499d95c916af71d8cb2bdbec4d85?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc1MywiaWF0IjoxNjEyMTkwOTUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzZjg3NDk5ZDk1YzkxNmFmNzFkOGNiMmJkYmVjNGQ4NSJ9.TjoG4Lk3zyhSbiK8TH9w05NhKcIYq795bAPzyz6jUZ4&download=image.png "")



服务器提供者就是 xxxServiceImpl

![](https://tcs.teambition.net/storage/312162349e76d0e418fc2c51cecd13f0cc35?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc1MywiaWF0IjoxNjEyMTkwOTUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2MjM0OWU3NmQwZTQxOGZjMmM1MWNlY2QxM2YwY2MzNSJ9.Vg5NpjdHNRzfQJqP2WBt9FwtdBAA9wjvLhifPK4Wec0&download=image.png "")

![](https://tcs.teambition.net/storage/3121a5e37e603dc6c18b1bfc36254ef21f0b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc1MywiaWF0IjoxNjEyMTkwOTUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhNWUzN2U2MDNkYzZjMThiMWJmYzM2MjU0ZWYyMWYwYiJ9.qcDF1kUiZdiOuC9i4TyrGmlersbiJ3Z3CdfcGz7c9fY&download=image.png "")

```java
package com.imooc.order.fallback.itemservice;

import com.imooc.item.service.ItemCommentsService;
import org.springframework.cloud.openfeign.FeignClient;


/**
 * 讨厌的地方来了，对于需要在调用端指定降级业务的场景来说，由于@RequestMapping和@xxxMapping注解
 * 可以从原始接口上继承，因此不能配置两个完全一样的访问路径，否则启动报错。
 *
 * 在我们的实际案例中，ItemCommentsService上面定义了RequestMapping，同时
 * ItemCommentsServiceFeign继承自ItemCommentsService，因此相当于在Spring上下文
 * 中加载了两个访问路径一样的方法，会报错"Ambiguous mapping"
 *
 * 解决问题的思路就是，避免让Spring的上下文中，同时加载两个访问路径相同的方法
 *
 * 解决方案：
 * 1）在启动类扫包的时候，不要把原始Feign接口扫描进来
 * 具体做法：可以使用EnableFeignClients注解的clients属性，只加载需要的Feign接口
 *  * 优点：服务提供者和服务调用者都不需要额外的配置
 *  * 缺点：启动的时候配置麻烦一点，要指定加载每一个用到的接口
 *
 * 2) 原始Feign接口不要定义RequestMapping注解
 * 优点：启动的时候直接扫包即可，不用指定加载接口
 * 缺点：a, 服务提供者要额外配置路径访问的注解
 *      b, 任何情况下，即使不需要在调用端定义fallback类，服务调用者都需要声明一个
 *
 * 3) 原始Feign接口不要定义@FeignClients注解，这样就不会被加载到上下文当中
 *  * 优点：启动的时候直接扫包即可，不用指定加载接口，服务提供者不用额外配置
 *  * 缺点：任何情况下，服务调用者都需要声明一个额外@FeignCliet接口
 *
 * 各有利弊，按照喜好来选就行，个人比较喜欢1），毕竟懒人
 *
 */
@FeignClient("foodie-item-service")
public interface ItemCommentsFeignClient extends ItemCommentsService {

}

```



开源笔记

可 Pull Requests 协作写开源笔记

如果笔记图片无法访问 请访问 [teambition](https://tburl.in/0jDNvpbK) 原版开源笔记

gitee

[https://gitee.com/opendevel/java-for-linux](https://gitee.com/opendevel/java-for-linux)

github

[https://github.com/OSrcD/java-for-linux](https://github.com/OSrcD/java-for-linux)

teambition

[https://tburl.in/0jDNvpbK](https://tburl.in/0jDNvpbK)

开源视频

bilibili

[https://space.bilibili.com/77266754](https://space.bilibili.com/77266754)

开源博客

oschina

[https://my.oschina.net/u/4675154](https://my.oschina.net/u/4675154)

csdn

[https://blog.csdn.net/OpenDevel](https://blog.csdn.net/OpenDevel)

开源项目

gitee

[https://gitee.com/opendevel](https://gitee.com/opendevel)

github

[https://github.com/OSrcD](https://github.com/OSrcD)

开源赞赏

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc1MywiaWF0IjoxNjEyMTkwOTUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.W6OA-kVj5nq6Ls2ecwHe51m_9peXOC7G64jaX15gZC0&download=image.png "")

