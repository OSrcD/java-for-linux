<%@ page import="com.imooc.code.CaptchaCode" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%

    response.setHeader("pragma","no-cache");
    response.setHeader("cache-control","no-cache");
    response.setHeader("expires","0");
    String code = CaptchaCode.drawImageVerificate(response);
    session.setAttribute("code",code);

    out.clear();
    out = pageContext.pushBody();

%>
