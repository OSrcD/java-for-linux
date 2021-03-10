package com.imooc.listener;

import javax.servlet.ServletContextAttributeEvent;
import javax.servlet.ServletContextAttributeListener;

public class MyServletContextAttributeListener implements ServletContextAttributeListener {

	@Override
	public void attributeAdded(ServletContextAttributeEvent scae) {
		System.out.println("ServletContext#attAdded#name:"+scae.getName()+"#"+scae.getValue());
	}

	@Override
	public void attributeRemoved(ServletContextAttributeEvent scae) {
		System.out.println("ServletContext#Removed#name:"+scae.getName()+"#"+scae.getValue());
	}

	@Override
	public void attributeReplaced(ServletContextAttributeEvent scae) {
		System.out.println("ServletContext#Replaced#name:"+scae.getName()+"#"+scae.getValue());
	}

}
