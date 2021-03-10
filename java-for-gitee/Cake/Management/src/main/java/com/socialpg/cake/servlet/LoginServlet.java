package com.opendevel.cake.servlet;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 * 登录
 */

public class LoginServlet extends HttpServlet {
    @Override
    protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        if("/login.do".equals(req.getServletPath())){
            String username = req.getParameter("username");
            String password = req.getParameter("password");

            //如果用户名和密码相同且不为空，则登录成功
            if(null != username && !"".equals(username.trim()) && username.equals(password)){
                req.getSession().setAttribute("username",username);

                System.out.println(req.getSession().getAttribute("username"));

                req.getRequestDispatcher("/cake/list.do").forward(req, resp);

            }else {
                req.getRequestDispatcher("/loginPrompt.do").forward(req, resp);
            }
        }else if("/loginPrompt.do".equals(req.getServletPath())){
            req.getRequestDispatcher("/WEB-INF/views/biz/login.jsp").forward(req, resp);

        }


    }
}
