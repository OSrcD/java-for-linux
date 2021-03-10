package com.imooc.aspectj.demo2;

import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.ProceedingJoinPoint;

public class MyAspectXml {


    // 前置通知
    public void before(JoinPoint joinPoint){
        System.out.println("1.XML方式的前置通知=================\t" + joinPoint);
    }

    // 后置通知
    public void afterReturing(Object result){
        System.out.println("2.XML方式的后置通知================== " + result);
    }


    public Object around(ProceedingJoinPoint joinPoint) throws Throwable{
        System.out.println("3.XML方式的环绕前通知================");
        Object result = joinPoint.proceed();
        System.out.println("4.XML方式的环绕后通知================");
        return result;
    }

    public void afterThrowing(Throwable e){
        System.out.println("5.异常抛出通知"+e.getMessage());
    }

    public void after(){
        System.out.println("6.最终通知");
    }

}
