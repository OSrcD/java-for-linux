<%@page import="org.eclipse.jdt.internal.compiler.ast.ThisReference"%>
<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<title>人事管理系统</title>
<style type="text/css">
	table,td{
		border:2px lightgray solid;
		border-collapse:collapse;
		background-color:lightblue;
	}
	h3{
		color:lightblue;
	}
	
	table{
		
		margin:0 auto;
	}
	
	
</style>
</head>

<body>
	config对象：<%=config.getServletName() %>
	<br/>
	config获取初始化参数：<%=config.getInitParameter("age") %>
	<%
		pageContext.setAttribute("age",12);
	%>
	<br/>
	pageContext作用域中获取的值：<%= pageContext.getAttribute("age") %>
	<% 
		//request.setAttribute("name","Imooc");
	   //request.getRequestDispatcher("result.jsp").forward(request,response);
	%>
	<h3 align="center">人事管理系统登陆页面</h3>
	<hr>
	<!-- action代表了服务器端的处理程序 -->
	<form action="control.jsp">
		<table>
			<tr>
				<td>
					账号:
				</td>
				<td>
					<input type="text" name="account"/>
				</td>
			</tr>
			<tr>
				<td>
					密码:
				</td>
				<td>
					<input type="password" name="password" />
				</td>
			</tr>
			<tr>
				<td>
					<input type="submit" value="登陆"/>
				</td>
			</tr>
		</table>
	</form>
</body>
</html>