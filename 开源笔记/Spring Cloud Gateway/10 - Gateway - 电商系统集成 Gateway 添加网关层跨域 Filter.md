![](https://tcs.teambition.net/storage/3122186309c16e91b2c4557d303d2963bdb7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM1OCwiaWF0IjoxNjEyMTkwNTU4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxODYzMDljMTZlOTFiMmM0NTU3ZDMwM2QyOTYzYmRiNyJ9.73IR0XaDdZfLNwlHLIAmXgOCffwrXzFa6ZlIU4FcF8I&download=image.png "")

```java
//package com.imooc.config;
//
//import org.springframework.context.annotation.Bean;
//import org.springframework.context.annotation.Configuration;
//import org.springframework.web.cors.CorsConfiguration;
//import org.springframework.web.cors.UrlBasedCorsConfigurationSource;
//import org.springframework.web.filter.CorsFilter;
//
//@Configuration
//public class CorsConfig {
//
//    public CorsConfig(){
//
//    }
//
//    @Bean
//    public CorsFilter corsFilter(){
//        // 1.添加cors配置信息
//        CorsConfiguration config = new CorsConfiguration();
//        config.addAllowedOrigin("*");
////        config.addAllowedOrigin("http://localhost:8080");
////        config.addAllowedOrigin("http://120.77.47.215:8080");
////        config.addAllowedOrigin("http://120.77.47.215");
//
//        // 设置是否发送cookie信息
//        config.setAllowCredentials(true);
//
//        // 设置允许请求的方式
//        config.addAllowedMethod("*");
//
//        // 设置允许的header
//        config.addAllowedHeader("*");
//
//        // 2. 为url添加映射路径
//        UrlBasedCorsConfigurationSource corsSource = new UrlBasedCorsConfigurationSource();
//        corsSource.registerCorsConfiguration("/**",config);
//
//        // 3. 返回重新定义好的corsSource
//        return new CorsFilter(corsSource);
//    }
//}

```

![](https://tcs.teambition.net/storage/31220b06af9100757aae76a2d78d10ddd60e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM1OCwiaWF0IjoxNjEyMTkwNTU4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIwYjA2YWY5MTAwNzU3YWFlNzZhMmQ3OGQxMGRkZDYwZSJ9.Xeg1xGGwa6G5vkSt6Vz6uAVdvPEmBu9VVhy2CgXyorA&download=image.png "")

```java
package com.imooc.utils;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.UnsupportedEncodingException;
import java.net.URLDecoder;
import java.net.URLEncoder;


/**
 * 
 * @Title: CookieUtils.java
 * @Package com.imooc.utils
 * @Description: Cookie 工具类
 * Copyright: Copyright (c)
 * Company: www.imooc.com
 *
 * @author imooc
 * @version V1.0
 */
public final class CookieUtils {

    final static Logger logger = LoggerFactory.getLogger(CookieUtils.class);
   
   /**
    * 
    * @Description: 得到Cookie的值, 不编码
    * @param request
    * @param cookieName
    * @return
    */
    public static String getCookieValue(HttpServletRequest request, String cookieName) {
        return getCookieValue(request, cookieName, false);
    }
    
    /**
     * 
     * @Description: 得到Cookie的值
     * @param request
     * @param cookieName
     * @param isDecoder
     * @return
     */
    public static String getCookieValue(HttpServletRequest request, String cookieName, boolean isDecoder) {
        Cookie[] cookieList = request.getCookies();
        if (cookieList == null || cookieName == null) {
            return null;
        }
        String retValue = null;
        try {
            for (int i = 0; i < cookieList.length; i++) {
                if (cookieList[i].getName().equals(cookieName)) {
                    if (isDecoder) {
                        retValue = URLDecoder.decode(cookieList[i].getValue(), "UTF-8");
                    } else {
                        retValue = cookieList[i].getValue();
                    }
                    break;
                }
            }
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
        return retValue;
    }

    /**
     * 
     * @Description: 得到Cookie的值
     * @param request
     * @param cookieName
     * @param encodeString
     * @return
     */
    public static String getCookieValue(HttpServletRequest request, String cookieName, String encodeString) {
        Cookie[] cookieList = request.getCookies();
        if (cookieList == null || cookieName == null) {
            return null;
        }
        String retValue = null;
        try {
            for (int i = 0; i < cookieList.length; i++) {
                if (cookieList[i].getName().equals(cookieName)) {
                    retValue = URLDecoder.decode(cookieList[i].getValue(), encodeString);
                    break;
                }
            }
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
        return retValue;
    }

    /**
     * 
     * @Description: 设置Cookie的值 不设置生效时间默认浏览器关闭即失效,也不编码
     * @param request
     * @param response
     * @param cookieName
     * @param cookieValue
     */
    public static void setCookie(HttpServletRequest request, HttpServletResponse response, String cookieName,
            String cookieValue) {
        setCookie(request, response, cookieName, cookieValue, -1);
    }

    /**
     * 
     * @Description: 设置Cookie的值 在指定时间内生效,但不编码
     * @param request
     * @param response
     * @param cookieName
     * @param cookieValue
     * @param cookieMaxage
     */
    public static void setCookie(HttpServletRequest request, HttpServletResponse response, String cookieName,
            String cookieValue, int cookieMaxage) {
        setCookie(request, response, cookieName, cookieValue, cookieMaxage, false);
    }

    /**
     * 
     * @Description: 设置Cookie的值 不设置生效时间,但编码
     * 在服务器被创建，返回给客户端，并且保存客户端
     * 如果设置了SETMAXAGE(int seconds)，会把cookie保存在客户端的硬盘中
     * 如果没有设置，会默认把cookie保存在浏览器的内存中
     * 一旦设置setPath()：只能通过设置的路径才能获取到当前的cookie信息
     * @param request
     * @param response
     * @param cookieName
     * @param cookieValue
     * @param isEncode
     */
    public static void setCookie(HttpServletRequest request, HttpServletResponse response, String cookieName,
            String cookieValue, boolean isEncode) {
        setCookie(request, response, cookieName, cookieValue, -1, isEncode);
    }

   /**
    * 
    * @Description: 设置Cookie的值 在指定时间内生效, 编码参数
    * @param request
    * @param response
    * @param cookieName
    * @param cookieValue
    * @param cookieMaxage
    * @param isEncode
    */
    public static void setCookie(HttpServletRequest request, HttpServletResponse response, String cookieName,
            String cookieValue, int cookieMaxage, boolean isEncode) {
        doSetCookie(request, response, cookieName, cookieValue, cookieMaxage, isEncode);
    }

    /**
     * 
     * @Description: 设置Cookie的值 在指定时间内生效, 编码参数(指定编码)
     * @param request
     * @param response
     * @param cookieName
     * @param cookieValue
     * @param cookieMaxage
     * @param encodeString
     */
    public static void setCookie(HttpServletRequest request, HttpServletResponse response, String cookieName,
            String cookieValue, int cookieMaxage, String encodeString) {
        doSetCookie(request, response, cookieName, cookieValue, cookieMaxage, encodeString);
    }

    /**
     * 
     * @Description: 删除Cookie带cookie域名
     * @param request
     * @param response
     * @param cookieName
     */
    public static void deleteCookie(HttpServletRequest request, HttpServletResponse response,
            String cookieName) {
        doSetCookie(request, response, cookieName, null, -1, false);
//        doSetCookie(request, response, cookieName, "", -1, false);
    }

    
    /**
     * 
     * @Description: 设置Cookie的值，并使其在指定时间内生效
     * @param request
     * @param response
     * @param cookieName
     * @param cookieValue
     * @param cookieMaxage cookie生效的最大秒数
     * @param isEncode
     */
    private static final void doSetCookie(HttpServletRequest request, HttpServletResponse response,
            String cookieName, String cookieValue, int cookieMaxage, boolean isEncode) {
        try {
            if (cookieValue == null) {
                cookieValue = "";
            } else if (isEncode) {
                cookieValue = URLEncoder.encode(cookieValue, "utf-8");
            }
            Cookie cookie = new Cookie(cookieName, cookieValue);
            if (cookieMaxage > 0)
                cookie.setMaxAge(cookieMaxage);
            if (null != request) {// 设置域名的cookie
                // FIXME 上线之前改回来（仅限在localhost访问）
                /**
                 * 本地使用 localhost 为了防止浏览器前面的域名
                 * 和最终经过 网关转发 到达 咱们 后台微服务 这个domainName
                 * 有不一致的情况 在本地测试可以直接改成 localhost
                 */
//             String domainName = getDomainName(request);
                String domainName = "localhost";
                logger.info("========== domainName: {} ==========", domainName);
                if (!"localhost".equals(domainName)) {
                   cookie.setDomain(domainName);
                }
            }
            cookie.setPath("/");
            response.addCookie(cookie);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * 
     * @Description: 设置Cookie的值，并使其在指定时间内生效
     * @param request
     * @param response
     * @param cookieName
     * @param cookieValue
     * @param cookieMaxage cookie生效的最大秒数
     * @param encodeString
     */
    private static final void doSetCookie(HttpServletRequest request, HttpServletResponse response,
            String cookieName, String cookieValue, int cookieMaxage, String encodeString) {
        try {
            if (cookieValue == null) {
                cookieValue = "";
            } else {
                cookieValue = URLEncoder.encode(cookieValue, encodeString);
            }
            Cookie cookie = new Cookie(cookieName, cookieValue);
            if (cookieMaxage > 0)
                cookie.setMaxAge(cookieMaxage);
            if (null != request) {// 设置域名的cookie
               String domainName = getDomainName(request);
                logger.info("========== domainName: {} ==========", domainName);
                if (!"localhost".equals(domainName)) {
                   cookie.setDomain(domainName);
                }
            }
            cookie.setPath("/");
            response.addCookie(cookie);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * 
     * @Description: 得到cookie的域名
     * @return
     */
    private static final String getDomainName(HttpServletRequest request) {
        String domainName = null;

        String serverName = request.getRequestURL().toString();
        if (serverName == null || serverName.equals("")) {
            domainName = "";
        } else {
            serverName = serverName.toLowerCase();
            serverName = serverName.substring(7);
            final int end = serverName.indexOf("/");
            serverName = serverName.substring(0, end);
            if (serverName.indexOf(":") > 0) {
               String[] ary = serverName.split("\\:");
               serverName = ary[0];
            }

            final String[] domains = serverName.split("\\.");
            int len = domains.length;
            if (len > 3 && !isIp(serverName)) {
               // www.xxx.com.cn
                domainName = "." + domains[len - 3] + "." + domains[len - 2] + "." + domains[len - 1];
            } else if (len <= 3 && len > 1) {
                // xxx.com or xxx.cn
                domainName = "." + domains[len - 2] + "." + domains[len - 1];
            } else {
                domainName = serverName;
            }
        }
        return domainName;
    }
    
    public static String trimSpaces(String IP){//去掉IP字符串前后所有的空格  
        while(IP.startsWith(" ")){  
               IP= IP.substring(1,IP.length()).trim();  
            }  
        while(IP.endsWith(" ")){  
               IP= IP.substring(0,IP.length()-1).trim();  
            }  
        return IP;  
    }  
    
    public static boolean isIp(String IP){//判断是否是一个IP  
        boolean b = false;  
        IP = trimSpaces(IP);  
        if(IP.matches("\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}")){  
            String s[] = IP.split("\\.");  
            if(Integer.parseInt(s[0])<255)  
                if(Integer.parseInt(s[1])<255)  
                    if(Integer.parseInt(s[2])<255)  
                        if(Integer.parseInt(s[3])<255)  
                            b = true;  
        }  
        return b;  
    }  

}

```

![](https://tcs.teambition.net/storage/312209ba98d77237afc311632e26ec6ee197?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM1OCwiaWF0IjoxNjEyMTkwNTU4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIwOWJhOThkNzcyMzdhZmMzMTE2MzJlMjZlYzZlZTE5NyJ9.6IZqaXKbMBOrdkJ8vSzcmf-OurcbsnAxxycC7ZIHD1w&download=image.png "")

```yaml
# 可以尝试集成config-server来配置
spring:
  application:
    name: platform-gateway
  redis:
    host: 192.168.245.138
    port: 6379
    database: 0
  main:
    allow-bean-definition-overriding: true
  cloud:
    gateway:
      # 全局跨域配置
      globalcors:
        # 配置各个不同的路径
        cors-configurations:
          # 全部路径
          '[/**]':
            # 返回的资源共享给请求来源
            allowed-origins:
            # - 配置多个属性
            - "http://localhost:8080"
            - "http://shop.z.mukewang.com:8080"
            - "http://center.z.mukewang.com:8080"
            - "http://shop.z.mukewang.com"
            - "http://center.z.mukewang.com"
            - "*"
            # 允许携带一些认证信息 比如 cookie authorization之类的认证信息 是否可以暴露给前端页面
            allow-credentials: true
            # 可以允许接收那些 header * 所有 header都可以
            allowed-headers: "*"
            # 允许调用的方法
            allowed-methods: "*"
            # 可以暴露给前端用户 给它返回回去的 headers
            expose-headers: "*"
            # 单位是秒 600 秒 10分钟 表示Options可以在浏览器缓存多长时间
            max-age: 600
      locator:
        # 在生产环境下会关闭 不会自动创建默认路由规则
        enabled: false
        lower-case-service-id: true


server:
  port: 20004


eureka:
  client:
    serviceUrl:
      defaultZone: http://localhost:20000/eureka/

## 开启所有actuator-endpoint
management:
  security:
    user:
      name: gitee
      password: gitee
      roles: ADMIN
  endpoints:
    web:
      exposure:
        include: "*"
  endpoint:
    health:
      show-details: always
```





开源笔记

可 Pull Requests 协作写开源笔记

如果笔记图片无法访问 请访问 [teambition](https://tburl.in/0jDNvpbK) 原版开源笔记

gitee

[https://gitee.com/opendevel/java-for-linux](https://gitee.com/opendevel/java-for-linux)

github

[https://github.com/OSrcD/java-for-linux](https://github.com/OSrcD/java-for-linux)

teambition

[https://tburl.in/0jDNvpbK](https://tburl.in/0jDNvpbK)

开源视频

bilibili

[https://space.bilibili.com/77266754](https://space.bilibili.com/77266754)

开源博客

oschina

[https://my.oschina.net/u/4675154](https://my.oschina.net/u/4675154)

csdn

[https://blog.csdn.net/OpenDevel](https://blog.csdn.net/OpenDevel)

开源项目

gitee

[https://gitee.com/opendevel](https://gitee.com/opendevel)

github

[https://github.com/OSrcD](https://github.com/OSrcD)

开源赞赏

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTM1OCwiaWF0IjoxNjEyMTkwNTU4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.Ls8R8GmWSsi1Pl6gtvjSUgxTr0BtlSWwGZxE4IOF6Ak&download=image.png "")

