![](https://tcs.teambition.net/storage/31223e1e4b6b341265a17e95ef65cfa8851b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzIzMywiaWF0IjoxNjEzMDA4NDMzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzZTFlNGI2YjM0MTI2NWExN2U5NWVmNjVjZmE4ODUxYiJ9.HUlhr5h92HWDNjePvu5C08WrntG0fRfuSYZIo85qaIQ&download=image.png "")

![](https://tcs.teambition.net/storage/3122ce15f4295373f3289a9e7b5e08606096?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzIzMywiaWF0IjoxNjEzMDA4NDMzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJjZTE1ZjQyOTUzNzNmMzI4OWE5ZTdiNWUwODYwNjA5NiJ9.s1SfQ9ynkBnlz21bOBJgN2NNIFGgLxzYODSqACz72FM&download=image.png "")

![](https://tcs.teambition.net/storage/3122403d6b1a8942df9611792462e3a8cb5b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzIzMywiaWF0IjoxNjEzMDA4NDMzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI0MDNkNmIxYTg5NDJkZjk2MTE3OTI0NjJlM2E4Y2I1YiJ9.SNaj-vKeSNzjrrAzyfPGMtA3ECzEdi3f7zoOlHCNYok&download=image.png "")

![](https://tcs.teambition.net/storage/3122405ee127f203c1906e838488cff182d4?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzIzMywiaWF0IjoxNjEzMDA4NDMzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI0MDVlZTEyN2YyMDNjMTkwNmU4Mzg0ODhjZmYxODJkNCJ9.iGPhXcXSEKpvXkwIYFT55GBZVFfl3XMCMen4hiPkgJk&download=image.png "")

看enable base Control

![](https://tcs.teambition.net/storage/3122d64397362585afdae18bdd5f47f3b156?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzIzMywiaWF0IjoxNjEzMDA4NDMzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkNjQzOTczNjI1ODVhZmRhZTE4YmRkNWY0N2YzYjE1NiJ9.ftnHq9-M8soj2lhmyqbC1FQ_92pTNtzSPwDgbXOdrJ4&download=image.png "")

```text
[root@151-k8s-master-CentOS7-Logstash-6 software]# vim^Cetc/kubernetes/manifests/kube-apiserver.yaml 
[root@151-k8s-master-CentOS7-Logstash-6 software]# cat /etc/kubernetes/manifests/kube-apiserver.yaml | grep auth
	# 每个 node  来做 authorization Enable RBAC 自动激活了
    - --authorization-mode=Node,RBAC
    - --enable-bootstrap-token-auth=true

```

![](https://tcs.teambition.net/storage/31223025163b40d912d2a0175770e84f9e93?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzIzMywiaWF0IjoxNjEzMDA4NDMzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIzMDI1MTYzYjQwZDkxMmQyYTAxNzU3NzBlODRmOWU5MyJ9.Ygh2ch6cm-RKXtoySKJ_IKEjThzG1xlfwTucjs2T61M&download=image.png "")

![](https://tcs.teambition.net/storage/3122b84b16251c36acdee72cba82409ac5a9?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzIzMywiaWF0IjoxNjEzMDA4NDMzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJiODRiMTYyNTFjMzZhY2RlZTcyY2JhODI0MDlhYzVhOSJ9.nP_MKIDO2Uh-QxGCib4Au-UhQsSRuZ7mszPwH8nqIBc&download=image.png "")

```yaml
apiVersion: v1
# 创建一个 ServiceAccount
kind: ServiceAccount
metadata:
  # 名字
  name: mysa
# --- 表示把多个 yaml 写在一个 yaml 文件里面 把这些内容分隔开来 
---
apiVersion: rbac.authorization.k8s.io/v1
kind: Role
metadata:
  name: mysa-role
# role 的规则
rules:
# 对所有 api 
- apiGroups:
  # 我不具体区分 到底是 api v1 v2 都可以操作
  - ""
  # 资源控制
  resources:
  # 只能先对 pod 进行合理的操作 其他 node 节点 不一定有权限
  - pods
  # 动作
  verbs:
  # 可读
  - get
  # 可查
  - list
  # 可仔细监控 可以读状态 可以读很多信息
  - watch
# role 和 账号对应关系
---
# k8s 提供的相关 api
apiVersion: rbac.authorization.k8s.io/v1
# 权限绑定 把 刚刚 创建的 Service account 为 mysa 和 一个 role 在 apiGroup 是rbac 里面定义的 role 名字叫
# mysa-role 就是上面哪两个 子 yaml 文件生成的内容 对应起来  
kind: RoleBinding
metadata:
  name: mysa-rolebinding
roleRef:
  apiGroup: rbac.authorization.k8s.io
  kind: Role
  name: mysa-role
subjects:
- kind: ServiceAccount
  # 名字 需要和我们的 service account 对应
  name: mysa

```

![](https://tcs.teambition.net/storage/312227f85c24be5b5fb7cc37e58650ad9913?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzIzMywiaWF0IjoxNjEzMDA4NDMzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIyN2Y4NWMyNGJlNWI1ZmI3Y2MzN2U1ODY1MGFkOTkxMyJ9._-cNGbZn1WJg3EtsBcQJgPzAqWnXYUrCyOSSgkW-bEc&download=image.png "")

创建在 default namespace

因为我没有指定namespace



查 service account

kubectl get sa



![](https://tcs.teambition.net/storage/31229b2308ce60ec21237592abaa547d5caf?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzIzMywiaWF0IjoxNjEzMDA4NDMzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5YjIzMDhjZTYwZWMyMTIzNzU5MmFiYWE1NDdkNWNhZiJ9.F8WemAcUxwNJz3qDzJYn--Heh4FcH9GsrjpjqAIQ-b0&download=image.png "")

它可以对大部分 node 进行查询 之前起了个特殊的pod 大盘

![](https://tcs.teambition.net/storage/31229005f3fb853e91a935ecfa0eded22ee0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzIzMywiaWF0IjoxNjEzMDA4NDMzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI5MDA1ZjNmYjg1M2U5MWE5MzVlY2ZhMGVkZWQyMmVlMCJ9.QkCbTxPqULuh31r5d5JeMxXfCxQyhDtdYWixYtqbKhA&download=image.png "")

查询 token 

kubectl get secret 

![](https://tcs.teambition.net/storage/312210ecae2ef52ad41b4a6d927ddde01967?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzIzMywiaWF0IjoxNjEzMDA4NDMzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxMGVjYWUyZWY1MmFkNDFiNGE2ZDkyN2RkZGUwMTk2NyJ9.rpK4ptlCQzRUEJAKKbwLRiXhZuMUaBWlKAY-8MzhV-U&download=image.png "")

提供密钥管理



查询 token的详细信息

kubectl describe secret mysa-token-8zv89

![](https://tcs.teambition.net/storage/31225350aba6f3819665756b6927d2f8e253?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzIzMywiaWF0IjoxNjEzMDA4NDMzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI1MzUwYWJhNmYzODE5NjY1NzU2YjY5MjdkMmY4ZTI1MyJ9.UXhPBXUDXrzpThKLOTWoqPyIclaBaAoIJUeMBzAG0s8&download=image.png "")



![](https://tcs.teambition.net/storage/3122d3e1f0229e280ce312cd50f2675fc17b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzIzMywiaWF0IjoxNjEzMDA4NDMzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJkM2UxZjAyMjllMjgwY2UzMTJjZDUwZjI2NzVmYzE3YiJ9.XAjpnMD95YSrZ-kGqmxL1UAA33xgJ8WzmZISMyuoO2Q&download=image.png "")

![](https://tcs.teambition.net/storage/312202929f97b099285a9edce3a7a3916325?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzIzMywiaWF0IjoxNjEzMDA4NDMzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIwMjkyOWY5N2IwOTkyODVhOWVkY2UzYTdhMzkxNjMyNSJ9.VC5wNCvRigesDxZGzkpx-0uAb3etuhds5SPra8qWkTA&download=image.png "")

![](https://tcs.teambition.net/storage/312218ff3079240ea90b74ce37cbd807dbb6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzIzMywiaWF0IjoxNjEzMDA4NDMzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjIxOGZmMzA3OTI0MGVhOTBiNzRjZTM3Y2JkODA3ZGJiNiJ9.eRabA9Iofp2ZVWDT7p4LQee30mVll-_4qn6VldvPxYs&download=image.png "")









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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzYxMzIzMywiaWF0IjoxNjEzMDA4NDMzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.YVvVSwP0wFJK0-c4FuZqLK06C3IzD3n7Lj5ABMTqRSY&download=image.png "")

