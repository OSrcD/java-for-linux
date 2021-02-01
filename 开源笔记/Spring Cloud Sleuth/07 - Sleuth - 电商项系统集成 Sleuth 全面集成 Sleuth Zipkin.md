![](https://tcs.teambition.net/storage/3122620e0dfe46ba5008c8a79cad752bec1d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI2MjBlMGRmZTQ2YmE1MDA4YzhhNzljYWQ3NTJiZWMxZCJ9.qz586YkPd51hVk8yZ6I_8am0MksglRLVcM1c196GPx4&download=image.png "")



```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <parent>
        <artifactId>foodie-cloud</artifactId>
        <groupId>com.imooc</groupId>
        <version>1.0-SNAPSHOT</version>
        <relativePath>../../../pom.xml</relativePath>
    </parent>
    <modelVersion>4.0.0</modelVersion>

    <artifactId>foodie-auth-service</artifactId>

    <dependencies>
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-web</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-client</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-actuator</artifactId>
        </dependency>

        <!-- redis -->
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-data-redis</artifactId>
        </dependency>

        <!-- jwt -->
        <dependency>
            <groupId>com.auth0</groupId>
            <artifactId>java-jwt</artifactId>
            <version>3.7.0</version>
        </dependency>

        <dependency>
            <groupId>com.imooc</groupId>
            <artifactId>foodie-auth-api</artifactId>
            <version>${project.version}</version>
        </dependency>

        <!-- 链路追踪 -->
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-sleuth</artifactId>
        </dependency>
        <!-- Zipkin -->
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-zipkin</artifactId>
        </dependency>

    </dependencies>

    <build>
        <plugins>
            <plugin>
                <groupId>org.springframework.boot</groupId>
                <artifactId>spring-boot-maven-plugin</artifactId>
                <configuration>
                    <mainClass>com.imooc.auth.service.impl.AuthApplication</mainClass>
                </configuration>
                <executions>
                    <execution>
                        <goals>
                            <goal>repackage</goal>
                        </goals>
                    </execution>
                </executions>
            </plugin>
        </plugins>
    </build>

</project>
```



如何查找配置信息

![](https://tcs.teambition.net/storage/3122963d18ea3207f9bcb45c381c9f0b1c7c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5NjNkMThlYTMyMDdmOWJjYjQ1YzM4MWM5ZjBiMWM3YyJ9.PZUyhBsXjshCOxi66tcWFyVdSVDi32H8QtOfMM0lBoI&download=image.png "")

![](https://tcs.teambition.net/storage/3122e97317ee5613b553cc8487e122f11720?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJlOTczMTdlZTU2MTNiNTUzY2M4NDg3ZTEyMmYxMTcyMCJ9.5i2oSVlnZG98huJ9KYEehecOH-GUk21BMV4tMMrRqYo&download=image.png "")

![](https://tcs.teambition.net/storage/3122852663eb867c57a85469ffad7e684e70?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI4NTI2NjNlYjg2N2M1N2E4NTQ2OWZmYWQ3ZTY4NGU3MCJ9.lpZuuRhCjeAdk9vNH_1nEs6Y7Kf67lP4-6tVqjvOeqI&download=image.png "")

![](https://tcs.teambition.net/storage/31228b8dcedd968d85b1a9d8fdf4c3f334c5?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI4YjhkY2VkZDk2OGQ4NWIxYTlkOGZkZjRjM2YzMzRjNSJ9.Fogvu8h5aR3J7mjPFeagNxJhp00bs8u_XQDngai9sN8&download=image.png "")

![](https://tcs.teambition.net/storage/3122289882227461f930eec390bf1a68800f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIyODk4ODIyMjc0NjFmOTMwZWVjMzkwYmYxYTY4ODAwZiJ9.F5ygoA9QL_ienx5z-AHD820HnjG2nOXYcltX6YLazOA&download=image.png "")

![](https://tcs.teambition.net/storage/31221d9ca464d7caa61c9bf8ef11bc1fccb0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxZDljYTQ2NGQ3Y2FhNjFjOWJmOGVmMTFiYzFmY2NiMCJ9.TrHTMbWh7n-KzQIT7xpPu0iaGEqYKpEYUTgBz5L_yKc&download=image.png "")

```yaml
server:
  port: 10006

spring:
  application:
    name: foodie-auth-service
  redis:
    database: 0
    host: 192.168.245.138
    port: 6379
    password: imooc
  zipkin:
    # 基于服务发现的机制
    discoveryClientEnabled: true
    # 基于高可用
    base-url: http://ZIPKIN-SERVER/
    # 关闭 zipkin
#    enabled: false
    # 模仿配置
    locator:
      discovery:
        # 通过服务发现 定位 它的 hostname
        enabled: true
  sleuth:
    sampler:
      probability: 1

eureka:
  client:
    serviceUrl:
      defaultZone: http://localhost:20000/eureka/

management:
  endpoint:
    health:
      show-details: always
  endpoints:
    web:
      exposure:
        include: '*'
  security:
    user:
      name: gitee
      password: gitee
      roles: ADMIN


```

启动

![](https://tcs.teambition.net/storage/3122b050b9c65008c914ecda4037a044b592?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJiMDUwYjljNjUwMDhjOTE0ZWNkYTQwMzdhMDQ0YjU5MiJ9.FpAPSa7-Wp44wIVwu3kTyfRjGqxLsTIXijedJLWnAEQ&download=image.png "")

![](https://tcs.teambition.net/storage/312297b8d4ed632a981eb87156b62b69ee2b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5N2I4ZDRlZDYzMmE5ODFlYjg3MTU2YjYyYjY5ZWUyYiJ9.I5t8ie0F8_tM7otqQWsuLrtwDQPNVTTKZsSPFofL69Y&download=image.png "")

配置网关

![](https://tcs.teambition.net/storage/3122618368a23e01ce1cad9537289c9d5c94?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI2MTgzNjhhMjNlMDFjZTFjYWQ5NTM3Mjg5YzlkNWM5NCJ9.ix5HXxDBbn_SjDyAVyFjTZBrDx8cimp3-32fwLDGizA&download=image.png "")



```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <parent>
        <artifactId>foodie-cloud</artifactId>
        <groupId>com.imooc</groupId>
        <version>1.0-SNAPSHOT</version>
        <relativePath>../../pom.xml</relativePath>
    </parent>
    <modelVersion>4.0.0</modelVersion>

    <artifactId>gateway</artifactId>

    <dependencies>
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-gateway</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-client</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-actuator</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-data-redis-reactive</artifactId>
        </dependency>

        <!-- 因为spring cloud gateway是基于webflux的，
        如果非要web支持的话需要导入spring-boot-starter-webflux而不是spring-boot-start-web-->
        <dependency>
            <groupId>com.imooc</groupId>
            <artifactId>foodie-auth-api</artifactId>
            <version>${project.version}</version>
            <exclusions>
                <exclusion>
                    <groupId>org.springframework.boot</groupId>
                    <artifactId>spring-boot-starter-web</artifactId>
                </exclusion>
            </exclusions>
        </dependency>

        <!-- 链路追踪 -->
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-sleuth</artifactId>
        </dependency>
        <!-- Zipkin -->
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-zipkin</artifactId>
        </dependency>
    </dependencies>

    <build>
        <plugins>
            <plugin>
                <groupId>org.springframework.boot</groupId>
                <artifactId>spring-boot-maven-plugin</artifactId>
                <configuration>
                    <mainClass>com.imooc.GatewayApplication</mainClass>
                </configuration>
                <executions>
                    <execution>
                        <goals>
                            <goal>repackage</goal>
                        </goals>
                    </execution>
                </executions>
            </plugin>
        </plugins>
    </build>

</project>
```

![](https://tcs.teambition.net/storage/3122d126037e212b528a852553563d6d92e7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkMTI2MDM3ZTIxMmI1MjhhODUyNTUzNTYzZDZkOTJlNyJ9.nbgyrQTtSAJ6RfSiTWnI-qo5gCHxI78fTXeA104Xsuk&download=image.png "")

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
  # 链路追踪
  zipkin:
    # 基于服务发现的机制
    discoveryClientEnabled: true
    # 基于高可用
    base-url: http://ZIPKIN-SERVER/
    # 关闭 zipkin
    #    enabled: false
    # 模仿配置
    locator:
      discovery:
        # 通过服务发现 定位 它的 hostname
        enabled: true
  sleuth:
    sampler:
      probability: 1
  # 跨域配置
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

配置用户微服务

![](https://tcs.teambition.net/storage/3122a748f81e02a6eec520bab64a97643fe6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhNzQ4ZjgxZTAyYTZlZWM1MjBiYWI2NGE5NzY0M2ZlNiJ9.Lu7jmqcfUZ-fv6oSFY_VNQHVrIjGMnsZ8Pmg3_I2Xr4&download=image.png "")

```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <parent>
        <artifactId>foodie-cloud</artifactId>
        <groupId>com.imooc</groupId>
        <version>1.0-SNAPSHOT</version>
        <relativePath>../../../pom.xml</relativePath>
    </parent>
    <modelVersion>4.0.0</modelVersion>

    <artifactId>foodie-user-web</artifactId>

    <dependencies>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-user-service</artifactId>
            <version>${project.version}</version>
        </dependency>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-cloud-web-components</artifactId>
            <version>${project.version}</version>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-client</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-config</artifactId>
        </dependency>

        <dependency>
            <groupId>com.imooc</groupId>
            <artifactId>foodie-auth-api</artifactId>
            <version>${project.version}</version>
        </dependency>

        <!-- 链路追踪 -->
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-sleuth</artifactId>
        </dependency>
        <!-- Zipkin -->
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-zipkin</artifactId>
        </dependency>
    </dependencies>

    <build>
        <plugins>
            <plugin>
                <groupId>org.springframework.boot</groupId>
                <artifactId>spring-boot-maven-plugin</artifactId>
                <configuration>
                    <mainClass>com.imooc.user.UserApplication</mainClass>
                </configuration>
                <executions>
                    <execution>
                        <goals>
                            <goal>repackage</goal>
                        </goals>
                    </execution>
                </executions>
            </plugin>
        </plugins>
    </build>

</project>
```

坑

集成Bus 推送以后 我们配置中心 不用做多余的配置 你只用 在自己的这个启动文件当中 配置好rabbitmq连接串就可以自动使用Bus 组件来推送 是不是非常的智能 



新增加的

![](https://tcs.teambition.net/storage/312249f24259de7916485721489ba5da3003?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI0OWYyNDI1OWRlNzkxNjQ4NTcyMTQ4OWJhNWRhMzAwMyJ9.pYBIYa8PnvCSkAz9RH1TBXd3kDL_ftV9A8s92nP3jhg&download=image.png "")

这个也是新增加的

![](https://tcs.teambition.net/storage/312251e5d3e50fec0b91284891ef9d247499?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI1MWU1ZDNlNTBmZWMwYjkxMjg0ODkxZWY5ZDI0NzQ5OSJ9.6y5I_msKQMpNnuU2I3HZ8OiKzoe7qFVDc7PwVLMejdE&download=image.png "")

这里多引入了rabbitmq 的依赖

zipkin 会变成 推送方式为rabbitmq

![](https://tcs.teambition.net/storage/3122a6ac003fafc6f4fc86bf30b4307e1e15?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhNmFjMDAzZmFmYzZmNGZjODZiZjMwYjQzMDdlMWUxNSJ9.Pbo8oP83FcyqGek4CmC3smL0UH5GvHQQe8CECap_r_Q&download=image.png "")

![](https://tcs.teambition.net/storage/3122954416ff1f8d9484f3d552afac7ac84e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5NTQ0MTZmZjFmOGQ5NDg0ZjNkNTUyYWZhYzdhYzg0ZSJ9.Ca3h8lDFq1YVIWzY1E0ZamyURT7l6dNMK51kDBnAJt8&download=image.png "")

```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <parent>
        <artifactId>foodie-cloud</artifactId>
        <groupId>com.imooc</groupId>
        <version>1.0-SNAPSHOT</version>
        <relativePath>../../../pom.xml</relativePath>
    </parent>
    <modelVersion>4.0.0</modelVersion>

    <artifactId>foodie-user-web</artifactId>

    <dependencies>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-user-service</artifactId>
            <version>${project.version}</version>
        </dependency>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-cloud-web-components</artifactId>
            <version>${project.version}</version>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-client</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-config</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-bus-amqp</artifactId>
        </dependency>

        <dependency>
            <groupId>com.imooc</groupId>
            <artifactId>foodie-auth-api</artifactId>
            <version>${project.version}</version>
        </dependency>

        <!-- 链路追踪 -->
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-sleuth</artifactId>
        </dependency>
        <!-- Zipkin -->
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-zipkin</artifactId>
        </dependency>
    </dependencies>

    <build>
        <plugins>
            <plugin>
                <groupId>org.springframework.boot</groupId>
                <artifactId>spring-boot-maven-plugin</artifactId>
                <configuration>
                    <mainClass>com.imooc.user.UserApplication</mainClass>
                </configuration>
                <executions>
                    <execution>
                        <goals>
                            <goal>repackage</goal>
                        </goals>
                    </execution>
                </executions>
            </plugin>
        </plugins>
    </build>

</project>
```

```yaml
server:
  port: 10002

spring:
  datasource:                                           # 数据源的相关配置
    # 拆分数据源到独立database instance，或者独立schema
#    url: jdbc:mysql://localhost:3306/foodie-cloud-item?useUnicode=true&characterEncoding=UTF-8&autoReconnect=true
#    url: jdbc:mysql://localhost:3306/foodie-shop-dev?useUnicode=true&characterEncoding=UTF-8&autoReconnect=true
#    password: SocialPG
    url: ${mariadb.url}
    password: ${mariadb.password}
  redis:
    # Redis 单机单实例
    database: 0
#    host: localhost
    host: 192.168.245.138
    port: 6379
    password: imooc
    # Redis 哨兵模式
#    database: 1
#    password: imooc
#    sentinel:
#      master: imooc-master
#      nodes: 192.168.245.138:26379,192.168.245.139:26379,192.168.245.140:26379
#    password: imooc
#    cluster:
#      nodes: 192.168.245.141:6379,192.168.245.142:6379,192.168.245.143:6379,192.168.245.144:6379,192.168.245.145:6379,192.168.245.146:6379
  #
  zipkin:
    # 基于服务发现的机制
    discoveryClientEnabled: true
    # 基于高可用
    base-url: http://ZIPKIN-SERVER/
    # 关闭 zipkin
    #    enabled: false
    # 模仿配置
    locator:
      discovery:
        # 通过服务发现 定位 它的 hostname
        enabled: true
      # 以Http方式上传数据到zipkin
      # WHY？ bus依赖项会导入rabbitmq的依赖项，zipkin会默认使用mq
    sender:
      type: web
  sleuth:
    sampler:
      probability: 1
    ### 推送变更的时候用
  rabbitmq:
    host: localhost
    port: 5672
    username: guest
    password: guest
mybatis:
  configuration:
    log-impl: org.apache.ibatis.logging.stdout.StdOutImpl

## 开启所有actuator-endpoint
# 第一步去配置中心 拉取这些属性 自动的加载到上下文当中 是有一样的key
# 我们这里可以直接把它删掉
#management:
#  endpoint:
#    health:
#      show-details: always
#  endpoints:
#    web:
#      exposure:
#        include: '*'
#  security:
#    user:
#      name: gitee
#      password: gitee
#      roles: ADMIN

hystrix:
  command:
    # 有的属性是默认值，写不写都行
    default:
      fallback:
        enabled: true
      circuitBreaker:
        enabled: true
        # 超过50%错误，那么开启熔断
        errorThresholdPercentage: 50
        # 5个request之后才进行统计
        requestVolumeThreshold: 5
        # 10秒之后进入半开状态
        sleepWindowInMilliseconds: 10000
        # forceClosed, forceOpen 强制关闭/开启熔断开关
      execution:
        timeout:
          enabled: true
        # 可以指定隔离方式是线程池还是信号量
        isolation:
          thread:
            interruptOnTimeout: true
            interruptOnFutureCancel: true
            timeoutInMilliseconds: 10000
      metrics:
        rollingStats:
          # 时间窗口统计
          timeInMilliseconds: 20000
          # numBuckets: 10
    #        rollingPercentile:
    #          # 时间窗口统计
    #          timeInMilliseconds: 20000
    #          # numBuckets: 10
    #          bucketSize: 300
    # 照这个方法，覆盖其他的属性
    loginFail:
      execution:
        isolation:
          thread:
            timeoutInMilliseconds: 3000

```

启动 配置中心

![](https://tcs.teambition.net/storage/3122fca5bd0e78c3bf580190336e8e69f977?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJmY2E1YmQwZTc4YzNiZjU4MDE5MDMzNmU4ZTY5Zjk3NyJ9.UC0_5bs9s9TYoCGavWKkKq2AhSlKCpVzsRz_TTmM5Y4&download=image.png "")

启动MQ

![](https://tcs.teambition.net/storage/3122ba74389f2461e446f821214e871ebb3a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJiYTc0Mzg5ZjI0NjFlNDQ2ZjgyMTIxNGU4NzFlYmIzYSJ9.n_7FW2BITaKsutUFhkGd6Q7ApAOtWTz1L1qyAMXPG2Q&download=image.png "")

```text
# 启动
cd /usr/local/Cellar/rabbitmq/3.8.3
./sbin/rabbitmq-server
# 访问
http://localhost:15672
```

![](https://tcs.teambition.net/storage/312213f1bcf99c21907ffd12f91b613d6bd5?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxM2YxYmNmOTljMjE5MDdmZmQxMmY5MWI2MTNkNmJkNSJ9.xEkAL7F9VfDl-7Tlx5IcCBXJYupB_6YPScTguAYla9k&download=image.png "")

启动用户微服务

![](https://tcs.teambition.net/storage/3122baa4be0c5f2fe349c42442582904a5c1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJiYWE0YmUwYzVmMmZlMzQ5YzQyNDQyNTgyOTA0YTVjMSJ9.LwYhmN35HDu_h8hWK5SdN7JZkc1oTBdmFzNEhv0Jx9U&download=image.png "")



启动网关

![](https://tcs.teambition.net/storage/3122d7e29164c270ccda8fc87465d4445bf4?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkN2UyOTE2NGMyNzBjY2RhOGZjODc0NjVkNDQ0NWJmNCJ9.Wn6alFzW4ujk4_1y4byp-f1oNFwzQY6KF4OXWwOqbNk&download=image.png "")

![](https://tcs.teambition.net/storage/31228f5f9e4883de65e939e47d7316f55f5f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI4ZjVmOWU0ODgzZGU2NWU5MzllNDdkNzMxNmY1NWY1ZiJ9.YfqATDy1VOceLoIRRvSwfm6Nlj7_0ebyEGDIY4S-Ecs&download=image.png "")

启动 redis

![](https://tcs.teambition.net/storage/3122f33ad53b4860b489f48fa58a2e7e6c32?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJmMzNhZDUzYjQ4NjBiNDg5ZjQ4ZmE1OGEyZTdlNmMzMiJ9.eLPMzjYpWXugx4juvDCuFjYj4hy5LUy1b39TyF3ogW0&download=image.png "")

![](https://tcs.teambition.net/storage/312286ab5d996352500a96151575c977da23?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI4NmFiNWQ5OTYzNTI1MDBhOTYxNTE1NzVjOTc3ZGEyMyJ9._qJ44mxbh4l2shmvp4QywZnNwDk4rD1MLyrcX7VEzzE&download=image.png "")

![](https://tcs.teambition.net/storage/3122c3c3755a5efb7cea860d18355e4040c9?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJjM2MzNzU1YTVlZmI3Y2VhODYwZDE4MzU1ZTQwNDBjOSJ9.B1D5U_FeD5z6_FOKypOOrdQq6Z83LTGGDU3w5CMlcyQ&download=image.png "")

![](https://tcs.teambition.net/storage/31220ebb9e7dffc9e27d0f2fcfd6b44eefe7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIwZWJiOWU3ZGZmYzllMjdkMGYyZmNmZDZiNDRlZWZlNyJ9.vvIZMS6piEGwThrn-4J5rqJBqsbtfhB_5goeDPrcz4o&download=image.png "")

![](https://tcs.teambition.net/storage/3122f6d8c69cc8a409da26eee58ceb83dc4d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJmNmQ4YzY5Y2M4YTQwOWRhMjZlZWU1OGNlYjgzZGM0ZCJ9.JsBtSRoZJNP3FuULlP780YOpKZiPGNRe9MUHmvwK0GA&download=image.png "")

```json
{
    "status": 200,
    "msg": "OK",
    "data": {
        "id": "210129DS8FH0S0DP",
        "username": "banxian",
        "password": null,
        "nickname": "banxian",
        "realname": null,
        "face": "http://122.152.205.72:88/group1/M00/00/05/CpoxxFw_8_qAIlFXAAAcIhVPdSg994.png",
        "mobile": null,
        "email": null,
        "sex": 2,
        "birthday": null,
        "createdTime": null,
        "updatedTime": null
    }
}

```

![](https://tcs.teambition.net/storage/31228a8b4e6b068ac622dc96c8d146e98a2a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI4YThiNGU2YjA2OGFjNjIyZGM5NmM4ZDE0NmU5OGEyYSJ9.kXUgwHTqi-FAbjS9NAxzfFFdVSltQ44KaUU15do24ZQ&download=image.png "")

```text
Authorization

eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJ5YW8iLCJleHAiOjE2MTIwNzU3NDMsImlhdCI6MTYxMTk4OTM0MywidXNlcmlkIjoiMjEwMTI5RFM4RkgwUzBEUCJ9.QdvFOUZBxuLTmNuLp6HKycR1GIDD594OQuGR1Ft-w0M

```

![](https://tcs.teambition.net/storage/3122b38453da29400932e767dbc36a77faf6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJiMzg0NTNkYTI5NDAwOTMyZTc2N2RiYzM2YTc3ZmFmNiJ9.bMxBIz9h8PXSqn_TEpepf0-MVOo9zlR5l7G-6fxNOAQ&download=image.png "")

![](https://tcs.teambition.net/storage/3122624ab2a86648e784a99ba0023d8ae3e7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI2MjRhYjJhODY2NDhlNzg0YTk5YmEwMDIzZDhhZTNlNyJ9._7qdk5I8UnnujWindCo3xASZYsmifPyHWRBBd_TEKOM&download=image.png "")

![](https://tcs.teambition.net/storage/31222e1e0efe54720c39a3f69ab015ea8ee7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIyZTFlMGVmZTU0NzIwYzM5YTNmNjlhYjAxNWVhOGVlNyJ9.1MzB5f9t1fsv6iztLgl88pKpeVVzE0-4rxGrYXqEdhw&download=image.png "")

![](https://tcs.teambition.net/storage/31221e2c753ca29965a08998d3a8b9c7fb92?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxZTJjNzUzY2EyOTk2NWEwODk5OGQzYThiOWM3ZmI5MiJ9.t1HUJOMWhIRSZ4bew0lRTT3IfGw24eCk58pprKP2GP8&download=image.png "")

![](https://tcs.teambition.net/storage/312215fbf5d3be871fa45a133df5a738378d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxNWZiZjVkM2JlODcxZmE0NWExMzNkZjVhNzM4Mzc4ZCJ9.mIHposYIhZW8eslkc6U5JPVp6SCGtHbWu_majje1eFQ&download=image.png "")

![](https://tcs.teambition.net/storage/3122334174d22e1fddb8e5f03202dd51d8fe?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzMzQxNzRkMjJlMWZkZGI4ZTVmMDMyMDJkZDUxZDhmZSJ9.ir6TJMjbyu39K9-lJ29PVFrObopzJT_fFM3Au6hINsU&download=image.png "")

![](https://tcs.teambition.net/storage/3122c1f46b45a53e481dfe91bb950d58616c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJjMWY0NmI0NWE1M2U0ODFkZmU5MWJiOTUwZDU4NjE2YyJ9.3_ePmeKgun_K-kBcvpemCjqBcF10Q9zaSpO-FmqvktU&download=image.png "")

![](https://tcs.teambition.net/storage/312293f7ba90476e53cd8356a26e1a4a70ec?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5M2Y3YmE5MDQ3NmU1M2NkODM1NmEyNmUxYTRhNzBlYyJ9.VWCTXazjBtK513CR_dtZNQdQgAQSNUxO6NU8HlhZqEs&download=image.png "")

![](https://tcs.teambition.net/storage/312228f6af84e9a8ec0c71f15a1d7d4d7fc7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIyOGY2YWY4NGU5YThlYzBjNzFmMTVhMWQ3ZDRkN2ZjNyJ9.t1GaYlDWFdYA90tAi-2F6kuccTJxAszdwsxhMNPfA3A&download=image.png "")

```xml
<?xml version="1.0" encoding="UTF-8" ?>
<configuration>
    <appender name="consoleLog" class="ch.qos.logback.core.ConsoleAppender">
        <filter class="ch.qos.logback.classic.filter.ThresholdFilter">
            <level>INFO</level>
        </filter>
        <layout class="ch.qos.logback.classic.PatternLayout">
            <pattern>
                [%d{HH:mm:ss.SSS}] %-5level %logger{15} - %msg%n
            </pattern>
        </layout>
    </appender>

    <appender name="fileLog" class="ch.qos.logback.core.rolling.RollingFileAppender">
        <encoder>
            <pattern>
                [%d{HH:mm:ss.SSS}] %-5level [%thread]%logger{15} - %msg%n
            </pattern>
        </encoder>
        <rollingPolicy class="ch.qos.logback.core.rolling.TimeBasedRollingPolicy">
            <fileNamePattern>logs/%d.log</fileNamePattern>
            <maxHistory>30</maxHistory>
        </rollingPolicy>
    </appender>
    <root level="DEBUG">
        <appender-ref ref = "consoleLog"/>
        <appender-ref ref = "fileLog"/>
    </root>
</configuration>
```

![](https://tcs.teambition.net/storage/312212e00e93ec56d48e55355266de51238d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxMmUwMGU5M2VjNTZkNDhlNTUzNTUyNjZkZTUxMjM4ZCJ9.7_ItmBpvrDuoypRHAErAinzLI5Uzw9KYOOsnnOpkSas&download=image.png "")

cart item order 模块已经集成 sleuth

![](https://tcs.teambition.net/storage/312241e5d48660f37ef8423557f2a70ab4b0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI0MWU1ZDQ4NjYwZjM3ZWY4NDIzNTU3ZjJhNzBhYjRiMCJ9.JDFcExs28iqjUZB6TRIl0cWAqbwOR0PHliPQ5IQJdgQ&download=image.png "")

![](https://tcs.teambition.net/storage/3122c763b3a8ab813b98e1cb96a21a63188a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJjNzYzYjNhOGFiODEzYjk4ZTFjYjk2YTIxYTYzMTg4YSJ9.IRfrN0agtWvZ5PmXgXdElsnptsxqUzep48EMt3flwG0&download=image.png "")



![](https://tcs.teambition.net/storage/31226c3659a5355d71508b1d13e97cd03001?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI2YzM2NTlhNTM1NWQ3MTUwOGIxZDEzZTk3Y2QwMzAwMSJ9.CcrVK2aF9ljpNHKSvrDv5u4t3M-23RgHNmtQmGifjYk&download=image.png "")

```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <parent>
        <artifactId>foodie-cloud</artifactId>
        <groupId>com.imooc</groupId>
        <version>1.0-SNAPSHOT</version>
        <relativePath>../../../pom.xml</relativePath>
    </parent>
    <modelVersion>4.0.0</modelVersion>

    <artifactId>foodie-cart-web</artifactId>

    <dependencies>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-cart-service</artifactId>
            <version>${project.version}</version>
        </dependency>

        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-cloud-common</artifactId>
            <version>${project.version}</version>
        </dependency>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-cloud-web-components</artifactId>
            <version>${project.version}</version>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-client</artifactId>
        </dependency>

        <!-- 链路追踪 -->
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-sleuth</artifactId>
        </dependency>
        <!-- Zipkin -->
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-zipkin</artifactId>
        </dependency>
    </dependencies>

    <build>
        <plugins>
            <plugin>
                <groupId>org.springframework.boot</groupId>
                <artifactId>spring-boot-maven-plugin</artifactId>
                <configuration>
                    <mainClass>com.imooc.cart.CartApplication</mainClass>
                </configuration>
                <executions>
                    <execution>
                        <goals>
                            <goal>repackage</goal>
                        </goals>
                    </execution>
                </executions>
            </plugin>
        </plugins>
    </build>

</project>
```

![](https://tcs.teambition.net/storage/3122d40ec82cb37bed3a2270adebe00dbe8c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkNDBlYzgyY2IzN2JlZDNhMjI3MGFkZWJlMDBkYmU4YyJ9.zwG4c8VuI_q233OgNCeEPcgrzsNR0Sxcw7LEtvR5RXc&download=image.png "")

```yaml
server:
  port: 10004

spring:
  datasource:                                           # 数据源的相关配置
    # 拆分数据源到独立database instance，或者独立schema
#    url: jdbc:mysql://localhost:3306/foodie-cloud-item?useUnicode=true&characterEncoding=UTF-8&autoReconnect=true
    url: jdbc:mysql://localhost:3306/foodie-shop-dev?useUnicode=true&characterEncoding=UTF-8&autoReconnect=true
    password: SocialPG
  redis:
    # Redis 单机单实例
    database: 0
    host: 192.168.245.138
    port: 6379
    password: imooc
    # Redis 哨兵模式
#    database: 1
#    password: imooc
#    sentinel:
#      master: imooc-master
#      nodes: 192.168.245.138:26379,192.168.245.139:26379,192.168.245.140:26379
#    password: imooc
#    cluster:
#      nodes: 192.168.245.141:6379,192.168.245.142:6379,192.168.245.143:6379,192.168.245.144:6379,192.168.245.145:6379,192.168.245.146:6379
  zipkin:
    # 基于服务发现的机制
    discoveryClientEnabled: true
    # 基于高可用
    base-url: http://ZIPKIN-SERVER/
    # 关闭 zipkin
    #    enabled: false
    # 模仿配置
    locator:
      discovery:
        # 通过服务发现 定位 它的 hostname
        enabled: true
  sleuth:
    sampler:
      probability: 1

mybatis:
  configuration:
    log-impl: org.apache.ibatis.logging.stdout.StdOutImpl


```

![](https://tcs.teambition.net/storage/3122f503da12436a9390ae0d5bba053a21a7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJmNTAzZGExMjQzNmE5MzkwYWUwZDViYmEwNTNhMjFhNyJ9.qKSn7pHkZDlCHd4CpxRxtyS1ZK-wi6C-c_J_w3kvfBc&download=image.png "")

```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <parent>
        <artifactId>foodie-cloud</artifactId>
        <groupId>com.imooc</groupId>
        <version>1.0-SNAPSHOT</version>
        <relativePath>../../../pom.xml</relativePath>
    </parent>
    <modelVersion>4.0.0</modelVersion>

    <artifactId>foodie-item-web</artifactId>

    <dependencies>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-item-service</artifactId>
            <version>${project.version}</version>
        </dependency>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-cloud-web-components</artifactId>
            <version>${project.version}</version>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-client</artifactId>
        </dependency>

        <!-- 链路追踪 -->
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-sleuth</artifactId>
        </dependency>
        <!-- Zipkin -->
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-zipkin</artifactId>
        </dependency>

    </dependencies>

    <build>
        <plugins>
            <plugin>
                <groupId>org.springframework.boot</groupId>
                <artifactId>spring-boot-maven-plugin</artifactId>
                <configuration>
                    <mainClass>com.imooc.item.ItemApplication</mainClass>
                </configuration>
                <executions>
                    <execution>
                        <goals>
                            <goal>repackage</goal>
                        </goals>
                    </execution>
                </executions>
            </plugin>
        </plugins>
    </build>

</project>
```

![](https://tcs.teambition.net/storage/3122da586d86cec661a976fd81d55fa32d96?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkYTU4NmQ4NmNlYzY2MWE5NzZmZDgxZDU1ZmEzMmQ5NiJ9.32mQIQ3dHgnu1r1fHgl-txq1FaRvu3VXpBB-60kpx8o&download=image.png "")

```yaml
server:
  port: 10001

spring:
  datasource:                                           # 数据源的相关配置
    # 拆分数据源到独立database instance，或者独立schema
#    url: jdbc:mysql://localhost:3306/foodie-cloud-item?useUnicode=true&characterEncoding=UTF-8&autoReconnect=true
    url: jdbc:mysql://localhost:3306/foodie-shop-dev?useUnicode=true&characterEncoding=UTF-8&autoReconnect=true
    password: SocialPG
  redis:
    # Redis 单机单实例
    database: 0
    host: 192.168.245.138
    port: 6379
    password: imooc
    # Redis 哨兵模式
#    database: 1
#    password: imooc
#    sentinel:
#      master: imooc-master
#      nodes: 192.168.245.138:26379,192.168.245.139:26379,192.168.245.140:26379
#    password: imooc
#    cluster:
#      nodes: 192.168.245.141:6379,192.168.245.142:6379,192.168.245.143:6379,192.168.245.144:6379,192.168.245.145:6379,192.168.245.146:6379
  zipkin:
    # 基于服务发现的机制
    discoveryClientEnabled: true
    # 基于高可用
    base-url: http://ZIPKIN-SERVER/
    # 关闭 zipkin
    #    enabled: false
    # 模仿配置
    locator:
      discovery:
        # 通过服务发现 定位 它的 hostname
        enabled: true
  sleuth:
    sampler:
      probability: 1

mybatis:
  configuration:
    log-impl: org.apache.ibatis.logging.stdout.StdOutImpl


## 开启所有actuator-endpoint
management:
  endpoint:
    health:
      show-details: always
  endpoints:
    web:
      exposure:
        include: '*'
  #        include: health,info,xxx
  security:
    user:
      name: gitee
      password: gitee
      roles: ADMIN
```

![](https://tcs.teambition.net/storage/3122edd7bfd370af599c95afafa04cfae10b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJlZGQ3YmZkMzcwYWY1OTljOTVhZmFmYTA0Y2ZhZTEwYiJ9.bHW5o-Y9IRfQleqIkNLNpufqlV81ETCNtrMpeRHmkfs&download=image.png "")

```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <parent>
        <artifactId>foodie-cloud</artifactId>
        <groupId>com.imooc</groupId>
        <version>1.0-SNAPSHOT</version>
        <relativePath>../../../pom.xml</relativePath>
    </parent>
    <modelVersion>4.0.0</modelVersion>

    <artifactId>foodie-order-web</artifactId>

    <dependencies>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-order-service</artifactId>
            <version>${project.version}</version>
        </dependency>

        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-cloud-web-components</artifactId>
            <version>${project.version}</version>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-client</artifactId>
        </dependency>

        <!-- 链路追踪 -->
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-sleuth</artifactId>
        </dependency>
        <!-- Zipkin -->
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-zipkin</artifactId>
        </dependency>
    </dependencies>

    <build>
        <!-- 打成jar包后，用java -jar -xxx.jar 的命令启动项目 -->
        <plugins>
            <plugin>
                <groupId>org.springframework.boot</groupId>
                <artifactId>spring-boot-maven-plugin</artifactId>
                <configuration>
                    <mainClass>com.imooc.order.OrderApplication</mainClass>
                </configuration>
                <executions>
                    <execution>
                        <goals>
                            <goal>repackage</goal>
                        </goals>
                    </execution>
                </executions>
            </plugin>

        </plugins>
    </build>

</project>
```

![](https://tcs.teambition.net/storage/31223cec38bb8a66e7db1fe01308a7377e8b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzY2VjMzhiYjhhNjZlN2RiMWZlMDEzMDhhNzM3N2U4YiJ9.ZlwRUjLA43UZUebo228RZUgj0CKmQfKwQpV5gzik2hU&download=image.png "")

```yaml
server:
  port: 10003

spring:
  datasource:                                           # 数据源的相关配置
    # 拆分数据源到独立database instance，或者独立schema
#    url: jdbc:mysql://localhost:3306/foodie-cloud-item?useUnicode=true&characterEncoding=UTF-8&autoReconnect=true
    url: jdbc:mysql://localhost:3306/foodie-shop-dev?useUnicode=true&characterEncoding=UTF-8&autoReconnect=true
    password: SocialPG
  redis:
    # Redis 单机单实例
    database: 0
    host: 192.168.245.138
    port: 6379
    password: imooc
    # Redis 哨兵模式
#    database: 1
#    password: imooc
#    sentinel:
#      master: imooc-master
#      nodes: 192.168.245.138:26379,192.168.245.139:26379,192.168.245.140:26379
#    password: imooc
#    cluster:
#      nodes: 192.168.245.141:6379,192.168.245.142:6379,192.168.245.143:6379,192.168.245.144:6379,192.168.245.145:6379,192.168.245.146:6379
  zipkin:
    # 基于服务发现的机制
    discoveryClientEnabled: true
    # 基于高可用
    base-url: http://ZIPKIN-SERVER/
    # 关闭 zipkin
    #    enabled: false
    # 模仿配置
    locator:
      discovery:
        # 通过服务发现 定位 它的 hostname
        enabled: true
  sleuth:
    sampler:
      probability: 1

mybatis:
  configuration:
    log-impl: org.apache.ibatis.logging.stdout.StdOutImpl

# Ribbon 全局配置
ribbon:
  ConnectTimeout: 1000
  ReadTimeout: 3000

# Ribbon 指定服务配置超时判定 优先级更高
foodie-user-service:
  ribbon:
    ConnectTiemout: 1000
    ReadTimeout: 3000
    MaxAutoRetries: 1
    MaxAutoRetriesNextServer: 2
    OkToRetryOnAllOperations: true

# Feign 超时判定 优先级高于Ribbon
# 可以通过这里控制Feign 接口上 降级 是否开启 或者是关闭
feign:
  hystrix:
    enabled: true
  client:
    config:
      # 全局配置
      default:
        connectTimeout: 1000
        readTimeout: 5000
      # 优先级比上面那伙计高
      foodie-user-service:
        connectTimeout: 1000
        readTimeout: 5000

## 开启所有actuator-endpoint
management:
  endpoint:
    health:
      show-details: always
  endpoints:
    web:
      exposure:
        include: '*'
  #        include: health,info,xxx
  security:
    user:
      name: gitee
      password: gitee
      roles: ADMIN

hystrix:
  command:
    # 有的属性是默认值，写不写都行
    default:
      fallback:
        enabled: true
      circuitBreaker:
        enabled: true
        # 超过50%错误，那么开启熔断
        errorThresholdPercentage: 50
        # 5个request之后才进行统计
        requestVolumeThreshold: 5
        # 10秒之后进入半开状态
        sleepWindowInMilliseconds: 10000
        # forceClosed, forceOpen 强制关闭/开启熔断开关
      execution:
        timeout:
          enabled: true
        # 可以指定隔离方式是线程池还是信号量
        isolation:
          thread:
            interruptOnTimeout: true
            interruptOnFutureCancel: true
            timeoutInMilliseconds: 10000
      metrics:
        rollingStats:
          # 时间窗口统计
          timeInMilliseconds: 20000
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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTIwNywiaWF0IjoxNjEyMTkwNDA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.igwWjkuHImoKyE18H4uIo4TZVKFGaX27QvE4Drh-Dg0&download=image.png "")

