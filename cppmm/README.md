# cppmm



cppmm 是 C++-- 其实 Java 就是 C++ 的简化版 在 C++ 的基础上进行简化 所以就是 C++--



## 编程健康指南



## 科学上网指南


## 社会工程学



### Google Hacking



## 追溯技术历史


## JVM 前世今生



### JAVA 1.0 代号 Oak（橡树）

#### 1996-01-23 发行

### JAVA 1.1

#### 1997-02-19 发行,主要更新内容：

引入JDBC

添加内部类支持

引入JAVA BEAN

引入RMI

引入反射

### JAVA 1.2 代号 Playground（操场）

#### 1998-12-8 发行，主要更新内容：

引入集合框架

对字符串常量做内存映射

引入JIT（Just In Time）编译器

引入打包文件数字签名

引入控制授权访问系统资源策略工具

引入JFC（Java Foundation Classes），包括Swing1.0，拖放和Java2D类库

引入Java插件

JDBC中引入可滚动结果集，BLOB,CLOB,批量更新和用户自定义类型

Applet中添加声音支持

### JAVA 1.3 代号 Kestrel（红隼）

#### 2000-5-8 发布，主要更新内容：

引入Java Sound API

引入jar文件索引

对Java各方面多了大量优化和增强

Java Platform Debugger Architecture用于 Java 调式的平台。

JAVA 1.4 代号 Merlin（隼）

#### 2004-2-6 发布（首次在 JCP 下发行），主要更新内容：

添加XML处理

添加Java打印服务（Java Print Service API）

引入Logging API

引入Java Web Start

引入JDBC 3.0 API

引入断言

引入Preferences API

引入链式异常处理

支持IPV6

支持正则表达式

引入Image I/O API

NIO，非阻塞的 IO，优化 Java 的 IO 读取。

### JDK 5.0 代号 Tiger（老虎），有重大改动

#### 2004-9-30 发布 主要更新内容：

引入泛型

For-Each循环 增强循环，可使用迭代方式

自动装箱与自动拆箱

引入类型安全的枚举

引入可变参数

添加静态引入

引入注解

引入Instrumentation

提供了 java.util.concurrent 并发包。

### JDK 6 代号 Mustang（野马）

#### 2006-12-11 发布，主要更新内容：

引入了一个支持脚本引擎的新框架（基于 Mozilla Rhino 的 JavaScript 脚本引擎）

UI的增强

对WebService支持的增强（JAX-WS2.0 和 JAXB2.0）

引入JDBC4.0API

引入Java Compiler API

通用的Annotations支持

### JDK 7 代号 Dolphin（海豚）

#### 2011-07-28 发布 这是 sun 被 oracle 收购（2009 年 4 月）后的第一个版本，主要更新内容：

switch语句块中允许以字符串作为分支条件

在创建泛型对象时应用类型推断,比如你之前版本使用泛型类型时这样写 ArrayList<User> userList= new ArrayList<User>();，这个版本只需要这样写 ArrayList<User> userList= new ArrayList<>();，也即是后面一个尖括号内的类型，JVM 帮我们自动类型判断补全了。

在一个语句块中捕获多种异常

添加try-with-resources语法支持，使用文件操作后不用再显示执行close了。

支持动态语言

JSR203, NIO.2,AIO,新I/O文件系统，增加多重文件的支持、文件原始数据和符号链接,支持ZIP文件操作

JDBC规范版本升级为JDBC4.1

引入Fork/Join框架，用于并行执行任务

支持带下划线的数值，如 int a = 100000000;，0 太多不便于人阅读，这个版本支持这样写 int a = 100_000_000，这样就对数值一目了然了。

Swing组件增强（JLayer,Nimbus Look Feel…）参考

### JDK 8

#### 2014-3-19 发布 oracle 原计划 2013 年发布，由于安全性问题两次跳票，是自 JAVA 5 以来最具革命性的版本，主要更新内容：

接口改进，接口居然可以定义默认方法实现和静态方法了。

引入函数式接口

引入Lambda表达式

引入全新的Stream API，提供了对值流进行函数式操作。

引入新的Date-Time API

引入新的JavaScrpit引擎Nashorn

引入Base64类库

引入并发数组（parallel）

添加新的Java工具：jjs、jdeps

JavaFX，一种用在桌面开发领域的技术

静态链接 JNI 程序库

