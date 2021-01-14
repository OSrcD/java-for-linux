package com.imooc.springcloud;

import lombok.Data;

// 为属性生成 get set toString
@Data
public class Friend {
    private String name;
    private String port;
}
