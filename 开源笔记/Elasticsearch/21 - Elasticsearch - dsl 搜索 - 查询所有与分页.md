## 文档

![](https://tcs.teambition.net/storage/3121ece502ba3daac0f2aa2ccd44a6e4f466?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ2NywiaWF0IjoxNjEwMDk3NjY3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlY2U1MDJiYTNkYWFjMGYyYWEyY2NkNDRhNmU0ZjQ2NiJ9.fSBxIukuvKD4TjfVpJ1pCTtn6e07zFwJQYpcgqR8xFU&download=2020-09-17%20174809.png "")

## QueryString 查询所有

![](https://tcs.teambition.net/storage/312137c18a807edb6c56c5801ad53c4b70b4?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ2NywiaWF0IjoxNjEwMDk3NjY3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzN2MxOGE4MDdlZGI2YzU2YzU4MDFhZDUzYzRiNzBiNCJ9.iysvzuBI5tdnd9G6Au5AmQ4ixTNKZPkRm0w1gPO_Crg&download=image.png "")

```json
{
    "took": 18,
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
        "hits": [
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1002",
                "_score": 1.0,
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
                }
            },
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
                "_id": "1007",
                "_score": 1.0,
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
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1008",
                "_score": 1.0,
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
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1011",
                "_score": 1.0,
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
                "_id": "1004",
                "_score": 1.0,
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
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1006",
                "_score": 1.0,
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
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1009",
                "_score": 1.0,
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
                }
            }
        ]
    }
}

```

![](https://tcs.teambition.net/storage/31218e27295e1afaf7ef3660d822a15e049e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ2NywiaWF0IjoxNjEwMDk3NjY3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4ZTI3Mjk1ZTFhZmFmN2VmMzY2MGQ4MjJhMTVlMDQ5ZSJ9.3KXvrOV3A4bYzgjvhTCOt3j66-xv4jY67LAZ9HN516s&download=image.png "")

## DSL 查询所有

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
            "value": 12,
            "relation": "eq"
        },
        "max_score": 1.0,
        "hits": [
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1002",
                "_score": 1.0,
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
                }
            },
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
                "_id": "1007",
                "_score": 1.0,
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
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1008",
                "_score": 1.0,
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
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1011",
                "_score": 1.0,
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
                "_id": "1004",
                "_score": 1.0,
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
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1006",
                "_score": 1.0,
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
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1009",
                "_score": 1.0,
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
                }
            }
        ]
    }
}

