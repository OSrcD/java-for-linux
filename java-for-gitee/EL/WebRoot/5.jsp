<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>通过jstl+表达式迭代List集合</title>
</head>
<body>
	<center>
		<table border="1px" cellspacing="0px" >
			<tr>
					<td>商品名称</td>
					<td>产地</td>
					<td>价格</td>
				</tr>
			<c:forEach items="${list }" var="Map">
				<tr>
					<td>${Map.shopName}</td>
					<td>${Map.address}</td>
					<td>${Map.price}</td>
				</tr>
			</c:forEach>
		</table>
	</center>
</body>
	
</html>