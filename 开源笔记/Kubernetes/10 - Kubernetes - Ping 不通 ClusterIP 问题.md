

```text
vim /etc/sysctl.conf

net.ipv4.ip_forward = 1
net.bridge.bridge-nf-call-iptables = 1
net.bridge.bridge-nf-call-ip6tables = 1

sysctl -p

yum -y install ipvsadm  ipset

# 临时生效
modprobe -- ip_vs
modprobe -- ip_vs_rr
modprobe -- ip_vs_wrr
modprobe -- ip_vs_sh
modprobe -- nf_conntrack_ipv4

# 永久生效

vim /etc/sysconfig/modules/ipvs.modules
modprobe -- ip_vs
modprobe -- ip_vs_rr
modprobe -- ip_vs_wrr
modprobe -- ip_vs_sh
modprobe -- nf_conntrack_ipv4



```

![](https://tcs.teambition.net/storage/3122419089fcc706de1eb30e8793d5b026ae?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzQ0ODg3OSwiaWF0IjoxNjEyODQ0MDc5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI0MTkwODlmY2M3MDZkZTFlYjMwZTg3OTNkNWIwMjZhZSJ9.wTfk2kbaZxjIGWFnPczZ_njAZhe_EWUXyDdMnXaRIK8&download=image.png "")

```text
# 配置 kube-proxy

kubectl edit cm kube-proxy -n kube-system

# 改为
mode: "ipvs"


# 重启
kubectl  get pod -n kube-system | grep kube-proxy | awk '{print $1}' | xargs kubectl delete pod -n kube-system




```

![](https://tcs.teambition.net/storage/3122b2ade5b7ce1d76efd7cb62661664fb81?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzQ0ODg3OSwiaWF0IjoxNjEyODQ0MDc5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjJiMmFkZTViN2NlMWQ3NmVmZDdjYjYyNjYxNjY0ZmI4MSJ9.DTq_htcnyIHEN98L4WVMZXtlStGERRXU3NPHbNaCVeo&download=image.png "")



![](https://tcs.teambition.net/storage/312281985b187d7f2b962d2284b8e98f0a20?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzQ0ODg3OSwiaWF0IjoxNjEyODQ0MDc5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjI4MTk4NWIxODdkN2YyYjk2MmQyMjg0YjhlOThmMGEyMCJ9.iB7HADZeSKUNuH1BW_s-wFOXB0RjdHRDjwxZYRJUjyQ&download=image.png "")

```text
kubectl  get pod -n kube-system | grep kube-proxy

kubectl logs kube-proxy-xxxxxx -n kube-system

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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMzQ0ODg3OSwiaWF0IjoxNjEyODQ0MDc5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.Gfo48-C8K4bCaJMTdGEW2tCwNMt1ayvbDP1MdwmGF78&download=image.png "")

