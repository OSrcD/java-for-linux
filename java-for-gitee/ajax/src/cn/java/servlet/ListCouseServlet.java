package cn.java.servlet;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.json.JSONObject;


@WebServlet("/ListCouseServlet")
public class ListCouseServlet extends HttpServlet {
	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		//1、获取ajax传递过来的参数信息
		String flag = request.getParameter("flag");
		//2、需要返回的数据信息
		String data = "";
		if("1".equals(flag)){//Java课程
			data = "Java从入门到精通<br>java框架";
		}else if("2".equals(flag)){//C课程
			data = "C程序设计<br>C项目实战";
		}
		//3、将数据信息回写给ajax
		response.getOutputStream().write(data.getBytes("utf-8"));
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request,response);
	}

}
