

![](https://tcs.teambition.net/storage/312185ffb8c7d658e68a1b11838d140fd3b5?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY2NSwiaWF0IjoxNjExODQzODY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4NWZmYjhjN2Q2NThlNjhhMWIxMTgzOGQxNDBmZDNiNSJ9.kwN6PWuScDeDjU9s8Nkdt6XYQD3sGUx2FvANZTlRdsw&download=image.png "")

```java
package com.imooc.springcloud;

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

    private String username;

    // 生成的访问密钥
    private String token;

    // 通过 refreshToken 生成新的 token
    private String refreshToken;
}

```

![](https://tcs.teambition.net/storage/3121c107588fd3f0c708c8519cac12db17c2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY2NSwiaWF0IjoxNjExODQzODY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjMTA3NTg4ZmQzZjBjNzA4Yzg1MTljYWMxMmRiMTdjMiJ9.T7yuY8FYNrcPnyxmFiupSnUAWBjVw0hP94ftL-0qzBw&download=image.png "")

```java
package com.imooc.springcloud;

import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.web.bind.annotation.*;

import java.util.UUID;


@RestController
@Slf4j
public class Controller {

    @Autowired
    private JwtService jwtService;

    @Autowired
    private RedisTemplate redisTemplate;

    @PostMapping("/login")
    @ResponseBody
    public AuthResponse login(@RequestParam String username,
                              @RequestParam String password) {

        Account account = Account.builder()
                .username(username)
                .build();

        // TODO 验证username + password

        String token = jwtService.token(account);
        account.setToken(token);
        account.setRefreshToken(UUID.randomUUID().toString());

        redisTemplate.opsForValue().set(account.getRefreshToken(),account);

        return AuthResponse.builder()
                .account(account)
                .code(AuthResponseCode.SUCCESS)
                .build();

    }


    @PostMapping("/refresh")
    @ResponseBody
    public AuthResponse refresh(@RequestParam String refreshToken) {
        Account account = (Account) redisTemplate.opsForValue().get(refreshToken);
        if (account == null) {
            return AuthResponse.builder()
                    .code(AuthResponseCode.USER_NOT_FOUND)
                    .build();
        }

        String jwt = jwtService.token(account);
        account.setToken(jwt);
        account.setRefreshToken(UUID.randomUUID().toString());

        redisTemplate.delete(refreshToken);
        redisTemplate.opsForValue().set(account.getRefreshToken(), account);

        return AuthResponse.builder()
                .account(account)
                .code(AuthResponseCode.SUCCESS)
                .build();

    }


    @GetMapping("/verify")
    public AuthResponse verify(@RequestParam String token,
                               @RequestParam String username) {
        boolean success = jwtService.verify(token, username);
        return AuthResponse.builder()
                // TODO 此处最好用invalid token 之类的错误信息
                .code(success ? AuthResponseCode.SUCCESS : AuthResponseCode.USER_NOT_FOUND)
                .build();
    }


}

```

![](https://tcs.teambition.net/storage/3121d5ae51d060c117ddaecb47edc03667dd?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY2NSwiaWF0IjoxNjExODQzODY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkNWFlNTFkMDYwYzExN2RkYWVjYjQ3ZWRjMDM2NjdkZCJ9.LPiF1mgnMY3qi3jsF2zJmPqT4h_n2rF8UAFNY6sEcXk&download=image.png "")

```none
spring.application.name=auth-service
server.port=65100

eureka.client.serviceUrl.defaultZone=http://localhost:20000/eureka/

logging.file=${spring.application.name}.log

spring.redis.database=0
spring.redis.host=192.168.245.138
spring.redis.port=6379
spring.redis.password=imooc

info.app.name=auth-service
info.app.description=test


management.security.user.name=gitee
management.security.user.password=gitee
management.security.user.roles=ADMIN

management.endpoints.web.exposure.include=*
management.endpoint.health.show-details=always




```

![](https://tcs.teambition.net/storage/31217ac0122b755f9019a740f36708048443?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY2NSwiaWF0IjoxNjExODQzODY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3YWMwMTIyYjc1NWY5MDE5YTc0MGYzNjcwODA0ODQ0MyJ9.Ym8yvaftZXJSh5kdeYDLLZ-EVxEnRVR9k1g88GNQVyk&download=image.png "")

```xml
<?xml version="1.0" encoding="UTF-8" ?>
<configuration>
    <appender name="consoleLog" class="ch.qos.logback.core.ConsoleAppender">
        <filter class="ch.qos.logback.classic.filter.ThresholdFilter">
            <level>INFO</level>
        </filter>
        <layout class="ch.qos.logback.classic.PatternLayout">
            <pattern>
                [%d{HH:mm:ss.SSS}] %-5level %logger{15} - %msg%n
            </pattern>
        </layout>
    </appender>

    <appender name="fileLog" class="ch.qos.logback.core.rolling.RollingFileAppender">
        <encoder>
            <pattern>
                [%d{HH:mm:ss.SSS}] %-5level [%thread]%logger{15} - %msg%n
            </pattern>
        </encoder>
        <rollingPolicy class="ch.qos.logback.core.rolling.TimeBasedRollingPolicy">
            <fileNamePattern>logs/%d.log</fileNamePattern>
            <maxHistory>30</maxHistory>
        </rollingPolicy>
    </appender>
    <root level="DEBUG">
        <appender-ref ref = "consoleLog"/>
        <appender-ref ref = "fileLog"/>
    </root>
</configuration>
```

启动

![](https://tcs.teambition.net/storage/31214591bf6e5617628f88e0074e53103d61?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY2NSwiaWF0IjoxNjExODQzODY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0NTkxYmY2ZTU2MTc2MjhmODhlMDA3NGU1MzEwM2Q2MSJ9.DpK2v-lMeIgsVYTNFyRoRHvoiMhedvLb1TyxCw3lE_U&download=image.png "")

![](https://tcs.teambition.net/storage/312135260ea37e36f1174c47d8ed9d9fca5b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY2NSwiaWF0IjoxNjExODQzODY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzNTI2MGVhMzdlMzZmMTE3NGM0N2Q4ZWQ5ZDlmY2E1YiJ9.qg7KET3c0Gnb_16jbKjlIFo9uVZ0UrZW5xpQOiI5M8g&download=image.png "")

```json
{
    "account": {
        "username": "me",
        "token": "eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJ5YW8iLCJleHAiOjE2MTE4MzI0NTksImlhdCI6MTYxMTgzMjM5OSwidXNlcm5hbWUiOiJtZSJ9.1JJ7a2mu97fJeaAvQiBitgctzUwYRlYe2QF2xjj0Jy8",
        "refreshToken": "0833d4f7-4d56-4279-82d0-387129e886cc"
    },
    "code": 1
}

```

![](https://tcs.teambition.net/storage/312193f1209d6ad3e60f682cf1600c92db50?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY2NSwiaWF0IjoxNjExODQzODY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5M2YxMjA5ZDZhZDNlNjBmNjgyY2YxNjAwYzkyZGI1MCJ9.xLLXb7Hl0BzpvLJ7y5yZlbtOe2dsdXiuCt17ZtfDPKg&download=image.png "")

![](https://tcs.teambition.net/storage/3121b3253ef7948d6c3d5d69a87c1813178b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY2NSwiaWF0IjoxNjExODQzODY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiMzI1M2VmNzk0OGQ2YzNkNWQ2OWE4N2MxODEzMTc4YiJ9.UuPhAQfNensc52VglE1xpv0ytox2b_sXbez8f56qwko&download=image.png "")

![](https://tcs.teambition.net/storage/312143a8fa8ee72d916718ec15ba56355e09?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY2NSwiaWF0IjoxNjExODQzODY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0M2E4ZmE4ZWU3MmQ5MTY3MThlYzE1YmE1NjM1NWUwOSJ9.Bm3ENSHoAU5H-nT7__xpwEoY9Rq8E76z7geNnmDyS7E&download=image.png "")

```json
{
    "account": {
        "username": "me",
        "token": "eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJ5YW8iLCJleHAiOjE2MTE4MzI2MjEsImlhdCI6MTYxMTgzMjU2MSwidXNlcm5hbWUiOiJtZSJ9.lqb2rn4DIJHe7ohE_kDWG7b4USSnLo3ss7By-SCBffg",
        "refreshToken": "19a0c64d-18bf-4a8d-aabe-0ff8a60c941f"
    },
    "code": 1
}

```

![](https://tcs.teambition.net/storage/31218ea5574300f70aaef551696a8fa23fdb?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY2NSwiaWF0IjoxNjExODQzODY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4ZWE1NTc0MzAwZjcwYWFlZjU1MTY5NmE4ZmEyM2ZkYiJ9.5oVNzxHrjgyVZhs1k8Ga08arn8JYBB5JqAeKRvUecoc&download=image.png "")

![](https://tcs.teambition.net/storage/312190d115e715ea3cf01247ae8be9524f95?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY2NSwiaWF0IjoxNjExODQzODY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5MGQxMTVlNzE1ZWEzY2YwMTI0N2FlOGJlOTUyNGY5NSJ9.8oGpfmid-zVwcUVArfoXARbfvQE7_wabRN-zFc_L_C0&download=image.png "")

```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <parent>
        <artifactId>spring-cloud-demo</artifactId>
        <groupId>com.imooc</groupId>
        <version>1.0-SNAPSHOT</version>
        <relativePath>../../pom.xml</relativePath>
    </parent>
    <modelVersion>4.0.0</modelVersion>

    <packaging>jar</packaging>

    <artifactId>gateway-sample</artifactId>

    <dependencies>
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-actuator</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-client</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-gateway</artifactId>
        </dependency>


        <!-- Spring boot 下面的 Redis 插件 就可以在配置文件 配置 Redis 连接串 -->
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-data-redis-reactive</artifactId>
        </dependency>

        <!-- 因为spring cloud gateway是基于webflux的，
        如果非要web支持的话需要导入spring-boot-starter-webflux而不是spring-boot-start-web-->
        <dependency>
            <groupId>com.imooc</groupId>
            <artifactId>auth-service-api</artifactId>
            <version>${project.version}</version>
            <exclusions>
                <exclusion>
                    <groupId>org.springframework.boot</groupId>
                    <artifactId>spring-boot-starter-web</artifactId>
                </exclusion>
            </exclusions>
        </dependency>


        <dependency>
            <groupId>org.apache.commons</groupId>
            <artifactId>commons-lang3</artifactId>
            <version>3.5</version>
        </dependency>

    </dependencies>




</project>
```

![](https://tcs.teambition.net/storage/31211c96abfc0805df51d1c3069ccff9f34c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY2NSwiaWF0IjoxNjExODQzODY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExYzk2YWJmYzA4MDVkZjUxZDFjMzA2OWNjZmY5ZjM0YyJ9.lSVquvpY8cgSn8spYg0NVgRmQRC9l2NStXtGGhjS6q0&download=image.png "")

```java
package com.imooc.springcloud;

import com.imooc.springcloud.AuthResponse;
import com.imooc.springcloud.AuthService;
import lombok.extern.slf4j.Slf4j;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cloud.gateway.filter.GatewayFilter;
import org.springframework.cloud.gateway.filter.GatewayFilterChain;
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

    @Autowired
    private AuthService authService;

    @Override
    public Mono<Void> filter(ServerWebExchange exchange, GatewayFilterChain chain) {
        log.info("Auth start");
        ServerHttpRequest request = exchange.getRequest();
        HttpHeaders header = request.getHeaders();
        String token = header.getFirst(AUTH);
        String username = header.getFirst(USERNAME);

        ServerHttpResponse response = exchange.getResponse();
        if (StringUtils.isBlank(token)) {
            log.error("token not found");
            // 没有验证
            response.setStatusCode(HttpStatus.UNAUTHORIZED);
            // 整个 response 结束
            return response.setComplete();
        }

        AuthResponse resp = authService.verify(token, username);
        if (resp.getCode() != 1L) {
            log.error("invalid token");
            // 没有权限
            response.setStatusCode(HttpStatus.FORBIDDEN);
            return response.setComplete();
        }

        // TODO 将用户信息存放在请求header中传递给下游业务
        ServerHttpRequest.Builder mutate = request.mutate(); // 中途构建request
        mutate.header("imooc-user-name", username);
        ServerHttpRequest buildReuqest = mutate.build();

        //todo 如果响应中需要放数据，也可以放在response的header中
        response.setStatusCode(HttpStatus.OK);
        response.getHeaders().add("imooc-username",username);
        return chain.filter(exchange.mutate() // 构建新的 请求 响应 传递给 下一个过滤器
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

![](https://tcs.teambition.net/storage/312164a1a67f4ecb3fb1164fb48cdc4ae34f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY2NSwiaWF0IjoxNjExODQzODY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2NGExYTY3ZjRlY2IzZmIxMTY0ZmI0OGNkYzRhZTM0ZiJ9.ScbcgbCAqXzVYhdYoFnlb7rQ4bC-bjDrdnSJlWdH3rY&download=image.png "")

```java
package com.imooc.springcloud;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cloud.gateway.route.RouteLocator;
import org.springframework.cloud.gateway.route.builder.RouteLocatorBuilder;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.core.annotation.Order;
import org.springframework.http.HttpMethod;

import java.time.ZonedDateTime;

@Configuration
public class GatewayConfiguration {


    @Autowired
    private TimerFilter timerFilter;


    @Autowired
    private AuthFilter authFilter;

    /**
     * RouteLocator 地址定位
     * Bean 注解 会作为初始化的一部分 自然有一个在当前上下文中已经初始化好的 builder 传给你
     * Order 默认加载顺序为 2147483647
     */
    @Bean
    @Order
    public RouteLocator customizedRoutes(RouteLocatorBuilder builder) {
        return builder.routes()
                // 每一个 route 相当于 yml 配置的 element
                .route(r -> r.path("/java/**")
                        .and().method(HttpMethod.GET)
                        .and().header("name")
                        .filters(f -> f.stripPrefix(1)
                                .addResponseHeader("java-param", "gateway-config")
                                /**
                                 * 添加自定义 filter
                                 */
                                .filter(timerFilter)
//                                .filter(timerFilter)
                                .filter(authFilter)
                        )
                        .uri("lb://FEIGN-CLIENT")
                )
                .route(r -> r.path("/seckill/**")
                                .and()
                                /**
                                 * 告诉 Gateway 当前的这个路由规则 只在某个时间点以后生效
                                 * now 也就是当前的时间点
                                 * 它是说 当你服务启动加载完成以后 往后推迟一分钟生效
                                 * 也就是 一分钟后才生效的秒杀场景
                                 * before 是说在某个时间点以前 路由规则才生效 过了这个时间点就生效
                                 * between 这个路由规则 会在这两个时间段生效
                                 */
                                .after(ZonedDateTime.now().plusMinutes(1))
//                        .and().before()
//                        .and().between()
                                .filters(f -> f.stripPrefix(1))
                                .uri("lb://FEIGN-CLIENT")
                )
                // 把当前 builder 所有的属性全部组装最终返回一个完整的 RouteLocator 对象
                .build();

    }

}

```

启动

![](https://tcs.teambition.net/storage/31213d5edf0ce432783c35c793b0fba80db1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY2NSwiaWF0IjoxNjExODQzODY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzZDVlZGYwY2U0MzI3ODNjMzVjNzkzYjBmYmE4MGRiMSJ9.H30uQY5RV14tP7AUIQxk7AqVirq9hMZqwFm2x279Zng&download=image.png "")

![](https://tcs.teambition.net/storage/31210bb52ccdaf229f9e9f66c8f0f3747526?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY2NSwiaWF0IjoxNjExODQzODY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwYmI1MmNjZGFmMjI5ZjllOWY2NmM4ZjBmMzc0NzUyNiJ9.OhWkjC6Awz4YEt_is1AnWKvGPYZ1ZKP7AXFDz7d7cnU&download=image.png "")

![](https://tcs.teambition.net/storage/3121a1b3b834d86872e8ca2f7e66fb56c901?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY2NSwiaWF0IjoxNjExODQzODY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhMWIzYjgzNGQ4Njg3MmU4Y2EyZjdlNjZmYjU2YzkwMSJ9.oZlHao5OWlQHtQ5XIA1Di1919xnJo0mB1S9CKhNY-f0&download=image.png "")

![](https://tcs.teambition.net/storage/3121e778d71d80785bd9c7603238b0e829ba?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY2NSwiaWF0IjoxNjExODQzODY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlNzc4ZDcxZDgwNzg1YmQ5Yzc2MDMyMzhiMGU4MjliYSJ9.tj319XfZNsv-OpqUy_dAFyRHS_-BCvd-LSa2vcsEBEs&download=image.png "")

![](https://tcs.teambition.net/storage/31211a0fe41882a0a441f85b92a2c7c35608?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY2NSwiaWF0IjoxNjExODQzODY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExYTBmZTQxODgyYTBhNDQxZjg1YjkyYTJjN2MzNTYwOCJ9.EJOWNwj7rFDTFC4WmC5P-YWIByJArXoDpr_fspquW40&download=image.png "")

![](https://tcs.teambition.net/storage/3121069be96f7385142ab7bd0b776ded6286?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY2NSwiaWF0IjoxNjExODQzODY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwNjliZTk2ZjczODUxNDJhYjdiZDBiNzc2ZGVkNjI4NiJ9.6Veyx_7Or4yHoBcxAFGv_LzuCuEEDZLIP5_VOMLrFa0&download=image.png "")

![](https://tcs.teambition.net/storage/312194f65ee44ecbd86667006d55a571a0b9?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY2NSwiaWF0IjoxNjExODQzODY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5NGY2NWVlNDRlY2JkODY2NjcwMDZkNTVhNTcxYTBiOSJ9.1djvJGNSAGslnS3otlaajHF2_DPMPiB0MLrKWOZq7hk&download=image.png "")

![](https://tcs.teambition.net/storage/312124623c26582d74fdb90d1f40d16448c1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY2NSwiaWF0IjoxNjExODQzODY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyNDYyM2MyNjU4MmQ3NGZkYjkwZDFmNDBkMTY0NDhjMSJ9.Zf798gsn9D6LnbktuRYWNE1dGuyT-ITeECjCK6D8FsI&download=image.png "")

![](https://tcs.teambition.net/storage/31210c98272c5bdd53798ea1f54f129af9f6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY2NSwiaWF0IjoxNjExODQzODY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwYzk4MjcyYzViZGQ1Mzc5OGVhMWY1NGYxMjlhZjlmNiJ9.iYU2jpY9gak4dOwu2iBfiIGp68oymepOnYYyYo8YgHw&download=image.png "")

![](https://tcs.teambition.net/storage/3121a675c82de615f35a78a6805d3698491a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY2NSwiaWF0IjoxNjExODQzODY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhNjc1YzgyZGU2MTVmMzVhNzhhNjgwNWQzNjk4NDkxYSJ9.U5nb2sCQaamrNiGKP4zxTWUeeVhvBKffW3a6F5CZR5Q&download=image.png "")



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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY2NSwiaWF0IjoxNjExODQzODY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.EeGP3E7wZ_hdQMqlsYmmu2ZdqVT4J0JjQKlsZugaHYg&download=image.png "")

