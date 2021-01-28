![](https://tcs.teambition.net/storage/3121d7bc2e0899cd530218489cfeba42b8d1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY1NCwiaWF0IjoxNjExODQzODU0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkN2JjMmUwODk5Y2Q1MzAyMTg0ODljZmViYTQyYjhkMSJ9.A1bWdUPKoz_TeT5AF6ZZQztxQ5Pq-au458eNwWLgiEc&download=2020-09-17%20060810.png "")

Token 可以理解为打开自己应用的钥匙

 

![](https://tcs.teambition.net/storage/3121d6826bc0ae5ab5038a08f144da32584e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY1NCwiaWF0IjoxNjExODQzODU0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkNjgyNmJjMGFlNWFiNTAzOGEwOGYxNDRkYTMyNTg0ZSJ9.PjyO7S40ooaJr3DFPmHkENMcMi1VleL6WAK-3UWbguQ&download=image.png "")

![](https://tcs.teambition.net/storage/3121bbd57a5d22d0a96b15656519096714c7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY1NCwiaWF0IjoxNjExODQzODU0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiYmQ1N2E1ZDIyZDBhOTZiMTU2NTY1MTkwOTY3MTRjNyJ9.lLUtKNlezTJamLUnw81p4SvhQC4Jp1ZnGXqSqtsfyv0&download=image.png "")

![](https://tcs.teambition.net/storage/3121da60ef17e2feb9c17b88a529cb09ecdc?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY1NCwiaWF0IjoxNjExODQzODU0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkYTYwZWYxN2UyZmViOWMxN2I4OGE1MjljYjA5ZWNkYyJ9.0P8X_dDPqng6N1KjUffredenl3iDJAyKSgTIkdSRsCU&download=image.png "")

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
    <artifactId>auth-service-api</artifactId>

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

![](https://tcs.teambition.net/storage/3121d25ed3a133b2f53a7a02c4333400d1b8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY1NCwiaWF0IjoxNjExODQzODU0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkMjVlZDNhMTMzYjJmNTNhN2EwMmM0MzMzNDAwZDFiOCJ9.wQYY_mZYbgRofOmkT9BxgxZkVi0J17UD16KB-JRkoU8&download=image.png "")

```java
package com.imooc.springcloud;

import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
public class Account {

    private String username;

    // 生成的访问密钥
    private String token;

    // 通过 refreshToken 生成新的 token
    private String refreshToken;
}

```

![](https://tcs.teambition.net/storage/3121614fe52430be86ac00aa63ad7e234019?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY1NCwiaWF0IjoxNjExODQzODU0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2MTRmZTUyNDMwYmU4NmFjMDBhYTYzYWQ3ZTIzNDAxOSJ9.StduYfmhCpAvqUGoGGEj5aPx2bzwi-prEAUt5zX_COo&download=image.png "")

```java
package com.imooc.springcloud;


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

![](https://tcs.teambition.net/storage/3121fa512962a8a42a71a3f77c265c38b4ad?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY1NCwiaWF0IjoxNjExODQzODU0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmYTUxMjk2MmE4YTQyYTcxYTNmNzdjMjY1YzM4YjRhZCJ9.w_mfvFYn1pAIov9AsRfIvZ6VU4As3Vtbj3RqRtMcO3k&download=image.png "")

```java
package com.imooc.springcloud;

import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

@FeignClient("auth-service")
public interface AuthService {

    @PostMapping("/login")
    @ResponseBody
    public AuthResponse login(@RequestParam("username") String username,
                              @RequestParam("password") String password);


    @GetMapping("/verify")
    public AuthResponse verify(@RequestParam("token") String token,
                               @RequestParam("username") String username);


    /**
     * 当你token在签发的时候 会给你一个有效期 比如说 2 3 天
     * 过期了就不能再使用了 不想重新登录 就可以使用 refresh 方法
     * 可以理解为备用的 token
     * 通过refresh token 生成一个新的token
     */
    @PostMapping("/refresh")
    @ResponseBody
    public AuthResponse refresh(@RequestParam("refresh") String refresh);


}

```

![](https://tcs.teambition.net/storage/31215e3ba35931b6313873434e576abf8743?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY1NCwiaWF0IjoxNjExODQzODU0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1ZTNiYTM1OTMxYjYzMTM4NzM0MzRlNTc2YWJmODc0MyJ9.35qhQvx1k6cTa6koroPiiMSgy8EDvJ95RsBAVDmXwhM&download=image.png "")

![](https://tcs.teambition.net/storage/312150ba5e71f1ae13067e7ff225de764356?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY1NCwiaWF0IjoxNjExODQzODU0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1MGJhNWU3MWYxYWUxMzA2N2U3ZmYyMjVkZTc2NDM1NiJ9.2G5FTN6bOJ84HrjVttEayAE4JBao5vNYAfamWG1pf8c&download=image.png "")

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

    <artifactId>auth-service</artifactId>

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

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-data-redis</artifactId>
        </dependency>

        <dependency>
            <groupId>com.auth0</groupId>
            <artifactId>java-jwt</artifactId>
            <version>3.7.0</version>
        </dependency>

        <dependency>
            <groupId>com.imooc</groupId>
            <artifactId>auth-service-api</artifactId>
            <version>${project.version}</version>
        </dependency>


    </dependencies>

</project>

```

![](https://tcs.teambition.net/storage/3121e623adcb00a316d69a1f179b301695fc?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY1NCwiaWF0IjoxNjExODQzODU0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlNjIzYWRjYjAwYTMxNmQ2OWExZjE3OWIzMDE2OTVmYyJ9._3ASNUzzKH3lcT0CRXdTkVNc-r-QgnqyCuYewpXSdK4&download=image.png "")

```java
package com.imooc.springcloud;

import org.springframework.boot.WebApplicationType;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.builder.SpringApplicationBuilder;
import org.springframework.cloud.netflix.eureka.EnableEurekaClient;

@SpringBootApplication
// 与 @EnableDiscoveryClient 作用一致
@EnableEurekaClient
public class AuthApplication {
    public static void main(String[] args) {
        new SpringApplicationBuilder(AuthApplication.class)
                .web(WebApplicationType.SERVLET)
                .run();
    }
}

```

![](https://tcs.teambition.net/storage/31215f461ed75a40d0fcca1733148207e492?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY1NCwiaWF0IjoxNjExODQzODU0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1ZjQ2MWVkNzVhNDBkMGZjY2ExNzMzMTQ4MjA3ZTQ5MiJ9.MVLFlRrPNx3T5lIMoXtBwkcvN_fbiZCQA7ZE-eUNvOU&download=image.png "")

```java
package com.imooc.springcloud;

import com.auth0.jwt.JWT;
import com.auth0.jwt.JWTVerifier;
import com.auth0.jwt.algorithms.Algorithm;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Service;

import java.util.Date;

@Slf4j
@Service
public class JwtService {

    // 生产环境不能这么用
    private static final String KEY = "changeIt"; // 密钥
    private static final String ISSUER = "yao"; // 发行方
    // 过期时间 60 秒
    private static final long TOKEN_EXP_TIME = 60000L;
    private static final String USER_NAME = "username";

    /**
     * 创建 token
     */
    public String token(Account acct) {
        Date now = new Date();

        // 定义一个算法 生成 token 需要用到
        Algorithm algorithm = Algorithm.HMAC256(KEY); // KEY 为 密钥

        /**
         * 开始创建 token
         * issuer 发行方
         */
        String token = JWT.create()
                // 就算被黑客获取了 密钥 依然不能破解 算法 因为不知道 ISSUER 是谁
                .withIssuer(ISSUER)
                // 这个 key 是在什么时间点生成的
                .withIssuedAt(now)
                // 过期时间 当前时间 + 过期时间
                .withExpiresAt(new Date(now.getTime() + TOKEN_EXP_TIME))
                // 添加自定义属性 传入用户名
                .withClaim(USER_NAME, acct.getUsername())
//                .withClaim("ROLE","")
                // 使用算法签发 一个 token
                .sign(algorithm);
        log.info("jwt generated user = {}",acct.getUsername());
        return token;
    }



    /**
     * 验证 token
     */
    public boolean verify(String token,String username) {
        log.info("verifying jwt username={}",username);

        try {
            Algorithm algorithm = Algorithm.HMAC256(KEY);

            /**
             * 验证 jwt 内容
             * JWT.require() 生成一个验证器 需要一个算法 怎么加解密
             */
            JWTVerifier verifier = JWT.require(algorithm)
                    // 验证发行人
                    .withIssuer(ISSUER)
                    // 验证自定义属性
                    .withClaim(USER_NAME, username)
                    .build();

            // 开始验证
            verifier.verify(token);
            return true;
        } catch (Exception e) {
            log.error("auth failed", e);
            return false;
        }

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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODY1NCwiaWF0IjoxNjExODQzODU0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.6v5DZY0KzSTarTh9ztDTUp6L49OH6HlbeI1eyIdbwdU&download=image.png "")

