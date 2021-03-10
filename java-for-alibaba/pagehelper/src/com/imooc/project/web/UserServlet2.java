package com.imooc.project.web;

import com.github.pagehelper.Page;
import com.github.pagehelper.PageHelper;
import com.github.pagehelper.PageInfo;
import com.imooc.project.entity.Person;
import com.imooc.project.service.UserService;
import com.imooc.project.service.impl.UserServiceImpl;
import com.imooc.project.util.PageUtil;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

@WebServlet("/servlet/UserServlet")
public class UserServlet2 extends HttpServlet {

	private UserService userService = new UserServiceImpl();

	public void doPost(HttpServletRequest request, HttpServletResponse response)
	throws ServletException, IOException {
		this.doGet(request, response);
 
		}
	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		String method = request.getParameter("method");

		if(method.equals("all")){
			selectAllUsers(request,response);
		}






//      String method=request.getParameter("method");
//
//      if(method.equals("all"))
//	  {
//	  	 selectAllUsers(request,response);
//	  }

	}

    //获取所有的用户信息
//	private void selectAllUsers(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
//	{
//
//        String num=request.getParameter("num");
//
//        if(null==num)
//		{
//			num="1";
//		}
//
//		PageUtil page=null;
//
//		try {
//			page=userService.getAllUsers(num);
//		} catch (Exception e) {
//			e.printStackTrace();
//		}
//		request.setAttribute("page",page);
//		request.getRequestDispatcher("/users.jsp").forward(request,response);
//
//	}
	


	private void selectAllUsers(HttpServletRequest request,HttpServletResponse response) throws ServletException,IOException{

		String num = request.getParameter("num");

		if(null==num){
			num="1";

		}

		//

		Page<?> page =PageHelper.startPage(Integer.parseInt(num),5);

		List<Person> persons = userService.getAllUsersBypageHelper();

		PageInfo<?> pageHelper = page.toPageInfo();

		request.setAttribute("persons",persons);

		request.setAttribute("pagehelper",pageHelper);

		request.getRequestDispatcher("/person.jsp").forward(request,response);





//		PageUtil page = null;
//
//		try {
//			page = userService.getAllUsers(num);
//		} catch (Exception e) {
//			e.printStackTrace();
//		}
//
//		request.setAttribute("page",page);
//		request.getRequestDispatcher("users.jsp").forward(request, response);


	}



}
