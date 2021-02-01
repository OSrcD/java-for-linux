![](https://tcs.teambition.net/storage/31211e841998945896a867727bd815552f45?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTYxMSwiaWF0IjoxNjEyMTkwODExLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExZTg0MTk5ODk0NTg5NmE4Njc3MjdiZDgxNTU1MmY0NSJ9.-W6bz2lSI38drDW5QuNYr6Cjfpqfj3e_FiNxxv5C9kg&download=image.png "")

配置文件加载顺序

bootstrap.yml->application.yml->application.properties



![](https://tcs.teambition.net/storage/3121a20435fe57dfb90625838bf5f984dd7b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTYxMSwiaWF0IjoxNjEyMTkwODExLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhMjA0MzVmZTU3ZGZiOTA2MjU4MzhiZjVmOTg0ZGQ3YiJ9.QnqwZIkOlzWRt2S7aNMspnqw1XiAM3IwrUs0-pN0MlM&download=image.png "")

![](https://tcs.teambition.net/storage/31213beacf3c69904fede9f75c5afed44244?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTYxMSwiaWF0IjoxNjEyMTkwODExLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzYmVhY2YzYzY5OTA0ZmVkZTlmNzVjNWFmZWQ0NDI0NCJ9.-kDKqzb6KwTNGFg3UbD89Ptbk1gpVRoEtGTYWSZzYN4&download=image.png "")

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
    </dependencies>

</project>
```

![](https://tcs.teambition.net/storage/3121fbecb4228f7bcff834f1cdead8280ee5?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTYxMSwiaWF0IjoxNjEyMTkwODExLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmYmVjYjQyMjhmN2JjZmY4MzRmMWNkZWFkODI4MGVlNSJ9.sZ1JUUGDPGdVk7Ih0t8T1fn3Gle3yHIumhrdbZOYXls&download=image.png "")

```java
package com.imooc.springcloud;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class Controller {

    /**
     * 依赖注入
     * 这种直接从外部的文件夹加载
     */
    @Value("${name}")
    private String name;

    /**
     * 这种是首先把外部的属性注入到自己项目中的配置文件
     * 再从配置文件中注入
     */
    @Value("${myWords}")
    private String words;

    @GetMapping("/name")
    public String getName() {
        return name;
    }

    @GetMapping("/words")
    public String getWords() {
        return words;
    }

}

```

 

![](https://tcs.teambition.net/storage/312131d8fdd96820a2cd32d4ed8cd978dbf7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTYxMSwiaWF0IjoxNjEyMTkwODExLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzMWQ4ZmRkOTY4MjBhMmNkMzJkNGVkOGNkOTc4ZGJmNyJ9.Ovi-2z3DJ1PFdj5yASGXKUFH2d5mc2I7IFtUlEpd_z4&download=image.png "")

名字错误

![](https://tcs.teambition.net/storage/3121fd1645c90287ae8f539baa1856b28fb7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTYxMSwiaWF0IjoxNjEyMTkwODExLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmZDE2NDVjOTAyODdhZThmNTM5YmFhMTg1NmIyOGZiNyJ9.qpJb80yBJT8OdZiMFVgBO1ULNO6haqpCOMa2-rRE-Rc&download=image.png "")

![](https://tcs.teambition.net/storage/31219f01f0c67fbc51672ac2f171bff74d19?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTYxMSwiaWF0IjoxNjEyMTkwODExLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5ZjAxZjBjNjdmYmM1MTY3MmFjMmYxNzFiZmY3NGQxOSJ9.ej0yqDx9a5BpXbWSx8s1CN807SVJXpecTOOXkpN1Rqw&download=image.png "")

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


```

![](https://tcs.teambition.net/storage/31218b87107cd0604a418a5fcd8a1df2c664?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTYxMSwiaWF0IjoxNjEyMTkwODExLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4Yjg3MTA3Y2QwNjA0YTQxOGE1ZmNkOGExZGYyYzY2NCJ9.iNYs1Eoisl0M_WTeXT12TXQE_DAfnQ4to1Av28o4hTM&download=image.png "")

![](https://tcs.teambition.net/storage/3121fe992784c025574cc19f6d03018f3bef?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTYxMSwiaWF0IjoxNjEyMTkwODExLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmZTk5Mjc4NGMwMjU1NzRjYzE5ZjZkMDMwMThmM2JlZiJ9.tdofNUvH1tjJyvhDcTKl-NcICizTkLaWUlL0CiFVPKI&download=image.png "")

![](https://tcs.teambition.net/storage/31216f622450a8800c7cdcf4d2509ab603fb?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTYxMSwiaWF0IjoxNjEyMTkwODExLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2ZjYyMjQ1MGE4ODAwYzdjZGNmNGQyNTA5YWI2MDNmYiJ9.6DRBdF85YH1lyxs-0xB1JcIzjmvItKuKaQqnPjtJfok&download=image.png "")

![](https://tcs.teambition.net/storage/3121df782422f48c1ef9bda43d82bda0152d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTYxMSwiaWF0IjoxNjEyMTkwODExLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkZjc4MjQyMmY0OGMxZWY5YmRhNDNkODJiZGEwMTUyZCJ9.5DtD8QryVBTVIbd9_aLO8b19QcVZYSQlvUxZMrYJJ4I&download=image.png "")

![](https://tcs.teambition.net/storage/31217b7f469c51b8e9c133c014a90b77b8a0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTYxMSwiaWF0IjoxNjEyMTkwODExLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3YjdmNDY5YzUxYjhlOWMxMzNjMDE0YTkwYjc3YjhhMCJ9.ex7TMBJcMkfkQROootE_wdBqZyFYAIAVuUm7UgbjK0M&download=image.png "")



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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTYxMSwiaWF0IjoxNjEyMTkwODExLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.RiXd_UEun_08ZOoCgFYu6IJifnAP3skENzhB5gwd4SQ&download=image.png "")

