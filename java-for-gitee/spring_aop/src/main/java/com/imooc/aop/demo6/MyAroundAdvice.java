package com.imooc.aop.demo6;

import org.aopalliance.intercept.MethodInterceptor;
import org.aopalliance.intercept.MethodInvocation;

public class MyAroundAdvice implements MethodInterceptor {
    public Object invoke(MethodInvocation Invocation) throws Throwable {
        System.out.println("环绕前增强");

        Object obj = Invocation.proceed();

        System.out.println("环绕后增强");
        return obj;
    }
}
