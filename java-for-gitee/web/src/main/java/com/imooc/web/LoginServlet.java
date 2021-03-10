package com.imooc.web;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.imooc.app.util.StringUtils;

public class LoginServlet extends HttpServlet {

	@Override
	public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		this.doPost(request, response);
	}

	@Override
	public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("UTF-8");
		response.setCharacterEncoding("UTF-8");
		
		String username = request.getParameter("username");
		
		String password = request.getParameter("password");
	
		System.out.println("用户名是"+username);
		System.out.println("密码是"+password);
		
		if(StringUtils.isEmpty(username) && StringUtils.isEmpty(password)) {
			response.sendRedirect("fail.jsp");
		}else {
			response.sendRedirect("success.jsp");
		}
		
		
	}
	
	
	

}
