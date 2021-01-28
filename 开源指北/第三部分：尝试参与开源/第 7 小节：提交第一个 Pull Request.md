# 第 7 小节：提交第一个 Pull Request

```
文章以 GitHub 为基准，需要补充 Gitee 的相关操作
```

```
merge pull request的流程相对简单，是通过两个自己项目的repo进行的阐述，需要补充权限说明，code review，approve，CI机制等  
```


####  什么是 Pull Request

这个是由 GitHub 提出的概念。根据 GitHub 的官方文档，Pull Request 是一种通知机制，它可以告知仓库的其他开发者，你推送了一个仓库新分支。 通过Pull Request ，你可以和仓库的协作者一起讨论和审查提交的代码，审查通过后，就可以提交到仓库的主分支中。

Pull Request 本质上是一种协同工作的机制，可以进行基于网络的多人提交，审核机制，审核通过后，就可以合并到主分支中。


####  提交 Pull Request 的步骤

第一步，你需要 Fork 别人的仓库。也就是复制别人的仓库到你自己的仓库中。

第二步，在你自己的仓库上，修改然后提交之后，在网页端点击「New pull request」按钮。

在接下来的网页上有 base 仓库和 head 仓库，其中 base 是你想要提交的仓库，head 分支是你已经提交变更的仓库。

第三步，在提交中，描述提交本地提交的说明。


#### 实际操作一下

1. 在 GitHub 上建立两个帐号 A 和 B。

1. 使用 A 帐号，创建项目 pull_request_demo
   
1. 在本地提交 README.md

   ```
   echo "pull_request_demo from A" >> README.md
   git init
   git add README.md
   git commit -m "first commit"
   git branch -M main
   git remote add origin https://github.com/A/pull_request_demo.git
   git push -u origin main
   ```

1. 使用 B 帐号登录 GitHub，然后 Fork 该项目。

1. 下载项目到本地

   ```
   git clone https://github.com/B/pull_request_demo
   echo "pull_request_demo add form B" >> README.md
   git add README.md
   git commit -m "modify commit"
   git push
   ```

1. 使用 B 帐号登录 GitHub，进入 pull_request_demo 仓库，点击 Pull request 链接。

1. 选择 base 和 head 仓库。点击「New pull request」按钮。

1. 填写提交说明后，「Create pull request」。

1. 使用 A 帐号登录 GitHub，进行 pull_request_demo 项目。

1. 可以看到 Pull request 中有新的数据。

1. 点击 Confirm merge，完成合并。

#### 补充内容：参与公共的 PR 仓库来完成第一次PR尝试

当然，如果你不想注册两个 GitHub 账户亦或由于某些原因对此感到比较麻烦的话，你也可以按照上面的说明来选择参与到 GitHub 上的一些公共且活跃维护的 PR 尝试仓库。

比如说 [这个仓库](https://github.com/ituring/first-pr) （不过第一次提交时你只能作为提交者进行尝试）。

当你的 PR 被通过合并后，你的账户通常也会得到管理员权限，在此时你也可以来尝试作为管理员的身份来合并其他人的提交。

是的，在此时你的心中可能已经有了一个猜想，而我们在这里也可以告诉你这个猜想没有问题，像这些仓库其实还有很多，而且通常是由全体自发的贡献者来自愿进行维护的，而你也可以成为其中的一员。

### 本部分内容贡献者

[brace](https://gitee.com/awang)、[李志鹏](https://gitee.com/lizhipeng1992)、[ORH](https://gitee.com/orh)、[ShardingSphere](https://gitee.com/dangdangdotcom_zhangliang)、[冰彦糖](https://gitee.com/bingyantang)