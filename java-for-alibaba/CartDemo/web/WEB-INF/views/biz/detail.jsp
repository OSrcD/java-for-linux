<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<html>
    <head>
        <meta charset="UTF-8">
        <title>课程</title>
        <link rel="stylesheet" href="../../../css/details.css">
        <link rel="stylesheet" href="../../../css/list.css">
    </head>
    <body>
        <!-- 头部 -->
        <header class="header">
            <div class="logo"></div>
            <div class="nav">
                <a href="/product/list.do" class="nav__item nav__course">课程</a>
                <a href="" class="nav__item nav__item_icon_new">职业路径<i class="icon_new"></i></a>
                <a href="" class="nav__item">实战</a>
                <a href="" class="nav__item">猿问</a>
                <a href="" class="nav__item">手记</a>
            </div>
            <div class="profile">
                <a href="/cart/list.do" class="profile__item profile__car"></a>
                <a href="/browse/list.do" class="profile__item profile__message"></a>
                <a href="" class="profile__item profile__ava"></a>
            </div>
            <div class="search"><input type="text" class="search_input"><a href="" class="search_submit"></a></div>
        </header>
        <div id="main">
            <div class="wrap">
            </div>
            <div class="container">
                <div class="product-wrapper">
                    <div class="product-l">
                        <div class="pro-preview">
                            <a href="/detail/list.do">
                                <img src="../../../img/g1.jpg">
                            </a>
                        </div>
                    </div>
                    <div class="product-r">
                        <div class="title">
                            <h3>${product.name}-${product.id}</h3>
                        </div>
                        <div class="attribute">
                            <dl>
                                <dt>课程标签:</dt>
                                <dd>${product.tag}</dd>
                            </dl>
                            <dl>
                                <dt>课程级别:</dt>
                                <dd>${product.level}</dd>
                            </dl>
                            <dl>
                                <dt>课程描述:</dt>
                                <dd>${product.desc}</dd>
                            </dl>
                        </div>
                        <div class="price">
                            价格：
                            <strong>
                                <span>￥</span>
                                <span>${product.price}</span>
                            </strong>
                        </div>
                    </div>
                </div>
            </div>
        </div>
        <!-- 尾部 -->
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