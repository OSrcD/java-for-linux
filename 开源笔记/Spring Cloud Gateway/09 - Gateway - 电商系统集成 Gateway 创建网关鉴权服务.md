![](https://tcs.teambition.net/storage/31220873d1edaac11138f7edaf2a0f2e6ee3?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM0MCwiaWF0IjoxNjEyMTkwNTQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIwODczZDFlZGFhYzExMTM4ZjdlZGFmMmEwZjJlNmVlMyJ9.EYh8GXE9Wa0LnLDBYn1Rwqk-QqD0a5xRlFx6jcAlw6Q&download=image.png "")

![](https://tcs.teambition.net/storage/3122347538e573a871b831d5e2ae92503e64?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM0MCwiaWF0IjoxNjEyMTkwNTQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzNDc1MzhlNTczYTg3MWI4MzFkNWUyYWU5MjUwM2U2NCJ9.vFzyiXsR7b7knGFv2xkcp_4bdCT5V1FQYBKKl8llrts&download=image.png "")

![](https://tcs.teambition.net/storage/31220c2bfe25cce1d23da58fbf73690f5fcf?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM0MCwiaWF0IjoxNjEyMTkwNTQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIwYzJiZmUyNWNjZTFkMjNkYTU4ZmJmNzM2OTBmNWZjZiJ9.vaUDEztsyMZSRPtNSochhr4N4ojjBmderJsu3QL0eG8&download=image.png "")

![](https://tcs.teambition.net/storage/31229b602474b700064790c0e17e4f577b46?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM0MCwiaWF0IjoxNjEyMTkwNTQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5YjYwMjQ3NGI3MDAwNjQ3OTBjMGUxN2U0ZjU3N2I0NiJ9.UOZTcbjy5ugsI3Go1gthNDK0B5RYJQmV7tNT5QbVJfw&download=image.png "")

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

    <artifactId>foodie-auth-api</artifactId>

    <dependencies>
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-web</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-openfeign</artifactId>
        </dependency>
    </dependencies>

</project>
```

![](https://tcs.teambition.net/storage/31228fab867449cd87bb9d00c5554e54ccc2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM0MCwiaWF0IjoxNjEyMTkwNTQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI4ZmFiODY3NDQ5Y2Q4N2JiOWQwMGM1NTU0ZTU0Y2NjMiJ9.s-ncAU-jqPc5pVsB5LX9A0DfmO3Md27gMoAzIRSIBHg&download=image.png "")

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

}

```

![](https://tcs.teambition.net/storage/3122ec01b8dbb615ee15f65e0226125ea2b5?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM0MCwiaWF0IjoxNjEyMTkwNTQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJlYzAxYjhkYmI2MTVlZTE1ZjY1ZTAyMjYxMjVlYTJiNSJ9.2dyjJzYvlvjKKeAhWqWq1QafcthnsFK_d74QD6kkOpo&download=image.png "")

```java
package com.imooc.auth.service.pojo;

import lombok.AllArgsConstructor;
import lombok.Getter;


@AllArgsConstructor
public enum AuthCode {

    SUCCESS(1L),
    USER_NOT_FOUND(1000L),
    INVALID_CREDENTIAL(2000L);

    @Getter
    private Long code;

}

```

![](https://tcs.teambition.net/storage/312256cf2e4a3ff181c7d8172817eb11b4f2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM0MCwiaWF0IjoxNjEyMTkwNTQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI1NmNmMmU0YTNmZjE4MWM3ZDgxNzI4MTdlYjExYjRmMiJ9.aTQzhfQ-GmD9bvXBQktKHO5mbjo0F98JynSkahcEeKc&download=image.png "")

```java
package com.imooc.auth.service.pojo;

import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;


@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
public class AuthResponse {

    private Account account;

    private Long code;

}

```

![](https://tcs.teambition.net/storage/3122cec5f86f7ffcd5c5dbfab0539e9864ed?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM0MCwiaWF0IjoxNjEyMTkwNTQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJjZWM1Zjg2ZjdmZmNkNWM1ZGJmYWIwNTM5ZTk4NjRlZCJ9.7T2iwYajXk2dhKmHsOYnN1BBkOJ8Ynk7NF2bTnIW8hA&download=image.png "")

```java
package com.imooc.auth.service;

import com.imooc.auth.service.pojo.Account;
import com.imooc.auth.service.pojo.AuthResponse;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.*;


@FeignClient("foodie-auth-service")
@RequestMapping("auth-service")
public interface AuthService {

    @PostMapping("token")
    public AuthResponse tokenize(@RequestParam("userId") String userId);

    @PostMapping("verify")
    public AuthResponse verify(@RequestBody Account account);

    @PostMapping("refresh")
    public AuthResponse refresh(@RequestParam("refresh") String refresh);

    @DeleteMapping("delete")
    public AuthResponse delete(@RequestBody Account account);

}

```

![](https://tcs.teambition.net/storage/31228e475b232f85ab4e93ae45211b52d930?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM0MCwiaWF0IjoxNjEyMTkwNTQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI4ZTQ3NWIyMzJmODVhYjRlOTNhZTQ1MjExYjUyZDkzMCJ9.ZXR8CqSzAzX0UHzUmL-PBeXNjEcM2WwHUClgmIZTvHM&download=image.png "")

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

    <artifactId>foodie-auth-service</artifactId>

    <dependencies>
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-web</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-client</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-actuator</artifactId>
        </dependency>

        <!-- redis -->
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-data-redis</artifactId>
        </dependency>

        <!-- jwt -->
        <dependency>
            <groupId>com.auth0</groupId>
            <artifactId>java-jwt</artifactId>
            <version>3.7.0</version>
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
                    <mainClass>com.imooc.auth.AuthApplication</mainClass>
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

![](https://tcs.teambition.net/storage/312234f5a789d8fd5be6a7d4c388d78bbfa8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM0MCwiaWF0IjoxNjEyMTkwNTQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzNGY1YTc4OWQ4ZmQ1YmU2YTdkNGMzODhkNzhiYmZhOCJ9.bVEbVT2itPKFl3neh60KpTK2__l911S2_fL18V43LeQ&download=image.png "")

```java
package com.imooc.auth.service.impl;

import com.imooc.auth.service.AuthService;
import com.imooc.auth.service.pojo.Account;
import com.imooc.auth.service.pojo.AuthResponse;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

import java.util.UUID;

import static com.imooc.auth.service.pojo.AuthCode.SUCCESS;
import static com.imooc.auth.service.pojo.AuthCode.USER_NOT_FOUND;


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
                .code(SUCCESS.getCode())
                .build();
    }

    @Override
    public AuthResponse verify(Account account) {
        boolean success = jwtService.verify(account.getToken(), account.getUserId());
        return AuthResponse.builder()
                // TODO 此处最好用invalid token之类的错误信息
                .code(success ? SUCCESS.getCode() : USER_NOT_FOUND.getCode())
                .build();
    }

    // 有很多种方法实现自动刷新，比如前端主动调用（可以在AuthResponse里将过期时间返回给前端口）
    @Override
    public AuthResponse refresh(String refreshToken) {
        String userId = (String) redisTemplate.opsForValue().get(refreshToken);
        if (StringUtils.isBlank(userId)) {
            return AuthResponse.builder()
                    .code(USER_NOT_FOUND.getCode())
                    .build();
        }

        redisTemplate.delete(refreshToken);
        return tokenize(userId);
    }

    @Override
    public AuthResponse delete(@RequestBody Account account) {
        AuthResponse token = verify(account);
        AuthResponse resp = new AuthResponse();
        if (SUCCESS.getCode().equals(token.getCode())) {
            redisTemplate.delete(USER_TOKEN + account.getUserId());
            redisTemplate.delete(account.getRefreshToken());
            resp.setCode(SUCCESS.getCode());
        } else {
            resp.setCode(USER_NOT_FOUND.getCode());
        }
        return resp;
    }
}

```

![](https://tcs.teambition.net/storage/3122dad4d6a0d16e9e5428c073f22b6ee2a2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM0MCwiaWF0IjoxNjEyMTkwNTQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkYWQ0ZDZhMGQxNmU5ZTU0MjhjMDczZjIyYjZlZTJhMiJ9.OC1qYICppB9VvY1uLoA8OH3Sbr1suYI9fw84Cq0QEiU&download=image.png "")

```java
package com.imooc.auth.service.impl;

import com.auth0.jwt.JWT;
import com.auth0.jwt.algorithms.Algorithm;
import com.auth0.jwt.interfaces.JWTVerifier;
import com.imooc.auth.service.pojo.Account;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Service;

import java.util.Date;


@Slf4j
@Service
public class JwtService {

    // 生产环境不能这么用
    private static final String KEY = "changeIt";
    private static final String ISSUER = "yao";

    private static final long TOKEN_EXP_TIME = 24 * 3600 * 1000;
    private static final String USER_ID = "userid";

    /**
     * 生成Token
     *
     * @param acct
     * @return
     */
    public String token(Account acct) {
        Date now = new Date();
        // 这里提供了很多种加密算法，生产环境可以用更高等级的加密算法，比如
        // 【最常用】采用非对称密钥加密，auth-service只负责生成jwt-token
        //  由各个业务方（或网关层）在自己的代码里用key校验token的正确性
        //  优点：符合规范，并且节约了一次HTTP Call
        //
        //  咱这里用了简单的token生成方式，同学们可以试着把上面的场景在本地实现
        Algorithm algorithm = Algorithm.HMAC256(KEY); // 密钥 + 散列函数做加密的

        String token = JWT.create()
                .withIssuer(ISSUER)
                .withIssuedAt(now)
                .withExpiresAt(new Date(now.getTime() + TOKEN_EXP_TIME))
                .withClaim(USER_ID, acct.getUserId())
//                .withClaim("ROLE", "")
                .sign(algorithm);

        log.info("jwt generated, userId={}", acct.getUserId());
        return token;
    }

    /**
     * 校验Token
     *
     * @param token
     * @param userId
     * @return
     */
    public boolean verify(String token, String userId) {
        log.info("verifying jwt - username={}", userId);

        try {
            Algorithm algorithm = Algorithm.HMAC256(KEY);
            JWTVerifier verifier = JWT.require(algorithm)
                    .withIssuer(ISSUER)
                    .withClaim(USER_ID, userId)
                    .build();

            verifier.verify(token);
            return true;
        } catch (Exception e) {
            log.error("auth failed, userId={}", userId);
            return false;
        }
    }

}

```

![](https://tcs.teambition.net/storage/31226920cab7b2c6a5c75b417378aa9e5d6c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM0MCwiaWF0IjoxNjEyMTkwNTQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI2OTIwY2FiN2IyYzZhNWM3NWI0MTczNzhhYTllNWQ2YyJ9.-WOOYudCg4UR4YYW04o8PghaBDGRkQxbMkYkaIerS4c&download=image.png "")

```java
package com.imooc.auth;

import org.springframework.boot.WebApplicationType;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.builder.SpringApplicationBuilder;
import org.springframework.cloud.netflix.eureka.EnableEurekaClient;

@SpringBootApplication
@EnableEurekaClient
public class AuthApplication {

    // 这里提供了很多种加密算法，生产环境可以用更高等级的加密算法，比如
    // 【最常用】采用非对称密钥加密，auth-service只负责生成jwt-token
    //  由各个业务方（或网关层）在自己的代码里用key校验token的正确性
    //  优点：符合规范，并且节约了一次HTTP Call
    //
    //  咱这里用了简单的token生成方式，同学们可以试着把上面的场景在本地实现
    public static void main(String[] args) {
        new SpringApplicationBuilder(AuthApplication.class)
                .web(WebApplicationType.SERVLET)
                .run(args);
    }
}

```

![](https://tcs.teambition.net/storage/3122a789472217fe7d1abb2bf2fe5767ce65?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM0MCwiaWF0IjoxNjEyMTkwNTQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhNzg5NDcyMjE3ZmU3ZDFhYmIyYmYyZmU1NzY3Y2U2NSJ9.GVpG-F2L20Dc7z4XEGZXWCzUfbCwzUcWo3zAxy_NMl8&download=image.png "")

```yaml
server:
  port: 10006

spring:
  application:
    name: foodie-auth-service
  redis:
    database: 0
    host: 192.168.245.138
    port: 6379
    password: imooc

eureka:
  client:
    serviceUrl:
      defaultZone: http://localhost:20000/eureka/

management:
  endpoint:
    health:
      show-details: always
  endpoints:
    web:
      exposure:
        include: '*'
  security:
    user:
      name: gitee
      password: gitee
      roles: ADMIN

```

![](https://tcs.teambition.net/storage/3122656713a022cad8bafdd6ba2ee839503d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM0MCwiaWF0IjoxNjEyMTkwNTQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI2NTY3MTNhMDIyY2FkOGJhZmRkNmJhMmVlODM5NTAzZCJ9.D8Xo3lT8Zmf-oKpWbaGyP8UodOPy8fx2wJ6HRsF8g4Y&download=image.png "")

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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM0MCwiaWF0IjoxNjEyMTkwNTQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.0DTOC_YZnBmqVS0hZ7b5Gsy9angWAAKlkWrj56qMoXA&download=image.png "")

