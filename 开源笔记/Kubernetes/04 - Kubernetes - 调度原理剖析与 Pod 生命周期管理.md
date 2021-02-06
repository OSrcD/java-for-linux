![](https://tcs.teambition.net/storage/31220101459c1d21bf74057fa90f7fbaa3d2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzE4MzkxNCwiaWF0IjoxNjEyNTc5MTE0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIwMTAxNDU5YzFkMjFiZjc0MDU3ZmE5MGY3ZmJhYTNkMiJ9.QyQiJXPglBmw53Q2N7DZOuQoOZBZJydojHGv6YbsJf8&download=image.png "")

在 namespace cgroup 隔离上 隔离成了一套环境



和其他pod 进行隔离

在同一个pod 各个容器之间用 localhost 之间可以很方便进行网络通信



可以访问相同的物理卷

卷来自于pod里面





![](https://tcs.teambition.net/storage/31228ae9a3b202a675004b93428b86d97c45?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzE4MzkxNCwiaWF0IjoxNjEyNTc5MTE0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI4YWU5YTNiMjAyYTY3NTAwNGI5MzQyOGI4NmQ5N2M0NSJ9.cKuKlPhO4_kyQ1-otIhaTCfFPnLmexqVI3i_WySDUZ8&download=image.png "")



可以在deployment 停止 pod



没有直接停止 使用 scale 来代替停止

kubectl scale --replicas=0 deployment/nginx-deployment

采用 deployment  来实现

![](https://tcs.teambition.net/storage/31227b30da852e75bbc2ed81e86b9d616dd9?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzE4MzkxNCwiaWF0IjoxNjEyNTc5MTE0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI3YjMwZGE4NTJlNzViYmMyZWQ4MWU4NmI5ZDYxNmRkOSJ9.ko0tTBye5i_m0G_MqIqZ9JAhhZMoo5XEDpHGcl-lwcs&download=image.png "")

![](https://tcs.teambition.net/storage/312206054d447a043213fd5569da8b09fc6c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzE4MzkxNCwiaWF0IjoxNjEyNTc5MTE0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIwNjA1NGQ0NDdhMDQzMjEzZmQ1NTY5ZGE4YjA5ZmM2YyJ9.AG7-t2U7UM71BDw3x6jZaQUNl_GcslQi4wLGr_EseAU&download=image.png "")

![](https://tcs.teambition.net/storage/3122c8a70dee21fff32df86f88d4b47234f8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzE4MzkxNCwiaWF0IjoxNjEyNTc5MTE0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJjOGE3MGRlZTIxZmZmMzJkZjg2Zjg4ZDRiNDcyMzRmOCJ9.PCf1so7ERvYXBubwqaWH_gT-Wg1ArVN2iOQuBl9wA5U&download=image.png "")



![](https://tcs.teambition.net/storage/312206e7b614617747337e39cc7c91b7c463?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMzE4Mzk1MiwiaWF0IjoxNjEyNTc5MTUyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIwNmU3YjYxNDYxNzc0NzMzN2UzOWNjN2M5MWI3YzQ2MyJ9.Wmo9FCqUepNiOvbQNof0r2fwksY70ktBIJy4tXEqtAI&download=image.png "")

![](https://tcs.teambition.net/storage/3122dfcd2b9f8179717ffebe4a56dc513609?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMzE4NTU0MSwiaWF0IjoxNjEyNTgwNzQxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkZmNkMmI5ZjgxNzk3MTdmZmViZTRhNTZkYzUxMzYwOSJ9.FRambzxpCy4S4EAzUXcIEfOjjgSKTwrd9odERB2PnHY&download=image.png "")

查看当前有哪些label

kubectl get node --show-labels

![](https://tcs.teambition.net/storage/3122fe05600a13b6f2bca4af9ecb43db11cd?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMzE4NTY4NywiaWF0IjoxNjEyNTgwODg3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJmZTA1NjAwYTEzYjZmMmJjYTRhZjllY2I0M2RiMTFjZCJ9.ZJiDY-21RYUli8QZIr96Wi0woBR2XaQBjGtlTlzTRPk&download=image.png "")

```text
[root@k8s-master ~]# kubectl get node --show-labels
NAME         STATUS   ROLES                  AGE   VERSION   LABELS
k8s-master   Ready    control-plane,master   12h   v1.20.2   beta.kubernetes.io/arch=amd64,beta.kubernetes.io/os=linux,kubernetes.io/arch=amd64,kubernetes.io/hostname=k8s-master,kubernetes.io/os=linux,node-role.kubernetes.io/control-plane=,node-role.kubernetes.io/master=
k8s-node-1   Ready    <none>                 12h   v1.20.2   beta.kubernetes.io/arch=amd64,beta.kubernetes.io/os=linux,kubernetes.io/arch=amd64,kubernetes.io/hostname=k8s-node-1,kubernetes.io/os=linux
k8s-node-2   Ready    <none>                 12h   v1.20.2   beta.kubernetes.io/arch=amd64,beta.kubernetes.io/os=linux,kubernetes.io/arch=amd64,kubernetes.io/hostname=k8s-node-2,kubernetes.io/os=linux

```

给一个节点打标签

kubectl get node --show-labels



![](https://tcs.teambition.net/storage/31223a7f6b37f4c0d1ed4c49dc584d70115a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMzE4NTkwMiwiaWF0IjoxNjEyNTgxMTAyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzYTdmNmIzN2Y0YzBkMWVkNGM0OWRjNTg0ZDcwMTE1YSJ9.LMnI3lGvSa5C7JK1B2vifW0T3LDxXYNB_5ijbqSW70g&download=image.png "")

```text
[root@k8s-master ~]# kubectl get node --show-labels
NAME         STATUS   ROLES                  AGE   VERSION   LABELS
k8s-master   Ready    control-plane,master   12h   v1.20.2   beta.kubernetes.io/arch=amd64,beta.kubernetes.io/os=linux,kubernetes.io/arch=amd64,kubernetes.io/hostname=k8s-master,kubernetes.io/os=linux,node-role.kubernetes.io/control-plane=,node-role.kubernetes.io/master=
k8s-node-1   Ready    <none>                 12h   v1.20.2   beta.kubernetes.io/arch=amd64,beta.kubernetes.io/os=linux,kubernetes.io/arch=amd64,kubernetes.io/hostname=k8s-node-1,kubernetes.io/os=linux
k8s-node-2   Ready    <none>                 12h   v1.20.2   beta.kubernetes.io/arch=amd64,beta.kubernetes.io/os=linux,disktype=ssd,kubernetes.io/arch=amd64,kubernetes.io/hostname=k8s-node-2,kubernetes.io/os=linux

```

![](https://tcs.teambition.net/storage/3122d6527cf3e29b9141bb4441b7ea75f63a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMzE4NjI0OCwiaWF0IjoxNjEyNTgxNDQ4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkNjUyN2NmM2UyOWI5MTQxYmI0NDQxYjdlYTc1ZjYzYSJ9.gngINmpp_oDqqtsnt_XNBIkhkeT2xFceaJsmqfojY3M&download=image.png "")

```yaml
# 指定版本 api server 在k8s master 上 api server 就会接收到这个信息 用 V1 这样 api 引擎 
# 来为你执行具体要求
apiVersion: v1
# 类型 最新单元 部署容器的最小单元
kind: Pod
# 指定关键的名称 要空两个格子
# name 具体应用名称 pod 的名称 
metadata:
  name: mynginx
# 给一个配置文件 spec
spec:
  # 定义我是一个 容器 共享网络命名空间 磁盘 文件系统
  containers:
  # - 定义列表 多个
  # name 定义一个名字 
  - name: nginx
    # 指定镜像
    image: nginx:1.7.9
  # 整个pod 都选用 这样一个node 
  nodeSelector:
    # 指定 label的标签磁盘类型 一定要指定有 SSD这个标签 disktype ssd 机器
    disktype: ssd

```

删除pod 就会变成 successed 状态

kubectl delete pod mynginx

![](https://tcs.teambition.net/storage/3122ab7dbbbef33299668d6e591b91edc425?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMzE4NjQyMiwiaWF0IjoxNjEyNTgxNjIyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhYjdkYmJiZWYzMzI5OTY2OGQ2ZTU5MWI5MWVkYzQyNSJ9._j7siONAMBCDaw8mtz0RpC8V4bhQo-dLvRMILaMzduA&download=image.png "")

直接改node 是不能直接 apply

![](https://tcs.teambition.net/storage/3122e9ad3d03fd0ce830cdcc392d8ab13cf8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMzE4NjUxMiwiaWF0IjoxNjEyNTgxNzEyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJlOWFkM2QwM2ZkMGNlODMwY2RjYzM5MmQ4YWIxM2NmOCJ9.X9wt-odUf4KZ3hZWaUl25oaSWqaxv0JNjWtgDQMIzww&download=image.png "")

![](https://tcs.teambition.net/storage/3122072027390b972f3ae2bb09ecb7be6d37?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMzE4NjUzNywiaWF0IjoxNjEyNTgxNzM3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIwNzIwMjczOTBiOTcyZjNhZTJiYjA5ZWNiN2JlNmQzNyJ9.KZXSExbDxM2nUdnY1FzJnjn5m1TRmWf-ppFbsGaCMJg&download=image.png "")

![](https://tcs.teambition.net/storage/31222b4f191746b23fd41ae22157ef1c9b9d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMzE4NzQ2MywiaWF0IjoxNjEyNTgyNjYzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIyYjRmMTkxNzQ2YjIzZmQ0MWFlMjIxNTdlZjFjOWI5ZCJ9.YcbWig3sElqXTauG4VWLxAUwbMvdjr-GCYyOOvRHKTM&download=image.png "")

![](https://tcs.teambition.net/storage/312222b2e4ffff1324d7e62d9c438b2bebac?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMzE4NzUxNiwiaWF0IjoxNjEyNTgyNzE2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIyMmIyZTRmZmZmMTMyNGQ3ZTYyZDljNDM4YjJiZWJhYyJ9.7dJWg5Gk_UOR54zOu0JuB09Rre1YzsT9WAI2dEt9avI&download=image.png "")

service多外网络服务

app是key

![](https://tcs.teambition.net/storage/3122acc516073375438ec45d02da83fc973a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMzE4NzYxNywiaWF0IjoxNjEyNTgyODE3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhY2M1MTYwNzMzNzU0MzhlYzQ1ZDAyZGE4M2ZjOTczYSJ9.BOwllXgXBcBqUmHutZVvbslHlWZ99TQlZv_KTOP6XAc&download=image.png "")

对不上就不会选择我们 pod

![](https://tcs.teambition.net/storage/3122b3c0c833fa0c6f8b13d035182a72e157?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMzE4NzY0NCwiaWF0IjoxNjEyNTgyODQ0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJiM2MwYzgzM2ZhMGM2ZjhiMTNkMDM1MTgyYTcyZTE1NyJ9.uKXZkJQephKR_RrjfqJhA_LNSmorcBfCH-HMJd6AAMA&download=image.png "")

就会打到我们 Traefik 上

![](https://tcs.teambition.net/storage/3122e46e53185f60ea92947b32b4b2db312a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMzE4NzgxMywiaWF0IjoxNjEyNTgzMDEzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJlNDZlNTMxODVmNjBlYTkyOTQ3YjMyYjRiMmRiMzEyYSJ9.J8-MnwHx6sJnBRJqMBA13tYq4AJaG7TzDlYGE6kql3U&download=image.png "")

![](https://tcs.teambition.net/storage/312235a832adf508b0f883732c3d256deac8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMzE4Nzg0NCwiaWF0IjoxNjEyNTgzMDQ0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzNWE4MzJhZGY1MDhiMGY4ODM3MzJjM2QyNTZkZWFjOCJ9.jjIVM7r4-aGDEm3jjeA0teIGH50jcw1Wp5QwVegu1-o&download=image.png "")

podSelector 必须指定一个 pod

![](https://tcs.teambition.net/storage/3122497f6008747eaff82f4ab08cd082da0b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMzE4Nzg5NiwiaWF0IjoxNjEyNTgzMDk2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI0OTdmNjAwODc0N2VhZmY4MmY0YWIwOGNkMDgyZGEwYiJ9.7cjf92-itvZSDGnA6LfoqNqGX_dWs1uMIuKo1U4-29c&download=image.png "")

![](https://tcs.teambition.net/storage/3122986d78798b95a60112f017903fa7fa5d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMzE4NzkxMSwiaWF0IjoxNjEyNTgzMTExLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5ODZkNzg3OThiOTVhNjAxMTJmMDE3OTAzZmE3ZmE1ZCJ9.Nh0Wf_hpd5RIMnRKD162qqEGWZcagkrs7KHd_-nvD1w&download=image.png "")

![](https://tcs.teambition.net/storage/3122daea88e7d89ae9d42357f16fd3e98f44?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMzE4ODAwOSwiaWF0IjoxNjEyNTgzMjA5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkYWVhODhlN2Q4OWFlOWQ0MjM1N2YxNmZkM2U5OGY0NCJ9.K1v-bqorVx75kivILa6K8FMEZVxdVTn5wDH0My4egjo&download=image.png "")

![](https://tcs.teambition.net/storage/312216e607cbe5c1945f0c2eb41f184fdc06?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMzE4ODY4OSwiaWF0IjoxNjEyNTgzODg5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxNmU2MDdjYmU1YzE5NDVmMGMyZWI0MWYxODRmZGMwNiJ9.x0nxcSLCpU5hRUzj8WhxWaa-LiA52UyuxneftUaUfuI&download=image.png "")

是不是能对外能够真正接收负载 traefick

接收方法 用一个httpget 方式去查一下这个端口 

如果是http的形式 能不能访问 默认就是http 80 形式

同时我要查一个网页 是/index.html

对这个 ip 地址 这个根目录 叫 index.html 的文件

直接进行http查询 get 如果能正常拿到 认为 这个容器是正常启动的

查询过程中还可以设置一些额外 东西 这里是停1秒

正常情况很多应用 比如 我 5分钟起来 5*60 就是  300 秒 我停 300 秒

在进行 liveness 检查 当 检查成功以后 我每 3秒进行反复查 一旦发现 你那个应用 已经不可 index 页面 不可达 立刻停止 你对 我的访问 这个容器就不对外提供服务了

由其他的容器 对外提供服务

![](https://tcs.teambition.net/storage/31224c0a537304ebf6f3e91d94952269581e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IjVmNTQ2ZDkyODI1NWU3ZjU1MzkxZmUwOSIsImV4cCI6MTYxMzE4OTU3NiwiaWF0IjoxNjEyNTg0Nzc2LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI0YzBhNTM3MzA0ZWJmNmYzZTkxZDk0OTUyMjY5NTgxZSJ9.JNMcUP5TvpKrbV3a4pJyFPOdtkiZesH5c6JLtM3i2M0&download=image.png "")



















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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzE4MzkxNCwiaWF0IjoxNjEyNTc5MTE0LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.4UMBBsWcG0Om6C8gwOjLUbj6fywesuWHMWkoo5RuxuY&download=image.png "")

