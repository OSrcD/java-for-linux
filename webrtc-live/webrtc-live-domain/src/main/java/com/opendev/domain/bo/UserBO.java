package com.opendev.domain.bo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;

@ApiModel(value = "用户对象BO",description = "从客户端，由用户传入的数据封装在此entity中")    // value是类型
public class UserBO {
    @ApiModelProperty(value="用户名",name = "username",example="imooc",required = true) // value是说明
    private String username;
    @ApiModelProperty(value="密码",name = "password",example="123456",required = true)
    private String password;
    @ApiModelProperty(value="确认密码",name = "confirmPassword",example="123456",required = false)
    private String confirmPassword;

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getConfirmPassword() {
        return confirmPassword;
    }

    public void setConfirmPassword(String confirmPassword) {
        this.confirmPassword = confirmPassword;
    }
}
