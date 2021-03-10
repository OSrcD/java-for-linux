package com.imooc.string;

public class StringDemo2 {

	public static void main(String[] args) {
		String str = new String("JAVA编程基础,我喜欢java编程");
		
		System.out.println("字符'A'在字符串中第一次出现的位置"+str.indexOf('A'));
		
		System.out.println("子串\"编程\"在字符串中第一次出现的位置"+str.indexOf("编程"));
	
		System.out.println("字符'A'在字符串中最后一次出现的位置"+str.lastIndexOf('A'));
		  
		System.out.println("子串\"编程\"在字符串中最后一次出现的位置"+str.lastIndexOf("编程"));
		
		System.out.println("在字符串index值为8的位置开始,查找字符\"编程\"第一次出现的位置"+str.indexOf("编程",8));
	}

}
