package cn.java.servlet;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.xml.ws.Response;

public class LoginServlet extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
			String username = request.getParameter("username");
			String password = request.getParameter("password");
			
			System.out.println("username="+username);
			System.out.println("password="+password);
			
			if(username.equals("admin") && password.equals("123")) {
				request.getRequestDispatcher("/success.jsp").forward(request, response);;
			}else {
				//request.getRequestDispatcher("/fail.jsp").forward(request, response);
				response.sendRedirect("/imooc_servlet/fail.jsp");
			}
	}
	
	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		doGet(req, resp);
	
	}
}
