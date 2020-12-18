package com.itmuch.contentcenter.configuration;


import com.alibaba.nacos.api.exception.NacosException;
import com.alibaba.nacos.api.naming.NamingService;
import com.alibaba.nacos.api.naming.pojo.Instance;

import com.alibaba.nacos.client.naming.core.Balancer;
import com.alibaba.nacos.client.naming.utils.CollectionUtils;
import com.netflix.client.config.IClientConfig;
import com.netflix.loadbalancer.AbstractLoadBalancerRule;
import com.netflix.loadbalancer.BaseLoadBalancer;

import com.netflix.loadbalancer.Server;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cloud.alibaba.nacos.NacosDiscoveryProperties;
import org.springframework.cloud.alibaba.nacos.ribbon.NacosServer;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;
import java.util.Objects;
import java.util.stream.Collector;
import java.util.stream.Collectors;

@Slf4j
public class NacosSameClusterWeightedRule extends AbstractLoadBalancerRule {

    @Autowired
    private NacosDiscoveryProperties nacosDiscoveryProperties;

    @Override
    public void initWithNiwsConfig(IClientConfig iClientConfig) {

    }


    @Override
    public Server choose(Object o) {


        try {
            // 获得当前配置文件的集群名称
            String clusterName = nacosDiscoveryProperties.getClusterName();

            // Ribbon入口
            BaseLoadBalancer loadBalancer = (BaseLoadBalancer) this.getLoadBalancer();

            // 获得微服务实例名称,也就是user-center
            String name = loadBalancer.getName();

            // 拿到服务发现相关API
            NamingService namingService = nacosDiscoveryProperties.namingServiceInstance();


            // 1. 找到指定服务的所有实例 A
            List<Instance> instances = namingService.selectInstances(name,true);

            // 2. 过滤出相同集群下的所有实例 B
            List<Instance> sameClusInstances = instances.stream().
                    filter(instance -> Objects.equals(instance.getClusterName(),
                            clusterName)).
                    collect(Collectors.toList());

            // 3. 如果B为空，就用A
            List<Instance> instancesToBeChose = new ArrayList<>();
            if(CollectionUtils.isEmpty(sameClusInstances)){
                log.warn("发生跨集群调用，name = {}，clusterName = {}，instance = {}",
                        name,clusterName,instances);
                instancesToBeChose = instances;
            }else{
                instancesToBeChose = sameClusInstances;
            }
            log.info(String.valueOf(instancesToBeChose));
            // 4. 基于权重的负载均衡算法，返回1个实例
            Instance instance = ExtendBalancer.getHostByRandomWeight2(instancesToBeChose);
            log.info("选择的实例是，port = {}，instance = {}",instance.getPort(),instance);
            return new NacosServer(instance);
        } catch (NacosException e) {
            log.error("发生异常",e);
            return null;
        }

    }
}

class ExtendBalancer extends Balancer {
    public static Instance getHostByRandomWeight2(List<Instance> hosts){
        return getHostByRandomWeight(hosts);
    }
}