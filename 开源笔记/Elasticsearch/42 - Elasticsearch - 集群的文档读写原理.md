![](https://tcs.teambition.net/storage/3121905962878de7eb157c416ac41c420772?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjgxNSwiaWF0IjoxNjEwMDk4MDE1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5MDU5NjI4NzhkZTdlYjE1N2M0MTZhYzQxYzQyMDc3MiJ9.lkl185ZRzpesF3G1gJgO26fVzZYwAWgR-E6btHQEUbs&download=image.png "")

![](https://tcs.teambition.net/storage/31217ddef88fec61293882e0c7368cf713a1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjgxNSwiaWF0IjoxNjEwMDk4MDE1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3ZGRlZjg4ZmVjNjEyOTM4ODJlMGM3MzY4Y2Y3MTNhMSJ9.f0opX9SDBF-bJGIHtvmTdGrP6vij3HVx-6TRN17sRm0&download=image.png "")

## 写包括文档的 add delete 

## 我们客户端会写上每个节点的 ip 和它的端口号

## 3个节点组成就有 3个 

## 客户端就会选择一个节点去负责 对接的工作

## 客户端选择了中间这个节点

![](https://tcs.teambition.net/storage/31211a19a2175ebfc77bc831514a29bcc8a9?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjgxNSwiaWF0IjoxNjEwMDk4MDE1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExYTE5YTIxNzVlYmZjNzdiYzgzMTUxNGEyOWJjYzhhOSJ9.IpIA9rSaeRvkDhU9eXMIqyLuiIHKyetMLB3FMUgapic&download=image.png "")

## 这个服务器就会被认为是ES集群中的 协调节点 

![](https://tcs.teambition.net/storage/3121ed423927a81f0f1272995f20ad9223f2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjgxNSwiaWF0IjoxNjEwMDk4MDE1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlZDQyMzkyN2E4MWYwZjEyNzI5OTVmMjBhZDkyMjNmMiJ9.SPtCnoXoLrthJXEz3tCDUWvNEe5_nyo8RTlqayQn2rs&download=image.png "")

## coordinating node

## 用于去负责接收用户的请求 可以理解为是一个controller

## 写文档操作 协调节点会针对文档去做一个路由 不管你是新增 还是修改 或者说是删除 都会去做一个路由 会去计算 如果是新增 会去做一个算法 这个数据要写到那个主分片里面  hash 算法

![](https://tcs.teambition.net/storage/312111a975345383237295a508397114b02a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjgxNSwiaWF0IjoxNjEwMDk4MDE1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExMWE5NzUzNDUzODMyMzcyOTVhNTA4Mzk3MTE0YjAyYSJ9.LC2Ix_9mdYS4Z8PgD-W4LhwhTKLbSf8knvw8r1obq3c&download=image.png "")

## 会获得对应的主分片 做文档的存储

![](https://tcs.teambition.net/storage/31214f5d8f4f1274cfc2faacb243d2c958cc?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjgxNSwiaWF0IjoxNjEwMDk4MDE1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0ZjVkOGY0ZjEyNzRjZmMyZmFhY2IyNDNkMmM5NThjYyJ9.AEpPRyCi0mRLfCCmrewnZSIPJklldYQ6i_ApNTruS7Q&download=image.png "")

## 存储 1 主分片之上

## 转发 1 之上 再去做一个对应的存储

## 数据同步到 1副本之上

![](https://tcs.teambition.net/storage/31211be25d14d4680eee971d88eb66d21611?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjgxNSwiaWF0IjoxNjEwMDk4MDE1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExYmUyNWQxNGQ0NjgwZWVlOTcxZDg4ZWI2NmQyMTYxMSJ9.4-9y_boClOQVqMyT6pqqeFBvaqlRosxwVol_DIKPtw8&download=image.png "")

## 告知客户端写操作已经是成功了

## 

## 文档读原理

## 根据文档id 查询 读取出来

## 针对 文档ID 路由 Hash算法 计算出这个文档是保存在哪个位置的

![](https://tcs.teambition.net/storage/3121a0c1c03b40784c317f62a0322f6d6d38?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjgxNSwiaWF0IjoxNjEwMDk4MDE1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhMGMxYzAzYjQwNzg0YzMxN2Y2MmEwMzIyZjZkNmQzOCJ9.GeYDA5U7ETC990DDlzWmu8hfepa9fy5B6qOt4ryO5KI&download=image.png "")

## 响应给客户端











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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjgxNSwiaWF0IjoxNjEwMDk4MDE1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.8tBk20c1P8Ld08YE5Qg8XxMlCVxcDtgXt-9dvDjjWuc&download=image.png "")

请勿相信图片中任何联系方式

图片来源于视频 作者拿到视频学习已被第三方打码 没办法 截图也没时间去修改图片 请勿相信图片里的任何联系方式

谢谢

