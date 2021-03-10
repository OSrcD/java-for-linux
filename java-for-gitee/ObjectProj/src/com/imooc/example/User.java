package com.imooc.example;

public class User {
	private String name;
	private String password;
	
	public User() {
		
	}
	public User(String name,String password) {
		this.name=name;
		this.password=password;
		System.out.println("”√ªß√˚£∫"+this.name);
		System.out.println("√‹¬Î£∫"+this.password);
		
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getPassword() {
		return password;
	}
	public void setPassword(String password) {
		this.password = password;
	}
	
	
}
