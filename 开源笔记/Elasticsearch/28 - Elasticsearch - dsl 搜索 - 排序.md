![](https://tcs.teambition.net/storage/312199712039cfdf0817fed893302bfe3654?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjU5MCwiaWF0IjoxNjEwMDk3NzkwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5OTcxMjAzOWNmZGYwODE3ZmVkODkzMzAyYmZlMzY1NCJ9.fQB604W40I4CsXo9igBSTgktj891COHhDa1ldKu0MwU&download=2020-09-17%20175516.png "")

## sort 排序 desc 从高到低 asc 

![](https://tcs.teambition.net/storage/3121dc47d328139417217b1bb6f334be874a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjU5MCwiaWF0IjoxNjEwMDk3NzkwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkYzQ3ZDMyODEzOTQxNzIxN2IxYmI2ZjMzNGJlODc0YSJ9.npnI9_fdgApKsDlQyu60521R5HmuVBLfzqupx8A4m6Y&download=image.png "")

```json
{
    "query": {
        "match": {
            "desc": "游戏"
        }
    },
    "sort": [
        {
            "money": "desc"
        },
        {
            "age": "asc"
        }
    ]
}

```

```json
{
    "took": 288,
    "timed_out": false,
    "_shards": {
        "total": 3,
        "successful": 3,
        "skipped": 0,
        "failed": 0
    },
    "hits": {
        "total": {
            "value": 2,
            "relation": "eq"
        },
        "max_score": null,
        "hits": [
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1007",
                "_score": null,
                "_source": {
                    "id": 1007,
                    "age": 19,
                    "username": "msgame",
                    "nickname": "gamexbox",
                    "money": 1056.8,
                    "desc": "明天去进货，最近微软处理很多游戏机，还要买xbox游戏卡带",
                    "sex": 1,
                    "birthday": "1985-05-14",
                    "face": "https://gitee.com/static/images/logo-black.svg?t=158106664"
                },
                "sort": [
                    1056.8,
                    19
                ]
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1005",
                "_score": null,
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
                },
                "sort": [
                    155.8,
                    25
                ]
            }
        ]
    }
}

```

## 被分词不能作为字段排序

## fields 是附属属性

![](https://tcs.teambition.net/storage/3121704f80328be5daf723d4cf10dc8b1f01?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjU5MCwiaWF0IjoxNjEwMDk3NzkwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3MDRmODAzMjhiZTVkYWY3MjNkNGNmMTBkYzhiMWYwMSJ9.WBtR0CuSOTqcm_RD1jmc7rwZKD0v577wIc9VA8iUOHo&download=image.png "")

## 新建索引

![](https://tcs.teambition.net/storage/3121fe2cda0fa8a3fe69b2ab88aa5d027f43?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjU5MCwiaWF0IjoxNjEwMDk3NzkwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmZTJjZGEwZmE4YTNmZTY5YjJhYjg4YWE1ZDAyN2Y0MyJ9.vnnDpdxitLvRye7YGWTNacOd9xM1VDerZxTZUvdGpJ8&download=image.png "")

![](https://tcs.teambition.net/storage/31216db93cd07ebf9a727d6e5c23221633ad?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjU5MCwiaWF0IjoxNjEwMDk3NzkwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2ZGI5M2NkMDdlYmY5YTcyN2Q2ZTVjMjMyMjE2MzNhZCJ9.eTJAHQU9MDeoCgnayhjxnkkKQs560XS0OeWRnn4ok08&download=image.png "")

## keyword 类型 其实就是对应的nickname 

## 建立Mapping

![](https://tcs.teambition.net/storage/31217386be3e4ea431d957d156a6b7296129?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjU5MCwiaWF0IjoxNjEwMDk3NzkwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3Mzg2YmUzZTRlYTQzMWQ5NTdkMTU2YTZiNzI5NjEyOSJ9.vuBhZ6uQC_KekmcybOd0bPbW-ilgtWClxwii3bMo_JY&download=image.png "")

```json
{
    "properties": {
        "id": {
            "type": "long"
        },
        "nickname": {
            "type": "text",
            "analyzer": "ik_max_word",
            "fields": {
                "keyword": {
                    "type": "keyword"
                }
            }
        }
    }
}

```

```json
{
    "acknowledged": true
}

```

## fields 其实就是 nickname.keyword 类型就是 keyword

![](https://tcs.teambition.net/storage/31213b2a33057f63878cf1bce7f849e7a09d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjU5MCwiaWF0IjoxNjEwMDk3NzkwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzYjJhMzMwNTdmNjM4NzhjZjFiY2U3Zjg0OWU3YTA5ZCJ9.pkforE1Rctck6cs8SiR8JwxfLjXXoPp0H-I4Az86GkY&download=image.png "")

## 建立数据

![](https://tcs.teambition.net/storage/31217b8a702eedf473ec2152fa6df9868e96?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjU5MCwiaWF0IjoxNjEwMDk3NzkwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3YjhhNzAyZWVkZjQ3M2VjMjE1MmZhNmRmOTg2OGU5NiJ9.AOPtdjxn8VBEo1CJ2kBE4X0EzRrJO_MMbqP-7TkQPeQ&download=image.png "")

## 模板

```json
{
    "id": 100 ,
    "nickname": ""
}

```

```json
{
    "id": 1001 ,
    "nickname": "美丽的风景"
}

{
    "id": 1002 ,
    "nickname": "漂亮的小哥哥"
}

{
    "id": 1003 ,
    "nickname": "飞翔的巨鹰"
}

{
    "id": 1004 ,
    "nickname": "完美的天空"
}

{
    "id": 1005 ,
    "nickname": "广阔的海域"
}

```



```json
{
    "_index": "shop2",
    "_type": "_doc",
    "_id": "Derc2nYBdA18d75JO5hk",
    "_version": 1,
    "result": "created",
    "_shards": {
        "total": 2,
        "successful": 1,
        "failed": 0
    },
    "_seq_no": 2,
    "_primary_term": 1
}

```

![](https://tcs.teambition.net/storage/312110fd4a1fc8e2a9b6a9f345f8a24a0b64?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjU5MCwiaWF0IjoxNjEwMDk3NzkwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExMGZkNGExZmM4ZTJhOWI2YTlmMzQ1ZjhhMjRhMGI2NCJ9.wPRzosqE08JGd1kxYeJkHArBCnD7UwBRcRAepY4wc1o&download=image.png "")

## 根据 keyword 里面的规则去做排序 asc desc

![](https://tcs.teambition.net/storage/31219b1da302ea0071f0320d7a1d8bc9184c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjU5MCwiaWF0IjoxNjEwMDk3NzkwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5YjFkYTMwMmVhMDA3MWYwMzIwZDdhMWQ4YmM5MTg0YyJ9.1repMIJTP7Nn9OS3qS1G_aJ5Yj6DjhZDHPD5rm2_ODo&download=image.png "")

```json
{
    "sort": [
        {
            "nickname.keyword": "asc"
        }
    ]
}

```

```json
{
    "took": 1083,
    "timed_out": false,
    "_shards": {
        "total": 5,
        "successful": 5,
        "skipped": 0,
        "failed": 0
    },
    "hits": {
        "total": {
            "value": 5,
            "relation": "eq"
        },
        "max_score": null,
        "hits": [
            {
                "_index": "shop2",
                "_type": "_doc",
                "_id": "Eerm2nYBdA18d75J6Ziu",
                "_score": null,
                "_source": {
                    "id": 1004,
                    "nickname": "完美的天空"
                },
                "sort": [
                    "完美的天空"
                ]
            },
            {
                "_index": "shop2",
                "_type": "_doc",
                "_id": "Eurn2nYBdA18d75JBJi_",
                "_score": null,
                "_source": {
                    "id": 1005,
                    "nickname": "广阔的海域"
                },
                "sort": [
                    "广阔的海域"
                ]
            },
            {
                "_index": "shop2",
                "_type": "_doc",
                "_id": "D-rm2nYBdA18d75Jvphj",
                "_score": null,
                "_source": {
                    "id": 1002,
                    "nickname": "漂亮的小哥哥"
                },
                "sort": [
                    "漂亮的小哥哥"
                ]
            },
            {
                "_index": "shop2",
                "_type": "_doc",
                "_id": "Durm2nYBdA18d75Jopge",
                "_score": null,
                "_source": {
                    "id": 1001,
                    "nickname": "美丽的风景"
                },
                "sort": [
                    "美丽的风景"
                ]
            },
            {
                "_index": "shop2",
                "_type": "_doc",
                "_id": "EOrm2nYBdA18d75J05j8",
                "_score": null,
                "_source": {
                    "id": 1003,
                    "nickname": "飞翔的巨鹰"
                },
                "sort": [
                    "飞翔的巨鹰"
                ]
            }
        ]
    }
}

```

![](https://tcs.teambition.net/storage/3121e8a2f40c0538f9b559552c2e0d1dde41?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjU5MCwiaWF0IjoxNjEwMDk3NzkwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlOGEyZjQwYzA1MzhmOWI1NTk1NTJjMmUwZDFkZGU0MSJ9.c0CRvEsQyjbZsitr9VNXSL3fAEMSQ1gq_QMM0Br-SXQ&download=image.png "")

```json
{
    "sort": [
        {
            "nickname.keyword": "desc"
        }
    ]
}

```

```json
{
    "took": 137,
    "timed_out": false,
    "_shards": {
        "total": 5,
        "successful": 5,
        "skipped": 0,
        "failed": 0
    },
    "hits": {
        "total": {
            "value": 5,
            "relation": "eq"
        },
        "max_score": null,
        "hits": [
            {
                "_index": "shop2",
                "_type": "_doc",
                "_id": "EOrm2nYBdA18d75J05j8",
                "_score": null,
                "_source": {
                    "id": 1003,
                    "nickname": "飞翔的巨鹰"
                },
                "sort": [
                    "飞翔的巨鹰"
                ]
            },
            {
                "_index": "shop2",
                "_type": "_doc",
                "_id": "Durm2nYBdA18d75Jopge",
                "_score": null,
                "_source": {
                    "id": 1001,
                    "nickname": "美丽的风景"
                },
                "sort": [
                    "美丽的风景"
                ]
            },
            {
                "_index": "shop2",
                "_type": "_doc",
                "_id": "D-rm2nYBdA18d75Jvphj",
                "_score": null,
                "_source": {
                    "id": 1002,
                    "nickname": "漂亮的小哥哥"
                },
                "sort": [
                    "漂亮的小哥哥"
                ]
            },
            {
                "_index": "shop2",
                "_type": "_doc",
                "_id": "Eurn2nYBdA18d75JBJi_",
                "_score": null,
                "_source": {
                    "id": 1005,
                    "nickname": "广阔的海域"
                },
                "sort": [
                    "广阔的海域"
                ]
            },
            {
                "_index": "shop2",
                "_type": "_doc",
                "_id": "Eerm2nYBdA18d75J6Ziu",
                "_score": null,
                "_source": {
                    "id": 1004,
                    "nickname": "完美的天空"
                },
                "sort": [
                    "完美的天空"
                ]
            }
        ]
    }
}

```

## 实际场景很少用

![](https://tcs.teambition.net/storage/3121e7e27edcf247469c46485aaed356de75?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjU5MCwiaWF0IjoxNjEwMDk3NzkwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlN2UyN2VkY2YyNDc0NjljNDY0ODVhYWVkMzU2ZGU3NSJ9.0OsqMmvIzU_TqRDBTtXF-kmIou0MoMzEEikwgtWOjRM&download=image.png "")



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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjU5MCwiaWF0IjoxNjEwMDk3NzkwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.QEdUiD485VQFS1Wx_PAcnTUHHisH7NaQ54zAROD77rM&download=image.png "")

请勿相信图片中任何联系方式

图片来源于视频 作者拿到视频学习已被第三方打码 没办法 截图也没时间去修改图片 请勿相信图片里的任何联系方式

谢谢

