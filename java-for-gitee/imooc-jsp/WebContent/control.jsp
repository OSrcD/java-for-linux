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
			<h3 align="right">������:<%= application.getAttribute("count")%></h3>
			
		
	
	<h3 align="right">��½�˺ţ�<%=session.getAttribute("account") %></h3>
	<%=request.getAttribute("name") %>
	<h3>��Ӧ���ַ����뼯��<%=response.getCharacterEncoding()%></h3>
	<h3 align="center">��ӭ�������¹���ϵͳ����ҳ</h3>
	<hr>
	<table align="center" border="1" width="500px" >
		<tr>
			<td>�˺�</td>
			<td>Ա������</td>
			<td>����</td>
			<td>
				�޸�
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
				<a href="update.jsp?account=<%= e.getAccount()%>&name=<%= e.getName()%>&email=<%=e.getEmail()%>">�޸�</a>
			</td>
		</tr>

		<%
			}
		%>
	</table>
	<%
		} else {
			throw new Exception("�˻����������");
		}
	%>
</body>
</html>