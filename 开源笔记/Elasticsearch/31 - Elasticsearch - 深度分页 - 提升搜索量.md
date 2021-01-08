![](https://tcs.teambition.net/storage/3121f9e68d1daa23835295e199b6397109df?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjY2MSwiaWF0IjoxNjEwMDk3ODYxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmOWU2OGQxZGFhMjM4MzUyOTVlMTk5YjYzOTcxMDlkZiJ9.UNKMJNhwVmL1VL1rYOJ8I6obHesDKXJTgyDIBjvT02Y&download=2020-09-17%20175602.png "")

## max_result_window 突破搜索量

## _settings 查看设置

![](https://tcs.teambition.net/storage/3121377af75144fab9fe7d2a93d779b6eeb0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjY2MSwiaWF0IjoxNjEwMDk3ODYxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzNzdhZjc1MTQ0ZmFiOWZlN2QyYTkzZDc3OWI2ZWViMCJ9.GJq_ZU9aaYwSaKTuLDgYc8KFVD1ThmqltJiGPjepIA0&download=image.png "")

```json
{
    "shop": {
        "settings": {
            "index": {
                "creation_date": "1609813762553",
                "number_of_shards": "3",
                "number_of_replicas": "1",
                "uuid": "fhXbi059Slqn6t77-vWMWA",
                "version": {
                    "created": "7040299"
                },
                "provided_name": "shop"
            }
        }
    }
}

```

## 修改 index.max_result_window

![](https://tcs.teambition.net/storage/3121ab7f4026c2df46a0b33584df43cfac17?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjY2MSwiaWF0IjoxNjEwMDk3ODYxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhYjdmNDAyNmMyZGY0NmEwYjMzNTg0ZGY0M2NmYWMxNyJ9.1RNVvmKHhoOj0-qhVYEFVOYg24jILXRs2Izcsg66Zm0&download=image.png "")

```json
{
    "index.max_result_window": 100000
}

```

```json
{
    "acknowledged": true
}

```

## 查询查看设置

![](https://tcs.teambition.net/storage/31218497228778264f09aad2720c99f41e46?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjY2MSwiaWF0IjoxNjEwMDk3ODYxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4NDk3MjI4Nzc4MjY0ZjA5YWFkMjcyMGM5OWY0MWU0NiJ9.y8d1KFPYd9oJv2f4vSUMVuWPNAmOcMTdCt_D3IGR7-A&download=image.png "")

## 突破搜索量查询

![](https://tcs.teambition.net/storage/3121119ff44178b6a38abe3125342f2e4c97?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjY2MSwiaWF0IjoxNjEwMDk3ODYxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExMTlmZjQ0MTc4YjZhMzhhYmUzMTI1MzQyZjJlNGM5NyJ9.yWuPrprdZHidY_1dfVoVrnmwSNM2YE1MP1jpzG46FwY&download=image.png "")

```json
{
    "query": {
        "match_all": {}
    },
    "from": 19999,
    "size": 10
}

```

```json
{
    "took": 22,
    "timed_out": false,
    "_shards": {
        "total": 3,
        "successful": 3,
        "skipped": 0,
        "failed": 0
    },
    "hits": {
        "total": {
            "value": 12,
            "relation": "eq"
        },
        "max_score": 1.0,
        "hits": []
    }
}

```





开源笔记

此笔记在学习的时候做的笔记 所以 没有那么多时间写的很细致或整理排版问题 采用关键帧图片与关键帧文字进行书写 

可 Pull Requests 协作写开源笔记

[gitee](https://gitee.com/opendevel/java-for-linux)

[github](https://github.com/OSrcD/java-for-linux)

[teambition](https://www.teambition.com/project/5ff1a6330b58d3e798744991?from=invite)

开源视频

[OSrcD的个人空间 - 哔哩哔哩 ( ゜- ゜)つロ 乾杯~ Bilibili](https://space.bilibili.com/77266754)

开源博客

[全部博文 - OpenDevel的个人空间 - OSCHINA](https://my.oschina.net/u/4675154?tab=newest&catalogId=0)

开源项目

[OSrcD (OpenDevel) - Gitee.com](https://gitee.com/OpenDevel)

[OSrcD - Overview](https://github.com/OSrcD)

开源赞赏

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjY2MSwiaWF0IjoxNjEwMDk3ODYxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.VkzorvGIZStgkkKlebHKavv4r3vHvtBx9UqvgkHq9hg&download=image.png "")

请勿相信图片中任何联系方式

图片来源于视频 作者拿到视频学习已被第三方打码 没办法 截图也没时间去修改图片 请勿相信图片里的任何联系方式

谢谢

