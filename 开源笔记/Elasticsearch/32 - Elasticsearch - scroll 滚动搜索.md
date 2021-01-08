





![](https://tcs.teambition.net/storage/31210928f3ce658403d005eda52bc7e6bc50?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjY3MCwiaWF0IjoxNjEwMDk3ODcwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwOTI4ZjNjZTY1ODQwM2QwMDVlZGE1MmJjN2U2YmM1MCJ9.PO7yWlMEJ3u59XjlMsywwMqtnAUY44-kNRsGzQJHyDE&download=2020-09-17%20175607.png "")

## scroll 滚动搜索 有一段时间的历史快照数据 数据变更 没影响

## sort 固定写上 _doc 基于文档去搜 size 每一次滚动的数据量

## scroll id 是 base 64 字符串

![](https://tcs.teambition.net/storage/312110d6da14bfc53a43580af1a8082f957a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjY3MCwiaWF0IjoxNjEwMDk3ODcwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExMGQ2ZGExNGJmYzUzYTQzNTgwYWYxYTgwODJmOTU3YSJ9.t_8M8r9wdYNNPGxicbY7jjciw89vnVAbHQR53IMOWj8&download=image.png "")

```json
{
    "query": {
        "match_all": {}
    },
    "sort": ["_doc"],
    "size": 5
}

```

```json
{
    "_scroll_id": "DnF1ZXJ5VGhlbkZldGNoAwAAAAAAAAG5FkI3M3VzT1ZPUk1TMlJuWWY1blh4emcAAAAAAAABuhZCNzN1c09WT1JNUzJSbllmNW5YeHpnAAAAAAAAAbsWQjczdXNPVk9STVMyUm5ZZjVuWHh6Zw==",
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
            "value": 12,
            "relation": "eq"
        },
        "max_score": null,
        "hits": [
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1002",
                "_score": null,
                "_source": {
                    "id": 1002,
                    "age": 19,
                    "username": "justbuy",
                    "nickname": "周杰棍",
                    "money": 77.8,
                    "desc": "今天上下班都很堵，车流量很大",
                    "sex": 1,
                    "birthday": "1993-01-24",
                    "face": "https://gitee.com/static/images/logo-black.svg?t=158106664"
                },
                "sort": [
                    0
                ]
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1001",
                "_score": null,
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
                },
                "sort": [
                    0
                ]
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1003",
                "_score": null,
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
                },
                "sort": [
                    1
                ]
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1004",
                "_score": null,
                "_source": {
                    "id": 1004,
                    "age": 22,
                    "username": "flyfish",
                    "nickname": "水中鱼",
                    "money": 55.8,
                    "desc": "昨天在学校的池塘里，看到有很多鱼在游泳，然后就去慕课网上课了",
                    "sex": 0,
                    "birthday": "1988-02-14",
                    "face": "https://gitee.com/static/images/logo-black.svg?t=158106664"
                },
                "sort": [
                    1
                ]
            },
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
                    2
                ]
            }
        ]
    }
}

```

![](https://tcs.teambition.net/storage/312193b510e0f56c40dd8d26ccb4d5e2b5c9?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjY3MCwiaWF0IjoxNjEwMDk3ODcwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5M2I1MTBlMGY1NmM0MGRkOGQyNmNjYjRkNWUyYjVjOSJ9.AsoDN9x5qktO04edVI7dE0URrnCkETerHpkCmXGtGxA&download=image.png "")

```json
{
    "scroll_id": "DnF1ZXJ5VGhlbkZldGNoAwAAAAAAAAG8FkI3M3VzT1ZPUk1TMlJuWWY1blh4emcAAAAAAAABvhZCNzN1c09WT1JNUzJSbllmNW5YeHpnAAAAAAAAAb0WQjczdXNPVk9STVMyUm5ZZjVuWHh6Zw==",
    "scroll": "1m"
}

```

```json
{
    "_scroll_id": "DnF1ZXJ5VGhlbkZldGNoAwAAAAAAAAG8FkI3M3VzT1ZPUk1TMlJuWWY1blh4emcAAAAAAAABvhZCNzN1c09WT1JNUzJSbllmNW5YeHpnAAAAAAAAAb0WQjczdXNPVk9STVMyUm5ZZjVuWHh6Zw==",
    "took": 50,
    "timed_out": false,
    "terminated_early": false,
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
        "max_score": null,
        "hits": [
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
                    2
                ]
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1008",
                "_score": null,
                "_source": {
                    "id": 1008,
                    "age": 19,
                    "username": "kaiyuan",
                    "nickname": "开源学习",
                    "money": 1056.8,
                    "desc": "大学毕业后，可以到gitee.com进修",
                    "sex": 1,
                    "birthday": "1995-06-14",
                    "face": "https://gitee.com/static/images/logo-black.svg?t=158106664"
                },
                "sort": [
                    3
                ]
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1006",
                "_score": null,
                "_source": {
                    "id": 1006,
                    "age": 19,
                    "username": "missgitee",
                    "nickname": "我叫小源",
                    "money": 156.8,
                    "desc": "我叫凌云彻，今年20岁，是一名律师，我在琦星球做演讲",
                    "sex": 1,
                    "birthday": "1993-04-14",
                    "face": "https://gitee.com/static/images/logo-black.svg?t=158106664"
                },
                "sort": [
                    3
                ]
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1011",
                "_score": null,
                "_source": {
                    "id": 1011,
                    "age": 31,
                    "username": "sparder",
                    "nickname": "皮特帕克",
                    "money": 180.8,
                    "desc": "它是一个超级英雄",
                    "sex": 1,
                    "birthday": "1989-08-14",
                    "face": "https://gitee.com/static/images/logo-black.svg?t=158106664"
                },
                "sort": [
                    4
                ]
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1009",
                "_score": null,
                "_source": {
                    "id": 1009,
                    "age": 22,
                    "username": "shaonian",
                    "nickname": "骚年轮",
                    "money": 96.8,
                    "desc": "骚年在大学毕业后，考研究生去了",
                    "sex": 1,
                    "birthday": "1998-07-14",
                    "face": "https://gitee.com/static/images/logo-black.svg?t=158106664"
                },
                "sort": [
                    4
                ]
            }
        ]
    }
}

```

[__https://www.elastic.co/guide/cn/elasticsearch/guide/current/scroll.html__](https://www.elastic.co/guide/cn/elasticsearch/guide/current/scroll.html)

## 性能会更好更快

![](https://tcs.teambition.net/storage/3121f023d89aad12c80122b8ea9459c8a1fb?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjY3MCwiaWF0IjoxNjEwMDk3ODcwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmMDIzZDg5YWFkMTJjODAxMjJiOGVhOTQ1OWM4YTFmYiJ9.AMX7nkcBG4F-BKqnNb1e2HvIpwFSI-tM9sqGCGLV_L4&download=image.png "")

![](https://tcs.teambition.net/storage/31219a507ef47aef347efb2d8003840c49ae?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjY3MCwiaWF0IjoxNjEwMDk3ODcwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5YTUwN2VmNDdhZWYzNDdlZmIyZDgwMDM4NDBjNDlhZSJ9.MEnti26eUOdhH8TWr7U83_XiSG9bBM8mTHq7l_ur8jg&download=image.png "")

![](https://tcs.teambition.net/storage/3121a2e26ad6ffc5e6a46c62428c86b8d937?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjY3MCwiaWF0IjoxNjEwMDk3ODcwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhMmUyNmFkNmZmYzVlNmE0NmM2MjQyOGM4NmI4ZDkzNyJ9.rw62pCeEHHhreqL28WS7YNCzv2O5sOei9OFmK7tbxxE&download=image.png "")

![](https://tcs.teambition.net/storage/31218c9181b75c1d9c548fe3358beaa49d8f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjY3MCwiaWF0IjoxNjEwMDk3ODcwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4YzkxODFiNzVjMWQ5YzU0OGZlMzM1OGJlYWE0OWQ4ZiJ9.QWv2chpV_H6wydxlY8kZB_ShoATGIJsT086ztKpr3H0&download=image.png "")

## number_of_primary_shards 分片数

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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjY3MCwiaWF0IjoxNjEwMDk3ODcwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.kStaIa83g6WoGMYiBHXRRrH7KIrIEWNIl7-ITVtcWXk&download=image.png "")

请勿相信图片中任何联系方式

图片来源于视频 作者拿到视频学习已被第三方打码 没办法 截图也没时间去修改图片 请勿相信图片里的任何联系方式

谢谢

