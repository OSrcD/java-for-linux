<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Insert title here</title>
</head>
<body>
<%
	int sum=0;
	for(int i=1;i<101;i++){
		sum+=i;
	}
	out.println("1-100的和是:"+sum);
%>
</body>
</html>