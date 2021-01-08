

![](https://tcs.teambition.net/storage/3121efa38693c8b0b70eee3adc4271e421ea?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjgwNCwiaWF0IjoxNjEwMDk4MDA0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlZmEzODY5M2M4YjBiNzBlZWUzYWRjNDI3MWU0MjFlYSJ9.QL1Gkq938SH0pIwcBWigVW8YENmxzdW7ASTCHL0h7EU&download=2020-09-17%20175651.png "")

## 服务器1：master

## 服务器2：slave

## 服务器3：slave

## 

## 服务器1：宕机 被踢出

## 服务器2：有可能变为新的master 主节点 服务器3也有可能的 服务器2现在是master

## 

## 服务器2 和 服务器3 成为新的集群

## 

## 服务器1 恢复了 有可能不会成为 slave 不会加入到我们原先的集群的 自己作为一个新的集群 单个节点 

## 

## 原因 有最小投票 人数选举 最小的支持人数 默认数值是 1 就是说 当我们的服务器 如果有一个节点要想成为master 只需要有最小的票数 = 1 那么这台服务器就可以成为Master 主节点

## 

## 服务器1 恢复可以给自己投票 

## 

## 划分为两片 也就是有两个集群了 服务器1 master 是一个不完整的集群 数据也是不完整的



## 修改投票人数



![](https://tcs.teambition.net/storage/31219e2d3b60b114671f699391aef5d9779d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjgwNCwiaWF0IjoxNjEwMDk4MDA0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5ZTJkM2I2MGIxMTQ2NzFmNjk5MzkxYWVmNWQ5Nzc5ZCJ9.vlPRuEsUUrkI662P-tO4cSUrHWiaRzCiOVNt28WEwv4&download=image.png "")

## 默认就是1 

## discovery.zen.minimum_master_nodes

## ( 3 /  1 ) + 1 = 2



![](https://tcs.teambition.net/storage/31217b9b68eff6a28d23597acf64761b7840?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjgwNCwiaWF0IjoxNjEwMDk4MDA0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3YjliNjhlZmY2YTI4ZDIzNTk3YWNmNjQ3NjFiNzg0MCJ9.K2Z5mlnlmNz7YKYBcjQpjO2bhIioslFsSFc9DUM6SZA&download=image.png "")

## node.master = true 



 

  















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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDcwMjgwNCwiaWF0IjoxNjEwMDk4MDA0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.MjPEvT-gsBQz6GBiJb-GxABXreVexZi-g8fhEeHQhMk&download=image.png "")

请勿相信图片中任何联系方式

图片来源于视频 作者拿到视频学习已被第三方打码 没办法 截图也没时间去修改图片 请勿相信图片里的任何联系方式

谢谢

