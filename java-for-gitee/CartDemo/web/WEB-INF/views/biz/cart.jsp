<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<html>
    <head>
        <meta charset="UTF-8">
        <title>购物车</title>
        <link rel="stylesheet" href="../../../css/shopcar.css">
    </head>
    <body>
        <!-- header区域 -->
        <header class="header">
            <div class="logo"></div>
            <div class="nav">
                <a href="/product/list.do" class="nav__item">课程</a>
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
        <!-- banner区域 -->
        <div class="banner">
            <div>我的购物车</div>
        </div>
        <!-- goods区域 -->
        <form action="/cart/settlement.do" id="cartBody">
            <div class="cart-panel">
                <div class="hd">
                    <ul class="order-title">
                        <li><input type="checkbox" class="check-all"><span>全选</span></li>
                        <li class="product">商品名称</li>
                        <li class="total-price">总价</li>
                        <li class="unit-price">单价</li>
                        <li class="number">数量</li>
                        <li class="operate">操作</li>
                    </ul>
                </div>
                <div class="bd">
                    <!-- 购物车列表 -->
                    <c:forEach items="${carts}" var="cart">
                        <ul class="order-list">
                            <li><input type="checkbox" class="check" checked ></li>
                            <input type="hidden" name="carts" value="${cart.id}">
                            <li class="img-box">
                                <a href="http://www.imooc.com">
                                    <img src="../../../img/g1.jpg" alt="">
                                </a>
                            </li>
                            <li class="product">
                                <a href="http://www.imooc.com">
                                    <span>${cart.name}-${cart.id}</span>
                                </a>
                            </li>
                            <li class="total-price">
                                <span class="price-sign"></span>
                                <span class="price-num"><fmt:formatNumber value="${cart.totalPrice}" type="currency"/></span>
                            </li>
                            <li class="unit-price">
                                <span class="price-sign"></span>
                                <span class="price-num"><fmt:formatNumber value="${cart.price}" type="currency"/></span>
                            </li>
                            <li class="number">
                                <div class="input-num">
                                    <a href="/cart/decr.do?productId=${cart.productId}">-</a>
                                    <input type="text" value="${cart.count}" class="num">
                                    <a href="/cart/incr.do?productId=${cart.productId}">+</a>
                                </div>
                            </li>
                            <li class="operate"><a href="/cart/delete.do?productId=${cart.id}">删除</a></li>
                        </ul>
                    </c:forEach>
                </div>
            </div>
            <!-- 结算栏 -->
            <div class="pay-bar">
                <%--<div class="pay-info">--%>
                    <%--<div class="price">--%>
                        <%--<span class="price-sign">¥</span>--%>
                        <%--<span class="price-num pay-money"></span>--%>
                    <%--</div>--%>
                    <%--<span>应付金额：</span>--%>
                <%--</div>--%>
                <button>去结算</button>
            </div>
        </form>
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
    <script src="./js/shopcar.js"></script>
</html>