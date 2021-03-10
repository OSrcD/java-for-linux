package com.damu.servlet;

import com.damu.dao.UsersDAO;
import com.damu.entity.Users;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Date;

@WebServlet("/addusers")
public class UsersAddServlet extends HttpServlet {

    private UsersDAO usersDAO = new UsersDAO();
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doPost(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String username = req.getParameter("username");
        String userpass = req.getParameter("userpass");
        String nickname = req.getParameter("nickname");
        String age = req.getParameter("age");
        String gender = req.getParameter("gender");
        String email = req.getParameter("email");
        String phone = req.getParameter("phone");
        Users user = new Users(username,userpass,nickname,Integer.parseInt(age),gender,email,phone,new Date(),new Date(),new Date(),0,"232");

        user = usersDAO.addUser(user);

        resp.sendRedirect("/detail?id="+user.getId());
    }
}
