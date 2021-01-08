

![](https://tcs.teambition.net/storage/3121e067743c892063cda3c2be4a1f2d3ad2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjU1NiwiaWF0IjoxNjEwMDk3NzU2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlMDY3NzQzYzg5MjA2M2NkYTNjMmJlNGExZjJkM2FkMiJ9.3n18AdbsIhIZ4uPd8sfh4Uyl4IAnbK_8yOB651dRxAY&download=2020-09-17%20175439.png "")

## must 必须匹配

![](https://tcs.teambition.net/storage/3121bf11c69caabf340b1811ec327a467803?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjU1NiwiaWF0IjoxNjEwMDk3NzU2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiZjExYzY5Y2FhYmYzNDBiMTgxMWVjMzI3YTQ2NzgwMyJ9.6Sm5XyU0oiwQ8KYvtN4wiW9Y2o8Vt6OQmEtqzXgbLOY&download=image.png "")

```json
{
    "query": {
        "bool": {
            "must": [
                {
                    "multi_match": {
                        "query": "开源",
                        "fields": [
                            "desc",
                            "nickname"
                        ]
                    }
                }
            ]
        }
    },
    "_source": [
        "id",
        "sex",
        "nickname",
        "desc"
    ]
}

```

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
            "value": 2,
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
                    "sex": 0,
                    "nickname": "开源中国",
                    "id": 1001,
                    "desc": "我的开源中国学习java和前端，学习了很多知识"
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1008",
                "_score": 1.5308114,
                "_source": {
                    "sex": 1,
                    "nickname": "开源学习",
                    "id": 1008,
                    "desc": "大学毕业后，可以到gitee.com进修"
                }
            }
        ]
    }
}

```

![](https://tcs.teambition.net/storage/3121845d36cd12a4a34294b41eea49d99c3c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjU1NiwiaWF0IjoxNjEwMDk3NzU2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4NDVkMzZjZDEyYTRhMzQyOTRiNDFlZWE0OWQ5OWMzYyJ9.2VC6AwNURhRiEcxBfo1oi4-AhfZo2IFl3JS0N9CVy2Y&download=image.png "")

```json
{
    "query": {
        "bool": {
            "must": [
                {
                    "multi_match": {
                        "query": "开源",
                        "fields": [
                            "desc",
                            "nickname"
                        ]
                    }
                },
                {
                    "term": {
                        "sex": 1
                    }
                }
            ]
        }
    },
    "_source": [
        "id",
        "sex",
        "nickname",
        "desc"
    ]
}

```

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
            "value": 1,
            "relation": "eq"
        },
        "max_score": 2.5308113,
        "hits": [
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1008",
                "_score": 2.5308113,
                "_source": {
                    "sex": 1,
                    "nickname": "开源学习",
                    "id": 1008,
                    "desc": "大学毕业后，可以到gitee.com进修"
                }
            }
        ]
    }
}

```

