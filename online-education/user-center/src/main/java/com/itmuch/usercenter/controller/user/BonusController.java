package com.itmuch.usercenter.controller.user;

import com.itmuch.usercenter.domain.entity.dto.messaging.UserAddBonusMsgDTO;
import com.itmuch.usercenter.domain.entity.dto.messaging.user.UserAddBonusDTO;
import com.itmuch.usercenter.domain.entity.user.User;
import com.itmuch.usercenter.service.user.UserService;
import lombok.RequiredArgsConstructor;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/users")
@RequiredArgsConstructor(onConstructor = @__(@Autowired))
public class BonusController {
    private final UserService userService;

    /**
     *
     * @param userAddBonusDTO 方便content-center传来构造UserAddBonusMsgDTO对象
     * @return 用户
     */
    @PutMapping("/add-bonus")
    public User addBonus(@RequestBody UserAddBonusDTO userAddBonusDTO){
        Integer userId = userAddBonusDTO.getUserId();
        // 调用分布式事务的addBonus添加积分方法
        userService.addBonus(
                UserAddBonusMsgDTO
                        .builder()
                        .userId(userId)
                        .bonus(userAddBonusDTO.getBonus())
                        .description("兑换分享...")
                        .event("BUY")
                        .build()
        );

        return this.userService.findById(userId);
    }
}
