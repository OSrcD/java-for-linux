package com.itmuch.contentcenter.feignclient.fallbackfactory;

import com.itmuch.contentcenter.domain.dto.user.UserAddBonusDTO;
import com.itmuch.contentcenter.domain.dto.user.UserDTO;
import com.itmuch.contentcenter.feignclient.UserCenterFeignClient;
import feign.hystrix.FallbackFactory;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Component;

@Component
@Slf4j
public class UserCenterFeignClientFallbackFactory implements FallbackFactory<UserCenterFeignClient> {
    @Override
    public UserCenterFeignClient create(Throwable throwable) {
        return new UserCenterFeignClient() {

            @Override
            public UserDTO findById(Integer id) {
                log.warn("远程调用被限流/降级了",throwable);
                UserDTO userDTO = new UserDTO();
                userDTO.setWxNickname("一个默认用户");
                return userDTO;
            }

            @Override
            public UserDTO addBonus(UserAddBonusDTO userAddBonusDTO) {
                log.warn("远程调用被限流/降级了",throwable);
                return null;
            }
        };
    }
}
