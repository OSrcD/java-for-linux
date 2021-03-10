<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>验证码对比分析</title>
    <style>#code{height:30px}</style>
</head>
<body>
    <form action="submit.action">

        <p>验证码：<input type="text" name="kaptcha" id="code" maxlength="4" placeholder="请输入验证码" /> <img src="http://localhost:8080/imooccode_war_exploded/kaptcha.jpg"  id="changecode" /></p>
        <p><input type="button" value="登录" id="login" />
        <div id="result"></div>
    </form>
    <script src="js/jquery-1.12.4.min.js"></script>
    <script>
        $(function () {
            $("#changecode").on("click",function () {
                $(this).attr("src","http://localhost:8080/imooccode_war_exploded/kaptcha.jpg?d="+new Date().getTime())
            });
            $("#login").on("click",function () {
                var code = $("#code").val();
                var params = {"code":code};
                $.post("http://localhost:8080/imooccode_war_exploded/login",params,function(data){
                   if(data=="success"){
                       $("#result").html("验证码输入正确");
                   }else{
                       $("#result").html("验证码输入错误,请重新输入...");
                       $("#code").val("").focus();
                   }
                });
            })
        });
        
    </script>

</body>
</html>