### JDK 9

#### 2017-9-21 发布

模块化（jiqsaw）

交互式命令行（JShell）

默认垃圾回收期切换为G1

进程操作改进

竞争锁性能优化

分段代码缓存

优化字符串占用空间

### JDK 10

#### 2018-3-21 发布

JEP286，var 局部变量类型推断。

JEP296，将原来用 Mercurial 管理的众多 JDK 仓库代码，合并到一个仓库中，简化开发和管理过程。

JEP304，统一的垃圾回收接口。

JEP307，G1 垃圾回收器的并行完整垃圾回收，实现并行性来改善最坏情况下的延迟。

JEP310，应用程序类数据 (AppCDS) 共享，通过跨进程共享通用类元数据来减少内存占用空间，和减少启动时间。

JEP312，ThreadLocal 握手交互。在不进入到全局 JVM 安全点 (Safepoint) 的情况下，对线程执行回调。优化可以只停止单个线程，而不是停全部线程或一个都不停。

JEP313，移除 JDK 中附带的 javah 工具。可以使用 javac -h 代替。

JEP314，使用附加的 Unicode 语言标记扩展。

JEP317，能将堆内存占用分配给用户指定的备用内存设备。

JEP317，使用 Graal 基于 Java 的编译器，可以预先把 Java 代码编译成本地代码来提升效能。

JEP318，在 OpenJDK 中提供一组默认的根证书颁发机构证书。开源目前 Oracle 提供的的 Java SE 的根证书，这样 OpenJDK 对开发人员使用起来更方便。

JEP322，基于时间定义的发布版本，即上述提到的发布周期。版本号为$FEATURE.$INTERIM.$UPDATE.$PATCH，分别是大版本，中间版本，升级包和补丁版本。

### JDK  11

#### 2018-9-25 发布

官网公开的 17 个 JEP（JDK Enhancement Proposal 特性增强提议）

JEP181: Nest-Based Access Control（基于嵌套的访问控制）

JEP309: Dynamic Class-File Constants（动态的类文件常量）

JEP315: Improve Aarch64 Intrinsics（改进 Aarch64 Intrinsics）

JEP318: Epsilon: A No-Op Garbage Collector（Epsilon 垃圾回收器，又被称为”No-Op（无操作）”回收器）

JEP320: Remove the Java EE and CORBA Modules（移除 Java EE 和 CORBA 模块，JavaFX 也已被移除）

JEP321: HTTP Client (Standard)

JEP323: Local-Variable Syntax for Lambda Parameters（用于 Lambda 参数的局部变量语法）

JEP324: Key Agreement with Curve25519 and Curve448（采用 Curve25519 和 Curve448 算法实现的密钥协议）

JEP327: Unicode 10

JEP328: Flight Recorder（飞行记录仪）

JEP329: ChaCha20 and Poly1305 Cryptographic Algorithms（实现 ChaCha20 和 Poly1305 加密算法）

JEP330: Launch Single-File Source-Code Programs（启动单个 Java 源代码文件的程序）

JEP331: Low-Overhead Heap Profiling（低开销的堆分配采样方法）

JEP332: Transport Layer Security (TLS) 1.3（对 TLS 1.3 的支持）

JEP333: ZGC: A Scalable Low-Latency Garbage Collector (Experimental)（ZGC：可伸缩的低延迟垃圾回收器，处于实验性阶段）

JEP335: Deprecate the Nashorn JavaScript Engine（弃用 Nashorn JavaScript 引擎）

JEP336: Deprecate the Pack200 Tools and API（弃用 Pack200 工具及其 API）

### JDK 12

#### 2019-3-19 发布

JEP189:Shenandoah: A Low-Pause-Time Garbage Collector (Experimental)

JEP230:Microbenchmark Suite

JEP325:Switch Expressions (Preview)

JEP334:JVM Constants API

JEP340:One AArch64 Port, Not Two

JEP341:Default CDS Archives

JEP344:Abortable Mixed Collections for G1

JEP346:Promptly Return Unused Committed Memory from G1

### JDK 13

#### 2019-9-17 发布

JEP350:Dynamic CDS Archives

JEP351:ZGC: Uncommit Unused Memory

JEP353:Reimplement the Legacy Socket API

JEP354:Switch Expressions

JEP355:Text Blocks

### JDK 14

#### 预计 2020-03-17 General Availability

