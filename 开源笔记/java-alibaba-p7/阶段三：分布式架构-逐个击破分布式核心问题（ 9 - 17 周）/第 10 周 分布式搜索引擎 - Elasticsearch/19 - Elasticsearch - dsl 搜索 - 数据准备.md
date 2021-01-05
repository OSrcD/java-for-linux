# 目录

  * [新建索引](#新建索引)
  * [type 为 text 增加文档数据的时候 会把nickname里面的内容去做一个分词 做一个倒排索引](#type-为-text-增加文档数据的时候-会把nickname里面的内容去做一个分词-做一个倒排索引)
  * [创建成功](#创建成功)
  * [创建数据](#创建数据)




![](https://tcs.teambition.net/storage/312168804b330655c4d5e4cb48fafeea1410?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDQ0ODA2OCwiaWF0IjoxNjA5ODQzMjY4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2ODgwNGIzMzA2NTVjNGQ1ZTRjYjQ4ZmFmZWVhMTQxMCJ9._ldq7TPooV1ZsSqEzaz8CdZ3ouS4rKrlhOn4B0MVvj0&download=2020-09-17%20174724.png "")

![](https://tcs.teambition.net/storage/3121515d6e8c1e259b8eb420105acd971710?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDQ0ODA2OCwiaWF0IjoxNjA5ODQzMjY4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1MTVkNmU4YzFlMjU5YjhlYjQyMDEwNWFjZDk3MTcxMCJ9.UMFjB-wkwM5GgZNBnrMlBQ9qCjJ1UWlur7fu50Pe5Yc&download=image.png "")

![](https://tcs.teambition.net/storage/3121ba928c1a3631bf602529e93c42c41179?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDQ0ODA2OCwiaWF0IjoxNjA5ODQzMjY4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiYTkyOGMxYTM2MzFiZjYwMjUyOWU5M2M0MmM0MTE3OSJ9.xqtB5gyPf58XWs47GD802L1ux3CInO_ccHwPRmXT7N8&download=image.png "")

## 新建索引

![](https://tcs.teambition.net/storage/3121965ba6a34fa56cd9f25a801a7ea0a39e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDQ0ODA2OCwiaWF0IjoxNjA5ODQzMjY4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5NjViYTZhMzRmYTU2Y2Q5ZjI1YTgwMWE3ZWEwYTM5ZSJ9.BQSnzEH9XIJv3VvtGFpKAGdCi4R0lHukYpW2kDIMAgY&download=image.png "")

![](https://tcs.teambition.net/storage/312102a5523f0bbc5b332c7375de7d61f2a0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDQ0ODA2OCwiaWF0IjoxNjA5ODQzMjY4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwMmE1NTIzZjBiYmM1YjMzMmM3Mzc1ZGU3ZDYxZjJhMCJ9.MPvzcqM5daIW9WoqlOw-WKpJlGF3EiOmY78KSE-ToGk&download=image.png "")

![](https://tcs.teambition.net/storage/312116c0789da2eb4c12efec67b81a5eced1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDQ0ODA2OCwiaWF0IjoxNjA5ODQzMjY4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExNmMwNzg5ZGEyZWI0YzEyZWZlYzY3YjgxYTVlY2VkMSJ9.LNllDh4oPytjVOS7Pfi7ur5kz2iicIgLvm4DYm4sNzk&download=image.png "")

![](https://tcs.teambition.net/storage/3121baf66897dd5af1094e86967e7359d805?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDQ0ODA2OCwiaWF0IjoxNjA5ODQzMjY4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiYWY2Njg5N2RkNWFmMTA5NGU4Njk2N2U3MzU5ZDgwNSJ9.Uc4rr67WgAHSjBxIvJyLbzc4TM1h1U98FESTskTrtls&download=image.png "")

![](https://tcs.teambition.net/storage/31219c0701e3d9f7371fb6a4b260b2bb402a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDQ0ODA2OCwiaWF0IjoxNjA5ODQzMjY4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5YzA3MDFlM2Q5ZjczNzFmYjZhNGIyNjBiMmJiNDAyYSJ9.8zWluaChztTT720R_5W6w0CB-1fWBxW0RUvx8_dGNeE&download=image.png "")



## type 为 text 增加文档数据的时候 会把nickname里面的内容去做一个分词 做一个倒排索引 

![](https://tcs.teambition.net/storage/31214f36768ab2d0c1580e04d529300491d0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDQ0ODA2OCwiaWF0IjoxNjA5ODQzMjY4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0ZjM2NzY4YWIyZDBjMTU4MGUwNGQ1MjkzMDA0OTFkMCJ9.ejPqOTXQ_PB-7HS2rIYcGVHXBLH_3nNSZfwT33yMmGk&download=image.png "")

![](https://tcs.teambition.net/storage/3121ab46bf9bdc03d5938828e2600aee357a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDQ0ODA2OCwiaWF0IjoxNjA5ODQzMjY4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhYjQ2YmY5YmRjMDNkNTkzODgyOGUyNjAwYWVlMzU3YSJ9.ZnWrkq1AMyhRH2a9KQOBIvhAjSp0OSn4jGPL9C0MFRo&download=image.png "")

```json
{
    "properties": {
        "id": {
            "type": "long"
        },
        "age": {
            "type": "integer"
        },
        "username": {
            "type": "keyword"
        },
        "nickname":{
            "type": "text",
            "analyzer": "ik_max_word"
        },
        "money": {
            "type": "float"
        },
        "desc": {
            "type": "text",
            "analyzer": "ik_max_word"
        },
        "sex": {
            "type": "byte"
        },
        "face": {
            "type": "text",
            "index": false
        }
    }
}

```

## 创建成功

![](https://tcs.teambition.net/storage/31214f6a9515845eaea430535deb7a349084?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDQ0ODA2OCwiaWF0IjoxNjA5ODQzMjY4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0ZjZhOTUxNTg0NWVhZWE0MzA1MzVkZWI3YTM0OTA4NCJ9.J-Z4fEpNS2s9T6uZ_rSGSQrIGPg1bb5-_Xhu3UvlE14&download=image.png "")

## 创建数据

![](https://tcs.teambition.net/storage/312104af6d2e8aebb7f4e567e3c255d1551c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDQ0OTM5NCwiaWF0IjoxNjA5ODQ0NTk0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwNGFmNmQyZThhZWJiN2Y0ZTU2N2UzYzI1NWQxNTUxYyJ9.wnpTOTpLqehNarlJ2Xq6QHMw_shlPsWzgDvknlqWqls&download=image.png "")

![](https://tcs.teambition.net/storage/3121564d0f50fe9fb1d453af1f7c65b11ac6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDQ0OTU4NywiaWF0IjoxNjA5ODQ0Nzg3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1NjRkMGY1MGZlOWZiMWQ0NTNhZjFmN2M2NWIxMWFjNiJ9.D0bH_bc18x_1CziC-FO0w-PJlQOHhgPyO9_UbOGeSp4&download=image.png "")

![](https://tcs.teambition.net/storage/312176047f1293cd1982cfa72f9dba2688fe?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDQ0OTcwNCwiaWF0IjoxNjA5ODQ0OTA0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3NjA0N2YxMjkzY2QxOTgyY2ZhNzJmOWRiYTI2ODhmZSJ9.gd8jbV_nA9tFnf95sH4X07gC2Yt3zzT_rWK3A05vQ-o&download=image.png "")

![](https://tcs.teambition.net/storage/31215a52dbe6bc05579bfac21e0fee085d56?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDQ0OTg0MCwiaWF0IjoxNjA5ODQ1MDQwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1YTUyZGJlNmJjMDU1NzliZmFjMjFlMGZlZTA4NWQ1NiJ9.VLsrwsa9I1W_gQ9np5Wu9vt2T91ei9RLsbe7AZyCDuA&download=image.png "")

![](https://tcs.teambition.net/storage/31219dd88f53d3d95e1146d01d5d27bf48a0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDQ0OTk3MCwiaWF0IjoxNjA5ODQ1MTcwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5ZGQ4OGY1M2QzZDk1ZTExNDZkMDFkNWQyN2JmNDhhMCJ9.1oFAhqWsAM197BCrMeaibWW5mApnlx24sIceu0PLNIY&download=image.png "")

![](https://tcs.teambition.net/storage/312118a41b86f5d4f87238b9b9f6ad294f94?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDQ1MDIxMiwiaWF0IjoxNjA5ODQ1NDEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExOGE0MWI4NmY1ZDRmODcyMzhiOWI5ZjZhZDI5NGY5NCJ9.v_kMTJp_5EHXQ6j14B5YC01-W6o5bUqVoy1mIEWVcbI&download=image.png "")

![](https://tcs.teambition.net/storage/31217e6d412aa263c2aea646066b09724581?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDQ1MDM0MSwiaWF0IjoxNjA5ODQ1NTQxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3ZTZkNDEyYWEyNjNjMmFlYTY0NjA2NmIwOTcyNDU4MSJ9.QJD6ab2w_bFbKQgVvnPUWAHPlC5wLNVMZVmAqfgOTGI&download=image.png "")

![](https://tcs.teambition.net/storage/31215b3e345fb11b092b150962e74430b335?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDQ1MDQ3MiwiaWF0IjoxNjA5ODQ1NjcyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1YjNlMzQ1ZmIxMWIwOTJiMTUwOTYyZTc0NDMwYjMzNSJ9.f66n3M2BSknLq4jPmQaWS3ZwE0GNAYuepPqv1kkYFcY&download=image.png "")

![](https://tcs.teambition.net/storage/31211c99db5cf47ba53d8a1624f732fb9f86?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDQ1MDU3OCwiaWF0IjoxNjA5ODQ1Nzc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExYzk5ZGI1Y2Y0N2JhNTNkOGExNjI0ZjczMmZiOWY4NiJ9.E2AheHaBI5u899BjvErgCwxpHOAD8VQhcL6tYrKkclA&download=image.png "")

![](https://tcs.teambition.net/storage/31219b46ed7cf2463b8d65d90938ed6c3474?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDQ1MDY2OSwiaWF0IjoxNjA5ODQ1ODY5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5YjQ2ZWQ3Y2YyNDYzYjhkNjVkOTA5MzhlZDZjMzQ3NCJ9.iM6HrLcaW5rPGz4q3DkGv4cNTosov9qNyKKSKheG6HE&download=image.png "")

![](https://tcs.teambition.net/storage/3121fb878c6bc29f416950718c2a22a63aca?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDQ1MDc5MSwiaWF0IjoxNjA5ODQ1OTkxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmYjg3OGM2YmMyOWY0MTY5NTA3MThjMmEyMmE2M2FjYSJ9.THHOZRcZFaYQvha3RC3eYCBmsR4fk6_iitIRPDo8rDE&download=image.png "")

![](https://tcs.teambition.net/storage/31214a0a412da8272c32fb39c9804d863547?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDQ1MDk3MCwiaWF0IjoxNjA5ODQ2MTcwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0YTBhNDEyZGE4MjcyYzMyZmIzOWM5ODA0ZDg2MzU0NyJ9.fW6HCSlH81eTtB5VkmWsKaN_joOOgIxtqY_NwuDK7Lg&download=image.png "")

![](https://tcs.teambition.net/storage/312172407ffb10b420d8d66ca684908a8c47?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDQ1MTA4NCwiaWF0IjoxNjA5ODQ2Mjg0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3MjQwN2ZmYjEwYjQyMGQ4ZDY2Y2E2ODQ5MDhhOGM0NyJ9.7UXnP6a4pI5tf0V8SC4gJ_3rxDp7Q2O7RvR3ihM2mbg&download=image.png "")

![](https://tcs.teambition.net/storage/3121d09b9e87ad4d6fdc7c9c4aadc3d0133e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDQ1MTEwNywiaWF0IjoxNjA5ODQ2MzA3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkMDliOWU4N2FkNGQ2ZmRjN2M5YzRhYWRjM2QwMTMzZSJ9.t_qIBoGcc3w11Viy-8iTj6DpP-4_4soyiXccCvh43zA&download=image.png "")

![](https://tcs.teambition.net/storage/3121f35d73fcb58561bee22cf1b221a8672a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMDQ1MTEzNSwiaWF0IjoxNjA5ODQ2MzM1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmMzVkNzNmY2I1ODU2MWJlZTIyY2YxYjIyMWE4NjcyYSJ9.WmbXVXfnX21ybpNTNN6gFPkC1DAHo4t3fOVba-MSf18&download=image.png "")

```json
# 模板

{
    "id": ,
    "age": ,
    "username": "",
    "nickname": "",
    "money": ,
    "desc": "",
    "sex": ,
    "birthday": "",
    "face": "https://gitee.com/static/images/logo-black.svg?t=158106664"
}

{
    "id": 1001,
    "age": 18,
    "username": "giteeAmazing",
    "nickname": "开源中国",
    "money": 88.8,
    "desc": "我的开源中国学习java和前端，学习了很多知识",
    "sex": 0,
    "birthday": "1992-12-24",
    "face": "https://gitee.com/static/images/logo-black.svg?t=158106664"
}

{
    "id": 1002,
    "age": 19,
    "username": "justbuy",
    "nickname": "周杰棍",
    "money": 77.8,
    "desc": "今天上下班都很堵，车流量很大",
    "sex": 1,
    "birthday": "1993-01-24",
    "face": "https://gitee.com/static/images/logo-black.svg?t=158106664"
}

{
    "id": 1003,
    "age": 20,
    "username": "bigFace",
    "nickname": "飞翔的巨鹰",
    "money": 66.8,
    "desc": "慕课网团队和导游坐飞机去海外旅游,去了新马泰和欧洲",
    "sex": 1,
    "birthday": "1996-01-14",
    "face": "https://gitee.com/static/images/logo-black.svg?t=158106664"
}

{
    "id": 1004,
    "age": 22,
    "username": "flyfish",
    "nickname": "水中鱼",
    "money": 55.8,
    "desc": "昨天在学校的池塘里，看到有很多鱼在游泳，然后就去慕课网上课了",
    "sex": 0,
    "birthday": "1988-02-14",
    "face": "https://gitee.com/static/images/logo-black.svg?t=158106664"
}

{
    "id": 1005,
    "age": 25,
    "username": "gotoplay",
    "nickname": "ps游戏机",
    "money": 155.8,
    "desc": "今年生日，女友送了我一台play station游戏机，非常好玩，非常不错",
    "sex": 1,
    "birthday": "1989-03-14",
    "face": "https://gitee.com/static/images/logo-black.svg?t=158106664"
}

{
    "id": 1006,
    "age": 19,
    "username": "missgitee",
    "nickname": "我叫小源",
    "money": 156.8,
    "desc": "我叫凌云彻，今年20岁，是一名律师，我在琦星球做演讲",
    "sex": 1,
    "birthday": "1993-04-14",
    "face": "https://gitee.com/static/images/logo-black.svg?t=158106664"
}

{
    "id": 1007,
    "age": 19,
    "username": "msgame",
    "nickname": "gamexbox",
    "money": 1056.8,
    "desc": "明天去进货，最近微软处理很多游戏机，还要买xbox游戏卡带",
    "sex": 1,
    "birthday": "1985-05-14",
    "face": "https://gitee.com/static/images/logo-black.svg?t=158106664"
}

{
    "id": 1008,
    "age": 19,
    "username": "kaiyuan",
    "nickname": "开源学习",
    "money": 1056.8,
    "desc": "大学毕业后，可以到gitee.com进修",
    "sex": 1,
    "birthday": "1995-06-14",
    "face": "https://gitee.com/static/images/logo-black.svg?t=158106664"
}

{
    "id": 1009,
    "age": 22,
    "username": "shaonian",
    "nickname": "骚年轮",
    "money": 96.8,
    "desc": "骚年在大学毕业后，考研究生去了",
    "sex": 1,
    "birthday": "1998-07-14",
    "face": "https://gitee.com/static/images/logo-black.svg?t=158106664"
}

{
    "id": 1010,
    "age": 30,
    "username": "tata",
    "nickname": "隔壁老王",
    "money": 100.8,
    "desc": "隔壁老外去国外出差，带给我很多好吃的",
    "sex": 1,
    "birthday": "1988-07-14",
    "face": "https://gitee.com/static/images/logo-black.svg?t=158106664"
}

{
    "id": 1011,
    "age": 31,
    "username": "sparder",
    "nickname": "皮特帕克",
    "money": 180.8,
    "desc": "它是一个超级英雄",
    "sex": 1,
    "birthday": "1989-08-14",
    "face": "https://gitee.com/static/images/logo-black.svg?t=158106664"
}

{
    "id": 1012,
    "age": 31,
    "username": "super hero",
    "nickname": "super hero",
    "money": 188.8,
    "desc": "BatMan，GreenArrow，SpiderMan，IronMan... are all Super Hero",
    "sex": 1,
    "birthday": "1980-08-14",
    "face": "https://gitee.com/static/images/logo-black.svg?t=158106664"
}

```

开源笔记

此笔记在学习的时候做的笔记 所以 没有那么多时间写的很细致或整理排版问题 采用关键帧图片与关键帧文字进行书写 

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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDQ0ODA2OCwiaWF0IjoxNjA5ODQzMjY4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.uJEPS7iZ1wG9olOAxT_3fpauONXmPXiFdpFXrvShkqc&download=image.png "")

请勿相信图片中任何联系方式

图片来源于视频 作者拿到视频学习已被第三方打码 没办法 截图也没时间去修改图片 请勿相信图片里的任何联系方式

谢谢

