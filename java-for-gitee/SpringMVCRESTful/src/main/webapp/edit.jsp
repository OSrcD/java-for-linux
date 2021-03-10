<%--
  Created by IntelliJ IDEA.
  User: Administrator.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page isELIgnored="false" %>
<html>
<head>
    <title>add</title>
    <link href="${pageContext.request.contextPath}/css/bootstrap.min.css" rel="stylesheet">
    <style type="text/css">
        body{
            overflow-x:hidden;
        }
        #main{
            width:1200px;
            height:600px;
            margin-left:500px;
        }
    </style>
</head>
<body>

<div id="main">
    <!-- 标题 -->
    <div class="row">
        <div class="col-md-12">
            <h1>imooc-修改课程</h1>
        </div>
    </div>

    <form class="form-horizontal" role="form" action="${pageContext.request.contextPath}/update" method="post">
        <div class="form-group">
            <label class="col-sm-1 control-label">课程编号</label>
            <div class="col-sm-3">
                <input type="text" value="${course.id}" name="id" readonly="readonly" class="form-control">
            </div>
        </div>
        <div class="form-group">
            <label class="col-sm-1 control-label">课程名称</label>
            <div class="col-sm-3">
                <input type="text" value="${course.name}" name="name" class="form-control">
            </div>
        </div>
        <div class="form-group">
            <label class="col-sm-1 control-label">课程价格</label>
            <div class="col-sm-3">
                <input type="text" value="${course.price}" name="price" class="form-control">
            </div>
        </div>
        <div class="form-group">
            <div class="col-sm-offset-1 col-sm-3">
                <input type="hidden" name="_method" value="PUT" />
                <button type="submit" class="btn btn-default">提交</button>
            </div>
        </div>
    </form>
</div>
</body>
</html>
