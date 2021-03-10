![](https://tcs.teambition.net/storage/31222afcc0609d99aa55cca6c0b56a189bd8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0OSwiaWF0IjoxNjEyMTkwMjQ5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIyYWZjYzA2MDlkOTlhYTU1Y2NhNmMwYjU2YTE4OWJkOCJ9.h-gqKKo6xT2FbtvW8D_LCH8xLZtIc63FPUGizFV84kQ&download=2020-09-17%20061738.png "")

![](https://tcs.teambition.net/storage/312269f1d8c00e5ea5d650800bb1d08d02b5?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0OSwiaWF0IjoxNjEyMTkwMjQ5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI2OWYxZDhjMDBlNWVhNWQ2NTA4MDBiYjFkMDhkMDJiNSJ9.rHwuwi8SGHpdYWeUwL7xTsJeuXgSoiiLcRlsJxCLwQU&download=image.png "")

![](https://tcs.teambition.net/storage/3122090932255fc7300d456be34f4717bdc1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0OSwiaWF0IjoxNjEyMTkwMjQ5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIwOTA5MzIyNTVmYzczMDBkNDU2YmUzNGY0NzE3YmRjMSJ9.rt2ufa7sA5sRsM1BU2Ad5PEJGBMf1em3tqnxqihVk7Y&download=image.png "")

```java
package com.imooc.auth.service.pojo;

import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;


@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
public class Account implements Serializable {

    private String userId;

    private String token;

    private String refreshToken;

    // 机关
    private final boolean skipVerification = false;

}

```

![](https://tcs.teambition.net/storage/3122da22a2940288fce3bd89b52eaa1c3ef7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0OSwiaWF0IjoxNjEyMTkwMjQ5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkYTIyYTI5NDAyODhmY2UzYmQ4OWI1MmVhYTFjM2VmNyJ9.CkD_xcA1ljINuNV2-lGfnBtmZzlBA13WyU3WUu7jrm8&download=image.png "")

![](https://tcs.teambition.net/storage/312217afff5d1489c899ebdc9090ed78b597?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0OSwiaWF0IjoxNjEyMTkwMjQ5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxN2FmZmY1ZDE0ODljODk5ZWJkYzkwOTBlZDc4YjU5NyJ9.KAXoDPS6CoPIGi9tPevNvIIgQRd-lnfoeeqcyFy0os0&download=image.png "")

```java
package com.imooc.auth.service.impl;

import com.imooc.auth.service.AuthService;
import com.imooc.auth.service.pojo.Account;
import com.imooc.auth.service.pojo.AuthCode;
import com.imooc.auth.service.pojo.AuthResponse;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

import java.util.UUID;


@RestController
public class AuthServiceImpl implements AuthService {

    @Autowired
    private JwtService jwtService;

    @Autowired
    private RedisTemplate redisTemplate;

    private static final String USER_TOKEN = "USER_TOKEN-";

    @Override
    public AuthResponse tokenize(String userId) {
        Account account = Account.builder()
                .userId(userId)
                .build();

        String token = jwtService.token(account);
        account.setToken(token);
        account.setRefreshToken(UUID.randomUUID().toString());

        redisTemplate.opsForValue().set(USER_TOKEN + userId, account);
        redisTemplate.opsForValue().set(account.getRefreshToken(), userId);

        return AuthResponse.builder()
                .account(account)
                .code(AuthCode.SUCCESS.getCode())
                .build();
    }

    @Override
    public AuthResponse verify(Account account) {
        // TODO 检查redis中当前token是否还生效
        boolean success = jwtService.verify(account.getToken(), account.getUserId());
        return AuthResponse.builder()
                // TODO 此处最好用invalid token之类的错误信息
                .code(success ? AuthCode.SUCCESS.getCode() : AuthCode.USER_NOT_FOUND.getCode())
                .build();
    }

    // 有很多种方法实现自动刷新，比如前端主动调用（可以在AuthResponse里将过期时间返回给前端口）
    @Override
    public AuthResponse refresh(String refreshToken) {
        String userId = (String) redisTemplate.opsForValue().get(refreshToken);
        if (StringUtils.isBlank(userId)) {
            return AuthResponse.builder()
                    .code(AuthCode.USER_NOT_FOUND.getCode())
                    .build();
        }

        redisTemplate.delete(refreshToken);
        return tokenize(userId);
    }

    @Override
    public AuthResponse delete(@RequestBody Account account) {
        AuthResponse resp = new AuthResponse();
        resp.setCode(AuthCode.SUCCESS.getCode());

        if (account.isSkipVerification()) {
            redisTemplate.delete(USER_TOKEN + account.getUserId());
        }else{
            AuthResponse token = verify(account);
            if (AuthCode.SUCCESS.getCode().equals(token.getCode())) {
                redisTemplate.delete(USER_TOKEN + account.getUserId());
                redisTemplate.delete(account.getRefreshToken());
            } else {
                resp.setCode(AuthCode.USER_NOT_FOUND.getCode());
            }
        }
        return resp;


    }
}

```

![](https://tcs.teambition.net/storage/3122bcfa699a669a9867d877a3f0535f0b7a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0OSwiaWF0IjoxNjEyMTkwMjQ5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJiY2ZhNjk5YTY2OWE5ODY3ZDg3N2EzZjA1MzVmMGI3YSJ9.vQDnZfQcoaeRk-syxBhV9L99lCFeXJGgm2GZ2gQT8_A&download=image.png "")

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

    <artifactId>foodie-user-service</artifactId>

    <dependencies>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-user-api</artifactId>
            <version>${project.version}</version>
        </dependency>

        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-user-mapper</artifactId>
            <version>${project.version}</version>
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

        <dependency>
            <groupId>com.imooc</groupId>
            <artifactId>foodie-auth-api</artifactId>
            <version>${project.version}</version>
        </dependency>

    </dependencies>

</project>
```

![](https://tcs.teambition.net/storage/3122d0316050736bf16e43cdcb2da5bf220f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0OSwiaWF0IjoxNjEyMTkwMjQ5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkMDMxNjA1MDczNmJmMTZlNDNjZGNiMmRhNWJmMjIwZiJ9.raEwCkBpy5pbvLOaVUOc6NqQ4WlqUfo-J8tM4br_lzc&download=image.png "")

```java
package com.imooc.user.stream;

import org.springframework.cloud.stream.annotation.Input;
import org.springframework.cloud.stream.annotation.Output;
import org.springframework.messaging.SubscribableChannel;

public interface ForceLogoutTopic {

    String INPUT = "force-logout-consumer";

    String OUTPUT = "force-logout-producer";

    @Input(INPUT)
    SubscribableChannel input();

    @Output(OUTPUT)
    SubscribableChannel output();
}

```

![](https://tcs.teambition.net/storage/3122df73b97e1f179d050b41c41ddc2b7d02?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0OSwiaWF0IjoxNjEyMTkwMjQ5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkZjczYjk3ZTFmMTc5ZDA1MGI0MWM0MWRkYzJiN2QwMiJ9.cCGohutoNYDSgKxOij98HhBwb9ac-ivYmAUJKwGgUsY&download=image.png "")

```java
package com.imooc.user.stream;

import com.imooc.auth.service.AuthService;
import com.imooc.auth.service.pojo.Account;
import com.imooc.auth.service.pojo.AuthCode;
import com.imooc.auth.service.pojo.AuthResponse;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cloud.stream.annotation.EnableBinding;
import org.springframework.cloud.stream.annotation.StreamListener;
import org.springframework.integration.annotation.ServiceActivator;
import org.springframework.messaging.Message;

@Slf4j
@EnableBinding(value = {
        ForceLogoutTopic.class
})

public class UserMessageConsumer {

    @Autowired
    private AuthService authService;

    @StreamListener(ForceLogoutTopic.INPUT)
    public void consumeLogoutMessage(String payload) {
        log.info("Force logout user，uid={}", payload);

        Account account = Account.builder()
                .userId(payload)
                .skipVerification(true)
                .build();

        AuthResponse resp = authService.delete(account);

        if (!AuthCode.SUCCESS.getCode().equals(resp.getCode())) {
            log.error("Error occurred when deleting user session，uid={}", account.getUserId());
            throw new RuntimeException("Cannot delete user session");
        }

    }

    /**
     * @ServiceActivator 指定回调的信道降级
     * 1）重试（待会配置）& requeue
     * 2）死信队列 & 服务降级
     * 请求到达 Producer之后 producer 只负责分发 每一个 Consumer 处理好以后 它的结果并不是
     * 同步返回给Producer的 这是一个异步的请求
     */
    @ServiceActivator(inputChannel =
            "force-logout-topic.force-logout-group.errors")
    public void fallback(Message message) {
        log.info("Force logout failed");
        // 新零售发布库存 - 异步请求
        // 降级：钉钉群的接口 - 通知运营

        // 强制登出 -> inactive user
        // user表 -> flag（active/inactive）-> 不让你下次登录
    }


}

```

![](https://tcs.teambition.net/storage/3122d98460e013b410f83d1a00be48a00901?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0OSwiaWF0IjoxNjEyMTkwMjQ5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkOTg0NjBlMDEzYjQxMGY4M2QxYTAwYmU0OGEwMDkwMSJ9.Beu8F7bG4V0D9BSOOA_f8B7X_U3AWiVhNZunyJnkJWI&download=image.png "")

```yaml
server:
  port: 10002

spring:
  datasource:                                           # 数据源的相关配置
    # 拆分数据源到独立database instance，或者独立schema
#    url: jdbc:mysql://localhost:3306/foodie-cloud-item?useUnicode=true&characterEncoding=UTF-8&autoReconnect=true
#    url: jdbc:mysql://localhost:3306/foodie-shop-dev?useUnicode=true&characterEncoding=UTF-8&autoReconnect=true
#    password: opendevel
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
  #
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
      # 以Http方式上传数据到zipkin
      # WHY？ bus依赖项会导入rabbitmq的依赖项，zipkin会默认使用mq
    sender:
      type: web
  sleuth:
    sampler:
      probability: 1
    ### 推送变更的时候用
  rabbitmq:
    host: localhost
    port: 5672
    username: guest
    password: guest
  ############################################################
  # Stream配置
  ############################################################
  cloud:
    stream:
      bindings:
        force-logout-consumer:
          destination: force-logout-topic
          group: force-logout-group
          consumer:
            # 默认重试次数就是 3次
            max-attempts: 2
        force-logout-producer:
          destination: force-logout-topic

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

![](https://tcs.teambition.net/storage/31220c9b1a2431b740e1e16aec3946fdda7f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0OSwiaWF0IjoxNjEyMTkwMjQ5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIwYzliMWEyNDMxYjc0MGUxZTE2YWVjMzk0NmZkZGE3ZiJ9._t7YH_x2pGCDSNAtoh0N-aCf7KgInLGSmbTYVa5oCd4&download=image.png "")

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
import com.imooc.user.stream.ForceLogoutTopic;
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
import org.springframework.messaging.support.MessageBuilder;
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

    @Autowired
    ForceLogoutTopic producer;

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



    // FIXME 将这个接口从网关层移除，不对外暴露
    @ApiOperation(value = "用户强制退出登录",notes = "用户退出登录",httpMethod = "POST")
    @PostMapping("/forceLogout")
    public IMOOCJSONResult forceLogout(@RequestParam String userIds){
        if (StringUtils.isNotBlank(userIds)) {
            for (String uid : userIds.split(",")) {
                log.info("send logout message，uid={}", uid);
                producer.output()
                        .send(MessageBuilder.withPayload(uid).build());
            }
        }
        return IMOOCJSONResult.ok();

    }


}

```

启动 auth 配置中心 user redis 注册中心 MQ

![](https://tcs.teambition.net/storage/31223d7ed74bc2fc94a689e7a977f636d6d4?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0OSwiaWF0IjoxNjEyMTkwMjQ5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzZDdlZDc0YmMyZmM5NGE2ODllN2E5NzdmNjM2ZDZkNCJ9.3BjGDrhLQDlbLvrfRd3wRXnno4a4VC13_BPmWvlm-DE&download=image.png "")

![](https://tcs.teambition.net/storage/3122b024bec7207f1948ca5bf73996060ae1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0OSwiaWF0IjoxNjEyMTkwMjQ5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJiMDI0YmVjNzIwN2YxOTQ4Y2E1YmY3Mzk5NjA2MGFlMSJ9.dOjeJmmnJDNWJP39eTTHoAHD5-gSskoeTjVkl6CGob4&download=image.png "")



![](https://tcs.teambition.net/storage/31224ae73e946b9d2941349adff7eef08517?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0OSwiaWF0IjoxNjEyMTkwMjQ5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI0YWU3M2U5NDZiOWQyOTQxMzQ5YWRmZjdlZWYwODUxNyJ9.bKTTIdbXIYTySswGLkBJdS9VTUzw9JXpc8bKTviuW6U&download=image.png "")

![](https://tcs.teambition.net/storage/3122abcb808f2ddef285135d0dc754eaced8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0OSwiaWF0IjoxNjEyMTkwMjQ5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhYmNiODA4ZjJkZGVmMjg1MTM1ZDBkYzc1NGVhY2VkOCJ9.CLSrfKM8SpENX8-SKCLpghF7KeK-S3VNBj2Aq6yYI0g&download=image.png "")

![](https://tcs.teambition.net/storage/31223e44802b3d39314a8cd480e49fb1a6d3?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0OSwiaWF0IjoxNjEyMTkwMjQ5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzZTQ0ODAyYjNkMzkzMTRhOGNkNDgwZTQ5ZmIxYTZkMyJ9.oaXnfEFEQeRxjZyAy8IsZUW8a8ymCGNGBHLq8dJBjJk&download=image.png "")

![](https://tcs.teambition.net/storage/31225664a0f683ea78ab5e5a3c9b81e6514a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0OSwiaWF0IjoxNjEyMTkwMjQ5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI1NjY0YTBmNjgzZWE3OGFiNWU1YTNjOWI4MWU2NTE0YSJ9._wacCLtnwqY0bir-xtusc_ZYrV3eOzkv4yS5hQJ0puM&download=image.png "")

![](https://tcs.teambition.net/storage/312239b33b2da6435128f5205bd611b283ec?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0OSwiaWF0IjoxNjEyMTkwMjQ5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzOWIzM2IyZGE2NDM1MTI4ZjUyMDViZDYxMWIyODNlYyJ9.Lm2EA9PW4APOdUw7w8lg1NuIEf7p5Q9ScWRM3Qtbz7Q&download=image.png "")

![](https://tcs.teambition.net/storage/3122cc0e892ab74f7ff25b18eede3cd5d847?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0OSwiaWF0IjoxNjEyMTkwMjQ5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJjYzBlODkyYWI3NGY3ZmYyNWIxOGVlZGUzY2Q1ZDg0NyJ9.ZIu9kxWhl_Y9YD2Iqq2hSdymjGFpZTlrPsJy0hP8bWw&download=image.png "")

```text
http://localhost:10002/passport/forceLogout?userIds=2011081YNP03A140,123,1234,122

```

![](https://tcs.teambition.net/storage/3122201fbf21909a96b1faf8f84719a76904?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0OSwiaWF0IjoxNjEyMTkwMjQ5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIyMDFmYmYyMTkwOWE5NmIxZmFmOGY4NDcxOWE3NjkwNCJ9.qbcmHIvyGDcWXs81kJmXgIcUo-7CdU2cZfUl61BxkBc&download=image.png "")

![](https://tcs.teambition.net/storage/3122a0d7622cc37ac62ab7364361c443720a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0OSwiaWF0IjoxNjEyMTkwMjQ5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhMGQ3NjIyY2MzN2FjNjJhYjczNjQzNjFjNDQzNzIwYSJ9.tZBohwlzVYLBpJBcr2ToK3SbGBDJRhLAIXq_B5PMR50&download=image.png "")

```text
[22:45:27.260] INFO  c.i.u.c.PassportController - send logout message，uid=2011081YNP03A140
[22:45:27.328] INFO  o.s.a.r.c.CachingConnectionFactory - Attempting to connect to: [localhost:5672]
[22:45:27.351] INFO  o.s.a.r.c.CachingConnectionFactory - Created new connection: rabbitConnectionFactory.publisher#76e62e88:0/SimpleConnection@7d82cfa [delegate=amqp://guest@127.0.0.1:5672/, localPort= 53375]
[22:45:27.374] INFO  o.s.a.r.c.RabbitAdmin - Auto-declaring a non-durable, auto-delete, or exclusive Queue (springCloudBus.anonymous.Kgh_7yzjQ7-vfXWF6fQBgQ) durable:false, auto-delete:true, exclusive:true. It will be redeclared if the broker stops and is restarted while the connection factory is alive, but all messages will be lost.
[22:45:27.418] INFO  c.i.u.c.PassportController - send logout message，uid=123
[22:45:27.423] INFO  c.i.u.c.PassportController - send logout message，uid=1234
[22:45:27.426] INFO  c.i.u.c.PassportController - send logout message，uid=122
[22:45:27.436] INFO  c.i.u.s.UserMessageConsumer - Force logout user，uid=2011081YNP03A140
[22:45:27.751] INFO  c.n.c.ChainedDynamicProperty - Flipping property: foodie-auth-service.ribbon.ActiveConnectionsLimit to use NEXT property: niws.loadbalancer.availabilityFilteringRule.activeConnectionsLimit = 2147483647
[22:45:27.766] INFO  c.n.u.c.ShutdownEnabledTimer - Shutdown hook installed for: NFLoadBalancer-PingTimer-foodie-auth-service
[22:45:27.767] INFO  c.n.l.BaseLoadBalancer - Client: foodie-auth-service instantiated a LoadBalancer: DynamicServerListLoadBalancer:{NFLoadBalancer:name=foodie-auth-service,current list of Servers=[],Load balancer stats=Zone stats: {},Server stats: []}ServerList:null
[22:45:27.776] INFO  c.n.l.DynamicServerListLoadBalancer - Using serverListUpdater PollingServerListUpdater
[22:45:27.919] INFO  c.n.c.ChainedDynamicProperty - Flipping property: foodie-auth-service.ribbon.ActiveConnectionsLimit to use NEXT property: niws.loadbalancer.availabilityFilteringRule.activeConnectionsLimit = 2147483647
[22:45:27.925] INFO  c.n.l.DynamicServerListLoadBalancer - DynamicServerListLoadBalancer for client foodie-auth-service initialized: DynamicServerListLoadBalancer:{NFLoadBalancer:name=foodie-auth-service,current list of Servers=[www.mtv.com:10006],Load balancer stats=Zone stats: {defaultzone=[Zone:defaultzone;	Instance count:1;	Active connections count: 0;	Circuit breaker tripped count: 0;	Active connections per server: 0.0;]
},Server stats: [[Server:www.mtv.com:10006;	Zone:defaultZone;	Total Requests:0;	Successive connection failure:0;	Total blackout seconds:0;	Last connection made:Thu Jan 01 08:00:00 CST 1970;	First connection made: Thu Jan 01 08:00:00 CST 1970;	Active Connections:0;	total failure count in last (1000) msecs:0;	average resp time:0.0;	90 percentile resp time:0.0;	95 percentile resp time:0.0;	min resp time:0.0;	max resp time:0.0;	stddev resp time:0.0]
]}ServerList:org.springframework.cloud.netflix.ribbon.eureka.DomainExtractingServerList@693c943f
[22:45:28.780] INFO  c.n.c.ChainedDynamicProperty - Flipping property: foodie-auth-service.ribbon.ActiveConnectionsLimit to use NEXT property: niws.loadbalancer.availabilityFilteringRule.activeConnectionsLimit = 2147483647
[22:45:30.330] INFO  c.i.u.s.UserMessageConsumer - Force logout user，uid=2011081YNP03A140
[22:45:31.048] INFO  c.i.u.s.UserMessageConsumer - Force logout user，uid=123
[22:45:31.086] INFO  c.i.u.s.UserMessageConsumer - Force logout user，uid=1234
[22:45:31.149] INFO  c.i.u.s.UserMessageConsumer - Force logout user，uid=122


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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTA0OSwiaWF0IjoxNjEyMTkwMjQ5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.voCIDJnHoHS7kzrmr_mLwDb6jWPsduC-bDfPrNYVhg8&download=image.png "")

