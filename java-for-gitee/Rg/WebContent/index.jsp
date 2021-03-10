<%@ page language="java" contentType="text/html; charset=utf-8"
	pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>注册页面</title>
</head>
<body>
	<center>
		<form action="/Rg/RegisterServlet" method="post">
			<p>
				用户名:<input type="text" name="username" pattern="[a-zA-Z]{6,12}"
					required="required" placeholder="请输入6-12位的字母">
			</p>
			<p>
				密&nbsp;码:<input type="password" name="password" pattern="[0-9]{6,}"
					required="required" placeholder="请输入至少6位数字">
			</p>
			<p>
				手机号:<input type="text" name="phone" pattern="1[3578]\d{9}"
					required="required" placeholder="请输入手机号">
			</p>
			<p>
				邮&nbsp;箱:<input type="email" name="email" placeholder="请输入邮箱"
					required="required" >
			</p>
			<p>
				<input type="submit" value="注册"> <input type="reset">
				<input type= "reset" value="重置" >
			</p>
			</form>
	</center>
</body>
</html>