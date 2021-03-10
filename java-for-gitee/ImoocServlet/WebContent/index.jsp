<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
    
<%
	String bashpath = request.getScheme()+":"+"//"+request.getServerName()+":"+request.getServerPort()
	+request.getServletContext().getContextPath()+"/";
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>登陆</title>
</head>
<body>

	<center>
		<form action="<%=bashpath %>LoginServlet" method="post">
			<p>用户名:<input type="text" name="username"></p>
			<p>密&nbsp;码:<input type="password" name="password"></p>
			<p>
				<input type="submit" value="登陆">
				<input type="reset" value="重置">
			</p>
		</form>
	</center>
</body>
</html>