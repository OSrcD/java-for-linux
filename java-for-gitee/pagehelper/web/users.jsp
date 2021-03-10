<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core"  prefix="c"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'users.jsp' starting page</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->

  </head>
  
  <body>

    <table align="center" width="80%" border="1">
      <tr><td>id</td><td>username</td><td>address</td></tr>

      <c:forEach items="${requestScope.page.records}" var="user">

          <tr><td>${user.id} </td><td>${user.username}</td><td>${user.address}</td></tr><br>

      </c:forEach>
    </table>




    <div align="center">

    共${requestScope.page.totalSize}条/共${requestScope.page.totalPageNum}页
  <a href="${pageContext.request.contextPath}/servlet/UserServlet?method=all&num=1">首页</a>

  <a href="${pageContext.request.contextPath}/servlet/UserServlet?method=all&num=${requestScope.page.prePageNum}">上一页</a>
  <c:forEach  begin="${requestScope.page.startPageNum}" end="${requestScope.page.endPageNum}" var="num">
   <a href="${pageContext.request.contextPath}/servlet/UserServlet?method=all&num=${num}">${num}</a>
  
 </c:forEach>
  
  <a href="${pageContext.request.contextPath}/servlet/UserServlet?method=all&num=${requestScope.page.nextPageNum}">下一页</a>
  <a href="${pageContext.request.contextPath}/servlet/UserServlet?method=all&num=${requestScope.page.totalPageNum}">末页</a>
  
  
  跳转到
  <input id="number" type="text" name="hello" size="6">页<input type="button" value="跳转" onclick="changeNumber()"></input>
  
  <script>
    function changeNumber()
    {
       var num=document.getElementById("number").value;
       
       
       
       //是否是数字  输入的数字一定是整数或者是小于总页数的值
       
      window.location.href="${pageContext.request.contextPath}/servlet/UserServlet?method=all&num="+num;
       
    
    
    }
  
  
  
  </script>
  
    
    </div>
    
    
    
  </body>
</html>
