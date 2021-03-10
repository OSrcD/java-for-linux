package com.imooc.string;

public class StringDemo1 {

	public static void main(String[] args) {
		String str = "JAVA 编程 基础";
		System.out.println("字符串的长度是:"+str.length());
		
		System.out.println(str.charAt(6));
		
		System.out.println(str.substring(5));
		
		System.out.println(str.substring(5, 7));
		
	}

}
