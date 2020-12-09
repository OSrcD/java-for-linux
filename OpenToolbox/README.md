# OpenToolbox（OpenSourceToolbox）
默认效果
![image](https://github.com/OpenSrcDeveloper/terminal/blob/master/static/TerminalDemo01.png)
全屏效果
![image](https://github.com/OpenSrcDeveloper/terminal/blob/master/static/TerminalDemo02.png)
背景图片来自于Anonymous-OS
<br />
![image](https://github.com/OpenSrcDeveloper/terminal/blob/master/static/Anonymous-OS.png)

#### Build Setup

``` bash
# install dependencies
需要安装node.js和npm这两个自行百度怎么安装

我的node.js版本是v12.18.3

sudo npm install -g cnpm

sudo cnpm install -g yarn

sudo sh npm_install.sh

# serve with hot reload at localhost:9080
sudo yarn run dev

# build electron application for production
sudo yarn run build

sudo open build/Terminal-darwin-x64/Terminal.app/

# 中文乱码问题：
在vim ~/.bash_profile添加以下配置
export LANG="zh_CN.UTF-8"
LANGUAGE="zh_CN.UTF-8"
LC_CTYPE="zh_CN.UTF-8"
LC_NUMERIC="zh_CN.UTF-8"
LC_TIME="zh_CN.UTF-8"
LC_COLLATE="zh_CN.UTF-8"
LC_MONETARY="zh_CN.UTF-8"
LC_MESSAGES="zh_CN.UTF-8"
LC_PAPER="zh_CN.UTF-8"
LC_NAME="zh_CN.UTF-8"
LC_ADDRESS="zh_CN.UTF-8"
LC_TELEPHONE="zh_CN.UTF-8"
LC_MEASUREMENT="zh_CN.UTF-8"
LC_IDENTIFICATION="zh_CN.UTF-8"
LC_ALL=

# vim打开文件无法显示内容问题（已修复）：
改变窗口的宽度大小或高度大小或字体大小

# 编辑器无法输入中文问题
用sudo命令打开应用
sudo open build/terminal-darwin-x64/terminal.app
或sudo open /Applications/Terminal.app

# 未修复的BUG

# 已修复的BUG
1、当窗口宽度小于1219px时或改变字体大小，用Vim打开有内容的文件会出现空白现象，
也可能还与高度有关，改变窗口大小还会引起出
现输入文字偏移位置不正确的情况。

# 待增功能
1、自定义黑色的标题栏，不要系统自带的标题栏
2、增加hacker工具箱
3、爬虫、爬取最新的网络安全新闻显示到GUI
4、待添Hacker学习路线、hacking指令搜索

# 2020-8-25
1、原项目名为Terminal改名为OpenToolbox（开源工具箱)
```

---

提供Mac OS X 编译好的二进制文件下载
链接:<https://pan.baidu.com/s/1K_YYmQxHw_CDtS0Qj7cCzg> 密码:yncu
