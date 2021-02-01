![](https://tcs.teambition.net/storage/312163ce046ee0d1574b6faa47e5d0e0fb48?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2M2NlMDQ2ZWUwZDE1NzRiNmZhYTQ3ZTVkMGUwZmI0OCJ9.llbHag4NYxQy8dIKm-Z-PBzNAaiiC5Tz-IBrHpLhsT4&download=image.png "")

客户端配置双节点

![](https://tcs.teambition.net/storage/31212e00c8cec75c2f0540dbe99dbcefc6c8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyZTAwYzhjZWM3NWMyZjA1NDBkYmU5OWRiY2VmYzZjOCJ9.pXTl2uw27Uqa_rI26tWWVuvs8lhH0JBqF1LItoNfG6Q&download=image.png "")

![](https://tcs.teambition.net/storage/312164e9bc5b01c02826214684dc29ece3fe?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2NGU5YmM1YjAxYzAyODI2MjE0Njg0ZGMyOWVjZTNmZSJ9.ub68Z6G3ywoLL7Zp9hqLzzl1STkb726PWwDDOLj79N4&download=image.png "")

![](https://tcs.teambition.net/storage/312116cb55e1207479b8f12de8fe2c8e690e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExNmNiNTVlMTIwNzQ3OWI4ZjEyZGU4ZmUyYzhlNjkwZSJ9.v1AgQh7ZnbBCPiC4unqvO2bHG8X_y1MbsDcK6jAQN1g&download=image.png "")

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

    <artifactId>eureka-server-peer</artifactId>

    <properties>
        <maven.compiler.source>8</maven.compiler.source>
        <maven.compiler.target>8</maven.compiler.target>
    </properties>

    <dependencies>
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-server</artifactId>
        </dependency>
    </dependencies>

</project>
```

![](https://tcs.teambition.net/storage/31215e0b6be4ae64d7f78aa3dadf29732703?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1ZTBiNmJlNGFlNjRkN2Y3OGFhM2RhZGYyOTczMjcwMyJ9.ahoqDANW3D8CAJlW6sl1-q3eTqo7jggBtc9adva8EXA&download=image.png "")

```java
package com.imooc.springcloud;

import org.springframework.boot.WebApplicationType;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.builder.SpringApplicationBuilder;
import org.springframework.cloud.netflix.eureka.server.EnableEurekaServer;

@SpringBootApplication
// 识别为 EurekaServer 注册中心
@EnableEurekaServer
public class EurekaServerApplication {
    public static void main(String[] args) {

        // 从Builder 构建一个启动类
        new SpringApplicationBuilder(EurekaServerApplication.class)
                // 定义启动方式 为 SERVLET形式
                .web(WebApplicationType.SERVLET)
                .run(args);

    }
}

```

![](https://tcs.teambition.net/storage/3121a7eb09a39096cfd603552a0a4a5a2ef3?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhN2ViMDlhMzkwOTZjZmQ2MDM1NTJhMGE0YTVhMmVmMyJ9.SCTDUePZ9bcRXM40PHts4qTmV57_x0CdYe7so5R6XHM&download=image.png "")

```text
spring.application.name=eureka-server-peer1
server.port=20001
eureka.instance.hostname=peer1

# 作为一个注册中心 它要向其他注册中心同步数据
# 注册中心注册
eureka.client.service-url.defaultZone=http://peer2:20000/eureka
```

![](https://tcs.teambition.net/storage/3121ba1aa5f4d7aabffc26de08fffb3080b3?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiYTFhYTVmNGQ3YWFiZmZjMjZkZTA4ZmZmYjMwODBiMyJ9.7Ak1Fd_ZkPEfJ_X1lGYatvTH1FkXlqjMmFn4tvcuJhg&download=image.png "")

![](https://tcs.teambition.net/storage/31210a913780f44d45a69ee72fb91199b951?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwYTkxMzc4MGY0NGQ0NWE2OWVlNzJmYjkxMTk5Yjk1MSJ9.9AOoQZJZHvJXNuGvAPuzJtP0-OPEXzdJETXd8heUZ_c&download=image.png "")



![](https://tcs.teambition.net/storage/31216ed5cf1c4d58ac8cb267380558367f54?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2ZWQ1Y2YxYzRkNThhYzhjYjI2NzM4MDU1ODM2N2Y1NCJ9.4BFnRnyxi7rrCtfD4mV6gdx-r7FcQt4kQrOFCiH3qXo&download=image.png "")

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

    <artifactId>eureka-server-peer2</artifactId>

    <properties>
        <maven.compiler.source>8</maven.compiler.source>
        <maven.compiler.target>8</maven.compiler.target>
    </properties>

    <dependencies>
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-server</artifactId>
        </dependency>
    </dependencies>
</project>
```

![](https://tcs.teambition.net/storage/3121c9ea8b5b4d294d69796bb53d37ed8c72?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjOWVhOGI1YjRkMjk0ZDY5Nzk2YmI1M2QzN2VkOGM3MiJ9.LZeOat5V-IwdOuIhvb3IZBLggEwAXh0WhNS2yRxG_u8&download=image.png "")

```java
package com.imooc.springcloud;

import org.springframework.boot.WebApplicationType;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.builder.SpringApplicationBuilder;
import org.springframework.cloud.netflix.eureka.server.EnableEurekaServer;

@SpringBootApplication
// 识别为 EurekaServer 注册中心
@EnableEurekaServer
public class EurekaServerApplication {
    public static void main(String[] args) {

        // 从Builder 构建一个启动类
        new SpringApplicationBuilder(EurekaServerApplication.class)
                // 定义启动方式 为 SERVLET形式
                .web(WebApplicationType.SERVLET)
                .run(args);

    }
}


```

![](https://tcs.teambition.net/storage/3121a876cd2121a998b34ad01fec75994261?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhODc2Y2QyMTIxYTk5OGIzNGFkMDFmZWM3NTk5NDI2MSJ9.DKfjvP8jUPSYGOR_PK5LDxGJ0x_PPegwmJNWyVhJWEw&download=image.png "")

```text
spring.application.name=eureka-server-peer2
server.port=20000
eureka.instance.hostname=peer2

# 作为一个注册中心 它要向其他注册中心同步数据
# 注册中心注册
eureka.client.service-url.defaultZone=http://peer1:20001/eureka
```

## 启动两个注册中心

![](https://tcs.teambition.net/storage/312132496cb560e28327c4b8456d0c89a79a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzMjQ5NmNiNTYwZTI4MzI3YzRiODQ1NmQwYzg5YTc5YSJ9.erU8UZSiTsuaOmv3qQXQE3XkpDYEp06ktn44FubTGNs&download=image.png "")

![](https://tcs.teambition.net/storage/312191f5136f5b14ae3090bbb9574a015e04?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5MWY1MTM2ZjViMTRhZTMwOTBiYmI5NTc0YTAxNWUwNCJ9.31pmwpUhNLAEm7iZvSz2FAXd-avj4_Vqv9a94q5sm_w&download=image.png "")

![](https://tcs.teambition.net/storage/31217ac96a01a635aee69298bb37a5397ccc?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3YWM5NmEwMWE2MzVhZWU2OTI5OGJiMzdhNTM5N2NjYyJ9.22jyPmx9WOnQrLNumdV-tYWUoijp-VjKVUKabOLRrR0&download=image.png "")

![](https://tcs.teambition.net/storage/3121883fe5a6c2b813b7089e95f0bf22cd86?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4ODNmZTVhNmMyYjgxM2I3MDg5ZTk1ZjBiZjIyY2Q4NiJ9.Cd4binAnyJVmBEPWphqG-nMVz9YVmUGCX7rfQPxeP4M&download=image.png "")

## 服务提供者的配置

![](https://tcs.teambition.net/storage/31211ae5fc3af821beb6128ba6043866e3e6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExYWU1ZmMzYWY4MjFiZWI2MTI4YmE2MDQzODY2ZTNlNiJ9.Fe7MY8G2p4qwFgi2z0TrdIcG_sSuA42k3OJMBoZ1HrY&download=image.png "")

## 启动服务提供者

![](https://tcs.teambition.net/storage/31219a4ec8bc06b95637412ba1828a9ff4a1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5YTRlYzhiYzA2Yjk1NjM3NDEyYmExODI4YTlmZjRhMSJ9.v8o_l_FU-7VS56owem1cLEOzLDWSK2Z078gs4X0wu3s&download=image.png "")

![](https://tcs.teambition.net/storage/3121280fad71c3e082830042a75601130c93?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyODBmYWQ3MWMzZTA4MjgzMDA0MmE3NTYwMTEzMGM5MyJ9.bM5hYlxd_dtE4s4za8JCKEZ4fjywvpVseyj_1oGKfnY&download=image.png "")

## 同步成功

![](https://tcs.teambition.net/storage/312156cf9a62a2e1e75a841cb283053138fb?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1NmNmOWE2MmEyZTFlNzVhODQxY2IyODMwNTMxMzhmYiJ9.rs_7y8RNEeZ4SyzEnt1Ehaz-s8lucUTlHRvQMQebj9c&download=image.png "")

![](https://tcs.teambition.net/storage/312182c2b17f1f8e71020182ed5fef018df6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4MmMyYjE3ZjFmOGU3MTAyMDE4MmVkNWZlZjAxOGRmNiJ9.Rr-D_MFg7kuWYhvbfpcKKHHGZvkkW9op_pXGSKX9NTA&download=image.png "")

![](https://tcs.teambition.net/storage/3121117677f4f1f53f7858b3024734b9e79a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExMTc2NzdmNGYxZjUzZjc4NThiMzAyNDczNGI5ZTc5YSJ9.iEx-fI5dBboxHffrtkp7zMpa3XFN5Y_ukLcFws54C0s&download=image.png "")

![](https://tcs.teambition.net/storage/3121b5b563be642a675021831feaf9dbcf55?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiNWI1NjNiZTY0MmE2NzUwMjE4MzFmZWFmOWRiY2Y1NSJ9.iKQDwWqsz1AUv6AMpUiwVx8DI3xCwB_Noke8OFrL6u8&download=image.png "")

## 重新启动

![](https://tcs.teambition.net/storage/312153007868be01be2eb4bdb606db95c512?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1MzAwNzg2OGJlMDFiZTJlYjRiZGI2MDZkYjk1YzUxMiJ9.Sk6qjxV29v9y8XbgNu9Zd7yxT6fUsfV2jKSqZFKM2zw&download=image.png "")

![](https://tcs.teambition.net/storage/312180cbb3cc477c6a7f526511feeabb5210?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4MGNiYjNjYzQ3N2M2YTdmNTI2NTExZmVlYWJiNTIxMCJ9.ljPATFrfNLXUjwQMMTmHyoj7XQQdILanwB5o-k_Jx4E&download=image.png "")

![](https://tcs.teambition.net/storage/312194c4088da2d261fe873e658b4e7528a5?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5NGM0MDg4ZGEyZDI2MWZlODczZTY1OGI0ZTc1MjhhNSJ9.MtCUz67hhGRx9Z_IqWz0_aZ-2Q1kPoTigO7zwDXNpsI&download=image.png "")

![](https://tcs.teambition.net/storage/31219a4821d27da3f747eaaecc303e666fa8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5YTQ4MjFkMjdkYTNmNzQ3ZWFhZWNjMzAzZTY2NmZhOCJ9.3nDu1ZZc9gk-0FZykKzVc-s6TaqjNmoROl2cZVh2UnM&download=image.png "")

## 停止

![](https://tcs.teambition.net/storage/3121b00ba1d883cc9004c5e8fd2e0b911b16?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiMDBiYTFkODgzY2M5MDA0YzVlOGZkMmUwYjkxMWIxNiJ9.Qo0OkVpVU-3r6fMYf0P-tvcQD30Gh_6-ZwgTbT_ZMrc&download=image.png "")

## 停止掉20000端口 注册中心

![](https://tcs.teambition.net/storage/312134b0b2462193e5e8da0e3e890db1170b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzNGIwYjI0NjIxOTNlNWU4ZGEwZTNlODkwZGIxMTcwYiJ9.BzJCac6I_R3bn1QAmuQ1T3a_d2TAMM-7NsVBNsJdMNc&download=image.png "")

## 启动服务提供者

![](https://tcs.teambition.net/storage/3121f9f16483fbcf914c17d8cad51dbea783?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmOWYxNjQ4M2ZiY2Y5MTRjMTdkOGNhZDUxZGJlYTc4MyJ9.bCE7_yPKjev_3uNE4O50T1PLT_Zd700FGdE6_-YrHN8&download=image.png "")

## 宕机

![](https://tcs.teambition.net/storage/3121c269e71dccf5b8bff30580dbf7b58dbd?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjMjY5ZTcxZGNjZjViOGJmZjMwNTgwZGJmN2I1OGRiZCJ9.CtwZjdKFfhotGoehY7JwPSipratBbGjBSy9rXMd7uQ0&download=image.png "")

![](https://tcs.teambition.net/storage/31215cb8ee39045c7a7847b43b7eccd81917?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1Y2I4ZWUzOTA0NWM3YTc4NDdiNDNiN2VjY2Q4MTkxNyJ9.yax6j0zkc3DMmNjZORe04ZoSqgJAGKJkPy3g__tuAuE&download=image.png "")

## 轮询的机制

![](https://tcs.teambition.net/storage/312156a9f186d6d848ebebcfffdc676a69b3?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1NmE5ZjE4NmQ2ZDg0OGViZWJjZmZmZGM2NzZhNjliMyJ9.UG9AHeZR47Ww13rVXODvIjamYgXpA_rPZNuQVzn_dVw&download=image.png "")

## 从这里拿一个 不行 就拿另外一个 直到注册成功为止

![](https://tcs.teambition.net/storage/3121c7451a45e28c5479d3794420454206fd?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjNzQ1MWE0NWUyOGM1NDc5ZDM3OTQ0MjA0NTQyMDZmZCJ9._JKIaj37T_r1WA1aN6rppbBLVNgTV0O-1Yx1A06PKhg&download=image.png "")

![](https://tcs.teambition.net/storage/3121cea88caeb3e26893ad0a238046ab9dd8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjZWE4OGNhZWIzZTI2ODkzYWQwYTIzODA0NmFiOWRkOCJ9.y1U5POe9tTG-USOb_ayKMzzz8sm4khPjEPpZeScCwhE&download=image.png "")

##  异地双活

## 距离超过1千千米

 

![](https://tcs.teambition.net/storage/3121276770203841c5a7411aab5209ca101d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyNzY3NzAyMDM4NDFjNWE3NDExYWFiNTIwOWNhMTAxZCJ9.cHyVTCu0juo3wYR4-xV7IGJJAZlLm6hB-Wl6x5JG5xo&download=image.png "")

延迟

## 主链路中不会因为最终一致性方案导致异常情况

勇敢

![](https://tcs.teambition.net/storage/312117f94f8da3a53bf1c55642a86b8b4c8f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExN2Y5NGY4ZGEzYTUzYmYxYzU1NjQyYTg2YjhiNGM4ZiJ9.OKhpPMj5E2fhL1eMEeMxgQTTmtxzltqeTE4LFZTCmU4&download=image.png "")



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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjI2OSwiaWF0IjoxNjEyMTkxNDY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.b9otBSJaZPseCD7LG1Y9O8sallteVNMfZXjOntjrM2Q&download=image.png "")

