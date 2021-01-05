# 目录

  * [standard 标准分词](#standard-标准分词)
  * [在先有索引库分词](#在先有索引库分词)
  * [大写会转换为小写](#大写会转换为小写)
  * [simple 单引号会被进行拆分 按照非字母进行拆分 大小写 和 我们标准分词是一样的](#simple-单引号会被进行拆分-按照非字母进行拆分-大小写-和-我们标准分词是一样的)
  * [非字母会被去除](#非字母会被去除)
  * [whitespace 根据空格去做拆分](#whitespace-根据空格去做拆分)
  * [stop 去除没有意义的词](#stop-去除没有意义的词)
  * [keyword 把整个文本作为关键字](#keyword-把整个文本作为关键字)




![](https://tcs.teambition.net/storage/31211bd717ac069489e7f7fda98ef601c66a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDQ0Mzk0MCwiaWF0IjoxNjA5ODM5MTQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExYmQ3MTdhYzA2OTQ4OWU3ZjdmZGE5OGVmNjAxYzY2YSJ9.pxfOaHLSTHMIC9iERb5_WlBstvID1Q7TJltsz2dbzaw&download=2020-09-17%20174648.png "")

![](https://tcs.teambition.net/storage/3121dfa79223d0cc3c24815e1399170e28c8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDQ0Mzk0MCwiaWF0IjoxNjA5ODM5MTQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkZmE3OTIyM2QwY2MzYzI0ODE1ZTEzOTkxNzBlMjhjOCJ9.vUwXQinr3LMHPRujOq0KeEKRjxUaID0YzUOnKrvt45E&download=image.png "")

## standard 标准分词

![](https://tcs.teambition.net/storage/3121e8f43272fef7ab82e7288fc068342664?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDQ0Mzk0MCwiaWF0IjoxNjA5ODM5MTQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlOGY0MzI3MmZlZjdhYjgyZTcyODhmYzA2ODM0MjY2NCJ9.norL9-z_a-aO7AlGLTh2QrVshKu-FQX6R5Jwp4NRtWM&download=image.png "")

![](https://tcs.teambition.net/storage/3121f38fcdd46d4b3af0c23ef5f3507b3592?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDQ0Mzk0MCwiaWF0IjoxNjA5ODM5MTQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmMzhmY2RkNDZkNGIzYWYwYzIzZWY1ZjM1MDdiMzU5MiJ9.Iwwz0UlihuSvrfbnzc0sSyNE68EgRTLMhfeCTw_KYoU&download=image.png "")

![](https://tcs.teambition.net/storage/31214c62a9544416f0fb4ac6942c86f7b7ae?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDQ0Mzk0MCwiaWF0IjoxNjA5ODM5MTQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0YzYyYTk1NDQ0MTZmMGZiNGFjNjk0MmM4NmY3YjdhZSJ9.3QynQDiT5MpW-2x5vVW4TPbsKWjpBG3krHm41ZCUdJA&download=image.png "")

```json
{
    "tokens": [
        {
            "token": "我",
            "start_offset": 0,
            "end_offset": 1,
            "type": "<IDEOGRAPHIC>",
            "position": 0
        },
        {
            "token": "在",
            "start_offset": 1,
            "end_offset": 2,
            "type": "<IDEOGRAPHIC>",
            "position": 1
        },
        {
            "token": "开",
            "start_offset": 2,
            "end_offset": 3,
            "type": "<IDEOGRAPHIC>",
            "position": 2
        },
        {
            "token": "源",
            "start_offset": 3,
            "end_offset": 4,
            "type": "<IDEOGRAPHIC>",
            "position": 3
        },
        {
            "token": "中",
            "start_offset": 4,
            "end_offset": 5,
            "type": "<IDEOGRAPHIC>",
            "position": 4
        },
        {
            "token": "国",
            "start_offset": 5,
            "end_offset": 6,
            "type": "<IDEOGRAPHIC>",
            "position": 5
        },
        {
            "token": "学",
            "start_offset": 6,
            "end_offset": 7,
            "type": "<IDEOGRAPHIC>",
            "position": 6
        },
        {
            "token": "习",
            "start_offset": 7,
            "end_offset": 8,
            "type": "<IDEOGRAPHIC>",
            "position": 7
        }
    ]
}

```

## 在先有索引库分词

![](https://tcs.teambition.net/storage/31213bbcf8f7431b92b5fda15e78941d2995?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDQ0Mzk0MCwiaWF0IjoxNjA5ODM5MTQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzYmJjZjhmNzQzMWI5MmI1ZmRhMTVlNzg5NDFkMjk5NSJ9.qlemkUEpyYjHuS-e8vrvejvsTiq3OvCMxv-8U4wawn0&download=image.png "")

![](https://tcs.teambition.net/storage/31211051cc792305ed1086cad04cd9a71d10?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDQ0Mzk0MCwiaWF0IjoxNjA5ODM5MTQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExMDUxY2M3OTIzMDVlZDEwODZjYWQwNGNkOWE3MWQxMCJ9.rUz7vNza0QEGXb7neXbeYkHNPJqV-StdPC4Daj0PMiY&download=image.png "")

![](https://tcs.teambition.net/storage/3121fd77752e6d3bb954321e5307fedf970f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDQ0Mzk0MCwiaWF0IjoxNjA5ODM5MTQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmZDc3NzUyZTZkM2JiOTU0MzIxZTUzMDdmZWRmOTcwZiJ9.LgW6LpHTXP_NOgS1jbK8Mc1QOcP_gbqxW5Lor4OVTQg&download=image.png "")

![](https://tcs.teambition.net/storage/312143ffadbacf885adc55ce0cd327f04d29?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDQ0Mzk0MCwiaWF0IjoxNjA5ODM5MTQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0M2ZmYWRiYWNmODg1YWRjNTVjZTBjZDMyN2YwNGQyOSJ9.fJAzOpUveDG8j9lJe65Pzrsgu1vdEKW-C3YO4vjbPEg&download=image.png "")

```json
{
    "tokens": [
        {
            "token": "study",
            "start_offset": 0,
            "end_offset": 5,
            "type": "<ALPHANUM>",
            "position": 0
        },
        {
            "token": "in",
            "start_offset": 6,
            "end_offset": 8,
            "type": "<ALPHANUM>",
            "position": 1
        },
        {
            "token": "gitee",
            "start_offset": 9,
            "end_offset": 14,
            "type": "<ALPHANUM>",
            "position": 2
        }
    ]
}

```

![](https://tcs.teambition.net/storage/312186a52734fe569da43eda878ceed90459?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDQ0Mzk0MCwiaWF0IjoxNjA5ODM5MTQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4NmE1MjczNGZlNTY5ZGE0M2VkYTg3OGNlZWQ5MDQ1OSJ9.BldGtRD_P4a4isCJK9cSUmFzodNa7cEKviGT6G9CwQQ&download=image.png "")

## 大写会转换为小写

```json

{
    "tokens": [
        {
            "token": "my",
            "start_offset": 0,
            "end_offset": 2,
            "type": "<ALPHANUM>",
            "position": 0
        },
        {
            "token": "name",
            "start_offset": 3,
            "end_offset": 7,
            "type": "<ALPHANUM>",
            "position": 1
        },
        {
            "token": "is",
            "start_offset": 8,
            "end_offset": 10,
            "type": "<ALPHANUM>",
            "position": 2
        },
        {
            "token": "opendevel",
            "start_offset": 11,
            "end_offset": 20,
            "type": "<ALPHANUM>",
            "position": 3
        },
        {
            "token": "i",
            "start_offset": 21,
            "end_offset": 22,
            "type": "<ALPHANUM>",
            "position": 4
        },
        {
            "token": "am",
            "start_offset": 23,
            "end_offset": 25,
            "type": "<ALPHANUM>",
            "position": 5
        },
        {
            "token": "a",
            "start_offset": 26,
            "end_offset": 27,
            "type": "<ALPHANUM>",
            "position": 6
        },
        {
            "token": "super",
            "start_offset": 28,
            "end_offset": 33,
            "type": "<ALPHANUM>",
            "position": 7
        },
        {
            "token": "hero",
            "start_offset": 34,
            "end_offset": 38,
            "type": "<ALPHANUM>",
            "position": 8
        },
        {
            "token": "i",
            "start_offset": 40,
            "end_offset": 41,
            "type": "<ALPHANUM>",
            "position": 9
        },
        {
            "token": "don't",
            "start_offset": 42,
            "end_offset": 47,
            "type": "<ALPHANUM>",
            "position": 10
        },
        {
            "token": "like",
            "start_offset": 48,
            "end_offset": 52,
            "type": "<ALPHANUM>",
            "position": 11
        },
        {
            "token": "the",
            "start_offset": 53,
            "end_offset": 56,
            "type": "<ALPHANUM>",
            "position": 12
        },
        {
            "token": "criminals",
            "start_offset": 57,
            "end_offset": 66,
            "type": "<ALPHANUM>",
            "position": 13
        }
    ]
}

```

![](https://tcs.teambition.net/storage/31218efddf6992c5da5b5c42eaa25985bed3?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDQ0Mzk0MCwiaWF0IjoxNjA5ODM5MTQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4ZWZkZGY2OTkyYzVkYTViNWM0MmVhYTI1OTg1YmVkMyJ9.mlvYi2nPjpwVbpuz1co4BEjIqxYzNGxT4P4y_y1jqpY&download=image.png "")

## simple 单引号会被进行拆分 按照非字母进行拆分 大小写 和 我们标准分词是一样的

```json
{
    "tokens": [
        {
            "token": "my",
            "start_offset": 0,
            "end_offset": 2,
            "type": "word",
            "position": 0
        },
        {
            "token": "name",
            "start_offset": 3,
            "end_offset": 7,
            "type": "word",
            "position": 1
        },
        {
            "token": "is",
            "start_offset": 8,
            "end_offset": 10,
            "type": "word",
            "position": 2
        },
        {
            "token": "opendevel",
            "start_offset": 11,
            "end_offset": 20,
            "type": "word",
            "position": 3
        },
        {
            "token": "i",
            "start_offset": 21,
            "end_offset": 22,
            "type": "word",
            "position": 4
        },
        {
            "token": "am",
            "start_offset": 23,
            "end_offset": 25,
            "type": "word",
            "position": 5
        },
        {
            "token": "a",
            "start_offset": 26,
            "end_offset": 27,
            "type": "word",
            "position": 6
        },
        {
            "token": "super",
            "start_offset": 28,
            "end_offset": 33,
            "type": "word",
            "position": 7
        },
        {
            "token": "hero",
            "start_offset": 34,
            "end_offset": 38,
            "type": "word",
            "position": 8
        },
        {
            "token": "i",
            "start_offset": 40,
            "end_offset": 41,
            "type": "word",
            "position": 9
        },
        {
            "token": "don",
            "start_offset": 42,
            "end_offset": 45,
            "type": "word",
            "position": 10
        },
        {
            "token": "t",
            "start_offset": 46,
            "end_offset": 47,
            "type": "word",
            "position": 11
        },
        {
            "token": "like",
            "start_offset": 48,
            "end_offset": 52,
            "type": "word",
            "position": 12
        },
        {
            "token": "the",
            "start_offset": 53,
            "end_offset": 56,
            "type": "word",
            "position": 13
        },
        {
            "token": "criminals",
            "start_offset": 57,
            "end_offset": 66,
            "type": "word",
            "position": 14
        }
    ]
}

```

## 非字母会被去除

![](https://tcs.teambition.net/storage/3121028374f9da21c9811a0152e7c0569218?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDQ0Mzk0MCwiaWF0IjoxNjA5ODM5MTQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwMjgzNzRmOWRhMjFjOTgxMWEwMTUyZTdjMDU2OTIxOCJ9.TXVqg78IJuq_oVhZZTLXGeh9ss7r-MBozmjJreLGEyw&download=image.png "")

```json
{
    "tokens": [
        {
            "token": "my",
            "start_offset": 0,
            "end_offset": 2,
            "type": "word",
            "position": 0
        },
        {
            "token": "name",
            "start_offset": 3,
            "end_offset": 7,
            "type": "word",
            "position": 1
        },
        {
            "token": "is",
            "start_offset": 8,
            "end_offset": 10,
            "type": "word",
            "position": 2
        },
        {
            "token": "opendevel",
            "start_offset": 11,
            "end_offset": 20,
            "type": "word",
            "position": 3
        },
        {
            "token": "i",
            "start_offset": 21,
            "end_offset": 22,
            "type": "word",
            "position": 4
        },
        {
            "token": "am",
            "start_offset": 23,
            "end_offset": 25,
            "type": "word",
            "position": 5
        },
        {
            "token": "a",
            "start_offset": 26,
            "end_offset": 27,
            "type": "word",
            "position": 6
        },
        {
            "token": "super",
            "start_offset": 28,
            "end_offset": 33,
            "type": "word",
            "position": 7
        },
        {
            "token": "hero",
            "start_offset": 34,
            "end_offset": 38,
            "type": "word",
            "position": 8
        },
        {
            "token": "i",
            "start_offset": 40,
            "end_offset": 41,
            "type": "word",
            "position": 9
        },
        {
            "token": "don",
            "start_offset": 42,
            "end_offset": 45,
            "type": "word",
            "position": 10
        },
        {
            "token": "t",
            "start_offset": 46,
            "end_offset": 47,
            "type": "word",
            "position": 11
        },
        {
            "token": "like",
            "start_offset": 48,
            "end_offset": 52,
            "type": "word",
            "position": 12
        },
        {
            "token": "the",
            "start_offset": 53,
            "end_offset": 56,
            "type": "word",
            "position": 13
        },
        {
            "token": "criminals",
            "start_offset": 57,
            "end_offset": 66,
            "type": "word",
            "position": 14
        }
    ]
}

```

## whitespace 根据空格去做拆分

![](https://tcs.teambition.net/storage/3121bbcac6a77d7cab8a0bf34b04b3ffb5f6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDQ0Mzk0MCwiaWF0IjoxNjA5ODM5MTQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiYmNhYzZhNzdkN2NhYjhhMGJmMzRiMDRiM2ZmYjVmNiJ9.tGQi1EQxhTZKc6Wk5zgmAE8Q-FpYKpHnyKfhyRRMDgg&download=image.png "")

```json
{
    "tokens": [
        {
            "token": "My",
            "start_offset": 0,
            "end_offset": 2,
            "type": "word",
            "position": 0
        },
        {
            "token": "name",
            "start_offset": 3,
            "end_offset": 7,
            "type": "word",
            "position": 1
        },
        {
            "token": "is",
            "start_offset": 8,
            "end_offset": 10,
            "type": "word",
            "position": 2
        },
        {
            "token": "OpenDevel,I",
            "start_offset": 11,
            "end_offset": 22,
            "type": "word",
            "position": 3
        },
        {
            "token": "am",
            "start_offset": 23,
            "end_offset": 25,
            "type": "word",
            "position": 4
        },
        {
            "token": "a",
            "start_offset": 26,
            "end_offset": 27,
            "type": "word",
            "position": 5
        },
        {
            "token": "Super",
            "start_offset": 28,
            "end_offset": 33,
            "type": "word",
            "position": 6
        },
        {
            "token": "Hero.",
            "start_offset": 34,
            "end_offset": 39,
            "type": "word",
            "position": 7
        },
        {
            "token": "I",
            "start_offset": 40,
            "end_offset": 41,
            "type": "word",
            "position": 8
        },
        {
            "token": "don't",
            "start_offset": 42,
            "end_offset": 47,
            "type": "word",
            "position": 9
        },
        {
            "token": "like",
            "start_offset": 48,
            "end_offset": 52,
            "type": "word",
            "position": 10
        },
        {
            "token": "the",
            "start_offset": 53,
            "end_offset": 56,
            "type": "word",
            "position": 11
        },
        {
            "token": "Criminals.",
            "start_offset": 57,
            "end_offset": 67,
            "type": "word",
            "position": 12
        }
    ]
}

```

## stop 去除没有意义的词

![](https://tcs.teambition.net/storage/3121f5cba7b6a895032dc9c7ba198d527f02?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDQ0Mzk0MCwiaWF0IjoxNjA5ODM5MTQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmNWNiYTdiNmE4OTUwMzJkYzljN2JhMTk4ZDUyN2YwMiJ9.XqJqeNNhHvbmb6-C1RdNUyUls7orKf-yrNp6bJRDbnY&download=image.png "")

```json
{
    "tokens": [
        {
            "token": "my",
            "start_offset": 0,
            "end_offset": 2,
            "type": "word",
            "position": 0
        },
        {
            "token": "name",
            "start_offset": 3,
            "end_offset": 7,
            "type": "word",
            "position": 1
        },
        {
            "token": "opendevel",
            "start_offset": 11,
            "end_offset": 20,
            "type": "word",
            "position": 3
        },
        {
            "token": "i",
            "start_offset": 21,
            "end_offset": 22,
            "type": "word",
            "position": 4
        },
        {
            "token": "am",
            "start_offset": 23,
            "end_offset": 25,
            "type": "word",
            "position": 5
        },
        {
            "token": "super",
            "start_offset": 28,
            "end_offset": 33,
            "type": "word",
            "position": 7
        },
        {
            "token": "hero",
            "start_offset": 34,
            "end_offset": 38,
            "type": "word",
            "position": 8
        },
        {
            "token": "i",
            "start_offset": 40,
            "end_offset": 41,
            "type": "word",
            "position": 9
        },
        {
            "token": "don",
            "start_offset": 42,
            "end_offset": 45,
            "type": "word",
            "position": 10
        },
        {
            "token": "t",
            "start_offset": 46,
            "end_offset": 47,
            "type": "word",
            "position": 11
        },
        {
            "token": "like",
            "start_offset": 48,
            "end_offset": 52,
            "type": "word",
            "position": 12
        },
        {
            "token": "criminals",
            "start_offset": 57,
            "end_offset": 66,
            "type": "word",
            "position": 14
        }
    ]
}

```

## keyword 把整个文本作为关键字

![](https://tcs.teambition.net/storage/3121d95f9bac44975d903cba1714d967092c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDQ0Mzk0MCwiaWF0IjoxNjA5ODM5MTQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkOTVmOWJhYzQ0OTc1ZDkwM2NiYTE3MTRkOTY3MDkyYyJ9.iUwah8dGJ1StNBLY8M_zbGTrN4sBWKwo9j5ZhBvYJ8M&download=image.png "")

开源笔记

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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDQ0Mzk0MCwiaWF0IjoxNjA5ODM5MTQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.AMpXiepmDsUyTH96W8XXXKJ3f_hsgOl6uA789gkCVGA&download=image.png "")

请勿相信图片中任何联系方式

图片来源于视频 作者拿到视频学习已被第三方打码 没办法 截图也没时间去修改图片 请勿相信图片里的任何联系方式

谢谢

