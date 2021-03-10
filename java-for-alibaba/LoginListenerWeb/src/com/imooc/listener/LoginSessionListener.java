package com.imooc.listener;

import javax.servlet.http.HttpSession;
import javax.servlet.http.HttpSessionAttributeListener;
import javax.servlet.http.HttpSessionBindingEvent;

import com.imooc.cache.LoginCache;

public class LoginSessionListener implements HttpSessionAttributeListener {

	
	private static final String LOGIN_USER = "loginUser";
	
	@Override
	public void attributeAdded(HttpSessionBindingEvent hsbe) {
		String attrName = hsbe.getName();
		
		if(LOGIN_USER.equals(attrName)) {
			String attrVal = (String)hsbe.getValue();
			HttpSession session = hsbe.getSession();//��ε�¼�����session����
			String sessionId = session.getId();//���IDֵ
			
			String sessionId2 = LoginCache.getInstance().getSessionByUsername(attrVal);
			
			if(sessionId2 == sessionId) {
				return;
			}
			
	
			
			if(null == sessionId2) {
				System.out.println("newSeesionID="+sessionId+"  newHttpSeesion="+session);
			}else {
				HttpSession session2 = LoginCache.getInstance().getSessionBySessionId(sessionId2);
				session2.invalidate();//ÿ��������������һ��Ψһ��sessionID 
				System.out.println("ExitnewSessionID="+sessionId+"  ExitnewHttpSeesion="+session);
				System.out.println("setSessionID="+sessionId2+"  seHttpSeesion="+session2);
				
			}
			
			LoginCache.getInstance().setSessionIdByUserName(attrVal, sessionId);
			LoginCache.getInstance().setSessionBySessionId(sessionId, session);
			
		}
	}

	@Override
	public void attributeRemoved(HttpSessionBindingEvent event) {

	}

	@Override
	public void attributeReplaced(HttpSessionBindingEvent event) {

	}

}
