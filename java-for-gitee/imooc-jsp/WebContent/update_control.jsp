<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8" import="com.imooc.db.*,com.imooc.bean.*,java.util.*"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Insert title here</title>
</head>
<body>
	<%
		Map<String,Emp> map = DBUtil.map;
		Emp emp = map.get(request.getParameter("account"));
		emp.setName(request.getParameter("name"));
		emp.setEmail(request.getParameter("email"));

	%>
	<h3 align="center">修改员工信息成功.</h3>
</body>
</html>