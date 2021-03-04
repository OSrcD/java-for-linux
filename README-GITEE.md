<div align="center"><img width="200" src="https://gitee.com/OpenDevel/java-for-linux/raw/master/image/logo.png"/>
<h1> java-for-linux: Welcome to Internet </h1>
</div>


## 仓库简介

这个仓库是 **java-for-linux 综合型开源项目** 就是把自己开发的**多个开源项目集成**在一起维护 **为什么**要集成在**一起维护** 因为玩 **10 个开源项目仓库** 还不如**精一个 开源项目仓库**
与编程相关的内容都会存放到 这个仓库里 目前有 **6+ 个开源项目** 涉及一直要不断复习 开发 改造 维护 两个主要的子项目 写一些开源笔记 开发或维护一些辅助编程小工具 录制一些开源课程
与其他开源项目合作 一直要研究的 JVM JDK 相关源码等。

### java-for-linux 综合型开源子项目：

**开源课程子项目**：Java 写游戏安全、基于 Linux 的 JNI 动态函数注册、Kali Linux 内核编程、基于 Java For OpenCV 的百度云失效链接自动分享、在 JVM 源码内嵌写 Native 函数给 Java 层调用、C 语言指针、Java 泛型反编译（在开源**课程**文件夹）。

**开源笔记子项目**：阅读英文技术文档基础、Docker、Kubernetes、Elasticsearch、FastDFS、OSS、Spring Cloud、Vultr 搭建加速器、互联网视频高效率学习技巧、DDOS 防御、Nginx、Redis、RocketMQ、Java 语法基础、Web 入门、Java 后台数据库、Java SSM框架、Spring Boot 等（在开源**笔记**文件夹）。

**OpenToolbox 子项目：**（在 **OpenToolbox** 文件夹）。

**简介：**

仿黑客命令行终端工具 一个辅助编程小工具 是一款终端命令小工具 用于敲 Linux 命令 敲各种软件的命令行命令 使用 SSH 命令连接服务器 可以多开窗口。

**OpenToolbox 主要功能模块：**

命令行输入输出组件模块。

多开窗口模块。

自定义黑色的标题栏，不要系统自带的标题栏模块。

hacker工具箱模块。

爬虫、爬取最新的网络安全新闻显示到GUI模块。

Hacker学习路线、hacking指令搜索模块。

**负责系统模块：**

1. 负责实现命令行输入输出组件模块。

2. 负责实现多开窗口模块。

**OpenToolbox 核心技术栈：**

node-pty、electron、vue、xterm。

**业绩：**

成为更加专业的开发者。

**开源指北开源项目**：参与 Gitee 官方开源项目 贡献开源项目与自媒体结合实战经验。

**iooc-admin 后台权限管理系统开源子项目**：与其他开源爱好者合作、贡献开源项目宣传、开源项目介绍教程、开源项目文档、开源项目入门（在 **iooc-vue-admin** 文件夹）。

**WebRTC 直播子项目**：（在 **WebRTC** 文件夹）。

**简介:**

此项目为直播子项目，主要是为客户提供直播指导用户购物，解答用户购物的问题，主播可以进行直播导购，客户可以观看直播导购优质服务。

**WebRTC 核心系统模块：**

内容中心核心系统：开始直播核心模块、直播权限控制模块、观看直播核心模块、WebSocket 信令服务器模块、Bootstrap 前端直播模板模块。

**负责系统模块：**

1. 负责实现 Java 信令服务器接收 KMS 流媒体服务器或客户端发来的 WebRTC 数据核心模块。
2. 负责实现封装用户会话与流媒体元素、流媒体管道进行一对多直播核心模块。
3. 负责实现直播权限控制模块。
4. 负责实现 Bootstrap 前端直播模板改造整合作为前端页面模块。

**WebRTC 核心技术栈：**

采用前后端从不分离到分离单体架构开发模式。

后端：Spring Boot 2.2.4、Spring、Spring MVC、Spring Security、Spring WebSocket 核心技术、Kurento Client 6.14.1、Tomcat 9.0.24、JDK 8、Maven、Kurento Media Server、Coturn。

服务器系统：CentOS 7.4。

前端：Bootstrap、Html、Css、JavaScript、JQuery、Vue、Kurento-utils、Sockjs-client、Stompjs、Webpack。

开发环境：IntelliJ IDEA 开发工具、FileZilla、SecureCRT、PostMan、Mac OS 10.15 操作系统。

**业绩：**

1. 重构前后端分离 Kurento 的 Client 客户端通信问题。三层跨域问题。前后端开启 HTTPS 服务器问题。Chrome 浏览器无法访问 HTTPS 问题，Spring Security 登录接口返回数据格式问题。
2. 重构项目为前后端分离项目、前端使用 Vue 框架、前后端使用 STOMP 子协议通信。
3. 阅读 WebRTC 开源技术英文文档。
4. 云服务器项目搭建开源 KMS 流媒体服务器、开源 Coturn 穿透服务器部署与上线。
5. 为未来结合 5G 时代的高带宽、超低延时的特性做准备，赋予 WebRTC 低延时性能。
6. 传统的 WebRTC 直播，只适合一对一直播，不适合一对多直播。只有在服务器端搭建流媒体服务器把客户端流量转发到流媒体服务器，才适合一对多直播。

**泡泡堂子项目**：（在 **bubble-hall** 文件夹）。

**简介：**

该项目是基于C/S架构休闲类型泡泡堂游戏，是一种由键盘操作的休闲小游戏，游戏控制简便，只要使用一个方向键控制方向，再加上一个空格键放置泡泡，5个按键就可以进行游戏了。

