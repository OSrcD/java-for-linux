## 修改

## source是元数据



![](https://tcs.teambition.net/storage/3121445d09c7befcd7404e461ad847371695?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjg2NiwiaWF0IjoxNjEwMDk4MDY2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0NDVkMDljN2JlZmNkNzQwNGU0NjFhZDg0NzM3MTY5NSJ9.YkzUlX-aRLdqNhhBift92n3z1gb6c30EIskuPuJXris&download=image.png "")

![](https://tcs.teambition.net/storage/31210c3cc41383042b41f97a6b4e0abe20ca?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjg2NiwiaWF0IjoxNjEwMDk4MDY2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwYzNjYzQxMzgzMDQyYjQxZjk3YTZiNGUwYWJlMjBjYSJ9.qBmo84cenwofdDt80b8RJgBKr1tSK3PmKH4zARcFvc4&download=image.png "")

![](https://tcs.teambition.net/storage/312107e80db248273677676d6a09c19fd84c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjg2NiwiaWF0IjoxNjEwMDk4MDY2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwN2U4MGRiMjQ4MjczNjc3Njc2ZDZhMDljMTlmZDg0YyJ9.UBNSBaYIASTu5A1xMZmGX6V7sEl49J0rCoRghHRalAw&download=image.png "")

```java
	@Test
    public void updateStuDoc() {

        // 构建元数据
        Map<String, Object> sourceMap = new HashMap<>();
        sourceMap.put("sign", "I am not super man");
        sourceMap.put("money", 88.6f);
        sourceMap.put("age", "33");

        // 构建请求
        IndexRequest indexRequest = new IndexRequest();
        indexRequest.source(sourceMap);


        UpdateQuery updateQuery = new UpdateQueryBuilder()
                .withClass(Stu.class) // 2. 使用Stu类型
                .withId("1003") // 1.先找到Id
                .withIndexRequest(indexRequest) // 3.请求
                .build(); // 4.构建UpdateQuery

        // update stu set sign='abc',age=33,money=88.6 where docId='1002'
        elasticsearchTemplate.update(updateQuery);
    }

```

![](https://tcs.teambition.net/storage/3121549146f2f86136eafe0639389b4578a1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjg2NiwiaWF0IjoxNjEwMDk4MDY2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1NDkxNDZmMmY4NjEzNmVhZmUwNjM5Mzg5YjQ1NzhhMSJ9.nQctO5ot2uPXco21V53aw46mNMZK6CPfCPrWeYotqHw&download=image.png "")

![](https://tcs.teambition.net/storage/3121e1abf4f04b67a119841cab32718ba424?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjg2NiwiaWF0IjoxNjEwMDk4MDY2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlMWFiZjRmMDRiNjdhMTE5ODQxY2FiMzI3MThiYTQyNCJ9.05DDxILm8TQH_7r8TsKuP_zVvmuKD9Wex66v9sKdt3M&download=image.png "")

开源笔记

此笔记在学习的时候做的笔记 所以 没有那么多时间写的很细致或整理排版问题 采用关键帧图片与关键帧文字进行书写 

可 Pull Requests 协作写开源笔记

[gitee](https://gitee.com/opendevel/java-for-linux)

[github](https://github.com/OSrcD/java-for-linux)

[teambition](https://tburl.in/0jDNvpbK)

开源视频

[OSrcD的个人空间 - 哔哩哔哩 ( ゜- ゜)つロ 乾杯~ Bilibili](https://space.bilibili.com/77266754)

开源博客

[全部博文 - OpenDevel的个人空间 - OSCHINA](https://my.oschina.net/u/4675154?tab=newest&catalogId=0)

开源项目

[OSrcD (OpenDevel) - Gitee.com](https://gitee.com/OpenDevel)

[OSrcD - Overview](https://github.com/OSrcD)

开源赞赏

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjg2NiwiaWF0IjoxNjEwMDk4MDY2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.PP1csY7cEvMR9sewCbadA6Px9NZuAXOEDW0BDsv19RM&download=image.png "")

请勿相信图片中任何联系方式

图片来源于视频 作者拿到视频学习已被第三方打码 没办法 截图也没时间去修改图片 请勿相信图片里的任何联系方式

谢谢

