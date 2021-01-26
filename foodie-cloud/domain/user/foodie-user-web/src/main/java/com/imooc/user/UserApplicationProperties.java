package com.imooc.user;

import lombok.Data;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.cloud.context.config.annotation.RefreshScope;
import org.springframework.context.annotation.Configuration;

@Configuration
/**
 * 因为注册功能
 * 希望从 外部控制它的开启和关闭
 * 是可以在运行期间不断刷新的
 */
@RefreshScope
@Data
public class UserApplicationProperties {

    @Value("${userservice.registration.disabled}")
    private boolean disableRegistration;

}
