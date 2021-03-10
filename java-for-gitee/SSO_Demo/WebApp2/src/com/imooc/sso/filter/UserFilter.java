package com.imooc.sso.filter;

import javax.servlet.*;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Objects;

public class UserFilter implements Filter {
    private String server;
    private String app;

    @Override
    public void init(FilterConfig filterConfig) throws ServletException {
        server = filterConfig.getInitParameter("server");
        app = filterConfig.getInitParameter("app");
    }

    @Override
    public void doFilter(ServletRequest request, ServletResponse response, FilterChain filterChain) throws IOException, ServletException {
        if(Objects.equals("/ssoLogout",((HttpServletRequest)request).getServletPath())){
            ((HttpServletResponse)response).sendRedirect(server + "/ssoLogout?source="+app);
            return;
        }

        String ticket = null;
        if(null != ((HttpServletRequest)request).getCookies()){
            for(Cookie cookie : ((HttpServletRequest)request).getCookies()){
                if(Objects.equals(cookie.getName(),"Ticket_Granting_Ticket")){
                    ticket = cookie.getValue();
                    break;
                }
            }
        }


        if(!Objects.equals(null, ticket)){
            String [] value = ticket.split(":");
            ticket = request.getParameter("ticket");
            if(Long.valueOf(value[1])<System.currentTimeMillis()){
                if(Objects.equals(null,ticket)){
                    ((HttpServletResponse)response).sendRedirect(server + "/ssoLogin?source="+app);
                    return;
                }else{
                    ticket = ticket + ":" + (System.currentTimeMillis()+10000);
                    ((HttpServletResponse)response).addCookie(new Cookie("Ticket_Granting_Ticket",ticket));
                    filterChain.doFilter(request,response);
                    return;
                }

            }
            filterChain.doFilter(request,response);
            return;
        }

        ticket = request.getParameter("ticket");
        if(!Objects.equals(null, ticket) && !Objects.equals("", ticket.trim())){
            ticket = ticket + ":" + (System.currentTimeMillis()+10000);
            ((HttpServletResponse)response).addCookie(new Cookie("Ticket_Granting_Ticket",ticket));
            filterChain.doFilter(request,response);

        }else{
            ((HttpServletResponse)response).sendRedirect(server + "/ssoLogin?source="+app);
        }

    }

    @Override
    public void destroy() {

    }
}
