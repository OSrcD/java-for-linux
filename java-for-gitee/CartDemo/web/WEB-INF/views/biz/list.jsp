<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<html>
<head>
    <meta charset="UTF-8">
    <title>课程</title>
    <link rel="stylesheet" href="../../../css/list.css">
    <style>
        .btn {
            color: blue;
            background-color: #FFFFFF;
            border: 0px none;  //去边框
        font-family: "宋体";
            font-size: 15px;
            text-decoration:underline;  //加下划线
        }
        .btn:hover{
            color:red;
            border: none;
            cursor: hand;
            cursor: pointer;
            text-decoration:underline;  //加下划线
        }
        .btn:focus {
            outline: none;    //去边框
        }
    </style>
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
    <form id="searchForm" method="post" action="/product/list.do">
        <div class="search">
            <input type="hidden" name="page" value="1">
            <input type="text" name="title" class="search_input" value="${title}">
            <input type="submit" class="search_submit" value="" >
        </div>
    </form>


    <%--<form id="searchForm" method="post" action="/product/list.do">--%>
        <%--<div class="search">--%>
            <%--<input type="hidden" name="page" value="1">--%>
            <%--<input type="text" name="title" class="search_input" value="${title}">--%>
            <%--<input type="submit" class="search_submit" value="">--%>
        <%--</div>--%>
    <%--</form>--%>
    <%--<div class="search"><input type="text" class="search_input"><a href="" class="search_submit"></a></div>--%>
</header>
<div id="main">
    <div class="wrap">
    </div>
    <div class="container">
        <!-- 课程列表 -->
        <div class="course-list">
            <div align="right">
                <%--<a href="/product/list.do?page=1">首页</a>--%>
                <%--<a href="/product/list.do?page=${prePage}">上一页</a>--%>
                <%--<a href="/product/list.do?page=${nextPage}">下一页</a>--%>
                <%--<a href="/product/list.do?page=${totalPage}">尾页</a>--%>

                <form method="post" action="/product/list.do" style="display: inline">
                    <input type="hidden" name="page" value="1">
                    <input type="hidden" name="title" value="${title}">
                    <input type="submit" value="首页" class="btn">
                </form>

                <form method="post" action="/product/list.do" style="display: inline">
                    <input type="hidden" name="page" value="${prePage}">
                    <input type="hidden" name="title" value="${title}">
                    <input type="submit" value="上一页" class="btn">
                </form>

                <form method="post" action="/product/list.do" style="display: inline">
                    <input type="hidden" name="page" value="${nextPage}">
                    <input type="hidden" name="title" value="${title}">
                    <input type="submit" value="下一页" class="btn">
                </form>

                    <form method="post" action="/product/list.do" style="display: inline">
                        <input type="hidden" name="page" value="${totalPage}">
                        <input type="hidden" name="title" value="${title}" >
                        <input type="submit" value="尾页" class="btn">
                    </form>



                第${curPage}页/共${totalPage}页
            </div>
                <%--<a href="/product/list.do?page=1">首页</a>--%>
                <%--<a href="/product/list.do?page=${prePage}">上一页</a>--%>
                <%--<a href="/product/list.do?page=${nextPage}">下一页</a>--%>
                <%--<a href="/product/list.do?page=${totalPage}">尾页</a>--%>

                <%--<form method="post" action="/product/list.do" style="display: inline">--%>
                    <%--<input type="hidden" name="page" value="1">--%>
                    <%--<input type="hidden" name="title" value="${title}">--%>
                    <%--<input type="submit" value="首页" class="btn">--%>
                <%--</form>--%>
                <%--<form method="post" action="/product/list.do" style="display: inline">--%>
                    <%--<input type="hidden" name="page" value="${prePage}">--%>
                    <%--<input type="hidden" name="title" value="${title}">--%>
                    <%--<input type="submit" value="上一页" class="btn">--%>
                <%--</form>--%>
                <%--<form method="post" action="/product/list.do" style="display: inline">--%>
                    <%--<input type="hidden" name="page" value="${nextPage}">--%>
                    <%--<input type="hidden" name="title" value="${title}">--%>
                    <%--<input type="submit" value="下一页" class="btn">--%>
                <%--</form>--%>
                <%--<form method="post" action="/product/list.do" style="display: inline">--%>
                    <%--<input type="hidden" name="page" value="${totalPage}">--%>
                    <%--<input type="hidden" name="title" value="${title}">--%>
                    <%--<input type="submit" value="尾页" class="btn">--%>
                <%--</form>--%>
                <%--第${curPage}页/共${totalPage}页--%>
            <%--</div>--%>
            <c:forEach items="${products}" var="product">
                <div class="course-card-container">
                    <div class="course-card">
                        <div class="course-card-top">
                            <span>${product.tag}</span>
                        </div>
                        <div class="course-card-content">
                            <a  href="/detail/detail.do?productId=${product.id}" >

                                <h3>${product.name}-${product.id}</h3>
                                <p>${product.desc}</p>
                            </a>
                            <div class="course-card-bottom">
                                <span>${product.level}</span>
                                <span>
                                    <a href="/cart/cart.do?productId=${product.id}">
                                        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                                    </a>
                                </span>
                                <a href="/favorite/favorite.do?productId=${product.id}">
                                    <span></span>
                                </a>
                            </div>
                        </div>
                    </div>
                    <div class="course-card-bk">
                        <img src="../../../img/bk1.jpg" alt="">
                    </div>
                </div>
            </c:forEach>
        </div>
        <div align="right">
            <%--<a href="/product/list.do?page=1">首页</a>--%>
            <%--<a href="/product/list.do?page=${prePage}">上一页</a>--%>
            <%--<a href="/product/list.do?page=${nextPage}">下一页</a>--%>
            <%--<a href="/product/list.do?page=${totalPage}">尾页</a>--%>

            <form method="post" action="/product/list.do" style="display: inline">
                <input type="hidden" name="page" value="1">
                <input type="hidden" name="title" value="${title}">
                <input type="submit" value="首页" class="btn">
            </form>
            <form method="post" action="/product/list.do" style="display: inline">
                <input type="hidden" name="page" value="${prePage}">
                <input type="hidden" name="title" value="${title}">
                <input type="submit" value="上一页" class="btn">
            </form>
            <form method="post" action="/product/list.do" style="display: inline">
                <input type="hidden" name="page" value="${nextPage}">
                <input type="hidden" name="title" value="${title}">
                <input type="submit" value="下一页" class="btn">
            </form>
            <form method="post" action="/product/list.do" style="display: inline">
                <input type="hidden" name="page" value="${totalPage}">
                <input type="hidden" name="title" value="${title}">
                <input type="submit" value="尾页" class="btn">
            </form>
            第${curPage}页/共${totalPage}页
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