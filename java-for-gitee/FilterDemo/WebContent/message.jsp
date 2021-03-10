<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
 <%@ page import="java.util.*,model.*" %>
<%
	String user = (String)session.getAttribute("loginUser");
	
	String subFlag = request.getParameter("subFlag");
	
	List<Message> messages = (List<Message>)session.getAttribute("messages");
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>留言板</title>
<link href="form.css" rel="stylesheet" type="text/css"/>
<link href="table.css" rel="stylesheet" type="text/css"/>

<script type="text/javascript">
 var subFlag = '<%=subFlag%>';
 if('1'==subFlag){
	alert('留言成功!'); 
 }
</script>
</head>
<body>
	<form action="messageSub.jsp" method="post" class="smart-green">
	<h1>留言板</h1>
	<label>
	<span>留言人 :</span>
	<input id="user" type="text" name="user" value="<%=user %>" readonly/>
	</label>

	<label>
	<span>标题 :</span>
	<input id="title" type="text" name="title" value=""/>
	</label>

	<label>
	<span>内容 :</span>
	<textarea id="content" name="content"></textarea>
	</label>

	<span>&nbsp;</span>
	
	<label>
	<input type="submit" class="button" value="提交"/>
	</label>
  </form>
    <br/>
    <table id="table-3" width="85%" align="center">
    <tr>
      <th width="15%">留言人</th>
      <th width="15%">标题</th>
      <th width="70%">内容</th>
    </tr>
    <%
    	if(messages!=null){
    		for(Message message:messages){
    		%>
    		<tr>
    			<td><%=user %>></td>
    			<td><%=message.getTitle() %></td>
    			<td><%=message.getContent() %></td>
    		</tr>
    		<% 
    		}
    	}
    %>
</body>
</html>