## 文档

![](https://tcs.teambition.net/storage/3121221ab16a795f1d6b3d9d8cc496da822c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ0NiwiaWF0IjoxNjEwMDk3NjQ2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyMjFhYjE2YTc5NWYxZDZiM2Q5ZDhjYzQ5NmRhODIyYyJ9.Ap1-H8nVpkGvvLjCNF11QzxVLH936sCk0vPJ88pkGmw&download=2020-09-17%20174738.png "")

![](https://tcs.teambition.net/storage/3121aa88d1bac1b227635723466100841561?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ0NiwiaWF0IjoxNjEwMDk3NjQ2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhYTg4ZDFiYWMxYjIyNzYzNTcyMzQ2NjEwMDg0MTU2MSJ9.IV4rasf-AKP8TUceFsQfLVk8xriY2kdH78DeNMgJ_PM&download=image.png "")

## 查询

![](https://tcs.teambition.net/storage/3121ad360f277cfa583a26cfe00a3bf0e559?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ0NiwiaWF0IjoxNjEwMDk3NjQ2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZDM2MGYyNzdjZmE1ODNhMjZjZmUwMGEzYmYwZTU1OSJ9.82sWUH4DYwy2-xoiRZWgzZP1S5cFU8vEj50Q89dOd_M&download=image.png "")

q代表检索

属性是desc

检索内容开源

![](https://tcs.teambition.net/storage/3121167374f39992816f2719ea50bdd62eab?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ0NiwiaWF0IjoxNjEwMDk3NjQ2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExNjczNzRmMzk5OTI4MTZmMjcxOWVhNTBiZGQ2MmVhYiJ9.-wzFq9_Mwekri4Q73_XmcrkiBH8YiJdnrbeJ9Gw_8XQ&download=image.png "")

总共一条数据

```json
{
    "took": 191,
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
        "max_score": 1.660784,
        "hits": [
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1001",
                "_score": 1.660784,
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
            }
        ]
    }
}

```

## 多条件查询

![](https://tcs.teambition.net/storage/3121c0376a932ff11e320d5bbd69b1212048?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ0NiwiaWF0IjoxNjEwMDk3NjQ2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjMDM3NmE5MzJmZjExZTMyMGQ1YmJkNjliMTIxMjA0OCJ9.D1J4XX02lYSgOOwkyZN2HxeTW1VmtcDtPqEhJ3Rt4es&download=image.png "")

```json
{
    "took": 58,
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
        "max_score": 1.0,
        "hits": [
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
            }
        ]
    }
}

```

这种查询方式称为 QueryString

![](https://tcs.teambition.net/storage/312196ea2b0c4e94bbf610becb4d2b4401be?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ0NiwiaWF0IjoxNjEwMDk3NjQ2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5NmVhMmIwYzRlOTRiYmY2MTBiZWNiNGQyYjQ0MDFiZSJ9.nnUq9nX7HOM0oVgYdlSiIp9Obkp3xDdB9TCsdA8uwfI&download=image.png "")

![](https://tcs.teambition.net/storage/3121dc35e3b5b5a195074b651147dfab1fef?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ0NiwiaWF0IjoxNjEwMDk3NjQ2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkYzM1ZTNiNWI1YTE5NTA3NGI2NTExNDdkZmFiMWZlZiJ9.YFXtmKAeJ6xs2z-asbZ8sL-eJBrnyI86jVt8HIau7hE&download=image.png "")

![](https://tcs.teambition.net/storage/3121294af74929e1da686c6f2306035750cf?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ0NiwiaWF0IjoxNjEwMDk3NjQ2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyOTRhZjc0OTI5ZTFkYTY4NmM2ZjIzMDYwMzU3NTBjZiJ9.oQwgSRqrPZGYCtYlDO1UjhM8_iJ9a0tWo05SZV3k-4Y&download=image.png "")

## 类型为 text 查询

![](https://tcs.teambition.net/storage/3121f7e9b35f2fcf944cdf1322f7c6c2537c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ0NiwiaWF0IjoxNjEwMDk3NjQ2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmN2U5YjM1ZjJmY2Y5NDRjZGYxMzIyZjdjNmMyNTM3YyJ9.sNVC1l0Uv4QGDmb1GZTx5rjZcm6bsla2T4GalYIToAM&download=image.png "")

![](https://tcs.teambition.net/storage/3121d939b15e7baa3487afadf09a613a817e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ0NiwiaWF0IjoxNjEwMDk3NjQ2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkOTM5YjE1ZTdiYWEzNDg3YWZhZGYwOWE2MTNhODE3ZSJ9.yg1_RSPX2JKG7E5MbRo0aFiTj3R0XZOp6k96InxxOoA&download=image.png "")

```json
{
    "took": 46,
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
        "max_score": 1.8759308,
        "hits": [
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1012",
                "_score": 1.8759308,
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

nickname 字段 text 是倒排索引 会对 super hero 进行分词为

super

hero

## 类型为 keyword 查询

![](https://tcs.teambition.net/storage/312169b5ea456e8c00a0a856bea50f534b4a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ0NiwiaWF0IjoxNjEwMDk3NjQ2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2OWI1ZWE0NTZlOGMwMGEwYTg1NmJlYTUwZjUzNGI0YSJ9.53B3kVo2v-5cqJN9ba9UEVgoBnVUHYlRQa37lyYm7yI&download=image.png "")

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
            "value": 0,
            "relation": "eq"
        },
        "max_score": null,
        "hits": []
    }
}

```

username 为 keyword 不会分词 会把整个作为关键字

![](https://tcs.teambition.net/storage/312195350da4ed16f4f22fab3b217338e1cc?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ0NiwiaWF0IjoxNjEwMDk3NjQ2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5NTM1MGRhNGVkMTZmNGYyMmZhYjNiMjE3MzM4ZTFjYyJ9.efYfsm6Iz0tahMtmxOfVlAqcnrWxOnhN4IjpMmQJTTQ&download=image.png "")

```json
{
    "took": 29,
    "timed_out": false,
    "_shards": {
        "total": 3,
        "successful": 3,
        "skipped": 0,
        "failed": 0
    },
    "hits": {
        "total": {
            "value": 0,
            "relation": "eq"
        },
        "max_score": null,
        "hits": []
    }
}

```

也是搜索不了

## 全量匹配

![](https://tcs.teambition.net/storage/31214a788ef0a9c4b720421ff833dbd2b2b2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ0NiwiaWF0IjoxNjEwMDk3NjQ2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0YTc4OGVmMGE5YzRiNzIwNDIxZmY4MzNkYmQyYjJiMiJ9.ojDevrQj2WBX5TRKINgU5S1O8daeOBwYJ0M3atq5YwE&download=image.png "")

```json
{
    "took": 340,
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
        "max_score": 2.0581827,
        "hits": [
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1012",
                "_score": 2.0581827,
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

完全匹配才能搜索的到

## 结构化搜索方式

DSL Domain Search Language

match 是匹配里的属性

![](https://tcs.teambition.net/storage/312134c17e43409e2ba337b8cf931438981d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ0NiwiaWF0IjoxNjEwMDk3NjQ2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzNGMxN2U0MzQwOWUyYmEzMzdiOGNmOTMxNDM4OTgxZCJ9.XM7l_r6fw7HKhA7lKFidmdhr8Gxab8Sb0cbkOMC0erk&download=image.png "")

```json
{
    "took": 157,
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
        "max_score": 1.660784,
        "hits": [
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1001",
                "_score": 1.660784,
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
            }
        ]
    }
}

```

![](https://tcs.teambition.net/storage/3121991f2cbe6f2428c85fd965181310738e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ0NiwiaWF0IjoxNjEwMDk3NjQ2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5OTFmMmNiZTZmMjQyOGM4NWZkOTY1MTgxMzEwNzM4ZSJ9.NaJh-s0y1p89_5iACLwGxO6eVzLj40WIpRs2dND2lzA&download=image.png "")

```json
{
    "took": 8,
    "timed_out": false,
    "_shards": {
        "total": 3,
        "successful": 3,
        "skipped": 0,
        "failed": 0
    },
    "hits": {
        "total": {
            "value": 0,
            "relation": "eq"
        },
        "max_score": null,
        "hits": []
    }
}

```

![](https://tcs.teambition.net/storage/31215068b8fa07cfaf61c4323070971e60b6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ0NiwiaWF0IjoxNjEwMDk3NjQ2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1MDY4YjhmYTA3Y2ZhZjYxYzQzMjMwNzA5NzFlNjBiNiJ9.sn-MwHfo5C1Wwu_wQIlhgKKqvfTE6X-knI16cMTdG90&download=image.png "")

```json
{
    "took": 10,
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
        "max_score": 1.8759308,
        "hits": [
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1012",
                "_score": 1.8759308,
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

![](https://tcs.teambition.net/storage/31214eee526e511cb5262fa70a6bdb7bac95?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ0NiwiaWF0IjoxNjEwMDk3NjQ2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0ZWVlNTI2ZTUxMWNiNTI2MmZhNzBhNmJkYjdiYWM5NSJ9.rjI9APhFGtQh6WH-zFmlij76OQj3xSb1MCts_kHuHlo&download=image.png "")

```json
{
    "took": 34,
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
        "max_score": 1.6739764,
        "hits": [
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1012",
                "_score": 1.6739764,
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

## exists 判断某个字段存在 会列出文档数据 个数

![](https://tcs.teambition.net/storage/31216e8c50012cdaea46aeb4bf97ef86bb53?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ0NiwiaWF0IjoxNjEwMDk3NjQ2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2ZThjNTAwMTJjZGFlYTQ2YWViNGJmOTdlZjg2YmI1MyJ9.9ZoBAhdb5GGF7ZZ5UmSdxWU2zp3PIipW3_10EtFLv_w&download=image.png "")

```json
{
    "took": 52,
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

## 查询不存在

![](https://tcs.teambition.net/storage/31213792135a803dd466f84c495c7ef4b1d9?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ0NiwiaWF0IjoxNjEwMDk3NjQ2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzNzkyMTM1YTgwM2RkNDY2Zjg0YzQ5NWM3ZWY0YjFkOSJ9.ZNLvf8FEkH3d1WckIWaJrlTc2q3do8QB256bkh05o58&download=image.png "")

```json
{
    "took": 17,
    "timed_out": false,
    "_shards": {
        "total": 3,
        "successful": 3,
        "skipped": 0,
        "failed": 0
    },
    "hits": {
        "total": {
            "value": 0,
            "relation": "eq"
        },
        "max_score": null,
        "hits": []
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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjQ0NiwiaWF0IjoxNjEwMDk3NjQ2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.6AhsOXQCMB6bRN1Jo8gqnmLvGvDX_wlkFv1iT0-PoOg&download=image.png "")

请勿相信图片中任何联系方式

图片来源于视频 作者拿到视频学习已被第三方打码 没办法 截图也没时间去修改图片 请勿相信图片里的任何联系方式

谢谢

