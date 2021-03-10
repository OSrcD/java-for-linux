<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
  <head>
    <title>java验证码</title>
  </head>
  <body>
      <img src="code.jsp" alt="" id="code">
      <a href="javascript:void(0);" onclick="changeCode()">看不清?点我</a>

      <script>
        function changeCode(){
            document.getElementById("code").src="code.jsp?d="+new Date().getTime();
        }
      </script>
  </body>
</html>
