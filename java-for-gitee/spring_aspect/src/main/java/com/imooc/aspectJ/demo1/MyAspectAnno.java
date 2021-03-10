package com.imooc.aspectJ.demo1;


import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.*;

@Aspect
public class MyAspectAnno {
        @Before(value="myPointcut()")
        public void before(JoinPoint joinPoint)
        {
            System.out.println("前置通知==============="+joinPoint);

        }

        @AfterReturning(value ="myPointcut2()",returning = "result")
        public  void afterReturing(Object result){
            System.out.println("后置通知==============="+result);
        }

        @Around(value = "myPointcut3()")
        public Object around(ProceedingJoinPoint joinPoint) throws Throwable {
            System.out.println("环绕前通知==============");
            Object obj = joinPoint.proceed();
            System.out.println("环绕后通知==============");
            return obj;
        }


        @AfterThrowing(value = "myPointcut4()",throwing = "e")
        public  void afterThrowing(Throwable e){
            System.out.println("异常抛出通知================="+e.getMessage());

        }

        @After(value="myPointcut5()")
        public void after(){
            System.out.println("最终通知============");
        }


        @Pointcut(value = "execution(* com.imooc.aspectJ.demo1.ProductDao.save(..))")
        private void myPointcut(){}


        @Pointcut(value = "execution(* com.imooc.aspectJ.demo1.ProductDao.update(..))")
        private void myPointcut2(){}

        @Pointcut(value = "execution(* com.imooc.aspectJ.demo1.ProductDao.delete(..))")
        private void myPointcut3(){}


        @Pointcut(value = "execution(* com.imooc.aspectJ.demo1.ProductDao.findOne(..))")
        private void myPointcut4(){}

        @Pointcut(value = "execution(* com.imooc.aspectJ.demo1.ProductDao.findAll(..))")
        private void myPointcut5(){}

}
