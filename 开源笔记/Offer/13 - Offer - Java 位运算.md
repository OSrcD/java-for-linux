<< 左移1位 代表 * 2



## 4 左移 2位

4 << 2 

4的二进制

0000 0100（原码）

向左移动2位 移出的丢弃

00 0100

00 0100xx

空位补0

00 010000（16）



## -4 左移 2位

-4的二进制

1111 1100（补码）

向左移动2位 移出的丢弃

111100

111100xx

空位补0

1111 0000（-16）



>> 右移1位 代表 / 2



## -4 右移 2位

-4 >> 2 



-4 的 二进制

11111100

向右移动 2 位 移出的丢弃

xx111111

如果是符号位空位补1

11111111（-1）



## 4 右移 2位

4 的 二进制

00000100

向右移动 2 位 移出的丢弃

xx000001

如果不是符号位空位补0

00000001（1）



## -4 无符号右移 2位

-4 >>> 2

-4 的 二进制

11111100

向右移动 2 位 移出的丢弃

xx111111

空位补0

00111111（63）



## 4 无符号右移 2位

4 的 二进制

0000 0100

向右移动 2 位 移出的丢弃

xx000001

空位补0

00000001（1）



二进制

1  1  1  1  1  1            1            1

128   64  32    16   4    2   1  (*2)



原码 二进制 值

1 = 0000 0001

-1 = 1000 0001



正数的反码是本身

负数的反码是 原码的基础上 符号位不变 其他位取反

 1 = 00000001（原码） = 00000001（反码）

-1 = 10000001（原码） = 11111110（反码）



正数的补码是本身

负数的补码是反码 + 1

在计算机存储负数用补码表示

1 = 00000001（原码） = 00000001（反码） = 00000001（补码）

-1 = 10000001（原码） = 11111110（反码） = 11111111（补码）



& 两个操作数都为1则为1 否则为0

| 两个操作数只要有一个为1 则为 1 否则为0



~ 取反



异或 ^

两个操作数相同为1

不同为0





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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTg4NCwiaWF0IjoxNjE1NTQ3MDg0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.-VUwKg-1roBQho5IilNQhM5g4O_h8Ph-NiC9qF0r8GQ&download=image.png "")

