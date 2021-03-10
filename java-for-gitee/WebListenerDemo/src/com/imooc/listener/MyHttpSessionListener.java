package com.imooc.listener;

import java.util.Date;

import javax.servlet.http.HttpSessionEvent;
import javax.servlet.http.HttpSessionListener;

public class MyHttpSessionListener implements HttpSessionListener {

	@Override
	public void sessionCreated(HttpSessionEvent hse) {
		String sessionId = hse.getSession().getId();
		Date createTime = new Date(hse.getSession().getCreationTime());
	
		System.out.println("session id:"+sessionId+",createTime"+createTime);
		
	}

	@Override
	public void sessionDestroyed(HttpSessionEvent hse) {
		String sessionId = hse.getSession().getId();
		
		System.out.println("destroyedSession id:"+sessionId);
		
	}

}
