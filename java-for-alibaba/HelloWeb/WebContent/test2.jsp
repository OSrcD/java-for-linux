<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
<% int i=10;%>
<%
	if(i>10){
		out.println("i>10");
	}else{
		out.println("i<=10");
	}
%>
<hr>
<%if(i>10){%>
<span>i>10</span>
<%}else{ %>
<span>i<=10</span>
<%} %>
</body>
</html>