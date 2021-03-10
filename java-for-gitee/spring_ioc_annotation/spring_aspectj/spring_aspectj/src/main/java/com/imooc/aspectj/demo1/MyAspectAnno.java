package com.imooc.aspectj.demo1;

import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.*;

@Aspect
public class MyAspectAnno {

    @Before(value="myPointcut1()")
    public void before(JoinPoint joinPoint){
        System.out.println("前置增强... " + joinPoint);
    }

    @AfterReturning(value="myPointcut2()",returning = "result")
    public void afterRetruning(Object result){
        System.out.println("后置通知.... " + result);
    }


    @Around(value="myPointcut3()")
    public Object around(ProceedingJoinPoint proceedingJoinPoint) throws Throwable{
        System.out.println("环绕前通知============");
        Object result = proceedingJoinPoint.proceed();
        System.out.println("环绕后通知============" + result);
        return result;
    }

    @AfterThrowing(value="myPointcut4()" ,throwing="e")
    public void afterThrowing(Throwable e){
        System.out.println("异常通知");
        System.out.println(e.getMessage());
    }


    @After(value="myPointcut5()")
    public void after(){
        System.out.println("最终通知=================");
    }


    @Pointcut(value="execution(* com.imooc.aspectj.demo1.ProductDao.save(..))")
    public void myPointcut1(){}

    @Pointcut(value="execution(* com.imooc.aspectj.demo1.ProductDao.update(..))")
    public void myPointcut2(){}

    @Pointcut(value="execution(* com.imooc.aspectj.demo1.ProductDao.delete(..))")
    public void myPointcut3(){}

    @Pointcut(value="execution(* com.imooc.aspectj.demo1.ProductDao.findOne(..))")
    public void myPointcut4(){}

    @Pointcut(value="execution(* com.imooc.aspectj.demo1.ProductDao.findAll(..))")
    public void myPointcut5(){}

}
