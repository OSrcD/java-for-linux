package com.imooc.ioc.demo3;

import org.springframework.beans.BeansException;
import org.springframework.beans.factory.BeanNameAware;
import org.springframework.beans.factory.DisposableBean;
import org.springframework.beans.factory.InitializingBean;
import org.springframework.context.ApplicationContext;
import org.springframework.context.ApplicationContextAware;

public class Man implements BeanNameAware, ApplicationContextAware, InitializingBean, DisposableBean {

    private String name;

    public String getName() {

        return name;
    }

    public void setName(String name) {
        System.out.println("第二步：populate properties设置属性"+ name);
        this.name = name;
    }

    public Man(){
        System.out.println("第一步：instantiate bean MAN被实例化...");
    }

    public void setup(){
        System.out.println("第七步：MAN被初始化...");
    }

    public void teardown(){
        System.out.println("第十一步：MAN被销毁了...");
    }

    @Override
    public void setBeanName(String name){
        System.out.println("第三步：得到配置文件bean的名称");
    }

    @Override
    public void setApplicationContext(ApplicationContext applicationContext) throws BeansException {
        System.out.println("第四步：得到工厂信息");
    }

    @Override
    public void afterPropertiesSet() throws Exception {
        System.out.println("第六步：属性设置之后");
    }

    public void run(){
        System.out.println("第九步：执行业务代码");
    }

    @Override
    public void destroy() throws Exception{
        System.out.println("第十步：执行Spring容器销毁方法");
    }
}
