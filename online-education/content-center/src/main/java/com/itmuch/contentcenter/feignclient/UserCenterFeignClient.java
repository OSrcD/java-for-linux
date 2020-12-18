package com.itmuch.contentcenter.feignclient;

import com.itmuch.contentcenter.domain.dto.user.UserAddBonusDTO;
import com.itmuch.contentcenter.domain.dto.user.UserDTO;
import com.itmuch.contentcenter.feignclient.fallback.UserCenterFeignClientFallback;
import com.itmuch.contentcenter.feignclient.fallbackfactory.UserCenterFeignClientFallbackFactory;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;

//@FeignClient(name = "user-center",configuration = UserCenterFeignConfiguration.class)
@FeignClient(name = "user-center",
        //fallback= UserCenterFeignClientFallback.class
fallbackFactory = UserCenterFeignClientFallbackFactory.class)
public interface UserCenterFeignClient {

    /**
     * http://user-center/users/{id}
     * @param id
     * @return
     */

    @GetMapping("/users/{id}")
    UserDTO findById(@PathVariable Integer id);

    @PutMapping("/users/add-bonus")
    UserDTO addBonus(@RequestBody UserAddBonusDTO userAddBonusDTO);
}
