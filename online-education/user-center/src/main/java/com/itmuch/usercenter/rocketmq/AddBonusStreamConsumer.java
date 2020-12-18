package com.itmuch.usercenter.rocketmq;

import com.itmuch.usercenter.domain.entity.dto.messaging.UserAddBonusMsgDTO;
import com.itmuch.usercenter.service.user.UserService;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cloud.stream.annotation.StreamListener;
import org.springframework.cloud.stream.messaging.Sink;
import org.springframework.stereotype.Service;

@Service
@RequiredArgsConstructor(onConstructor = @__(@Autowired))
@Slf4j
public class AddBonusStreamConsumer {
    private final UserService userService;


    @StreamListener(Sink.INPUT)
    public void receive(UserAddBonusMsgDTO userAddBonusMsgDTO){
        userAddBonusMsgDTO.setEvent("CONTRIBUTE");
        userAddBonusMsgDTO.setDescription("投稿加积分...");
        // 传过来的是一个json
//        UserAddBonusMsgDTO userAddBonusMsgDTO = JSON.parseObject(message, UserAddBonusMsgDTO.class);
        this.userService.addBonus(userAddBonusMsgDTO);
    }



}
