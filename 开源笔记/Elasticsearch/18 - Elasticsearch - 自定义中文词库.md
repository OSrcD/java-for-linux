# 目录

  * [骚年被解析成了骚 我们需要解析为骚年](#骚年被解析成了骚-我们需要解析为骚年)
  * [在同级目录之下创建一个文件 这个文件就是词典 自定义词典](#在同级目录之下创建一个文件-这个文件就是词典-自定义词典)
  * [custom.dic](#customdic)
  * [重启es](#重启es)
  * [骚年 开源中国 已被分词](#骚年-开源中国-已被分词)




![](https://tcs.teambition.net/storage/3121599256c684d380896bdc325832845daa?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDQ0MDMwOCwiaWF0IjoxNjA5ODM1NTA4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1OTkyNTZjNjg0ZDM4MDg5NmJkYzMyNTgzMjg0NWRhYSJ9._Q3cmzjMc1ehqoIFFkyrHlXplBLUKymAntGnndLuuT8&download=2020-09-17+174701.png "")

![](https://tcs.teambition.net/storage/3121463d42af7f84365ec5cdd5f13bdd0eb1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDQ0MDU4MSwiaWF0IjoxNjA5ODM1NzgxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0NjNkNDJhZjdmODQzNjVlYzVjZGQ1ZjEzYmRkMGViMSJ9.xZvDef_Sa_wrZOtUjvMTB8eWCe-HzCpByUrXVQbOJA0&download=image.png "")

## 骚年被解析成了骚 我们需要解析为骚年

```json
{
    "tokens": [
        {
            "token": "骚",
            "start_offset": 0,
            "end_offset": 1,
            "type": "CN_CHAR",
            "position": 0
        },
        {
            "token": "年在",
            "start_offset": 1,
            "end_offset": 3,
            "type": "CN_WORD",
            "position": 1
        },
        {
            "token": "开源",
            "start_offset": 3,
            "end_offset": 5,
            "type": "CN_WORD",
            "position": 2
        },
        {
            "token": "中国学",
            "start_offset": 5,
            "end_offset": 8,
            "type": "CN_WORD",
            "position": 3
        },
        {
            "token": "中国",
            "start_offset": 5,
            "end_offset": 7,
            "type": "CN_WORD",
            "position": 4
        },
        {
            "token": "国学",
            "start_offset": 6,
            "end_offset": 8,
            "type": "CN_WORD",
            "position": 5
        },
        {
            "token": "学习",
            "start_offset": 7,
            "end_offset": 9,
            "type": "CN_WORD",
            "position": 6
        }
    ]
}

```

![](https://tcs.teambition.net/storage/31210a26f2514503ddfa1ba6f29970b70fb3?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDQ0MDcyMCwiaWF0IjoxNjA5ODM1OTIwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwYTI2ZjI1MTQ1MDNkZGZhMWJhNmYyOTk3MGI3MGZiMyJ9.zn6L6YUMrPzgucN89Elvz7lvYuJ5ioKwUyaIFnU6xQE&download=image.png "")

![](https://tcs.teambition.net/storage/3121533cba529d65a39091d78a7c372e79a0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDQ0MDkwNCwiaWF0IjoxNjA5ODM2MTA0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1MzNjYmE1MjlkNjVhMzkwOTFkNzhhN2MzNzJlNzlhMCJ9.ppdmFZU6jFlRSUZcc927M981AidEQbTzv2AWX4itXz8&download=image.png "")

## 在同级目录之下创建一个文件 这个文件就是词典 自定义词典

![](https://tcs.teambition.net/storage/31212459462f7490eb892ba9fcec998dac36?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDQ0MTE4MiwiaWF0IjoxNjA5ODM2MzgyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyNDU5NDYyZjc0OTBlYjg5MmJhOWZjZWM5OThkYWMzNiJ9.eX7eFLL3uXHYETY0eK0tcGvYqYhOnFCg9KyDAThSPKs&download=image.png "")

![](https://tcs.teambition.net/storage/312134c742dedce600629347b3995fd0e584?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDQ0MTIxNCwiaWF0IjoxNjA5ODM2NDE0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzNGM3NDJkZWRjZTYwMDYyOTM0N2IzOTk1ZmQwZTU4NCJ9.XaPNk7Lx0HDhmAeTwvm5ZtBeiKCdAHfKUoxUcn9h2gQ&download=image.png "")

## custom.dic

![](https://tcs.teambition.net/storage/3121422e38418bcbebea8692ea16cce05ddd?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDQ0MTI1NSwiaWF0IjoxNjA5ODM2NDU1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0MjJlMzg0MThiY2JlYmVhODY5MmVhMTZjY2UwNWRkZCJ9.IJAYqaKqzQAzTG3sP736J6fOMxGreJP2kwqsx4suSXA&download=image.png "")

![](https://tcs.teambition.net/storage/312128373107c90909dcef4004138a288a30?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDQ0MTMyNywiaWF0IjoxNjA5ODM2NTI3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyODM3MzEwN2M5MDkwOWRjZWY0MDA0MTM4YTI4OGEzMCJ9.h_dm0bU-iDpczBjPinSwy-Wy0MwEZDO8LrQ7Ge_cQNA&download=image.png "")

## 重启es

![](https://tcs.teambition.net/storage/312182706835026556e690e9376d34d66b9c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDQ0MTQwMSwiaWF0IjoxNjA5ODM2NjAxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4MjcwNjgzNTAyNjU1NmU2OTBlOTM3NmQzNGQ2NmI5YyJ9.YGGlkRCxeaxzUKYvG6SHtEAn_Ig_q6qnANueiNMWSbs&download=image.png "")

![](https://tcs.teambition.net/storage/31214ff81fbed2a26e4d331fc9dd9abc25ba?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDQ0MTUxNywiaWF0IjoxNjA5ODM2NzE3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0ZmY4MWZiZWQyYTI2ZTRkMzMxZmM5ZGQ5YWJjMjViYSJ9.onMXaEdO7OzNX7oYug04T-6ZqSrrps84cGUxQRTp4tw&download=image.png "")

![](https://tcs.teambition.net/storage/3121519ef6dc598376d5525e6be92d9e6402?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDQ0MTUzMSwiaWF0IjoxNjA5ODM2NzMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1MTllZjZkYzU5ODM3NmQ1NTI1ZTZiZTkyZDllNjQwMiJ9.lSGE0-NjhK5t3dU_toogN9uN1pBKCDx8YxxZdzf42qA&download=image.png "")

## 骚年 开源中国 已被分词

![](https://tcs.teambition.net/storage/3121b3054a1dfa5a14721232bab4cc61dd5d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDQ0MTU2MywiaWF0IjoxNjA5ODM2NzYzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiMzA1NGExZGZhNWExNDcyMTIzMmJhYjRjYzYxZGQ1ZCJ9.pCGq_OsexyaYMa4oMH1GdZLLXX9030CwjXZvyWh3yz0&download=image.png "")

![](https://tcs.teambition.net/storage/31215072dcd3dca34bc0641b246b50f743c4?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDQ0MTU3NCwiaWF0IjoxNjA5ODM2Nzc0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1MDcyZGNkM2RjYTM0YmMwNjQxYjI0NmI1MGY3NDNjNCJ9.FziFKSyvGtJ23QuuYbNKEYOnVsPdBvQhkNzuTgpO220&download=image.png "")

```json
{
    "tokens": [
        {
            "token": "骚年",
            "start_offset": 0,
            "end_offset": 2,
            "type": "CN_WORD",
            "position": 0
        },
        {
            "token": "年在",
            "start_offset": 1,
            "end_offset": 3,
            "type": "CN_WORD",
            "position": 1
        },
        {
            "token": "开源中国",
            "start_offset": 3,
            "end_offset": 7,
            "type": "CN_WORD",
            "position": 2
        },
        {
            "token": "开源",
            "start_offset": 3,
            "end_offset": 5,
            "type": "CN_WORD",
            "position": 3
        },
        {
            "token": "中国学",
            "start_offset": 5,
            "end_offset": 8,
            "type": "CN_WORD",
            "position": 4
        },
        {
            "token": "中国",
            "start_offset": 5,
            "end_offset": 7,
            "type": "CN_WORD",
            "position": 5
        },
        {
            "token": "国学",
            "start_offset": 6,
            "end_offset": 8,
            "type": "CN_WORD",
            "position": 6
        },
        {
            "token": "学习",
            "start_offset": 7,
            "end_offset": 9,
            "type": "CN_WORD",
            "position": 7
        }
    ]
}

```

开源笔记

此笔记在学习的时候做的笔记 所以 没有那么多时间写的很细致或整理排版问题 采用关键帧图片与关键帧文字进行书写 

可 Pull Requests 协作写开源笔记

> [__gitee__](https://gitee.com/opendevel/java-for-linux)

> [__github__](https://github.com/OSrcD/java-for-linux)

> [__Teambition__](https://tburl.in/lPhmsyaa)

开源视频

[OSrcD的个人空间 - 哔哩哔哩 ( ゜- ゜)つロ 乾杯~ Bilibili](https://space.bilibili.com/77266754)

开源博客

[全部博文 - OpenDevel的个人空间 - OSCHINA](https://my.oschina.net/u/4675154?tab=newest&catalogId=0)

开源项目

[OSrcD (OpenDevel) - Gitee.com](https://gitee.com/OpenDevel)

[OSrcD - Overview](https://github.com/OSrcD)

开源赞赏

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDQ0MDIxOCwiaWF0IjoxNjA5ODM1NDE4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.TmI4rzQjRXZya264AjKqOT-e-thYdWBwZyErYucYil4&download=image.png "")

请勿相信图片中任何联系方式

图片来源于视频 作者拿到视频学习已被第三方打码 没办法 截图也没时间去修改图片 请勿相信图片里的任何联系方式

谢谢

