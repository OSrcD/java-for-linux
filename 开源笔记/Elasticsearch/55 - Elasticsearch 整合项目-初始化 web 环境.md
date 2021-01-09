![](https://tcs.teambition.net/storage/3121e11a3998ad4d8f56d4f5ff4f7539648c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM5MywiaWF0IjoxNjEwMjA4NTkzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlMTFhMzk5OGFkNGQ4ZjU2ZDRmNWZmNGY3NTM5NjQ4YyJ9.ERqnTuoEq7aGnPZzGM6DC6aJsSgscGavT7EubOfoINM&download=image.png "")

```xml
<dependency>
            <groupId>com.imooc</groupId>
            <artifactId>foodie-dev-common</artifactId>
            <version>1.0-SNAPSHOT</version>
        </dependency>

        <dependency>
            <groupId>org.apache.logging.log4j</groupId>
            <artifactId>log4j-core</artifactId>
            <version>2.11.1</version>
        </dependency>

```

![](https://tcs.teambition.net/storage/31211f67c723a8ce04a3f89f2c3665e8c3e5?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM5MywiaWF0IjoxNjEwMjA4NTkzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExZjY3YzcyM2E4Y2UwNGEzZjg5ZjJjMzY2NWU4YzNlNSJ9.mnc72f6SCbz79llhKX8_wD5l8iSMu2gOPa7BJhUYKKc&download=image.png "")

```java
package com.imooc.controller;

import com.imooc.utils.IMOOCJSONResult;
import com.imooc.utils.PagedGridResult;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("items")
public class ItemsController {

    @GetMapping("/hello")
    public Object hello() {
        return "Hello Elasticsearch~";
    }


}


```

![](https://tcs.teambition.net/storage/3121c68621c3d32cd1d8e9e8132ad2252733?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM5MywiaWF0IjoxNjEwMjA4NTkzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjNjg2MjFjM2QzMmNkMWQ4ZTllODEzMmFkMjI1MjczMyJ9.jsq4yaVObTUIPE1uqOhWpl99oZA0HCTYE3ytnhiVeZY&download=image.png "")

```java
package com.imooc;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.cors.CorsConfiguration;
import org.springframework.web.cors.UrlBasedCorsConfigurationSource;
import org.springframework.web.filter.CorsFilter;

@Configuration
public class CorsConfig {

    public CorsConfig() {
    }

    @Bean
    public CorsFilter corsFilter() {
        // 1. 添加cors配置信息
        CorsConfiguration config = new CorsConfiguration();
        config.addAllowedOrigin("http://localhost:8080");
        config.addAllowedOrigin("http://shop.z.mukewang.com:8080");
        config.addAllowedOrigin("http://center.z.mukewang.com:8080");
        config.addAllowedOrigin("http://shop.z.mukewang.com");
        config.addAllowedOrigin("http://center.z.mukewang.com");
        config.addAllowedOrigin("*");

        // 设置是否发送cookie信息
        config.setAllowCredentials(true);

        // 设置允许请求的方式
        config.addAllowedMethod("*");

        // 设置允许的header
        config.addAllowedHeader("*");

        // 2. 为url添加映射路径
        UrlBasedCorsConfigurationSource corsSource = new UrlBasedCorsConfigurationSource();
        corsSource.registerCorsConfiguration("/**", config);

        // 3. 返回重新定义好的corsSource
        return new CorsFilter(corsSource);
    }

}


```

![](https://tcs.teambition.net/storage/312171aa2ae6034bb991f6e8aa49d966d3a0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM5MywiaWF0IjoxNjEwMjA4NTkzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3MWFhMmFlNjAzNGJiOTkxZjZlOGFhNDlkOTY2ZDNhMCJ9.kiK1Od7HhdkvPAcFs13jeRT78ZPQdrxKZfeOy_rSfUs&download=image.png "")

![](https://tcs.teambition.net/storage/31211c631d3d22696e22e9d7e200d6ab3786?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM5MywiaWF0IjoxNjEwMjA4NTkzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExYzYzMWQzZDIyNjk2ZTIyZTlkN2UyMDBkNmFiMzc4NiJ9.jqxzpxd3GjCDZqMnkl4OysHmsxU9IRgJ8JfsmNuf3lM&download=image.png "")

![](https://tcs.teambition.net/storage/3121bed54914565e6006df0f1b4681f56922?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM5MywiaWF0IjoxNjEwMjA4NTkzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiZWQ1NDkxNDU2NWU2MDA2ZGYwZjFiNDY4MWY1NjkyMiJ9.m-ehIyGaGLLr9F_1ik76PNAoUeUhFIoIWwgSqzBty0I&download=image.png "")

![](https://tcs.teambition.net/storage/3121e9ee9c384794e3dcb3bc74d3497644cc?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM5MywiaWF0IjoxNjEwMjA4NTkzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlOWVlOWMzODQ3OTRlM2RjYjNiYzc0ZDM0OTc2NDRjYyJ9.Lx9QBItR-6ih1-BppM47n1y1DtLU_-3tLCvCiIsTwo8&download=image.png "")

![](https://tcs.teambition.net/storage/312198d7ed769f61300355e07fc7c6d8c363?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM5MywiaWF0IjoxNjEwMjA4NTkzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5OGQ3ZWQ3NjlmNjEzMDAzNTVlMDdmYzdjNmQ4YzM2MyJ9.5Pq8hAVIWlXgrVVxDNE5twCFhRG0QdDVEmjpsAbCUnk&download=image.png "")

```text
log4j.rootLogger=DEBUG,stdout,file
log4j.additivity.org.apache=true

log4j.appender.stdout=org.apache.log4j.ConsoleAppender
log4j.appender.stdout.threshold=INFO
log4j.appender.stdout.layout=org.apache.log4j.PatternLayout
log4j.appender.stdout.layout.ConversionPattern=%-5p %c{1}:%L - %m%n

log4j.appender.file=org.apache.log4j.DailyRollingFileAppender
log4j.appender.file.layout=org.apache.log4j.PatternLayout
log4j.appender.file.DatePattern='.'yyyy-MM-dd-HH-mm
log4j.appender.file.layout.ConversionPattern=%d{yyyy-MM-dd HH:mm:ss} %-5p %c{1}:%L - %m%n
log4j.appender.file.Threshold=INFO
log4j.appender.file.append=true
log4j.appender.file.File=/tmp/workspaces/logs/foodie-search/imooc.log



```

![](https://tcs.teambition.net/storage/3121ddefa668275cbccafe283df97112f329?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM5MywiaWF0IjoxNjEwMjA4NTkzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkZGVmYTY2ODI3NWNiY2NhZmUyODNkZjk3MTEyZjMyOSJ9.5-WvJmD6ZuymoGb4Q_Vab8OxThZDi6uzXOpU8_qgwpA&download=image.png "")

```yaml
server:
  port: 8033
spring:
  datasource:                                           # 数据源的相关配置
    type: com.zaxxer.hikari.HikariDataSource          # 数据源类型：HikariCP
    driver-class-name: com.mysql.jdbc.Driver          # mysql驱动
    url: jdbc:mysql://localhost:3306/foodie-shop-dev?useUnicode=true&characterEncoding=UTF-8&autoReconnect=true
    username: root
    password: 数据库密码
  redis:
    # Redis 单机单实例
    database: 0
    host: 192.168.245.138
    port: 6379
    password: imooc
  data:
    elasticsearch:
      cluster-nodes: 192.168.245.151:9300
      cluster-name: es6

```

![](https://tcs.teambition.net/storage/3121e2c2d2a0d8b6926e094007a595c412fc?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM5MywiaWF0IjoxNjEwMjA4NTkzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlMmMyZDJhMGQ4YjY5MjZlMDk0MDA3YTU5NWM0MTJmYyJ9.pSXQMeEtPbgXeGlhIXFdwR4HdoNL0FaL1Pczppph7yo&download=image.png "")

```java
package com.imooc;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.autoconfigure.security.servlet.SecurityAutoConfiguration;

@SpringBootApplication(exclude = {SecurityAutoConfiguration.class})
public class Application {

    public static void main(String[] args) {
        SpringApplication.run(Application.class,args);

    }
}


```

![](https://tcs.teambition.net/storage/3121b6fc3a493b6f6bb55703c8aee1e7c07d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM5MywiaWF0IjoxNjEwMjA4NTkzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiNmZjM2E0OTNiNmY2YmI1NTcwM2M4YWVlMWU3YzA3ZCJ9.r6j9UsXYXQN0glTwrADFFj1j1faXNWoLRQI710hk-2A&download=image.png "")

开源笔记

可 Pull Requests 协作写开源笔记

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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzM5MywiaWF0IjoxNjEwMjA4NTkzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.3KhVCe9EE6GG7lfasMr05_MHw5sBY6ClNE6cOrjX3MY&download=image.png "")

