![](https://tcs.teambition.net/storage/31225023dd159f3e669ed80208f5894a37d0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI1MDIzZGQxNTlmM2U2NjllZDgwMjA4ZjU4OTRhMzdkMCJ9.pwq3diPrtmpBXML4gLhfayZ_Xk3qjJSQNL1jy09-DHs&download=image.png "")

![](https://tcs.teambition.net/storage/3122e0fd300fbe0d46a96e8e59a23f2dab11?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJlMGZkMzAwZmJlMGQ0NmE5NmU4ZTU5YTIzZjJkYWIxMSJ9.vlbEQunpAVIE-P0SWZDFp2UH2-UMtFIcMPsA4JA1Xp8&download=image.png "")

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

    <artifactId>sleuth-traceA</artifactId>

    <dependencies>
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-client</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-web</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-actuator</artifactId>
        </dependency>

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

</project>

```

![](https://tcs.teambition.net/storage/3122b9e785348a76c077bd879fd6947fa04d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJiOWU3ODUzNDhhNzZjMDc3YmQ4NzlmZDY5NDdmYTA0ZCJ9.b2DSp6IdLME6LZbXM7dEah3j5g50PP6YJGyrfZ3F3LU&download=image.png "")

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

    <artifactId>sleuth-traceB</artifactId>

    <dependencies>
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-client</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-web</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-actuator</artifactId>
        </dependency>

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

</project>

```

![](https://tcs.teambition.net/storage/3122782e8f55330d0a1a796ad1311f80189b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI3ODJlOGY1NTMzMGQwYTFhNzk2YWQxMzExZjgwMTg5YiJ9.zUk37fEdKt4-asB7u38MInorMc9FNBz5VOmqTDkOEDw&download=image.png "")

```text
spring.application.name=sleuth-traceA
server.port=62000

eureka.client.serviceUrl.defaultZone=http://localhost:20000/eureka/

# zipkin的地址
spring.zipkin.base-url=http://localhost:62100

logging.file=${spring.application.name}.log

# 配置采样率 1 就是 100% 所有日志文件 收集出来 需要集成 zipkin才生效
spring.sleuth.sampler.probability=1

info.app.name=sleuth-traceA
info.app.description=test

management.security.enabled.user.name=gitee
management.security.enabled.user.password=gitee
management.security.enabled.user.roles=ADMIN

management.endpoints.web.exposure.include=*
management.endpoint.health.show-details=always




```

![](https://tcs.teambition.net/storage/31225fb83c360f5d2b4d0c720ec6668ada25?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI1ZmI4M2MzNjBmNWQyYjRkMGM3MjBlYzY2NjhhZGEyNSJ9.bnhNLEMsq_FPG0YxmopGT0GUpq06v0ReSQjulAMU80k&download=image.png "")

```text
spring.application.name=sleuth-traceB
server.port=62001

eureka.client.serviceUrl.defaultZone=http://localhost:20000/eureka/

# zipkin的地址
spring.zipkin.base-url=http://localhost:62100

logging.file=${spring.application.name}.log


info.app.name=sleuth-traceB
info.app.description=test

spring.sleuth.sampler.probability=1

management.security.enabled.user.name=gitee
management.security.enabled.user.password=gitee
management.security.enabled.user.roles=ADMIN

management.endpoints.web.exposure.include=*
management.endpoint.health.show-details=always




```

启动

![](https://tcs.teambition.net/storage/31223c653878da81962eb241ac2e2296d4b9?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzYzY1Mzg3OGRhODE5NjJlYjI0MWFjMmUyMjk2ZDRiOSJ9.jkrFZ9laEYKdnpsysybDUz6IRHjN7RysvsZxVlGdb3k&download=image.png "")

![](https://tcs.teambition.net/storage/3122af1bb31238509f1dab098cd0bebbac4e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhZjFiYjMxMjM4NTA5ZjFkYWIwOThjZDBiZWJiYWM0ZSJ9.pgmlukzNeduNwZ2sqtWGV-KTTTX05Pcq4q8W_x4iiuM&download=image.png "")

![](https://tcs.teambition.net/storage/31228e6ee4127908581feac6c6e880749891?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI4ZTZlZTQxMjc5MDg1ODFmZWFjNmM2ZTg4MDc0OTg5MSJ9.Rfrb4FbMihPCcCvwXeLaq74UHKCzlQF48HyPl9cFaow&download=image.png "")

```text
10:10:59.671  INFO [-,ed34f7b3a21db96a,ed34f7b3a21db96a,true] 66637 --- [io-62001-exec-2] -------Trace B
10:11:02.123  INFO [-,,,] 66637 --- [ender@336f49a1}] Flipping property: localhost.ribbon.ActiveConnectionsLimit to use NEXT property: niws.loadbalancer.availabilityFilteringRule.activeConnectionsLimit = 2147483647
10:11:02.360  INFO [-,,,] 66637 --- [ender@336f49a1}] Shutdown hook installed for: NFLoadBalancer-PingTimer-localhost
10:11:02.375  INFO [-,,,] 66637 --- [ender@336f49a1}] Client: localhost instantiated a LoadBalancer: DynamicServerListLoadBalancer:{NFLoadBalancer:name=localhost,current list of Servers=[],Load balancer stats=Zone stats: {},Server stats: []}ServerList:null
10:11:02.432  INFO [-,,,] 66637 --- [ender@336f49a1}] Using serverListUpdater PollingServerListUpdater
10:11:02.447  INFO [-,,,] 66637 --- [ender@336f49a1}] DynamicServerListLoadBalancer for client localhost initialized: DynamicServerListLoadBalancer:{NFLoadBalancer:name=localhost,current list of Servers=[],Load balancer stats=Zone stats: {},Server stats: []}ServerList:org.springframework.cloud.netflix.ribbon.eureka.DomainExtractingServerList@515ca21b


```

![](https://tcs.teambition.net/storage/3122cffd5ad14b98fbd678d77d5c07152762?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJjZmZkNWFkMTRiOThmYmQ2NzhkNzdkNWMwNzE1Mjc2MiJ9.J5aTgGvnIJCvlzD_m9HzdTOAyYxt4SuYYvJM6jhy_dQ&download=image.png "")

![](https://tcs.teambition.net/storage/3122ab629ef2cae667e85f35140f1298eb06?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhYjYyOWVmMmNhZTY2N2U4NWYzNTE0MGYxMjk4ZWIwNiJ9.-FIxZP2GVAidQasuP_7Eu2Naz3ecH7vGvSwBHm_kYpY&download=image.png "")

```text
10:13:00.868  INFO [-,9d31dfc076f7602c,9d31dfc076f7602c,true] 66808 --- [io-62000-exec-1] -------Trace A
10:13:02.044  INFO [-,9d31dfc076f7602c,c161d95a2ee87253,true] 66808 --- [io-62000-exec-1] Flipping property: sleuth-traceB.ribbon.ActiveConnectionsLimit to use NEXT property: niws.loadbalancer.availabilityFilteringRule.activeConnectionsLimit = 2147483647
10:13:02.156  INFO [-,9d31dfc076f7602c,c161d95a2ee87253,true] 66808 --- [io-62000-exec-1] Shutdown hook installed for: NFLoadBalancer-PingTimer-sleuth-traceB
10:13:02.159  INFO [-,9d31dfc076f7602c,c161d95a2ee87253,true] 66808 --- [io-62000-exec-1] Client: sleuth-traceB instantiated a LoadBalancer: DynamicServerListLoadBalancer:{NFLoadBalancer:name=sleuth-traceB,current list of Servers=[],Load balancer stats=Zone stats: {},Server stats: []}ServerList:null
10:13:02.477  INFO [-,9d31dfc076f7602c,c161d95a2ee87253,true] 66808 --- [io-62000-exec-1] Using serverListUpdater PollingServerListUpdater
10:13:02.558  INFO [-,9d31dfc076f7602c,c161d95a2ee87253,true] 66808 --- [io-62000-exec-1] Flipping property: sleuth-traceB.ribbon.ActiveConnectionsLimit to use NEXT property: niws.loadbalancer.availabilityFilteringRule.activeConnectionsLimit = 2147483647
10:13:02.563  INFO [-,9d31dfc076f7602c,c161d95a2ee87253,true] 66808 --- [io-62000-exec-1] DynamicServerListLoadBalancer for client sleuth-traceB initialized: DynamicServerListLoadBalancer:{NFLoadBalancer:name=sleuth-traceB,current list of Servers=[192.168.4.100:62001],Load balancer stats=Zone stats: {defaultzone=[Zone:defaultzone;	Instance count:1;	Active connections count: 0;	Circuit breaker tripped count: 0;	Active connections per server: 0.0;]
},Server stats: [[Server:192.168.4.100:62001;	Zone:defaultZone;	Total Requests:0;	Successive connection failure:0;	Total blackout seconds:0;	Last connection made:Thu Jan 01 08:00:00 CST 1970;	First connection made: Thu Jan 01 08:00:00 CST 1970;	Active Connections:0;	total failure count in last (1000) msecs:0;	average resp time:0.0;	90 percentile resp time:0.0;	95 percentile resp time:0.0;	min resp time:0.0;	max resp time:0.0;	stddev resp time:0.0]
]}ServerList:org.springframework.cloud.netflix.ribbon.eureka.DomainExtractingServerList@457fcc0f
10:13:03.253  INFO [-,,,] 66808 --- [ender@7f12094d}] Flipping property: localhost.ribbon.ActiveConnectionsLimit to use NEXT property: niws.loadbalancer.availabilityFilteringRule.activeConnectionsLimit = 2147483647
10:13:03.257  INFO [-,,,] 66808 --- [ender@7f12094d}] Shutdown hook installed for: NFLoadBalancer-PingTimer-localhost
10:13:03.258  INFO [-,,,] 66808 --- [ender@7f12094d}] Client: localhost instantiated a LoadBalancer: DynamicServerListLoadBalancer:{NFLoadBalancer:name=localhost,current list of Servers=[],Load balancer stats=Zone stats: {},Server stats: []}ServerList:null
10:13:03.265  INFO [-,,,] 66808 --- [ender@7f12094d}] Using serverListUpdater PollingServerListUpdater
10:13:03.267  INFO [-,,,] 66808 --- [ender@7f12094d}] DynamicServerListLoadBalancer for client localhost initialized: DynamicServerListLoadBalancer:{NFLoadBalancer:name=localhost,current list of Servers=[],Load balancer stats=Zone stats: {},Server stats: []}ServerList:org.springframework.cloud.netflix.ribbon.eureka.DomainExtractingServerList@1867a31c
10:13:03.490  INFO [-,,,] 66808 --- [erListUpdater-0] Flipping property: sleuth-traceB.ribbon.ActiveConnectionsLimit to use NEXT property: niws.loadbalancer.availabilityFilteringRule.activeConnectionsLimit = 2147483647


```

![](https://tcs.teambition.net/storage/3122c31870aa53917aca9f4264d3f7048bf2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJjMzE4NzBhYTUzOTE3YWNhOWY0MjY0ZDNmNzA0OGJmMiJ9.F_vGIUk2zFi-YoaV9WXnz6FSU86SWcuddYhmK-JGX-M&download=image.png "")

![](https://tcs.teambition.net/storage/31225da3994c77c3ff63ae4cace613be3770?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI1ZGEzOTk0Yzc3YzNmZjYzYWU0Y2FjZTYxM2JlMzc3MCJ9.AeaXGF41Gog2IRJ6ZhhPYubY2sqhCcbU042Y87JMqIg&download=image.png "")

![](https://tcs.teambition.net/storage/3122df03065759c455d93fb0a744ade58747?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkZjAzMDY1NzU5YzQ1NWQ5M2ZiMGE3NDRhZGU1ODc0NyJ9.7xQVWXO23BSZ36N5suLFGiU-DhjoIz5f8IWKX84O0_8&download=image.png "")

![](https://tcs.teambition.net/storage/3122a5b81c655c9ae7b898984aab5852ee4d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhNWI4MWM2NTVjOWFlN2I4OTg5ODRhYWI1ODUyZWU0ZCJ9.21eLoy2pbKUvFQMB64jdSCJH4k4LA_KX_e8jhNhDfU4&download=image.png "")

![](https://tcs.teambition.net/storage/3122a05375d075cac0a431722e57421cdb72?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhMDUzNzVkMDc1Y2FjMGE0MzE3MjJlNTc0MjFjZGI3MiJ9.ysRT49GEx9Rgzc_nDwZldbAJ9VHK44Ifp4epCf_uKRU&download=image.png "")

花费的总时间

![](https://tcs.teambition.net/storage/31227949be4fe99f24d3ede7d08398267783?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI3OTQ5YmU0ZmU5OWYyNGQzZWRlN2QwODM5ODI2Nzc4MyJ9.p_0mGINTySsJFxwGczZq13wYiwOf5T6CyjfZm5BmGUM&download=image.png "")

span的个数

![](https://tcs.teambition.net/storage/31220ff6d7560772ecdb8f073caf8fce97bc?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIwZmY2ZDc1NjA3NzJlY2RiOGYwNzNjYWY4ZmNlOTdiYyJ9.mZGnx_NFK-y54Xq5DcfoKT2uBqwwfPEMPnOR_dYKths&download=image.png "")

占了总采用时间 80%的时间花费

剩下的 20%就是 traceA 因为调用了TraceB



单独调用 traceB的情况

![](https://tcs.teambition.net/storage/3122bfc4f05a8c6a58aa84af4888a2fb9961?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJiZmM0ZjA1YThjNmE1OGFhODRhZjQ4ODhhMmZiOTk2MSJ9.EsqECLh7B-tTAQXVQqsrso-H39M1UWuPwQ8vivd0slc&download=image.png "")

![](https://tcs.teambition.net/storage/3122d5cefb366bb73bcdd8577fb45c913fc9?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkNWNlZmIzNjZiYjczYmNkZDg1NzdmYjQ1YzkxM2ZjOSJ9.M08nYMNqo4s66qE4zgEaDo8nKsnqgVvpQBfCyhoHxx0&download=image.png "")

![](https://tcs.teambition.net/storage/3122e6a95c203f5f8678c3b932b0dd06e594?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJlNmE5NWMyMDNmNWY4Njc4YzNiOTMyYjBkZDA2ZTU5NCJ9.O6cO85cRWp-4lHC4ozumM48RdzjBiymOWY4z3_MxmsM&download=image.png "")

请求方法 路径的名称

![](https://tcs.teambition.net/storage/3122fc1a9ee965a48d83fe727182f8c48eb0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJmYzFhOWVlOTY1YTQ4ZDgzZmU3MjcxODJmOGM0OGViMCJ9.pua9CEyl9RWwMG5X5AHle9YpQ5movGCEnGWGCy2dNKg&download=image.png "")

一个span当中 不同的annotation 之间的花费

![](https://tcs.teambition.net/storage/31229b90fbd99369a4199e5593500793cf7a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5YjkwZmJkOTkzNjlhNDE5OWU1NTkzNTAwNzkzY2Y3YSJ9.pB_IgCO2NbRI8l2jV0neosOfjKKc025Sd5KcPHIjcVw&download=image.png "")

调用情况



![](https://tcs.teambition.net/storage/312269e46db520fbb7676351968504ddfb96?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI2OWU0NmRiNTIwZmJiNzY3NjM1MTk2ODUwNGRkZmI5NiJ9.nSUNtCpcIk2CZ_m4Ov3X6odbIgksh5u8McJTF8Z3G5c&download=image.png "")

IP 地址

![](https://tcs.teambition.net/storage/3122f30aaf2ddaf16ad76efc2e19957a3f01?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJmMzBhYWYyZGRhZjE2YWQ3NmVmYzJlMTk5NTdhM2YwMSJ9.IQWbVbCO5ECWvQwQs8A-caPNdEUJYr0FU0VjSj9Nam0&download=image.png "")



那个类

![](https://tcs.teambition.net/storage/31229e12213bfbcaa573b09ec1e9bd360abd?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5ZTEyMjEzYmZiY2FhNTczYjA5ZWMxZTliZDM2MGFiZCJ9.YF9f95NhJ59nlX3PVmDNeVzzoV5eR1QpKRV_xtBOn7w&download=image.png "")



方法

![](https://tcs.teambition.net/storage/31226b1586a25ebaf40aee4225afc35207bf?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI2YjE1ODZhMjVlYmFmNDBhZWU0MjI1YWZjMzUyMDdiZiJ9.6mauswjYBCDj5EfKdQvnUxAj3J3AaqmjdZJHDJ5ZTfc&download=image.png "")

spanId 自己的ID

traceId 整个 链路的ID

![](https://tcs.teambition.net/storage/312285302affc008319b288410609418a1f6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI4NTMwMmFmZmMwMDgzMTliMjg4NDEwNjA5NDE4YTFmNiJ9.x0UVreLxMP3qW3PVVjF6xfxS7SQWITWcPnGaKAKwNdw&download=image.png "")

```text
	ed34f7b3a21db96a

```

![](https://tcs.teambition.net/storage/312245ebbbc45b853b32798f3fde88ed6409?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI0NWViYmJjNDViODUzYjMyNzk4ZjNmZGU4OGVkNjQwOSJ9.BIykFVavlC0FNab-iRfzj_iuZVEyqsP0GcYOinrA1H0&download=image.png "")

![](https://tcs.teambition.net/storage/312201af25e1a564bcef3d8d8af01ac989d8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIwMWFmMjVlMWE1NjRiY2VmM2Q4ZDhhZjAxYWM5ODlkOCJ9.WrJWH06b9JPzrQ_bUNvycq2vmIGgtbDea3J5MtnZqjA&download=image.png "")

![](https://tcs.teambition.net/storage/3122e5c383f8865acca8a3503d342e1998c5?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJlNWMzODNmODg2NWFjY2E4YTM1MDNkMzQyZTE5OThjNSJ9.tbFxOo4aQC-WkBssOTBN_s7RU4TxnZsfHALJlB66eoQ&download=image.png "")

![](https://tcs.teambition.net/storage/3122b150e03a895c8fe0cd305713c0e1414f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJiMTUwZTAzYTg5NWM4ZmUwY2QzMDU3MTNjMGUxNDE0ZiJ9.voUFIKLTaIDd7avqNvJ_Q2j02ko5BiHcSVHCD87wVpo&download=image.png "")

两个维度信息 一个是花费的时间 一个是在这个调用链所处的位置



![](https://tcs.teambition.net/storage/3122630ff28d6860d35bb31857edc2626541?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI2MzBmZjI4ZDY4NjBkMzViYjMxODU3ZWRjMjYyNjU0MSJ9.0l1WzJoZMWORNzF_cPrILPp-sWWSsE55oAlDteu0ivI&download=image.png "")

http方法与路径的组合



![](https://tcs.teambition.net/storage/3122f3351f8a0140dd4e52bc8e966113e9cd?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJmMzM1MWY4YTAxNDBkZDRlNTJiYzhlOTY2MTEzZTljZCJ9.mkvUksTMEmi__UTjfZoHN8P0XRiWVAwm9eqymarFOZ0&download=image.png "")

过去的时间记录



自定义时间的记录

![](https://tcs.teambition.net/storage/3122863be799103746e9764b7261aa536540?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI4NjNiZTc5OTEwMzc0NmU5NzY0YjcyNjFhYTUzNjU0MCJ9.-4rgs3K-Fi1EChuncWjnrX0otKRAZk3U3ZlIfsvMeV4&download=image.png "")

显示条数限制

![](https://tcs.teambition.net/storage/312235419c55db901e2245874d3d8a5468f0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzNTQxOWM1NWRiOTAxZTIyNDU4NzRkM2Q4YTU0NjhmMCJ9.wRJGqkWp51Wf7F-5CM1zfdBnhXYDj-6jUWIAvyjSQhQ&download=image.png "")



根据时间维度查找信息 微秒

![](https://tcs.teambition.net/storage/3122ad340bad731cf11070e2911bb7a72561?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhZDM0MGJhZDczMWNmMTEwNzBlMjkxMWJiN2E3MjU2MSJ9.uLyqcmr0UVBUVxfpUjTmOMisVn31lOpzzeSH2xN3S5A&download=image.png "")



复杂搜索

![](https://tcs.teambition.net/storage/3122a91b7379d3b812b54efbc11519e67095?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhOTFiNzM3OWQzYjgxMmI1NGVmYmMxMTUxOWU2NzA5NSJ9.J6TcxuKsjGDCpXtLqExQ4lJ7alI9YKBl5IxhoNkHSq4&download=image.png "")



选择文件

![](https://tcs.teambition.net/storage/31225cefe4e97eb59dc6a4c17dabf85e1fa6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI1Y2VmZTRlOTdlYjU5ZGM2YTRjMTdkYWJmODVlMWZhNiJ9.1YXgRd7Nb0KSUnN60YCbvjEp8ycRruU3oUZlyfMldKs&download=image.png "")

梳理上下游调用链路

![](https://tcs.teambition.net/storage/3122c2195bde9d6108e2f63fd580af14be25?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJjMjE5NWJkZTlkNjEwOGUyZjYzZmQ1ODBhZjE0YmUyNSJ9.BlAzXcCAhuS0S-iSVDSDV3ICrYYiLXEDlII8mCIx6sQ&download=image.png "")

时间选择框

![](https://tcs.teambition.net/storage/31229746e90f0bc00d8bda8d9af67b63397a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5NzQ2ZTkwZjBiYzAwZDhiZGE4ZDlhZjY3YjYzMzk3YSJ9.nqPcPKsOD6pbwF9mLVskjGY0RmCUNTs6k4n54mDcHLU&download=image.png "")

从时间维度调用链路分析的组件



排序花费时间最长的服务

![](https://tcs.teambition.net/storage/3122370197f4ebd2e41b00bf1cc04e3257f4?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzNzAxOTdmNGViZDJlNDFiMDBiZjFjYzA0ZTMyNTdmNCJ9.48oC0TBCPeX_c2GcgC6-lMn2xQUDbHX75SVcnM1Fc-c&download=image.png "")

![](https://tcs.teambition.net/storage/3122372e84db0616e78a1d4195f718a0a4a7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzNzJlODRkYjA2MTZlNzhhMWQ0MTk1ZjcxOGEwYTRhNyJ9.vFn4Y7fbdZXXrNw9ouA-fGgYC8WYE1FTctNQH6yI_x4&download=image.png "")











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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTI1MiwiaWF0IjoxNjEyMTkwNDUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.JfFVtl3dk4t0goZeJ7gABBUKFJIWwIBWeONz5CbKJIo&download=image.png "")

