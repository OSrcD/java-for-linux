package com.imooc.project.filter;

import java.io.IOException;

import javax.servlet.Filter;
import javax.servlet.FilterChain;
import javax.servlet.FilterConfig;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class LoginFilter implements Filter {

	public void destroy() {

	}

	public void doFilter(ServletRequest req, ServletResponse res,
			FilterChain chain) throws IOException, ServletException {
		 
		 //session
		HttpServletRequest request=(HttpServletRequest)req;
		
		HttpServletResponse response=(HttpServletResponse)res;
		
		HttpSession session=request.getSession();
		
	    String requestUrl=request.getRequestURI();
	    
	    if(requestUrl.contains("login.jsp")|| requestUrl.contains("Loginservlet"))
	    {
	    	chain.doFilter(req, res);
	    	return;
	    }
		
		if(null==session.getAttribute("loginUser"))
		{
			response.sendRedirect("login.jsp");
			return;
		}
		else
		{
			chain.doFilter(req, res);
		}
		
		
		
		
		
		
		
		
		
		
		
		

	}

	public void init(FilterConfig arg0) throws ServletException {

	}

}
