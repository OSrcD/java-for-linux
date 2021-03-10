package com.imooc.filter;

import java.io.IOException;

import javax.servlet.Filter;
import javax.servlet.FilterChain;
import javax.servlet.FilterConfig;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class SessionFilter implements Filter {

	@Override
	public void init(FilterConfig filterConfig) throws ServletException {
		
	}

	@Override
	public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain)
			throws IOException, ServletException {
		HttpServletRequest hrequest = (HttpServletRequest)request;
		HttpServletResponse	hresponse = (HttpServletResponse)response;
		
		String loginUser =(String)hrequest.getSession().getAttribute("loginUser");
		
		if(loginUser==null) {
			hresponse.sendRedirect(hrequest.getContextPath()+"/index.jsp?flag=1");
			return;
		}else {
			chain.doFilter(request, hresponse);
			return;
		}
		
	}

	@Override
	public void destroy() {

	}

}