JEP 305: Pattern Matching for instanceof (Preview)

JEP 358: Helpful NullPointerExceptions

JEP 361: Switch Expressions (Standard)

JEP 345: NUMA-Aware Memory Allocation for G1

JEP 349: JFR Event Streaming

JEP 366: Deprecate the ParallelScavenge + SerialOld GC Combination

JEP 363: Remove the CMS Garbage Collector

JEP 364: ZGC on macOS

JEP 368: Text Blocks (Second Preview)

## 参考文献

### JVM&C&C++&Linux 强强联合

### JVM 篇

#### Java 的 JNI 篇书籍大全

Essential Jni: Java Native Interface 出版年: 1998-3



Java(TM) Native Interface 出版年: 1999-06-20



Professional Java Native Interfaces with SWT/JFace (Programmer to Programmer) 出版年: 2005-02-11



Java AWT Native Interface 页数: 18



Java Native Interface 页数: 112



Java Native Access 页数: 112



IBM JNI



JNI



JNA（JNI的框架）



JNR（JNI的框架）



#### 安卓 NDK 篇书籍大全

细说Android 4.0 NDK编程（推荐PC阅读） 出版时间：2012-07-01



Android NDK Game Development Cookbook 出版时间：2013-11-25



Android C++高级编程：使用NDK [Pro Android C++ with the NDK] 出版时间：2014-01-01



Android NDK: Beginner's Guide - Second Edition 出版时间：2015-04-28



Mastering Android NDK 出版时间：2015-09-30



#### Java 虚拟机书籍大全

Java 虚拟机规范 出版年: 1996-12-01



Java Virtual Machine (Java Series) 出版年: 1997-04-01



Java虚拟机规范 出版年: 1997-10



The Java™ Virtual Machine Specification 出版年: 1999-4-24



Programming for the Java™ Virtual Machine 出版年: 1999-7-2



