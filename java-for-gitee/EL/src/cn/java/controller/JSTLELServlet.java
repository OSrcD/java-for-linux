package cn.java.controller;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


@WebServlet("/JSTLELServlet")
public class JSTLELServlet extends HttpServlet {
       
  

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		Map<String, Object> dataMap1 = new HashMap<String, Object>();
		dataMap1.put("shopName", "联想笔记本");
		dataMap1.put("address","北京");
		dataMap1.put("price",4999.99);
		Map<String, Object> dataMap2 = new HashMap<String, Object>();
		dataMap2.put("shopName", "神州笔记本");
		dataMap2.put("address","南京");
		dataMap2.put("price",3999.99);
		List<Map<String, Object>> lists = new ArrayList<Map<String,Object>>();
		
		lists.add(dataMap1);
		lists.add(dataMap2);
		request.setAttribute("list", lists);
		
		request.getRequestDispatcher("/5.jsp").forward(request, response);;
	}


	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
