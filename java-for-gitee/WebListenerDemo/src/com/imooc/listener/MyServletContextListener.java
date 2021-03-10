package com.imooc.listener;

import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;

public class MyServletContextListener implements ServletContextListener {

	@Override
	public void contextInitialized(ServletContextEvent sce) {
	
		String appName = (String)sce.getServletContext().getInitParameter("app_name");
		String version = (String)sce.getServletContext().getInitParameter("version");
		
		System.out.println("MyServletContextListenerInit,appName:"+appName+",version:"+version);
		sce.getServletContext().setAttribute("app_name", appName);
		
		sce.getServletContext().setAttribute("version",version);
		
		
		
	}

	@Override
	public void contextDestroyed(ServletContextEvent sce) {
		String appNameString = (String)sce.getServletContext().getAttribute("app_name");
		String version = (String)sce.getServletContext().getAttribute("version");
		
		System.out.println("MyServletContextListenerdestroy,appName:"+appNameString+",version:"+version);
		

		
		
		
		
	}

}
