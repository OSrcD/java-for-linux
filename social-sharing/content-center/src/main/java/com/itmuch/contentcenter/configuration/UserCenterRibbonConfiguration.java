package com.itmuch.contentcenter.configuration;


import org.springframework.cloud.netflix.ribbon.RibbonClients;

import org.springframework.context.annotation.Configuration;
import ribbonconfiguration.RibbonConfiguration;


@Configuration
@RibbonClients(defaultConfiguration = RibbonConfiguration.class)
public class UserCenterRibbonConfiguration {

}
