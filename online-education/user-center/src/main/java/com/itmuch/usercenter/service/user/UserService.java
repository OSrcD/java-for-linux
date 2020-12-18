package com.itmuch.usercenter.service.user;

import com.itmuch.usercenter.dao.bonus.BonusEventLogMapper;
import com.itmuch.usercenter.dao.user.UserMapper;
import com.itmuch.usercenter.domain.entity.bonus.BonusEventLog;
import com.itmuch.usercenter.domain.entity.dto.messaging.UserAddBonusMsgDTO;
import com.itmuch.usercenter.domain.entity.dto.messaging.user.UserLoginDTO;
import com.itmuch.usercenter.domain.entity.user.User;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.Date;

@Slf4j
@Service
@RequiredArgsConstructor(onConstructor = @__(@Autowired))
public class UserService {
    private final UserMapper userMapper;
    private final BonusEventLogMapper bonusEventLogMapper;

    public User findById(Integer id){
        //select * from where id = #{id}
        return this.userMapper.selectByPrimaryKey(id);
    }

    @Transactional(rollbackFor = Exception.class)
    public void addBonus(UserAddBonusMsgDTO msgDTO){
        // 1.为用户添加积分
        Integer userId = msgDTO.getUserId();
        Integer bonus = msgDTO.getBonus();

        User user = this.userMapper.selectByPrimaryKey(userId);

        user.setBonus(user.getBonus() + bonus);

        this.userMapper.updateByPrimaryKeySelective(user);

        // 2. 记录日志到bonus_event_log表里
        this.bonusEventLogMapper.insert(
                BonusEventLog.builder()
                        .userId(userId)
                        .value(bonus)
                        .event(msgDTO.getEvent())
                        .createTime(new Date())
                        .description(msgDTO.getDescription())
                        .build()
        );
        log.info("积分添加完毕...");
    }

    public User login(UserLoginDTO loginDTO, String openId){

        User user = this.userMapper.selectOne(
                User.builder()
                        .wxId(openId)
                        .build()
        );

        if(user == null){
            //插入一个用户
            User userToSave = User.builder()
                    .wxId(openId)
                    .bonus(300)
                    .wxNickname(loginDTO.getWxNickname())
                    .avatarUrl(loginDTO.getAvatarUrl())
                    .roles("user")
                    .createTime(new Date())
                    .updateTime(new Date())

                    .build();
             this.userMapper.insertSelective(userToSave);

             return userToSave;
        }

        return user;

    }

}
