package com.imooc.example;

public class UserManager {
	public UserManager() {
		
	}
	
	public void checkUser(User one,User two) {
		System.out.println("=====================");
		if(one.getName().equals(two.getName())) {
			System.out.println("�û���һ��");
		}else {
			System.out.println("�û�����һ��");
		}
	}
}
