<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <meta charset="UTF-8">
        <title>登录</title>
        <link rel="stylesheet" href="../../../css/imooc.css">
    </head>
    <body>
    <!-- header区域 -->
    <header class="header">
        <div class="logo"></div>
        <div class="nav">
            <a href="" class="nav__item">课程</a>
            <a href="" class="nav__item nav__item_icon_new">职业路径<i class="icon_new"></i></a>
            <a href="" class="nav__item">实战</a>
            <a href="" class="nav__item">猿问</a>
            <a href="" class="nav__item">手记</a>
        </div>
        <div class="profile">
            <a href="" class="profile__item profile__car"></a>
            <a href="" class="profile__item profile__message"></a>
            <a href="" class="profile__item profile__ava"></a>
        </div>
        <div class="search"><input type="text" class="search_input"><a href="" class="search_submit"></a></div>
    </header>
    <div style="height: 40%; margin-left: 30%; margin-top: 20%">
        <form method="post" action="/login">
            <input type="hidden" name="source" value="${source}">
            <table>
                <tr>
                    <td>用户名：</td>
                    <td><input type="text" name="username"></td>
                </tr>
                <tr>
                    <td>密码：</td>
                    <td><input type="password" name="password"></td>
                </tr>
                <tr>
                    <td colspan="2" align="center"><input type="submit"></td>
                </tr>
            </table>
        </form>
    </div>
    <!-- footer区域 -->
    <footer class="footer">
        <div class="waper">
            <div class="footerWaper">
                <div class="followus">
                    <a href="" class="followus_weixin"><div class="flw-weixin-box"></div></a>
                    <a href="" class="followus_weibo"></a>
                    <a href="" class="followus_qzone"></a>
                </div>
                <div class="footer_intro">
                    <div class="footer_link">
                        <ul>
                            <li><a href="">网站首页</a></li>
                            <li><a href="">企业合作</a></li>
                            <li><a href="">人才招聘</a></li>
                            <li><a href="">联系我们</a></li>
                            <li><a href="">讲师招募</a></li>
                            <li><a href="">常见问题</a></li>
                            <li><a href="">意见反馈</a></li>
                            <li><a href="">慕课大学</a></li>
                            <li><a href="">友情链接</a></li>
                        </ul>
                    </div>
                    <p>Copyright © 2017 imooc.com All Rights Reserved | 京ICP备 13046642号-2</p>
                </div>
            </div>
        </div>
    </footer>
    </body>
</html>