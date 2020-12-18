package com.itmuch.usercenter.domain.entity.dto.messaging.user;

import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

@Builder
@NoArgsConstructor
@AllArgsConstructor
@Data
public class LoginRespDTO {
    /**
     * token
     */
    private JwtTokenRespDTO tokne;
    /**
     * 用户信息
     */
    private UserRespDTO user;
}
