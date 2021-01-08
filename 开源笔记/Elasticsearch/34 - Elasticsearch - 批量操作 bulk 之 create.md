

![](https://tcs.teambition.net/storage/312118571d726a04118080546f0047ce547a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjY5OSwiaWF0IjoxNjEwMDk3ODk5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExODU3MWQ3MjZhMDQxMTgwODA1NDZmMDA0N2NlNTQ3YSJ9.o7Ud0sbi8Ym9nU6Y3181clgDoIDxLZAZD-gELiP8dYo&download=2020-09-17%20175624.png "")

## _bulk create 

## items 创建的结果

![](https://tcs.teambition.net/storage/312109b7972f39844d42f2a4286231e95265?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjY5OSwiaWF0IjoxNjEwMDk3ODk5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwOWI3OTcyZjM5ODQ0ZDQyZjJhNDI4NjIzMWU5NTI2NSJ9.zOxJGpZzmsLL0x6e6z4bT-7AkFPkn9biaa2djIw2aEE&download=image.png "")

```json
{"create":{"_index": "shop2", "_type": "_doc", "_id": "2001"}}
{"id": "2001", "nickname": "name-2001"}
{"create":{"_index": "shop2", "_type": "_doc", "_id": "2002"}}
{"id": "2002", "nickname": "name-2002"}
{"create":{"_index": "shop2", "_type": "_doc", "_id": "2003"}}
{"id": "2003", "nickname": "name-2003"}


```

```json
{
    "took": 372,
    "errors": false,
    "items": [
        {
            "create": {
                "_index": "shop2",
                "_type": "_doc",
                "_id": "2001",
                "_version": 1,
                "result": "created",
                "_shards": {
                    "total": 2,
                    "successful": 1,
                    "failed": 0
                },
                "_seq_no": 0,
                "_primary_term": 1,
                "status": 201
            }
        },
        {
            "create": {
                "_index": "shop2",
                "_type": "_doc",
                "_id": "2002",
                "_version": 1,
                "result": "created",
                "_shards": {
                    "total": 2,
                    "successful": 1,
                    "failed": 0
                },
                "_seq_no": 2,
                "_primary_term": 1,
                "status": 201
            }
        },
        {
            "create": {
                "_index": "shop2",
                "_type": "_doc",
                "_id": "2003",
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
        }
    ]
}

```

![](https://tcs.teambition.net/storage/3121c9a0cc536db4869b5235820dd0d86a8e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjY5OSwiaWF0IjoxNjEwMDk3ODk5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjOWEwY2M1MzZkYjQ4NjliNTIzNTgyMGRkMGQ4NmE4ZSJ9.Q8UIbdhDr_oIT-dGsIBQemZBKGT93nXLpasKOsIO5cY&download=image.png "")

![](https://tcs.teambition.net/storage/3121b53309e30281e58e2882451dbfe3d56d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjY5OSwiaWF0IjoxNjEwMDk3ODk5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiNTMzMDllMzAyODFlNThlMjg4MjQ1MWRiZmUzZDU2ZCJ9.Y9DFhoXahAdUrPTuTi_34LgAU7U2kkUqct5i4epl0Ss&download=image.png "")

```json
{"create":{"_index": "shop2", "_type": "_doc", "_id": "2004"}}
{"id": "2004", "nickname": "name-2004"}
{"create":{"_index": "shop2", "_type": "_doc", "_id": "2005"}}
{"id": "2005", "nickname": "name-2005"}
{"create":{"_index": "shop2", "_type": "_doc", "_id": "2006"}}
{"id": "2006", "nickname": "name-2006"}


```

```json
{
    "took": 114,
    "errors": false,
    "items": [
        {
            "create": {
                "_index": "shop2",
                "_type": "_doc",
                "_id": "2004",
                "_version": 1,
                "result": "created",
                "_shards": {
                    "total": 2,
                    "successful": 1,
                    "failed": 0
                },
                "_seq_no": 2,
                "_primary_term": 1,
                "status": 201
            }
        },
        {
            "create": {
                "_index": "shop2",
                "_type": "_doc",
                "_id": "2005",
                "_version": 1,
                "result": "created",
                "_shards": {
                    "total": 2,
                    "successful": 1,
                    "failed": 0
                },
                "_seq_no": 3,
                "_primary_term": 1,
                "status": 201
            }
        },
        {
            "create": {
                "_index": "shop2",
                "_type": "_doc",
                "_id": "2006",
                "_version": 1,
                "result": "created",
                "_shards": {
                    "total": 2,
                    "successful": 1,
                    "failed": 0
                },
                "_seq_no": 3,
                "_primary_term": 1,
                "status": 201
            }
        }
    ]
}

```

![](https://tcs.teambition.net/storage/312126b344345dffda7c843100f01f9a0683?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjY5OSwiaWF0IjoxNjEwMDk3ODk5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyNmIzNDQzNDVkZmZkYTdjODQzMTAwZjAxZjlhMDY4MyJ9.03gks6kOXS9BTlam1Ydt34CA0sW3uRBZVCL0SrokAOQ&download=image.png "")





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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjY5OSwiaWF0IjoxNjEwMDk3ODk5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.QAo6pE9pB7Pc7b7-jf0csZf9oDICj2k93H_4Xv2mEbo&download=image.png "")

请勿相信图片中任何联系方式

图片来源于视频 作者拿到视频学习已被第三方打码 没办法 截图也没时间去修改图片 请勿相信图片里的任何联系方式

谢谢

