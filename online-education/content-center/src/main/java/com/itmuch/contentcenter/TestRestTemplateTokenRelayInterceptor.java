package com.itmuch.contentcenter;

import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpRequest;
import org.springframework.http.client.ClientHttpRequestExecution;
import org.springframework.http.client.ClientHttpRequestInterceptor;
import org.springframework.http.client.ClientHttpResponse;
import org.springframework.web.context.request.RequestAttributes;
import org.springframework.web.context.request.RequestContextHolder;
import org.springframework.web.context.request.ServletRequestAttributes;

import javax.servlet.http.HttpServletRequest;
import java.io.IOException;

public class TestRestTemplateTokenRelayInterceptor implements ClientHttpRequestInterceptor {
    @Override
    public ClientHttpResponse intercept(HttpRequest request, byte[] body, ClientHttpRequestExecution execution) throws IOException {
        // 拿到token
        RequestAttributes requestAttributes = RequestContextHolder.getRequestAttributes();

        ServletRequestAttributes servletRequestAttributes =  (ServletRequestAttributes) requestAttributes;

        HttpServletRequest httpServletRequest = servletRequestAttributes.getRequest();

        String token = httpServletRequest.getHeader("X-Token");

        HttpHeaders headers = request.getHeaders();

        headers.add("X-Token",token);

        //保证请求继续执行
        return execution.execute(request,body);
    }
}
