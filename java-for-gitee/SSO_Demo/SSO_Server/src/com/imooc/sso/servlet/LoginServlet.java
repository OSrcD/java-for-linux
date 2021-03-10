package com.imooc.sso.servlet;

import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Objects;
import java.util.UUID;

public class LoginServlet extends HttpServlet {
    private String domains;

    @Override
    public void init(ServletConfig config) throws ServletException {
        domains = config.getInitParameter("domains");
    }

    @Override
    protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        if(Objects.equals("/login",request.getServletPath())){
            String username = request.getParameter("username");
            String password = request.getParameter("password");
            String source  = request.getParameter("source");

            if(null == source || Objects.equals("", source)){
                String referer = request.getHeader("referer");
                source = referer.substring(referer.indexOf("source=")+7);

            }

            if(Objects.equals(username,password)){
                String ticket = UUID.randomUUID().toString().replace("-","");

                System.out.println("ticket*******************************:" + ticket);
                System.out.println("source*******************************:"+source);
                response.sendRedirect(source + "/main?ticket=" + ticket + "&domains=" +
                        domains.replace(source + ",", "").replace("," + source, "").replace(source, ""));
            }else{
                request.setAttribute("source",source);
                request.getRequestDispatcher("/WEB-INF/views/login.jsp").forward(request,response);
            }
        }else if (Objects.equals("/ssoLogin",request.getServletPath())){
            request.getRequestDispatcher("/WEB-INF/views/login.jsp").forward(request,response);
        }else if(Objects.equals("/ssoLogout", request.getServletPath())){
            String source = request.getParameter("source");

            if(null == source || Objects.equals("", source)){
                String referer = request.getHeader("referer");
                source = referer.substring(referer.indexOf("source=")+7);
            }

            response.sendRedirect(source + "/logout?domains="+
                    domains.replace(source+",", "").replace(","+source, ""
                    ).replace(source, ""));





        }
    }
}
