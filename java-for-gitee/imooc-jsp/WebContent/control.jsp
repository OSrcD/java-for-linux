<%@ page language="java" contentType="text/html; charset=GBK" errorPage="error.jsp"
	pageEncoding="GBK"
	import="com.imooc.db.*,com.imooc.bean.*,java.util.*" %>
<!DOCTYPE html>
<html>
<head>
<title>Insert title here</title>
</head>
<body>
	<%
		String account = request.getParameter("account");
		String password = request.getParameter("password");

		Emp emp = new Emp(account, null, password, null);

		boolean flag = DBUtil.selectEmpByAccountAndPassword(emp);
		Map<String, Emp> map = DBUtil.map;
		if (flag) {
			Object o = application.getAttribute("count");
			if(o==null){
				application.setAttribute("count", 1);
			}else{
				int count=Integer.valueOf(o.toString());

				application.setAttribute("count",count+1);
			}
			session.setAttribute("account",account);
			session.setMaxInactiveInterval(5*60);
			%>
			<h3 align="right">访问量:<%= application.getAttribute("count")%></h3>
			
		
	
	<h3 align="right">登陆账号：<%=session.getAttribute("account") %></h3>
	<%=request.getAttribute("name") %>
	<h3>响应的字符编码集：<%=response.getCharacterEncoding()%></h3>
	<h3 align="center">欢迎来到人事管理系统的首页</h3>
	<hr>
	<table align="center" border="1" width="500px" >
		<tr>
			<td>账号</td>
			<td>员工姓名</td>
			<td>邮箱</td>
			<td>
				修改
			</td>
		</tr>
		<%
			for (String key : map.keySet()) {
					Emp e = map.get(key);
		%>
		<tr>
			<td>
				<%= e.getAccount() %>
			</td>
			<td>
				<%= e.getName() %>
			</td>
			<td>
				<%= e.getEmail()%>
			</td>
			<td>
				<a href="update.jsp?account=<%= e.getAccount()%>&name=<%= e.getName()%>&email=<%=e.getEmail()%>">修改</a>
			</td>
		</tr>

		<%
			}
		%>
	</table>
	<%
		} else {
			throw new Exception("账户和密码错误");
		}
	%>
</body>
</html>