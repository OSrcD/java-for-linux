package com.opendev.domain.vo;

import com.opendev.domain.Users;

import java.util.List;

public class UserListVO {

    private List<UserVO> userList;

    public List<UserVO> getUserList() {
        return userList;
    }

    public void setUserList(List<UserVO> userList) {
        this.userList = userList;
    }
}
