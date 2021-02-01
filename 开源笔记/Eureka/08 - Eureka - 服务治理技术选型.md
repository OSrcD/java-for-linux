

![](https://tcs.teambition.net/storage/3121ee23186630ef8f26562a9b1d20060e12?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjE3NiwiaWF0IjoxNjEyMTkxMzc2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlZTIzMTg2NjMwZWY4ZjI2NTYyYTliMWQyMDA2MGUxMiJ9.SFpWhbaLGV9f9-fctawBvvV4zi3_Rjc2MObaO6bA9a8&download=2020-09-17%20051328.jpg "")





![](https://tcs.teambition.net/storage/3121ba16bc114b3b461d5d6c3ee902bd66c2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjE3NiwiaWF0IjoxNjEyMTkxMzc2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiYTE2YmMxMTRiM2I0NjFkNWQ2YzNlZTkwMmJkNjZjMiJ9.GTySNLrRaEYvC3_yCoKX2CUREr6zX9guiQssgNKkUqI&download=2020-09-17%20051415.jpg "")

![](https://tcs.teambition.net/storage/3121cd7e76fa86649f5006073bed750f9db3?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjE3NiwiaWF0IjoxNjEyMTkxMzc2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjZDdlNzZmYTg2NjQ5ZjUwMDYwNzNiZWQ3NTBmOWRiMyJ9.fdX8jsMXl3SZQKrqbK6AtZrK2Y4fyNHYqCXqLq9KSjc&download=image.png "")

## C 一致性

在分布式系统中 所有的数据副本

副本是指在分布式环境中 分布的所有节点 比如说 我的数据库有主从备份 redis也是一个集群 在这个集群当中 每一个节点 可能都保存着一份数据的副本

在同一时刻 同一个值 在每一个副本 中 数值都是完全一样的

指的是数据一致性



## 强一致性（我们这里的C是强一致性）

我们对系统中 一个数据做了一次更新操作

在更新过后 所有的访问请求都能获取这个更新过后的值



## 弱一致性

后续的访问请求 有一部分还是拿不到 更新过后的数据

或者说全部请求都拿不到



## 最终一致性（主流的互联网应用）

经过一段时间以后 在某个未来的时间点 我能保证在这个某个未来的时间点 访问到的数据 都能取得到更新过后的值 在这个时间点 所有的数据副本中的值都能会保持一致



![](https://tcs.teambition.net/storage/31210b6be90e498a1de64ba6d6434e09c690?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjE3NiwiaWF0IjoxNjEyMTkxMzc2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwYjZiZTkwZTQ5OGExZGU2NGJhNmQ2NDM0ZTA5YzY5MCJ9.3tC2MF5gY4HRfvS4WoVDaq1s4Ldy6G7sxOU4f60xmNk&download=image.png "")



## A 可用性

就是服务可用

就是一部分的机器宕机

也要保证整个服务是可用的

![](https://tcs.teambition.net/storage/31219145efc937f54fa87f256fcd7993b0f5?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjE3NiwiaWF0IjoxNjEyMTkxMzc2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5MTQ1ZWZjOTM3ZjU0ZmE4N2YyNTZmY2Q3OTkzYjBmNSJ9.HAHbNn6-EXEnACO1zAmjOVMy7ziutyGrf8VjG5bm0DE&download=image.png "")

## P 分区容错性

大型应用都有异地机房做容灾

> 容灾系统是指在相隔较远的异地，建立两套或多套功能相同的IT系统，互相之间可以进行健康状态监视和功能切换，当一处系统因意外（如火灾、地震等）停止工作时，整个应用系统可以切换到另一处，使得该系统功能可以继续正常工作。

这些异地机房数据 在互相同步备份 

假如 在某两个分区之间 这种数据同步的通信通道被切断了 这两个机房的数据 停止了同步 这样就会产生数据不一致性



对于 支持分区容错性的系统来说 必须做一个艰难的二选一

假设这个时候它选择了兼顾可用性 两个机房继续提供服务

数据就不一致



选择一致性 就要等待 阻塞在这里 



 一般来说 在一致性 分区容忍性

或者可用性 在分区容忍性

二选一



单体应用 可以保证 一致性 可用性



分布式应用 后台数据库 从单库 变成了多库 或者是主从 不能保证这两种可以兼得 必须考虑分区容错性

![](https://tcs.teambition.net/storage/3121f934e0e97586e21cb4a4333f092cea12?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjE3NiwiaWF0IjoxNjEyMTkxMzc2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmOTM0ZTBlOTc1ODZlMjFjYjRhNDMzM2YwOTJjZWExMiJ9.smX1qYdUM6S8V8d_QHdAKdXu64qXoQqsx5hIQ4bQR28&download=image.png "")

![](https://tcs.teambition.net/storage/3121beba5801b1fdf6f4160e70bb81d73092?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjE3NiwiaWF0IjoxNjEyMTkxMzc2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiZWJhNTgwMWIxZmRmNmY0MTYwZTcwYmI4MWQ3MzA5MiJ9.1UnlqoKMHvWtJI_WUv0CXPw5NM_I1sQgHpqbqf7Qyuc&download=image.png "")

![](https://tcs.teambition.net/storage/31216c6d3194ed2a4364ae23d12c12666729?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjE3NiwiaWF0IjoxNjEyMTkxMzc2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2YzZkMzE5NGVkMmE0MzY0YWUyM2QxMmMxMjY2NjcyOSJ9.dGPLESWKNzBc-sV1XaAeDmnoPXPbiAtNKaPePA5IY8M&download=image.png "")



可用性 分区容错性 采用的是弱一致性

![](https://tcs.teambition.net/storage/3121d3431d6aa4add119c0e45c59ea407d20?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjE3NiwiaWF0IjoxNjEyMTkxMzc2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkMzQzMWQ2YWE0YWRkMTE5YzBlNDVjNTllYTQwN2QyMCJ9.951FdOWlAkpMSHsjRRD9NLf0ajBRVsXN6FGFqw4nt98&download=image.png "")

## 应用广度

![](https://tcs.teambition.net/storage/312153b1a49b9a511eb60063294eef068099?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjE3NiwiaWF0IjoxNjEyMTkxMzc2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1M2IxYTQ5YjlhNTExZWI2MDA2MzI5NGVlZjA2ODA5OSJ9.giMRkx4SU5Lc9z_LOnzlKMdlUXMryvxJ_rvrmfl-9Co&download=image.png "")

































开源笔记

可 Pull Requests 协作写开源笔记

gitee

[https://gitee.com/opendevel/java-for-linux](https://gitee.com/opendevel/java-for-linux)

github

[https://github.com/OSrcD/java-for-linux](https://github.com/OSrcD/java-for-linux)

teambition

[https://tburl.in/0jDNvpbK](https://tburl.in/0jDNvpbK)

开源视频

bilibili

[https://space.bilibili.com/77266754](https://space.bilibili.com/77266754)

开源博客

oschina

[https://my.oschina.net/u/4675154](https://my.oschina.net/u/4675154)

csdn

[https://blog.csdn.net/OpenDevel](https://blog.csdn.net/OpenDevel)

开源项目

gitee

[https://gitee.com/opendevel](https://gitee.com/opendevel)

github

[https://github.com/OSrcD](https://github.com/OSrcD)

开源赞赏

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjE3NiwiaWF0IjoxNjEyMTkxMzc2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.lw-V3MP9zXZt99N-riXTifCmhbbefI-njcwveqDbIBM&download=image.png "")

