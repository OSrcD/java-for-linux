<div align="center"><img width="200" src="https://gitee.com/OpenDevel/java-for-linux/raw/OSrcD/image/logo.png"/>
<h1> java-for-linux: Welcome to Internet </h1>
</div>


## 仓库简介

这个仓库主要是一个**代码库 & 项目库** 方便自己以后**做其他项目**的时候 直接 **Copy** 这个仓库的代码。后续会选择 **cppmm 开源项目** 作为未来的开源项目。**⭐java-for-linux 是作者的一个自媒体与开源项目结合 综合型开源项目** 作为 **Gitee 官方开源指北项目贡献者贡献了 自媒体与开源项目结合理论与实际模块** 就是把自己开发的**多个开源项目集成**在一起维护 
与编程相关的内容都会存放到 这个仓库里 目前有 **6+ 个开源项目**：**⭐webrtc-live 直播导购子项目** **⭐Gitee 官方开源指北项目**、Java 开源课程子项目、Java 开源笔记子项目、
**⭐OpenToolbox 仿黑客命令行终端工具子项目** 、**⭐Java 泡泡堂游戏子项目**、Java 2048 小游戏子项目、
**⭐cppmm 搜集了市面上 JVM 源码 所有研究资料子项目**、**⭐开发者英语子项目**、**其他 Java 开源子项目等**

### java-for-linux 综合型开源子项目：

**⭐Gitee 官方开源指北开源项目**：**Gitee 官方联合 90 多位开源爱好者、开源社区及 6 位审校专家**
编写的十分优秀的开源操作指南、保姆级开源百科《开源指北》
为那些想参与开源的开发者们提供一个丰富详实的操作指南，让更多开发者认识开源、参与开源、爱上开源。
开源指北的项目模块有 **Git 入门（初级篇）、Git 命令详解、Git 团队协作与管理（进阶篇）。
开源故事。初识开源、学习和使用开源项目、尝试参与开源、启动自己的开源项目、开源治理、有关开源的其他问题、
开源指北编写成员、开源指北 Logo、开源 VLOG、开源寄语。
开源指北官方 pages 阅读页**，该页面还支持了 PWA ，Android 或者 PC 系统的用户还可以把开源指北添加在桌面上，能够让你随时随地的阅读。
⭐积累了 **57 多个 Issues、403 多次 PR（Pull Requests）提交、997 多次的 Push 提交、1.8K Star**、成为了 Gitee 官方推荐项目。
⭐目前开源指北 1.0 版本正式上线了。
**⭐作者作为开源指北编写成员** 贡献了开源项目与媒体结合实战经验 PR，⭐提交如何申请 JetBrains 开源许可证 Issue。

**💡 使用说明：**

