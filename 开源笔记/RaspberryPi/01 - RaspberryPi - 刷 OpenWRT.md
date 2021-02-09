插入读卡器

![](https://tcs.teambition.net/storage/31223d945685d451c565791400f0f8313add?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzQ0OTYzOCwiaWF0IjoxNjEyODQ0ODM4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzZDk0NTY4NWQ0NTFjNTY1NzkxNDAwZjBmODMxM2FkZCJ9.kN6rps4CjOpNO8mcgBCnH6HzdynItI_hoPGvHvy2p9Y&download=image.png "")

```text
df -h

# 挂载掉
diskutil unmount /dev/disk2s1

diskutil list

```

![](https://tcs.teambition.net/storage/31220784d581884a052663177e847956f892?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzQ0OTYzOCwiaWF0IjoxNjEyODQ0ODM4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIwNzg0ZDU4MTg4NGEwNTI2NjMxNzdlODQ3OTU2Zjg5MiJ9.AbND5jSp5Lwgbsb0sP02w51b85MJzoPOjfEm-CLX2kE&download=image.png "")

下载固件

![](https://tcs.teambition.net/storage/312221a5effa1c7a6a5f47c46b277b2c8484?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzQ0OTYzOCwiaWF0IjoxNjEyODQ0ODM4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIyMWE1ZWZmYTFjN2E2YTVmNDdjNDZiMjc3YjJjODQ4NCJ9.jCskbGUJjHhsUxhxJCDRdZLP9qePdDp8cVb-aPTmNJs&download=image.png "")

![](https://tcs.teambition.net/storage/31227e98a41f7cf1547353e0459bf67cda6e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzQ0OTYzOCwiaWF0IjoxNjEyODQ0ODM4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI3ZTk4YTQxZjdjZjE1NDczNTNlMDQ1OWJmNjdjZGE2ZSJ9.fL4T9t60O9YQQ2YmxafikvTLdc2Hr7Czoka6GfX9zm0&download=image.png "")

> [https://github.com/SuLingGG/OpenWrt-Rpi/actions/runs/541200137](https://github.com/SuLingGG/OpenWrt-Rpi/actions/runs/541200137)

![](https://tcs.teambition.net/storage/312264fa06de03fc4ab385800cf516d4dd16?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzQ0OTYzOCwiaWF0IjoxNjEyODQ0ODM4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI2NGZhMDZkZTAzZmM0YWIzODU4MDBjZjUxNmQ0ZGQxNiJ9.CCu9vCqp6BgbaaR_zIhMoSUlYNW_cCgtZJXL89lp9yA&download=image.png "")



```text
# 刷入镜像
# bs 每块的每秒大小
# if 输入文件
# of 输出文件
# dd 命令 可从标准输入或文件中读取数据，根据指定的格式来转换数据，再输出到文件、设备或标准输出
# 刷写镜像的过程当中 不要取消 否则会损坏 sd 卡
sudo dd bs=4m if=镜像文件.img of=/dev/disk2

# 卸载块设备
diskutil unmountDisk /dev/disk2

# 弹出 sd 卡
sudo diskutil eject /dev/disk2


```

显示 dd 命令进度

![](https://tcs.teambition.net/storage/312230e38d0f7b7eb25aa002f346a70a8635?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzQ0OTYzOCwiaWF0IjoxNjEyODQ0ODM4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzMGUzOGQwZjdiN2ViMjVhYTAwMmYzNDZhNzBhODYzNSJ9.IEj-FxXii8aV1lZWsE9BYVrIVGgSd25muesC5sqfOtI&download=image.png "")

![](https://tcs.teambition.net/storage/3122834831e71528e1acd650994547b4b582?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzQ0OTYzOCwiaWF0IjoxNjEyODQ0ODM4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI4MzQ4MzFlNzE1MjhlMWFjZDY1MDk5NDU0N2I0YjU4MiJ9.PVYGqYHGjPv2VfSQOP7hMRntuTSsw1YK9rZPtnbks5A&download=image.png "")

```text
sudo killall -29 dd

```

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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzQ0OTYzOCwiaWF0IjoxNjEyODQ0ODM4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.IzHk-Bv0gVISQwFipcU8rZr5QTMIJh-rhLWuCoofEZQ&download=image.png "")

