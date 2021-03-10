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
