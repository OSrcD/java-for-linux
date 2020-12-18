package com.itmuch.usercenter.domain.entity.dto.messaging.user;

import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

@Builder
@NoArgsConstructor
@AllArgsConstructor
@Data
public class UserRespDTO {
    /**
     * id
     */
    private Integer id;

    /**
     * 头像地址
     */
    private String avatarUrl;

    /**
     * 积分
     */
    private Integer bonus;

    /**
     * 微信昵称
     */
    private String wxNickname;
}
