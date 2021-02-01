![](https://tcs.teambition.net/storage/3121a6db8cbefebd919e5d7f318eaddb6214?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTYwMCwiaWF0IjoxNjEyMTkwODAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhNmRiOGNiZWZlYmQ5MTllNWQ3ZjMxOGVhZGRiNjIxNCJ9.HlbEXDBGnRFOoFl5vUV14UShHfWWBvh2le9299TyEDU&download=2020-09-17%20055252.png "")

![](https://tcs.teambition.net/storage/3121906188d6913ab6f57618a31d1ad6550f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTYwMCwiaWF0IjoxNjEyMTkwODAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5MDYxODhkNjkxM2FiNmY1NzYxOGEzMWQxYWQ2NTUwZiJ9.AUHDD7wgHKJEIoqjfdoEhjEKkkzTAxTcRZZtZWzBtv4&download=image.png "")

![](https://tcs.teambition.net/storage/3121b2bac0b12cda279aec9f5a53cc132584?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTYwMCwiaWF0IjoxNjEyMTkwODAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiMmJhYzBiMTJjZGEyNzlhZWM5ZjVhNTNjYzEzMjU4NCJ9.upS581phtC1grB3LWpIbpMoLkLOjOFsVNR-cQlPGwDk&download=image.png "")

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
    </dependencies>

</project>
```

![](https://tcs.teambition.net/storage/3121e1fbda3fee28280772ea706bf32f6a48?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTYwMCwiaWF0IjoxNjEyMTkwODAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlMWZiZGEzZmVlMjgyODA3NzJlYTcwNmJmMzJmNmE0OCJ9.nTJ5NY93Gs7r1GvHZTzXE1zAJKbNMFWuVji0TTH5lWY&download=image.png "")

```java
package com.imooc.springcloud;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.cloud.context.config.annotation.RefreshScope;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/refresh")
/**
 * RefreshScope 创建一个新的实例 注入到所有上下游的依赖当中
 */
@RefreshScope
public class RefreshController {

    @Value("${words}")
    private String words;

    @GetMapping("/words")
    public String getWords() {
        return words;
    }
}

```

![](https://tcs.teambition.net/storage/3121d01e8061d27d658b2da930adf4def09a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTYwMCwiaWF0IjoxNjEyMTkwODAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkMDFlODA2MWQyN2Q2NThiMmRhOTMwYWRmNGRlZjA5YSJ9.FamtCTaqBnRjeDiaMYI4apNZUO3oh9p1E-Ql3oYeKaI&download=image.png "")

```yaml
spring:
  application:
    name: config-client
  cloud:
    config:
      # 覆盖 上面的name 指定 git 远端 Repository
      name: config-consumer
      # 指向config server 的端口
      uri: http://localhost:60000
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

启动

![](https://tcs.teambition.net/storage/3121df23293fb876825eba7166ea8fab1e45?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTYwMCwiaWF0IjoxNjEyMTkwODAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkZjIzMjkzZmI4NzY4MjVlYmE3MTY2ZWE4ZmFiMWU0NSJ9.Xy6No4ZP3qHwO65Io-nuFpSUvJyGm00r4FL9lgpKhvk&download=image.png "")

![](https://tcs.teambition.net/storage/3121db8d243de29f8558f555352158f0b49a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTYwMCwiaWF0IjoxNjEyMTkwODAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkYjhkMjQzZGUyOWY4NTU4ZjU1NTM1MjE1OGYwYjQ5YSJ9.4JS1SjzXJj2w8TVJTFhMc6iYl39JiYNyG75cOfY5l0g&download=image.png "")

![](https://tcs.teambition.net/storage/3121f1194bc6c4c482c319bffa9507b14091?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTYwMCwiaWF0IjoxNjEyMTkwODAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmMTE5NGJjNmM0YzQ4MmMzMTliZmZhOTUwN2IxNDA5MSJ9.cL7Eb1_toErNOKQ54o53gm43sKOxhMACoqF2PcVInB4&download=image.png "")

![](https://tcs.teambition.net/storage/3121d6a93982e27dfea1f01b359ccbb6fa42?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTYwMCwiaWF0IjoxNjEyMTkwODAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkNmE5Mzk4MmUyN2RmZWExZjAxYjM1OWNjYmI2ZmE0MiJ9.4bHUI62H1fUNwKg8zpdUeMvqp7JqUXKU-AxE1Wo5Fbc&download=image.png "")

![](https://tcs.teambition.net/storage/312187bb092e7604ef43e911c0bfd795a598?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTYwMCwiaWF0IjoxNjEyMTkwODAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4N2JiMDkyZTc2MDRlZjQzZTkxMWMwYmZkNzk1YTU5OCJ9.kqb1UMy3-OHV3-SzG0ojFhcjQDhvXR4wB9C5uxJ0YEs&download=image.png "")

![](https://tcs.teambition.net/storage/31213f7d1a6291d00d938bd944c4ef9d363d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTYwMCwiaWF0IjoxNjEyMTkwODAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzZjdkMWE2MjkxZDAwZDkzOGJkOTQ0YzRlZjlkMzYzZCJ9.Zk_9GyuFqU6bZAgJslIsWSL0VZQc715QVW1eTYesQ6c&download=image.png "")

获取新的一份文件到本地了



![](https://tcs.teambition.net/storage/3121de3ff5691b568bb3309c8e5405f287cf?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTYwMCwiaWF0IjoxNjEyMTkwODAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkZTNmZjU2OTFiNTY4YmIzMzA5YzhlNTQwNWYyODdjZiJ9.ZA5H6ynpjAUHUgKf2S1840VQK6Y6fAE3HB3NaLB_bt0&download=image.png "")

![](https://tcs.teambition.net/storage/3121bdec859ddedd416b3adf706b0d422440?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTYwMCwiaWF0IjoxNjEyMTkwODAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiZGVjODU5ZGRlZGQ0MTZiM2FkZjcwNmIwZDQyMjQ0MCJ9.Ro29fShp3K_wfByxhlYmZbceUO0lf4JxmrYP7sEcAXs&download=image.png "")

```java
package com.imooc.springcloud;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.cloud.context.config.annotation.RefreshScope;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/refresh")
/**
 * RefreshScope 从Config 端 重新拉取新的文件 创建一个新的实例 注入到所有上下游的依赖当中
 */
@RefreshScope
public class RefreshController {

    @Value("${words}")
    private String words;

    @GetMapping("/words")
    public String getWords() {
        return words;
    }
}

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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTYwMCwiaWF0IjoxNjEyMTkwODAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.CcagZmJ8Be_P3mKM8JNMQkIZdhNOaZBMGZY8SSNlyKE&download=image.png "")

