<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>通过EL表达式获取数据</title>
</head>
<body>
	姓名：${username} <br>
	年龄：${age} <br>
	session_age:${requestScope.username}
	${sessionScope.username}
</body>
	
</html>