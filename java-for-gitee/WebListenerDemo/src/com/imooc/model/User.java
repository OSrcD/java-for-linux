package com.imooc.model;

import javax.servlet.http.HttpSessionBindingEvent;
import javax.servlet.http.HttpSessionBindingListener;

public class User implements HttpSessionBindingListener {

	private String username;
	private String password;
	
	@Override
	public void valueBound(HttpSessionBindingEvent hsbe) {
		String name = hsbe.getName();
		System.out.println("value bound,name:"+name);
	}

	@Override
	public void valueUnbound(HttpSessionBindingEvent hsbe) {
		String name = hsbe.getName();
		System.out.println("value unbound,name:"+name);
	}

	public String getUsername() {
		return username;
	}

	public void setUsername(String username) {
		this.username = username;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}

	
}
