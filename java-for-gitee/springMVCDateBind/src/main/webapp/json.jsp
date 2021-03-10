<%--
  Created by IntelliJ IDEA.
  User: Administrator.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<%--<script type="text/javascript" src="js/jquery-1.8.3.min.js"></script>--%>
<%--<script type="text/javascript">--%>

    <%--$(function(){--%>
        <%--var course = {--%>
            <%--"id":"8",--%>
            <%--"name":"SSM框架整合",--%>
            <%--"price":"200"--%>
        <%--};--%>
        <%--$.ajax({--%>
            <%--url:"jsonType",--%>
            <%--data:JSON.stringify(course),--%>
            <%--type:"post",--%>
            <%--contentType:"application/json;charse=UTF-8",--%>
            <%--dataType:"json",--%>
            <%--success:function(data){--%>
                <%--alert(data.name+"---"+data.price);--%>
            <%--}--%>
        <%--})--%>
    <%--})--%>

<%--</script>--%>
    <script type="text/javascript" src="js/jquery-1.8.3.min.js"></script>
    <script type="text/javascript">
       $(function(){
           var course = {
               "id":"8",
               "name":"SSM框架整合",
               "price":"200"
           };
           $.ajax({
               url:"jsonType",
               data:JSON.stringify(course),
               type:"post",
               contentType:"application/json;charset=UTF-8",
               dataType:"json",
               success:function(data){
                   alert(data.name+"---"+data.price);
               }
           })
       })
    </script>
<body>

</body>
</html>
