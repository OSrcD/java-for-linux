package com.itmuch.contentcenter.feignclient.interceptor;

import feign.RequestInterceptor;
import feign.RequestTemplate;
import org.apache.commons.lang.StringUtils;
import org.springframework.web.context.request.RequestAttributes;
import org.springframework.web.context.request.RequestContextHolder;
import org.springframework.web.context.request.ServletRequestAttributes;

import javax.servlet.http.HttpServletRequest;

public class TokenRelayRequestInterceptor implements RequestInterceptor {
    @Override
    public void apply(RequestTemplate template) {
        // 1.获取到token
        RequestAttributes requestAttributes = RequestContextHolder.getRequestAttributes();

        ServletRequestAttributes servletRequestAttributes = (ServletRequestAttributes)requestAttributes;

        HttpServletRequest httpServletRequest = servletRequestAttributes.getRequest();

        String token = httpServletRequest.getHeader("X-Token");

        // 2.将token传递到feign,feign调用的时候会自动传递这个header
        if(StringUtils.isNotBlank(token)){

            template.header("X-Token",token);
        }


    }
}
