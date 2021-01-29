package com.imooc.auth.service.pojo;

import lombok.AllArgsConstructor;
import lombok.Getter;


@AllArgsConstructor
public enum AuthCode {

    SUCCESS(1L),
    USER_NOT_FOUND(1000L),
    INVALID_CREDENTIAL(2000L);

    @Getter
    private Long code;

}
