

![](https://tcs.teambition.net/storage/312188fc1dbdc3271a438d4258a701aa6591?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU2MSwiaWF0IjoxNjEyMTkwNzYxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4OGZjMWRiZGMzMjcxYTQzOGQ0MjU4YTcwMWFhNjU5MSJ9.i8fue2vNbCA5AiIR2Y8IJpq-rWgqN-lDw4oTVbsK6PY&download=image.png "")

![](https://tcs.teambition.net/storage/3121b9b44bff0ad195ffbbdb53c60509179c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU2MSwiaWF0IjoxNjEyMTkwNzYxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiOWI0NGJmZjBhZDE5NWZmYmJkYjUzYzYwNTA5MTc5YyJ9.gRWJ6PX01YGD6EYwcnGCxiUifERlvIy5KvNS7i-SihY&download=image.png "")

```text
b19c790944906dc1c1eb702cc6718497419d3164e963372f25a5d6bf8c78a8c8

```

![](https://tcs.teambition.net/storage/31216c127a72fd2cc07d05401b26047cc287?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU2MSwiaWF0IjoxNjEyMTkwNzYxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2YzEyN2E3MmZkMmNjMDdkMDU0MDFiMjYwNDdjYzI4NyJ9.jZOPIczCusztv-31mc19nFZqYp7Ddltzd5crrBcvQXw&download=image.png "")

```yaml
# 数据库连接串 & 密码
mariadb:
  url: 'jdbc:mysql://localhost:3306/foodie-shop-dev?useUnicode=true&characterEncoding=UTF-8&autoReconnect=true'
  password: '{cipher}b19c790944906dc1c1eb702cc6718497419d3164e963372f25a5d6bf8c78a8c8'
 
 
 
 # 功能开关 - 开启/关闭注册功能
 userservice:
  registration:
    disabled: true
```

![](https://tcs.teambition.net/storage/31216b6f5d16166670fafd496abb0c8d0a30?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU2MSwiaWF0IjoxNjEyMTkwNzYxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2YjZmNWQxNjE2NjY3MGZhZmQ0OTZhYmIwYzhkMGEzMCJ9.T9oJQd6DVf96clGjpstUiAzpplOTP5Obx1YMqcPPwOg&download=image.png "")

```yaml
# 公共的配置 注册中心在拉取配置的时候 发现dev 配置里没有 而 这个文件里有的配置 会 拉取这些没有的配置

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

![](https://tcs.teambition.net/storage/312196c17355bc3ba6a3e01c4e50b6717d8e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU2MSwiaWF0IjoxNjEyMTkwNzYxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5NmMxNzM1NWJjM2JhNmEzZTAxYzRlNTBiNjcxN2Q4ZSJ9.W0cvepYF7RRmYNiZ_3WxQAaLbkR9sd5KGm3QvPxzvJU&download=image.png "")

![](https://tcs.teambition.net/storage/3121c300b2baa0ffa81be6455b69f366fb32?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU2MSwiaWF0IjoxNjEyMTkwNzYxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjMzAwYjJiYWEwZmZhODFiZTY0NTViNjlmMzY2ZmIzMiJ9.L0b1jFMvIv4qSaplb4TGp8NvCoRE8STQdF_wFIGOZCM&download=image.png "")

![](https://tcs.teambition.net/storage/31219c58976a93b485a9dff419a12b45b571?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU2MSwiaWF0IjoxNjEyMTkwNzYxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5YzU4OTc2YTkzYjQ4NWE5ZGZmNDE5YTEyYjQ1YjU3MSJ9.mYWxydzhamku2MuQs86MUV4Iv_Da0hvhXTx_F-W7n9s&download=image.png "")

```json
{
    "name": "foodie-user-service",
    "profiles": [
        "dev"
    ],
    "label": "main",
    "version": "9399808fe0dbdd605dfc8945bed6a21c64ceb0d1",
    "state": null,
    "propertySources": [
        {
            "name": "overrides",
            "source": {
                "test": "mytest"
            }
        },
        {
            "name": "https://github.com/OSrcD/foodie-cloud-config.git/foodie-user-service/foodie-user-service-dev.yml",
            "source": {
                "mariadb.url": "jdbc:mysql://localhost:3306/foodie-shop-dev?useUnicode=true&characterEncoding=UTF-8&autoReconnect=true",
                "userservice.registration.disabled": false,
                "mariadb.password": ""
            }
        },
        {
            "name": "https://github.com/OSrcD/foodie-cloud-config.git/foodie-user-service/foodie-user-service.yml",
            "source": {
                "management.endpoint.health.show-details": "always",
                "management.endpoints.web.exposure.include": "*",
                "management.security.enabled": false,
                "management.security.user.name": "gitee",
                "management.security.user.password": "gitee",
                "management.security.user.roles": "ADMIN"
            }
        }
    ]
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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTU2MSwiaWF0IjoxNjEyMTkwNzYxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.B6mpno5eqa4fEE1M-4IzZck6SxT0HJ6Dxrw9PzMwpTw&download=image.png "")