```

## _source  就是元数据 定制化查询

![](https://tcs.teambition.net/storage/312102c359476f12710fc1b4759654fa5ca9?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ2NywiaWF0IjoxNjEwMDk3NjY3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwMmMzNTk0NzZmMTI3MTBmYzFiNDc1OTY1NGZhNWNhOSJ9.rdwDgtEMzzzUqM0nj1KFqbXs2D4MVBtzzj2IPF5_3cw&download=image.png "")

```json
{
    "took": 266,
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
        "hits": [
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1002",
                "_score": 1.0,
                "_source": {
                    "nickname": "周杰棍",
                    "id": 1002,
                    "age": 19
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1003",
                "_score": 1.0,
                "_source": {
                    "nickname": "飞翔的巨鹰",
                    "id": 1003,
                    "age": 20
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1007",
                "_score": 1.0,
                "_source": {
                    "nickname": "gamexbox",
                    "id": 1007,
                    "age": 19
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1008",
                "_score": 1.0,
                "_source": {
                    "nickname": "开源学习",
                    "id": 1008,
                    "age": 19
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1011",
                "_score": 1.0,
                "_source": {
                    "nickname": "皮特帕克",
                    "id": 1011,
                    "age": 31
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
                    "age": 18
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1004",
                "_score": 1.0,
                "_source": {
                    "nickname": "水中鱼",
                    "id": 1004,
                    "age": 22
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1005",
                "_score": 1.0,
                "_source": {
                    "nickname": "ps游戏机",
                    "id": 1005,
                    "age": 25
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1006",
                "_score": 1.0,
                "_source": {
                    "nickname": "我叫小源",
                    "id": 1006,
                    "age": 19
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1009",
                "_score": 1.0,
                "_source": {
                    "nickname": "骚年轮",
                    "id": 1009,
                    "age": 22
                }
            }
        ]
    }
}

```

## 可视化方式搜索

![](https://tcs.teambition.net/storage/31216530000866d482d1afa3cc8c734f9ba1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ2NywiaWF0IjoxNjEwMDk3NjY3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2NTMwMDAwODY2ZDQ4MmQxYWZhM2NjOGM3MzRmOWJhMSJ9.E5HU9uQue-zmtf8GC7nu87SMl5gK2XA75AlrDPmL-YU&download=image.png "")

![](https://tcs.teambition.net/storage/3121f6e84c2a20e2eb30685beed936319e5f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ2NywiaWF0IjoxNjEwMDk3NjY3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmNmU4NGMyYTIwZTJlYjMwNjg1YmVlZDkzNjMxOWU1ZiJ9.teBMqcNUypQACOf4mMv9JR8UhTS2Chp_7ul2KwxEZAg&download=image.png "")

## from 是数据查询开始位置 也就是index下标 从0开始

## size 每次分页的条数

![](https://tcs.teambition.net/storage/3121cd04491045f0b49835985a42836b31cf?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ2NywiaWF0IjoxNjEwMDk3NjY3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjZDA0NDkxMDQ1ZjBiNDk4MzU5ODVhNDI4MzZiMzFjZiJ9.73MEHP65QNTnH0lym8SNBYyhUPwQDgxR8swZu3a7O5I&download=image.png "")

![](https://tcs.teambition.net/storage/31213404a002a439ba9fc54ab10bf3ab212b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ2NywiaWF0IjoxNjEwMDk3NjY3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzNDA0YTAwMmE0MzliYTlmYzU0YWIxMGJmM2FiMjEyYiJ9.t8AVKpgxXWd2hksXShX2BWBxM1wh0LF-rZ37O1NUI38&download=image.png "")

## 返回JSON格式

![](https://tcs.teambition.net/storage/31211a0caf92f6d2b8c384e0da09ce4156e4?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ2NywiaWF0IjoxNjEwMDk3NjY3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExYTBjYWY5MmY2ZDJiOGMzODRlMGRhMDljZTQxNTZlNCJ9.O8UZzkd-TJgMhqLmDttMaqXAZLZPqAMAyp4pgabV48o&download=image.png "")

```json
{
  "took": 101,
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
    "max_score": 1,
    "hits": [
      {
        "_index": "shop",
        "_type": "_doc",
        "_id": "1002",
        "_score": 1,
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
        }
      },
      {
        "_index": "shop",
        "_type": "_doc",
        "_id": "1003",
        "_score": 1,
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
        "_id": "1007",
        "_score": 1,
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
        }
      },
      {
        "_index": "shop",
        "_type": "_doc",
        "_id": "1008",
        "_score": 1,
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
        }
      },
      {
        "_index": "shop",
        "_type": "_doc",
        "_id": "1011",
        "_score": 1,
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
        }
      },
      {
        "_index": "shop",
        "_type": "_doc",
        "_id": "1001",
        "_score": 1,
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
        "_id": "1004",
        "_score": 1,
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
        }
      },
      {
        "_index": "shop",
        "_type": "_doc",
        "_id": "1005",
        "_score": 1,
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
      },
      {
        "_index": "shop",
        "_type": "_doc",
        "_id": "1006",
        "_score": 1,
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
        }
      },
      {
        "_index": "shop",
        "_type": "_doc",
        "_id": "1009",
        "_score": 1,
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
        }
      },
      {
        "_index": "shop",
        "_type": "_doc",
        "_id": "1010",
        "_score": 1,
        "_source": {
          "id": 1010,
          "age": 30,
          "username": "tata",
          "nickname": "隔壁老王",
          "money": 100.8,
          "desc": "隔壁老外去国外出差，带给我很多好吃的",
          "sex": 1,
          "birthday": "1988-07-14",
          "face": "https://gitee.com/static/images/logo-black.svg?t=158106664"
        }
      },
      {
        "_index": "shop",
        "_type": "_doc",
        "_id": "1012",
        "_score": 1,
        "_source": {
          "id": 1012,
          "age": 31,
          "username": "super hero",
          "nickname": "super hero",
          "money": 188.8,
          "desc": "BatMan，GreenArrow，SpiderMan，IronMan... are all Super Hero",
          "sex": 1,
          "birthday": "1980-08-14",
          "face": "https://gitee.com/static/images/logo-black.svg?t=158106664"
        }
      }
    ]
  }
}


