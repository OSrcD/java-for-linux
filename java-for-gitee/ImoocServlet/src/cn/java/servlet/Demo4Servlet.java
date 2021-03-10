package cn.java.servlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.jasper.tagplugins.jstl.core.Out;

import javafx.application.Application;
@WebServlet("/Demo4Servlet")
public class Demo4Servlet extends HttpServlet {


	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
//		request.setAttribute("username", "Íõ¶þÂé×Ó");
//		request.getRequestDispatcher("/demo.jsp").forward(request,response);
		
		ServletContext sc = request.getServletContext();
		sc.setAttribute("goods", "ÍÞÍÞ");
		PrintWriter pw=response.getWriter();
		pw.write(request.getServletContext().getContextPath());
	
		//	response.sendRedirect("/imooc_servlet/demo.jsp");
		
	}
	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
