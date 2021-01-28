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