```

![](https://tcs.teambition.net/storage/31216a417a49fd293e02810b7532f1e98fa6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ2NywiaWF0IjoxNjEwMDk3NjY3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2YTQxN2E0OWZkMjkzZTAyODEwYjc1MzJmMWU5OGZhNiJ9.cJQAj9b7nxrhk-f79L0oyBZpHlh3U2AnuJWzCC5E20Q&download=image.png "")

```text
_index,_type,_id,_score,_source.id,_source.age,_source.username,_source.nickname,_source.money,_source.desc,_source.sex,_source.birthday,_source.face
"shop","_doc","1002","1","1002","19","justbuy","周杰棍","77.8","今天上下班都很堵，车流量很大","1","1993-01-24","https://gitee.com/static/images/logo-black.svg?t=158106664"
"shop","_doc","1003","1","1003","20","bigFace","飞翔的巨鹰","66.8","慕课网团队和导游坐飞机去海外旅游,去了新马泰和欧洲","1","1996-01-14","https://gitee.com/static/images/logo-black.svg?t=158106664"
"shop","_doc","1007","1","1007","19","msgame","gamexbox","1056.8","明天去进货，最近微软处理很多游戏机，还要买xbox游戏卡带","1","1985-05-14","https://gitee.com/static/images/logo-black.svg?t=158106664"
"shop","_doc","1008","1","1008","19","kaiyuan","开源学习","1056.8","大学毕业后，可以到gitee.com进修","1","1995-06-14","https://gitee.com/static/images/logo-black.svg?t=158106664"
"shop","_doc","1011","1","1011","31","sparder","皮特帕克","180.8","它是一个超级英雄","1","1989-08-14","https://gitee.com/static/images/logo-black.svg?t=158106664"
"shop","_doc","1001","1","1001","18","giteeAmazing","开源中国","88.8","我的开源中国学习java和前端，学习了很多知识","0","1992-12-24","https://gitee.com/static/images/logo-black.svg?t=158106664"
"shop","_doc","1004","1","1004","22","flyfish","水中鱼","55.8","昨天在学校的池塘里，看到有很多鱼在游泳，然后就去慕课网上课了","0","1988-02-14","https://gitee.com/static/images/logo-black.svg?t=158106664"
"shop","_doc","1005","1","1005","25","gotoplay","ps游戏机","155.8","今年生日，女友送了我一台play station游戏机，非常好玩，非常不错","1","1989-03-14","https://gitee.com/static/images/logo-black.svg?t=158106664"
"shop","_doc","1006","1","1006","19","missgitee","我叫小源","156.8","我叫凌云彻，今年20岁，是一名律师，我在琦星球做演讲","1","1993-04-14","https://gitee.com/static/images/logo-black.svg?t=158106664"
"shop","_doc","1009","1","1009","22","shaonian","骚年轮","96.8","骚年在大学毕业后，考研究生去了","1","1998-07-14","https://gitee.com/static/images/logo-black.svg?t=158106664"
"shop","_doc","1010","1","1010","30","tata","隔壁老王","100.8","隔壁老外去国外出差，带给我很多好吃的","1","1988-07-14","https://gitee.com/static/images/logo-black.svg?t=158106664"
"shop","_doc","1012","1","1012","31","super hero","super hero","188.8","BatMan，GreenArrow，SpiderMan，IronMan... are all Super Hero","1","1980-08-14","https://gitee.com/static/images/logo-black.svg?t=158106664"

