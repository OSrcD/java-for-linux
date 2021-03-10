package com.imooc.aop.demo3;


import org.springframework.aop.AfterReturningAdvice;
import org.springframework.aop.MethodBeforeAdvice;


import java.lang.reflect.Method;

public class MyBeforeAdvice implements MethodBeforeAdvice {

    @Override
    public void before(Method method,Object[] args,Object target) throws Throwable{
        System.out.println("前置通知============================");
    }


}
