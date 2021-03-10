package com.imooc.string;

import java.io.UnsupportedEncodingException;

public class StringDemo3 {

	public static void main(String[] args) throws UnsupportedEncodingException {
		String str = new String("JAVA 编程 基础");
		byte [] arrs = str.getBytes("GBK");
		
		for(int i=0;i<arrs.length;i++) {
			System.out.print(arrs[i]+" ");
		}
		
		System.out.println();
		String str2 = new String(arrs,"GBK");
		System.out.println(str2);
		
		
		
	}

}
