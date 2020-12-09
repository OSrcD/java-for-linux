package com.itmuch.contentcenter.configuration;








import com.alibaba.nacos.api.exception.NacosException;
import com.alibaba.nacos.api.naming.NamingService;


import com.alibaba.nacos.api.naming.pojo.Instance;
import com.alibaba.nacos.client.naming.core.Balancer;
import com.netflix.loadbalancer.BaseLoadBalancer;
import com.netflix.loadbalancer.Server;
import com.netflix.client.config.IClientConfig;
import com.netflix.loadbalancer.AbstractLoadBalancerRule;

import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cloud.alibaba.nacos.NacosDiscoveryProperties;

import org.springframework.cloud.alibaba.nacos.ribbon.NacosServer;

import java.util.List;

@Slf4j
public class NacosWeightedRule extends AbstractLoadBalancerRule {

    @Autowired
    private NacosDiscoveryProperties nacosDiscoveryProperties;

    @Override
    public void initWithNiwsConfig(IClientConfig iClientConfig) {
        // 读取配置文件,并初始化NacosWeightedRule
    }

    @Override
    public Server choose(Object o){
        try {
            // 获得Ribbon的入口类,强转为子类BaseLoadBalancer，为了getName方法
            BaseLoadBalancer loadBalancer = (BaseLoadBalancer) this.getLoadBalancer();

            // 拿到请求的服务名称，也就是user-center
            String name = loadBalancer.getName();

            log.info("name = {}",name);

            // 拿到服务发现的相关API
            NamingService namingService = nacosDiscoveryProperties.namingServiceInstance();

            // nacos client自动基于权重的负载均衡算法，给我们选择一个实例。
            Instance instance = namingService.selectOneHealthyInstance(name);

            log.info("选择的实例是：port = {}，instance = {}", instance.getPort(), instance);
            return new NacosServer(instance);
        }catch(NacosException e){

            return null;
        }


    }
}