Proceedings of the Java Virtual Machine Research and Technology Symposium (JVM'01) 



April 23-24, 2001 Monterey, California USA 出版时间：2001-1-1



Java and the Java Virtual Machine 出版年: 2001-6-27



2nd Java Virtual Machine Reasearch and Technology Symposium (JVM '02) 出版年: 2002



深入嵌入式Java虚拟机 出版年: 2003-5-1



嵌入式Java虚拟机及其应用研究



深入Java虚拟机(原书第2版) 出版年: 2003-9



A Real-Time Java Virtual Machine for Avionics (Preprint)  出版时间：2006-1-1



IBM Technology for Java Virtual Machine in IBM i5/OS 出版时间：2007-2-14



Java Virtual Machine 出版年: 2009-12-30



Principles of Computer Organization and Assembly Language (2-downloads): Using the Java Virtual Machine Kindle电子书 出版时间：2011年1月11日



Java Virtual Machine 出版年: 2011-9



Kaffe Real-Time JVM (英语) 出版时间：2013-3-22



Understanding Java Virtual Machine 出版年: 2013-3-31



Java虚拟机并发编程 出版时间：2013-05-01



解析Java虚拟机开发 出版年: 2013-5-1



Java虚拟机规范（Java SE 7版） [The Java Virtual Machine Specification] 出版时间：2013-12-01



HotSpot实战 出版时间：2014-03-01



Java虚拟机精讲 出版时间：2015-05-01



Java核心技术系列：Java虚拟机规范（Java SE 8版） [The Java Virtual Machine 



Specification Jave SE 8 Edition] 出版时间：2015-06-01



OpenJDK Cookbook 出版时间：2015-01-30



自己动手写Java虚拟机 出版时间：2016-06-01



深入理解JVM ＆ G1 GC 出版时间：2017-06-01



揭秘Java虚拟机：JVM设计原理与实现 出版时间：2017-06-01



 Java虚拟机基础教程 出版时间：2018-02-01



Optimizing Java: Practical Techniques for Improving JVM Application Performance (英语)  出版时间：2018-5-11



Java virtual machine Second Edition Kindle电子书 出版时间：2018-6-10



JVM Tutorials - Herong's Tutorial Examples Kindle电子书 出版时间：2018-6-29



JRockit权威指南 深入理解JVM 出版时间：2019-01-01



JVM G1源码分析和调优 出版时间：2019-04-01



实战Java虚拟机：JVM故障诊断与性能优化（第2版） 出版时间：2019-07-01



深入理解Java虚拟机：JVM高级特性与最佳实践（第3版） 出版时间：2019-12-01



虚拟机设计与实现 以JVM为例 出版时间：2020-01-01



深入浅出：Java虚拟机设计与实现 出版时间：2020-04-01



深入理解JVM字节码 出版时间：2020-06-01


Microsoft Java Virtual Machine 页数: 88 JVM 1.1 闭源



A Dynamic Compiler for an Embedded Java Virtual Machine 页数: 96



Serializable Coroutines for Java Virtual Machines 页数: 104



Java Virtual Machine, Including 页数: 106



Openjdk 页数: 112



Hotspot 页数: 136



Java Virtual Machine Design for Embedded Systems 页数: 152



Java Virtual Machines 页数: 280



Java Language and Virtual Machine Specifications



OpenJDK JVM 1.6



jvms8


#### 第三方 Java 虚拟机

https://github.com/mateusbraga/JVM-1.2 JVM 1.2

DS虚拟机 JVM 1.2

ClassPath虚拟机 JVM 1.2 1.3 1.4 1.5

SableVM 虚拟机 JVM 1.2

Harmony虚拟机 JVM 1.5

IBM虚拟机

The Kaffe Virtual Machine 虚拟机

Alibaba dragonwell8 虚拟机 JVM 1.8

华为 bishengjdk-8 虚拟机 JVM 1.8

https://github.com/zhangkari/jvm 

https://github.com/kayodesu/cabin

SAP JVM虚拟机

avian 虚拟机

#### 安卓虚拟机书籍大全

Android Virtual Machine (VM) Setup on Linux 出版时间：2014-01-01



深入解析Android虚拟机 出版时间：2014-01-01



Android Dalvik虚拟机结构及机制剖析：第1卷 Dalvik虚拟机结构剖析 出版时间：2014-11-01



Android Dalvik虚拟机结构及机制剖析：第2卷（Dalvik虚拟机各模块机制分析） 出版时间：2014-08-01



深入解析Android虚拟机 出版时间：2016-09-01



Programming for the Android Dalvik Virtual Machine 出版时间：2017年1月15日



深入理解Android：Java虚拟机ART [Understanding Android Internals: ART JVM] 出版时间：2019-04-01



Dalvik Turbo Virtual Machine 页数: 18



Dalvik 页数: 80



Dalvik Turbo Virtual Machine: Lite Edition


### C&C++ 篇

滴水逆向

C++反汇编与逆向分析技术揭秘

第二部分 C++反汇编揭秘

第2章 基本数据类型的表现形式

2.1 整数类型

2.1.1 无符号整数

2.1.2 有符号整数

2.2 浮点数类型

2.2.1 浮点数的编码方式

2.2.2 基本的浮点数指令

2.3 字符和字符串

2.3.1 字符的编码

2.3.2 字符串的存储方式

2.4 布尔类型

2.5 地址、指针和引用

2.5.1 指针和地址的区别

2.5.2 各类型指针的工作方式

2.5.3 引用

2.6 常量

2.6.1 常量的定义

2.6.2 #define和const的区别

2.7 本章小结

第3章 认识启动函数，找到用户入口

3.1 程序的真正入口

3.2 了解VC++6.0的启动函数

3.3 main函数的识别

3.4 本章小结

第4章 观察各种表达式的求值过程

4.1 算术运算和赋值

4.1.1 各种算术运算的工作形式

4.1.2 算术结果溢出

4.1.3 自增和自减

4.2 关系运算和逻辑运算

4.2.1 关系运算和条件跳转的对应

4.2.2 表达式短路

4.2.3 条件表达式

4.3 位运算

4.4 编译器使用的优化技巧

4.4.1 流水线优化规则

4.4.2 分支优化规则

4.4.3 高速缓存（cache）优化规则

4.5 一次算法逆向之旅

4.6 本章小结

第5章 流程控制语句的识别

5.1 if语句

5.2 if……else……语句

5.3 用if构成的多分支流程

5.4 switch的真相

5.5 难以构成跳转表的switch

5.6 降低判定树的高度

5.7 do/while/for的比较

5.8 编译器对循环结构的优化

5.9 本章小结

第6章 函数的工作原理

6.1 栈帧的形成和关闭

6.2 各种调用方式的考察

6.3 使用ebp或esp寻址

6.4 函数的参数

6.5 函数的返回值

6.6 回顾

6.7 本章小结

第7章 变量在内存中的位置和访问方式

7.1 全局变量和局部变量的区别

7.2 局部静态变量的工作方式

7.3 堆变量

7.4 本章小结

第8章 数组和指针的寻址

8.1 数组在函数内

8.2 数组作为参数

8.3 数组作为返回值

8.4 下标寻址和指针寻址

8.5 多维数组

8.6 存放指针类型数据的数组

8.7 指向数组的指针变量

8.8 函数指针

8.9 本章小结

第9章 结构体和类

9.1 对象的内存布局

9.2 this指针

9.3 静态数据成员

9.4 对象作为函数参数

9.5 对象作为返回值

9.6 本章小结

第10章 关于构造函数和析构函数

10.1 构造函数的出现时机

10.2 每个对象都有默认的构造函数吗

10.3 析构函数的出现时机

10.4 本章小结

第11章 关于虚函数

11.1 虚函数的机制

11.2 虚函数的识别

11.3 本章小结

第12章 从内存角度看继承和多重继承

12.1 识别类和类之间的关系

12.2 多重继承

12.3 虚基类

12.4 菱形继承

12.5 本章小结

第13章 异常处理

13.1 异常处理的相关知识

13.2 异常类型为基本数据类型的处理流程

13.3 异常类型为对象的处理流程

13.4 识别异常处理

13.5 本章小结

天书夜读：从汇编语言到Windows内核编程

内容简介

前言

入手篇 熟悉汇编

第1章 汇编指令与C语言

1.1 上机建立第一个工程

1.2 简要复习常用的汇编指令

1.3 C函数的参数传递过程

第2章 C语言的流程和处理

2.1 C语言的循环反汇编

2.2 C语言判断与分支的反汇编

2.3 C语言的数组与结构

2.4 C语言的共用体和枚举类型

第3章 练习反汇编C语言程序

3.1 算法的反汇编

3.2 发行版的反汇编

3.3 汇编反C语言练习

完全手册丛书：C++参考大全（第4版） [C++: The Complete Reference] 出版时间：2003-01-01

C++设计新思维：泛型编程与设计模式之应用 出版时间：2003-03-01

C++ STL程序员开发指南（附光盘） 出版时间：2003-04-01

深入C++系列：泛型编程与STL 出版时间：2003-04-01

C++并行与分布式编程 [Parallel and Distributed Programming Using C++] 出版时间：2004-01-01

C++网络编程，卷 2 ：基于ACE和框架的系统化复用 出版时间：2004-01-01

ACE程序员指南：网络与系统编程的实用设计模式（附光盘） [The ACE Programmers Guide] 出版时间：2004-01-01

C++编程艺术 出版时间：2005-04-01

精通Oracle10g Pro*C/C++编程 出版时间：2005-10-01

Effective C++中文版：改善程序与设计的55个具体做法（第3版） 出版时间：2006-07-01

C++网络编程，卷1：运用ACE和模式消除复杂性 出版时间：2007-05-01

[按需印刷]C++ STL开发技术导引 出版时间：2007-08-01

C++沉思录：Ruminations on C++ 出版时间：2008-01-01

C和C++经典著作：C专家编程Expert C Programming Deep C Secrets 出版时间：2008-02-01

C和C++经典著作：C陷阱与缺陷 [C Traps and Pitfalls] 出版时间：2008-02-01

C和C++经典著作：C和指针 POINTERS ON C 出版时间：2008-04-01

Professional Multicore Programming: Design And Implementation For C++ Developers 出版时间：2008-08-22

你必须知道的495个C语言问题 出版时间：2009-02-01

代码揭秘：从C/C++的角度探秘计算机系统（推荐PC阅读） 出版时间：2009-09-01

C++编程规范：101条规则、准则与最佳实践 出版时间：2010-12-01

More Exceptional C++：40个新的工程难题、编程疑问及解决方法（中文版） 出版时间：2011-01-01

提高C++性能的编程技术 出版时间：2011-03-01

白盒测试之道：C++test 出版时间：2011-04-01

C++编程思想（两卷合订本） 出版时间：2011-07-01

Professional C++, Second Edition 出版时间：2011-09-16

编写高质量代码：改善C++程序的150个建议 出版时间：2011-12-01

Applied C++中文版 出版时间：2012-01-01

深度探索C++对象模型 出版时间：2012-01-01

Imperfect C++（中文版） [Imperfect C++: Practical Solutions for Real-Life Programming] 出版时间：2012-06-01

C++代码设计与重用 [Designing and Coding Reusable C++] 出版时间：2012-06-01

ACE技术内幕：深入解析ACE架构设计与实现原理 出版时间：2012-07-09

高质量程序设计指南：C++/C语言 出版时间：2012-10-01

C++编程调试秘笈 出版时间：2013-01-01

Linux多线程服务端编程 使用muduo C++网络库 出版时间：2013-01-01

C和C++实务精选：C++ Templates中文版 出版时间：2013-04-01

实战系列：深入实践C++模板编程 出版时间：2013-06-01

像计算机科学家一样思考C++ 出版时间：2013-06-01

华章科技：深入理解C++11：C++11新特性解析与应用 出版时间：2013-06-01

Essential C++中文版 出版时间：2013-08-01

图灵程序设计丛书：C++ API设计 [API Design for C++] 出版时间：2013-08-01

从缺陷中学习C/C++ 出版时间：2013-09-01

华章程序员书库：C和C++安全编码（原书第2版） 出版时间：2014-01-01

编码的法则：C++程序员不可不知的101条实用经验 出版时间：2014-01-01

C++ For Dummies, 7th Edition 出版时间：2014-01-01

深入理解C指针（C/C++程序员进阶必备，透彻理解指针与内存管理） 出版时间：2014-02-01

C标准库（英文版） 出版时间：2014-04-01

深入实践Boost：Boost程序库开发的94个秘笈 出版时间：2014-04-21

C++ All-in-One For Dummies, 3rd Edition 出版时间：2014-08-08

大规模C++程序设计 出版时间：2014-10-01

华章原创精品·深入应用C++11：代码优化与工程级应用 出版时间：2015-05-01

C++ STL基础及应用（第2版）/中国高等学校计算机科学与技术专业 应用型 规划教材 出版时间：2015-05-01

C/C++技术丛书：高级C/C++编译技术 [Advanced C and C++ Compiling] 出版时间：2015-05-01

C++标准库（第2版） 出版时间：2015-06-01

C++并发编程实战 出版时间：2015-06-01

Learning Boost C++ Libraries 出版时间：2015-07-31

写给大忙人看的C++ 出版时间：2015-08-01

C安全编码标准：开发安全、可靠、稳固系统的98条规则（原书第2版） 出版时间：2015-08-01

最新C/C++函数与算法速查速用大辞典（附光盘） 出版时间：2015-09-01

Boost.Asio C++ Network Programming - Second Edition 出版时间：2015-09-16

大道至简 C++ STL（标准模板库）精解 出版时间：2015-11-01

C++泛型：STL原理和应用 出版时间：2015-12-01

Boost.Asio C++ Network Programming Cookbook 出版时间：2016-01-25

C++编程剖析 问题 方案和设计准则 出版时间：2016-03-01

C++多线程编程实战 出版时间：2016-04-01

C++覆辙录 出版时间：2016-04-01

C++必知必会 出版时间：2016-04-01

C高级编程：基于模块化设计思想的C语言开发 出版时间：2016-05-01

C指针：基本概念、核心技术及最佳实践 出版时间：2016-05-01

后台开发：核心技术与应用实践 出版时间：2016-08-01

码农·经典C++（第26期） 出版时间：2016-12-22

C++程序设计实践与技巧：测试驱动开发 出版时间：2017-01-01

C++标准模板库编程实战 出版时间：2017-01-01

C++ STL标准程序库开发指南（第2版） 出版时间：2017-01-01

C++17 STL Cookbook 出版时间：2017-06-28

Boost C++ Application Development Cookbook - Second Edition 出版时间：2017-08-30

Learning C++ Functional Programming 出版时间：2017-08-10

Mastering the C++17 STL 出版时间：2017-09-28

C++入门经典（第10版） 出版时间：2017-11-01

C++语义和性能分析 出版时间：2017-12-01

C++性能优化指南 出版时间：2018-01-01

C++ High Performance 出版时间：2018-01-31

Effective Modern C++(中文版) 出版时间：2018-04-01

多核异构并行计算（OpenMP4.5C\C++篇）/超算、云计算与大数据技术专业教程·普通高等教育“十三五”规划教材 出版时间：2018-04-01

C/C++实践进阶之道：写给程序员看的编程书 出版时间：2018-05-01

新标准C++程序设计 出版时间：2018-08-01

清华计算机图书译丛：精通C++（第9版） 出版时间：2018-08-01

Linux C与C++ 一线开发实践 出版时间：2018-12-01

Hands-On System Programming with C++ 出版时间：2018-12-26

Hands-On Design Patterns with C++ 出版时间：2019-01-30

C++代码整洁之道：C++17可持续软件开发模式实践 出版时间：2019-04-01

C++高级编程(第4版) 出版时间：2019-04-01

C指针原理揭秘：基于底层实现机制 出版时间：2019-05-01

白话C++之练功 出版时间：2019-05-01

C++程序设计语言（第1-4部分 套装共2册） 出版时间：2019-06-01

C++17入门经典（第5版） 出版时间：2019-06-01

C Primer Plus 第6版 中文版 出版时间：2019-11-01

C++函数式编程 [Functional Programming in C++] 出版时间：2020-01-01

Boost程序库完全开发指南：深入C++“准”标准库（第5版） 出版时间：2020-06-01

C++新经典 出版时间：2020-07-01

### Linux 篇

Debug Hacks中文版 出版年: 2011-8

Linux内核安全模块深入剖析 出版时间：2016-12-01

Linux内核源代码分析 出版年: 2000-06

Linux内核分析及常见问题解答 (平装) 出版年: 2000-07

LINUX的内核与编程 出版时间：	2000-07-01

Linux操作系统内核分析 出版年: 2000-8

LINUX内核源代码情景分析（上册） 出版时间：2001-01-01

LINUX内核源代码情景分析（下） 出版时间：2001-09-01

Linux内核2.4版源代码分析大全 出版年: 2002-1-1

Linux内核源代码 出版年: 2002-1-1

深入分析Linux内核源代码 出版时间：2002-07-01

普通高等教育“十一五”国家级规划教材：边干边学（LINUX内核指导） [LEARNING LINUX KERNEL BY PRACTICE] 出版时间：2002-08-01

Linux内核分析与实例应用 出版年: 2002-9

操作系统教程：Linux实例分析/面向21世纪高等学校计算机类专业系列教材 出版时间：2004-01-01

高等学校计算机科学与技术教材：Linux操作系统分析教程（推荐PC阅读） 出版时间：2004-05-01

Linux内核完全注释 出版时间：2004-09-01

Linux0.01内核分析与操作系统设计（创造你自己的操作系统）（附CD—ROM光盘1张） 出版时间：2004-10-01

国外计算机科学经典教材：Linux内核编程指南（第3版） 出版时间：2004-11-01

IA-64 Linux内核设计与实现 出版年: 2004-11

操作系统：Linux 篇/高职高专21世纪规划教材 出版时间：2005-01-01

Linux操作系统内核实习 出版年: 2005-2

LInux内核分析及编程 出版时间：2005-09-01

O'Reilly：LINUX设备驱动程序（第3版） 出版时间：2006-01-01

Linux网络体系结构：Linux内核中网络协议的设计与实现 出版时间：2006-07-01

Linux内核分析及高级编程（推荐PC阅读） 出版时间：2006-07-01

O'Reilly：深入理解LINUX内核（第3版）（涵盖2.6版） 出版时间：2008-01-01

计算机科学与技术系列教材：Linux原理与应用 出版时间：2008-03-01

Linux中TCP/IP协议实现及嵌入式应用 出版时间：2008-07-01

高等学校计算机专业教材精选·计算机原理·微型计算机操作系统基础：基于Linux/i386 出版时间：2008-07-01

高等学校电子与能信类专业“十一五”规划教材·计算机操作系统原理：Linux实例分析 出版时间：2008-09-01

Linux操作系统分析与实践 出版时间：2008-11-01

Linux2.6内核标准教程（附光盘1张） 出版时间：2008-11-01

Linux内核完全剖析：基于0.12内核 出版时间：2009-01-01

Linux操作系统实验教程 出版时间：2009-02-01

高等学校计算机实践教学系列教材：Linux操作系统实验教程 出版时间：2009-04-01

Linux操作系统原理与应用 出版时间：2009-04-01

深入理解Linux网络技术内幕 出版时间：2009-06-01

独辟蹊径品内核：Linux内核源代码导读（推荐PC阅读）  出版时间：2009-08-01

深入浅出Linux TCP/IP协议栈 出版时间：2010-01-01

Linux内核网络栈源代码情景分析 出版年: 2010-1

追踪Linux TCP/IP代码运行：基于2.6内核（附CD-ROM光盘1张） 出版时间：2010-04-01

Linux体系与编程：基于Linux0.01版本/21世纪软件工程师规划教材 出版时间：2010-04-01

O'Reilly：Linux 内核技术手册 [Linux Kernel in a Nutsbell] 出版时间：2010-06-01

深入Linux内核架构 出版时间：2010-06-01

Linux内核修炼之道 出版时间：2010-07-01

Linux网络内核分析与开发 出版年: 2010-8

操作系统实验教程及Linux和Windows系统调用编程/计算机课程设计与综合实践规划教材 出版时间：2010-09-01

Linux内核源码剖析：TCP/IP实现（套装上下册） 出版时间：2011-01-01

Linux内核设计与实现（原书第3版） 出版时间：2011-05-01

嵌入式Linux网络体系结构设计与TCP/IP协议栈 出版年: 2011-05

Linux内核编程 出版年: 2011-5

存储技术原理分析：基于Linux 2.6内核源代码 出版时间：2011-09-01

Linux内核注释 出版时间：2011-12-01

Linux操作系统原理与应用（第2版） 出版时间：2012-01-01

深入Linux设备驱动程序内核机制 出版时间：2012-01-01

Linux原理与结构 出版时间：2012-02-01

O'Reilly精品图书系列·Linux内核精髓：精通Linux内核必会的75个绝技 出版时间：2012-02-01

Linux那些事儿之我是USB（第2版） 出版时间：2012-03-01

Linux内核分析与高级教程 出版年: 2012-8

Linux内核精析（附CD光盘1张） 出版时间：2013-02-01

21世纪高等学校规划教材·计算机科学与技术：操作系统原理及应用（Linux） 出版时间：2013-04-01

Linux内核设计的艺术：图解Linux操作系统架构设计与实现原理（第2版） 出版时间：2013-05-01

深度探索Linux操作系统：系统构建和原理解析 出版时间：2013-10-08

Linux内核探秘：深入解析文件系统和设备驱动的架构与设计 出版时间：2013-12-01

操作系统原理与Linux实例设计（第2版） 出版时间：2014-06-01

计算机操作系统实验指导(Linux版)(国家精品课程配套实验教材　国家精品资源共享课程配套实验教材) 出版时间：2014-07-01

精通Linux内核网络 出版时间：2015-06-01

操作系统原理与实践教程（第2版）/计算机系列教材 出版时间：2015-08-01

深入理解Linux驱动程序设计 出版时间：2015-11-01

操作系统原理与Linux实践教程 出版时间：2016-01-01

精通Linux设备驱动程序开发 出版时间：2016-04-01

操作系统实验指导：基于Linux内核（第3版） 出版时间：2016-07-01

Linux内核API完全参考手册（第2版） 出版时间：2016-10-01

Linux技术内幕 出版时间：2016-12-01

深入Linux内核架构与底层原理 出版时间：2017-11-01

操作系统原理及Linux内核分析(第2版）/21世纪高等学校规划教材·计算机科学与技术 出版时间：2018-08-01

Linux设备驱动程序开发（影印版 英文版） [Linux Device Drivers Development] 出版时间：2018-08-01

2016同济大学本科教材出版基金：Linux操作系统实现原理 出版时间：2018-09-01

庖丁解牛Linux内核分析 出版时间：2018-10-01

操作系统原理与应用（Linux） 出版时间：2018-12-01

操作系统实验指导与习题解析 出版时间：2019-10-01

精通Linux内核：智能设备开发核心技术 出版时间：2020-01-01

用“芯”探核 基于龙芯的Linux内核探索解析 出版时间：2020-08-01

Linux内核观测技术BPF [Linux Observability with BPF] 出版时间：2020-08-01

Linux Kernel Development Cookbook 出版时间：2021-01

深度探索Linux系统虚拟化：原理与实现 出版时间：2020-11-01

### 微信赞赏码

![image](https://github.com/OpenSrcDeveloper/java-for-linux/blob/master/image/赞赏码.png)

