![](https://tcs.teambition.net/storage/31212cac37eae3ebb4a2d86b859c675fbedb?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjUyNSwiaWF0IjoxNjEwMDk3NzI1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyY2FjMzdlYWUzZWJiNGEyZDg2Yjg1OWM2NzVmYmVkYiJ9.JMPG65drCLQ717GYhXIsitPWXGF-cUxiXVrGodowOoI&download=2020-09-17%20175353.png "")

## 相当于有 OR

![](https://tcs.teambition.net/storage/3121fcce2cbbb1437b37b1912da34c49eb37?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjUyNSwiaWF0IjoxNjEwMDk3NzI1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmY2NlMmNiYmIxNDM3YjM3YjE5MTJkYTM0YzQ5ZWIzNyJ9.PFT92S9lCVGmSGFsuWZ9Chtm4ivak0aLFOwb1xukovU&download=image.png "")

```json
{
    "took": 41,
    "timed_out": false,
    "_shards": {
        "total": 3,
        "successful": 3,
        "skipped": 0,
        "failed": 0
    },
    "hits": {
        "total": {
            "value": 1,
            "relation": "eq"
        },
        "max_score": 10.593136,
        "hits": [
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1001",
                "_score": 10.593136,
                "_source": {
                    "nickname": "开源中国",
                    "id": 1001,
                    "desc": "我的开源中国学习java和前端，学习了很多知识"
                }
            }
        ]
    }
}

```

![](https://tcs.teambition.net/storage/3121d25ac6c84fdc093d36cb5d5d924f99c0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjUyNSwiaWF0IjoxNjEwMDk3NzI1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkMjVhYzZjODRmZGMwOTNkMzZjYjVkNWQ5MjRmOTljMCJ9.9R542BTjKAaOYxSoo2KghFk0KF-L4GvIpQdSrYHB7-I&download=image.png "")

```json
{
    "took": 41,
    "timed_out": false,
    "_shards": {
        "total": 3,
        "successful": 3,
        "skipped": 0,
        "failed": 0
    },
    "hits": {
        "total": {
            "value": 1,
            "relation": "eq"
        },
        "max_score": 10.593136,
        "hits": [
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1001",
                "_score": 10.593136,
                "_source": {
                    "nickname": "开源中国",
                    "id": 1001,
                    "desc": "我的开源中国学习java和前端，学习了很多知识"
                }
            }
        ]
    }
}

```

## and 必须都包含

![](https://tcs.teambition.net/storage/3121000c7a5f9c72462bf51096629d335ab6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjUyNSwiaWF0IjoxNjEwMDk3NzI1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwMDBjN2E1ZjljNzI0NjJiZjUxMDk2NjI5ZDMzNWFiNiJ9.F_F5aqMFmV2VgBHmVnF4BYNJ1ckyuoAbmXeogk9SB-4&download=image.png "")

```json
{
    "took": 44,
    "timed_out": false,
    "_shards": {
        "total": 3,
        "successful": 3,
        "skipped": 0,
        "failed": 0
    },
    "hits": {
        "total": {
            "value": 1,
            "relation": "eq"
        },
        "max_score": 10.593136,
        "hits": [
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1001",
                "_score": 10.593136,
                "_source": {
                    "nickname": "开源中国",
                    "id": 1001,
                    "desc": "我的开源中国学习java和前端，学习了很多知识"
                }
            }
        ]
    }
}

```

## 最小应该被匹配到的

![](https://tcs.teambition.net/storage/3121ad41ab2c598b57dbccd9434af9e37577?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjUyNSwiaWF0IjoxNjEwMDk3NzI1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZDQxYWIyYzU5OGI1N2RiY2NkOTQzNGFmOWUzNzU3NyJ9.foJV2HN-7lseEpQ8FtG7KiA8YaL6xpfWL3aOufUaLWw&download=image.png "")

```json
{
    "took": 26,
    "timed_out": false,
    "_shards": {
        "total": 3,
        "successful": 3,
        "skipped": 0,
        "failed": 0
    },
    "hits": {
        "total": {
            "value": 1,
            "relation": "eq"
        },
        "max_score": 8.974521,
        "hits": [
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1005",
                "_score": 8.974521,
                "_source": {
                    "nickname": "ps游戏机",
                    "id": 1005,
                    "desc": "今年生日，女友送了我一台play station游戏机，非常好玩，非常不错"
                }
            }
        ]
    }
}

```

## 只要 满足 1 个词语就能查询出来

![](https://tcs.teambition.net/storage/312151e015a6bc27debd67b4b19f67541aa2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjUyNSwiaWF0IjoxNjEwMDk3NzI1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1MWUwMTVhNmJjMjdkZWJkNjdiNGIxOWY2NzU0MWFhMiJ9.Plk7xu79na32kuCvfXVPQChvCY2tAK7xWRM3r5ui16E&download=image.png "")

```json
{
    "took": 133,
    "timed_out": false,
    "_shards": {
        "total": 3,
        "successful": 3,
        "skipped": 0,
        "failed": 0
    },
    "hits": {
        "total": {
            "value": 5,
            "relation": "eq"
        },
        "max_score": 8.974521,
        "hits": [
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1005",
                "_score": 8.974521,
                "_source": {
                    "nickname": "ps游戏机",
                    "id": 1005,
                    "desc": "今年生日，女友送了我一台play station游戏机，非常好玩，非常不错"
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1007",
                "_score": 5.3226337,
                "_source": {
                    "nickname": "gamexbox",
                    "id": 1007,
                    "desc": "明天去进货，最近微软处理很多游戏机，还要买xbox游戏卡带"
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1010",
                "_score": 0.8941545,
                "_source": {
                    "nickname": "隔壁老王",
                    "id": 1010,
                    "desc": "隔壁老外去国外出差，带给我很多好吃的"
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1001",
                "_score": 0.8201636,
                "_source": {
                    "nickname": "开源中国",
                    "id": 1001,
                    "desc": "我的开源中国学习java和前端，学习了很多知识"
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1004",
                "_score": 0.7207594,
                "_source": {
                    "nickname": "水中鱼",
                    "id": 1004,
                    "desc": "昨天在学校的池塘里，看到有很多鱼在游泳，然后就去慕课网上课了"
                }
            }
        ]
    }
}

```

## type 就是类型 查什么类型

![](https://tcs.teambition.net/storage/31211aca14b6652b05c96c8446bd07b2f1a4?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjUyNSwiaWF0IjoxNjEwMDk3NzI1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExYWNhMTRiNjY1MmIwNWM5NmM4NDQ2YmQwN2IyZjFhNCJ9.lyxu6xWeIVqcUylv9r7Aud4kEDdTZkBVCRKWQVDIZcU&download=image.png "")

```json
{
    "took": 23,
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
        "max_score": 1.0,
        "hits": [
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1003",
                "_score": 1.0,
                "_source": {
                    "nickname": "飞翔的巨鹰",
                    "id": 1003,
                    "desc": "慕课网团队和导游坐飞机去海外旅游,去了新马泰和欧洲"
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1001",
                "_score": 1.0,
                "_source": {
                    "nickname": "开源中国",
                    "id": 1001,
                    "desc": "我的开源中国学习java和前端，学习了很多知识"
                }
            }
        ]
    }
}

```

## post_filter 同级元素

![](https://tcs.teambition.net/storage/3121ba001f165ad06cbc9765d83f949a016d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjUyNSwiaWF0IjoxNjEwMDk3NzI1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiYTAwMWYxNjVhZDA2Y2JjOTc2NWQ4M2Y5NDlhMDE2ZCJ9.jeiRoMYzbgbzpZC7r5DwBT5IrtcIBv4TV5rmKjV1pkM&download=image.png "")

```json
{
    "query": {
        "match": {
            "desc": "游戏"
        }
    },
    "post_filter": {
        "range": {
            "money": {
                "gt": 55.8,
                "lte": 155.8
            }
        }
    }
}

```

```json
{
    "took": 114,
    "timed_out": false,
    "_shards": {
        "total": 3,
        "successful": 3,
        "skipped": 0,
        "failed": 0
    },
    "hits": {
        "total": {
            "value": 1,
            "relation": "eq"
        },
        "max_score": 1.4957534,
        "hits": [
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1005",
                "_score": 1.4957534,
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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjUyNSwiaWF0IjoxNjEwMDk3NzI1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.Qbeo7NW802Dw2Boz0FJrelO2L9kTMKoML4DIe_PSA18&download=image.png "")

请勿相信图片中任何联系方式

图片来源于视频 作者拿到视频学习已被第三方打码 没办法 截图也没时间去修改图片 请勿相信图片里的任何联系方式

谢谢

