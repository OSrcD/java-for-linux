package com.imooc.springcloud;

import com.imooc.springcloud.hystrix.Fallback;
import org.springframework.cloud.openfeign.FeignClient;

/**
 * fallback  指定一个类来处理降级异常
 * MyService会将用户请求重新导到了当前Fallback类中 error方法
 */
@FeignClient(name = "feign-client", fallback = Fallback.class)
public interface MyService extends IService {

}
