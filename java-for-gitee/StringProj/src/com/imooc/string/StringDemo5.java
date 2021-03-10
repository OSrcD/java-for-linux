package com.imooc.string;

public class StringDemo5 {
	
	public static void main(String[] args) {
		String str1="imooc";
		String str2="imooc";
		String str3 = new String("imooc");
		System.out.println("st1和st2的内容相同？"+(str1.equals(str2)));
		System.out.println("str1和str3的内容相同？"+(str1.equals(str3)));
		
		System.out.println("str1和str2的地址相同？"+(str1==str2));
		System.out.println("str1和str3的地址相同？"+(str1==str3));
	}
}