**主要功能模块：**
   
Control模块包含游戏逻辑设计，游戏动作事件监听，Element模块包含元素加载、管理元素，元素类型，Frame模块包含窗口显示，元素图像渲染等模块。

**责任描述：**

1. 负责小组之间合理的分配任务，检查小组任务完成情况。
2. 负责实现泡泡爆炸。
3. 负责实现泡泡爆炸转换为泡泡波纹数组。
4. 负责实现箱子与泡泡爆炸碰撞摧毁。
5. 负责实现泡泡波纹与泡泡爆炸碰撞形成连爆。

**技术描述：**

采用Java SE 核心架构开发模式。

项目主要利用的技术有Java SE 1.8 核心技术、JLayer，Swing，MSpaint、Photoshop。

开发环境：IntelliJ IDEA开发工具、Windows 7。

**业绩：**

通过这个项目锻炼了Java面向对象分散式逻辑思维，排除不符合逻辑的编程思想，不同的类，在不同的包、不同的模块编写，而不是一个类写出所有游戏模块功能；借鉴Spring框架IOC、DL思想，编写游戏元素对象加载类，元素对象管理器类，如何以高内聚低耦合的方式管理、加载游戏里各种对象资源；当然作为组长最为重要的是，小组之间如何合理的分配任务了，共同的去完成这个项目。

**2048 小游戏子项目**：（在 **2048** 文件夹里）。

**其他开源子项目**：cppmm 子项目搜集了市面上 JVM 源码 所有研究资料、auto-homework 子项目使用 Selenium 库自动选择试卷选项题答题考卷（在 **cppmm** 文件夹 **auto-homework** 文件夹 **其他**文件夹）。

### 负责实现 java-for-linux 综合型开源子项目：

1. 负责实现开源课程子项目。

2. 负责实现开源笔记子项目。

3. 负责实现 OpenToolbox 子项目。

4. 负责实现其他开源子项目。

5. 负责在开源指北项目贡献开源项目与自媒体结合实战经验

6. 负责实现 WebRTC 直播子项目

7. 负责实现 泡泡堂子项目

8. 负责实现 2048 小游戏子项目

### java-for-linux 综合型开源项目技术栈：

Gitee、Github、为知笔记、Bilibili、JetBrains、Teambition、Photoshop、IntelliJ IDEA、WebStorm、Mac OS 10.15 操作系统、OpenToolbox、百度搜索引擎、Google 搜索引擎。

### java-for-linux 综合型开源项目业绩：

1. 获得 JetBrains 开源许可证 可以免费使用 JetBrains 全家桶所有产品 IntelliJ IDEA DataGrip WebStorm
   Clion TeamCity 等 使用 JetBrains 各种工具集成到 IntelliJ IDEA 工具里。

2. 获得 Gitee 官方开源指北项目贡献纸质证书 T恤 并在开源指北电子书编写成员栏署名 成为该项目的优质贡献者 成为其他开源爱好者的开源项目贡献者。

3. 开源的收入来源 开源赞赏。

4. 与其他开源爱好者的开源项目合作 收获了一群开源爱好者朋友 。

5. 学习 Git Gitee 版本控制软件的使用 代码托管到 Git Gitee 方便复习代码。

6. 自媒体开源课程与开源项目结合 建立交流群 传播开源入门知识 贡献自己一点点的开源贡献。

7. 制作专业 Logo 头像 开发专业开发者小工具 成为更加专业的开发者。

### java-for-linux 综合型开源项目链接：

[java-for-linux 综合型开源项目。](https://gitee.com/opendevel/java-for-linux)

[java-for-linux 综合型开源项目创作号。](https://space.bilibili.com/77266754)

[开源指北开源项目。](https://gitee.com/gitee-community/opensource-guide)

[iooc-admin后台权限管理系统开源项目。](https://gitee.com/OpenDevel/java-for-linux/tree/master/iooc-vue-admin)

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

[java-for-alibaba](https://gitee.com/OpenDevel/java-for-linux/tree/master/java-for-alibaba)

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

## 2048 小游戏 开源项目

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

[Teambition 开源笔记](https://tburl.in/0jDNvpbK)

[Gitee 开源笔记](https://gitee.com/OpenDevel/java-for-linux/tree/master/%E5%BC%80%E6%BA%90%E7%AC%94%E8%AE%B0)

## OSrcD 的英语小抄 开源笔记

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

## JVM 源码内嵌写 Native 函数给 Java 层调用 开源课程

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

[openjdk-for-linux](https://gitee.com/OpenDevel/java-for-linux/tree/master/openjdk-for-linux)

## auto-homework

项目地址：

[auto-homework](https://gitee.com/OpenDevel/java-for-linux/tree/master/auto-homework)

## TS JS 双版本前端通用后台权限管理系统开源项目（Vue 3.x TypeScript element-plus）

项目地址：

[iooc-admin](https://github.com/MyJacking/iooc-vue-admin)

[项目观看地址](https://www.bilibili.com/video/BV1qK411u7w6)

# 开源项目交流群

## java-for-linux & iooc-admin 开源项目 交流群

**QQ 群**号 : **741396149**

![image](https://gitee.com/OpenDevel/java-for-linux/raw/master/image/group.png)

# 开源赞赏

## 微信赞赏码

![image](https://gitee.com/OpenDevel/java-for-linux/raw/master/image/赞赏码.png)

## LICENSE

使用 Apache2.0 开源许可协议 
