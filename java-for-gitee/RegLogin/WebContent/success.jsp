<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="com.imooc.domain.User"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>登录成功</title>
<link rel="stylesheet" href="./css/login.css">
</head>
<body>

	<%
		if(session.getAttribute("user")!=null){
			User user = (User)session.getAttribute("user");
			System.out.println(user.getPath());
			int idx =  user.getPath().lastIndexOf("\\");
			String fileName = 	user.getPath().substring(idx+1);
	%>
			<div class="login">
		<div class="header">
			<h1>登录成功</h1>
		</div>
		<div class="content">
			<table align="center">
				<tr>
					<td align="center"><img src="/reg_login/upload/<%= fileName %>" /></td>
				</tr>
				<tr>
					<td align="center">欢迎<%= user.getNickname()%>,登录成功！</td>
				</tr>
			</table>

		</div>
	</div>	
		<%
			}else{
		%>
		<div class="login">
			<div class="header">
				<h1>你还没有登陆！请先去<a href="/reg_login/login.jsp">登陆</a></h1>
			</div>
		</div>
		<% 
		}
	%>

</body>
</html>