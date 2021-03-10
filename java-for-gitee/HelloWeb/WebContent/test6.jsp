<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="java.util.*" %>
<%@ page import="java.text.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Insert title here</title>
</head>
<body>
<%!
	public String getNow(){
		SimpleDateFormat sdformat = new SimpleDateFormat("YYY/MM/DD hh:mm:ss");
		Date currenDate = new Date();
	
		return sdformat.format(currenDate);
		
	}

%>

<%=getNow()%>
</body>
</html>