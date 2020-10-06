package com.imooc.service;

import com.imooc.pojo.Users;
import com.imooc.pojo.bo.UserBO;

public interface UserService {

    /**
     * 判断用户名是否存在
     * @param username
     * @return
     */
    public boolean queryUsernameIsExist(String username);

    /**
     * 创建用户
     * @param userBo
     * @return
     */
    public Users createUser(UserBO userBo);

    /**
     * 检索用户名和密码是否匹配，用于登录
     */

    public Users queryUserForLogin(String username,String password);
}
