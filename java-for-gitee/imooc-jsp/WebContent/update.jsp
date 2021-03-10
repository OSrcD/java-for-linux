<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>员工更新页面</title>
</head>
<body>
	<h3>员工更新界面</h3>
	<hr/>
	<h3 align="right">登陆账号:<%= session.getAttribute("account") %></h3>
	<h3 align="left"><%=session.getMaxInactiveInterval() %></h3>
	<form action="update_control.jsp">
		<table align="center" border="1" width="500px">
			<tr>
				<td>账号</td>
				<td><input type="text" name="account" value="<%=request.getParameter("account")%>"/></td>
			</tr>
			<tr>
				<td>名字</td>
				<td><input type="text" name="name" value="<%= request.getParameter("name") %>" /></td>
			</tr>
			<tr>
				<td>邮箱</td>
				<td><input type="text" name="email" value="<%=request.getParameter("email") %>" /></td>
			</tr>
			<tr>
				<td colspan="2"><input type="submit" value="提交" /></td>
			</tr>
		</table>
	</form>
</body>
</html>