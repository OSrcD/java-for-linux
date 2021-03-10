package cn.java.servlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class RegisterServlet
 */
@WebServlet("/RegisterServlet")
public class RegisterServlet extends HttpServlet {

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String username = request.getParameter("username");
		String password = request.getParameter("password");
		String phone = request.getParameter("phone");
		String email = request.getParameter("email");
		String usernameRegex = "[a-zA-Z]{6,12}";
		String passwordRegex = "[0-9]{6,}";
		String phoneRegex = "[1][3578][0-9]{9}";
		String emailRegex ="[a-zA-Z_0-9]{3,}@([a-zA-Z]+|\\d+)(\\.[a-zA-Z]+)+";
		
		boolean flag1 = username.matches(usernameRegex);
		boolean flag2 = password.matches(passwordRegex);
		boolean flag3 = phone.matches(phoneRegex);
		boolean flag4 = email.matches(emailRegex);
		if(flag1 && flag2 && flag3 && flag4) {
			System.out.println("username="+username);
			System.out.println("password="+password);
			System.out.println("phone="+phone);
			System.out.println("email="+email);
		}else {
			System.out.println("亲，你输入的注册信息数据不满足格式要求,请检查仔细后在输入");
		}
		System.out.println(flag1+" "+flag2+" "+flag3+" "+flag4+" ");
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
