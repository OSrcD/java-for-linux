![](https://tcs.teambition.net/storage/3121406a22ed970173181ff6693b3c1b635b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc0NywiaWF0IjoxNjEyMTkwOTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0MDZhMjJlZDk3MDE3MzE4MWZmNjY5M2IzYzFiNjM1YiJ9.4dSv1KMhhSx2WoV5lDYunfLWrIKlI-8kxN7mYV8CTpw&download=image.png "")

线上环境 设置 30% 35% 



user服务没有对远程服务的调用

ribbon 和 Hystrix 超时冲突

如果Hystrix 设置超时时间为4000ms

ribbon 的超时时间为 2000ms

重试 3 次  2000*3 = 6000ms 第3次就无法重试



numBuckets 滑动窗口的计数 配置的时候 最好能被上面 timeInMilliseconds 整除掉 就可以在指定的窗口内均匀的分布这么多个统计桶了 默认是 10



rollingPercentile 百分位计数 

bucketSize 设置为300  在过去的20秒内 如果你这边有 500个请求 哪我这里只记录最后 300个  默认值是100

![](https://tcs.teambition.net/storage/31213ee4d0da3b03ae79c2926e09efd79e90?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc0NywiaWF0IjoxNjEyMTkwOTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzZWU0ZDBkYTNiMDNhZTc5YzI5MjZlMDllZmQ3OWU5MCJ9.R--2AR0XJLgpnkuwLqr9lUY8QONpvFihTP1ifV9ILGY&download=image.png "")

commandKey 默认名

![](https://tcs.teambition.net/storage/312173416513f23199fb5bec38711890490e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc0NywiaWF0IjoxNjEyMTkwOTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3MzQxNjUxM2YyMzE5OWZiNWJlYzM4NzExODkwNDkwZSJ9.0yYKgRzzn1U_NOxDwxQBgpRMNfkZzaRelXTRf5797h0&download=image.png "")



方法名相同 可以用方法签名

定义到Hystrix 托管方法当中

![](https://tcs.teambition.net/storage/31212774a817abdaa353632745c620f03ef6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc0NywiaWF0IjoxNjEyMTkwOTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyNzc0YTgxN2FiZGFhMzUzNjMyNzQ1YzYyMGYwM2VmNiJ9.mjZORLI8VvKG6xLq8UGCn1S3dI_yb-ay6efv4E7sM6M&download=image.png "")













开源笔记

可 Pull Requests 协作写开源笔记

如果笔记图片无法访问 请访问 [teambition](https://tburl.in/0jDNvpbK) 原版开源笔记

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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc0NywiaWF0IjoxNjEyMTkwOTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.rlPStXFt5Kq7PPWWs15L_-GHeaYU_mttExGPmHgY4hk&download=image.png "")

