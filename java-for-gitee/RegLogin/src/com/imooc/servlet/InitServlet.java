package com.imooc.servlet;

import java.util.ArrayList;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;

import com.imooc.domain.User;

/**
 * Servlet implementation class InitServlet
 */
public class InitServlet extends HttpServlet {
	@Override
	public void init() throws ServletException {
		List<User> list = new ArrayList<User>();
		this.getServletContext().setAttribute("list",list);
	}
}
