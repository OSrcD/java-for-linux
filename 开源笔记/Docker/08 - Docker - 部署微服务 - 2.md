![](https://tcs.teambition.net/storage/31225117b776f96d3a883c4162a506310a4d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjk1ODc2MywiaWF0IjoxNjEyMzUzOTYzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI1MTE3Yjc3NmY5NmQzYTg4M2M0MTYyYTUwNjMxMGE0ZCJ9.rl0BtsdJquEusweZw6UnEJy7RmJeHI1tTUoHJrrOPJI&download=image.png "")

```text
FROM java:8
ADD registry-center-1.0-SNAPSHOT.jar registry-center-1.0-SNAPSHOT.jar
# 容器启动的时候运行命令
ENTRYPOINT ["java","-jar","registry-center-1.0-SNAPSHOT.jar"]

```



![](https://tcs.teambition.net/storage/312295ddb1771e3831777ede760fbb3bf688?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjk1OTE5MSwiaWF0IjoxNjEyMzU0MzkxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5NWRkYjE3NzFlMzgzMTc3N2VkZTc2MGZiYjNiZjY4OCJ9.b8MRn25eFSCVV__ZKVL_4O5glaL3K_-rW9p7pWK6xZg&download=image.png "")

![](https://tcs.teambition.net/storage/312243d71e83ec6d39764c539b997ef72db7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjk1OTE5OCwiaWF0IjoxNjEyMzU0Mzk4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI0M2Q3MWU4M2VjNmQzOTc2NGM1MzliOTk3ZWY3MmRiNyJ9.rejncz_5KK0kBTCQAb3c5JrAW8q2SdLn7LVmJJdaqH8&download=image.png "")

![](https://tcs.teambition.net/storage/31225c10d369eb9488752f3b0b4eac9d3fc1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjk1OTY0MywiaWF0IjoxNjEyMzU0ODQzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI1YzEwZDM2OWViOTQ4ODc1MmYzYjBiNGVhYzlkM2ZjMSJ9.zgRmSy1Ah6zt5uflA5Kq_G_kCjJ9rs73VQvYd2qeelw&download=image.png "")

docker build -t myregistry .



![](https://tcs.teambition.net/storage/3122e410a8b20eafe18413214529967f3d11?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjk1OTY2OCwiaWF0IjoxNjEyMzU0ODY4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJlNDEwYThiMjBlYWZlMTg0MTMyMTQ1Mjk5NjdmM2QxMSJ9.khS13bsiwGFbNYE4w3is5b2IKb1Nh56WnTJD-7JsrxU&download=image.png "")

![](https://tcs.teambition.net/storage/3122dfdc32231a2edc7d432cfaca412ec2cd?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjk1OTc1NywiaWF0IjoxNjEyMzU0OTU3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkZmRjMzIyMzFhMmVkYzdkNDMyY2ZhY2E0MTJlYzJjZCJ9.5N7VVzjeL7X6GAfsob5SDxAHjWsH0yHFDMkSF3qBbLE&download=image.png "")

开始启动容器

docker run -d -p 20000:20000 --name myregistry myregistry

![](https://tcs.teambition.net/storage/312299e97dbdd76f13c321602c57c0f6f0ea?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjk1OTg4NiwiaWF0IjoxNjEyMzU1MDg2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5OWU5N2RiZGQ3NmYxM2MzMjE2MDJjNTdjMGY2ZjBlYSJ9.kKUfWRDMVzSEEkAT3oevvgh7dEgKidgQAHMB8y1at4U&download=image.png "")

![](https://tcs.teambition.net/storage/3122b4253b70126142c0d56e5617a484e381?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjk2MjIxOCwiaWF0IjoxNjEyMzU3NDE4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJiNDI1M2I3MDEyNjE0MmMwZDU2ZTU2MTdhNDg0ZTM4MSJ9.540wR04y35boNDS_-f3517xQCsKC0UuTbmBPhPg0rlU&download=image.png "")

![](https://tcs.teambition.net/storage/3122ac6207fd552e422849bc314a9ff093e9?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjk2MzM3NSwiaWF0IjoxNjEyMzU4NTc1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhYzYyMDdmZDU1MmU0MjI4NDliYzMxNGE5ZmYwOTNlOSJ9.2Rerh9iVKdCmp5I4MdUw8YkZnIQYTG5rblh-6sFI-p0&download=image.png "")

![](https://tcs.teambition.net/storage/31226f85540cce723f2b78f712cfd332927d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjk2MzQyMiwiaWF0IjoxNjEyMzU4NjIyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI2Zjg1NTQwY2NlNzIzZjJiNzhmNzEyY2ZkMzMyOTI3ZCJ9.gknD_fnFMWvh05260ujA71_hXlfCdl_3GXB968KmZDs&download=image.png "")

![](https://tcs.teambition.net/storage/3122a6274e98874918d01ffd2adc87386dfb?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjk2NDUzOSwiaWF0IjoxNjEyMzU5NzM5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhNjI3NGU5ODg3NDkxOGQwMWZmZDJhZGM4NzM4NmRmYiJ9.PVB81dsw5TBPOTfA37wHC0v7uclBB7feNFVgKwL-8K8&download=image.png "")

![](https://tcs.teambition.net/storage/3122d0995f05adbd1a5115208371ed4df66c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjk2NDMxMSwiaWF0IjoxNjEyMzU5NTExLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkMDk5NWYwNWFkYmQxYTUxMTUyMDgzNzFlZDRkZjY2YyJ9.Y6-yV609PdVTRTMYIzydHexrS7cihcg5ixiIlfLBHUU&download=image.png "")

```text
vim /etc/sysconfig/network-scripts/ifcfg-eth1 


DEVICE=eth1
ONBOOT=yes
NM_CONTROLLED=no
BOOTPROTO=static
IPADDR=10.34.96.3
NETMASK=255.255.240.0
IPV6INIT=no
MTU=1450


service network restart

```

![](https://tcs.teambition.net/storage/312213af04e477ae17b6660bc95c195d2bad?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjk2NDU4MiwiaWF0IjoxNjEyMzU5NzgyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxM2FmMDRlNDc3YWUxN2I2NjYwYmM5NWMxOTVkMmJhZCJ9.Hkkt8hj4gz2AAJvNNW6kugg43jcsVdQGlVgW27QBIqo&download=image.png "")

![](https://tcs.teambition.net/storage/3122ad13bb9d3dab2a9be4510e53be8ec567?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjk2NDY4NSwiaWF0IjoxNjEyMzU5ODg1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhZDEzYmI5ZDNkYWIyYTliZTQ1MTBlNTNiZThlYzU2NyJ9.zYgA_l3-R9fa3kxHe7alOM42eqlP7f-jecePnbJaE00&download=image.png "")

```yaml
server:
  port: 20003


spring:
  application:
    name: config-server
  ## rabbitMQ用于Bus推送 生产环境
  rabbitmq:
    host: 10.34.96.3
    port: 5672
    username: guest
    password: guest
  cloud:
    config:
      server:
        overrides:
          # 属性重载 也就是把属性覆盖掉吧
          test: mytest
        git:
          uri: https://github.com/OSrcD/foodie-cloud-config.git
          force-pull: true
          # 在主目录创建不同的文件夹 管理配置文件
          # 将配置文件放到接入方服务名称对应文件夹下
          search-paths: '{application}'
          # username:
          # password:
# 本地环境
#eureka:
#  client:
#    serviceUrl:
#      defaultZone: http://localhost:20000/eureka/
# 生产环境
eureka:
  client:
    serviceUrl:
      defaultZone: http://10.34.96.3:20000/eureka/
  # 生产环境
  # 使用 ip 地址形式注册 希望以ip地址是形式在Eureka里面进行互通
  instance:
    # IP 地址部署默认容器的 ip 地址 容器会起一个自己内部的私有ip地址
    # 这个ip地址外网不能访问的 所以我们要指定服务器的地址 端口还是容器的端口
    # 10.34.96.3:20003
    instance-id: ${eureka.instance.ip-address}:${server.port}
    ip-address: 10.34.96.3
    prefer-ip-address: true

## 开启所有actuator-endpoint
management:
  security:
    enabled: false
  endpoints:
    web:
      exposure:
        include: "*"
  endpoint:
    health:
      show-details: always
```

![](https://tcs.teambition.net/storage/3122f12c68e2b9d0e061291807862fc78216?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjk2Nzk3NiwiaWF0IjoxNjEyMzYzMTc2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJmMTJjNjhlMmI5ZDBlMDYxMjkxODA3ODYyZmM3ODIxNiJ9.Gz266rjJp-SJHe76h5YPtCga_dVYNynuVysmq1lx-_Q&download=image.png "")

![](https://tcs.teambition.net/storage/3122ac62fc53fb749728c0d3bfa4a26f4f48?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjk2ODAwMywiaWF0IjoxNjEyMzYzMjAzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhYzYyZmM1M2ZiNzQ5NzI4YzBkM2JmYTRhMjZmNGY0OCJ9.8i8JHvbVxjpnKrtxSbTSwpHEo5DxoBIHDk6tKt_OsZk&download=image.png "")

![](https://tcs.teambition.net/storage/31228e083374020ec051a174885d4caf3535?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjk2ODAzMiwiaWF0IjoxNjEyMzYzMjMyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI4ZTA4MzM3NDAyMGVjMDUxYTE3NDg4NWQ0Y2FmMzUzNSJ9.h_3XZBDiIHPRYUdJh5BwOLpZq59SXPBdhsWEy9e7lqk&download=image.png "")

![](https://tcs.teambition.net/storage/31228ac0543bea1ca6dd34b3193f5b35889f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjk2ODEzMSwiaWF0IjoxNjEyMzYzMzMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI4YWMwNTQzYmVhMWNhNmRkMzRiMzE5M2Y1YjM1ODg5ZiJ9.BwFusbZ7TJ-rEJZxr9an4xGxx-7O5oo3JqzTPXjl_dE&download=image.png "")

![](https://tcs.teambition.net/storage/3122f3529c2111db8749d9852886f0f45091?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjk2ODE5MiwiaWF0IjoxNjEyMzYzMzkyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJmMzUyOWMyMTExZGI4NzQ5ZDk4NTI4ODZmMGY0NTA5MSJ9.OY6jlONaCekGw2iFU-uliHXgl2DYh9qeBAA_N2jtzGc&download=image.png "")

![](https://tcs.teambition.net/storage/31229ff13e73c953eea3bd69853d1dcfa1e7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjk2ODIyOSwiaWF0IjoxNjEyMzYzNDI5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5ZmYxM2U3M2M5NTNlZWEzYmQ2OTg1M2QxZGNmYTFlNyJ9.giqHtpnkKh6cFA2evbhkioGoiOxs9gZD4IbKF3q4vME&download=image.png "")

![](https://tcs.teambition.net/storage/3122d0022740fa503d3ad60c52dd028d410d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjk2ODI1NSwiaWF0IjoxNjEyMzYzNDU1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkMDAyMjc0MGZhNTAzZDNhZDYwYzUyZGQwMjhkNDEwZCJ9.TJL_SpuAZQgpt-Gi4tcQr-oK0LF51XX12sDzPtuu1ag&download=image.png "")

![](https://tcs.teambition.net/storage/31220eae9970d333560803368b7274c94ae1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjk2ODMyMywiaWF0IjoxNjEyMzYzNTIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIwZWFlOTk3MGQzMzM1NjA4MDMzNjhiNzI3NGM5NGFlMSJ9.DCoG0hYc-ysLAsbedkfyXvEc-bDfTuV5xgqEbBVp5zQ&download=image.png "")

![](https://tcs.teambition.net/storage/312247f08b7601e54174e5efd96820c89b93?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjk2ODQ1MiwiaWF0IjoxNjEyMzYzNjUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI0N2YwOGI3NjAxZTU0MTc0ZTVlZmQ5NjgyMGM4OWI5MyJ9.u7yDwH4nuX-XtB7tmMwOSEwjRMPxwB2bFI3NES524HI&download=image.png "")

通过内网的IP的端口 与容器里面的端口进行映射



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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjk1ODc2MywiaWF0IjoxNjEyMzUzOTYzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.BZ_9a7fM_HICCx0IUuzsykbi_xpz1dtuKmoIDRKyN18&download=image.png "")

