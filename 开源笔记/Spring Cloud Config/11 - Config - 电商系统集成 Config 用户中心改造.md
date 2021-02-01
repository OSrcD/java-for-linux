![](https://tcs.teambition.net/storage/31215ac2edecf598702061972f26e7b0c1ca?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU1MSwiaWF0IjoxNjEyMTkwNzUxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1YWMyZWRlY2Y1OTg3MDIwNjE5NzJmMjZlN2IwYzFjYSJ9.IcB2MixJKGrvZJftRQie674At7hOfO6nqycde0jLue0&download=image.png "")

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

    <artifactId>foodie-user-web</artifactId>

    <dependencies>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-user-service</artifactId>
            <version>${project.version}</version>
        </dependency>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-cloud-web-components</artifactId>
            <version>${project.version}</version>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-client</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-config</artifactId>
        </dependency>
    </dependencies>

    <build>
        <plugins>
            <plugin>
                <groupId>org.springframework.boot</groupId>
                <artifactId>spring-boot-maven-plugin</artifactId>
                <configuration>
                    <mainClass>com.imooc.user.UserApplication</mainClass>
                </configuration>
                <executions>
                    <execution>
                        <goals>
                            <goal>repackage</goal>
                        </goals>
                    </execution>
                </executions>
            </plugin>
        </plugins>
    </build>

</project>
```

![](https://tcs.teambition.net/storage/3121d9595bcfcf7b9536a3a8d37c5e6b8da8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU1MSwiaWF0IjoxNjEyMTkwNzUxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkOTU5NWJjZmNmN2I5NTM2YTNhOGQzN2M1ZTZiOGRhOCJ9.-vn88vIV7PuFzbBUZgm5Co2s_H7ijzEsraZJcLVrThc&download=image.png "")

```yaml
############################################################
#
# Eureka注册中心
#
############################################################
eureka:
  client:
    serviceUrl:
      defaultZone: http://localhost:20000/eureka/

############################################################
#
# Config配置中心
#
############################################################
spring:
  cloud:
    config:
      discovery:
        enabled: true
        service-id: config-server
      profile: dev
      # 默认
      label: main
```

![](https://tcs.teambition.net/storage/3121257f881c1e70d99ad5bd52abd78cea20?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU1MSwiaWF0IjoxNjEyMTkwNzUxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyNTdmODgxYzFlNzBkOTlhZDViZDUyYWJkNzhjZWEyMCJ9.Wsibabaw7eJb1nejeYXtQ3WV7aMsq19aGdspDQCGyN8&download=image.png "")

![](https://tcs.teambition.net/storage/31211d4ea4034719bebbbc613f705fb7cfe6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU1MSwiaWF0IjoxNjEyMTkwNzUxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExZDRlYTQwMzQ3MTliZWJiYmM2MTNmNzA1ZmI3Y2ZlNiJ9.rQM1CGEpASVIlwBo-DqPW4PNnZwBybjT4Vx7_iUmg8c&download=image.png "")

```yaml
server:
  port: 10002

spring:
  datasource:                                           # 数据源的相关配置
    # 拆分数据源到独立database instance，或者独立schema
#    url: jdbc:mysql://localhost:3306/foodie-cloud-item?useUnicode=true&characterEncoding=UTF-8&autoReconnect=true
#    url: jdbc:mysql://localhost:3306/foodie-shop-dev?useUnicode=true&characterEncoding=UTF-8&autoReconnect=true
#    password: 
    url: ${mariadb.url}
    password: ${mariadb.password}
  redis:
    # Redis 单机单实例
    database: 0
#    host: localhost
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

## 开启所有actuator-endpoint
# 第一步去配置中心 拉取这些属性 自动的加载到上下文当中 是有一样的key
# 我们这里可以直接把它删掉
#management:
#  endpoint:
#    health:
#      show-details: always
#  endpoints:
#    web:
#      exposure:
#        include: '*'
#  security:
#    user:
#      name: gitee
#      password: gitee
#      roles: ADMIN

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
          # numBuckets: 10
    #        rollingPercentile:
    #          # 时间窗口统计
    #          timeInMilliseconds: 20000
    #          # numBuckets: 10
    #          bucketSize: 300
    # 照这个方法，覆盖其他的属性
    loginFail:
      execution:
        isolation:
          thread:
            timeoutInMilliseconds: 3000
```

专门管理外部注入的属性

![](https://tcs.teambition.net/storage/312132aeeaba0296151ec9cec6609565e5dc?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU1MSwiaWF0IjoxNjEyMTkwNzUxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzMmFlZWFiYTAyOTYxNTFlYzljZWM2NjA5NTY1ZTVkYyJ9.kif3iRE7Uh1wgSsrfKsOneG7p5bx1VMK3ajl7bwf3yg&download=image.png "")

![](https://tcs.teambition.net/storage/3121d2273cfb133e94a9edf0a632f1ab07a0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU1MSwiaWF0IjoxNjEyMTkwNzUxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkMjI3M2NmYjEzM2U5NGE5ZWRmMGE2MzJmMWFiMDdhMCJ9.YHRHoVg4UCxSzYPmYjhfgnuVOX0cXfdYSl8RQVBVrPk&download=image.png "")

```java
package com.imooc.user;

import lombok.Data;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.cloud.context.config.annotation.RefreshScope;
import org.springframework.context.annotation.Configuration;

@Configuration
/**
 * 因为注册功能
 * 希望从 外部控制它的开启和关闭
 * 是可以在运行期间不断刷新的
 */
@RefreshScope
@Data
public class UserApplicationProperties {

    @Value("${userservice.registration.disabled}")
    private boolean disableRegistration;
    
}

```

![](https://tcs.teambition.net/storage/3121c088ff5437122259dcee21f798d743a6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU1MSwiaWF0IjoxNjEyMTkwNzUxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjMDg4ZmY1NDM3MTIyMjU5ZGNlZTIxZjc5OGQ3NDNhNiJ9.hqP-p_PrmcNbQv8wHIIW2LOBCkDR14mqnEfHk5L2Qs8&download=image.png "")

![](https://tcs.teambition.net/storage/3121501f619f39f580439bea718bc26f5f7c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU1MSwiaWF0IjoxNjEyMTkwNzUxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1MDFmNjE5ZjM5ZjU4MDQzOWJlYTcxOGJjMjZmNWY3YyJ9.AiK7WkWDJRTm_o-8m7RELxuiHYdWg23xk6p5isS1xa4&download=image.png "")

```java
package com.imooc.user.controller;

import com.imooc.controller.BaseController;
import com.imooc.pojo.IMOOCJSONResult;
import com.imooc.pojo.ShopcartBO;
import com.imooc.user.UserApplicationProperties;
import com.imooc.user.pojo.Users;
import com.imooc.user.pojo.bo.UserBO;
import com.imooc.user.service.UserService;
import com.imooc.utils.CookieUtils;
import com.imooc.utils.JsonUtils;
import com.imooc.utils.MD5Utils;
import com.imooc.utils.RedisOperator;
import com.netflix.hystrix.contrib.javanica.annotation.HystrixCommand;
import com.netflix.hystrix.contrib.javanica.annotation.HystrixProperty;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.util.ArrayList;
import java.util.List;

@Api(value="注册登录",tags = {"用于注册登录的相关接口"}) // tags是导航的标题 value不知道
@RestController
@RequestMapping("/passport")
@Slf4j
public class PassportController extends BaseController {

    @Autowired
    private UserService userService;

    @Autowired
    private RedisOperator redisOperator;

    @Autowired
    private UserApplicationProperties userApplicationProperties;

    @ApiOperation(value = "用户名是否存在",notes = "用户名是否存在",httpMethod = "GET") // value是接口名称，可在导航标题下面显示 notes是说明
    @GetMapping("/usernameIsExist")
    public IMOOCJSONResult usernameIsExist(@RequestParam String username) {

        // 1. 判断用户不能为空
        if(StringUtils.isBlank(username)){
            return IMOOCJSONResult.errorMsg("用户名不能为空");
        }

        // 2. 查找用户名是否存在
        boolean isExist = userService.queryUsernameIsExist(username);

        if(isExist){
            return IMOOCJSONResult.errorMsg("用户名已经存在");
        }

        // 3. 请求成功，用户名没有重复
        return IMOOCJSONResult.ok();

    }

    @ApiOperation(value = "用户注册", notes = "用户注册", httpMethod = "POST") // value是接口名称，可在导航标题下面显示 notes是说明
    @PostMapping("/regist")
    public IMOOCJSONResult regist(@RequestBody UserBO userBO,
                                  HttpServletRequest request,
                                  HttpServletResponse response){

        if (userApplicationProperties.isDisableRegistration()) {
            log.info("user registration request is blocked - {}" + userBO.getUsername());
            return IMOOCJSONResult.errorMsg("当前注册用户过多，请稍后再试");
        }

        String username = userBO.getUsername();
        String password = userBO.getPassword();
        String confirmPwd = userBO.getConfirmPassword();

        // 0. 判断用户名和密码必须不为空
        if(StringUtils.isBlank(username) ||
                StringUtils.isBlank(password) ||
                StringUtils.isBlank(confirmPwd)){

            return IMOOCJSONResult.errorMsg("用户名或密码不能为空");
        }
        // 1. 查询用户名是否存在
        boolean isExist = userService.queryUsernameIsExist(username);
        if(isExist){
            return IMOOCJSONResult.errorMsg("用户名已经存在");
        }

        // 2. 密码长度不能少于6位
        if(password.length() < 6){
            return IMOOCJSONResult.errorMsg("密码长度不能少于6");
        }

        // 3. 判断两次密码是否一致
        if(!password.equals(confirmPwd)){
            return IMOOCJSONResult.errorMsg("两次密码输入不一致");
        }

        // 4.实现注册
        Users userResult = userService.createUser(userBO);

        userResult = setNullProperty(userResult);

        // 实现用户的redis会话
//        UsersVO usersVO = conventUsersVO(userResult);

        CookieUtils.setCookie(request, response, "user",
                JsonUtils.objectToJson(userResult), true);

        // 同步购物车数据
        synchShopcartData(userResult.getId(), request, response);

        return IMOOCJSONResult.ok();

    }



    @ApiOperation(value="用户登录",notes="用户登录",httpMethod="POST")
    @PostMapping("/login")
    @HystrixCommand(
            commandKey = "loginFail", // 全局唯一的标识服务，默认函数名称
            groupKey = "password", // 全局服务分组，用于组织仪表盘，统计信息。默认：类名
            fallbackMethod = "loginFail", // 同一个类里，public private都可以
            // 在列表中的exception，不会触发降级
//            ignoreExceptions = {IllegalArgumentException.class}
            // 线程有关的属性
            // 线程组, 多个服务可以共用一个线程组
            threadPoolKey = "threadPoolA",
            threadPoolProperties = {
                    // 核心线程数
                    @HystrixProperty(name = "coreSize",value = "10"),
                    // size > 0, LinkedBlockingQueue -> 请求等待队列
                    // 默认-1 , SynchronousQueue -> 不存储元素的阻塞队列（建议读源码，学CAS应用）
                    @HystrixProperty(name = "maxQueueSize", value = "40"),
                    // 在maxQueueSize=-1的时候无效，队列没有达到maxQueueSize依然拒绝
                    @HystrixProperty(name = "queueSizeRejectionThreshold",value = "15"),
                    // （线程池）统计窗口持续时间
                    @HystrixProperty(name = "metrics.rollingStats.timeInMilliseconds", value = "1024"),
                    // （线程池）窗口内桶子的数量
                    @HystrixProperty(name = "metrics.rollingStats.numBuckets", value = "18")
            }
//            ,
//            commandProperties = {
//                  // TODO 熔断降级相关属性，也可以放在这里
//            }
    )
    public IMOOCJSONResult login(@RequestBody UserBO userBO,
                                 HttpServletRequest request,
                                 HttpServletResponse response) throws Exception{

        String username = userBO.getUsername();
        String password = userBO.getPassword();


        // 0. 判断用户名和密码必须不为空
        if(StringUtils.isEmpty(username)
                || StringUtils.isEmpty(password)){
            return IMOOCJSONResult.errorMsg("用户名或密码不能为空");
        }

        // 1.实现登录
        Users userResult = userService.queryUserForLogin(username,
                MD5Utils.getMD5Str(password));

        if(userResult == null){
            return IMOOCJSONResult.errorMsg("用户名或密码不正确");
        }

        userResult = setNullProperty(userResult);

        // 实现用户的redis会话
//        UsersVO usersVO = conventUsersVO(userResult);

        CookieUtils.setCookie(request,response,"user",
                JsonUtils.objectToJson(userResult),true);

        // 同步购物车数据
        synchShopcartData(userResult.getId(), request, response);


        return IMOOCJSONResult.ok(userResult);

    }

    private IMOOCJSONResult loginFail(UserBO userBO,
                                      HttpServletRequest request,
                                      HttpServletResponse response,
                                      Throwable throwable) throws Exception {

        return IMOOCJSONResult.errorMsg("验证码输错了（模仿12306）" + throwable.getLocalizedMessage());
    }

    private void synchShopcartData(String userId,HttpServletRequest request,HttpServletResponse response){
        /**
         * 1. redis中无数据，如果cookie中的购物车为空，那么这个时候不做任何处理
         *                 如果cookie中的购物车不为空，此时直接放入redis中
         * 2. redis中有数据，如果cookie中的购物车为空，那么直接把redis的购物车覆盖本地cookie
         *                 如果cookie中的购物车不为空，
         *                      如果cookie中的某个商品在redis存在,
         *                      则以cookie为主，删除redis中的，
         *                      把cookie中的商品直接覆盖redis中（参考京东）
         * 3. 同步到redis中去了以后，覆盖本地cookie购物车数据，保证本地购物车的数据是同步最新的
         */

        // 从redis中获取购物车
        String shopcartJsonRedis = redisOperator.get(FOODIE_SHOPCART + ":" + userId);

        // 从cookie中获取购物车
        String shopcartStrCookie = CookieUtils.getCookieValue(request,FOODIE_SHOPCART,true);

        if (StringUtils.isBlank(shopcartJsonRedis)) {

            // redis为空，cookie不为空，直接把cookie中的数据放入redis
            if (StringUtils.isNotBlank(shopcartStrCookie)) {
                redisOperator.set(FOODIE_SHOPCART + ":" + userId, shopcartStrCookie);
            }

        }else{
            // redis不为空，cookie不为空,合并cookie和redis中购物车的商品数据（同一商品则覆盖redis）
            if (StringUtils.isNotBlank(shopcartStrCookie)) {

                /**
                 * 1. 已经存在的，把cookie中对应的数量，覆盖redis（参考京东）
                 * 2. 该项商品标记为待删除，统一放入一个待删除的list
                 * 3. 从cookie中清理所有的待删除list
                 * 4. 合并redis和cookie中的数据
                 * 5. 更新到redis和cookie中
                 */

                List<ShopcartBO> shopcartListRedis = JsonUtils.jsonToList(shopcartJsonRedis, ShopcartBO.class);
                List<ShopcartBO> shopcartListCookie = JsonUtils.jsonToList(shopcartStrCookie, ShopcartBO.class);

                // 定义一个待删除list
                List<ShopcartBO> pendingDeleteList = new ArrayList<>();

                for (ShopcartBO redisShopcart : shopcartListRedis) {

                    String redisSpecId = redisShopcart.getSpecId();

                    for (ShopcartBO cookieShopcart : shopcartListCookie) {
                        String cookieSpecId = cookieShopcart.getSpecId();

                        if (redisSpecId.equals(cookieSpecId)) {
                            // 覆盖购买数量，不累加，参考京东
                            redisShopcart.setBuyCounts(cookieShopcart.getBuyCounts());
                            // 把cookieShopcar放入待删除列表，用于最后的删除与合并
                            pendingDeleteList.add(cookieShopcart);
                        }

                    }
                }

                // 从现有cookie中删除对应覆盖过的商品数据
                shopcartListCookie.removeAll(pendingDeleteList);

                // 合并两个list
                shopcartListRedis.addAll(shopcartListCookie);

                // 更新到redis和cookie
                CookieUtils.setCookie(request, response, FOODIE_SHOPCART, JsonUtils.objectToJson(shopcartListRedis), true);
                redisOperator.set(FOODIE_SHOPCART + ":" + userId, JsonUtils.objectToJson(shopcartListRedis));


            }else{
                // redis不为空，cookie为空，直接把redis覆盖cookie
                CookieUtils.setCookie(request, response, FOODIE_SHOPCART, shopcartJsonRedis,true);
            }
        }

    }

    /**
     * 设置密码、手机、邮件、创建时间、更新时间、生日为空
     */

    public Users setNullProperty(Users userResult){
        userResult.setPassword(null);
        userResult.setMobile(null);
        userResult.setEmail(null);
        userResult.setCreatedTime(null);
        userResult.setUpdatedTime(null);
        userResult.setBirthday(null);
        return userResult;
    }

    @ApiOperation(value = "退出登录",notes = "退出登录",httpMethod = "POST")
    @PostMapping("/logout")
    public IMOOCJSONResult logout(@RequestParam String userId,
                                  HttpServletRequest request,
                                  HttpServletResponse response){

        // 清除用户的相关信息的cookie
        CookieUtils.deleteCookie(request,response,"user");


        // 用户退出登录，清除redis中user的会话信息
        redisOperator.del(REDIS_USER_TOKEN + ":" + userId);

        // 分布式会话中需要清理用户数据
        CookieUtils.deleteCookie(request, response, FOODIE_SHOPCART);

        return IMOOCJSONResult.ok();

    }


}

```

![](https://tcs.teambition.net/storage/31215cbfd46ebba798b3796f56595a316526?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU1MSwiaWF0IjoxNjEyMTkwNzUxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1Y2JmZDQ2ZWJiYTc5OGIzNzk2ZjU2NTk1YTMxNjUyNiJ9.S35hmcU3FsVEoReUtmesep0Z2zuodO89RVmdV5ViMGc&download=image.png "")

![](https://tcs.teambition.net/storage/312110b114746cd5a773ec9618be0d5bd6e7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU1MSwiaWF0IjoxNjEyMTkwNzUxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExMGIxMTQ3NDZjZDVhNzczZWM5NjE4YmUwZDViZDZlNyJ9.GgbY96qV6deqBoZ2LM7H1dXloJGQnDsmD0WtZhyK4Ao&download=image.png "")

![](https://tcs.teambition.net/storage/3121b1737c2785449d2802758679818ed93e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU1MSwiaWF0IjoxNjEyMTkwNzUxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiMTczN2MyNzg1NDQ5ZDI4MDI3NTg2Nzk4MThlZDkzZSJ9.mfdFGxkP1s3-cndRK7rmDBNHckPBWbzSL57Pj6t72cE&download=image.png "")

```json
[
    {
        "id": "190825CG3AA14Y3C",
        "userId": "1908189H7TNWDTXP",
        "receiver": "jack",
        "mobile": "13333333333",
        "province": "北京",
        "city": "北京",
        "district": "东城区",
        "detail": "123",
        "extand": null,
        "isDefault": 1,
        "createdTime": "2019-08-25T22:34:14.000+0000",
        "updatedTime": "2019-08-25T22:34:14.000+0000"
    },
    {
        "id": "190825CG4ZCSSWM8",
        "userId": "1908189H7TNWDTXP",
        "receiver": "abc",
        "mobile": "13666666666",
        "province": "北京",
        "city": "北京",
        "district": "东城区",
        "detail": "345",
        "extand": null,
        "isDefault": 0,
        "createdTime": "2019-08-25T22:34:24.000+0000",
        "updatedTime": "2019-08-25T22:34:24.000+0000"
    }
]

```

![](https://tcs.teambition.net/storage/3121e0af686bb59ca2544544223452d3f8c2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU1MSwiaWF0IjoxNjEyMTkwNzUxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlMGFmNjg2YmI1OWNhMjU0NDU0NDIyMzQ1MmQzZjhjMiJ9.Oic34n-lqHfebQ57SNQwteIbTnABywPT5jcFgIFVyiE&download=image.png "")

![](https://tcs.teambition.net/storage/312191b69f607da65bea423657b4431b447b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU1MSwiaWF0IjoxNjEyMTkwNzUxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5MWI2OWY2MDdkYTY1YmVhNDIzNjU3YjQ0MzFiNDQ3YiJ9.xZ27bS1LouC3WtvUSRm0qJvYbXkDKtCcQGaYw-cw4gU&download=image.png "")



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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU1MSwiaWF0IjoxNjEyMTkwNzUxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.gRx6ENgIwSOO3X3kVqw-CgCAu72WaZzsoS_Yh8Z84Fo&download=image.png "")

