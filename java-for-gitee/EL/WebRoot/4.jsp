<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>jst的if标签和choose标签</title>
</head>
<body>
	<c:set var="age" value="12" scope="request"></c:set>
	
	<!--<c:if test="${age==12}">
		你的年龄为12
	</c:if>
	<hr/>
	-->
	
	<c:choose>
		<c:when test="${age==12 }">
			你的年龄为12岁
		</c:when>
		<c:otherwise>
			你的年龄不是12岁
		</c:otherwise>
	</c:choose>
</body>
	
</html>