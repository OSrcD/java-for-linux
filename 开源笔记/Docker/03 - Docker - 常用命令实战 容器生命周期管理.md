![](https://tcs.teambition.net/storage/3122780098a98f483cd3ac8bfbdbe701364d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjgzNjMzNywiaWF0IjoxNjEyMjMxNTM3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI3ODAwOThhOThmNDgzY2QzYWM4YmZiZGJlNzAxMzY0ZCJ9.r3OISrsTGkKo0_6DJDKaXPJdRuS19ptzj1qbWzsl0Rs&download=image.png "")

![](https://tcs.teambition.net/storage/312230511a5edab71bd16dbf7acf681650aa?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjgzNjM5OSwiaWF0IjoxNjEyMjMxNTk5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzMDUxMWE1ZWRhYjcxYmQxNmRiZjdhY2Y2ODE2NTBhYSJ9.djoAbfzBWmWlAKRUtlx70ut3eZ9KzjZ-ha00PS9Plok&download=image.png "")

docker create nginx  创建一个新的容器但不启动它



docker start 短容器id 开始一个容器



docker ps -a 查看所有的容器状态

docker ps 只查看运行的容器状态



![](https://tcs.teambition.net/storage/3122ee37364bd59af33b74481f3027de798f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjgzNjk1NiwiaWF0IjoxNjEyMjMyMTU2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJlZTM3MzY0YmQ1OWFmMzNiNzQ0ODFmMzAyN2RlNzk4ZiJ9.5LpFL8gH_E_u4mBDT8I2d7Vj35Qsj4L8Bcx6SBzj64M&download=image.png "")

```text
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker pull nginx
Using default tag: latest
latest: Pulling from library/nginx
a076a628af6f: Pull complete 
0732ab25fa22: Pull complete 
d7f36f6fe38f: Pull complete 
f72584a26f32: Pull complete 
7125e4df9063: Pull complete 
Digest: sha256:10b8cc432d56da8b61b070f4c7d2543a9ed17c2b23010b43af434fd40e2ca4aa
Status: Downloaded newer image for nginx:latest
docker.io/library/nginx:latest
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker create nginx
e0f1fac5f12471d30f20ad205e0466f41912f20a1732961e53aa27a71491dcf5
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker ps -a
CONTAINER ID   IMAGE     COMMAND                  CREATED          STATUS    PORTS     NAMES
e0f1fac5f124   nginx     "/docker-entrypoint.…"   15 seconds ago   Created             relaxed_volhard
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker ps
CONTAINER ID   IMAGE     COMMAND   CREATED   STATUS    PORTS     NAMES
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker start e0f1fac5f124
e0f1fac5f124
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker ps
CONTAINER ID   IMAGE     COMMAND                  CREATED              STATUS          PORTS     NAMES
e0f1fac5f124   nginx     "/docker-entrypoint.…"   About a minute ago   Up 15 seconds   80/tcp    relaxed_volhard

```

此时容器正在运行

![](https://tcs.teambition.net/storage/312268f9f0fcca39ca0da1bff5b826ff2f45?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjgzNzgwOCwiaWF0IjoxNjEyMjMzMDA4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI2OGY5ZjBmY2NhMzljYTBkYTFiZmY1YjgyNmZmMmY0NSJ9.-2VSQAEg4eUVJbFJNWlM1gBukdMT2SDtJpjyQN2YQAg&download=image.png "")

进入容器终端

docker exec -it e0f1fac5f124 /bin/bash



暂停容器

docker pause e0f1fac5f124



取消暂停容器

docker unpause e0f1fac5f124

![](https://tcs.teambition.net/storage/31225d19f37a28400f10504b5459e9b30734?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjgzNzc0NSwiaWF0IjoxNjEyMjMyOTQ1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI1ZDE5ZjM3YTI4NDAwZjEwNTA0YjU0NTllOWIzMDczNCJ9.j1hNb5PR6YDuh3o0L9Fc_zsXJNrPteR6jPv0jCA0RfI&download=image.png "")

```text
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker exec -it e0f1fac5f124 /bin/bash
root@e0f1fac5f124:/# uname -a
Linux e0f1fac5f124 3.10.0-1160.el7.x86_64 #1 SMP Mon Oct 19 16:18:59 UTC 2020 x86_64 GNU/Linux
root@e0f1fac5f124:/# cat /etc/isuse
cat: /etc/isuse: No such file or directory
root@e0f1fac5f124:/# cat /etc/issue
Debian GNU/Linux 10 \n \l

root@e0f1fac5f124:/# exit
exit
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker pause e0f1fac5f124
e0f1fac5f124
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker exec -it e0f1fac5f124 /bin/bash
Error response from daemon: Container e0f1fac5f124 is paused, unpause the container before exec
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker unpause e0f1fac5f124
e0f1fac5f124
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker exec -it e0f1fac5f124 /bin/bash
root@e0f1fac5f124:/# ls
bin   dev                  docker-entrypoint.sh  home  lib64  mnt  proc  run   srv  tmp  var
boot  docker-entrypoint.d  etc                   lib   media  opt  root  sbin  sys  usr
root@e0f1fac5f124:/# mkdir opendev
root@e0f1fac5f124:/# touch opendev/opendev
root@e0f1fac5f124:/# ls
bin   dev                  docker-entrypoint.sh  home  lib64  mnt      opt   root  sbin  sys  usr
boot  docker-entrypoint.d  etc                   lib   media  opendev  proc  run   srv   tmp  var
root@e0f1fac5f124:/# ls opendev/
opendev
root@e0f1fac5f124:/# exit
exit
[root@153-IMOOC-DEV-FDFS-Storage ~]# 

```

![](https://tcs.teambition.net/storage/3122c2b8c25af3ebdf04e2d23ac024033678?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjgzODAyNiwiaWF0IjoxNjEyMjMzMjI2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJjMmI4YzI1YWYzZWJkZjA0ZTJkMjNhYzAyNDAzMzY3OCJ9.JYYFVQyytTAZz5xvYsIYc0BmopePhp-F_4VIZQdmByM&download=image.png "")

停止容器

docker stop e0f1fac5f124



![](https://tcs.teambition.net/storage/3122f64e01153d1d81385ba9e15b49ed4f69?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjgzNzkyNCwiaWF0IjoxNjEyMjMzMTI0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJmNjRlMDExNTNkMWQ4MTM4NWJhOWUxNWI0OWVkNGY2OSJ9.aprEV0LJnTjUqapDq2LI1Bs6oUi5XE51ClEn4bK23K8&download=image.png "")



```text
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker stop e0f1fac5f124
e0f1fac5f124
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker ps
CONTAINER ID   IMAGE     COMMAND   CREATED   STATUS    PORTS     NAMES
[root@153-IMOOC-DEV-FDFS-Storage ~]# 

```

状态变成退出了



![](https://tcs.teambition.net/storage/31224f7e0e10761a8533495efb0e9386a05a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjgzODA5NCwiaWF0IjoxNjEyMjMzMjk0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI0ZjdlMGUxMDc2MWE4NTMzNDk1ZWZiMGU5Mzg2YTA1YSJ9.ZzTatkffRpvvvb6GBBTy4nb1xR1BSrT_hQz_yvnIeQU&download=image.png "")

```text
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker ps -a
CONTAINER ID   IMAGE     COMMAND                  CREATED          STATUS                     PORTS     NAMES
e0f1fac5f124   nginx     "/docker-entrypoint.…"   20 minutes ago   Exited (0) 3 minutes ago             relaxed_volhard

```

![](https://tcs.teambition.net/storage/3122747b8fe97e854fcf20b035ed2e0e31eb?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjgzODIwMSwiaWF0IjoxNjEyMjMzNDAxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI3NDdiOGZlOTdlODU0ZmNmMjBiMDM1ZWQyZTBlMzFlYiJ9.YkJbWuJZFAqvm0bjA4aAo_vBCOVHjNm3zozFuTrzDm4&download=image.png "")

容器文件还存在

```text
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker start e0f1fac5f124
e0f1fac5f124
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker exec -it e0f1fac5f124 /bin/bash
root@e0f1fac5f124:/# ls op
opendev/ opt/     
root@e0f1fac5f124:/# ls opendev/
opendev
root@e0f1fac5f124:/# exit
exit

```

杀死容器

![](https://tcs.teambition.net/storage/31228443ab20d026b9f2596882e837295f43?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjgzODQ4NSwiaWF0IjoxNjEyMjMzNjg1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI4NDQzYWIyMGQwMjZiOWYyNTk2ODgyZTgzNzI5NWY0MyJ9.HxyaerEqF5Xj7BtBDLIbllLxPg1gfQ3m4c_JX-GY_7s&download=image.png "")

docker kill e0f1fac5f124

![](https://tcs.teambition.net/storage/3122fe95569430b6836a0351f602cfa34929?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjgzODM5NiwiaWF0IjoxNjEyMjMzNTk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJmZTk1NTY5NDMwYjY4MzZhMDM1MWY2MDJjZmEzNDkyOSJ9.u43Dnb584Je1DuGuAykwWxYtW3hPLI8RyWomJcJt9Gk&download=image.png "")

```text
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker kill e0f1fac5f124
e0f1fac5f124
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker ps -a
CONTAINER ID   IMAGE     COMMAND                  CREATED          STATUS                       PORTS     NAMES
e0f1fac5f124   nginx     "/docker-entrypoint.…"   24 minutes ago   Exited (137) 6 seconds ago             relaxed_volhard
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker start e0f1fac5f124
e0f1fac5f124
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker exec -it e0f1fac5f124 /bin/bash
root@e0f1fac5f124:/# ls
bin   dev                  docker-entrypoint.sh  home  lib64  mnt      opt   root  sbin  sys  usr
boot  docker-entrypoint.d  etc                   lib   media  opendev  proc  run   srv   tmp  var
root@e0f1fac5f124:/# ls opendev/
opendev
root@e0f1fac5f124:/# 

```

容器移除

![](https://tcs.teambition.net/storage/31222e830841d7f01576cbf91c5915b96ad8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjgzODc3OCwiaWF0IjoxNjEyMjMzOTc4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIyZTgzMDg0MWQ3ZjAxNTc2Y2JmOTFjNTkxNWI5NmFkOCJ9.brmXZpFru-CzSW0wpa9VA-oXwFsPISsMPm_GSCrhz0s&download=image.png "")

正在运行的容器 需要强制移除

docker rm e0f1fac5f124



docker rm -f e0f1fac5f124



```text
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker rm e0f1fac5f124
Error response from daemon: You cannot remove a running container e0f1fac5f12471d30f20ad205e0466f41912f20a1732961e53aa27a71491dcf5. Stop the container before attempting removal or force remove
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker ps
CONTAINER ID   IMAGE     COMMAND                  CREATED          STATUS         PORTS     NAMES
e0f1fac5f124   nginx     "/docker-entrypoint.…"   28 minutes ago   Up 4 minutes   80/tcp    relaxed_volhard
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker rm -f e0f1fac5f124
e0f1fac5f124
[root@153-IMOOC-DEV-FDFS-Storage ~]# ps -a
   PID TTY          TIME CMD
  3716 pts/0    00:00:00 ps
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker ps -a
CONTAINER ID   IMAGE     COMMAND   CREATED   STATUS    PORTS     NAMES
[root@153-IMOOC-DEV-FDFS-Storage ~]# 

```

容器移除以后 文件不再存在

![](https://tcs.teambition.net/storage/3122f4d159ae99caf3bcba1b2d736d32f2d5?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjgzODkxMiwiaWF0IjoxNjEyMjM0MTEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJmNGQxNTlhZTk5Y2FmM2JjYmExYjJkNzM2ZDMyZjJkNSJ9.Hs5bZtQizIv3dtsCjFGOAKAFhMHoe3w7zzLl9E6OfFE&download=image.png "")

```text
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker create nginx 
23d5acac82ddd541b507df8e8ab0a79dda57d232a57c27995b3352a965111036
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker start 23d5acac82ddd541b507df8e8ab0a79dda57d232a57c27995b3352a965111036
23d5acac82ddd541b507df8e8ab0a79dda57d232a57c27995b3352a965111036
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker exec -it 23d5acac82ddd541b507df8e8ab0a79dda57d232a57c27995b3352a965111036 /bin/bash
root@23d5acac82dd:/# ls
bin   dev                  docker-entrypoint.sh  home  lib64  mnt  proc  run   srv  tmp  var
boot  docker-entrypoint.d  etc                   lib   media  opt  root  sbin  sys  usr
root@23d5acac82dd:/# exit
exit
[root@153-IMOOC-DEV-FDFS-Storage ~]# 

```

![](https://tcs.teambition.net/storage/3122213bbec2cdab06d8af374333139b8b86?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjgzOTAxMywiaWF0IjoxNjEyMjM0MjEzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIyMTNiYmVjMmNkYWIwNmQ4YWYzNzQzMzMxMzliOGI4NiJ9.unPDtHJWhvkI-Y1JQCVTsiB0TrPcgOTiBGzXpJpUAMA&download=image.png "")

docker run -d redis



查看容器运行的日志

docker logs bad5bb3253194ba5ac63c8df1957a17899379559c2f63780711fb44ce3471ce8

![](https://tcs.teambition.net/storage/3122c41586d6e2efc64a913fa56dc1a6c624?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjg0MDY3NCwiaWF0IjoxNjEyMjM1ODc0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJjNDE1ODZkNmUyZWZjNjRhOTEzZmE1NmRjMWE2YzYyNCJ9.AEPLMYy18AC3ncrw2bUuK11elWwAJjubd-c5vienuAs&download=image.png "")

```text
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker run -d redis 
Unable to find image 'redis:latest' locally
latest: Pulling from library/redis
a076a628af6f: Already exists 
f40dd07fe7be: Pull complete 
ce21c8a3dbee: Pull complete 
ee99c35818f8: Pull complete 
56b9a72e68ff: Pull complete 
3f703e7f380f: Pull complete 
Digest: sha256:0f97c1c9daf5b69b93390ccbe8d3e2971617ec4801fd0882c72bf7cad3a13494
Status: Downloaded newer image for redis:latest
bad5bb3253194ba5ac63c8df1957a17899379559c2f63780711fb44ce3471ce8
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker ps
CONTAINER ID   IMAGE     COMMAND                  CREATED              STATUS              PORTS      NAMES
bad5bb325319   redis     "docker-entrypoint.s…"   About a minute ago   Up About a minute   6379/tcp   quizzical_sutherland
23d5acac82dd   nginx     "/docker-entrypoint.…"   5 minutes ago        Up 5 minutes        80/tcp     awesome_lovelace
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker logs 他们太年轻了^C
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker logs bad5bb3253194ba5ac63c8df1957a17899379559c2f63780711fb44ce3471ce8
1:C 02 Feb 2021 02:51:29.838 # oO0OoO0OoO0Oo Redis is starting oO0OoO0OoO0Oo
1:C 02 Feb 2021 02:51:29.838 # Redis version=6.0.10, bits=64, commit=00000000, modified=0, pid=1, just started
1:C 02 Feb 2021 02:51:29.838 # Warning: no config file specified, using the default config. In order to specify a config file use redis-server /path/to/redis.conf
1:M 02 Feb 2021 02:51:29.843 * Running mode=standalone, port=6379.
1:M 02 Feb 2021 02:51:29.843 # WARNING: The TCP backlog setting of 511 cannot be enforced because /proc/sys/net/core/somaxconn is set to the lower value of 128.
1:M 02 Feb 2021 02:51:29.843 # Server initialized
1:M 02 Feb 2021 02:51:29.843 # WARNING overcommit_memory is set to 0! Background save may fail under low memory condition. To fix this issue add 'vm.overcommit_memory = 1' to /etc/sysctl.conf and then reboot or run the command 'sysctl vm.overcommit_memory=1' for this to take effect.
1:M 02 Feb 2021 02:51:29.843 # WARNING you have Transparent Huge Pages (THP) support enabled in your kernel. This will create latency and memory usage issues with Redis. To fix this issue run the command 'echo madvise > /sys/kernel/mm/transparent_hugepage/enabled' as root, and add it to your /etc/rc.local in order to retain the setting after a reboot. Redis must be restarted after THP is disabled (set to 'madvise' or 'never').
1:M 02 Feb 2021 02:51:29.844 * Ready to accept connections
[root@153-IMOOC-DEV-FDFS-Storage ~]# 

```

实时跟踪容器日志

docker logs -f bad5bb3253194ba5ac63c8df1957a17899379559c2f63780711fb44ce3471ce8

![](https://tcs.teambition.net/storage/3122912b609a351b68aed70b5138a842d186?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjg0MDY4MCwiaWF0IjoxNjEyMjM1ODgwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5MTJiNjA5YTM1MWI2OGFlZDcwYjUxMzhhODQyZDE4NiJ9.6ULCJgwMkJw5BnzYMbQhcp_dNTdAAptAuQ57s3nC2vA&download=image.png "")

```text
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker logs -f bad5bb3253194ba5ac63c8df1957a17899379559c2f63780711fb44ce3471ce8
1:C 02 Feb 2021 02:51:29.838 # oO0OoO0OoO0Oo Redis is starting oO0OoO0OoO0Oo
1:C 02 Feb 2021 02:51:29.838 # Redis version=6.0.10, bits=64, commit=00000000, modified=0, pid=1, just started
1:C 02 Feb 2021 02:51:29.838 # Warning: no config file specified, using the default config. In order to specify a config file use redis-server /path/to/redis.conf
1:M 02 Feb 2021 02:51:29.843 * Running mode=standalone, port=6379.
1:M 02 Feb 2021 02:51:29.843 # WARNING: The TCP backlog setting of 511 cannot be enforced because /proc/sys/net/core/somaxconn is set to the lower value of 128.
1:M 02 Feb 2021 02:51:29.843 # Server initialized
1:M 02 Feb 2021 02:51:29.843 # WARNING overcommit_memory is set to 0! Background save may fail under low memory condition. To fix this issue add 'vm.overcommit_memory = 1' to /etc/sysctl.conf and then reboot or run the command 'sysctl vm.overcommit_memory=1' for this to take effect.
1:M 02 Feb 2021 02:51:29.843 # WARNING you have Transparent Huge Pages (THP) support enabled in your kernel. This will create latency and memory usage issues with Redis. To fix this issue run the command 'echo madvise > /sys/kernel/mm/transparent_hugepage/enabled' as root, and add it to your /etc/rc.local in order to retain the setting after a reboot. Redis must be restarted after THP is disabled (set to 'madvise' or 'never').
1:M 02 Feb 2021 02:51:29.844 * Ready to accept connections

```

 -c 设置容器CPU权重，在CPU共享场景使用



通过docker run -m可以调整容器所使用的内存资源。如果主机支持swap内存，那么可以使用-m可以设定比主机物理内存还大的值。



同样，通过-c可以调整容器的CPU优先级。默认情况下，所有的容器拥有相同的CPU优先级和CPU调度周期，但你可以通过Docker来通知内核给予某个或某几个容器更多的CPU计算周期。



比如，我们使用-c或者--cpu-shares =0启动了C0、C1、C2三个容器，使用-c/--cpu-shares=512启动了C3容器。这时，C0、C1、C2可以100%的使用CPU资源（1024），但C3只能使用50%的CPU资源（512）。如果这个主机的操作系统是时序调度类型的，每个CPU时间片是100微秒，那么C0、C1、C2将完全使用掉这100微秒，而C3只能使用50微秒。



![](https://tcs.teambition.net/storage/3122a51aaf05c8c8622dd13755337725de2f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjg0MTM3NSwiaWF0IjoxNjEyMjM2NTc1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhNTFhYWYwNWM4Yzg2MjJkZDEzNzU1MzM3NzI1ZGUyZiJ9.tXBlPFTyJdhER6zLqmx428Rnmg0xk6RE4hVYnfZyDro&download=image.png "")

```text
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker run -d -c 4000 nginx
7491ec4f6ec72df1324d3175f84f1e5d658def343f58385a1242a055df384a31
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker ps
CONTAINER ID   IMAGE     COMMAND                  CREATED          STATUS          PORTS      NAMES
7491ec4f6ec7   nginx     "/docker-entrypoint.…"   17 seconds ago   Up 15 seconds   80/tcp     priceless_hellman
bad5bb325319   redis     "docker-entrypoint.s…"   36 minutes ago   Up 36 minutes   6379/tcp   quizzical_sutherland
23d5acac82dd   nginx     "/docker-entrypoint.…"   40 minutes ago   Up 40 minutes   80/tcp     awesome_lovelace
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker run -d -c 40 nginx
cc44c9ec56b23cc54263e7919ea7535d8220843766aacfb20f5d68ac2cb8a4a4
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker ps
CONTAINER ID   IMAGE     COMMAND                  CREATED              STATUS              PORTS      NAMES
cc44c9ec56b2   nginx     "/docker-entrypoint.…"   6 seconds ago        Up 5 seconds        80/tcp     great_thompson
7491ec4f6ec7   nginx     "/docker-entrypoint.…"   About a minute ago   Up About a minute   80/tcp     priceless_hellman
bad5bb325319   redis     "docker-entrypoint.s…"   37 minutes ago       Up 37 minutes       6379/tcp   quizzical_sutherland
23d5acac82dd   nginx     "/docker-entrypoint.…"   41 minutes ago       Up 41 minutes       80/tcp     awesome_lovelace
[root@153-IMOOC-DEV-FDFS-Storage ~]# 

```

设置内存

 -m或 --memory:设置内存的使用限制

--memory-swap:设置内存+swap的使用限制



docker run -d -m 200m --memory-swap=400m nginx 



设置限制每个块设备的输入输出控制。例如:磁盘，光盘以及usb等等。

docker run -d --blkio-weight 1000 nginx 

![](https://tcs.teambition.net/storage/312298a2cd229e508e2df87909b9423999e0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMjg0MzkwOCwiaWF0IjoxNjEyMjM5MTA4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5OGEyY2QyMjllNTA4ZTJkZjg3OTA5Yjk0MjM5OTllMCJ9.-fbdx-l1PY4piO_4eMpCFTe8hW4U2ZZwb8OEPQCIH9U&download=image.png "")

```text
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker run -d -m 200m --memory-swap=400m nginx
87167ec40257d4b331375ec6524cc17bc21c6bc24244a8ce4a170fe7abb36c1a
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker ps
CONTAINER ID   IMAGE     COMMAND                  CREATED             STATUS             PORTS      NAMES
87167ec40257   nginx     "/docker-entrypoint.…"   5 seconds ago       Up 1 second        80/tcp     vigilant_rhodes
cc44c9ec56b2   nginx     "/docker-entrypoint.…"   41 minutes ago      Up 41 minutes      80/tcp     great_thompson
7491ec4f6ec7   nginx     "/docker-entrypoint.…"   42 minutes ago      Up 42 minutes      80/tcp     priceless_hellman
bad5bb325319   redis     "docker-entrypoint.s…"   About an hour ago   Up About an hour   6379/tcp   quizzical_sutherland
23d5acac82dd   nginx     "/docker-entrypoint.…"   About an hour ago   Up About an hour   80/tcp     awesome_lovelace
[root@153-IMOOC-DEV-FDFS-Storage ~]# docker run -d --blkio-weight 1000 nginx 
6c657198f420a9e4418fee3b57a346a0a3bcfb1fe690821a7073368e6d42785d

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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjgzNjMzNywiaWF0IjoxNjEyMjMxNTM3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.sSEwl71i63IIQ2ikZHGBHsOvrp3SQtUmbzXaRsZUqsU&download=image.png "")

