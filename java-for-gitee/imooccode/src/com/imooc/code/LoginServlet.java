package com.imooc.code;

import com.google.code.kaptcha.Constants;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;


public class LoginServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        request.setCharacterEncoding("UTF-8");
        response.setCharacterEncoding("UTF-8");

        PrintWriter out =  response.getWriter();

        String code = request.getParameter("code");

        String sessionCode = (String) request.getSession().getAttribute(Constants.KAPTCHA_SESSION_KEY);

        if(code !=null && sessionCode !=null){
            if(code.equalsIgnoreCase(sessionCode)){
                out.print("success");
            }
        }else{
                out.print("fail");
        }

        out.flush();
        out.close();

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}
