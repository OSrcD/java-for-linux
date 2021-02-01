![](https://tcs.teambition.net/storage/312258ca8336a7fa4d7f5c98ab00752defaa?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM3OCwiaWF0IjoxNjEyMTkwNTc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI1OGNhODMzNmE3ZmE0ZDdmNWM5OGFiMDA3NTJkZWZhYSJ9.Wy1_dvx18edqKSe-TrgUIKsSbHJn5v_3QfQ6VNMoPYM&download=2020-09-17%20060926.png "")

![](https://tcs.teambition.net/storage/31228c7980cea95609481d797c1cfa038ef9?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM3OCwiaWF0IjoxNjEyMTkwNTc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI4Yzc5ODBjZWE5NTYwOTQ4MWQ3OTdjMWNmYTAzOGVmOSJ9.dQlGB1NPN3AHETc3wSIcrvZfoFDCHZE-DAjAUlBH4q8&download=image.png "")



![](https://tcs.teambition.net/storage/31224b7ad165400f814f4a80ab0a48926cf1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM3OCwiaWF0IjoxNjEyMTkwNTc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI0YjdhZDE2NTQwMGY4MTRmNGE4MGFiMGE0ODkyNmNmMSJ9.Zxm3L2aLSY4h19U_f81yEIVtlJtyBi3MaXiX-di7Yyo&download=image.png "")

![](https://tcs.teambition.net/storage/3122db72790892d525ebccd482bd018b7f94?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM3OCwiaWF0IjoxNjEyMTkwNTc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkYjcyNzkwODkyZDUyNWViY2NkNDgyYmQwMThiN2Y5NCJ9.i03tSzpRy1_fTFWprhjCIX4IqVCb_ZswyrVFgz0fPz4&download=image.png "")

```java
package com.imooc.user.controller;

import com.imooc.auth.service.AuthService;
import com.imooc.auth.service.pojo.Account;
import com.imooc.auth.service.pojo.AuthCode;
import com.imooc.auth.service.pojo.AuthResponse;
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
import java.util.Calendar;
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

    @Autowired
    private AuthService authService;

    /**
     * 定义 header 存储的值叫什么名字
     */
    private static final String AUTH_HEADER = "Authorization";

    private static final String REFRESH_TOKEN_HEADER = "refresh-token";

    private static final String UID_HEADER = "imooc-user-id";

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

        /**
         * 生成token
         */
        AuthResponse token = authService.tokenize(userResult.getId());

        // 判断 token
        if (!AuthCode.SUCCESS.getCode().equals(token.getCode())) {
            log.error("Token error - uid={}", userResult.getId());
            return IMOOCJSONResult.errorMsg("Token error");
        }

        // 将token添加到Header当中
        addAuth2Header(response,token.getAccount());


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

        // 清理 token
        Account account = Account.builder()
                .token(request.getHeader(AUTH_HEADER))
                .refreshToken(request.getHeader(REFRESH_TOKEN_HEADER))
                .userId(userId)
                .build();
        AuthResponse auth = authService.delete(account);
        if (!AuthCode.SUCCESS.getCode().equals(auth.getCode())) {
            log.error("Token error - uid={}",userId);
            return IMOOCJSONResult.errorMsg("Token error");
        }


        // 清除用户的相关信息的cookie
        CookieUtils.deleteCookie(request,response,"user");


        // 用户退出登录，清除redis中user的会话信息
        redisOperator.del(REDIS_USER_TOKEN + ":" + userId);

        // 分布式会话中需要清理用户数据
        CookieUtils.deleteCookie(request, response, FOODIE_SHOPCART);

        return IMOOCJSONResult.ok();

    }

    // TODO 修改前端js代码
    // 在前端页面里拿到Authorization，refresh-token和imooc-user-id。
    // 前端每次请求服务，都把这几个参数带上
    private void addAuth2Header(HttpServletResponse response, Account token) {

        response.setHeader(AUTH_HEADER, token.getToken());
        response.setHeader(REFRESH_TOKEN_HEADER,token.getRefreshToken());
        response.setHeader(UID_HEADER, token.getUserId());
        /**
         * Token 签发后 过一天就会过期了
         * 让前端感知到，过期时间一天，这样可以在临近过期的时候refresh token
         */
        Calendar expTime = Calendar.getInstance();
        expTime.add(Calendar.DAY_OF_MONTH, 1);
        // + "" 强转为字符串
        response.setHeader("token-exp-time",expTime.getTimeInMillis() + "");

    }


}

```

![](https://tcs.teambition.net/storage/312258b847dec0d01774382bbbde57676ba6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM3OCwiaWF0IjoxNjEyMTkwNTc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI1OGI4NDdkZWMwZDAxNzc0MzgyYmJiZGU1NzY3NmJhNiJ9._bSxf5t9xlxAGzGHYlTtLbElNm8HvCflvHMQ2m85Ev8&download=image.png "")

```java
package com.imooc.springcloud;

import com.imooc.springcloud.filter.AuthFilter;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.cloud.gateway.filter.ratelimit.KeyResolver;
import org.springframework.cloud.gateway.filter.ratelimit.RateLimiter;
import org.springframework.cloud.gateway.route.RouteLocator;
import org.springframework.cloud.gateway.route.builder.RouteLocatorBuilder;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.http.HttpStatus;

@Configuration
public class RoutesConfiguration {

    @Autowired
    private KeyResolver hostNameResolver;

    @Autowired
    @Qualifier("redisLimiterUser") // 指定加载哪个bean
    private RateLimiter rateLimiterUser;

    /**
     * AuthFilter 会自动被注入
     * @param builder
     * @param authFilter
     * @return
     */
    @Bean
    public RouteLocator routes(RouteLocatorBuilder builder, AuthFilter authFilter) {
        return builder.routes()
                // FIXME search服务自己实现
                // Auth在网关层有很多种做法，我用了种最丑的，同学们可以试试其他姿势
                // 1) 【最常用】网关层或微服务自己本地校验jwt token有效性，不向auth-service发起远程调用
                // 2) 【路由配置最简单】可以把AuthFilter注册为global filter，
                //     然后在AuthFilter里配置需要过滤的url pattern(也可以从config-server动态拉取)
                // 3) 【路由配置也简单】也可以采用interceptor的形式
                // 4) 【路由配置最丑】这就是我选的路，只是为了演示下自定义过滤器，才走了这条不归路
                // 要注意声明URL Pattern的先后顺序，一个URL可能匹配多个路由，先来后到
                //
                // FIXME
                // 1) 将其他需要登录校验的地址添加在下面，或者采用上面提到的其他方案改造登录检测过程
                // 2) 修改前端JS代码，记得把login后返回的jwt-token和refresh-token带到每个请求的header里
                // 3) 前端JS依据header中的Authorization来判断是否登录
                /**
                 * 验证与鉴权
                 */
                .route(r -> r.path("/address/list",
                        "/address/add",
                        "/address/update",
                        "/address/setDefault",
                        "/address/delete",
                        "/userInfo/**", "/center/**")
                        .filters(f -> f.filter(authFilter))
                        // 不会 js 就让他不起作用
//                        .filters(f -> f.filter(authFilter))
                        .uri("lb://FOODIE-USER-SERVICE")
                )
                // 给前端调用刷新接口
                .route(r -> r.path("/auth-service/refresh")
                    .uri("lb://FOODIE-AUTH-SERVICE")
                )

                .route(r -> r.path("/search/**", "/index/**", "/items/search", "/items/catItems")

                        .uri("lb://FOODIE-SEARCH-SERVICE")
                )

                .route(r -> r.path("/address/**", "/passport/**", "/userInfo/**", "/center/**")
                        // 指定 requestRateLimiter 过滤器
                        .filters(f -> f.requestRateLimiter(c -> {
                            // 指定限流Key
                            c.setKeyResolver(hostNameResolver);
                            // 指定限流规则
                            c.setRateLimiter(rateLimiterUser);
                            c.setStatusCode(HttpStatus.BAD_GATEWAY);
                        }))
                        .uri("lb://FOODIE-USER-SERVICE")
                )

                .route(r -> r.path("/items/**")
                        .uri("lb://FOODIE-ITEM-SERVICE")
                )

                .route(r -> r.path("/shopcart/**")
                        .uri("lb://FOODIE-CART-SERVICE")
                )

                .route(r -> r.path("/orders/**", "/myorders/**", "/mycomments/**")
                        .uri("lb://FOODIE-ORDER-SERVICE")
                )
                .build();
    }

}

```

启动 注册中心

![](https://tcs.teambition.net/storage/3122dec824573c2dc39d7e65c2568a589a67?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM3OCwiaWF0IjoxNjEyMTkwNTc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkZWM4MjQ1NzNjMmRjMzlkN2U2NWMyNTY4YTU4OWE2NyJ9.1QGDsIdwQk4Pfu19pNa3FF_9LXV2ZhAZJlukI2DiWtc&download=image.png "")

![](https://tcs.teambition.net/storage/3122b1de5a3f468b80212c74b200551cc7c6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM3OCwiaWF0IjoxNjEyMTkwNTc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJiMWRlNWEzZjQ2OGI4MDIxMmM3NGIyMDA1NTFjYzdjNiJ9.byk2ZmDhWty_n_uzNoCXlj9fhY229q1qpUEW6VWGua4&download=image.png "")

![](https://tcs.teambition.net/storage/3122e893e2ce18f4f6bc014d7e862c0abad5?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM3OCwiaWF0IjoxNjEyMTkwNTc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJlODkzZTJjZTE4ZjRmNmJjMDE0ZDdlODYyYzBhYmFkNSJ9.eYhkD_rili4IYp3nb2cgPyKJR_LokmhUOBqIpn7Lxjk&download=image.png "")

![](https://tcs.teambition.net/storage/3122c3a57d7916ba7635eaca51b8f8248df6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM3OCwiaWF0IjoxNjEyMTkwNTc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJjM2E1N2Q3OTE2YmE3NjM1ZWFjYTUxYjhmODI0OGRmNiJ9.XwHR6w9KzkhFgXa2PPiTCGsBbFv1C3nOR6SjunHgdMg&download=image.png "")

![](https://tcs.teambition.net/storage/31229b377ad98f1afaf17b2bdcb0f33fb02b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM3OCwiaWF0IjoxNjEyMTkwNTc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5YjM3N2FkOThmMWFmYWYxN2IyYmRjYjBmMzNmYjAyYiJ9.tBevbqlnKWKTDwbv37D-RqRrJwBYDUB49Gzwr3RkrHM&download=image.png "")

![](https://tcs.teambition.net/storage/31226ed6c74c68e2aea611ba7274f7c2439b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM3OCwiaWF0IjoxNjEyMTkwNTc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI2ZWQ2Yzc0YzY4ZTJhZWE2MTFiYTcyNzRmN2MyNDM5YiJ9.zKW0wZx8_6yF-t_8BlXQM5Q-hUeWFKdAp9ql9IaFpqU&download=image.png "")

![](https://tcs.teambition.net/storage/312242117686e7e93d4592e3fcb155c881f7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM3OCwiaWF0IjoxNjEyMTkwNTc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI0MjExNzY4NmU3ZTkzZDQ1OTJlM2ZjYjE1NWM4ODFmNyJ9.U6friQwm_La1_BfXNkhnUA9P2pu4lUvebJdZ2yDA9pA&download=image.png "")

![](https://tcs.teambition.net/storage/31221d1b06822254d4de4dbbfb6264248421?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM3OCwiaWF0IjoxNjEyMTkwNTc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxZDFiMDY4MjIyNTRkNGRlNGRiYmZiNjI2NDI0ODQyMSJ9.l0suFBdbdceD1H32w9gDgN038_RSNYo7V524tCuVG3s&download=image.png "")

![](https://tcs.teambition.net/storage/3122987bba14cc819e7bce01713ff5b0ba73?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM3OCwiaWF0IjoxNjEyMTkwNTc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5ODdiYmExNGNjODE5ZTdiY2UwMTcxM2ZmNWIwYmE3MyJ9.4dlsaoYGu5rji2MKaTRedqLGq7Yzcme8n-_akylukP0&download=image.png "")

![](https://tcs.teambition.net/storage/31229b97d8efb363b3784e84e532e0d01aad?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM3OCwiaWF0IjoxNjEyMTkwNTc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5Yjk3ZDhlZmIzNjNiMzc4NGU4NGU1MzJlMGQwMWFhZCJ9.Cv6nUpmYxLsjP1601geM1Dai-SRtEt35bcxwSi1U56I&download=image.png "")

![](https://tcs.teambition.net/storage/3122f324381c77f9c6841e8c26d61299650c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM3OCwiaWF0IjoxNjEyMTkwNTc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJmMzI0MzgxYzc3ZjljNjg0MWU4YzI2ZDYxMjk5NjUwYyJ9.M2Y-h_PSfSljv-bB54l1_HTx4CO7J49qXFpRBDSeYtw&download=image.png "")

![](https://tcs.teambition.net/storage/31229ef39642677852a3a3c862d4f54cd5f8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM3OCwiaWF0IjoxNjEyMTkwNTc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5ZWYzOTY0MjY3Nzg1MmEzYTNjODYyZDRmNTRjZDVmOCJ9.jIQI_iodnDS3StNinNXb-73iUgZSzqh2g0gZR7oClbE&download=image.png "")

![](https://tcs.teambition.net/storage/31224d6da8f936f5873f4a56bcba6adf9a04?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM3OCwiaWF0IjoxNjEyMTkwNTc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI0ZDZkYThmOTM2ZjU4NzNmNGE1NmJjYmE2YWRmOWEwNCJ9.OCtaoGTm9zY2aRjS1UjGL2hLz1Gwpo04b2WzR-fzFPs&download=image.png "")

![](https://tcs.teambition.net/storage/3122505b485b1e1e5b904afd005af9a32cdd?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM3OCwiaWF0IjoxNjEyMTkwNTc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI1MDViNDg1YjFlMWU1YjkwNGFmZDAwNWFmOWEzMmNkZCJ9.9cKy0hOE9boNEy7-YT4uORLc4GWcHNkDmLtF2USyrGE&download=image.png "")

```json
{
    "status": 200,
    "msg": "OK",
    "data": {
        "id": "210129DS8FH0S0DP",
        "username": "banxian",
        "password": null,
        "nickname": "banxian",
        "realname": null,
        "face": "http://122.152.205.72:88/group1/M00/00/05/CpoxxFw_8_qAIlFXAAAcIhVPdSg994.png",
        "mobile": null,
        "email": null,
        "sex": 2,
        "birthday": null,
        "createdTime": null,
        "updatedTime": null
    }
}

```

![](https://tcs.teambition.net/storage/312201e4c28ae38a4626ac968aa074323aae?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM3OCwiaWF0IjoxNjEyMTkwNTc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIwMWU0YzI4YWUzOGE0NjI2YWM5NjhhYTA3NDMyM2FhZSJ9.z_hKVdM7ZopTpTaY7d2mvx9gCrzgMo2QAGezf0zNvNk&download=image.png "")

![](https://tcs.teambition.net/storage/3122e5472b7b3045d5d173b53dc7b009c34a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM3OCwiaWF0IjoxNjEyMTkwNTc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJlNTQ3MmI3YjMwNDVkNWQxNzNiNTNkYzdiMDA5YzM0YSJ9.Wf3CwEGMKMKKGvkFwBvSLLtUDr2BHQ-Rw9QV2Y1ntnU&download=image.png "")

![](https://tcs.teambition.net/storage/3122a68ad3809640eb7321114ab412ab0e47?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM3OCwiaWF0IjoxNjEyMTkwNTc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhNjhhZDM4MDk2NDBlYjczMjExMTRhYjQxMmFiMGU0NyJ9.Iinoyq3FIBk0FHUQKpJpYhXyTjq914qkw7V13ZCDuBs&download=image.png "")

```text
Authorization
eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJ5YW8iLCJleHAiOjE2MTIwMDU2NzksImlhdCI6MTYxMTkxOTI3OSwidXNlcmlkIjoiMjEwMTI5RFM4RkgwUzBEUCJ9.wR-c9W4TAyY_q3SVfMgkZiVXo_x_71PvUHAOk7ZcBlc

imooc-user-id
210129DS8FH0S0DP

```

![](https://tcs.teambition.net/storage/31225471eb219cacc0e148fa9ca4321090e0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM3OCwiaWF0IjoxNjEyMTkwNTc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI1NDcxZWIyMTljYWNjMGUxNDhmYTljYTQzMjEwOTBlMCJ9.Hg2SecTGb70rufk2unUzWyhbmlObL9Hr7TzOEaCt1TE&download=image.png "")

![](https://tcs.teambition.net/storage/3122a96108ed83f8327d0c8a9c9b4f7fe9e0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM3OCwiaWF0IjoxNjEyMTkwNTc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhOTYxMDhlZDgzZjgzMjdkMGM4YTljOWI0ZjdmZTllMCJ9.lN1XCKC--XLMjQOOOO1ItOb1RA8n5DYErqmS_kOGdLQ&download=image.png "")

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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM3OCwiaWF0IjoxNjEyMTkwNTc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.Eivn9u0tcSTXqh08WXW2waWRl2L2CSojElFUSSbYnjw&download=image.png "")

