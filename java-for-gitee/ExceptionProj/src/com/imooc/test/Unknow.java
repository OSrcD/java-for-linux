package com.imooc.test;

public class Unknow {

	public static void main(String[] args) {
		try {
			int a=1-1;
			System.out.println("a = " + a);
			int b = 4/a;
			int c[] = {1};
			c[10]=99;
		}catch(ArithmeticException e) {
			System.out.println("除数不允许为零");
			e.printStackTrace();
		}catch(ArrayIndexOutOfBoundsException e) {
			System.out.println("数组越界");
		}
	}

}
