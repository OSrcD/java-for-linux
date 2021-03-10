package com.imooc.ioc.demo3;

import org.springframework.beans.BeansException;
import org.springframework.beans.factory.config.BeanPostProcessor;

import javax.xml.transform.Source;
import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;
import java.sql.SQLOutput;

public class MyBeanPostProcessor implements BeanPostProcessor {

    @Override
    public Object postProcessBeforeInitialization(Object bean,String beanName) throws BeansException {
        System.out.println("第五步：bean实例之前后处理");
        return bean;
    }

    /**
     *
     * @param bean UserDaoImpl实现类
     * @param beanName 配置的beanName名字
     * @return
     * @throws BeansException
     */
    @Override
    public Object postProcessAfterInitialization(final Object bean,String beanName) throws BeansException{

        System.out.println("第八步：bean实例化之后处理");

        if("userDao".equals(beanName)){
            Class<?>[] interfaces = bean.getClass().getInterfaces();
            for(Class c : interfaces){
                System.out.println(c);
            }

            Object proxy = Proxy.newProxyInstance(bean.getClass().getClassLoader(),bean.getClass().getInterfaces(),new InvocationHandler(){

                @Override
                public Object invoke(Object proxy,Method method,Object[] args) throws Throwable {

                    if("save".equals(method.getName())){
                        System.out.println("方法增强");
                        return method.invoke(bean,args);
                    }

                    return method.invoke(bean,args);


                }
            });

            return proxy;

        }else{
            return bean;
        }


    }




}
