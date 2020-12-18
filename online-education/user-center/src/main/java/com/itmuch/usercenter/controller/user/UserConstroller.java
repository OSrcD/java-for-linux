package com.itmuch.usercenter.controller.user;


import cn.binarywang.wx.miniapp.api.WxMaService;
import cn.binarywang.wx.miniapp.bean.WxMaJscode2SessionResult;
import com.itmuch.usercenter.auth.CheckLogin;
import com.itmuch.usercenter.domain.entity.dto.messaging.user.JwtTokenRespDTO;
import com.itmuch.usercenter.domain.entity.dto.messaging.user.LoginRespDTO;
import com.itmuch.usercenter.domain.entity.dto.messaging.user.UserLoginDTO;
import com.itmuch.usercenter.domain.entity.dto.messaging.user.UserRespDTO;
import com.itmuch.usercenter.domain.entity.user.User;
import com.itmuch.usercenter.service.user.UserService;
import com.itmuch.usercenter.util.JwtOperator;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import me.chanjar.weixin.common.error.WxErrorException;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.HashMap;
import java.util.Map;


@RestController
@RequestMapping("/users")
@RequiredArgsConstructor(onConstructor = @__(@Autowired))
@Slf4j
public class UserConstroller {

    private final UserService userService;
    private final WxMaService wxMaService;
    private final JwtOperator jwtOperator;

    @CheckLogin
    @GetMapping("/{id}")
    public User findById(@PathVariable Integer id){
        log.info("我被请求了...");
        return this.userService.findById(id);
    }


    /**
     * 模拟生成token(假的登录)
     *
     */

    @GetMapping("/gen-token")
    public String genToken(){
        Map<String,Object> userInfo = new HashMap<>(3);

        userInfo.put("id",10);
        userInfo.put("wxNickname","开源开发则");
        userInfo.put("role","user");
        return jwtOperator.generateToken(userInfo);
    }

    @PostMapping("/login")
    public LoginRespDTO login(@RequestBody UserLoginDTO loginDTO) throws WxErrorException {
        // 微信小程序服务端校验是否已经登录的结果
        WxMaJscode2SessionResult result =this.wxMaService.getUserService()
                .getSessionInfo(loginDTO.getCode());

        // 微信的openId，用户在微信这边的唯一标识
        String openId = result.getOpenid();

        // 看用户是否注册，如果没有注册就插入
        // 如果已经注册，直接颁发token
        User user = this.userService.login(loginDTO,openId);

        Map<String,Object> userInfo = new HashMap<String,Object>(3);

        userInfo.put("id",user.getId());
        userInfo.put("wxNickname",user.getWxNickname());
        userInfo.put("role",user.getRoles());

        // 生成token
        String token = jwtOperator.generateToken(userInfo);

        // 打印用户信息
        log.info(
                "用户{}登录成功，生成的token = {},有效期到：{}",
                loginDTO.getWxNickname(),
                token,
                jwtOperator.getExpirationTime()
        );

        // 构建响应给前端
        return LoginRespDTO.builder()

                // 构建user对象
                .user(
                        UserRespDTO.builder()
                                // id
                                .id(user.getId())
                                // 头像
                                .avatarUrl(user.getAvatarUrl())
                                // 积分
                                .bonus(user.getBonus())
                                // 微信名称
                                .wxNickname(user.getWxNickname())
                                .build()
                )

                // 构建token对象
                .tokne(
                        JwtTokenRespDTO.builder()
                                .expirationTime(jwtOperator.getExpirationTime().getTime())
                                .token(token)
                                .build()
                )
                .build();



    }

}
