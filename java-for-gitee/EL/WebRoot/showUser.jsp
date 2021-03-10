<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Insert title here</title>
</head>
<body>
<hr>
		用户名:${user.username}<br/>
		密    码:${user.password}<br/>
		
<hr>
用户名:${requestScope.user.username}<br/>
密    码:${requestScope.user.password}
<hr>
用户名:${user["username"]}
密    码:${user["password"]} 
头         :${header["Accept-Language"]}
</body>
</html>