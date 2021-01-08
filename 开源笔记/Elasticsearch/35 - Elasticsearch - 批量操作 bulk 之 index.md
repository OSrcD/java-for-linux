

## 提取到url

![](https://tcs.teambition.net/storage/312140a9b78cd7b92e9860670e5d08fd1e80?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjcxMiwiaWF0IjoxNjEwMDk3OTEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0MGE5Yjc4Y2Q3YjkyZTk4NjA2NzBlNWQwOGZkMWU4MCJ9.e8EcBz5mjH7vYSQdEpZ5aM26IB4tX0KUkVG8U-N6FbA&download=image.png "")

```json
{"create":{"_id": "2004"}}
{"id": "2004", "nickname": "name-2004"}
{"create":{"_id": "2005"}}
{"id": "2005", "nickname": "name-2005"}
{"create":{"_id": "2006"}}
{"id": "2006", "nickname": "name-2006"}


```

```json
{
    "took": 37,
    "errors": true,
    "items": [
        {
            "create": {
                "_index": "shop2",
                "_type": "_doc",
                "_id": "2004",
                "status": 409,
                "error": {
                    "type": "version_conflict_engine_exception",
                    "reason": "[2004]: version conflict, document already exists (current version [1])",
                    "index_uuid": "o3LMyQ9tRyu2-MF1FKuWHA",
                    "shard": "4",
                    "index": "shop2"
                }
            }
        },
        {
            "create": {
                "_index": "shop2",
                "_type": "_doc",
                "_id": "2005",
                "status": 409,
                "error": {
                    "type": "version_conflict_engine_exception",
                    "reason": "[2005]: version conflict, document already exists (current version [1])",
                    "index_uuid": "o3LMyQ9tRyu2-MF1FKuWHA",
                    "shard": "4",
                    "index": "shop2"
                }
            }
        },
        {
            "create": {
                "_index": "shop2",
                "_type": "_doc",
                "_id": "2006",
                "status": 409,
                "error": {
                    "type": "version_conflict_engine_exception",
                    "reason": "[2006]: version conflict, document already exists (current version [1])",
                    "index_uuid": "o3LMyQ9tRyu2-MF1FKuWHA",
                    "shard": "2",
                    "index": "shop2"
                }
            }
        }
    ]
}

```

## bulk index 创建或替换文档数据 index = create \ update

![](https://tcs.teambition.net/storage/312107e94b484d560c59657e1502199cf7b0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjcxMiwiaWF0IjoxNjEwMDk3OTEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwN2U5NGI0ODRkNTYwYzU5NjU3ZTE1MDIxOTljZjdiMCJ9.JQwuXKtNeClCbdoiGMjAHYideUoP1s8s9czQWqkSl58&download=image.png "")

```json
{"index":{"_id": "2004"}}
{"id": "2004", "nickname": "name-2004"}
{"index":{"_id": "2007"}}
{"id": "2007", "nickname": "name-2007"}
{"index":{"_id": "2008"}}
{"id": "2008", "nickname": "name-2008"}


```

```json
{
    "took": 201,
    "errors": false,
    "items": [
        {
            "index": {
                "_index": "shop2",
                "_type": "_doc",
                "_id": "2004",
                "_version": 2,
                "result": "updated",
                "_shards": {
                    "total": 2,
                    "successful": 1,
                    "failed": 0
                },
                "_seq_no": 4,
                "_primary_term": 1,
                "status": 200
            }
        },
        {
            "index": {
                "_index": "shop2",
                "_type": "_doc",
                "_id": "2007",
                "_version": 1,
                "result": "created",
                "_shards": {
                    "total": 2,
                    "successful": 1,
                    "failed": 0
                },
                "_seq_no": 1,
                "_primary_term": 1,
                "status": 201
            }
        },
        {
            "index": {
                "_index": "shop2",
                "_type": "_doc",
                "_id": "2008",
                "_version": 1,
                "result": "created",
                "_shards": {
                    "total": 2,
                    "successful": 1,
                    "failed": 0
                },
                "_seq_no": 4,
                "_primary_term": 1,
                "status": 201
            }
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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjcxMiwiaWF0IjoxNjEwMDk3OTEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.3xo-IgQm1RkVmtclBLoXKjqB3DSKeRxqlybpkH4sovs&download=image.png "")

请勿相信图片中任何联系方式

图片来源于视频 作者拿到视频学习已被第三方打码 没办法 截图也没时间去修改图片 请勿相信图片里的任何联系方式

谢谢

