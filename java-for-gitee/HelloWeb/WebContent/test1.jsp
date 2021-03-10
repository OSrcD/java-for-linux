<%@page import="org.eclipse.jdt.internal.compiler.ast.ThisReference"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
<%!
	String str = "Hello World!";
	String getStr(){
		return "Hello World2!";
	}
%>
<hr>
<% 
	out.println(this.str);
	
%>
<hr>
<%=
 this.getStr()
%>

</body>
</html>