package com.imooc.springcloud;

import com.netflix.loadbalancer.IRule;
import com.netflix.loadbalancer.RandomRule;
import org.springframework.cloud.netflix.ribbon.RibbonClient;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

// 全局配置
@Configuration
/**
 * @RibbonClient 基于注解方式配置负载均衡策略
 * name 指定微服务的名称 configuration 指定负载均衡策略
 */
@RibbonClient(name = "eureka-client", configuration = com.netflix.loadbalancer.RoundRobinRule.class)
public class RibbonConfiguration {

    /**
     * IRule 负载均衡策略顶级接口
     * RandomRule 随机负载均衡策略
     * 注解的优先级比配置文件优先级高
     */
    @Bean
    public IRule defaultLBStrategy() {
        return new RandomRule();
    }

}
