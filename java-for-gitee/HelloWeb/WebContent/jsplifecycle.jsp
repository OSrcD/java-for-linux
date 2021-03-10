<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
 <%!
 	int initVar = 0;
 	int destroyVar = 0;
 	int serviceVar = 0;
 
 	public void jspInit(){
 		initVar++;
 		System.out.println("jspInit:"+initVar);
 	}
 	
 	public void jspDestroy(){
 		destroyVar++;
 		System.out.println("destroyVar:"+initVar);
 	}
 	
 %>
 
 
 <%
 	serviceVar++;
 	
 %>
 
 <%=initVar%>
  <%=destroyVar%>
  <%=serviceVar%>
</body>
</html>