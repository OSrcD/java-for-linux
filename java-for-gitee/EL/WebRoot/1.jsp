<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>表单提交</title>
</head>
<body>
	<form action="/EL/ELServlet" method="post">
		用户名:<input type="text" name="username"><br>
		年龄:<input type="text" name="age"><br>
		<input type="submit" value="提交">
	</form>
</body>
</html>