```

![](https://tcs.teambition.net/storage/3121ab94d7685f4a26b5041b091b792cda88?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ2NywiaWF0IjoxNjEwMDk3NjY3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhYjk0ZDc2ODVmNGEyNmI1MDQxYjA5MWI3OTJjZGE4OCJ9.vKFKXjzvrpmgC8QKucgA-OL2HeO8NWrvjJHny74SyLM&download=image.png "")

![](https://tcs.teambition.net/storage/31211a78314733abd47d42e022dc6a678a2b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ2NywiaWF0IjoxNjEwMDk3NjY3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExYTc4MzE0NzMzYWJkNDdkNDJlMDIyZGM2YTY3OGEyYiJ9._By2-u3q8bivJNm90aKLNxx1SCMqsB32GrMKSPfknXs&download=image.png "")

## 分页

## from 从哪里开始

## size 多长

![](https://tcs.teambition.net/storage/31213fb2d245fbbfb0d5402e374f412cceb0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ2NywiaWF0IjoxNjEwMDk3NjY3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzZmIyZDI0NWZiYmZiMGQ1NDAyZTM3NGY0MTJjY2ViMCJ9.2irHYkoCDfnDAlh9MFO2C43Ft1-9H3Gi3C6Bo2FprYU&download=image.png "")

```json
{
    "took": 19,
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
        "hits": [
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1002",
                "_score": 1.0,
                "_source": {
                    "nickname": "周杰棍",
                    "id": 1002,
                    "age": 19
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1003",
                "_score": 1.0,
                "_source": {
                    "nickname": "飞翔的巨鹰",
                    "id": 1003,
                    "age": 20
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1007",
                "_score": 1.0,
                "_source": {
                    "nickname": "gamexbox",
                    "id": 1007,
                    "age": 19
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1008",
                "_score": 1.0,
                "_source": {
                    "nickname": "开源学习",
                    "id": 1008,
                    "age": 19
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1011",
                "_score": 1.0,
                "_source": {
                    "nickname": "皮特帕克",
                    "id": 1011,
                    "age": 31
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
                    "age": 18
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1004",
                "_score": 1.0,
                "_source": {
                    "nickname": "水中鱼",
                    "id": 1004,
                    "age": 22
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1005",
                "_score": 1.0,
                "_source": {
                    "nickname": "ps游戏机",
                    "id": 1005,
                    "age": 25
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1006",
                "_score": 1.0,
                "_source": {
                    "nickname": "我叫小源",
                    "id": 1006,
                    "age": 19
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1009",
                "_score": 1.0,
                "_source": {
                    "nickname": "骚年轮",
                    "id": 1009,
                    "age": 22
                }
            }
        ]
    }
}

```

![](https://tcs.teambition.net/storage/3121f8de3689a47ab9728158d154d5a06ad9?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ2NywiaWF0IjoxNjEwMDk3NjY3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmOGRlMzY4OWE0N2FiOTcyODE1OGQxNTRkNWEwNmFkOSJ9.IByJN-PI6vKPv-KF2hEkI_vKjN5vls61GsG3ecqSNgc&download=image.png "")

![](https://tcs.teambition.net/storage/312105db804c22fbd64bb97f166e00e85204?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ2NywiaWF0IjoxNjEwMDk3NjY3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwNWRiODA0YzIyZmJkNjRiYjk3ZjE2NmUwMGU4NTIwNCJ9.y2JOMlnWvggaNQRIaFdzY9ILKkUoBMz_OjaYTEGNjGc&download=image.png "")

![](https://tcs.teambition.net/storage/3121f82fcc61d18942bd43bdaf0152642819?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ2NywiaWF0IjoxNjEwMDk3NjY3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmODJmY2M2MWQxODk0MmJkNDNiZGFmMDE1MjY0MjgxOSJ9.TZYjkr6Kg7qGkvayA7ZDudIogX8k8yr_WibqE8wmR20&download=image.png "")

![](https://tcs.teambition.net/storage/31210e721bee00acc1cc25cb6e48ece9fd23?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ2NywiaWF0IjoxNjEwMDk3NjY3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwZTcyMWJlZTAwYWNjMWNjMjVjYjZlNDhlY2U5ZmQyMyJ9.qc6u9_5UFYmwcg5RdG4UCktDIbRYdPr-DYsWlfSIlY8&download=image.png "")

![](https://tcs.teambition.net/storage/3121496a7b92bee77988e52396304d13410f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ2NywiaWF0IjoxNjEwMDk3NjY3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0OTZhN2I5MmJlZTc3OTg4ZTUyMzk2MzA0ZDEzNDEwZiJ9.HwfCZrh-0ZgmpjX4jCIEqd_S6THW8USEqW4cxuiL-lY&download=image.png "")

```json
{
    "took": 39,
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
        "hits": [
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1001",
                "_score": 1.0,
                "_source": {
                    "nickname": "开源中国",
                    "id": 1001,
                    "age": 18
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1004",
                "_score": 1.0,
                "_source": {
                    "nickname": "水中鱼",
                    "id": 1004,
                    "age": 22
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1005",
                "_score": 1.0,
                "_source": {
                    "nickname": "ps游戏机",
                    "id": 1005,
                    "age": 25
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1006",
                "_score": 1.0,
                "_source": {
                    "nickname": "我叫小源",
                    "id": 1006,
                    "age": 19
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1009",
                "_score": 1.0,
                "_source": {
                    "nickname": "骚年轮",
                    "id": 1009,
                    "age": 22
                }
            }
        ]
    }
}

```

开源笔记

此笔记在学习的时候做的笔记 所以 没有那么多时间写的很细致或整理排版问题 采用关键帧图片与关键帧文字进行书写 

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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ2NywiaWF0IjoxNjEwMDk3NjY3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.Ie32cbxyU0DXpb4qXiLGvZU89t5vZ2fEoyoTYRR4cao&download=image.png "")

请勿相信图片中任何联系方式

图片来源于视频 作者拿到视频学习已被第三方打码 没办法 截图也没时间去修改图片 请勿相信图片里的任何联系方式

谢谢

