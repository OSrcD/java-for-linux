



![](https://tcs.teambition.net/storage/312190bb9213af51bf84fd0b7f0a9c36c3fe?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjYxNywiaWF0IjoxNjEwMDk3ODE3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5MGJiOTIxM2FmNTFiZjg0ZmQwYjdmMGE5YzM2YzNmZSJ9.Ndb1wICEWv3s5PADE115DT04pvicrqxFHFmAiB3EE3E&download=2020-09-17%20175524.png "")

![](https://tcs.teambition.net/storage/31213f20939fb3ac9cd62a0e325abe5d77fa?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjYxNywiaWF0IjoxNjEwMDk3ODE3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzZjIwOTM5ZmIzYWM5Y2Q2MmEwZTMyNWFiZTVkNzdmYSJ9.84z_h0iQF0MItb2QJZ8TdBsPWfIq2RNg-bnfu1QVH38&download=image.png "")

![](https://tcs.teambition.net/storage/31212d7c7563798060bd03558f52de104763?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjYxNywiaWF0IjoxNjEwMDk3ODE3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyZDdjNzU2Mzc5ODA2MGJkMDM1NThmNTJkZTEwNDc2MyJ9.OJJ9KbPPqKx95Il4GYQOInoYait_zF3t5UA1OB8h0sg&download=image.png "")

## highlight 高亮显示 

![](https://tcs.teambition.net/storage/312110e1446bcf47b32d3be3fff64cdaa6f2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjYxNywiaWF0IjoxNjEwMDk3ODE3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExMGUxNDQ2YmNmNDdiMzJkM2JlM2ZmZjY0Y2RhYTZmMiJ9.-j0ld46ItJ9dNpw_hLVIDDflcC_x_1jQpeIfK0-inAo&download=image.png "")

```json
{
    "query": {
        "match": {
            "desc": "开源"
        }
    },
    "highlight": {
        "fields": {
            "desc": {}
        }
    }
}

```

```json
{
    "took": 600,
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
                },
                "highlight": {
                    "desc": [
                        "我的<em>开源</em>中国学习java和前端，学习了很多知识"
                    ]
                }
            }
        ]
    }
}

```

![](https://tcs.teambition.net/storage/3121325cd254a51d1e3456396f0459527547?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjYxNywiaWF0IjoxNjEwMDk3ODE3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzMjVjZDI1NGE1MWQxZTM0NTYzOTZmMDQ1OTUyNzU0NyJ9.sBpLzlhn2KJZ-VrvYw6foF88rQ6OGTGjpv_Wxlg9oxs&download=image.png "")

## tag 自定义标签

```json
{
    "query": {
        "match": {
            "desc": "开源"
        }
    },
    "highlight": {
        "pre_tags": ["<span>"],
        "post_tags": ["</span"],
        "fields": {
            "desc": {}
        }
    }
}

```

```json
{
    "took": 20,
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
                },
                "highlight": {
                    "desc": [
                        "我的<span>开源</span中国学习java和前端，学习了很多知识"
                    ]
                }
            }
        ]
    }
}

```

## 附:课外拓展 - prefix - fuzzy- wildcard

![](https://tcs.teambition.net/storage/3121fa2891ad26f2a00c38b8de68c4c0b8cc?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjYxNywiaWF0IjoxNjEwMDk3ODE3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmYTI4OTFhZDI2ZjJhMDBjMzhiOGRlNjhjNGMwYjhjYyJ9.ZTa9OCDU_aS_GqMGi7JUdOBuI0MRESNB-iN7_nl8tvo&download=2020-09-17%20175540.png "")

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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjYxNywiaWF0IjoxNjEwMDk3ODE3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.hn1d86r_YBlskEwYjeJXX5J8NRHzzyiC2UQaaEET_yE&download=image.png "")

请勿相信图片中任何联系方式

图片来源于视频 作者拿到视频学习已被第三方打码 没办法 截图也没时间去修改图片 请勿相信图片里的任何联系方式

谢谢

