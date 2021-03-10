package com.opendevel.jdbc.servlet;

import com.opendevel.jdbc.bean.User;
import com.opendevel.jdbc.service.UserService;
import com.sun.org.apache.xml.internal.security.Init;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Objects;

/**
 * 用户Servlet
 */
public class UserServlet extends HttpServlet {

    private UserService userService;

    @Override
    public void init() throws ServletException {
        userService = new UserService();
    }

    @Override
    protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String pathName = request.getServletPath();

        if(Objects.equals("/userInfo.do",pathName)){
            //查看用户编辑信息
            request.getRequestDispatcher("/WEB-INF/views/biz/user.jsp").forward(request, response);
        }else if (Objects.equals("/editUserPrompt.do",pathName)){
            //进入编辑用户信息的页面
            Long id = Long.valueOf(request.getParameter("id"));
            User user = userService.getUserById(id);
            if(null != user){
                request.setAttribute("user", user);
                request.getRequestDispatcher("/WEB-INF/views/biz/edit_user.jsp").forward(request, response);

            }else{
                request.getRequestDispatcher("/WEB-INF/views/biz/user.jsp").forward(request, response);

            }
        }else if(Objects.equals("/editUser.do", pathName)){
            //修改
            Long id = Long.valueOf(request.getParameter("id"));
            String name = request.getParameter("name");
            String password = request.getParameter("password");
            String realName = request.getParameter("realName");
            String birthday = request.getParameter("birthday");
            String phone = request.getParameter("phone");
            String address = request.getParameter("address");

            User user = new User();
            user.setId(id);
            user.setName(name);
            user.setPassword(password);
            user.setRealName(realName);
            try {
                user.setBirthday(new SimpleDateFormat("yyyy-MM-dd").parse(birthday));
            } catch (ParseException e) {
                System.out.println("格式化Birthday字段失败");
                e.printStackTrace();
            }
            user.setPhone(phone);
            user.setAddress(address);
            boolean result = userService.updateUser(user);
            if(result){
                request.getSession().setAttribute("user",user);
                request.setAttribute("user", user);
                request.getRequestDispatcher("/WEB-INF/views/biz/user.jsp").forward(request, response);

            }else{
                request.getRequestDispatcher("/WEB-INF/views/error/404.jsp").forward(request, response);
            }
        }else{
            request.getRequestDispatcher("/WEB-INF/views/error/404.jsp").forward(request, response);
        }
    }
}
