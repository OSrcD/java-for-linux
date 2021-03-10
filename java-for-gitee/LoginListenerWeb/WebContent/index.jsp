<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    
 <%
 	String flag = request.getParameter("flag");
 %> 
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<link href="form.css" rel="stylesheet" type="text/css" />
<title>Login</title>
<script type="text/javascript">
	var flag = '<%=flag%>';
	if("1"==flag){
		alert("你尚未登录，或者账号在异地登录,请重新登录！");	
	}
</script>
</head>
<body>
<form action="login.jsp" method="post" class="smart-green">
	<h1>系统登录</h1>

	<label>
	<span>用户名:</span>
	<input id="username" type="text" name="username"/>
	</label>

	<label>
	<span>密码:</span>
	<input id="password" type="password" name="password"/>
	</label>

	<span>&nbsp;</span>

	<label>
	<input type="submit" class="button" value="登录"/>
	</label>
	
  </form>
</body>
</html>