<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>监听器Demo</title>
</head>
<body>
	<h1>首页</h1>
	
	<label>
		<span>ServletRequesttListener测试</span>
		<a href="servlet_request.jsp?par=request_par" target="_blank">初始化</a>
	</label>
	<br/>
	
	<label>
		<span>ServletRequesttListener测试</span>
		<a href="attribute_init.jsp" target="_blank">属性初始化</a>
	</label>
	
		<label>
		<span>BindingListener测试</span>
		<a href="bound.jsp" target="_blank">绑定测试</a>
		<a href="unbound.jsp" target="_blank">解绑测试</a>
	</label>
</body>
</html>