package com.imooc.test;


import java.util.InputMismatchException;
import java.util.Scanner;

public class TryDemoOne {

	public static void main(String[] args) {
//		 int one = 12;
//		 int two =2;
//		 System.out.println("one和two的商是"+(one/two));
		 Scanner input = new Scanner(System.in);
		 System.out.println("====运算开始====");
		 try {
			 System.out.print("请输入第一个整数");
		 	int one = input.nextInt();
		 	System.out.print("请输入第二个整数");
		 	int two = input.nextInt();
		 	System.out.println("one和two的商是:"+(one/two));
		 }catch(ArithmeticException e) {
			 System.exit(1);
			 System.out.println("除数不能为零");
			 e.printStackTrace();
		 }catch(InputMismatchException e) {
			 System.out.println("请输入整数");
			 e.printStackTrace(); 
		 }catch(Exception e) {
			System.out.println("程序出错了~~~");
			e.printStackTrace();
		 }finally{
			 System.out.println("====运算结束====");
		 }
		
		}

}
