package com.imooc.listener;

import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;

public class MySecondListener implements ServletContextListener {

	@Override
	public void contextInitialized(ServletContextEvent sce) {
		System.out.println("second listener context Init... ...");
		
	}

	@Override
	public void contextDestroyed(ServletContextEvent sce) {
		System.out.println("second listener context destory... ...");
		
	}

}
