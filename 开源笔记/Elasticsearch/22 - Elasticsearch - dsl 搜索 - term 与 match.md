![](https://tcs.teambition.net/storage/31211afc34f3ebed3a5fd8778ffba2b2bc25?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjUwNSwiaWF0IjoxNjEwMDk3NzA1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExYWZjMzRmM2ViZWQzYTVmZDg3NzhmZmJhMmIyYmMyNSJ9.XFmI1M3zx35s70WL2xWGg2IHh8JnObBq-OitaSlGmdQ&download=2020-09-17%20174843.png "")

## term 精确搜索

![](https://tcs.teambition.net/storage/3121501ac219ceadce7d21a535d4c584c069?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjUwNSwiaWF0IjoxNjEwMDk3NzA1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1MDFhYzIxOWNlYWRjZTdkMjFhNTM1ZDRjNTg0YzA2OSJ9.edsq2p-FZAqWEHsD43xy4uHxpIqUGYFThhdiAOByALA&download=image.png "")

```json
{
    "took": 66,
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
                    "nickname": "开源中国",
                    "id": 1001,
                    "desc": "我的开源中国学习java和前端，学习了很多知识"
                }
            }
        ]
    }
}

```

## match 搜索 会进行分词

![](https://tcs.teambition.net/storage/3121a25d51db3a278faf4a6dcf5dbb264e3d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjUwNSwiaWF0IjoxNjEwMDk3NzA1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhMjVkNTFkYjNhMjc4ZmFmNGE2ZGNmNWRiYjI2NGUzZCJ9.Zr1iYGCZ7VmQ4_4UdSYf0J-ctuCcfCUxem2_2OC46qU&download=image.png "")

```json
{
    "took": 22,
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
        "max_score": 4.9823523,
        "hits": [
            {
                "_index": "shop",
                "_type": "_doc",
                "_id": "1001",
                "_score": 4.9823523,
                "_source": {
                    "nickname": "开源中国",
                    "id": 1001,
                    "desc": "我的开源中国学习java和前端，学习了很多知识"
                }
            }
        ]
    }
}

```

![](https://tcs.teambition.net/storage/31218dd4c6fe063ca1d1e5782b27ddcfda39?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjUwNSwiaWF0IjoxNjEwMDk3NzA1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4ZGQ0YzZmZTA2M2NhMWQxZTU3ODJiMjdkZGNmZGEzOSJ9.GTUr1aaN7BM7x_JQV7jmk6k1uA3AZWuxPKJHodm_wX4&download=image.png "")

![](https://tcs.teambition.net/storage/31211787948306d1f8a2d218cd5c1a80532a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjUwNSwiaWF0IjoxNjEwMDk3NzA1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExNzg3OTQ4MzA2ZDFmOGEyZDIxOGNkNWMxYTgwNTMyYSJ9.WZ6MvvyNpm-53CJ4sgNlnR-NUXITVtGwDfj27UxV5no&download=image.png "")

## terms 多个关键字匹配

![](https://tcs.teambition.net/storage/31217ba078a677df4fb368cb2d5c4681da32?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjUwNSwiaWF0IjoxNjEwMDk3NzA1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3YmEwNzhhNjc3ZGY0ZmIzNjhjYjJkNWM0NjgxZGEzMiJ9.-kH582BmQ_zEf_YERVy9XmUvzWgoaE-0rXoOuk17y6Q&download=image.png "")

```json
{
    "took": 151,
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
                    "desc": "我的开源中国学习java和前端，学习了很多知识"
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
                    "desc": "骚年在大学毕业后，考研究生去了"
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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjUwNSwiaWF0IjoxNjEwMDk3NzA1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.x8CMFGN3CNvIF1kXHTghd0jqQoEjfzDxwUJxJJEuuJY&download=image.png "")

请勿相信图片中任何联系方式

图片来源于视频 作者拿到视频学习已被第三方打码 没办法 截图也没时间去修改图片 请勿相信图片里的任何联系方式

谢谢

