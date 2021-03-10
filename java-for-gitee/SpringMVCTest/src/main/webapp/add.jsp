<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>add</title>
    <link href="css/bootstrap.min.css" rel="stylesheet">
    <style type="text/css">
        body{
            overflow-x:hidden;
        }
    </style>
</head>
<body>
    <form class="form-horizontal" role="form" action="addGoods" method="post">
        <div class="form-group">
            <label class="col-sm-1 control-label">名称</label>
            <div class="col-sm-3">
                <input type="text" class="form-control" name="name" placeholder="请输入商品名称">
            </div>
        </div>
        <div class="form-group">
            <label class="col-sm-1 control-label">价格</label>
            <div class="col-sm-3">
                <input type="text" class="form-control" name="price" placeholder="请输入商品价格">
            </div>
        </div>
        <div class="form-group">
            <div class="col-sm-offset-1 col-sm-3">
                <button type="submit" class="btn btn-default">提交</button>
            </div>
        </div>
    </form>
</body>
</html>
