<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<html>
    <head>
        <meta charset="UTF-8">
        <title>新建</title>
        <link rel="stylesheet" href="../../../css/bootstrap.min.css">
        <link rel="stylesheet" href="../../../css/add.css">
    </head>
    <body>
        <nav class="navbar navbar-default">
            <div class="container">
                <div class="navbar-header">
                    <a class="navbar-brand" href="/cake/list.do">
                        慕课网蛋糕管理
                    </a>
                </div>
            </div>
        </nav>
        <div class="container">
            <div class="jumbotron">
                <h1>Hello, ${username}!</h1>
                <p>请小心的新增蛋糕记录，要是建了一个错误的就不好了。。。</p>
            </div>
            <div class="page-header">
                <h3><small>新建</small></h3>
            </div>
            <form class="form-horizontal" action="/cake/add.do" method="post" enctype="multipart/form-data">
                <div class="form-group">
                    <label for="name" class="col-sm-2 control-label">名称 ：</label>
                    <div class="col-sm-8">
                        <input name="name" class="form-control" id="name">
                    </div>
                </div>
                <div class="form-group">
                    <label for="categoryId" class="col-sm-2 control-label">分类 ：</label>
                    <select id="categoryId" name="categoryId" class="col-sm-2 form-control" style="width: auto">
                        <c:forEach var="item" items="${categories}">
                            <option id="${item.id}" value="${item.id}">${item.name}</option>
                        </c:forEach>
                    </select>
                </div>
                <div class="form-group">
                    <label for="level" class="col-sm-2 control-label">星级 ：</label>
                    <select id="level" name="level" class="col-sm-2 form-control" style="width: auto">
                        <option id="1" value="1">1星</option>
                        <option id="2" value="2">2星</option>
                        <option id="3" value="3">3星</option>
                        <option id="4" value="4">4星</option>
                        <option id="5" value="5">5星</option>
                    </select>
                </div>
                <div class="form-group">
                    <label for="price" class="col-sm-2 control-label">价格 ：</label>
                    <div class="col-sm-8">
                        <input name="price" type="number" class="form-control" id="price">
                    </div>
                </div>
                <div class="form-group">
                    <label for="smallImg" class="col-sm-2 control-label">图片 ：</label>
                    <div class="col-sm-8">
                        <input id="smallImg" name="smallImg" class="file-loading"
                               type="file" multiple accept=".jpg,.jpeg,.png" data-min-file-count="1"
                               data-show-preview="true">
                    </div>
                </div>

                <div class="form-group">
                    <div class="col-sm-offset-2 col-sm-10">
                        <button type="submit" class="btn btn-primary">保存</button>&nbsp;&nbsp;&nbsp;
                    </div>
                </div>
            </form>
        </div>
        <footer class="text-center" >
            copy@imooc
        </footer>
    </body>
</html>
