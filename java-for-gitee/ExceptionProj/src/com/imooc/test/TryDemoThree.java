package com.imooc.test;

import java.util.InputMismatchException;
import java.util.Scanner;

public class TryDemoThree {
	public static void main(String[] args) {
//		try {
//			int result = test();
//			System.out.println("one和two的商是："+result);
//		} catch (ArithmeticException e) {
//			System.out.println("除数不允许为零");
//			e.printStackTrace();
//		}catch(InputMismatchException e) {
//			System.out.println("请输入整数");
//			e.printStackTrace();
//		}
		try {
			int result = test();
			System.out.println("one和two的商是："+result);
		}catch(ArithmeticException e) {
			
		}catch(InputMismatchException e) {
			
		}catch(Exception e) {
			
		}
		test();
	}
	/**/
	/**
	 * 测试接收数据相除结果的方法
	 * @return 两个接收数据的商
	 * @throws ArithmeticException
	 * @throws InputMismatchException
	 * throws注解告诉编译器可能会产生两个异常
	 */
	public static int test() throws ArithmeticException,InputMismatchException{
		Scanner input = new Scanner(System.in);
		System.out.println("=====运算开始====");
	
			System.out.println("请输入第一个整数");
			int one = input.nextInt();
			System.out.println("请输入第二个整数：");
			int two = input.nextInt();
			
			System.out.println("=====运算结束=====");
			return one/two;
		}
		
//	public static int test() throws Exception{
//		Scanner input = new Scanner(System.in);
//		System.out.println("=====运算开始====");
//	
//			System.out.println("请输入第一个整数");
//			int one = input.nextInt();
//			System.out.println("请输入第二个整数：");
//			int two = input.nextInt();
//			
//			System.out.println("=====运算结束=====");
//			return one/two;
//		}
	
	}

