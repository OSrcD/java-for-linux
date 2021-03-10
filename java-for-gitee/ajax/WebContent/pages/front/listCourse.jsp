<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>
<!DOCTYPE html>
<html>
<head>
<base href="<%=basePath%>">
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>js调用ajax</title>
<style type="text/css">
	input{
		width:250px;
		height:25px;
	}
	#login{
		width:255px;
		height:35px;
		background-color:#FF2611;
		border:0px;
		cursor:pointer;
		color:white
	}
	.c1{
		font-size:24px;
		color:black;
		font-weight:bolder
	}
	.c2{
		font-size:14px;
		color:#666;
	}
	.c3{
		font-size:14px;
		color:red;
	}
</style>
</head>
<body style="text-align:center;">
			<input type="button" value="查看java课程" flag="1" onclick="showJava()">
			<input type="button" value="查看C课程" flag="2" onclick="showC()">
			<div style="width:400px,height:300px" id="div1">
			</div>
</body>
<script type="text/javascript">
	function showJava(){
		//1、创建一个 xmlhttpRequest对象
		var xmlhttp = new XMLHttpRequest();
		//2、规定请求的类型、URL 以及是否异步处理请求。
		xmlhttp.open("GET","<%=basePath%>/ListCouseServlet?flag=1",true);
		//3、将请求发送到服务器。
		xmlhttp.send();
		//4、接收服务器端的响应(readyState=4表示请求已完成且响应已就绪    status=200表示请求响应一切正常)
		xmlhttp.onreadystatechange=function(){
			if (xmlhttp.readyState==4 && xmlhttp.status==200){
				//responseText：表示的是服务器返回给ajax的数据
		    	document.getElementById("div1").innerHTML=xmlhttp.responseText;
		    	//alert(xmlhttp.responseText);
		    }
		}
	}
	
	function showC(){
		//1、创建一个 xmlhttpRequest对象
		var xmlhttp = new XMLHttpRequest();
		//2、规定请求的类型、URL 以及是否异步处理请求。
		xmlhttp.open("GET","<%=basePath%>/ListCouseServlet?flag=2",true);
		//3、将请求发送到服务器。
		xmlhttp.send();
		//4、接收服务器端的响应(readyState=4表示请求已完成且响应已就绪    status=200表示请求响应一切正常)
		xmlhttp.onreadystatechange=function(){
			if (xmlhttp.readyState==4 && xmlhttp.status==200){
				//responseText：表示的是服务器返回给ajax的数据
		    	document.getElementById("div1").innerHTML=xmlhttp.responseText;
		    	//alert(xmlhttp.responseText);
		    }
		}
	}
</script>
</html>