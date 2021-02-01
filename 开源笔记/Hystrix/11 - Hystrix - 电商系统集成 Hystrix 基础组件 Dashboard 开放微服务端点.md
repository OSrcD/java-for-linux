![](https://tcs.teambition.net/storage/3121fd2488f5fc39cde0f869161183b2f5d2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTcyMywiaWF0IjoxNjEyMTkwOTIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmZDI0ODhmNWZjMzljZGUwZjg2OTE2MTE4M2IyZjVkMiJ9.8BG65eY2dqTTVWDnOzIG3V2Er3WrGIZBsOn8ioqxH3g&download=image.png "")

![](https://tcs.teambition.net/storage/312199dd8923728780d21ec6148172f1a6a2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTcyMywiaWF0IjoxNjEyMTkwOTIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5OWRkODkyMzcyODc4MGQyMWVjNjE0ODE3MmYxYTZhMiJ9.MP-6VtjGJ5P3ixHycn9qQd3iE4NWWTl72dJfOrHEdZ0&download=image.png "")

![](https://tcs.teambition.net/storage/312183c3444151027ae0981e9ef722713ee9?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTcyMywiaWF0IjoxNjEyMTkwOTIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4M2MzNDQ0MTUxMDI3YWUwOTgxZTllZjcyMjcxM2VlOSJ9.qOdmE_vPDc29aNTq8ltklOhGiVVdVPk7Enf0-3QfLg4&download=image.png "")

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

    <artifactId>hystrix-dashboard</artifactId>


    <dependencies>
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-hystrix-dashboard</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-hystrix</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-actuator</artifactId>
        </dependency>
    </dependencies>

    <build>
        <plugins>
            <plugin>
                <groupId>org.springframework.boot</groupId>
                <artifactId>spring-boot-maven-plugin</artifactId>
                <configuration>
                    <mainClass>com.imooc.HystrixDashboardApplication</mainClass>
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

![](https://tcs.teambition.net/storage/3121e356cd0ab1cc648c58bdc3ccf87ff519?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTcyMywiaWF0IjoxNjEyMTkwOTIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlMzU2Y2QwYWIxY2M2NDhjNThiZGMzY2NmODdmZjUxOSJ9.uBVMVI7cz2U3yNczaEEWioHCt5_sR2Qw6LHNgIe2xCQ&download=image.png "")

```java
package com.imooc;

import org.springframework.boot.WebApplicationType;
import org.springframework.boot.builder.SpringApplicationBuilder;
import org.springframework.cloud.client.SpringCloudApplication;
import org.springframework.cloud.netflix.hystrix.dashboard.EnableHystrixDashboard;

@SpringCloudApplication
@EnableHystrixDashboard
public class HystrixDashboardApplication {

    public static void main(String[] args) {
        new SpringApplicationBuilder(HystrixDashboardApplication.class)
                .web(WebApplicationType.SERVLET)
                .run(args);
    }
}

```

![](https://tcs.teambition.net/storage/31219b32bbd98c210785b33432678c0a374a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTcyMywiaWF0IjoxNjEyMTkwOTIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5YjMyYmJkOThjMjEwNzg1YjMzNDMyNjc4YzBhMzc0YSJ9.hfLaiY3Kis_4vexDRJX5opD8-2uiZDrmRlkaHXjcY1M&download=image.png "")

```yaml
spring:
  appliction:
    name: hystrix-dashboard

server:
  port: 20002
```



![](https://tcs.teambition.net/storage/3121c1e14f5c58aa8088520b9a76b39806b7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTcyMywiaWF0IjoxNjEyMTkwOTIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjMWUxNGY1YzU4YWE4MDg4NTIwYjlhNzZiMzk4MDZiNyJ9.PMrkdH13Pj7f0G6QWoeWElGaYM5QFL4Nh_OW7qXaCVk&download=image.png "")

```yaml
server:
  port: 10002

spring:
  datasource:                                           # 数据源的相关配置
    # 拆分数据源到独立database instance，或者独立schema
#    url: jdbc:mysql://localhost:3306/foodie-cloud-item?useUnicode=true&characterEncoding=UTF-8&autoReconnect=true
    url: jdbc:mysql://localhost:3306/foodie-shop-dev?useUnicode=true&characterEncoding=UTF-8&autoReconnect=true
    password: SocialPG
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

![](https://tcs.teambition.net/storage/3121ad8922efdd1d5ec3e3daeb21a49164bc?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTcyMywiaWF0IjoxNjEyMTkwOTIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZDg5MjJlZmRkMWQ1ZWMzZTNkYWViMjFhNDkxNjRiYyJ9.UOMv2Ysg6EpogApaWXS10gQ-Lxqx5JXFCgCrEZNyvpE&download=image.png "")

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

    <artifactId>foodie-user-service</artifactId>

    <dependencies>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-user-api</artifactId>
            <version>${project.version}</version>
        </dependency>

        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-user-mapper</artifactId>
            <version>${project.version}</version>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-hystrix</artifactId>
        </dependency>
    </dependencies>

</project>
```

![](https://tcs.teambition.net/storage/3121f5c4cc91df4a6a659a1a715fa0947128?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTcyMywiaWF0IjoxNjEyMTkwOTIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmNWM0Y2M5MWRmNGE2YTY1OWExYTcxNWZhMDk0NzEyOCJ9.-7ytyR5K-S03gLq16U2oUqp-DhS4GYSaOOnXn2dFYhw&download=image.png "")

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

    <artifactId>foodie-order-service</artifactId>

    <dependencies>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-order-mapper</artifactId>
            <version>${project.version}</version>
        </dependency>

        <!-- 用户服务接口层 -->
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-user-api</artifactId>
            <version>${project.version}</version>
        </dependency>

        <!-- 订单服务接口层 -->
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-order-api</artifactId>
            <version>${project.version}</version>
        </dependency>

        <!-- 商品服务依赖 -->
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-item-api</artifactId>
            <version>${project.version}</version>
        </dependency>

        <!-- TODO 学到Feign章节以后，就可以把它删掉 -->
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-client</artifactId>
        </dependency>


        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-hystrix</artifactId>
        </dependency>
    </dependencies>

</project>
```

![](https://tcs.teambition.net/storage/31211f8ad20422793d2c28d9dc6a26a1bdfe?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTcyMywiaWF0IjoxNjEyMTkwOTIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExZjhhZDIwNDIyNzkzZDJjMjhkOWRjNmEyNmExYmRmZSJ9.8HWgw7_GUHgJCihzPIqx89YkYiq201uyHGBT_e33H3s&download=image.png "")

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

    <artifactId>foodie-item-service</artifactId>

    <dependencies>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-item-api</artifactId>
            <version>${project.version}</version>
        </dependency>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-item-mapper</artifactId>
            <version>${project.version}</version>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-hystrix</artifactId>
        </dependency>
    </dependencies>

</project>
```

![](https://tcs.teambition.net/storage/3121fb7f7115f6353e4a8e01465327031501?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTcyMywiaWF0IjoxNjEyMTkwOTIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmYjdmNzExNWY2MzUzZTRhOGUwMTQ2NTMyNzAzMTUwMSJ9.Ob1yYywgk2HvFLIKsxWnVNb27RwYm_4P8gR52r2HURE&download=image.png "")

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
feign:
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
```

![](https://tcs.teambition.net/storage/31218737d1f3920cb13a77b3e579176793af?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTcyMywiaWF0IjoxNjEyMTkwOTIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4NzM3ZDFmMzkyMGNiMTNhNzdiM2U1NzkxNzY3OTNhZiJ9.OdFoYQ7Z423M93yXg9ltYJ3N6PV_UWm92-T0KAs7k10&download=image.png "")

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

![](https://tcs.teambition.net/storage/31211764606256b0e3eeb36404aa58672f6a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTcyMywiaWF0IjoxNjEyMTkwOTIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExNzY0NjA2MjU2YjBlM2VlYjM2NDA0YWE1ODY3MmY2YSJ9.ksJ39E3cbBg2OUB6xLjuK4kq1pAlWQiH0ay9KZCAMv8&download=image.png "")

```json
{
  _links: {
    self: {
      href: "http://localhost:10002/actuator",
      templated: false
    },
    archaius: {
      href: "http://localhost:10002/actuator/archaius",
      templated: false
    },
    auditevents: {
      href: "http://localhost:10002/actuator/auditevents",
      templated: false
    },
    beans: {
      href: "http://localhost:10002/actuator/beans",
      templated: false
    },
    caches-cache: {
      href: "http://localhost:10002/actuator/caches/{cache}",
      templated: true
    },
    caches: {
      href: "http://localhost:10002/actuator/caches",
      templated: false
    },
    health-component: {
      href: "http://localhost:10002/actuator/health/{component}",
      templated: true
    },
    health-component-instance: {
      href: "http://localhost:10002/actuator/health/{component}/{instance}",
      templated: true
    },
    health: {
      href: "http://localhost:10002/actuator/health",
      templated: false
    },
    conditions: {
      href: "http://localhost:10002/actuator/conditions",
      templated: false
    },
    configprops: {
      href: "http://localhost:10002/actuator/configprops",
      templated: false
    },
    env: {
      href: "http://localhost:10002/actuator/env",
      templated: false
    },
    env-toMatch: {
      href: "http://localhost:10002/actuator/env/{toMatch}",
      templated: true
    },
    info: {
      href: "http://localhost:10002/actuator/info",
      templated: false
    },
    loggers: {
      href: "http://localhost:10002/actuator/loggers",
      templated: false
    },
    loggers-name: {
      href: "http://localhost:10002/actuator/loggers/{name}",
      templated: true
    },
    heapdump: {
      href: "http://localhost:10002/actuator/heapdump",
      templated: false
    },
    threaddump: {
      href: "http://localhost:10002/actuator/threaddump",
      templated: false
    },
    metrics-requiredMetricName: {
      href: "http://localhost:10002/actuator/metrics/{requiredMetricName}",
      templated: true
    },
    metrics: {
      href: "http://localhost:10002/actuator/metrics",
      templated: false
    },
    scheduledtasks: {
      href: "http://localhost:10002/actuator/scheduledtasks",
      templated: false
    },
    httptrace: {
      href: "http://localhost:10002/actuator/httptrace",
      templated: false
    },
    mappings: {
      href: "http://localhost:10002/actuator/mappings",
      templated: false
    },
    refresh: {
      href: "http://localhost:10002/actuator/refresh",
      templated: false
    },
    features: {
      href: "http://localhost:10002/actuator/features",
      templated: false
    },
    service-registry: {
      href: "http://localhost:10002/actuator/service-registry",
      templated: false
    }
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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTcyMywiaWF0IjoxNjEyMTkwOTIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.iegk6Uh873mjSQuGCG-SngKKWP_WvbIPDNan7QNYlq4&download=image.png "")

