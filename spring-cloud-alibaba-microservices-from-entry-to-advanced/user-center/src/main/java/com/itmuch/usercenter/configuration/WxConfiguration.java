package com.itmuch.usercenter.configuration;

import cn.binarywang.wx.miniapp.api.WxMaService;
import cn.binarywang.wx.miniapp.api.impl.WxMaServiceImpl;
import cn.binarywang.wx.miniapp.config.WxMaConfig;
import cn.binarywang.wx.miniapp.config.impl.WxMaDefaultConfigImpl;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class WxConfiguration {
    @Bean
    public WxMaConfig wxMaConfig(){
        WxMaDefaultConfigImpl config = new WxMaDefaultConfigImpl();
        config.setAppid("wx94acb79699a0fb29");
        config.setSecret("1e68471b17c32d21ae1005185dc93bbe");
        return config;
    }

    @Bean
    public WxMaService wxMaService(WxMaConfig wxMaConfig){
        WxMaServiceImpl service = new WxMaServiceImpl();
        service.setWxMaConfig(wxMaConfig);
        return service;
    }
}
