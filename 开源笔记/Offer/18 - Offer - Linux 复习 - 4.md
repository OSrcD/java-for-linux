uname 当前用户名

uname -a 当前用户名 内核版本

ifconfig

ip addr

shutdown -h now 关机

shutdown -r now 重启

reboot

halt 关机

poweroff 关机

init 0 关机 

init 6 重启



目录结构

/bin 命令目录

/sbin root才能使用的命令

/boot 启动目录

/root root目录

/dev 设备文件目录 硬盘

/etc 配置文件目录

/lib 函数库目录

/home 普通用户目录

/mnt 系统挂载目录 u盘挂载

/media 媒体设备挂载目录

/proc 里面的文件数据会存放到内存

/tmp 临时目录

/opt 第三方软件目录

/srv 服务存放数据目录

/usr 系统软件目录

/var 系统文档 日志目录



/boot 500M

/swap 2G



ls -l .

ls -al 

ls -alh

ls -alhS

ls -alhSr 倒序

ls --help

man ls



网络配置文件目录

![](https://tcs.teambition.net/storage/3123a77a9f57be027aafbd56015636b567df?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkyNiwiaWF0IjoxNjE1NTQ3MTI2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjNhNzdhOWY1N2JlMDI3YWFmYmQ1NjAxNTYzNmI1NjdkZiJ9.ibTKAdjcwm4GEFytZW0aIe_iPxAx6d_Pjq10oO62CXY&download=image.png "")

pwd

cd ~ 家目录

mkdir a

mkdir -p c/d 依次创建目录

rmdir a 删除目录

rmdir -p c/d/e 依次删除目录



/ 绝对路径

. ..  相对路径



touch a.txt 创建文件



vim 进入命令模式

a i o 插入命令 进入编辑模式

: / 最后行模式

esc 进入命令模式



j 下

k 上

h 左

l 右

dd 剪切

yy 复制

p 下一行黏贴

P 上一行黏贴

a 在光标后插入

i 在光标前插入

A 行首插入

I 行尾插入

o 下一行插入

O 上一行插入

w 保存

wq 保存并退出

按 n 会找下一个匹配

/ 关键字 

: set nu 显示行号



cat 文件 以打开的方式查看文件

more 文件 分段显示文件

less 文件 查看文件

PgUp 上一页

PgDn 下一页

head 文件 查看开头文件

tail 文件 查看尾部文件





cp -r 来源文件 目标文件 循环递归复制 r是递归

rm -rf 循环递归删除 f是不提示

mv 源文件 目标文件 移动文件



which 命令名 # 查找 命令位置

whereis 文件或目录 # 在特定位置查找

find 目录 -name/user/size 参数 

find / -name 'pass??' # 相当于 MySQL中的 __

find /root -user 'root' # 指定用户查找



who # 查看当前登录用户

useradd [-g 群组] 用户名 # 创建用户

passwd 用户名 # 为用户设置密码

userdel [-r] 用户名 # 删除用户 -r 连同用户相关数据都删除



groups [用户名] # 查看用户的群组

groupadd 群组名 # 创建群组

groupdel 群组名 # 删除群组

usermod [-g 群组名] 用户名 # 修改用户群组



r 读权限

w 写权限

x 执行权限



![](https://tcs.teambition.net/storage/3123ce736218deccd0ff88c0b9f4d06b40e2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkyNiwiaWF0IjoxNjE1NTQ3MTI2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjNjZTczNjIxOGRlY2NkMGZmODhjMGI5ZjRkMDZiNDBlMiJ9.-TDenC0vs_tsQPM5I2TA6nu-Ih62yYZS87YocSuvtDc&download=image.png "")



![](https://tcs.teambition.net/storage/3123f339cfcd8e093f9aec3337fda322a1b2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkyNiwiaWF0IjoxNjE1NTQ3MTI2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjNmMzM5Y2ZjZDhlMDkzZjlhZWMzMzM3ZmRhMzIyYTFiMiJ9.KFN16glKbsSLTv_d378qp4yjzVqZXjRQD1oIqYDlqMA&download=image.png "")

- 表示文件

d 表示目录

l 表示软连接

ln -s 软连接文件名 目标文件  相当于值引用的概念 删除原文件会影响到 软连接文件

ln 硬连接文件名 目标文件 两个对象指向同一引用 删除一个文件 互不影响 但是修改文件会影响 可创建文件 不能创建目录



chown [-R] 用户名 文件或目录 # 修改文件的所有者 -R 表示递归修改

chown [-R] 用户名:组名 文件或目录 # 修改文件的所有者和所属组

chgrp [-R] 组名 文件或目录 # 修改所属组



chmod [-R] xyz 文件或目录 # 修改文件权限 x 所有者权限 y 所属组权限 z 其他用户权限

r:4 w:2 x:1 # rwx 数字总和权限 



chmod [-R] x:u所有者 g所属组 o其他用户 a所有角色 y: + 增加 - 减少 = 设置 z:r读权限 w写权限 x执行权限 # 比如 chmod -R u + w 所有者权限添加写 chmod -R a - r 所有人权限去掉读权限



![](https://tcs.teambition.net/storage/3123ef4b6add4b33b87551af33ccac1d975a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkyNiwiaWF0IjoxNjE1NTQ3MTI2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjNlZjRiNmFkZDRiMzNiODc1NTFhZjMzY2NhYzFkOTc1YSJ9.GW8vqB9Yf-WWisOanEGVm9djUPwWE4k2xg99EsVmi4c&download=image.png "")



tar -ctx zjJ vf 压缩文件 [源文] # z 为gzip方式 j为bzip2方式 J 为xz方式 v显示过程 f指定压缩包名 c表示打包 t表示查看 x 表示解压



打包为 tar

tar -cvf 压缩文件名.tar 多个文件或者多个目录



打包为 gz

tar -czvf .tar.gz 多个文件或者多个目录



打包为 bz2

yum install bzip2

tar -cjvf .tar.bz2 多个文件或者多个目录



打包为 xz

tar -cJvf .tar.bz2  多个文件或者多个目录



打包为 zip

yum install zip

zip -r .zip 多个文件或者多个目录



查看 tar压缩包文件

tar -tvf .tar



查看 gz 压缩文件

tar -tzvf .tar.gz



查看 xz压缩文件

tar -Jtvf .tar.xz



解压为 tar

tar -xvf .tar



解压为xz

tar -xJvf .tar.xz



解压为zip

unzip .zip





./configure

make

make install

make clean # 清除上次make 编译的文件 后 删除目录



安装rpm

rpm -ivh 软件包 # -i 为安装 -v 显示详细过程 -h 显示进度

rpm -q 安装包名 # 查看是否安装

rpm -qi 安装包名 # 查看安装包详细信息

rpm -ql 安装包名 # 查看安装详细位置

rpm -e 安装包名 # 卸载





![](https://tcs.teambition.net/storage/3123eb44f9bcd235c7adb7c894ccd4520a58?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkyNiwiaWF0IjoxNjE1NTQ3MTI2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjNlYjQ0ZjliY2QyMzVjN2FkYjdjODk0Y2NkNDUyMGE1OCJ9.kSIZUo4iS5w7jdXZUtVkvZ4mwSnxvHwxz9jbJhH6eNI&download=image.png "")

![](https://tcs.teambition.net/storage/31238fd3476dad72a08c35907e9d27a7cfa8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkyNiwiaWF0IjoxNjE1NTQ3MTI2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM4ZmQzNDc2ZGFkNzJhMDhjMzU5MDdlOWQyN2E3Y2ZhOCJ9.XG-IKr7xJEGDsBztfPdL87lx2YTfngnWxHMKIaNcA9c&download=image.png "")



yum list 名称 # 查询可以安装的包

yum [-y] install 软件包 # -y 自动回答yes

yum [-y] update 软件包 # 更新

yum [-y] remove 软件包 # 卸载



curl -O URL或URI # 下载文件



linux jdk配置

![](https://tcs.teambition.net/storage/31234893b7ffcd29897abaeaf64ab6226095?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkyNiwiaWF0IjoxNjE1NTQ3MTI2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM0ODkzYjdmZmNkMjk4OTdhYmFlYWY2NGFiNjIyNjA5NSJ9.Y2HTx5JdtapBMVsO7qVyA7ILtC5vxgRhXMqfYH-YrPs&download=image.png "")

source profile

把war包放到 webapps 目录下

在bin 目录 启动 tomcat

ps -ef | grep tomcat # -e和-A的意思是一样的，即显示有关其他用户进程的信息，包括那些没有控制终端的进程。-f显示用户id，进程id，父进程id，最近CPU使用情况，进程开始时间等等。

用 webapps目录下目录名访问

![](https://tcs.teambition.net/storage/3123246abd868dbbd5b50ea8c1936778d3e7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkyNiwiaWF0IjoxNjE1NTQ3MTI2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjMyNDZhYmQ4NjhkYmJkNWI1MGVhOGMxOTM2Nzc4ZDNlNyJ9.yJDrAOxF530eaZsFCt6OHEu5XzdkajeXtrgvzLs5lY4&download=image.png "")



实时调试 tail catalina.out -f

![](https://tcs.teambition.net/storage/31230a4cbb6bbdfe8cc42deea837a5fa6b90?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkyNiwiaWF0IjoxNjE1NTQ3MTI2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjMwYTRjYmI2YmJkZmU4Y2M0MmRlZWE4MzdhNWZhNmI5MCJ9.WmacVeN6Jppw0Zv3OgXhJNITGDfZJ9ngsDJAcklz7_Q&download=image.png "")





 





















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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkyNiwiaWF0IjoxNjE1NTQ3MTI2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.ADZOS0dlFvM4nmKFgfhCZ8Xf-zeJHXZY-EBV26ElR28&download=image.png "")

