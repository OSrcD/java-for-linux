package com.imooc.servlet;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.commons.fileupload.FileItem;
import org.apache.commons.fileupload.FileUploadException;
import org.apache.commons.fileupload.disk.DiskFileItemFactory;
import org.apache.commons.fileupload.servlet.ServletFileUpload;

import com.imooc.domain.User;

import utils.UploadUtils;

public class RegisterServlet extends HttpServlet {

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		

	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		try {
			
			Map<String,String> map  = new HashMap<String, String>();
			DiskFileItemFactory diskFileItemFactory = new DiskFileItemFactory();
			
			ServletFileUpload servletFileUpload = new ServletFileUpload(diskFileItemFactory);

			List<FileItem> list = servletFileUpload.parseRequest(request);
			List<String> hobbyList = new ArrayList<String>();
			String url=null;
			for (FileItem fileItem : list) {
				if(fileItem.isFormField()) {
					String name= fileItem.getFieldName();
					String value = fileItem.getString("UTF-8");
					System.out.println(name+" "+value);
					if(name.equals("hobby")) {
						String hobbyValue = fileItem.getString("UTF-8");
						hobbyList.add(hobbyValue);
						hobbyValue = hobbyList.toString().substring(1,hobbyList.toString().length()-1);
						System.out.println(name+"   "+hobbyValue);
						map.put(name, hobbyValue);
					}else {
						map.put(name, value);
					}
				}else{
					String fileName = fileItem.getName();
					if(fileName !=null && !"".equals(fileName)) {
						String uuidFIleName = UploadUtils.getUUIDFIleName(fileName);
						InputStream is = fileItem.getInputStream();
						String path = this.getServletContext().getRealPath("/upload");
						
						 url = path+"\\"+uuidFIleName;
						System.err.println(url);
						OutputStream os = new FileOutputStream(url);
						int len=0;
						byte [] bytes = new byte [1024]  ;
						while((len = is.read(bytes)) != -1) {
							os.write(bytes, 0, len);
							System.out.println(len);
							
						}
						
						is.close();
						os.close();
					}
					
					
				}
			}
			System.out.println(map);
			
			List<User> userList =(List<User>)this.getServletContext().getAttribute("list");
			for(User u :userList) {
				if(u.getUsername().equals(map.get("username"))) {
					request.setAttribute("msg", "用户名已经存在！");
					request.getRequestDispatcher("/regist.jsp").forward(request, response);
					return ;
				}
			}
			User user = new User();
			user.setUsername(map.get("username"));
			user.setPassword(map.get("password"));
			user.setSex(map.get("sex"));
			user.setNickname(map.get("nickname"));
			user.setHobby(map.get("hobby"));
			user.setPath(url);;
			
			
			userList.add(user);
			
			
			for(User u : userList) {
				 System.out.println(u);
			}
			
			this.getServletContext().setAttribute("list", userList);
			
			request.getSession().setAttribute("username", user.getUsername());
			response.sendRedirect(request.getContextPath()+"/login.jsp");
		} catch (FileUploadException e) {
			e.printStackTrace();
		}
	}

}
