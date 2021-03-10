package com.opendevel.jdbc.servlet;

import com.opendevel.jdbc.bean.Message;
import com.opendevel.jdbc.bean.User;
import com.opendevel.jdbc.service.MessageService;

import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Objects;

/**
 * 留言处理Servlet
 */


public class MessageServlet extends HttpServlet {

    private MessageService messageService;



    @Override
    public void init(ServletConfig config) throws ServletException {
        super.init(config);
        messageService = new MessageService();
    }

    @Override
    public void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String pathName = request.getServletPath();
        //进入留言
        if(Objects.equals("/addMessagePrompt.do", pathName)){
            request.getRequestDispatcher("/WEB-INF/views/biz/add_message.jsp").forward(request, response);
        }else if(Objects.equals("/addMessage.do",pathName)){
            //保存message信息
            User user = (User)request.getAttribute("user");
            if(null == user){
                request.getRequestDispatcher("/message/list.do").forward(request, response);
            }else{
                String title = request.getParameter("title");
                String content = request.getParameter("content");
                boolean result = messageService.addMessage(new Message(user.getId(), user.getName(), title, content));

                if(result){
                    request.getRequestDispatcher("/message/list.do").forward(request, response);
                }else{
                    request.getRequestDispatcher("/WEB-INF/views/biz/add_message.jsp").forward(request, response);
                }
            }
        }else{
            request.getRequestDispatcher("/WEB-INF/views/error/404.jsp").forward(request, response);
        }
    }
}
