package com.imooc.example;

public class UserManager {
	public UserManager() {
		
	}
	
	public void checkUser(User one,User two) {
		System.out.println("=====================");
		if(one.getName().equals(two.getName())) {
			System.out.println("用户名一致");
		}else {
			System.out.println("用户名不一致");
		}
	}
}
