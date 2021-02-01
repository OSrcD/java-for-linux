![](https://tcs.teambition.net/storage/3122835cd12bba10e052b270cd0f006f9763?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0MSwiaWF0IjoxNjEyMTkwMjQxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI4MzVjZDEyYmJhMTBlMDUyYjI3MGNkMGYwMDZmOTc2MyJ9.PPfdcafK5KL0wqr5kquViWrjHeTNGGdF7eD2Tis_uD8&download=image.png "")

![](https://tcs.teambition.net/storage/312246fb994c002b597944903f7e30c5b9ff?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0MSwiaWF0IjoxNjEyMTkwMjQxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI0NmZiOTk0YzAwMmI1OTc5NDQ5MDNmN2UzMGM1YjlmZiJ9.PNmQ1NJvDQtLZ9PgQwsg-CmsWdOnxfLtqqb71gO0BJ8&download=image.png "")

```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <parent>
        <artifactId>foodie-cloud</artifactId>
        <groupId>com.imooc</groupId>
        <version>1.0-SNAPSHOT</version>
        <relativePath>../../../pom.xml</relativePath>
    </parent>
    <modelVersion>4.0.0</modelVersion>

    <artifactId>foodie-order-service</artifactId>

    <dependencies>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-order-mapper</artifactId>
            <version>${project.version}</version>
        </dependency>

        <!-- 用户服务接口层 -->
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-user-api</artifactId>
            <version>${project.version}</version>
        </dependency>

        <!-- 订单服务接口层 -->
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-order-api</artifactId>
            <version>${project.version}</version>
        </dependency>

        <!-- 商品服务依赖 -->
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-item-api</artifactId>
            <version>${project.version}</version>
        </dependency>

        <!-- TODO 学到Feign章节以后，就可以把它删掉 -->
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-client</artifactId>
        </dependency>


        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-hystrix</artifactId>
        </dependency>

        <!-- stream -->
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-stream-rabbit</artifactId>
        </dependency>

    </dependencies>

</project>
```

![](https://tcs.teambition.net/storage/3122e7c65f010b422ab11c8a728a292b6349?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0MSwiaWF0IjoxNjEyMTkwMjQxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJlN2M2NWYwMTBiNDIyYWIxMWM4YTcyOGEyOTJiNjM0OSJ9.PiDj-zF_zRPsjXa1zITZ3D_dYKVbOloR6gQWqPUNIiA&download=image.png "")

```java
package com.imooc.order.stream;

import org.springframework.cloud.stream.annotation.Input;
import org.springframework.cloud.stream.annotation.Output;
import org.springframework.messaging.MessageChannel;
import org.springframework.messaging.SubscribableChannel;


public interface CheckOrderTopic {

    String INPUT = "orderstatus-consumer";

    String OUTPUT = "orderstatus-producer";

    @Input(INPUT)
    SubscribableChannel input();

    @Output(OUTPUT)
    MessageChannel output();

}

```

![](https://tcs.teambition.net/storage/3122b7917a399c44e61c5085e98135117216?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0MSwiaWF0IjoxNjEyMTkwMjQxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJiNzkxN2EzOTljNDRlNjFjNTA4NWU5ODEzNTExNzIxNiJ9.wCr-7IwURBp1sbNA1nnSbAv0i8vRg7M0bes5OLfwY80&download=image.png "")

```java
package com.imooc.order.stream;

import com.imooc.enums.OrderStatusEnum;
import com.imooc.order.mapper.OrderStatusMapper;
import com.imooc.order.pojo.OrderStatus;
import com.imooc.order.pojo.bo.OrderStatusCheckBO;
import com.imooc.utils.DateUtil;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cloud.stream.annotation.EnableBinding;
import org.springframework.util.CollectionUtils;

import java.util.Date;
import java.util.List;

@Slf4j
@EnableBinding(value = {
        CheckOrderTopic.class
})
public class CheckOrderConsumer {

    @Autowired
    private OrderStatusMapper orderStatusMapper;


    public void consumeOrderStatusMessage(OrderStatusCheckBO bean) {
        log.info("received order check request，orderId={}", bean.getOrderID());

        OrderStatus queryOrder = new OrderStatus();

        queryOrder.setOrderId(bean.getOrderID());

        queryOrder.setOrderStatus(OrderStatusEnum.WAIT_PAY.type);

        List<OrderStatus> list = orderStatusMapper.select(queryOrder);

        if (CollectionUtils.isEmpty(list)) {
            log.info("order paid or closed, orderId={}", bean.getOrderID());
            return;
        }

        // 获得订单创建时间
        Date createdTime = list.get(0).getCreatedTime();

        // 和当前时间进行对比
        int days = DateUtil.daysBetween(createdTime, new Date());

        if (days >= 1) {
            // 超过1天，关闭订单
            OrderStatus update = new OrderStatus();
            update.setOrderId(bean.getOrderID());
            update.setOrderStatus(OrderStatusEnum.CLOSE.type);
            update.setCloseTime(new Date());

            int count = orderStatusMapper.updateByPrimaryKey(update);

            log.info("Closed order，orderId={}，count={}", bean.getOrderID(), count);
        }
    }

}

```

![](https://tcs.teambition.net/storage/312261d0e4b7c74656d7db3ba96b60d59352?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0MSwiaWF0IjoxNjEyMTkwMjQxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI2MWQwZTRiN2M3NDY1NmQ3ZGIzYmE5NmI2MGQ1OTM1MiJ9.v2ad7bWGTQzORtjDQtmejWiGUAP25ynM4sH62mPgga4&download=image.png "")

```java
package com.imooc.order.controller;

import com.imooc.controller.BaseController;
import com.imooc.enums.OrderStatusEnum;
import com.imooc.enums.PayMethod;
import com.imooc.order.pojo.OrderStatus;
import com.imooc.order.pojo.bo.OrderStatusCheckBO;
import com.imooc.order.pojo.bo.PlaceOrderBO;
import com.imooc.order.stream.CheckOrderTopic;
import com.imooc.pojo.ShopcartBO;
import com.imooc.order.pojo.bo.SubmitOrderBO;
import com.imooc.order.pojo.vo.MerchantOrdersVO;
import com.imooc.order.pojo.vo.OrderVO;
import com.imooc.order.service.OrderService;
import com.imooc.utils.CookieUtils;
import com.imooc.pojo.IMOOCJSONResult;
import com.imooc.utils.JsonUtils;
import com.imooc.utils.RedisOperator;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.apache.commons.lang3.StringUtils;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.*;
import org.springframework.messaging.support.MessageBuilder;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.client.RestTemplate;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.util.List;

@Api(value = "订单相关", tags = {"订单相关的api接口"})
@RequestMapping("orders")
@RestController
public class OrdersController extends BaseController {

    final static Logger logger = LoggerFactory.getLogger(OrdersController.class);

    @Autowired
    private OrderService orderService;

    @Autowired
    private RestTemplate restTemplate;

    @Autowired
    private RedisOperator redisOperator;

    @Autowired
    private CheckOrderTopic orderStatusProducer;

    @ApiOperation(value = "用户下单", notes = "用户下单", httpMethod = "POST")
    @PostMapping("/create")
    public IMOOCJSONResult create(
            @RequestBody SubmitOrderBO submitOrderBO,
            HttpServletRequest request,
            HttpServletResponse response) {

        if (submitOrderBO.getPayMethod() != PayMethod.WEIXIN.type
            && submitOrderBO.getPayMethod() != PayMethod.ALIPAY.type ) {
            return IMOOCJSONResult.errorMsg("支付方式不支持！");
        }

//        System.out.println(submitOrderBO.toString());

        String shopcartJson = redisOperator.get(FOODIE_SHOPCART + ":" + submitOrderBO.getUserId());
        if (StringUtils.isBlank(shopcartJson)) {
            return IMOOCJSONResult.errorMsg("购物数据不正确");
        }

        List<ShopcartBO> shopcartList = JsonUtils.jsonToList(shopcartJson, ShopcartBO.class);

        // 1. 创建订单
        PlaceOrderBO orderBO = new PlaceOrderBO(submitOrderBO, shopcartList);
        OrderVO orderVO = orderService.createOrder(orderBO);
        String orderId = orderVO.getOrderId();

        // 2. 创建订单以后，移除购物车中已结算（已提交）的商品
        /**
         * 1001
         * 2002 -> 用户购买
         * 3003 -> 用户购买
         * 4004
         */
        // 清理覆盖现有的redis汇总的购物数据
        shopcartList.removeAll(orderVO.getToBeRemovedShopcatdList());
        redisOperator.set(FOODIE_SHOPCART + ":" + submitOrderBO.getUserId(), JsonUtils.objectToJson(shopcartList));
        // 整合redis之后，完善购物车中的已结算商品清除，并且同步到前端的cookie
        CookieUtils.setCookie(request, response, FOODIE_SHOPCART, JsonUtils.objectToJson(shopcartList), true);

        // order status检查
        OrderStatusCheckBO msg = new OrderStatusCheckBO();
        msg.setOrderID(orderId);
        // 可以采用更短的Delay时间，在consumer里面重新投递消息
        orderStatusProducer.output().send(
                MessageBuilder.withPayload(msg)
                        // 一小时 3600 秒 * 24 小时 * 1000 毫秒 + 5分钟 300 秒 * 1000 毫秒
                        .setHeader("x-delay", 3600 * 24 * 1000 + 300 * 1000)
                        .build()
        );
        // 3. 向支付中心发送当前订单，用于保存支付中心的订单数据
        MerchantOrdersVO merchantOrdersVO = orderVO.getMerchantOrdersVO();
        merchantOrdersVO.setReturnUrl(payReturnUrl);

        // 为了方便测试购买，所以所有的支付金额都统一改为1分钱
        merchantOrdersVO.setAmount(1);

        HttpHeaders headers = new HttpHeaders();
        headers.setContentType(MediaType.APPLICATION_JSON);
        headers.add("imoocUserId","imooc");
        headers.add("password","imooc");

        HttpEntity<MerchantOrdersVO> entity =
                new HttpEntity<>(merchantOrdersVO, headers);

        ResponseEntity<IMOOCJSONResult> responseEntity =
                restTemplate.postForEntity(paymentUrl,
                                            entity,
                                            IMOOCJSONResult.class);
        IMOOCJSONResult paymentResult = responseEntity.getBody();
        if (paymentResult.getStatus() != 200) {
            logger.error("发送错误：{}", paymentResult.getMsg());
            return IMOOCJSONResult.errorMsg("支付中心订单创建失败，请联系管理员！");
        }

        return IMOOCJSONResult.ok(orderId);
    }

    @PostMapping("notifyMerchantOrderPaid")
    public Integer notifyMerchantOrderPaid(String merchantOrderId) {
        orderService.updateOrderStatus(merchantOrderId, OrderStatusEnum.WAIT_DELIVER.type);
        return HttpStatus.OK.value();
    }

    @PostMapping("getPaidOrderInfo")
    public IMOOCJSONResult getPaidOrderInfo(String orderId) {

        OrderStatus orderStatus = orderService.queryOrderStatusInfo(orderId);
        return IMOOCJSONResult.ok(orderStatus);
    }
}

```

![](https://tcs.teambition.net/storage/31221c67352a22dbdb97accedacb2e3486e9?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0MSwiaWF0IjoxNjEyMTkwMjQxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxYzY3MzUyYTIyZGJkYjk3YWNjZWRhY2IyZTM0ODZlOSJ9.2nu6FEl1_lxsYDqNVK16eMoenBwIHVIfNJaWCqzoFlU&download=image.png "")

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
  zipkin:
    # 基于服务发现的机制
    discoveryClientEnabled: true
    # 基于高可用
    base-url: http://ZIPKIN-SERVER/
    # 关闭 zipkin
    #    enabled: false
    # 模仿配置
    locator:
      discovery:
        # 通过服务发现 定位 它的 hostname
        enabled: true
  sleuth:
    sampler:
      probability: 1
  # 延迟消息
  cloud:
    stream:
      bindings:
        orderstatus-consumer:
          destination: orderstatus-topic
          group: order-group
        orderstatus-producer:
          destination: orderstatus-topic
      rabbit:
        bindings:
          orderstatus-producer:
            producer:
              delayed-exchange: true

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

![](https://tcs.teambition.net/storage/3122fba99eebf98b403eb33bbca3e7c41bd6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0MSwiaWF0IjoxNjEyMTkwMjQxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJmYmE5OWVlYmY5OGI0MDNlYjMzYmJjYTNlN2M0MWJkNiJ9.KIr6rkp4kbb5ofN9hzdXyoaXe-2n2ailQfzXbCY2Ptw&download=image.png "")

![](https://tcs.teambition.net/storage/3122b0ab5800f837c04f92f603d35d576a53?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0MSwiaWF0IjoxNjEyMTkwMjQxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJiMGFiNTgwMGY4MzdjMDRmOTJmNjAzZDM1ZDU3NmE1MyJ9.nKShchry8NFCzFM3Sxwm8zfzXYsxVxLcvuMtXLUjM5g&download=image.png "")

![](https://tcs.teambition.net/storage/312224dd992f139e31b192b60599614dadcb?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0MSwiaWF0IjoxNjEyMTkwMjQxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIyNGRkOTkyZjEzOWUzMWIxOTJiNjA1OTk2MTRkYWRjYiJ9.CBeXQqYds0pAMh5BfytoJIIpEvTTI5tsl8s6XgZh9tE&download=image.png "")

![](https://tcs.teambition.net/storage/312282fc42d0fe9c6e44c7815973f9096b5f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0MSwiaWF0IjoxNjEyMTkwMjQxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI4MmZjNDJkMGZlOWM2ZTQ0Yzc4MTU5NzNmOTA5NmI1ZiJ9.V6L5sLLQJBlpuPm8mneBDbcZYSdzPaInwp0S-RAQHcQ&download=image.png "")

![](https://tcs.teambition.net/storage/312287bdf916c134e0a19509461d8d76a141?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0MSwiaWF0IjoxNjEyMTkwMjQxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI4N2JkZjkxNmMxMzRlMGExOTUwOTQ2MWQ4ZDc2YTE0MSJ9.DeIEfOYHxA2CA7gb0zOADS2J1oAFmCYy8T7T8Ec89a8&download=image.png "")

![](https://tcs.teambition.net/storage/3122bac01174cf54dc6a5b404205ba7959e4?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0MSwiaWF0IjoxNjEyMTkwMjQxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJiYWMwMTE3NGNmNTRkYzZhNWI0MDQyMDViYTc5NTllNCJ9.QbVOqYvDO0F4xkdxYaKmkZDoaftI9U1cvMkdVnxnonA&download=image.png "")

![](https://tcs.teambition.net/storage/31224bedb830262024b148b198a063314fe6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0MSwiaWF0IjoxNjEyMTkwMjQxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI0YmVkYjgzMDI2MjAyNGIxNDhiMTk4YTA2MzMxNGZlNiJ9.ZVHyz7fb_c8zEUk_OwiwScP215wDYEYyAEXZXaaODPE&download=image.png "")

![](https://tcs.teambition.net/storage/3122e326de141551ce75896246904ee737a3?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0MSwiaWF0IjoxNjEyMTkwMjQxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJlMzI2ZGUxNDE1NTFjZTc1ODk2MjQ2OTA0ZWU3MzdhMyJ9.Nn-0hBWKndjFPZQOZ2qaJlH6grMkXy0gPDeX27rWDxQ&download=image.png "")

![](https://tcs.teambition.net/storage/3122331a472fc7a3ab3471aed3a8a26903e3?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0MSwiaWF0IjoxNjEyMTkwMjQxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzMzFhNDcyZmM3YTNhYjM0NzFhZWQzYThhMjY5MDNlMyJ9.YH-oHnyAlVknKN3hzhI6fLbvjTHCE7x9Hz3MrLHHvI4&download=image.png "")







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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0MSwiaWF0IjoxNjEyMTkwMjQxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.D3Nez3ngKL03yVDEhNTboTP6ZxXZVG1-M7yEwWcIR3M&download=image.png "")

