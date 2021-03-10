package com.damu.servlet;

import com.damu.dao.UsersDAO;
import com.damu.entity.Users;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/deluser")
public class UsersDelServlet  extends HttpServlet {

    private UsersDAO usersDAO = new UsersDAO();
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doPost(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
       String id = req.getParameter("id");
       String type = req.getParameter("type");

       if("lock".equals(type)){
           Users user = new Users();
           user.setId(Integer.parseInt(id));
           user.setUserStatus(1);
           usersDAO.updateUsers(user);
       }else if("del".equals(type)){
           usersDAO.delUsers(Integer.parseInt(id));
       }else if("unlock".equals(type)){
           Users user = new Users();
           user.setId(Integer.parseInt(id));
           user.setUserStatus(0);
           usersDAO.updateUsers(user);
       }

        resp.sendRedirect("/index");

    }
}
