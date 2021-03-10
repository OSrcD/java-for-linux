package com.opendevel.cake.web;

import javax.servlet.*;
import java.io.IOException;

/**
 * 字符集过滤器
 */

public class CharsetEncodingFilter  implements Filter {
    private String encoding;
    public void init(FilterConfig filterConfig) throws ServletException {
        this.encoding  = filterConfig.getInitParameter("encoding");

    }

    public void doFilter(ServletRequest servletRequest, ServletResponse servletResponse, FilterChain filterChain) throws IOException, ServletException {
        servletRequest.setCharacterEncoding(encoding);
        filterChain.doFilter(servletRequest, servletResponse);
    }

    public void destroy() {

    }
}
