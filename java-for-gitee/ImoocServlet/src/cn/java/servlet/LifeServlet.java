package cn.java.servlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


@WebServlet("/LifeServlet")
public class LifeServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	
	
	
	
	
	@Override
	public void init(ServletConfig config) throws ServletException {
		System.out.println("Servlet的init方法");
	}


	@Override
	protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		System.out.println("Servlet被请求了");
	}
	
	
	@Override
	public void destroy() {
		System.out.println("Servlet被销毁");
		super.destroy();
	}
}
