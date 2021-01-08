## type 搜索的类型 

## 普通的批量搜索方式

![](https://tcs.teambition.net/storage/3121df3bd6f7044e99f0626bafa967004183?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjY4NywiaWF0IjoxNjEwMDk3ODg3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkZjNiZDZmNzA0NGU5OWYwNjI2YmFmYTk2NzAwNDE4MyJ9.jGC0lxJ4HPA3SiLH1a1uUl2oLZCcTeKUX2jlaDLH68M&download=image.png "")

```json
{
    "query": {
        "ids": {
            "type": "_doc",
            "values": ["1001","1003","1005"]
        }
    }
}

```

```json
{
    "took": 21,
    "timed_out": false,
    "_shards": {
        "total": 3,
        "successful": 3,
        "skipped": 0,
        "failed": 0
    },
    "hits": {
        "total": {
            "value": 3,
            "relation": "eq"
        },
        "max_score": 1.0,
        "hits": [
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1003",
                "_score": 1.0,
                "_source": {
                    "id": 1003,
                    "age": 20,
                    "username": "bigFace",
                    "nickname": "飞翔的巨鹰",
                    "money": 66.8,
                    "desc": "慕课网团队和导游坐飞机去海外旅游,去了新马泰和欧洲",
                    "sex": 1,
                    "birthday": "1996-01-14",
                    "face": "https://gitee.com/static/images/logo-black.svg?t=158106664"
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1001",
                "_score": 1.0,
                "_source": {
                    "id": 1001,
                    "age": 18,
                    "username": "giteeAmazing",
                    "nickname": "开源中国",
                    "money": 88.8,
                    "desc": "我的开源中国学习java和前端，学习了很多知识",
                    "sex": 0,
                    "birthday": "1992-12-24",
                    "face": "https://gitee.com/static/images/logo-black.svg?t=158106664"
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1005",
                "_score": 1.0,
                "_source": {
                    "id": 1005,
                    "age": 25,
                    "username": "gotoplay",
                    "nickname": "ps游戏机",
                    "money": 155.8,
                    "desc": "今年生日，女友送了我一台play station游戏机，非常好玩，非常不错",
                    "sex": 1,
                    "birthday": "1989-03-14",
                    "face": "https://gitee.com/static/images/logo-black.svg?t=158106664"
                }
            }
        ]
    }
}

```

## _mget 内置批量查询 查询出来是一个docs数组 精简元数据

## found 为 true 代表能够搜索到  可以判断该id 是否在这个文档 而普通的搜索不行

![](https://tcs.teambition.net/storage/3121352affa16389c25634e52cceb056ab48?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjY4NywiaWF0IjoxNjEwMDk3ODg3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzNTJhZmZhMTYzODljMjU2MzRlNTJjY2ViMDU2YWI0OCJ9.306YnJFKdnHtRbkL9-5XEgYijATol1f1tKnmbnQPVJs&download=image.png "")

```json
{
    "ids": ["1001","1003","10015"]
}

```

```json
{
    "docs": [
        {
            "_index": "shop",
            "_type": "_doc",
            "_id": "1001",
            "_version": 1,
            "_seq_no": 0,
            "_primary_term": 1,
            "found": true,
            "_source": {
                "id": 1001,
                "age": 18,
                "username": "giteeAmazing",
                "nickname": "开源中国",
                "money": 88.8,
                "desc": "我的开源中国学习java和前端，学习了很多知识",
                "sex": 0,
                "birthday": "1992-12-24",
                "face": "https://gitee.com/static/images/logo-black.svg?t=158106664"
            }
        },
        {
            "_index": "shop",
            "_type": "_doc",
            "_id": "1003",
            "_version": 1,
            "_seq_no": 1,
            "_primary_term": 1,
            "found": true,
            "_source": {
                "id": 1003,
                "age": 20,
                "username": "bigFace",
                "nickname": "飞翔的巨鹰",
                "money": 66.8,
                "desc": "慕课网团队和导游坐飞机去海外旅游,去了新马泰和欧洲",
                "sex": 1,
                "birthday": "1996-01-14",
                "face": "https://gitee.com/static/images/logo-black.svg?t=158106664"
            }
        },
        {
            "_index": "shop",
            "_type": "_doc",
            "_id": "10015",
            "found": false
        }
    ]
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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjY4NywiaWF0IjoxNjEwMDk3ODg3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.2SdL5HFtj9F-Aqeac2oDR2ojfwyeVwdXTQepqVf1hFg&download=image.png "")

请勿相信图片中任何联系方式

图片来源于视频 作者拿到视频学习已被第三方打码 没办法 截图也没时间去修改图片 请勿相信图片里的任何联系方式

谢谢

