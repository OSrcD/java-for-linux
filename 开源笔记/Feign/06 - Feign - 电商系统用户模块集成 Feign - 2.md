![]( "")

在下游中配置

![](https://tcs.teambition.net/storage/312164890efcd7936d69594b8411d14cfed0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkyNSwiaWF0IjoxNjEyMTkxMTI1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2NDg5MGVmY2Q3OTM2ZDY5NTk0Yjg0MTFkMTRjZmVkMCJ9.3o0_9FVdWAiVOTR-Zsoje05ih90vKrQtLp7b2puu1hs&download=image.png "")

![](https://tcs.teambition.net/storage/3121aaf733e96445fa09834b00ed5859cc2d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkyNSwiaWF0IjoxNjEyMTkxMTI1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhYWY3MzNlOTY0NDVmYTA5ODM0YjAwZWQ1ODU5Y2MyZCJ9.Mi36Yj9I4IuM-PQLmnD6XcVXRBfKcRHfNYUc0ily5Zk&download=image.png "")

![](https://tcs.teambition.net/storage/31214db488b683dd5665dc7fe726ca00e97f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkyNSwiaWF0IjoxNjEyMTkxMTI1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0ZGI0ODhiNjgzZGQ1NjY1ZGM3ZmU3MjZjYTAwZTk3ZiJ9.-iX8T9txU9OKByWKMIROSkZs-QWhf_6x1e-qmwNUsDg&download=image.png "")



## 基于Feign的配置

![](https://tcs.teambition.net/storage/31219fb553bb237d11af4206479ed81a488b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkyNSwiaWF0IjoxNjEyMTkxMTI1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5ZmI1NTNiYjIzN2QxMWFmNDIwNjQ3OWVkODFhNDg4YiJ9.skXcoaLnuoT6iZu4EaXLuUyNSghIBtIjImJx0t0WGgs&download=image.png "")

这里的Feign ReadTimeout 覆盖 ribbon里的ReadTimeout 

![](https://tcs.teambition.net/storage/312118328055aff35ba261c6fba4eed8200b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkyNSwiaWF0IjoxNjEyMTkxMTI1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExODMyODA1NWFmZjM1YmEyNjFjNmZiYTRlZWQ4MjAwYiJ9.nTMYd1vWwHCu-9ADqJBtmUtPrRo_C1uXsD4hTT_qBGY&download=image.png "")

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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkyNSwiaWF0IjoxNjEyMTkxMTI1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.jN82EeCwFhIIWQcEMD4Wj0YQKasS5_deR9I2c2i28tM&download=image.png "")

