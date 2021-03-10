package com.imooc.sso.servlet;

import org.apache.http.HttpEntity;
import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.util.EntityUtils;

import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Objects;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class MainServlet extends HttpServlet {
    private ExecutorService service = Executors.newFixedThreadPool(10);
    private String servers;

    private void syncCookie(String server,String ticket, String method){
        service.submit(new Runnable() {
            @Override
            public void run() {
                HttpPost httpPost = new HttpPost(server + "/" + method + "?ticket=" + ticket);
                CloseableHttpClient httpClient = null;
                CloseableHttpResponse response = null;
                try {
                    httpClient = HttpClients.createDefault();
                    response = httpClient.execute(httpPost);
                    HttpEntity entity = response.getEntity();
                    String responseContent = EntityUtils.toString(entity, "UTF-8");
                    System.out.println("=====================" + responseContent);

                }catch (Exception e){
                    e.printStackTrace();
                }finally{
                    try {
                        if (null != response) {
                            response.close();
                        }
                    }catch (IOException e){
                        e.printStackTrace();
                    }
                    try {
                        if (null != httpClient) {
                            httpClient.close();
                        }
                    }catch (IOException e){
                        e.printStackTrace();
                    }
                }
            }
        });
    }

    @Override
    protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        if(Objects.equals("/main",request.getServletPath())){
            String domains = request.getParameter("domains");
            String ticket  = request.getParameter("ticket");
            if(null != domains){
                this.servers = domains;
            }
            if(null != domains && null != ticket) {
                for (String server : domains.split(",")) {
                    if (!Objects.equals(null, server) && !Objects.equals("", server.trim())) {
                        syncCookie(server, ticket,"setCookie");
                    }
                }
            }
            request.getRequestDispatcher("/WEB-INF/views/main.jsp").forward(request, response);

        }else if(Objects.equals("/setCookie",request.getServletPath())){
            String ticket = request.getParameter("ticket");
            response.addCookie(new Cookie("Ticket_Granting_Ticket", ticket));
            response.setCharacterEncoding("UTF-8");
            response.setContentType("application/text; charset=utf-8");
            PrintWriter out =null;
            try {
                out = response.getWriter();
                out.write("ok");
            }catch (IOException e){
                e.printStackTrace();
            }finally{
                if (out !=null){
                    out.close();
                }
            }

        }else if (Objects.equals("/logout",request.getServletPath())){
            Cookie cookie = new Cookie("Ticket_Granting_Ticket",null);
            cookie.setMaxAge(0);
            response.addCookie(cookie);
            if(null != servers){
                for(String server : servers.split(",")){
                    if(!Objects.equals(null, server) && !Objects.equals("", server.trim())){
                        syncCookie(server,"","removeCookie");
                    }
                }
            }
            request.getRequestDispatcher("/WEB-INF/views/logout.jsp").forward(request,response);

        }else if(Objects.equals("/removeCookie", request.getServletPath())){
            Cookie cookie = new Cookie("Ticket_Granting_Ticket", null);
            cookie.setMaxAge(0);
            response.addCookie(cookie);

            response.setCharacterEncoding("UTF-8");
            response.setContentType("application/text; charset=utf-8");

            PrintWriter out = null;
            try {
                out = response.getWriter();
                out.write("ok logout");
            }catch (IOException e){
                e.printStackTrace();
            }finally {
                if(null != out){
                    out.close();
                }
            }

        }
    }

}