![](https://tcs.teambition.net/storage/312180047e82a8114838d80e3cf0d53e9ae6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjU1NiwiaWF0IjoxNjEwMDk3NzU2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4MDA0N2U4MmE4MTE0ODM4ZDgwZTNjZjBkNTNlOWFlNiJ9.fubBA8hjCxref_au-zADLujsQxoiZg4iZppu7V1qzuI&download=image.png "")

![](https://tcs.teambition.net/storage/3121f67c7e11a60a5de775b502d0dc0f8958?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjU1NiwiaWF0IjoxNjEwMDk3NzU2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmNjdjN2UxMWE2MGE1ZGU3NzViNTAyZDBkYzBmODk1OCJ9.fPfW3G8UDGUQpHZKl3WoFmqNSBcftwp4kX-HVygjMD0&download=image.png "")

```json
{
    "query": {
        "bool": {
            "must": [
                {
                    "multi_match": {
                        "query": "开源",
                        "fields": [
                            "desc",
                            "nickname"
                        ]
                    }
                },
                {
                    "term": {
                        "sex": 1
                    }
                },
                {
                    "term": {
                        "birthday": "1992-12-24"
                    }
                }
            ]
        }
    },
    "_source": [
        "id",
        "sex",
        "nickname",
        "desc",
        "birthday"
    ]
}

```

```json
{
    "took": 270,
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

## should 只要其中一个条件满足就能被搜索出来

```json
{
    "query": {
        "bool": {
            "should": [
                {
                    "multi_match": {
                        "query": "开源",
                        "fields": [
                            "desc",
                            "nickname"
                        ]
                    }
                },
                {
                    "term": {
                        "sex": 1
                    }
                },
                {
                    "term": {
                        "birthday": "1992-12-24"
                    }
                }
            ]
        }
    },
    "_source": [
        "id",
        "sex",
        "nickname",
        "desc",
        "birthday"
    ]
}

```

```json
{
    "took": 115,
    "timed_out": false,
    "_shards": {
        "total": 3,
        "successful": 3,
        "skipped": 0,
        "failed": 0
    },
    "hits": {
        "total": {
            "value": 11,
            "relation": "eq"
        },
        "max_score": 2.660784,
        "hits": [
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1001",
                "_score": 2.660784,
                "_source": {
                    "birthday": "1992-12-24",
                    "sex": 0,
                    "nickname": "开源中国",
                    "id": 1001,
                    "desc": "我的开源中国学习java和前端，学习了很多知识"
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1008",
                "_score": 2.5308113,
                "_source": {
                    "birthday": "1995-06-14",
                    "sex": 1,
                    "nickname": "开源学习",
                    "id": 1008,
                    "desc": "大学毕业后，可以到gitee.com进修"
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1002",
                "_score": 1.0,
                "_source": {
                    "birthday": "1993-01-24",
                    "sex": 1,
                    "nickname": "周杰棍",
                    "id": 1002,
                    "desc": "今天上下班都很堵，车流量很大"
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1003",
                "_score": 1.0,
                "_source": {
                    "birthday": "1996-01-14",
                    "sex": 1,
                    "nickname": "飞翔的巨鹰",
                    "id": 1003,
                    "desc": "慕课网团队和导游坐飞机去海外旅游,去了新马泰和欧洲"
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1007",
                "_score": 1.0,
                "_source": {
                    "birthday": "1985-05-14",
                    "sex": 1,
                    "nickname": "gamexbox",
                    "id": 1007,
                    "desc": "明天去进货，最近微软处理很多游戏机，还要买xbox游戏卡带"
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1011",
                "_score": 1.0,
                "_source": {
                    "birthday": "1989-08-14",
                    "sex": 1,
                    "nickname": "皮特帕克",
                    "id": 1011,
                    "desc": "它是一个超级英雄"
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1005",
                "_score": 1.0,
                "_source": {
                    "birthday": "1989-03-14",
                    "sex": 1,
                    "nickname": "ps游戏机",
                    "id": 1005,
                    "desc": "今年生日，女友送了我一台play station游戏机，非常好玩，非常不错"
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1006",
                "_score": 1.0,
                "_source": {
                    "birthday": "1993-04-14",
                    "sex": 1,
                    "nickname": "我叫小源",
                    "id": 1006,
                    "desc": "我叫凌云彻，今年20岁，是一名律师，我在琦星球做演讲"
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1009",
                "_score": 1.0,
                "_source": {
                    "birthday": "1998-07-14",
                    "sex": 1,
                    "nickname": "骚年轮",
                    "id": 1009,
                    "desc": "骚年在大学毕业后，考研究生去了"
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1010",
                "_score": 1.0,
                "_source": {
                    "birthday": "1988-07-14",
                    "sex": 1,
                    "nickname": "隔壁老王",
                    "id": 1010,
                    "desc": "隔壁老外去国外出差，带给我很多好吃的"
                }
            }
        ]
    }
}

```

## must_not

![](https://tcs.teambition.net/storage/31210f0350a44b0bb470fb73d15333e039a7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjU1NiwiaWF0IjoxNjEwMDk3NzU2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwZjAzNTBhNDRiMGJiNDcwZmI3M2QxNTMzM2UwMzlhNyJ9.m4pXTbeUs7m8VYqPECWB8XhGzerkw9C7MDLpqq8p9QM&download=image.png "")

```json
{
    "query": {
        "bool": {
            "must_not": [
                {
                    "multi_match": {
                        "query": "开源",
                        "fields": [
                            "desc",
                            "nickname"
                        ]
                    }
                },
                {
                    "term": {
                        "sex": 1
                    }
                },
                {
                    "term": {
                        "birthday": "1992-12-24"
                    }
                }
            ]
        }
    },
    "_source": [
        "id",
        "sex",
        "nickname",
        "desc",
        "birthday"
    ]
}

```

```json
{
    "took": 70,
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
        "max_score": 0.0,
        "hits": [
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1004",
                "_score": 0.0,
                "_source": {
                    "birthday": "1988-02-14",
                    "sex": 0,
                    "nickname": "水中鱼",
                    "id": 1004,
                    "desc": "昨天在学校的池塘里，看到有很多鱼在游泳，然后就去慕课网上课了"
                }
            }
        ]
    }
}

```

## 组合查询

![](https://tcs.teambition.net/storage/312102ff7ed8b7fe3f4c8c5ae9ffa381993b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjU1NiwiaWF0IjoxNjEwMDk3NzU2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwMmZmN2VkOGI3ZmUzZjRjOGM1YWU5ZmZhMzgxOTkzYiJ9.jwKQoHFD9RoSP-ycQV3raFz81VZrCEw_Opiyph_DkJk&download=image.png "")

![](https://tcs.teambition.net/storage/312184749ed48aa3f0088e1a8e1c46e17f46?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjU1NiwiaWF0IjoxNjEwMDk3NzU2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4NDc0OWVkNDhhYTNmMDA4OGUxYThlMWM0NmUxN2Y0NiJ9.AgR-p6s4j6vepIbBD-wM_RhDXHZx6QTkiD5-IiKRFh0&download=image.png "")

![](https://tcs.teambition.net/storage/3121a562636046a38eb5d5427cf7c6d8f375?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjU1NiwiaWF0IjoxNjEwMDk3NzU2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhNTYyNjM2MDQ2YTM4ZWI1ZDU0MjdjZjdjNmQ4ZjM3NSJ9.GUK1srYgkUhgtXYRZ1jkmqPG958qA1m_K2GJOTiqfqY&download=image.png "")

## must 必须满足 should 或者 满足 在这里是满不满足都可以 must_not 满足取反

```json
{
    "query": {
        "bool": {
            "must": [
                {
                    "match": {
                        "desc": "开源"
                    }
                },
                {
                    "match": {
                        "nickname": "开源"
                    }
                }
            ],
            "should": [
                {
                    "match": {
                        "sex": 1
                    }
                }
            ],
            "must_not": [
                {
                    "term": {
                        "birthday": "1992-12-23"
                    }
                }
            ]
        }
    },
    "_source": [
        "id",
        "sex",
        "nickname",
        "desc",
        "birthday"
    ]
}
 


```

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
            "value": 1,
            "relation": "eq"
        },
        "max_score": 3.2656512,
        "hits": [
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1001",
                "_score": 3.2656512,
                "_source": {
                    "birthday": "1992-12-24",
                    "sex": 0,
                    "nickname": "开源中国",
                    "id": 1001,
                    "desc": "我的开源中国学习java和前端，学习了很多知识"
                }
            }
        ]
    }
}

```

![](https://tcs.teambition.net/storage/3121286d587589600b2325294d9cd6e36222?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjU1NiwiaWF0IjoxNjEwMDk3NzU2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyODZkNTg3NTg5NjAwYjIzMjUyOTRkOWNkNmUzNjIyMiJ9.NT-mYydesSUcYxwn-It_DlD5kmKlO52sxeIH6a64DQY&download=image.png "")

![](https://tcs.teambition.net/storage/3121e4c26b6573c584c5436410003b56b69b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjU1NiwiaWF0IjoxNjEwMDk3NzU2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlNGMyNmI2NTczYzU4NGM1NDM2NDEwMDAzYjU2YjY5YiJ9.2fuH2sFksUS-1Q2z16gNwTQnvluKImcCAzy5HXeltlU&download=image.png "")

![](https://tcs.teambition.net/storage/3121467ad470a32b9bdd965ac992e7c7d0ab?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjU1NiwiaWF0IjoxNjEwMDk3NzU2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0NjdhZDQ3MGEzMmI5YmRkOTY1YWM5OTJlN2M3ZDBhYiJ9.w8wHSD5kkL1g8C9J5P1CQtVqhEViWO_-_Pi9AtGRgsw&download=image.png "")

![](https://tcs.teambition.net/storage/312127cd537a535af78698349786b254c4d2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjU1NiwiaWF0IjoxNjEwMDk3NzU2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyN2NkNTM3YTUzNWFmNzg2OTgzNDk3ODZiMjU0YzRkMiJ9.0EBn7iJVg5rEvypyxkJyV58TUjW1xqEaxVoXIMuL__w&download=image.png "")

```json

{
    "query": {
        "bool": {
            "should": [
                {
                    "match": {
                        "desc": {
                            "query": "开源",
                            "boost": 2
                        }
                    }
                },
                {
                    "match": {
                        "desc": {
                            "query": "律师",
                            "boost": 4
                        }
                    }
                }
            ]
        }
    },
    "_source": [
        "id",
        "sex",
        "nickname",
        "desc",
        "birthday"
    ]
}
 

```

```json
{
    "took": 81,
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
        "max_score": 6.135432,
        "hits": [
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1006",
                "_score": 6.135432,
                "_source": {
                    "birthday": "1993-04-14",
                    "sex": 1,
                    "nickname": "我叫小源",
                    "id": 1006,
                    "desc": "我叫凌云彻，今年20岁，是一名律师，我在琦星球做演讲"
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1001",
                "_score": 3.321568,
                "_source": {
                    "birthday": "1992-12-24",
                    "sex": 0,
                    "nickname": "开源中国",
                    "id": 1001,
                    "desc": "我的开源中国学习java和前端，学习了很多知识"
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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjU1NiwiaWF0IjoxNjEwMDk3NzU2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.QNwTPcq1JLnOYDGmlQh8-MRxnJHQHnISGM8NQToqElo&download=image.png "")

请勿相信图片中任何联系方式

图片来源于视频 作者拿到视频学习已被第三方打码 没办法 截图也没时间去修改图片 请勿相信图片里的任何联系方式

谢谢

