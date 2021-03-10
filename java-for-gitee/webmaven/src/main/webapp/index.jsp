<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Document</title>
</head>
<body>
    <h1>登陆</h1>
    <form action="login" method="post">
        <div>
            <label for="username">用户名</label>
            <input type="text" id="username" name="username" placeholder="请输入用户名">

        </div>
        <div>
            <label for="passowrd">用户名</label>
            <input type="text" id="passowrd" name="passowrd" placeholder="请输入密码">

        </div>
        <div>
            <input type="submit" value="登陆">
        </div>

    </form>
</body>
</html>