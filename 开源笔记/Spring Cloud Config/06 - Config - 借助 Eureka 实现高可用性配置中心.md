![](https://tcs.teambition.net/storage/3121545e0f2b8895e0898b0d2a0f30dd7382?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU5MSwiaWF0IjoxNjEyMTkwNzkxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1NDVlMGYyYjg4OTVlMDg5OGIwZDJhMGYzMGRkNzM4MiJ9.SWWj1RDK3DyBkejRd6umpKh_uskVgN42DRC-GtDc3aA&download=image.png "")

![](https://tcs.teambition.net/storage/31210ed041d806350a0b72ab68ac98c95bf2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU5MSwiaWF0IjoxNjEyMTkwNzkxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwZWQwNDFkODA2MzUwYTBiNzJhYjY4YWM5OGM5NWJmMiJ9.BYHleEQphzQI2noqfmkaK8jAbWkjpiOGVpakeHWFQYc&download=image.png "")

![](https://tcs.teambition.net/storage/3121201a983d1b65065c83fdd2c1c4092c3f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU5MSwiaWF0IjoxNjEyMTkwNzkxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyMDFhOTgzZDFiNjUwNjVjODNmZGQyYzFjNDA5MmMzZiJ9.KbeMas5L0m77D44ae8mNBZm109eX4onwv2Xeovv3Dw0&download=image.png "")

```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <parent>
        <artifactId>spring-cloud-demo</artifactId>
        <groupId>com.imooc</groupId>
        <version>1.0-SNAPSHOT</version>
        <relativePath>../../pom.xml</relativePath>
    </parent>
    <modelVersion>4.0.0</modelVersion>
    <packaging>jar</packaging>
    <artifactId>config-server-eureka</artifactId>

    <dependencies>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-config-server</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-client</artifactId>
        </dependency>

    </dependencies>


</project>
```

![](https://tcs.teambition.net/storage/3121f6a3d5d2fdfdeacad6025ec62c3ab759?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU5MSwiaWF0IjoxNjEyMTkwNzkxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmNmEzZDVkMmZkZmRlYWNhZDYwMjVlYzYyYzNhYjc1OSJ9.OF4dm_vlC33PxgBwKsh1aRz42Bmu5h0UgS4eH1sP0HE&download=image.png "")

```text
package com.imooc.springcloud;

import org.springframework.boot.WebApplicationType;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.builder.SpringApplicationBuilder;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import org.springframework.cloud.config.server.EnableConfigServer;

@SpringBootApplication
@EnableConfigServer
@EnableDiscoveryClient
public class ConfigServerApplication {

    public static void main(String[] args) {
        new SpringApplicationBuilder(ConfigServerApplication.class)
                .web(WebApplicationType.SERVLET)
                .run();
    }
}

```

![](https://tcs.teambition.net/storage/312177351926fe138720ca09e3319c101dd8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU5MSwiaWF0IjoxNjEyMTkwNzkxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3NzM1MTkyNmZlMTM4NzIwY2EwOWUzMzE5YzEwMWRkOCJ9.tR9Sr4ihGJtrm0SGCnqLDrgWP0cPb5Y-eIGIjuQESuo&download=image.png "")

```yaml
spring:
  application:
    name: config-server-eureka
  cloud:
    config:
      server:
        git:
          uri: https://github.com/OSrcD/config-repo.git
          force-pull: true


eureka:
  client:
    # 如果写错 会默认访问 localhost:87 几的端口 去访问注册中心
    service-url:
      defaultZone: http://localhost:20000/eureka/

server:
  port: 60001



```

![](https://tcs.teambition.net/storage/3121cb781b9f4fce093c3fa2d77fa001f63d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU5MSwiaWF0IjoxNjEyMTkwNzkxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjYjc4MWI5ZjRmY2UwOTNjM2ZhMmQ3N2ZhMDAxZjYzZCJ9.3P7byp-chmbeIv5QIbhl_2JPaE0k1IHhgtWIKMf1r-s&download=image.png "")

![](https://tcs.teambition.net/storage/31213e6c40fb5f74eccf7c47ce2da9a92c83?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU5MSwiaWF0IjoxNjEyMTkwNzkxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzZTZjNDBmYjVmNzRlY2NmN2M0N2NlMmRhOWE5MmM4MyJ9.OyFr3L-4ULvYWToxLr-Yz6bHTmKq0XQc_LNJlUlNH6k&download=image.png "")

![](https://tcs.teambition.net/storage/3121f2e6c6767103bd9aad0c08ddb5921797?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU5MSwiaWF0IjoxNjEyMTkwNzkxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmMmU2YzY3NjcxMDNiZDlhYWQwYzA4ZGRiNTkyMTc5NyJ9.gVEQtybQz67tg1yU2Txq5O2QYYN4289-lW-tE8jftsM&download=image.png "")

![](https://tcs.teambition.net/storage/3121dcceb11f30f5c64e252bb67f2b856114?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU5MSwiaWF0IjoxNjEyMTkwNzkxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkY2NlYjExZjMwZjVjNjRlMjUyYmI2N2YyYjg1NjExNCJ9.FvSYcz_0BzbqZnjQhYB2twF7ODjB8nKxsBePZusrVeU&download=image.png "")

```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <parent>
        <artifactId>spring-cloud-demo</artifactId>
        <groupId>com.imooc</groupId>
        <version>1.0-SNAPSHOT</version>
        <relativePath>../../pom.xml</relativePath>
    </parent>
    <modelVersion>4.0.0</modelVersion>

    <artifactId>config-client</artifactId>
    <packaging>jar</packaging>

    <dependencies>
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-web</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-config</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-actuator</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-client</artifactId>
        </dependency>

    </dependencies>

</project>
```

![](https://tcs.teambition.net/storage/3121351271f176c50976e02f334411c0075d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU5MSwiaWF0IjoxNjEyMTkwNzkxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzNTEyNzFmMTc2YzUwOTc2ZTAyZjMzNDQxMWMwMDc1ZCJ9.eSTOMHj2UFouhQqRn49IjWivP4jSnKsg9I1LO3HUlms&download=image.png "")

```java
package com.imooc.springcloud;


import org.springframework.boot.WebApplicationType;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.builder.SpringApplicationBuilder;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;

@SpringBootApplication
@EnableDiscoveryClient
public class ConfigClientApplication {
    public static void main(String[] args) {
        new SpringApplicationBuilder(ConfigClientApplication.class)
                .web(WebApplicationType.SERVLET)
                .run();
    }
}

```

![](https://tcs.teambition.net/storage/3121baf32de468fe187f85eb3656f618ee69?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU5MSwiaWF0IjoxNjEyMTkwNzkxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiYWYzMmRlNDY4ZmUxODdmODVlYjM2NTZmNjE4ZWU2OSJ9.P_8Hplkhf29iMvj7PFOx0uX2FYrFGZQkeAbP8kTn418&download=image.png "")

```yaml
spring:
  application:
    name: config-client
  cloud:
    config:
      # 覆盖 上面的name 指定 git 远端 Repository
      name: config-consumer
      # 指向config server 的端口
#      uri: http://localhost:60000
      # 跟服务发现有关 启动服务发现功能
      # 这样 config client 组件就会通过 Eureka的服务发现 尝试去拉取配置文件
      discovery:
        enabled: true
        # 指定 注册中心的 service id 去拉取注册中心的配置
        # 也就是 spring application name
        service-id: config-server-eureka
      # 真实项目中 可以配置操作系统环境变量
      # 或者在启动 Tomcat 的时候 给它指定一些属性 参数 注入进来
      # 这样 profile 就跟 环境挂钩起来了 比方说 我们在日常测试的机器上
      # 启动项里面 profile 注入的是 dev
      # 真正生产环境注入 production 就可以根据动态转入的profile 去github拉取到正确的文件
      profile: prod
      label: main
server:
  port: 61000

# 自定义属性 myWords ${words} 从 git 仓库获取的 words
myWords: ${words}

eureka:
  client:
    service-url:
      defaultZone: http://localhost:20000/eureka/

management:
  security:
    user:
      name: gitee
      password: gitee
      roles: ADMIN
  endpoints:
    web:
      exposure:
        # 使用"" 才能识别 *
        include: "*"
  endpoint:
    health:
      show-details: always

```

![](https://tcs.teambition.net/storage/3121c33832d7553a340e75fbe5427e35fc6e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU5MSwiaWF0IjoxNjEyMTkwNzkxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjMzM4MzJkNzU1M2EzNDBlNzVmYmU1NDI3ZTM1ZmM2ZSJ9.5fMDYb7NTyJz1I2xTlVHb94fbJbaePOF3kU4UfghfXc&download=image.png "")

![](https://tcs.teambition.net/storage/3121ddf1f3729ef2c76dd55f2daf5be55df3?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU5MSwiaWF0IjoxNjEyMTkwNzkxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkZGYxZjM3MjllZjJjNzZkZDU1ZjJkYWY1YmU1NWRmMyJ9.MbK74n__OMtf9xM-a175PQwjKjbQ-BaPqnsko2qD-x8&download=image.png "")

从注册中心获取到的地址

![](https://tcs.teambition.net/storage/31214b1698e5af40515b9e29807e2a1f6996?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU5MSwiaWF0IjoxNjEyMTkwNzkxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0YjE2OThlNWFmNDA1MTViOWUyOTgwN2UyYTFmNjk5NiJ9.UbvxRZhmlMPIAUitfxMq0Bs0g7XjPQUMrWyqrvl1Z-U&download=image.png "")

![](https://tcs.teambition.net/storage/31211f021384eb616fcd0be17941e0613b4b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU5MSwiaWF0IjoxNjEyMTkwNzkxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExZjAyMTM4NGViNjE2ZmNkMGJlMTc5NDFlMDYxM2I0YiJ9.iAdcSt9e_k5bUQnR70hkv3J8hkH5pv0dcpaV3HZ2oVY&download=image.png "")





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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU5MSwiaWF0IjoxNjEyMTkwNzkxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.FcA1gHKZ7yhYVvo4sL9XobzH4Y3Wfu6yBLnggJ6e7n0&download=image.png "")

