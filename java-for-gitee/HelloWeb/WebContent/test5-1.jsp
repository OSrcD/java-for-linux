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
		int x=-5;
		int y=0;
		if(x<0){
	%>
	<div style="text-align:center;">
		当x<0时，输出
		<br>
		x=-5;
		<br>
		y=-1;
		<br>
	</div>
	<%}else if(x==0){%>
		<div style="text-align=center">
		当x=0时，输出
		x=-5;
		y=0;
	</div>
	<%}else{ %>
		<div style="text-align=center">
		当x=0时，输出
		x=-5;
		y=0;
	</div>
	<%} %>
</body>
</html>