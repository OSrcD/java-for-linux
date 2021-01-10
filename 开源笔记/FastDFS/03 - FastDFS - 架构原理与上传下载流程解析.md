![](https://tcs.teambition.net/storage/31217e7f266bb172677e03ec6329fea7695d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDg5NTA1NywiaWF0IjoxNjEwMjkwMjU3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3ZTdmMjY2YmIxNzI2NzdlMDNlYzYzMjlmZWE3Njk1ZCJ9.2Y219rJ58ZCeJHOxT8LcaS3mrj0Y-UEhD0ryGEhLEbQ&download=image.png "")

## 跟踪器

前文说到，tracker其实就是一个负载均衡的调度器，用户发起的请求会首先经过tracker。tracker可以有多个，类比于nginx。

## 存储节点

前文说过，FastDFS由多个group组成，每个group包含了多个节点，做一个冗余的作用。

用户向tracker发起请求，然后tracker接受到请求后他会去查找一下看一下哪一个storage可用，拿到相应的节点地址后，会返回给用户。然后用户再次发起请求去做一个上传或者下载的操作。如下图所示：

![](https://tcs.teambition.net/storage/3121fef1d931a49ea12122b1ff6aaa1bce9b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDg5NTA1NywiaWF0IjoxNjEwMjkwMjU3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmZWYxZDkzMWE0OWVhMTIxMjJiMWZmNmFhYTFiY2U5YiJ9.o8YjtEXwMmlxQvW5zm2zeEP5B-wxfyP3g945LCijmBc&download=image.png "")







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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDg5NTA1NywiaWF0IjoxNjEwMjkwMjU3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.nlWImTK2xahmhebrJXkYiTQb68F1Yh4B2BpZ4XPpihY&download=image.png "")

