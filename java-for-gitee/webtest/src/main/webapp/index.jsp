<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
 <h1>登陆</h1>
    <form action="login" method="post">
        <div>
            <label for="username">用户名</label>
            <input type="text" id="username" name="username" placeholder="请输入用户名">

        </div>
        <div>
            <label for="passowrd">密码</label>
            <input type="text" id="passowrd" name="passowrd" placeholder="请输入密码">

        </div>
        <div>
            <input type="submit" value="登陆">
        </div>

    </form>
</body>
</html>