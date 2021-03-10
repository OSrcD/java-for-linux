package com.imooc.test;

public class UnknowTwo {
	
	public static int test(int b) {
		try {
			b+=10;
			return b;
		}catch(Exception e) {
			return 1;
		}finally {
			b+=10;
			return b;
		}
	
	}
	public static void main(String[] args) {
		int num=10;
		System.out.println(UnknowTwo.test(num));
	}

}
