# 目录

  * [什么是 mapping](#什么是-mapping)
    * [类似数据库的表结构](#类似数据库的表结构)
    * [相当于是一种表设置](#相当于是一种表设置)
    * [text 是字符串](#text-是字符串)
    * [需要被索引就写 true 就会被查询到](#需要被索引就写-true-就会被查询到)
    * [doc 代表文档](#doc-代表文档)
    * [kerword 是 String 类型](#kerword-是-string-类型)
    * [text 是一些文字类型内容要被分词 倒排索引](#text-是一些文字类型内容要被分词-倒排索引)
    * [keyword 是不会被分词 倒排索引的 精确匹配的搜索](#keyword-是不会被分词-倒排索引的-精确匹配的搜索)


![](https://tcs.teambition.net/storage/312135cffc77ed8b20d2f2e875f9de333bcf?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDI5NTE5MCwiaWF0IjoxNjA5NjkwMzkwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzNWNmZmM3N2VkOGIyMGQyZjJlODc1ZjlkZTMzM2JjZiJ9.lpgw-4oiuQuR5arad78iLGLLZUQzfl_dwsYJd2Eywyk&download=image.png "")

![](https://tcs.teambition.net/storage/31215f02f597f1325bd38b2a6bf0853b29b1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDI5NTE5MCwiaWF0IjoxNjA5NjkwMzkwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1ZjAyZjU5N2YxMzI1YmQzOGIyYTZiZjA4NTNiMjliMSJ9.bNi4geOhLsZ3p7S5b9yejqjlj185fCE_xaugt_SSCwQ&download=image.png "")

![](https://tcs.teambition.net/storage/3121418ca014cc26fda3015a904f7746ce16?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDI5NTE5MCwiaWF0IjoxNjA5NjkwMzkwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0MThjYTAxNGNjMjZmZGEzMDE1YTkwNGY3NzQ2Y2UxNiJ9.shAPra5gz6QzdhvL-C0x_Nhe2lOLPu7SGf5GiCrNXjI&download=image.png "")

## 什么是 mapping

### 类似数据库的表结构

![](https://tcs.teambition.net/storage/3121db708ec7564f261237021b6405d81cb3?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDI5NTE5MCwiaWF0IjoxNjA5NjkwMzkwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkYjcwOGVjNzU2NGYyNjEyMzcwMjFiNjQwNWQ4MWNiMyJ9.-IMlt_gUEFKc-HS7xKluSPS1FqHVcOcAuGtSOhzE1ww&download=image.png "")

### 相当于是一种表设置

![](https://tcs.teambition.net/storage/3121d13e26d6439217738448e9dfd2bbb8d3?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDI5NTE5MCwiaWF0IjoxNjA5NjkwMzkwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkMTNlMjZkNjQzOTIxNzczODQ0OGU5ZGZkMmJiYjhkMyJ9.Uf1gS1wS3ZKZPOR40s-1l9rQttky0Of_WJ5XQ07bUc4&download=image.png "")

### text 是字符串

![](https://tcs.teambition.net/storage/312132d57780213c84813084e4aaaa6fc267?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDI5NTE5MCwiaWF0IjoxNjA5NjkwMzkwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzMmQ1Nzc4MDIxM2M4NDgxMzA4NGU0YWFhYTZmYzI2NyJ9.zzLAH1XAfyMj0v9ZnzUxTKEqT8wiGGOfzxS8xouaMKo&download=image.png "")

### 需要被索引就写 true 就会被查询到

![](https://tcs.teambition.net/storage/31214825a709a9726bae74073327877aee26?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDI5NTE5MCwiaWF0IjoxNjA5NjkwMzkwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0ODI1YTcwOWE5NzI2YmFlNzQwNzMzMjc4NzdhZWUyNiJ9.lVAYH_GaB1hxRLuu1gD3tu72YKlC8ab-bmIx9uUPJx0&download=image.png "")

![](https://tcs.teambition.net/storage/3121004c7f1bc084a832eaa091e5793a33c7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDI5NTE5MCwiaWF0IjoxNjA5NjkwMzkwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwMDRjN2YxYmMwODRhODMyZWFhMDkxZTU3OTNhMzNjNyJ9.dKYvEb3TpTVHkBav92zGHO4CtZ2D-fJElH7nGmHUs68&download=image.png "")

![](https://tcs.teambition.net/storage/31216398b7c9deac02910f98de4f9573809d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDI5NTE5MCwiaWF0IjoxNjA5NjkwMzkwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2Mzk4YjdjOWRlYWMwMjkxMGY5OGRlNGY5NTczODA5ZCJ9.8Hb6oY2OddWR9LDP2QZskCAM5e4jvcReEjRvbT2DTZU&download=image.png "")

![](https://tcs.teambition.net/storage/31217293cb84b911b13837d23bd4b28c65d1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDI5NTE5MCwiaWF0IjoxNjA5NjkwMzkwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3MjkzY2I4NGI5MTFiMTM4MzdkMjNiZDRiMjhjNjVkMSJ9.kia1O84M85vOJvQINnNTBUGPNbnggY9R7YMNoCj-ENY&download=image.png "")

![](https://tcs.teambition.net/storage/3121821908eb2a0b135d995c7c194134491c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDI5NTE5MCwiaWF0IjoxNjA5NjkwMzkwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4MjE5MDhlYjJhMGIxMzVkOTk1YzdjMTk0MTM0NDkxYyJ9.oQZTD3cvk2dW4dRU7ij9S4bPw5ydu3_5m2jdNL3PpGg&download=image.png "")

### doc 代表文档

### kerword 是 String 类型



### text 是一些文字类型内容要被分词 倒排索引

### keyword 是不会被分词 倒排索引的 精确匹配的搜索



































开源笔记

可 Pull requests 协作写开源笔记

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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDI5NTE5MCwiaWF0IjoxNjA5NjkwMzkwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.v5u4616lgunKEHA4AO9uLbV_U6czHC4F7lFmo151vHY&download=image.png "")

请勿相信图片中任何联系方式

图片来源于视频 作者拿到视频学习已被第三方打码 没办法 截图也没时间去修改图片 请勿相信图片里的任何联系方式

谢谢

 

