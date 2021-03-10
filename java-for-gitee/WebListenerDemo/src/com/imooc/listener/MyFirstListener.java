package com.imooc.listener;

import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;

public class MyFirstListener implements ServletContextListener {

	@Override
	public void contextDestroyed(ServletContextEvent sce) {
		System.out.println("context destroyeed... ...");
	}
	
	
	@Override
	public void contextInitialized(ServletContextEvent sce) {
		System.out.println("context init... ...");
	}

	

}
