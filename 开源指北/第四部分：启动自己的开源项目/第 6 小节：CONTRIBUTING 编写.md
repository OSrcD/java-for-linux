# 第 6 小节：CONTRIBUTING 编写

## CONTRIBUTING 是什么

> ​	CONTRIBUTING 文件用来告诉人们如何对项目做出贡献.



## CONTRIBUTING  如何编写

在 **CONTRIBUTING** 文件中会含有下面这些主题的内容（可能不完整, 请各位读者进行补充）

1. 如何提交错误报告
   1. 当出现 Bug 的时候需要如何提交，对于安全性的漏洞需要通过项目内部的人员邮箱通知， 不应该将安全性 Bug 公开
   2. 通过 Issues 仅提交
2. 解决现有问题
3. 如何提出新功能
4. 如何设置开发环境并运行测试
5. 提交变更的日志信息（git commit message）
6. 编码约定
7. 分支处理的约定
8. 合并 PR 的形式



### 例子

```md
## 提交错误报告
如果您在XXX中发现了一个不存在安全问题的漏洞, 请在XXX仓库中的 Issues 中搜索, 以防该漏洞已被提交, 如果找不到漏洞可以创建一个新的 Issues. 如果发现了一个安全问题请不要将其公开. 请参阅安全问题处理方式. 提交错误报告时应该详尽

## 安全问题处理
本项目中对安全问题处理的形式. 项目核心人员确认编辑. 该部分内容可以根据项目情况添加

## 解决现有问题
通过查看仓库的 Issues 列表何以发现需要处理的问题信息, 可以尝试解决其中的某个问题

## 如何提出新功能
提出新功能有些项目使用 Issues 的 Feature 标签进行管理, 有些则通过邮件的形式统一收集. 在收集后项目内人员会进行确认开发, 一般的将确认开发的功能会放入下一个版本的任务列表

## 如何设置开发环境并运行测试
如果是通过 Git 管理可以从 `git clone xxx` 开始编写, 将开发环境的配置信息, IDE 的设置等信息配置文档编写. 

## 变更日志填写规则 
1. 使用现在时态
1. 第一行字数限制
1. 提交内容的约束

## 编码约定
- 项目内编码约定文件, .editorconfig

## 分支处理约定
- 分支处理形式, 如 gitFlow

## 合并 PR 的形式
在什么情况下可以合并到 master/main.
	1. 通过 CI
	2. 两个及以上的维护者通过. 
	3. 最新版本
```

### 本部分内容贡献者

[huifer](https://gitee.com/pychfarm_admin)、[PureBlue](https://gitee.com/qq379377944)、[taotieren](https://gitee.com/taotieren)、[WhitePaper](https://gitee.com/whitepaper233)、[yadong.zhang](https://gitee.com/yadong.zhang)