[开源指北仓库地址](https://gitee.com/gitee-community/opensource-guide)

[开源指北阅读首页](https://gitee.com/opensource-guide/)

[开源指北 VLOG](https://www.bilibili.com/video/BV1pU4y147Fu)

**Java 开源课程子项目**：**⭐像 JDK 开发团队一样开发 Java（在 JVM 源码内嵌写 Native 函数给 Java 层调用）**、**⭐Java 写游戏安全**、⭐基于 Linux 的 JNI 外嵌级 Native 函数动态注册、Kali Linux 内核编程、⭐基于 Java for OpenCV 的百度云失效链接自动分享、⭐C 语言指针、⭐Java 泛型反编译（在开源**课程**文件夹）。

**💡 使用说明：**

[课程观看地址](https://space.bilibili.com/77266754/video)

[专栏阅读地址](https://space.bilibili.com/77266754/article)

**Java 开源笔记子项目**：**⭐阅读英文技术文档基础**、⭐Docker、⭐Kubernetes、Elasticsearch、FastDFS、OSS、⭐Spring Cloud 全家桶、⭐Vultr 搭建服务器、互联网视频高效率学习技巧、⭐DDOS 防御、Nginx、Redis、RabbitMQ、RocketMQ、Java 语法基础、Web 入门、Java 后台数据库、Java SSM 框架、Spring Boot 等（在开源**笔记**、java-for-gitee 文件夹）。

**💡 使用说明：**

[笔记阅读地址](https://thoughts.teambition.com/sharespace/60b31958a2aa01004a28b7dc)

**⭐OpenToolbox 仿黑客命令行终端工具子项目：**（在 **OpenToolbox** 文件夹）。

**简介：**

⭐仿黑客命令行终端工具 一个辅助编程小工具 是一款终端命令小工具 用于敲 Linux 命令 敲各种软件的命令行命令 使用 SSH 命令连接服务器 可以多开窗口。

**OpenToolbox 主要功能模块：**

命令行输入输出组件模块。

多开窗口模块。

自定义黑色的标题栏，不要系统自带的标题栏模块。

hacker 工具箱模块。

爬虫、爬取最新的网络安全新闻显示到 GUI 模块。

Hacker 学习路线、hacking 指令搜索模块。

**负责系统模块：**

1. 负责实现命令行输入输出组件模块。

2. 负责实现多开窗口模块。

**OpenToolbox 核心技术栈：**

node-pty、electron、vue、xterm。

**业绩：**

成为更加专业的开发者。

**💡 使用说明：**

```shell
# Mac OS X 版本 克隆项目
git clone https://gitee.com/OpenDevel/java-for-linux.git
# 进入 OpenToolbox 子项目文件夹
cd OpenToolbox
# 安装 npm
sudo npm install -g cnpm
# 安装 cnpm
sudo cnpm install -g yarn
# 安装依赖
sudo sh npm_install.sh
# 运行
sudo yarn run dev
# 编译
sudo yarn run build
# 启动（Mac OS X）
sudo open build/OpenToolbox-darwin-x64/OpenToolbox.app/
```

```shell

# windows 版本 克隆项目
git clone https://gitee.com/OpenDevel/java-for-linux.git

cd OpenToolbox

# 进入 windows 版本
cd OpenToolbox

# 安装依赖
npm install --global --production windows-build-tools

npm_install.bat

npm i

npm run dev

npm run build:win32
```

**⭐foodie-mall 吃货商城项目**（在 **foodie-center foodie-cloud foodie-dev foodie-payment foodie-shop nginx-url-hash mybatis-generator sso-mtv sso-music java-for-gitee 开源笔记** 文件夹）。

**简介:**

专为客户提供蛋糕点心、饼干膨化、熟食肉类、素食卤味、坚果炒货、糖果蜜饯、巧克力果冻、海鲜海味、花茶、果茶、生鲜、蔬果、⭐吃货系的直播导购电商平台，集成了直播导购指导客户购买商品优质服务。

**foodie-mall 吃货商城核心系统模块：**

内容中心系统：用户模块、轮播图模块、商品分类模块、商品推荐模块、商品评价模块、商品搜索核心模块、
购物车核心模块、收货地址模块、订单核心模块。

用户中心系统：用户信息模块、头像上传核心模块、订单管理模块、评价管理模块。

⭐支付中心核心系统：微信支付核心模块、支付宝支付核心模块。

数据库核心系统：数据库表核心模块。

⭐直播导购子项目：开始直播核心模块、直播权限控制模块、观看直播核心模块、WebSocket 信令服务器模块、Bootstrap 前端直播模板模块。

⭐Nginx 集群系统：LVS 双机主备、Nginx 双机热备、负载均衡、动静分离、Tomcat 集群、网关、反向代理。

⭐Redis 分布式缓存系统：轮播图缓存、商品分类缓存、分布式缓存购物车、Redis 主从复制读写分离架构、Redis 哨兵机制与实现、Spring Boot 集成 Redis 哨兵、Redis 集群、Spring Boot 集成 Redis 集群、缓存穿透、Redis 分布式用户会话、分布式会话拦截器、 CAS 单点登陆。

⭐Elasticsearch 分布式搜索引擎系统：Logstatsh 商品表数据库同步、Elasticsearch 商品分页搜索、高亮、排序。

⭐FastDFS 分布式文件系统：FastDFS 头像上传、OSS 头像上传。

⭐Spring Cloud 微服务重构 Spring Boot 项目：搭建项目整体结构、公共依赖模块、集成 Eureka 注册中心模块、改造商品中心模块、改造用户中心模块、改造订单中心模块、改造购物车模块、用户模块集成 Feign 组件、用户与订单模块集成 Hystrix 相关组件、Config 配置中心模块、用户模块集成 Config 相关组件、集成 Gateway 网关中心模块、鉴权中心模块、集成 Sleuth、Zipkin、ELK 相关组件模块、集成 Stream 强制退出用户、关闭超时订单模块。

⭐Docker 部署注册中心、配置中心、鉴权中心、用户中心、网关中心微服务、Nginx 前端内容中心系统。

⭐阿里云部署 云数据库 MySQL、云数据库 Redis、云消息中间件 RabbitMQ。

⭐K8S 部署 RabbitMQ、注册中心、配置中心集群、鉴权中心集群、用户中心集群、商品中心集群、购物车中心集群、订单中心集群、网关中心集群。自由扩缩容 用户中心集群、安装 Istio、Knative 有客户端请求就自动伸缩指定容器。

**负责系统模块：**

1. ⭐负责实现商品搜索核心模块。
2. 负责实现购物车核心模块。
3. ⭐负责实现订单核心模块。
4. 负责实现头像上传核心模块。
5. 负责实现数据库表核心模块。
6. ⭐负责实现直播导购子项目核心模块。

**foodie-mall 吃货商城技术栈：**

⭐采用前后端分离单体、集群、分布式、微服务、容器化架构开发模式。

后端：⭐Spring Boot 2.1.5 核心技术、Spring、Spring MVC、MyBatis、Swagger 2、Tomcat 9.0.24、JDK 8、Maven、Redis、LVS、Nginx、Elasticsearch、Logstatsh、FastDFS、OSS、Lombok 1.18.8、⭐Spring Cloud Greenwich.SR1 核心技术、Eureka、Ribbon、Feign、Hystrix、Config、Gateway、JWT 3.7.0、Sleuth、Zipkin 2.8.4、ELK 5.2、Stream、⭐Docker、⭐K8S、Istio、Knative、OpenToolbox、VMware。

数据库：MariaDB 10.4.8.1、HikariCP 数据源。

服务器系统：CentOS 7.4。

前端：Vue、JQuery、Html、Css、JavaScript。

开发环境：IntelliJ IDEA 开发工具、PDMan 2.2 数据库建模工具、Navicat Premium 数据库管理工具、VMware Fusion、CentOS 7、rdm、FileZilla、SecureCRT、V2RayX、WebStorm、DataGrip、PostMan、Jmeter、Mac OS 10.15 操作系统、Photoshop。

**业绩：**

1. ⭐前后端返回请求的数据格式不一致问题。请求方法不匹配问题。MyBatis 分页数据不正确问题。跨域配置 实现前后端联调问题。部署项目时 Tomcat 的新 Cookie 处理器问题。远程数据库表导入问题。
2. ⭐Nginx 找不到 PID 问题。CentOS 虚拟机克隆的网络问题。
3. ⭐用户修改完信息保证 Token 是最新的问题。前端 Get 请求携带 Headers 失效问题。 CAS 单点登陆前端 发起验证，后端获取不到 Cookie 问题。
4. ⭐Logstatsh 数据库同步版本不匹配问题。Logstash 自定义模板配置中文分词 Mappings 同步失效问题。
5. ⭐FastDFS 追踪服务器器无法访问问题。OSS 头像无法上传问题。
6. ⭐启动报 Ambiguous mapping 错误问题、yml 配置文件存储在 Github 无法加载配置问题。
7. ⭐引入 Bus 依赖 Zipkin 配置不起作用问题。retry 与 requeue 配置之间的冲突问题。Docker 部署微服务 Cookie 域设置问题。
8. ⭐CentOS 搭建 K8S 无法访问镜像问题、Ping 不通 ClusterIP 问题、cni0 网络错误问题、Master Ping 不通 Node 节点问题、ipv4 内核版本低问题、helm install 权限问题。
9. ⭐如何系统的开发一个单体、集群、分布式、微服务、容器化架构项目，大部分的项目都离不开内容中心系统、支付中心系统、用户中心系统， 系统内部的模块都是通用的，可以借鉴复用项目的通用系统模块开发其他项目。
10. ⭐Gateway 配置网关层 Redis 限流。了解可以通过防火墙、负载均衡、缓存、限流、K8S 弹性扩缩容技术 缓解 DDOS 攻击。
11. ⭐Config Server 使用对称性密钥进行 Github 配置 yml 文件 属性值进行加密与解密。
12. 搭建 Nginx 集群系统，Redis 主从复制读写分离架构作为数据库的保护屏障系统。
13. 项目分层设计。Swagger 2 后端接口 API 文档生成。PostMan 测试接口 API。云服务器前端后端项目部署与上线。

**💡 使用说明：**
```shell
# 克隆项目
git clone https://gitee.com/OpenDevel/java-for-linux.git

# 进入 foodie-dev 文件夹
cd foodie-dev

# 安装依赖并编译
mvn clean install

# 在 IDEA 里进行配置、修改、启动项目
```

**⭐webrtc-live 直播导购子项目**：（在 **WebRTC** 文件夹）。

**简介:**

此项目为 foodie-mall 吃货商城子项目，⭐主要是为客户提供直播指导用户购物，解答用户购物的问题，主播可以进行直播导购，客户可以观看直播导购优质服务。

**webrtc-live 直播导购核心系统模块：**

内容中心核心系统：开始直播核心模块、直播权限控制模块、观看直播核心模块、WebSocket 信令服务器模块、Bootstrap 前端直播模板模块。

⭐吃货商城内容中心系统：商城首页推荐直播导购模块、商品与直播推销商品关联模块。

⭐Vue 前后端分离直播系统重构，前后端分离不分离直播系统：重构内容中心核心系统、重构吃货商城内容中心系统。

⭐OpenVidu CE 生产级单体架构 WebRTC 直播系统重构 Vue 单体架构直播系统：提供生产级的 WebRTC 直播 SDK & API 服务，重构为兼容性强、生产环境、稳定版 WebRTC 直播系统。

⭐OpenVidu Pro 商业级集群架构 WebRTC 直播系统重构 OpenVidu CE 生产级单体架构直播系统：提供商用生产级 WebRTC 直播集群服务、后台监视服务，管理和查看所有视频会议服务、录音管理服务、会话历史记录服务、集群管理服务、客户地理位置服务、Elasticsearch & Kibana 可视化后台视频会议服务、录音管理服务、会话历史记录服务、集群管理服务，重构为可商用多人 WebRTC 直播系统。

**负责系统模块：**

1. ⭐负责实现 Java 信令服务器接收 KMS 流媒体服务器或客户端发来的 WebRTC 数据核心模块。
2. ⭐负责实现封装用户会话与流媒体元素、流媒体管道进行一对多直播核心模块。
3. 负责实现直播权限控制模块。
4. 负责实现 Bootstrap 前端直播模板改造整合作为前端页面模块。

**WebRTC 核心技术栈：**

采用前后端不分离到分离单体、集群、分布式、微服务、容器化架构开发模式。

后端：⭐Spring Boot 2.2.4、Spring、Spring MVC、Spring Security、⭐Spring WebSocket 核心技术、Kurento Client 6.14.1、Tomcat 9.0.24、JDK 8、Maven、Kurento Media Server、Coturn、VMware、⭐OpenVidu CE、⭐OpenVidu Pro。

服务器系统：CentOS 7.4。

前端：Bootstrap、Html、Css、JavaScript、JQuery、Vue、Kurento-utils、Sockjs-client、Stompjs、Webpack、openvidu-browser-2.17.0.js。

开发环境：IntelliJ IDEA 开发工具、FileZilla、SecureCRT、V2RayX、OpenToolbox、PostMan、Mac OS 10.15 操作系统。

**业绩：**

1. ⭐三层跨域问题。前后端开启 HTTPS 服务器问题。Chrome 浏览器无法访问 HTTPS 问题，Spring Security 登录接口返回数据格式问题。重构前后端分离 Kurento 的 Client 客户端通信问题。
2. ⭐重构项目为 Vue 前后端分离项目、前端使用 Vue 框架、前后端使用 STOMP 子协议通信。
3. ⭐阅读 WebRTC 开源技术英文文档。
4. ⭐传统的 WebRTC 直播，只适合一对一直播，不适合一对多直播。只有在服务器端搭建流媒体服务器把客户端流量转发到流媒体服务器，才适合一对多直播。
5. 云服务器项目搭建开源 KMS 流媒体服务器、开源 Coturn 穿透服务器部署与上线。
6. 为未来结合 5G 时代的高带宽、超低延时的特性做准备，赋予 WebRTC 低延时性能。

**💡 使用说明：**

```shell
# 克隆项目
git clone https://gitee.com/OpenDevel/java-for-linux.git
# 进入 webrtc 子项目文件夹
cd webrtc
# 安装依赖
mvn clean install
# 安装 KMS 流媒体服务器
docker pull kurento/kurento-media-server
# 运行 KMS 并把本地 8888 端口 映射到容器 8888 端口
docker run -itd --name kms --network host --restart always -p 8888:8888 kurento/kurento-media-server
# 安装 Coturn 服务器
git clong https://github.com/konoui/kurento-coturn-docker.git
cd kurento-coturn-docker     
cd  coturn
sudo docker build --tag coturn .
sudo docker run --name coturn -p 3478:3478 -p 3478:3478/udp coturn
docker exec -it kms /bin/bash
apt-get update
apt-get install vim
cd /etc/kurento/modules/kurento/
# 修改配置文件
vim WebRtcEndpoint.conf.ini
# 找到以下配置 并修改为
stunServerAddress=127.0.0.1
stunServerPort=3478
turnURL=kurento:kurento@127.0.0.1?transport=tcp
# 回到 webrtc 子项目目录 
cd java-for-linux
cd webrtc
cd target
# 启动项目
java -jar webrtc-6.14.1-SNAPSHOT.jar
# 打开 Chrome 浏览器访问
https://127.0.0.1:8443/admin.html
```

**⭐Java 泡泡堂子项目**：（在 **bubble-hall** 文件夹）。

**简介：**

⭐该项目是基于 C/S 架构休闲类型泡泡堂游戏，是一种由键盘操作的休闲小游戏，游戏控制简便，只要使用一个方向键控制方向，再加上一个空格键放置泡泡，5 个按键就可以进行游戏了。

**主要功能模块：**

⭐Control 模块包含游戏逻辑设计、游戏动作事件监听、Element 模块包含元素加载、管理元素、元素类型、Frame 模块包含窗口显示、元素图像渲染等模块。

**责任描述：**

1. ⭐负责小组之间合理的分配任务，检查小组任务完成情况。
2. 负责实现泡泡爆炸。
3. ⭐负责实现泡泡爆炸转换为泡泡波纹数组。
4. 负责实现箱子与泡泡爆炸碰撞摧毁。
5. ⭐负责实现泡泡波纹与泡泡爆炸碰撞形成连爆。

**技术描述：**

⭐采用 Java SE 核心架构开发模式。

项目主要利用的技术有 Java SE 1.8 核心技术、JLayer、⭐Swing、MSpaint、Photoshop。

开发环境：IntelliJ IDEA 开发工具、Windows 7。

**业绩：**

通过这个项目锻炼了 Java 面向对象分散式逻辑思维，排除不符合逻辑的编程思想，不同的类，在不同的包、不同的模块编写，而不是一个类写出所有游戏模块功能；⭐借鉴 Spring 框架 IOC、DL 思想，编写游戏元素对象加载类，元素对象管理器类，如何以高内聚低耦合的方式管理、加载游戏里各种对象资源；⭐当然作为组长最为重要的是，小组之间如何合理的分配任务了，共同的去完成这个项目。

**💡 使用说明：**

```shell
# 克隆项目
git clone https://gitee.com/OpenDevel/java-for-linux.git
cd bubble-hall
mvn clean install
cd target
# 启动项目
java -jar bubble-hall-1.0-SNAPSHOT.jar
```

**Java 2048 小游戏子项目**：（在 **2048** 文件夹里）。

**💡 使用说明：**

```shell
# 克隆项目
git clone https://gitee.com/OpenDevel/java-for-linux.git
cd 2048
mvn clean install
cd target
# 启动项目
java -jar 2048-1.0-SNAPSHOT.jar
```

**⭐其他 Java 开源子项目**：cppmm 子项目搜集了市面上 JVM 源码 所有研究资料、auto-homework 子项目使用 Selenium 库自动选择试卷选项题答题考卷（在 **cppmm** 文件夹 **auto-homework** 文件夹 **其他**文件夹）。

**💡 使用说明：**

[cppmm 子项目阅读地址](https://gitee.com/OpenDevel/java-for-linux/tree/master/cppmm)

### 负责实现 java-for-linux 综合型开源子项目：

1. 负责实现 Java 开源课程子项目。

2. 负责实现 Java 开源笔记子项目。

3. ⭐负责实现 OpenToolbox 仿黑客命令行终端工具子项目。

4. 负责实现其他 Java 开源子项目。

5. ⭐负责在开源指北项目贡献开源项目与自媒体结合理论与实际模块。

6. ⭐负责实现 webrtc-live 直播导购子项目。

7. ⭐负责实现 Java 泡泡堂游戏子项目。

8. 负责实现 Java 2048 小游戏子项目。

9. ⭐负责实现开发者英语子项目。

10. ⭐负责实现 cppmm 子项目。

### java-for-linux 综合型开源项目技术栈：

Gitee、Github、为知笔记、Bilibili、JetBrains、Teambition、Photoshop、IntelliJ IDEA、WebStorm、Mac OS 10.15 操作系统、OpenToolbox、百度搜索引擎、Google 搜索引擎。

### java-for-linux 综合型开源项目业绩：

1. ⭐解决了复杂的 JVM 源码写 C & C++ 内嵌级别 Native 函数问题、Linux 的 JNI 动态函数注册问题，为开源社区提供了研究 Java Native 层函数源码解决方案。
2. ⭐Java 写内存级别游戏安全解决方案。Java 如何进行图像识别问题。正确理解 C 语言指针问题。
3. ⭐积累 1 年 Java 开源项目实战经验
4. ⭐获得 Gitee 官方开源指北项目贡献纸质证书 T 恤 并在开源指北电子书编写成员栏署名 成为该项目的优质贡献者 成为其他开源爱好者的开源项目贡献者。
5. ⭐使用 java-for-linux 综合型开源项目申请了 JetBrains 开源许可证 可以免费使用 JetBrains 全家桶所有产品 IntelliJ IDEA DataGrip WebStorm Clion TeamCity 等 使用 JetBrains 各种工具集成到 IntelliJ IDEA 工具里。
6. ⭐制作专业 Java 开发者 Logo 头像 开发专业的仿黑客命令行工具 成为更加专业的 Java 开发者。
7. ⭐学习阅读英文技术文档基础。学习 Github、Gitee 版本控制软件的使用。

### java-for-linux 综合型开源项目链接：

[⭐java-for-linux 综合型开源项目](https://gitee.com/OpenDevel/java-for-linux)

[⭐java-for-linux 综合型开源项目创作号](https://space.bilibili.com/77266754)

[⭐开源指北仓库](https://gitee.com/gitee-community/opensource-guide)

[⭐开源指北阅读首页](https://gitee.com/opensource-guide/)

[⭐开源指北 VLOG](https://www.bilibili.com/video/BV1pU4y147Fu)

[⭐演示地址](https://www.bilibili.com/video/BV1qK411u7w6)

### java-for-linux 综合型开源项目资格证书：

**JetBrains 开源许可证**认证者。

![image](https://gitee.com/OpenDevel/java-for-linux/raw/master/image/01-证书.png)

![image](https://gitee.com/OpenDevel/java-for-linux/raw/master/image/02-证书.png)

**Gitee 官方开源指北项目**贡献者。

![image](https://gitee.com/OpenDevel/java-for-linux/raw/master/image/03-证书.png)


# 开源项目

![image](https://gitee.com/OpenDevel/java-for-linux/raw/master/image/OpenProject.jpeg)

[开源项目观看地址](https://space.bilibili.com/77266754/channel/detail?cid=160074)

## 开源工具箱 开源项目

![image](https://gitee.com/OpenDevel/java-for-linux/raw/master/image/OpenToolbox-00.png)

![image](https://gitee.com/OpenDevel/java-for-linux/raw/master/image/OpenToolbox-01.png)

项目地址：

[OpenToolbox](https://gitee.com/OpenDevel/java-for-linux/tree/master/OpenToolbox)

[项目观看地址](https://www.bilibili.com/video/BV1MK4y1L7nU)

## 电商

......

文件夹：

[foodie-center](https://gitee.com/OpenDevel/java-for-linux/tree/master/foodie-center)

[foodie-cloud](https://gitee.com/OpenDevel/java-for-linux/tree/master/foodie-cloud)

[foodie-dev](https://gitee.com/OpenDevel/java-for-linux/tree/master/foodie-dev)

[foodie-payment](https://gitee.com/OpenDevel/java-for-linux/tree/master/foodie-payment)

[foodie-shop](https://gitee.com/OpenDevel/java-for-linux/tree/master/foodie-shop)

[nginx-url-hash](https://gitee.com/OpenDevel/java-for-linux/tree/master/nginx-url-hash)

[mybatis-generator](https://gitee.com/OpenDevel/java-for-linux/tree/master/mybatis-generator-for-imooc)

[sso-mtv](https://gitee.com/OpenDevel/java-for-linux/tree/master/sso-mtv)

[sso-music](https://gitee.com/OpenDevel/java-for-linux/tree/master/sso-music)

[java-for-gitee](https://gitee.com/OpenDevel/java-for-linux/tree/master/java-for-gitee)

## exagear-desktop-rpi3

文件夹：

[exagear-desktop-rpi3](https://gitee.com/OpenDevel/java-for-linux/tree/master/exagear-desktop-rpi3)

[文章地址](https://www.bilibili.com/read/cv8446499)

[下载地址](https://github.com/OSrcD/java-for-linux/releases/tag/0.0.3)

## WebRTC 一对多直播项目 开源项目

![image](https://gitee.com/OpenDevel/java-for-linux/raw/master/image/WebRTC.png)

项目地址：

[webrtc](https://gitee.com/OpenDevel/java-for-linux/tree/master/webrtc)

[webrtc-live](https://gitee.com/OpenDevel/java-for-linux/tree/master/webrtc-live) (Vue 重构版 还在开发当中)

[项目观看地址](https://www.bilibili.com/video/BV15t4y1e7PJ)

[观众端线上体验地址](https://120.77.47.215:8443/)

[主播端线上体验地址](https://120.77.47.215:8443/admin.html)

## 在线教育
......

文件夹：

[online-education](https://gitee.com/OpenDevel/java-for-linux/tree/master/online-education/course)

## 社交分享

......

文件夹：

[social-sharing](https://gitee.com/OpenDevel/java-for-linux/tree/master/social-sharing)

## 电影预告

......

文件夹：

[movie-trailer](https://gitee.com/OpenDevel/java-for-linux/tree/master/movie-trailer)

## OA 办公

......

文件夹：

[oa](https://gitee.com/OpenDevel/java-for-linux/tree/master/oa)

## Java 泡泡堂 开源项目

![image](https://gitee.com/OpenDevel/java-for-linux/raw/master/image/bubble-hall.png)

项目地址：

[bubble-hall](https://gitee.com/OpenDevel/java-for-linux/tree/master/bubble-hall)

[项目观看地址](https://www.bilibili.com/video/BV1Xa4y1t7sS)

## Java 2048 小游戏 开源项目

![image](https://gitee.com/OpenDevel/java-for-linux/raw/master/image/2048.png)

项目地址：

[2048](https://gitee.com/OpenDevel/java-for-linux/tree/master/2048)

[项目观看地址](https://www.bilibili.com/video/BV19e411x7F2)

## C++-- 开源项目

可以看第三方实现精简版的 JVM 1.2 虚拟机源码 只有一个 C++ 小项目的代码量 OpenJDK 源码太复杂 1.6 版本才开源 代码量很庞大 不利于研究 这是一种学习技巧。

微软的 JVM 虚拟机是 1.1 版本的 不开源 被 SUN 公司起诉了 1.0 版本 JVM 源码 只有 SUN 公司有了。

项目地址：

[cppmm](https://gitee.com/OpenDevel/java-for-linux/tree/master/cppmm)

# 开源笔记

项目地址：

[Thoughts 开源笔记](https://thoughts.teambition.com/sharespace/60b31958a2aa01004a28b7dc)

## 开发者英语笔记

![image](https://gitee.com/OpenDevel/java-for-linux/raw/master/image/programmer-for-english-00.png)

项目地址：

[开发者英语笔记](https://www.wiz.cn/wapp/pages/applyJoinGroup?code=glfvvh)

# 开源课程

![image](https://gitee.com/OpenDevel/java-for-linux/raw/master/image/OpenCourse.jpeg)

[开源课程观看地址](https://space.bilibili.com/77266754)

## Java 游戏安全 开源课程

![image](https://gitee.com/OpenDevel/java-for-linux/raw/master/image/java-game-security.png)

项目地址：

[java-game-securit](https://gitee.com/OpenDevel/java-for-linux/tree/master/java-game-security)

[该课程观看地址](https://www.bilibili.com/video/BV1nQ4y1T7yp)

## JNI 基于 Linux 动态函数注册 开源课程

![image](https://gitee.com/OpenDevel/java-for-linux/raw/master/image/jni-dynamic-register-for-linux.png)

项目地址：

[jni-dynamic-register-for-linux](https://gitee.com/OpenDevel/java-for-linux/tree/master/jni-dynamic-register-for-linux)

[该课程观看地址](https://www.bilibili.com/read/cv7893718)

## Kali Linux 内核编程 开源课程

![image](https://gitee.com/OpenDevel/java-for-linux/raw/master/image/kali-linux-kernel-programming.png)

项目地址：

[kali-linux-kernel-programming](https://gitee.com/OpenDevel/java-for-linux/tree/master/kali-linux-kernel-programming)

[该课程观看地址](https://www.bilibili.com/read/cv8504716)

## 基于 Java For OpenCV 的百度云失效链接自动分享 开源课程

![image](https://gitee.com/OpenDevel/java-for-linux/raw/master/image/baidu-cloud-auto-share-link.png)

![image](https://gitee.com/OpenDevel/java-for-linux/raw/master/image/baidu-cloud-auto-share-link-02.png)

项目地址：

[baidu-cloud-auto-share-link](https://gitee.com/OpenDevel/java-for-linux/tree/master/baidu-cloud-auto-share-link)

[opencv-for-linux](https://gitee.com/OpenDevel/java-for-linux/tree/master/opencv-for-linux)

[tesseract-for-linux](https://gitee.com/OpenDevel/java-for-linux/tree/master/tesseract-for-linux)

[该课程观看地址](https://www.bilibili.com/video/BV1po4y1f7eq)

## 像 JDK 开发团队一样开发 Java（在 JVM 源码内嵌写 Native 函数给 Java 层调用）

[JVM 系列课程观看地址](https://www.bilibili.com/video/BV1DD4y1U7k6)

### JVM 源码之写 Java 层代码 开源课程

![image](https://gitee.com/OpenDevel/java-for-linux/raw/master/image/jvm-library-extend-01.png)

[该课程观看地址](https://www.bilibili.com/video/BV1Zz4y1k7Mj)

### JVM 源码之导出模块 开源课程

![image](https://gitee.com/OpenDevel/java-for-linux/raw/master/image/jvm-library-extend-02.png)

[该课程观看地址](https://space.bilibili.com/77266754/channel/detail?cid=160075)

### JVM 源码 之写 C++ 层代码 开源课程

![image](https://gitee.com/OpenDevel/java-for-linux/raw/master/image/jvm-library-extend-03.png)

[该课程观看地址](https://www.bilibili.com/video/BV1xZ4y1g7A9)

### JVM 源码之注册 Java & C++ 层代码 开源课程

![image](https://gitee.com/OpenDevel/java-for-linux/raw/master/image/jvm-library-extend-04.png)

[该课程观看地址](https://www.bilibili.com/video/BV1mv411b7SE)

### JVM 源码之写 MakeFile 文件 开源课程

![image](https://gitee.com/OpenDevel/java-for-linux/raw/master/image/jvm-library-extend-05.png)

![image](https://gitee.com/OpenDevel/java-for-linux/raw/master/image/jvm-library-extend-06.png)

[该课程观看地址](https://www.bilibili.com/video/BV1zV41187j7)

### JVM 源码之编译生成的文件 开源课程

![image](https://gitee.com/OpenDevel/java-for-linux/raw/master/image/jvm-library-extend-07.png)

![image](https://gitee.com/OpenDevel/java-for-linux/raw/master/image/jvm-library-extend-08.png)

![image](https://gitee.com/OpenDevel/java-for-linux/raw/master/image/jvm-library-extend-09.png)

[该课程观看地址](https://www.bilibili.com/video/BV1Ff4y1i72H)

### JVM 源码之写 Java 测试代码 开源课程

![image](https://gitee.com/OpenDevel/java-for-linux/raw/master/image/jvm-library-extend-10.png)

![image](https://gitee.com/OpenDevel/java-for-linux/raw/master/image/jvm-library-extend-11.png)

[该课程观看地址](https://www.bilibili.com/video/BV1Ff4y1i72H)

JVM 系列的项目地址：

[openjdk-for-linux](https://gitee.com/OpenDevel/java-for-linux/tree/master/%E5%BC%80%E6%BA%90%E5%AD%90%E4%BB%93%E5%BA%93/openjdk-for-linux)

## auto-homework

项目地址：

[auto-homework](https://gitee.com/OpenDevel/java-for-linux/tree/master/auto-homework)

# 开源赞赏

## 微信赞赏码

![image](https://gitee.com/OpenDevel/java-for-linux/raw/master/image/赞赏码.png)

# LICENSE

使用 Apache2.0 开源许可协议 

# 鸣谢

foodie-mall 吃货商城项目库（foodie-center foodie-cloud foodie-dev foodie-payment foodie-shop mybatis-generator nginx-url-hash sso-mtv sso-music 文件夹）

来自慕课网 Java 架构师-技术专家

movie-trailer 电影预告项目库（movie-trailer 文件夹）

来自腾讯课堂 uni-app 商业级应用实战

OA 办公项目库（oa 文件夹）

来自 慕课网 Java 工程师 2018 版

online-education 在线教育项目库（online-education 文件夹）

来自 慕课网 Spring Cloud + Vue 前后端分离 开发企业级在线视频课程系统

social-sharing 社交分享项目库 （social-sharing 文件夹）

来自 慕课网 Spring Cloud Alibaba 微服务从入门到进阶

来自 GitHub MyJacking 开源作者
