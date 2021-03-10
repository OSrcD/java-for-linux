package com.imooc.aspectJ.demo2;

import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.ProceedingJoinPoint;

public class MyAspectXml {



    //前置通知
    public void before(JoinPoint joinPoint){
        System.out.println("XML方式的前置通知================"+joinPoint);
    }


    public  void afterReturing(Object result){
        System.out.println("xml方式的后置通知======="+result);
    }


    public Object  around(ProceedingJoinPoint joinPoint) throws Throwable{
        System.out.println("xml方式的环绕前通知======="+joinPoint);
        Object obj = joinPoint.proceed();
        System.out.println("xml方式的环绕后通知======="+joinPoint);
        return obj;

    }

    public void afterThrowing(Throwable e){
        System.out.println("XML方式的异常抛出通知============"+e.getMessage());
    }


    public void after(){
        System.out.println("XML方式的最终通知==========");
    }

}
