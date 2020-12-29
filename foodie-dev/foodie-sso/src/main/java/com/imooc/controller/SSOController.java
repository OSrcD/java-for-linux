package com.imooc.controller;

import com.imooc.pojo.Users;
import com.imooc.pojo.vo.UsersVO;
import com.imooc.service.UserService;
import com.imooc.utils.JsonUtils;
import com.imooc.utils.MD5Utils;
import com.imooc.utils.RedisOperator;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;

import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.util.Random;
import java.util.UUID;

@Controller
public class SSOController {

    @Autowired
    private UserService userService;

    @Autowired
    private RedisOperator redisOperator;

    public static final String REDIS_USER_TOKEN = "redis_user_token";
    public static final String REDIS_USER_TICKET = "redis_user_ticket";
    public static final String REDIS_TMP_TICKET = "redis_tmp_ticket";

    public static final String COOKIE_USER_TICKET = "cookie_user_ticket";

    @GetMapping("/login")
    public String login(String returnUrl ,
                        Model model,
                        HttpServletRequest request,
                        HttpServletResponse response) {

        model.addAttribute("returnUrl", returnUrl);

        // TODO 后续完善校验是否登录

        // 用户从未登录过，第一次进入侧跳转到CAS的统一登录页面

        return "login";
    }

    /**
     * CAS的统一登录接口
     *      目的：
     *          1. 登录后创建用户的全局会话                    -> uniqueToken
     *          2. 创建用户全局门票，用以表示在CAS端是否登录     -> userTicket
     *          3. 创建用户的临时票据，用于回跳回传             -> tmpTicket
     */
    @PostMapping("/doLogin")
    public String doLogin(String username,
                        String password,
                        String returnUrl,
                        Model model,
                        HttpServletRequest request,
                        HttpServletResponse response) throws Exception {

        model.addAttribute("returnUrl", returnUrl);

        // 0. 判断用户名和密码必须不为空
        if(StringUtils.isBlank(username) ||
                StringUtils.isBlank(password)){
            model.addAttribute("errmsg","用户名或密码不能为空");
            return "login";
        }

        // 1. 实现登录
        Users userResult = userService.queryUserForLogin(username,
                MD5Utils.getMD5Str(password));
        if (userResult == null) {
            model.addAttribute("errmsg", "用户名或密码不正确");
            return "login";
        }

        // 2. 实现用户的redis会话
        String uniqueToken = UUID.randomUUID().toString().trim();
        UsersVO usersVO = new UsersVO();
        BeanUtils.copyProperties(userResult, usersVO);
        usersVO.setUserUniqueToken(uniqueToken);
        redisOperator.set(REDIS_USER_TOKEN + ":" + userResult.getId(),
                JsonUtils.objectToJson(usersVO));

        // 3. 生成ticket门票，全局门票，代表用户在CAS端登录过
        String userTicket = UUID.randomUUID().toString().trim();

        // 3.1 用户全局门票需要放入CAS端的cookie中
        setCookie(COOKIE_USER_TICKET,userTicket,response);

        // 4. userTicket关联用户id，并且放入redis中，代表这个用户有门票了，可以在各个景区游玩
        redisOperator.set(REDIS_USER_TICKET + ":" + userTicket,userResult.getId());

        // 5. 生成临时票据，回跳到调用端网站，是由CAS端所签发的一个一次性的临时ticket
        String tmpTicket = createTicket();

        return "login";
//        return "redirect:" + returnUrl + "?tmpTicket=" + tmpTicket;
    }

    /**
     * 创建临时票据
     * @return
     */
    private String createTicket() {
        String tmpTicket = UUID.randomUUID().toString().trim();
        try {
            redisOperator.set(REDIS_TMP_TICKET + ":" + tmpTicket,
                    MD5Utils.getMD5Str(tmpTicket),600);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return tmpTicket;
    }

    private void setCookie(String key,
                           String val,
                           HttpServletResponse response) {

        Cookie cookie = new Cookie(key,val);
        cookie.setDomain("sso.com");
        cookie.setPath("/");
        response.addCookie(cookie);

    }

}
