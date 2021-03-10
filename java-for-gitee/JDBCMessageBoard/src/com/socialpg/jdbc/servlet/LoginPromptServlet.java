package com.opendevel.jdbc.servlet;

import com.opendevel.jdbc.bean.User;
import com.opendevel.jdbc.service.UserService;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

/**
 * 跳转到登录页面的Servlet
 */

public class LoginPromptServlet extends HttpServlet {



    @Override
    protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.getRequestDispatcher("/WEB-INF/views/biz/login.jsp").forward(request, response);

    }
}
