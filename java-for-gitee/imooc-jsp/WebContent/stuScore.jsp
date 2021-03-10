<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8" 
    import="com.imooc.bean.*,com.imooc.db.*,java.util.*"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Insert title here</title>
</head>
<body>
	<%!
	Map<String,Student>  map = new HashMap<String,Student>();
		
		public void jspInit(){
		map.put("1", new Student("11071011","赵明",78));
		map.put("2", new Student("11071012","赵明",78));
		map.put("3", new Student("11071013","赵明",78));
		map.put("4", new Student("11071014","赵明",78));
		map.put("5", new Student("11071015","赵明",78));
		map.put("6", new Student("11071016","赵明",78));
		}
	%>
	<%
		
		for(String key:map.keySet()){
			Student stu = map.get(key);
			out.println("第"+key+"条:"+stu);
			%>
			<br>
			<br>
			<%
		}
	
	%>
</body>
</html>