![](https://tcs.teambition.net/storage/31220c64df3d59ae96ccdc28efb8bdde4fdb?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM2NiwiaWF0IjoxNjEyMTkwNTY2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIwYzY0ZGYzZDU5YWU5NmNjZGMyOGVmYjhiZGRlNGZkYiJ9.ckJnNyrfBXNhMePrYnEs12J4SxEO1_O0qNvr7VhQkzY&download=image.png "")

```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <parent>
        <artifactId>foodie-cloud</artifactId>
        <groupId>com.imooc</groupId>
        <version>1.0-SNAPSHOT</version>
        <relativePath>../../pom.xml</relativePath>
    </parent>
    <modelVersion>4.0.0</modelVersion>

    <artifactId>gateway</artifactId>

    <dependencies>
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-gateway</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-client</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-actuator</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-data-redis-reactive</artifactId>
        </dependency>

        <!-- 因为spring cloud gateway是基于webflux的，
        如果非要web支持的话需要导入spring-boot-starter-webflux而不是spring-boot-start-web-->
        <dependency>
            <groupId>com.imooc</groupId>
            <artifactId>foodie-auth-api</artifactId>
            <version>${project.version}</version>
            <exclusions>
                <exclusion>
                    <groupId>org.springframework.boot</groupId>
                    <artifactId>spring-boot-starter-web</artifactId>
                </exclusion>
            </exclusions>
        </dependency>

    </dependencies>

    <build>
        <plugins>
            <plugin>
                <groupId>org.springframework.boot</groupId>
                <artifactId>spring-boot-maven-plugin</artifactId>
                <configuration>
                    <mainClass>com.imooc.GatewayApplication</mainClass>
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

![](https://tcs.teambition.net/storage/3122e79fd97ad4087640e8ff1e98f8a22e81?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM2NiwiaWF0IjoxNjEyMTkwNTY2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJlNzlmZDk3YWQ0MDg3NjQwZThmZjFlOThmOGEyMmU4MSJ9.cKJcRIkSCZ7LiPisP3YXhv11HDWmF7uWF08Qf_vBT2c&download=image.png "")

```java
package com.imooc.springcloud;


import com.imooc.auth.service.AuthService;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import org.springframework.cloud.openfeign.EnableFeignClients;


@EnableDiscoveryClient
@SpringBootApplication
@EnableFeignClients(basePackageClasses = {
        AuthService.class
})
public class GatewayApplication {

    public static void main(String[] args) {
        SpringApplication.run(GatewayApplication.class);
    }

}

```

![](https://tcs.teambition.net/storage/3122079e07e36b648eb6e6aa67962548a513?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM2NiwiaWF0IjoxNjEyMTkwNTY2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIwNzllMDdlMzZiNjQ4ZWI2ZTZhYTY3OTYyNTQ4YTUxMyJ9.A6bmCIMql-IsIhRxSCxL1JGOIqfMx9w8wO35mL0QUbo&download=image.png "")

```java
package com.imooc.springcloud.filter;

import com.imooc.auth.service.AuthService;
import com.imooc.auth.service.pojo.Account;
import com.imooc.auth.service.pojo.AuthResponse;
import lombok.extern.slf4j.Slf4j;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cloud.gateway.filter.GatewayFilter;
import org.springframework.cloud.gateway.filter.GatewayFilterChain;
import org.springframework.context.annotation.Configuration;
import org.springframework.core.Ordered;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.server.reactive.ServerHttpRequest;
import org.springframework.http.server.reactive.ServerHttpResponse;
import org.springframework.stereotype.Component;
import org.springframework.web.server.ServerWebExchange;
import reactor.core.publisher.Mono;

@Component("authFilter")
@Slf4j
public class AuthFilter implements GatewayFilter, Ordered {

    private static final String AUTH = "Authorization";
    private static final String USERNAME = "imooc-user-name";
    private static final String USERID = "imooc-user-id";

    @Autowired
    private AuthService authService;

    @Override
    public Mono<Void> filter(ServerWebExchange exchange, GatewayFilterChain chain) {
        log.info("Auth start");
        ServerHttpRequest request = exchange.getRequest();
        HttpHeaders header = request.getHeaders();
        String token = header.getFirst(AUTH);
        String userId = header.getFirst(USERID);

        ServerHttpResponse response = exchange.getResponse();
        if (StringUtils.isBlank(token)) {
            log.error("token not found");
            response.setStatusCode(HttpStatus.UNAUTHORIZED);
            return response.setComplete();
        }

        Account acct = Account.builder().token(token).userId(userId).build();
        AuthResponse resp = authService.verify(acct);
        if (resp.getCode() != 1L) {
            log.error("invalid token");
            response.setStatusCode(HttpStatus.FORBIDDEN);
            return response.setComplete();
        }

        // TODO 将用户信息存放在请求header中传递给下游业务
        ServerHttpRequest.Builder mutate = request.mutate();
        mutate.header(USERID, userId);
        mutate.header(AUTH, token);
        ServerHttpRequest buildReuqest = mutate.build();

        // TODO 如果响应中需要放数据，也可以放在response的header中
        response.getHeaders().add(USERID, userId);
        response.getHeaders().add(AUTH, token);
        return chain.filter(exchange.mutate()
                .request(buildReuqest)
                .response(response)
                .build());
    }

    @Override
    public int getOrder() {
        return 0;
    }
}

```

![](https://tcs.teambition.net/storage/3122f6c186ab07b774fde03a21c5edf7b110?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM2NiwiaWF0IjoxNjEyMTkwNTY2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJmNmMxODZhYjA3Yjc3NGZkZTAzYTIxYzVlZGY3YjExMCJ9.QDCDIJPLMjro-sSc_3xN2FmFAJ0lC0PfEWrO7EXET-M&download=image.png "")

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

![](https://tcs.teambition.net/storage/31227915893aa90d3e9179bc12547dd52d03?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM2NiwiaWF0IjoxNjEyMTkwNTY2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI3OTE1ODkzYWE5MGQzZTkxNzliYzEyNTQ3ZGQ1MmQwMyJ9.GvXbmsYYsaAGJ4Z-JOt8kROBm7wC4nT1CLZATFG-LSM&download=image.png "")

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

        <dependency>
            <groupId>com.imooc</groupId>
            <artifactId>foodie-auth-api</artifactId>
            <version>${project.version}</version>
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

![](https://tcs.teambition.net/storage/312225d4369bfeb814ccda109d7bc7ccbe80?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM2NiwiaWF0IjoxNjEyMTkwNTY2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIyNWQ0MzY5YmZlYjgxNGNjZGExMDlkN2JjN2NjYmU4MCJ9.voFDLqpzhK5V5XFFpc6vEknirMIh7pEOrtkFD7nS0AU&download=image.png "")

```java
package com.imooc.user;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.circuitbreaker.EnableCircuitBreaker;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import org.springframework.cloud.openfeign.EnableFeignClients;
import org.springframework.context.annotation.ComponentScan;
import tk.mybatis.spring.annotation.MapperScan;


@SpringBootApplication
// 扫描 mybatis 通用 mapper 所在的包
@MapperScan(basePackages = "com.imooc.user.mapper")
// 扫描所有包以及相关组件包
@ComponentScan(basePackages = {"com.imooc", "org.n3r.idworker"})
@EnableDiscoveryClient
@EnableCircuitBreaker
// 可以以 basePackageClasses 类的形式加载 也可以以 basePackages
@EnableFeignClients(basePackages = {
        "com.imooc.auth" //调用微服务auth 生成token
})
// TODO feign注解
public class UserApplication {

    public static void main(String[] args) {
        SpringApplication.run(UserApplication.class, args);
    }

}

```

authFilter 从这里拿值

![](https://tcs.teambition.net/storage/312215171ed64f66a2a3918a110eabeef215?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM2NiwiaWF0IjoxNjEyMTkwNTY2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxNTE3MWVkNjRmNjZhMmEzOTE4YTExMGVhYmVlZjIxNSJ9.ovAYmpZWPB2FLglDnYnRFXQdMkZ_n6itoqvtfMqwp_A&download=image.png "")

![](https://tcs.teambition.net/storage/3122f2d1edd8c97a11f4cdedb270d352af7f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM2NiwiaWF0IjoxNjEyMTkwNTY2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJmMmQxZWRkOGM5N2ExMWY0Y2RlZGIyNzBkMzUyYWY3ZiJ9.26NbjO2aDtesvISXt8iIzpyltsEyRuU62jU3t9WXX-A&download=image.png "")

![](https://tcs.teambition.net/storage/3122c9deaaea2a4e79b3ca35c1d0f90a113c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM2NiwiaWF0IjoxNjEyMTkwNTY2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJjOWRlYWFlYTJhNGU3OWIzY2EzNWMxZDBmOTBhMTEzYyJ9.VGmrgffOi-z17wEqqWDSR4kDT9oqDKLp9j08KlFkFsA&download=image.png "")

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

    // TODO 修改前端js代码
    // 在前端页面里拿到Authorization，refresh-token和imooc-user-id。
    // 前端每次请求服务，都把这几个参数带上
    private void addAuth2Header(HttpServletResponse response, Account token) {

        response.setHeader(AUTH_HEADER, token.getToken());
        response.setHeader(REFRESH_TOKEN_HEADER,token.getRefreshToken());
        response.setHeader(UID_HEADER, token.getUserId());

    }


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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM2NiwiaWF0IjoxNjEyMTkwNTY2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.9bEOzDeliAf0ROXuoHt3cndVWFFSINPg0p5vN9gC0Sg&download=image.png "")

