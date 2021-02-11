

![](https://tcs.teambition.net/storage/31229e2cf46252431a04ef2241aa9900b555?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzg1MywiaWF0IjoxNjEzMDA5MDUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5ZTJjZjQ2MjUyNDMxYTA0ZWYyMjQxYWE5OTAwYjU1NSJ9.xm24PDUTajr3Kid4NIZY4TGZKjuCmQw83Ilb6ix03Wo&download=2020-09-17%20191339.png "")





![](https://tcs.teambition.net/storage/3122cba0b3eb5025237505d0e8c5cce3aa2e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzg1MywiaWF0IjoxNjEzMDA5MDUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJjYmEwYjNlYjUwMjUyMzc1MDVkMGU4YzVjY2UzYWEyZSJ9.uLlpgihnVOtFTr61GqA7x32126eUAYXQBaND4-AUbms&download=image.png "")

vim mynginx-pod.yaml

![](https://tcs.teambition.net/storage/3122a82e8c62c6b13111f6d3a7afe980d050?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzg1MywiaWF0IjoxNjEzMDA5MDUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhODJlOGM2MmM2YjEzMTExZjZkM2E3YWZlOTgwZDA1MCJ9.IVCNnXAZtkwg7G3VHzbmhbpP6gfvMNatNG8kKm4UDSE&download=image.png "")

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
    # 配置卷
    volumeMounts:
    # 映射到 pod 里面的 目录
    - mountPath: /mymount
      # 卷名 把 name 的 名字 卷 映射到 这个 pod 里面 所有容器 /mymount 底下
      name: mount-volume
  volumes:
  # 指定 volume 的名字 
  - name: mount-volume
    # 指定类型
    emptyDir: {}

```

删除 pod

![](https://tcs.teambition.net/storage/3122356cfab57029f79c0fba47121693c323?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzg1MywiaWF0IjoxNjEzMDA5MDUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzNTZjZmFiNTcwMjlmNzljMGZiYTQ3MTIxNjkzYzMyMyJ9.2fq1RIQ-NorKscLnSpyHetlkvbmGuFrZCQ0PPvJNUiQ&download=image.png "")

```text
kubectl apply -f mynginx-pod.yaml

```

![](https://tcs.teambition.net/storage/312204fc54e7e69ad6cde4c290eab4547866?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzg1MywiaWF0IjoxNjEzMDA5MDUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIwNGZjNTRlN2U2OWFkNmNkZTRjMjkwZWFiNDU0Nzg2NiJ9.eH9r3VexLqs7RKBtwKjgIqchahulc3yK0hY68CRN9bc&download=image.png "")

```shell
[root@151-k8s-master-CentOS7-Logstash-6 software]# 
[root@151-k8s-master-CentOS7-Logstash-6 software]# vim mynginx-pod.yaml 
[root@151-k8s-master-CentOS7-Logstash-6 software]# kubectl delete^C
[root@151-k8s-master-CentOS7-Logstash-6 software]# kubectl apply -f mynginx-pod.yaml 
pod/mynginx created
[root@151-k8s-master-CentOS7-Logstash-6 software]# kubectl get pod 
NAME                                READY   STATUS    RESTARTS   AGE
busybox                             1/1     Running   1          3h53m
mynginx                             1/1     Running   0          30s
nginx-deployment-546d9dcc8d-9qtfk   1/1     Running   0          5h31m
nginx-deployment-546d9dcc8d-9xrpv   1/1     Running   0          5h31m
nginx-deployment-546d9dcc8d-b57t9   1/1     Running   0          5h31m
nginx-deployment-546d9dcc8d-c9s8r   1/1     Running   0          5h31m
nginx-deployment-546d9dcc8d-x22vr   1/1     Running   0          5h30m
[root@151-k8s-master-CentOS7-Logstash-6 software]# 这个 容器 告诉我们 把外面的卷 挂载到 容器里面 mymount ^C
[root@151-k8s-master-CentOS7-Logstash-6 software]# kubectl exec mynginx mount | grep mymount
kubectl exec [POD] [COMMAND] is DEPRECATED and will be removed in a future version. Use kubectl exec [POD] -- [COMMAND] instead.
/dev/mapper/centos-root on /mymount type xfs (rw,relatime,seclabel,attr2,inode64,noquota)

```

这是同一个pod 的目录共享



SP

快设备





PV 长期保存的 volume 



亚马逊的块设备

主要的存储类型

![](https://tcs.teambition.net/storage/31226b3e22bb5e3a35be423bf74cf0ccbf66?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzg1MywiaWF0IjoxNjEzMDA5MDUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI2YjNlMjJiYjVlM2EzNWJlNDIzYmY3NGNmMGNjYmY2NiJ9.sKwMb_10ZoH23OMNFp8ystlx908Fx6row0QlxWn79f8&download=image.png "")

 



NFS 服务器



![](https://tcs.teambition.net/storage/3122a3633a7457c944164bbf1d2d805df92b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzg1MywiaWF0IjoxNjEzMDA5MDUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJhMzYzM2E3NDU3Yzk0NDE2NGJiZjFkMmQ4MDVkZjkyYiJ9.JdNxcjjsEv9NOwWJ1gvlyIcdD2Tw4LbwNSUBIdgF4qo&download=image.png "")

```shell
yum install -y  nfs-utils

yum install -y rpcbind

```



```text
[root@153-k8s-node-2-IMOOC-DEV-FDFS-Storage ~]# # 开启 rpcbind 服务器
[root@153-k8s-node-2-IMOOC-DEV-FDFS-Storage ~]# systemctl restart rpcbind
[root@153-k8s-node-2-IMOOC-DEV-FDFS-Storage ~]# # 开启 nfs-server 服务器
[root@153-k8s-node-2-IMOOC-DEV-FDFS-Storage ~]# systemctl restart nfs-server
[root@153-k8s-node-2-IMOOC-DEV-FDFS-Storage ~]# ifocnfig |^C
[root@153-k8s-node-2-IMOOC-DEV-FDFS-Storage ~]# ifconfig | grep 192.168.2
        inet 192.168.245.153  netmask 255.255.255.0  broadcast 192.168.245.255
[root@153-k8s-node-2-IMOOC-DEV-FDFS-Storage ~]# # 修改服务端 配置文件
[root@153-k8s-node-2-IMOOC-DEV-FDFS-Storage ~]# vim /etc/exports
exports    exports.d/ 
[root@153-k8s-node-2-IMOOC-DEV-FDFS-Storage ~]# vim /etc/exports
[root@153-k8s-node-2-IMOOC-DEV-FDFS-Storage ~]# vim /etc/exports
[root@153-k8s-node-2-IMOOC-DEV-FDFS-Storage ~]# # 重启 nfs 服务器
[root@153-k8s-node-2-IMOOC-DEV-FDFS-Storage ~]# systemctl restart nfs-server
[root@153-k8s-node-2-IMOOC-DEV-FDFS-Storage ~]# # 使用客户端查看命令
[root@153-k8s-node-2-IMOOC-DEV-FDFS-Storage ~]# show
show-changed-rco  showconsolefont   show-installed    showkey           showmount         
[root@153-k8s-node-2-IMOOC-DEV-FDFS-Storage ~]# showmount -e
Export list for 153-k8s-node-2-IMOOC-DEV-FDFS-Storage:
/mnt 192.168.245.0/24
[root@153-k8s-node-2-IMOOC-DEV-FDFS-Storage ~]# 

```

```text
/mnt 192.168.245.0/24(rw,sync,no_root_squash)

```





![](https://tcs.teambition.net/storage/3122ca1bcbb2632de441493c8dd2dfbab718?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzg1MywiaWF0IjoxNjEzMDA5MDUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJjYTFiY2JiMjYzMmRlNDQxNDkzYzhkZDJkZmJhYjcxOCJ9.Gh6s6yEbeGxd5XnhgpZ_qFySquVcSY__5Rb_HQdNiL4&download=image.png "")

![](https://tcs.teambition.net/storage/312291a0c39533f0ebe0b6c29324dd7db731?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzg1MywiaWF0IjoxNjEzMDA5MDUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5MWEwYzM5NTMzZjBlYmUwYjZjMjkzMjRkZDdkYjczMSJ9.pxv5P_IuYStgOFtyAFI_F69HWnStTAiZrrxmwp14Qy8&download=image.png "")

![](https://tcs.teambition.net/storage/312204e922d8c87572084cd495bad3775911?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzg1MywiaWF0IjoxNjEzMDA5MDUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIwNGU5MjJkOGM4NzU3MjA4NGNkNDk1YmFkMzc3NTkxMSJ9.hwlkhP6j4xy0XxJ2pQmLDKlunVXeMYgTZZUQPj5Z49M&download=image.png "")

```yaml
apiVersion: v1
# 持久卷
kind: PersistentVolume
metadata:
  name: mypv
spec:
  # 容量
  capacity:
    # 大小
    storage: 1Gi
  # 访问模式 有读 可写 有一次读写 多次读写等等
  accessModes:
  # 一次读写
  - ReadWriteOnce
  # 回收方式 持久卷的回收策略 当我用完以后 其实我会把这个卷回收回来
  persistentVolumeReclaimPolicy: Recycle
  # 起名字
  storageClassName: nfs
  # 指定协议
  nfs: 
    # 指定目录
    path: /mnt
    # 指定服务器地址 
    server: 192.168.245.153

```

![](https://tcs.teambition.net/storage/3122ba70a19a6c5f052ddbbc18e7dfdafb48?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzg1MywiaWF0IjoxNjEzMDA5MDUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJiYTcwYTE5YTZjNWYwNTJkZGJiYzE4ZTdkZmRhZmI0OCJ9.6nqdTFo88o6xvU2YMCaS7uOoILQ83l8NHNYhQGzorjk&download=image.png "")

![](https://tcs.teambition.net/storage/31229a921676116ef78df7e0680896991d39?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzg1MywiaWF0IjoxNjEzMDA5MDUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5YTkyMTY3NjExNmVmNzhkZjdlMDY4MDg5Njk5MWQzOSJ9.xosN5gngtMOFNbmJOd1VmcIb0KUuAX3wYLujFH3-mKk&download=image.png "")

查看 pv

```shell
kubectl get pv

```

建 pvc



![](https://tcs.teambition.net/storage/31223348e08a16c5521c3a09403013f9e474?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzg1MywiaWF0IjoxNjEzMDA5MDUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzMzQ4ZTA4YTE2YzU1MjFjM2EwOTQwMzAxM2Y5ZTQ3NCJ9.WDe9lI3WjAdixGlarO6TmW51GvEGxTdjbA6vm8raHms&download=image.png "")

PVC 是使用者

```yaml
apiVersion: v1
# PV 一个请求 一个需求
kind: PersistentVolumeClaim
metadata:
  name: mypvc
spec:
  accessModes:
  # 要比 pv 权限要低
  - ReadWriteOnce
  # 指定资源 可以指定多个 pv
  resources:
    # 需求
    requests:
      # 提供 1G 不能大于 1G
      storage: 1Gi
  # 指定要用那个 storageClassName 用于映射
  storageClassName: nfs


```

![](https://tcs.teambition.net/storage/3122256946695f694f8bf27d70666617f6e5?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzg1MywiaWF0IjoxNjEzMDA5MDUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIyNTY5NDY2OTVmNjk0ZjhiZjI3ZDcwNjY2NjE3ZjZlNSJ9.N72WKy--OovmAHOYyloaCcy2eA46vGf4lBcyhmz4wtA&download=image.png "")

查看 pvc

kubectl get pvc



![](https://tcs.teambition.net/storage/31229aecf1d9141570641b5e3f8db87d25c7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzg1MywiaWF0IjoxNjEzMDA5MDUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5YWVjZjFkOTE0MTU3MDY0MWI1ZTNmOGRiODdkMjVjNyJ9.W6yhWrOeUGRVnN-my_uul6R04sZs_2DLJoGoO0YDDoo&download=image.png "")

![](https://tcs.teambition.net/storage/3122cdfcfd7da56903fe7162cac636b6758b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzg1MywiaWF0IjoxNjEzMDA5MDUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJjZGZjZmQ3ZGE1NjkwM2ZlNzE2MmNhYzYzNmI2NzU4YiJ9.sdXjBCPMAQktZSmQi538l5x-8vAHVnNMXKckI4YaQRc&download=image.png "")

```yaml
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
    # 配置卷
    volumeMounts:
    # 映射到 pod 里面的 目录
    - mountPath: /mymount
      # 卷名 把 name 的 名字 卷 映射到 这个 pod 里面 所有容器 /mymount 底下
      name: mount-volume
  volumes:
  # 指定 volume 的名字
  - name: mount-volume
    # 指定类型
    persistentVolumeClaim:
       claimName: mypvc

```

![](https://tcs.teambition.net/storage/3122588f99634b932b7710532a6145810052?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzg1MywiaWF0IjoxNjEzMDA5MDUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI1ODhmOTk2MzRiOTMyYjc3MTA1MzJhNjE0NTgxMDA1MiJ9.tbg5Qeye6-9YOQue0AgAWMTAPNcr-0Uy8TnHW9xXY2Y&download=image.png "")

```shell
kubectl apply -f mynginx-pod.yaml 

```

![](https://tcs.teambition.net/storage/3122d6e9f02df3c175ae3ba85ff5b8a0a3e8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzg1MywiaWF0IjoxNjEzMDA5MDUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkNmU5ZjAyZGYzYzE3NWFlM2JhODVmZjViOGEwYTNlOCJ9.2TrcpYoOkLk9ULBX51ZcflNPr1kvWAV0TLMxmTy-alQ&download=image.png "")

![](https://tcs.teambition.net/storage/31224093e78510e9165d673a9e15767dd38b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzg1MywiaWF0IjoxNjEzMDA5MDUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI0MDkzZTc4NTEwZTkxNjVkNjczYTllMTU3NjdkZDM4YiJ9.R-KFvT5FZicW0noOtEU6DP_6hyNNlVUe2ZkvLtLBvjo&download=image.png "")

hello



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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzg1MywiaWF0IjoxNjEzMDA5MDUzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.pabsu4CvfhL06_jVPrOzM0Cw0Gkf-lDmh2vFA2r16m0&download=image.png "")

