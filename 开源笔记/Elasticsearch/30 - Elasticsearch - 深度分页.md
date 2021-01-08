

![](https://tcs.teambition.net/storage/3121b6b0043895234de465452e6a6851f8ad?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjY1MCwiaWF0IjoxNjEwMDk3ODUwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiNmIwMDQzODk1MjM0ZGU0NjU0NTJlNmE2ODUxZjhhZCJ9.QOKVRspueQKtYbiiw2n25vxIHJma3r02iBvOHxTfWmU&download=2020-09-17%20175556.png "")

![](https://tcs.teambition.net/storage/3121cead397d5f3d9da1559993cd11e0c638?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjY1MCwiaWF0IjoxNjEwMDk3ODUwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjZWFkMzk3ZDVmM2Q5ZGExNTU5OTkzY2QxMWUwYzYzOCJ9.zFUaf1EetQfSimy-HxJGS8iFIlDCQS0oeFvbtB37_w4&download=image.png "")

```json
{
    "query": {
        "match_all": {}
    },
    "from": 9999,
    "size": 10
}

```

```json
{
    "error": {
        "root_cause": [
            {
                "type": "illegal_argument_exception",
                "reason": "Result window is too large, from + size must be less than or equal to: [10000] but was [10009]. See the scroll api for a more efficient way to request large data sets. This limit can be set by changing the [index.max_result_window] index level setting."
            }
        ],
        "type": "search_phase_execution_exception",
        "reason": "all shards failed",
        "phase": "query",
        "grouped": true,
        "failed_shards": [
            {
                "shard": 0,
                "index": "shop",
                "node": "B73usOVORMS2RnYf5nXxzg",
                "reason": {
                    "type": "illegal_argument_exception",
                    "reason": "Result window is too large, from + size must be less than or equal to: [10000] but was [10009]. See the scroll api for a more efficient way to request large data sets. This limit can be set by changing the [index.max_result_window] index level setting."
                }
            }
        ],
        "caused_by": {
            "type": "illegal_argument_exception",
            "reason": "Result window is too large, from + size must be less than or equal to: [10000] but was [10009]. See the scroll api for a more efficient way to request large data sets. This limit can be set by changing the [index.max_result_window] index level setting.",
            "caused_by": {
                "type": "illegal_argument_exception",
                "reason": "Result window is too large, from + size must be less than or equal to: [10000] but was [10009]. See the scroll api for a more efficient way to request large data sets. This limit can be set by changing the [index.max_result_window] index level setting."
            }
        }
    },
    "status": 400
}

```

## 深度分页

### 3个shard

### 分页9999 - 10009

![](https://tcs.teambition.net/storage/31215f48ada9dd9ba48ad76317024b9bf50a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjY1MCwiaWF0IjoxNjEwMDk3ODUwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1ZjQ4YWRhOWRkOWJhNDhhZDc2MzE3MDI0YjliZjUwYSJ9.5D539gDMyxFv0nhzbte4Y9LWoss-n9VH2hEMFuFRjzI&download=image.png "")

### 3个 shard 里面各个 10w 条数据

### 去分页 每个 shard 是 10w条数据 累加在 一起就是 30w  再去做一个排序 排序之后 匹配 10条 从30w里面 拿到 10 条 数据 最后再返回给用户 

### 而ES不是这样去做的 会拿出 10009条数据  三个shard 都会拿出10009条数据 会做一个汇总 30027条数据 然后 排序 再去做一个分页 随后会拿出 第 10 条数据  剩下的30007条数据 没有任何的作用 性能有影响 深度分页达到一千以上 分页就会有这样的一种情况 其实数据量比较多的话 可能达到几百个 性能就会受到一些影响了 

### 淘宝限制 100页

![](https://tcs.teambition.net/storage/31219227f6ad829e19e75e92d054ec827f78?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjY1MCwiaWF0IjoxNjEwMDk3ODUwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5MjI3ZjZhZDgyOWUxOWU3NWU5MmQwNTRlYzgyN2Y3OCJ9.b9WP4Kh3EN8UQJ6D0uLzV8kiWO1rR6CaZWkR0vnsQ7A&download=image.png "")







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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjY1MCwiaWF0IjoxNjEwMDk3ODUwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.zwduXdt9Slcrj3bqL5Pc9fk6OmIT1p3UGOwaRQpodcg&download=image.png "")

请勿相信图片中任何联系方式

图片来源于视频 作者拿到视频学习已被第三方打码 没办法 截图也没时间去修改图片 请勿相信图片里的任何联系方式

谢谢

