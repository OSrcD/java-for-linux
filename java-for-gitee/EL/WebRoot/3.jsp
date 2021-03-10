<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>jstlc常用标签</title>
</head>
<body>
	<c:set var="user" value="张三" scope="request" ></c:set>
	<hr/>
	<c:out value="${user}"></c:out>
	<hr/>
	<c:remove var="user" scope="request" />
	<hr/>
	<c:out value="${user}"></c:out>
</body>
	
</html>