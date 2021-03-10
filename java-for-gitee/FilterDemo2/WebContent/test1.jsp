<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>

<%
	request.getRequestDispatcher("/test2.jsp").forward(request, response);
%>

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Test1</title>
</head>
<body>
	<jsp:include page="test2.jsp"></jsp:include>
	<h1>Test1</h1>
</body>
</html>