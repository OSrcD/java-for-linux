package com.itmuch.contentcenter.domain.dto.user;

import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
@Builder
public class UserAddBonusDTO {

    /**
     * 用户Id
     */
    private Integer userId;

    /**
     * 积分
     */
    private Integer bonus;
}
