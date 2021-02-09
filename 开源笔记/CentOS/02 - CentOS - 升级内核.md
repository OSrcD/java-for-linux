```text
# 添加源
rpm --import https://www.elrepo.org/RPM-GPG-KEY-elrepo.org
rpm -Uvh http://www.elrepo.org/elrepo-release-7.0-3.el7.elrepo.noarch.rpm
yum --disablerepo=\* --enablerepo=elrepo-kernel repolist

# 检查可用的内核包

yum --disablerepo=\* --enablerepo=elrepo-kernel list kernel*

# 安装最新版本的内核

yum --disablerepo=\* --enablerepo=elrepo-kernel install  kernel-ml.x86_64  -y

# 删除旧版本工具包并安装最新版本工具包
yum remove kernel-tools-libs.x86_64 kernel-tools.x86_64  -y
yum --disablerepo=\* --enablerepo=elrepo-kernel install kernel-ml-tools.x86_64  -y

# 查看内核启动顺序
awk -F \' '$1=="menuentry " {print i++ " : " $2}' /etc/grub2.cfg

# 使用索引
grub2-set-default 0　

# 也可使用名称
grub2-set-default 'CentOS Linux (5.9.1-1.el7.elrepo.x86_64) 7 (Core)'

# 查看当前内核启动索引
grub2-editenv list

reboot

uname -r 

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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzQ0OTcxOSwiaWF0IjoxNjEyODQ0OTE5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.dUslJJ1abbIRuU4SyUfy9iRmmEVC8M93CdlHAC46pTY&download=image.png "")

