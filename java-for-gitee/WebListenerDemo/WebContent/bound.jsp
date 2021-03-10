<%@page import="com.imooc.model.User"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>

<%
	session.setAttribute("user",new User());
%>


<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>bound</title>
</head>
<body>
<h1>binding listener test</h1>
</body>
</html>