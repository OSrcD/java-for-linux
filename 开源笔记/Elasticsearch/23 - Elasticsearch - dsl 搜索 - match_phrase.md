

![](https://tcs.teambition.net/storage/3121d8f707f6b32f4c045b007b371b777c56?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjUxNywiaWF0IjoxNjEwMDk3NzE3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkOGY3MDdmNmIzMmY0YzA0NWIwMDdiMzcxYjc3N2M1NiJ9.4hcILPnJAX5X0SGdJdSw1_91XyyL7l87AUvZYpkl1Lg&download=2020-09-17%20174849.png "")

## match_phrase 根据包含的词汇去查询 内容会分词  词汇要求连贯 匹配的顺序 中间可以跳过一些字符

![](https://tcs.teambition.net/storage/31217ebc40e9846440a45dd8c6b66fb2ff78?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjUxNywiaWF0IjoxNjEwMDk3NzE3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3ZWJjNDBlOTg0NjQ0MGE0NWRkOGM2YjY2ZmIyZmY3OCJ9.lAHkdIYIw12Z-FUcXr2tDBia1OS_tZYObW1zrMbe6BY&download=image.png "")

```json
{
    "took": 82,
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
        "max_score": 3.7334948,
        "hits": [
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1009",
                "_score": 3.7334948,
                "_source": {
                    "nickname": "骚年轮",
                    "id": 1009,
                    "desc": "骚年在大学毕业后，考研究生去了"
                }
            },
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1008",
                "_score": 2.9383912,
                "_source": {
                    "nickname": "开源学习",
                    "id": 1008,
                    "desc": "大学毕业后，可以到gitee.com进修"
                }
            }
        ]
    }
}

```

![](https://tcs.teambition.net/storage/3121b66231eef96ee5b3255d1fdd96e92999?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjUxNywiaWF0IjoxNjEwMDk3NzE3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiNjYyMzFlZWY5NmVlNWIzMjU1ZDFmZGQ5NmU5Mjk5OSJ9.R-JbTaL3xcP8ZXoXHSkBAZBfnK_LBgc3IXEkkLIJ0gQ&download=image.png "")

![](https://tcs.teambition.net/storage/3121e60440a1dd8f07c4b4868badd8e96615?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjUxNywiaWF0IjoxNjEwMDk3NzE3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlNjA0NDBhMWRkOGYwN2M0YjQ4NjhiYWRkOGU5NjYxNSJ9.Eq-XTN9J_QoMNFxckx-X-ZxbZJ026Lk9UE10IXm7iT8&download=image.png "")

## slop 跳过中间词 词与词之间允许跳过的数量

![](https://tcs.teambition.net/storage/3121248b3403f458e1dc6d9696c73eea4541?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjUxNywiaWF0IjoxNjEwMDk3NzE3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyNDhiMzQwM2Y0NThlMWRjNmQ5Njk2YzczZWVhNDU0MSJ9.EvnyGa6BSZa41RVSRfCYEG5ypGDEw7admhdZ-sWTWlc&download=image.png "")

![](https://tcs.teambition.net/storage/312122efd34f450ed56561f87ed041682960?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjUxNywiaWF0IjoxNjEwMDk3NzE3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyMmVmZDM0ZjQ1MGVkNTY1NjFmODdlZDA0MTY4Mjk2MCJ9.oUcu1g4xLNbNR0z0XKbcJvccUkVRnCPJQpowKQfh4mY&download=image.png "")

![](https://tcs.teambition.net/storage/3121230abe54971cbd69828a1c735661eec1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjUxNywiaWF0IjoxNjEwMDk3NzE3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyMzBhYmU1NDk3MWNiZDY5ODI4YTFjNzM1NjYxZWVjMSJ9._mA8-K-5IH1zI_zKwnxGO4GKL6mAutd04kNC3DHw4zc&download=image.png "")









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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjUxNywiaWF0IjoxNjEwMDk3NzE3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.DS72U9RhL8t9Yc8m6eX6w1YGeVsfKXWVVY47etihEu0&download=image.png "")

请勿相信图片中任何联系方式

图片来源于视频 作者拿到视频学习已被第三方打码 没办法 截图也没时间去修改图片 请勿相信图片里的任何联系方式

谢谢

