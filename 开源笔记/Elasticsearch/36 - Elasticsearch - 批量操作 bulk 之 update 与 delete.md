## bulk update 与 单个_update 一样 doc 代表文档

![](https://tcs.teambition.net/storage/312153a091ec716c82775fd17cee9f71677f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjczMSwiaWF0IjoxNjEwMDk3OTMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1M2EwOTFlYzcxNmM4Mjc3NWZkMTdjZWU5ZjcxNjc3ZiJ9.TwdHRWxMKraJdc0deD7-DJihALgqimE9BbdkeOOJJuU&download=image.png "")

```json
{"update": {"_id": "2004"}}
{"doc": {"id": "3304"}}
{"update": {"_id": "2007"}}
{"doc": {"nickname": "name-update"}}


```

```json
{
    "took": 166,
    "errors": false,
    "items": [
        {
            "update": {
                "_index": "shop2",
                "_type": "_doc",
                "_id": "2004",
                "_version": 3,
                "result": "updated",
                "_shards": {
                    "total": 2,
                    "successful": 1,
                    "failed": 0
                },
                "_seq_no": 5,
                "_primary_term": 1,
                "status": 200
            }
        },
        {
            "update": {
                "_index": "shop2",
                "_type": "_doc",
                "_id": "2007",
                "_version": 2,
                "result": "updated",
                "_shards": {
                    "total": 2,
                    "successful": 1,
                    "failed": 0
                },
                "_seq_no": 2,
                "_primary_term": 1,
                "status": 200
            }
        }
    ]
}

```

![](https://tcs.teambition.net/storage/3121f6bfccf21380648b2c1b03a7e6f137d3?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjczMSwiaWF0IjoxNjEwMDk3OTMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmNmJmY2NmMjEzODA2NDhiMmMxYjAzYTdlNmYxMzdkMyJ9.Av2zb9DA9GanR8ml6Yx4nSD1-d4zRWD0ToEkG5N2OB0&download=image.png "")

## delete 

![](https://tcs.teambition.net/storage/312110c742ba19e47c269c1eb5791b39275a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjczMSwiaWF0IjoxNjEwMDk3OTMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExMGM3NDJiYTE5ZTQ3YzI2OWMxZWI1NzkxYjM5Mjc1YSJ9.HiNgjnMeLJuVxNq4FpuTcDIIZscitCah-2aJ73z0xHk&download=image.png "")

```json
{"delete": {"_id": "2004"}}
{"delete": {"_id": "2007"}}


```

```json
{
    "took": 361,
    "errors": false,
    "items": [
        {
            "delete": {
                "_index": "shop2",
                "_type": "_doc",
                "_id": "2004",
                "_version": 4,
                "result": "deleted",
                "_shards": {
                    "total": 2,
                    "successful": 1,
                    "failed": 0
                },
                "_seq_no": 6,
                "_primary_term": 1,
                "status": 200
            }
        },
        {
            "delete": {
                "_index": "shop2",
                "_type": "_doc",
                "_id": "2007",
                "_version": 3,
                "result": "deleted",
                "_shards": {
                    "total": 2,
                    "successful": 1,
                    "failed": 0
                },
                "_seq_no": 3,
                "_primary_term": 1,
                "status": 200
            }
        }
    ]
}

```

![](https://tcs.teambition.net/storage/3121ae692938c416e3c6da53a8f16bf2b050?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjczMSwiaWF0IjoxNjEwMDk3OTMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZTY5MjkzOGM0MTZlM2M2ZGE1M2E4ZjE2YmYyYjA1MCJ9.gwnznwe266Rs3rvLYm1XJrVggYZAtmwh6ggXh-7vzRg&download=image.png "")

## 组合操作

![](https://tcs.teambition.net/storage/31211b4d275d1a6e690a3e757929d4f748cd?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjczMSwiaWF0IjoxNjEwMDk3OTMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExYjRkMjc1ZDFhNmU2OTBhM2U3NTc5MjlkNGY3NDhjZCJ9.mxks4JotXQbcjGA1TrR9BdcYam2v-p-dJhZc4DaAUdI&download=image.png "")

```json
{"delete": {"_id": "2001"}}
{"delete": {"_id": "2003"}}
{"create": {"_id": "8008"}}
{"id": "8008", "nickname": "name8008"}
{"update": {"_id": "2002"}}
{"doc":{"id": "2222"}}



```

```json
{
    "took": 37,
    "errors": false,
    "items": [
        {
            "delete": {
                "_index": "shop2",
                "_type": "_doc",
                "_id": "2001",
                "_version": 2,
                "result": "deleted",
                "_shards": {
                    "total": 2,
                    "successful": 1,
                    "failed": 0
                },
                "_seq_no": 7,
                "_primary_term": 1,
                "status": 200
            }
        },
        {
            "delete": {
                "_index": "shop2",
                "_type": "_doc",
                "_id": "2003",
                "_version": 2,
                "result": "deleted",
                "_shards": {
                    "total": 2,
                    "successful": 1,
                    "failed": 0
                },
                "_seq_no": 8,
                "_primary_term": 1,
                "status": 200
            }
        },
        {
            "create": {
                "_index": "shop2",
                "_type": "_doc",
                "_id": "8008",
                "_version": 1,
                "result": "created",
                "_shards": {
                    "total": 2,
                    "successful": 1,
                    "failed": 0
                },
                "_seq_no": 9,
                "_primary_term": 1,
                "status": 201
            }
        },
        {
            "update": {
                "_index": "shop2",
                "_type": "_doc",
                "_id": "2002",
                "_version": 2,
                "result": "updated",
                "_shards": {
                    "total": 2,
                    "successful": 1,
                    "failed": 0
                },
                "_seq_no": 3,
                "_primary_term": 1,
                "status": 200
            }
        }
    ]
}

```

![](https://tcs.teambition.net/storage/3121853bf04f612a988fd2f5708edb2afa75?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjczMSwiaWF0IjoxNjEwMDk3OTMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4NTNiZjA0ZjYxMmE5ODhmZDJmNTcwOGVkYjJhZmE3NSJ9.XyGqkfEeDfNWHn2s4QQCixnNfvJpb2HzDPk9uzCnrRo&download=image.png "")

## 最佳批量操作的阀值 操作性能下降就是这个 阀值 批量操作的数据量 



![](https://tcs.teambition.net/storage/3121731777d54b231b8a9cf7af8a027105d2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjczMSwiaWF0IjoxNjEwMDk3OTMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3MzE3NzdkNTRiMjMxYjhhOWNmN2FmOGEwMjcxMDVkMiJ9.zXVe7rIunZT8JjZIq_mJrQHbwqQkT_CRM2Di1SrFfZw&download=image.png "")

![](https://tcs.teambition.net/storage/3121b1265c9fd4638f85bbe52f5980f12874?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjczMSwiaWF0IjoxNjEwMDk3OTMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiMTI2NWM5ZmQ0NjM4Zjg1YmJlNTJmNTk4MGYxMjg3NCJ9.XXl4qz7yY_OYD5hcWTMnQmYWrd3qnt_affzkSvd4mls&download=image.png "")

![](https://tcs.teambition.net/storage/312125c5fd576d5612585eab3251093b7af9?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjczMSwiaWF0IjoxNjEwMDk3OTMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyNWM1ZmQ1NzZkNTYxMjU4NWVhYjMyNTEwOTNiN2FmOSJ9.X_X5kg_hVQ6v465DQxRx0X1S_IY_SiaiDHzbRxD7Og0&download=image.png "")

![](https://tcs.teambition.net/storage/3121f78382ac99d960eb199765db78887ed2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjczMSwiaWF0IjoxNjEwMDk3OTMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmNzgzODJhYzk5ZDk2MGViMTk5NzY1ZGI3ODg4N2VkMiJ9.DIiL_PqO-MkJqvg0g0AJiaacSZt-ebMlk-jx2tOekw0&download=image.png "")

![](https://tcs.teambition.net/storage/3121da3d166243ac78c6aa836e50e56bb81f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjczMSwiaWF0IjoxNjEwMDk3OTMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkYTNkMTY2MjQzYWM3OGM2YWE4MzZlNTBlNTZiYjgxZiJ9.eBH2-xWir-nfRMlYlW0Mnq1Je_0YZB_nYkPB_mnNbqk&download=image.png "")

![](https://tcs.teambition.net/storage/3121d3a9ac119b9b62e04cf79412c0476e47?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjczMSwiaWF0IjoxNjEwMDk3OTMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkM2E5YWMxMTliOWI2MmUwNGNmNzk0MTJjMDQ3NmU0NyJ9.cY_tEJv6jCqy60OgWSy4GgiOQrqI-jNcAIAVTspBRpg&download=image.png "")

![](https://tcs.teambition.net/storage/312121900c5003542c92c28b98d49624bc60?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjczMSwiaWF0IjoxNjEwMDk3OTMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyMTkwMGM1MDAzNTQyYzkyYzI4Yjk4ZDQ5NjI0YmM2MCJ9.-exWtLCVYNcSigoN9DcQRwGegW21lnsD0E9uHjXTYJs&download=image.png "")

![](https://tcs.teambition.net/storage/31213d8cdda4f800a78994b5844369393922?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjczMSwiaWF0IjoxNjEwMDk3OTMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzZDhjZGRhNGY4MDBhNzg5OTRiNTg0NDM2OTM5MzkyMiJ9.SbgnVdyc1Cu6uB3MZGC46fLSs0JvHLQ4Ry8zilD-7us&download=image.png "")

![](https://tcs.teambition.net/storage/3121108109b55586a39ad80169572a61a550?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjczMSwiaWF0IjoxNjEwMDk3OTMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExMDgxMDliNTU1ODZhMzlhZDgwMTY5NTcyYTYxYTU1MCJ9.Scieuyvb5TXWahb95at0ZbK4CvIKf9101b7LNfkTXG8&download=image.png "")

![](https://tcs.teambition.net/storage/312199e44b7ba87a10ef705bd5b63306e54a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjczMSwiaWF0IjoxNjEwMDk3OTMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5OWU0NGI3YmE4N2ExMGVmNzA1YmQ1YjYzMzA2ZTU0YSJ9.3LHpOk1vBW0kmuOG2bBd9PjfdhCe_WsNWUsCGXlh8Sk&download=image.png "")

![](https://tcs.teambition.net/storage/3121b209da3d69f4d8a534b1b390e351ac2f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjczMSwiaWF0IjoxNjEwMDk3OTMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiMjA5ZGEzZDY5ZjRkOGE1MzRiMWIzOTBlMzUxYWMyZiJ9.w3V3sbZlZ1Aq8cYgFdnSV3KcWmVZeK-knO9yXxBUuKo&download=image.png "")

![](https://tcs.teambition.net/storage/3121f7bc4a5240f708bcb9444d6527bcd23f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjczMSwiaWF0IjoxNjEwMDk3OTMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmN2JjNGE1MjQwZjcwOGJjYjk0NDRkNjUyN2JjZDIzZiJ9.iHLSZxV3xLLrwUaUUp58nkMmlg2CoCJTEkWlhmuSgMs&download=image.png "")

[__https://www.elastic.co/guide/cn/elasticsearch/guide/current/bulk.html__](https://www.elastic.co/guide/cn/elasticsearch/guide/current/bulk.html)

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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjczMSwiaWF0IjoxNjEwMDk3OTMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.EgpjWGaJI7lOaMea6pu2CFlHcVaTrwAbHRYT4p93dHg&download=image.png "")

请勿相信图片中任何联系方式

图片来源于视频 作者拿到视频学习已被第三方打码 没办法 截图也没时间去修改图片 请勿相信图片里的任何联系方式

谢谢

