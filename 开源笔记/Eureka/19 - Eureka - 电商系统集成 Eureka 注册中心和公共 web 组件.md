![](https://tcs.teambition.net/storage/312123866e94e07edd9d82d8899556a696b0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyMzg2NmU5NGUwN2VkZDlkODJkODg5OTU1NmE2OTZiMCJ9.L5UbpirAlnVqMrls4d2Zsb-KNyqMXLfMouJx7Ao-j5U&download=image.png "")

![](https://tcs.teambition.net/storage/312125b339becfe3e3d6bb80b42261f8b1c6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyNWIzMzliZWNmZTNlM2Q2YmI4MGI0MjI2MWY4YjFjNiJ9.XATmXVzS5dxOGjKYfGYVPwHX10ofMWoSe6gFDYJ1XNU&download=image.png "")

![](https://tcs.teambition.net/storage/312135870ea1454404718dd3f5a844f672b1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzNTg3MGVhMTQ1NDQwNDcxOGRkM2Y1YTg0NGY2NzJiMSJ9.zPzW_nyL7fwF9k77_myMpu5X7-9FlyWoUoiXkXNvepo&download=image.png "")

![](https://tcs.teambition.net/storage/3121b40a972d1ce1256adf5e92735638fccb?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiNDBhOTcyZDFjZTEyNTZhZGY1ZTkyNzM1NjM4ZmNjYiJ9.L1PrpNrLIbrbe5QNqszCFgXfKzPOUeaW67eqJ6YWkIU&download=image.png "")

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

    <artifactId>registry-center</artifactId>

    <dependencies>
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-server</artifactId>
        </dependency>
    </dependencies>

    <!-- 指定 Spring Boot 启动时的 main 方法 主类 -->
    <!-- 可以在描述文件中指定 也可以在运行时指定 -->
    <build>
        <plugins>
            <plugin>
                <groupId>org.springframework.boot</groupId>
                <artifactId>spring-boot-maven-plugin</artifactId>
                <configuration>
                    <mainClass></mainClass>
                </configuration>
                <!-- 指定动作 -->
                <executions>
                    <execution>
                        <goals>
                            <!-- 指定执行目标重新打包 只不过在重新打包过程中 在描述文件中的 主类被mainclass标签替换掉 -->
                            <goal>repackage</goal>
                        </goals>
                    </execution>

                </executions>
            </plugin>
        </plugins>
    </build>


</project>

```

![](https://tcs.teambition.net/storage/3121cd5a9f33ce79beb21cd430180f0675e7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjZDVhOWYzM2NlNzliZWIyMWNkNDMwMTgwZjA2NzVlNyJ9.pvDPXhf6hJREbDLSMCYBTTk8Soj05-TpvSA3pgCx3Fc&download=image.png "")

```java
package com.imooc;

import org.springframework.boot.WebApplicationType;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.builder.SpringApplicationBuilder;
import org.springframework.cloud.netflix.eureka.server.EnableEurekaServer;

@SpringBootApplication
@EnableEurekaServer
public class EurekaServerApplication {

    public static void main(String[] args) {
        new SpringApplicationBuilder(EurekaServerApplication.class)
                .web(WebApplicationType.SERVLET)
                .run(args);
    }
}


```

![](https://tcs.teambition.net/storage/3121dfc49461498e64a9d8069f27a12ce634?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkZmM0OTQ2MTQ5OGU2NGE5ZDgwNjlmMjdhMTJjZTYzNCJ9.GeyG1FwDHIK2L_QNomERft1y0wWnPb7niv0PHdvDLUc&download=image.png "")

```yaml
## 启动顺序： #1

spring:
  application:
    name: eureka-server
  profiles:
    active: dev

server:
  port: 20000

eureka:
  client:
    fetch-registry: false
    register-with-eureka: false
  instance:
    ## 将localhost指向本机（host文件）
    hostname: localhost

```

![](https://tcs.teambition.net/storage/3121148b8003cbfb3ed3bac613d703ad926d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExNDhiODAwM2NiZmIzZWQzYmFjNjEzZDcwM2FkOTI2ZCJ9.agaxiHMymehOzYOjl6EcbBn6nNioPKxuLU2-2C3JB-Q&download=image.png "")

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

    <artifactId>registry-center</artifactId>

    <dependencies>
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-server</artifactId>
        </dependency>
    </dependencies>

    <!-- 指定 Spring Boot 启动时的 main 方法 主类 -->
    <!-- 可以在描述文件中指定 也可以在运行时指定 -->
    <build>
        <plugins>
            <plugin>
                <groupId>org.springframework.boot</groupId>
                <artifactId>spring-boot-maven-plugin</artifactId>
                <configuration>
                    <mainClass>com.imooc.EurekaServerApplication</mainClass>
                </configuration>
                <!-- 指定动作 -->
                <executions>
                    <execution>
                        <goals>
                            <!-- 指定执行目标重新打包 只不过在重新打包过程中 在描述文件中的 主类被mainclass标签替换掉 -->
                            <goal>repackage</goal>
                        </goals>
                    </execution>

                </executions>
            </plugin>
        </plugins>
    </build>


</project>

```

![](https://tcs.teambition.net/storage/3121099ec0e8da3a2d22e65fdc4a6aa9c8cf?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwOTllYzBlOGRhM2EyZDIyZTY1ZmRjNGE2YWE5YzhjZiJ9.Ak1p8EjLX_JQS5sFPSnpcThMhURbSGT6O2iX3xR6yjE&download=image.png "")

![](https://tcs.teambition.net/storage/31213120aa01e48ac132f11021fbcd7e5884?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzMTIwYWEwMWU0OGFjMTMyZjExMDIxZmJjZDdlNTg4NCJ9.18WiTW-g2Fd--3R1xuJ3jtDRSew03hwRR-TAnKhEz0g&download=image.png "")

![](https://tcs.teambition.net/storage/312114fcfc5688ee9eae18e4360e81a94384?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExNGZjZmM1Njg4ZWU5ZWFlMThlNDM2MGU4MWE5NDM4NCJ9.lJWPEkfpToXL6YOrtjgobbGz15uDvwGLCaGGDhJlJIw&download=image.png "")

![](https://tcs.teambition.net/storage/312199aad54a898cea3a2d3446bfb1a4d71e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5OWFhZDU0YTg5OGNlYTNhMmQzNDQ2YmZiMWE0ZDcxZSJ9.etl0ZRWl10-4KX5XQYQgn6KiHIQGKm8SK3rtgZ0plhg&download=image.png "")

![](https://tcs.teambition.net/storage/312178dc9d4aaf73d74b338b7e284972e694?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3OGRjOWQ0YWFmNzNkNzRiMzM4YjdlMjg0OTcyZTY5NCJ9.-EyFSkNBC9AU02_fqfxUtO1pky_YvjTlhOqtyNFs8gk&download=image.png "")

![](https://tcs.teambition.net/storage/3121fb31ce01d597bfcb0189bd2e7127e9fd?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmYjMxY2UwMWQ1OTdiZmNiMDE4OWJkMmU3MTI3ZTlmZCJ9.WOy-gLB4gUWyyzipw7T4kQ2GfnHBySyGRMhn7T4ctmg&download=image.png "")

![](https://tcs.teambition.net/storage/312192ef2b3495a3ef5c4e8d0c619ce6fedc?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5MmVmMmIzNDk1YTNlZjVjNGU4ZDBjNjE5Y2U2ZmVkYyJ9.fjFHh5WOxfM_JOHGbtiY6MMIj34GRs1WmbJAg-FCl2w&download=image.png "")

![](https://tcs.teambition.net/storage/312107de185908490f8b6782b596a0ebd379?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwN2RlMTg1OTA4NDkwZjhiNjc4MmI1OTZhMGViZDM3OSJ9.o2qfYFr0jVpo86L6tSZ1LdhnlTrm3bCk5I2lahNTVO4&download=image.png "")

![](https://tcs.teambition.net/storage/3121316fb032fc9b17f135f5f6b1fc8b719b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzMTZmYjAzMmZjOWIxN2YxMzVmNWY2YjFmYzhiNzE5YiJ9.N7MJ0JYXRATv3lQAlQNm2yfnCWduCN5K2FYJEjV4lYw&download=image.png "")

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

    <artifactId>foodie-cloud-web-components</artifactId>

    <dependencies>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-cloud-common</artifactId>
            <version>${project.version}</version>
        </dependency>

        <!-- 会从父 pom 中指定的depend...Manager 中依赖版本 -->
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-actuator</artifactId>
        </dependency>
    </dependencies>

</project>
```

![](https://tcs.teambition.net/storage/31214bd920a4cc7c9d755886993706c3096f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0YmQ5MjBhNGNjN2M5ZDc1NTg4Njk5MzcwNmMzMDk2ZiJ9.YoicK_8lsINXc9fRifYEVgBviWHQUBC9reriv8UWbo4&download=image.png "")

## 复制

![](https://tcs.teambition.net/storage/31213ac8302e9db761f0ed22ede5ff18ab2f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzYWM4MzAyZTlkYjc2MWYwZWQyMmVkZTVmZjE4YWIyZiJ9.Vefh9CR2bOgB9tIk8fDLWLaBUgaMRJDkl-hAWsu0_xw&download=image.png "")

![](https://tcs.teambition.net/storage/3121feb81b07757511eba4f585438317d296?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmZWI4MWIwNzc1NzUxMWViYTRmNTg1NDM4MzE3ZDI5NiJ9.d88tIUJNRuQ4NRzHO_Gen3KxtS4bXLNkoRkr8V7DY0o&download=image.png "")

## 修改

![](https://tcs.teambition.net/storage/3121af29579b6cb8d37e22e743e5441a80cd?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZjI5NTc5YjZjYjhkMzdlMjJlNzQzZTU0NDFhODBjZCJ9.d04bPuryEerAOphnuJhDuGiRA4LawBd7cl9jQu71Fuw&download=image.png "")

![](https://tcs.teambition.net/storage/31216a4d4f72cd6dd043d855c1beb4fdace0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2YTRkNGY3MmNkNmRkMDQzZDg1NWMxYmViNGZkYWNlMCJ9.3wUwQ3g5l1OMt1h-Mh_7M2jEssStFX_zaggl6qNIPHQ&download=image.png "")

## 复制

![](https://tcs.teambition.net/storage/3121a2825a5fc6b733f0f83d087740a3ccbc?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhMjgyNWE1ZmM2YjczM2YwZjgzZDA4Nzc0MGEzY2NiYyJ9.DOV3LK84izLNttUWdr2w3LqNFWAAqegfYyTAO-Gbrhc&download=image.png "")

![](https://tcs.teambition.net/storage/3121754b654607b6ce2fc20ffac76e18d9c4?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3NTRiNjU0NjA3YjZjZTJmYzIwZmZhYzc2ZTE4ZDljNCJ9.yDNeHYG5zNsMPlaQyGlhCAVPu-rghmL4gXfisW87qnU&download=image.png "")

![](https://tcs.teambition.net/storage/312173e2cce95cdb25ac2d9ce1d2ceb6ca79?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3M2UyY2NlOTVjZGIyNWFjMmQ5Y2UxZDJjZWI2Y2E3OSJ9.c8e5BuSC6TK0G7ioumYWURb1ZRil9sARwAFx5tEviyo&download=image.png "")

![](https://tcs.teambition.net/storage/3121ad9a93b43fac45439a043a2f80b681f3?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZDlhOTNiNDNmYWM0NTQzOWEwNDNhMmY4MGI2ODFmMyJ9.OOxghURzKxP25hcAxI4nA1dEKgW-Ozh37lEcKcuVF9s&download=image.png "")

## 复制

![](https://tcs.teambition.net/storage/3121faee03531cd437bf169c464e43116cd1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmYWVlMDM1MzFjZDQzN2JmMTY5YzQ2NGU0MzExNmNkMSJ9.w8KYrjyOf1-e0MwoYTynWTVwAVJpCVyJ10T-TH4ti7I&download=image.png "")

![](https://tcs.teambition.net/storage/31217ce36a0724ed80ef7f30203b63f071e4?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3Y2UzNmEwNzI0ZWQ4MGVmN2YzMDIwM2I2M2YwNzFlNCJ9.MmQwx7WKQF4OmHNTYjC51HCEtNbtN9yG37m3ZE4YnpY&download=image.png "")

## 修改

![](https://tcs.teambition.net/storage/312177353d863d9162d8f3e4f4c176ef8705?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3NzM1M2Q4NjNkOTE2MmQ4ZjNlNGY0YzE3NmVmODcwNSJ9.MuZo42j4ynsP_k1thOOZokh5n7RFdm_FMLTP1hfqKA8&download=image.png "")

![](https://tcs.teambition.net/storage/31210628f3a2b3084c0e555ddcc3c88659dd?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwNjI4ZjNhMmIzMDg0YzBlNTU1ZGRjYzNjODg2NTlkZCJ9.zLYyhFsmEKBH9o-eNPRY4DRJEQSbxqSJ0PS8y5TW9iM&download=image.png "")

![](https://tcs.teambition.net/storage/3121ec2252f111f729efbd19001c7fd9fac9?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlYzIyNTJmMTExZjcyOWVmYmQxOTAwMWM3ZmQ5ZmFjOSJ9.Tl0X_2MER9sC_zY0_Mn2-CTUE4JXbVtbkmeei4o4WL8&download=image.png "")

```java
package com.imooc.controller;

import com.imooc.pojo.Orders;
import com.imooc.pojo.Users;
import com.imooc.pojo.vo.UsersVO;
import com.imooc.service.center.MyOrdersService;
import com.imooc.utils.IMOOCJSONResult;
import com.imooc.utils.RedisOperator;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;

import java.io.File;
import java.util.UUID;

@Controller
public class BaseController {

    @Autowired
    public RedisOperator redisOperator;

    public static final String FOODIE_SHOPCART = "shopcart";

    public static final Integer COMMON_PAGE_SIZE = 10;
    public static final Integer PAGE_SIZE = 20;

    public static final String REDIS_USER_TOKEN = "redis_user_token";

    // 支付中心的调用地址
    public String paymenUrl = "http://payment.t.mukewang.com/foodie-payment/payment/createMerchantOrder";

    // 微信支付成功 -> 支付中心 -> 天天吃货平台
    //                       -> 回调通知的url
    public String payReturnUrl = "http://api.z.opendevel.gq:8088/foodie-dev-api/orders/notifyMerchantOrderPaid";

    public final String IMAGE_USER_FACE_LOCATION = File.separator + "Users"+
                                                    File.separator + "virtualman"+
                                                    File.separator + "Downloads" +
                                                    File.separator + "temp"+
                                                    File.separator + "workspace" +
                                                    File.separator + "images" +
                                                    File.separator + "foodie" +
                                                    File.separator + "faces";

    // FIXME 下面的逻辑移植到订单中心
//    @Autowired
//    public MyOrdersService myOrdersService;
//
//    /**
//     * 用于验证用户和订单是否有关联关系，避免非法用户调用
//     * @return
//     */
//    public IMOOCJSONResult checkUserOrder(String userId, String orderId) {
//        Orders orders = myOrdersService.queryMyOrder(userId,orderId);
//        if(orders == null){
//            return IMOOCJSONResult.errorMsg("订单Id不存在！");
//        }
//        return IMOOCJSONResult.ok(orders);
//    }

//    public UsersVO conventUsersVO(Users user) {
//        // 实现用户的redis会话
//        String uniqueToken = UUID.randomUUID().toString().trim();
//        redisOperator.set(REDIS_USER_TOKEN + ":" + user.getId(),
//                uniqueToken);
//
//        UsersVO usersVO = new UsersVO();
//        BeanUtils.copyProperties(user, usersVO);
//        usersVO.setUserUniqueToken(uniqueToken);
//        return usersVO;
//    }

}


```

![](https://tcs.teambition.net/storage/3121e2699148a2bca722bda9e3eaa7afd33f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlMjY5OTE0OGEyYmNhNzIyYmRhOWUzZWFhN2FmZDMzZiJ9.2XUJZM8pOBTFN9BEn0mbQxCKEaW3La9Y0GdINJeI_c8&download=image.png "")

![](https://tcs.teambition.net/storage/31214d7351ffa0a9e5f8ca7903d99f141159?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0ZDczNTFmZmEwYTllNWY4Y2E3OTAzZDk5ZjE0MTE1OSJ9.tjTIPqDiMmtock4rgTl4-NTdxBNEHnITga5gPEkAbkQ&download=image.png "")

```java
package com.imooc.controller;

import org.springframework.stereotype.Controller;

import java.io.File;

@Controller
public class BaseController {

//    @Autowired
//    public RedisOperator redisOperator;

    public static final String FOODIE_SHOPCART = "shopcart";

    public static final Integer COMMON_PAGE_SIZE = 10;
    public static final Integer PAGE_SIZE = 20;

    public static final String REDIS_USER_TOKEN = "redis_user_token";

    // 支付中心的调用地址
    public String paymenUrl = "http://payment.t.mukewang.com/foodie-payment/payment/createMerchantOrder";

    // 微信支付成功 -> 支付中心 -> 天天吃货平台
    //                       -> 回调通知的url
    public String payReturnUrl = "http://api.z.opendevel.gq:8088/foodie-dev-api/orders/notifyMerchantOrderPaid";

    public final String IMAGE_USER_FACE_LOCATION = File.separator + "Users"+
                                                    File.separator + "virtualman"+
                                                    File.separator + "Downloads" +
                                                    File.separator + "temp"+
                                                    File.separator + "workspace" +
                                                    File.separator + "images" +
                                                    File.separator + "foodie" +
                                                    File.separator + "faces";

    // FIXME 下面的逻辑移植到订单中心
//    @Autowired
//    public MyOrdersService myOrdersService;
//
//    /**
//     * 用于验证用户和订单是否有关联关系，避免非法用户调用
//     * @return
//     */
//    public IMOOCJSONResult checkUserOrder(String userId, String orderId) {
//        Orders orders = myOrdersService.queryMyOrder(userId,orderId);
//        if(orders == null){
//            return IMOOCJSONResult.errorMsg("订单Id不存在！");
//        }
//        return IMOOCJSONResult.ok(orders);
//    }

//    public UsersVO conventUsersVO(Users user) {
//        // 实现用户的redis会话
//        String uniqueToken = UUID.randomUUID().toString().trim();
//        redisOperator.set(REDIS_USER_TOKEN + ":" + user.getId(),
//                uniqueToken);
//
//        UsersVO usersVO = new UsersVO();
//        BeanUtils.copyProperties(user, usersVO);
//        usersVO.setUserUniqueToken(uniqueToken);
//        return usersVO;
//    }

}


```



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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI5NiwiaWF0IjoxNjEyMTkxNDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.qQ4DlAqZVZpdhXrs1rIwyFrQspeQM3tpFoCnzO0DR5o&download=image.png "")

