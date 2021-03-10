package com.imooc.string;

public class StringBuilderDemo1 {

	public static void main(String[] args) {
		StringBuilder str = new StringBuilder("你好");
//		str.append(',');
//		str.append("imooc!");
//		System.out.println("str="+str);
		System.out.println("str="+str.append(',').append("imooc"));
		
//		System.out.println("替换后："+str.delete(4, 8).insert(4, "MOOC"));
		System.out.println("替换后："+str.replace(4, 8, "MOOC"));
		System.out.println(str.substring(0,2));
		
		
	} 

}
