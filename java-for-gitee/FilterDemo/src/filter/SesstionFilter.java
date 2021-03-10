package filter;

import java.io.IOException;

import javax.servlet.Filter;
import javax.servlet.FilterChain;
import javax.servlet.FilterConfig;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class SesstionFilter  implements Filter {

	@Override
	public void init(FilterConfig filterConfig) throws ServletException {
		
	}

	@Override
	public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain)
			throws IOException, ServletException {
		
		HttpServletRequest hRequest = (HttpServletRequest)request;
		HttpServletResponse hResponse = (HttpServletResponse)response;
		
	
		String loginUser = (String)hRequest.getSession().getAttribute("loginUser");
		System.out.println(loginUser);
		if(loginUser==null) {
			hResponse.sendRedirect(hRequest.getContextPath()+"/index.jsp?flag=1");
			System.out.println("2");
			return;
		}else {
			chain.doFilter(hRequest, hResponse);
			return;
		}
		
	}

	@Override
	public void destroy() {
		
	}

}
