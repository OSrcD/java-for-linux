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
    private boolean skipVerification = false;

}
