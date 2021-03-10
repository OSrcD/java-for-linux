<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
<%!int totalCount=0; %>
<%
	int localCount=0;
	totalCount++;
	localCount++;
%>
<%
	out.println(totalCount);
	out.println("<br>");
	out.println(localCount);
%>
</body>
</html>