

![](https://tcs.teambition.net/storage/3122c5b089645318713981a63b33c31040bd?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjg1NDA2NSwiaWF0IjoxNjEyMjQ5MjY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJjNWIwODk2NDUzMTg3MTM5ODFhNjNiMzNjMzEwNDBiZCJ9.Q4FFlN2qMtRnhcx5kmAlaKaRbU6pTo6J2cHN_dE1LrA&download=%E6%9C%AA%E6%A0%87%E9%A2%98-1.png "")

![](https://tcs.teambition.net/storage/3122d4cbaf311d71f93cbecfa23eaefa1238?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjg1NDA2NSwiaWF0IjoxNjEyMjQ5MjY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkNGNiYWYzMTFkNzFmOTNjYmVjZmEyM2VhZWZhMTIzOCJ9.Q8xq2rgZ2Nfc4MTjH_M_dXR59sUsFdDERhlki4SJnHM&download=image.png "")

![](https://tcs.teambition.net/storage/31229107cf6e6e1c36cb4c295a47f2200d71?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjg1NTg5MSwiaWF0IjoxNjEyMjUxMDkxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5MTA3Y2Y2ZTZlMWMzNmNiNGMyOTVhNDdmMjIwMGQ3MSJ9.TJs5dM-i5Ou5_GOJqmVkp8N1i7lLT97Jfx3uAMvOZ_0&download=image.png "")

```text
# 从哪个base image镜像开始 本地没有就 会去 pull
FROM debian
# 维修人员
# maintainer
MAINTAINER OpenDevel
# 在docker 容器起来的时候跑命令 在root 的根目录 
RUN mkdir test1
RUN touch test2
# 你在整个执行过程当中 容器不光要去跟互联网沟通 不光要跟外网环境沟通 甚至在整个容器镜像过程当中 我希望跟
# 我当前环境沟通 比如我把当前文件 复制 到镜像里面来 当镜像启动的时候 会把这个 文件加载到 . 就是当前目录
# 也就是容器 根里面底下去 
COPY test3 .
# ADD 也是把当前目录 或者文件复制到容器里面 但是有2个功能 copy 不具有的 一个就是解压功能 ADD 命令能解压
# 另外一个也可以从网络下载文件 用 ADD 命令 
ADD test4.tar.gz .
# 用于打开端口 把容器的端口 对外暴露出去 绑定到我们服务器某个端口之上 如果在容器启动的时候 加-P 它会自动
# 选择一个合适端口 去和我们容器80 端口绑定 就可以用服务器特定端口
# EXPOSE 80

# 希望这个目录绑定到服务器指定的里面底下 会生成一个相关的卷 名字随意 可以通过 docker images的时候 通过 VOLUME 将他那个目录 来指定 这个整个过程 
# VOLUME /data

# 再多的命令 只看最后一条 如果你有两个run都会执行 在启动容器过程中分别执行 执行完以后会看到很多ENTRYPOINT全部跳过 一直到最后一条 ENTRYPOINT 
# 必然会被执行到
ENTRYPOINT ["/bin/sh"]

# CMD 不一定必然被执行到 什么时候会被执行到 在Docker run 或者说 Docker start 这个容器的时候 后面不加那个参数 不加启动好 我要跑什么命令 在外面不指定命令的时候 CMD 会被执行到 如果 外面指定了命令 CMD就不会执行到 CMD 被执行过程当中 也要看 如果在DockerFile 没有ENTRYPOINT 文件 就直接去run这个  命令 如果有 ENTRYPOINT文件 它就会作为参数传给 ENTRYPOINT 我们这个执行的结果 就是 /bin/sh 跑起来以后再尝试 run /bin/sh 必然是一个报错
#CMD ["/bin/sh"]

# /bin/sh 后面通常 会跟一个 -c 去看看跑到底什么命令 这是一个传参 传一个参数不够 可以再传一个参数 
CMD ["-c","ls -l"]


```

-t 指定 叫什么

. 当前目录

Docker build -t mysh . 

```text

[root@153-IMOOC-DEV-FDFS-Storage software]# docker images
REPOSITORY   TAG       IMAGE ID       CREATED       SIZE
redis        latest    621ceef7494a   2 weeks ago   104MB
nginx        latest    f6d0b4767a6c   2 weeks ago   133MB
[root@153-IMOOC-DEV-FDFS-Storage software]# touch test3
[root@153-IMOOC-DEV-FDFS-Storage software]# mkdir test4
[root@153-IMOOC-DEV-FDFS-Storage software]# tar -czvf test4.tar.gz test4
test4/
[root@153-IMOOC-DEV-FDFS-Storage software]# ls
apache-tomcat-9.0.24.tar.gz                    libaio-0.3.107-10.el6.x86_64.rpm
commons-codec-1.9.jar                          libfastcommon-1.0.42
commons-logging-1.2.jar                        libfastcommon-1.0.42.tar.gz
config                                         logstash-6.4.3.tar.gz
DockerFile                                     MariaDB-client-10.4.8-1.el7.centos.x86_64.rpm
elasticsearch-6.4.3.tar.gz                     MariaDB-common-10.4.8-1.el7.centos.x86_64.rpm
elasticsearch-7.4.2-linux-x86_64.tar.gz        MariaDB-compat-10.4.8-1.el7.centos.x86_64.rpm
elasticsearch-analysis-ik-6.4.3 .zip           MariaDB-server-10.4.8-1.el7.centos.x86_64.rpm
elasticsearch-analysis-ik-7.4.2.zip            mysql-connector-java-5.1.41.jar
fastdfs-6.04                                   mysql-connector-java-8.0.20.jar
fastdfs-6.04.tar.gz                            nginx-1.16.1
fastdfs-nginx-module-1.22                      nginx-1.16.1.tar.gz
fastdfs-nginx-module-1.22.tar.gz               plugin-descriptor.properties
galera-4-26.4.2-1.rhel7.el7.centos.x86_64.rpm  plugin-security.policy
httpclient-4.5.2.jar                           redis-5.0.5
httpcore-4.4.4.jar                             redis-5.0.5.tar.gz
imooc                                          test3
jdk-8u191-linux-x64.tar.gz                     test4
jemalloc-3.6.0-1.el7.x86_64.rpm                test4.tar.gz
jemalloc-devel-3.6.0-1.el7.x86_64.rpm
[root@153-IMOOC-DEV-FDFS-Storage software]# Docker build -t mysh . 
-bash: Docker: 未找到命令
[root@153-IMOOC-DEV-FDFS-Storage software]# docker build -t mysh .
unable to prepare context: unable to evaluate symlinks in Dockerfile path: lstat /home/software/Dockerfile: no such file or directory
[root@153-IMOOC-DEV-FDFS-Storage software]# vim DockerFile ^C
[root@153-IMOOC-DEV-FDFS-Storage software]# mv DockerFile Dockerfile
[root@153-IMOOC-DEV-FDFS-Storage software]# docker build -t mysh .
Sending build context to Docker daemon  339.8MB
Sending build context to Docker daemon  357.1MB
Sending build context to Docker daemon  992.8MB
Step 1/8 : FROM debian
latest: Pulling from library/debian
b9a857cbf04d: Downloading  5.614MB/50.4MB

^C
[root@153-IMOOC-DEV-FDFS-Storage software]# docker build -t mysh .
Sending build context to Docker daemon  992.8MB
Step 1/8 : FROM debian
latest: Pulling from library/debian
b9a857cbf04d: Retrying in 1 second 
^C
[root@153-IMOOC-DEV-FDFS-Storage software]# docker pull debian
Using default tag: latest
latest: Pulling from library/debian
b9a857cbf04d: Pull complete 
Digest: sha256:b16f66714660c4b3ea14d273ad8c35079b81b35d65d1e206072d226c7ff78299
Status: Downloaded newer image for debian:latest
docker.io/library/debian:latest
[root@153-IMOOC-DEV-FDFS-Storage software]# docker build -t mysh .
Sending build context to Docker daemon  992.8MB
Step 1/8 : FROM debian
 ---> e7d08cddf791
Step 2/8 : MAINTAINER OpenDevel
 ---> Running in 16c1bf86153c
Removing intermediate container 16c1bf86153c
 ---> db73b325f9aa
Step 3/8 : RUN mkdir test1
 ---> Running in 420122d6d74f
Removing intermediate container 420122d6d74f
 ---> faa77c0ff8be
Step 4/8 : RUN touch test2
 ---> Running in 4c3b61c8225a
Removing intermediate container 4c3b61c8225a
 ---> 23fc6aa3bd62
Step 5/8 : COPY test3 .
 ---> 6660481caf12
Step 6/8 : ADD test4.tar.gz .
 ---> fb4584732619
Step 7/8 : ENTRYPOINT ["/bin/sh"]
 ---> Running in 603bdc6e6d18
Removing intermediate container 603bdc6e6d18
 ---> 3fddc0f7fc41
Step 8/8 : CMD ["-c","ls -l"]
 ---> Running in decefbe7ecb1
Removing intermediate container decefbe7ecb1
 ---> da752bebf15b
Successfully built da752bebf15b
Successfully tagged mysh:latest

```



所有结果 直接输出 服务器终端上

会运行 run ENTRYPOINT cmd





cmd 和 ENTRYPOINT 命令都执行了

![](https://tcs.teambition.net/storage/312234c4ff8efad362ccc13f22baf0b2bedc?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjg1NTc0OCwiaWF0IjoxNjEyMjUwOTQ4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzNGM0ZmY4ZWZhZDM2MmNjYzEzZjIyYmFmMGIyYmVkYyJ9.BuXdEHD-RpO1203WBgwZTXOBa0kp5GtS5bLBzYWV0WE&download=image.png "")

```text
[root@153-IMOOC-DEV-FDFS-Storage software]# docker run mysh
total 8
drwxr-xr-x.   2 root root 4096 Jan 11 00:00 bin
drwxr-xr-x.   2 root root    6 Nov 22 12:37 boot
drwxr-xr-x.   5 root root  340 Feb  2 07:27 dev
drwxr-xr-x.   1 root root   66 Feb  2 07:27 etc
drwxr-xr-x.   2 root root    6 Nov 22 12:37 home
drwxr-xr-x.   7 root root   85 Jan 11 00:00 lib
drwxr-xr-x.   2 root root   34 Jan 11 00:00 lib64
drwxr-xr-x.   2 root root    6 Jan 11 00:00 media
drwxr-xr-x.   2 root root    6 Jan 11 00:00 mnt
drwxr-xr-x.   2 root root    6 Jan 11 00:00 opt
dr-xr-xr-x. 136 root root    0 Feb  2 07:27 proc
drwx------.   2 root root   37 Jan 11 00:00 root
drwxr-xr-x.   3 root root   30 Jan 11 00:00 run
drwxr-xr-x.   2 root root 4096 Jan 11 00:00 sbin
drwxr-xr-x.   2 root root    6 Jan 11 00:00 srv
dr-xr-xr-x.  13 root root    0 Feb  2 00:32 sys
drwxr-xr-x.   2 root root    6 Feb  2 07:24 test1
-rw-r--r--.   1 root root    0 Feb  2 07:24 test2
-rw-r--r--.   1 root root    0 Feb  2 07:03 test3
drwxr-xr-x.   2 root root    6 Feb  2 07:03 test4
drwxrwxrwt.   2 root root    6 Jan 11 00:00 tmp
drwxr-xr-x.  10 root root  105 Jan 11 00:00 usr
drwxr-xr-x.  11 root root  139 Jan 11 00:00 var

```

![](https://tcs.teambition.net/storage/3122e8ca35687cbfa7a49aac9c9cd136f71f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjg1NjA4OCwiaWF0IjoxNjEyMjUxMjg4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJlOGNhMzU2ODdjYmZhN2E0OWFhYzljOWNkMTM2ZjcxZiJ9.BBf8rEMf7J6HFQcrhw719lw2AeCnB_OJQ_-plMx6Aqs&download=image.png "")

会取代 cmd 里面的命令

和 ENTRYPOINT 拼接在一起运行



最后一个ENTRYPOINT 会作为主命令执行 



如果没有ENTRYPOINT CMD也可以进行独立执行 就会得到实际的命令 得到执行 除非外面有传参









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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjg1NDA2NSwiaWF0IjoxNjEyMjQ5MjY1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.47_3yDPge7abUL-z52CEXXwSYOLQlaXjK4blxdxPlIU&download=image.png "")

