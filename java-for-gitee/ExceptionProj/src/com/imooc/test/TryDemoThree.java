package com.imooc.test;

import java.util.InputMismatchException;
import java.util.Scanner;

public class TryDemoThree {
	public static void main(String[] args) {
//		try {
//			int result = test();
//			System.out.println("one��two�����ǣ�"+result);
//		} catch (ArithmeticException e) {
//			System.out.println("����������Ϊ��");
//			e.printStackTrace();
//		}catch(InputMismatchException e) {
//			System.out.println("����������");
//			e.printStackTrace();
//		}
		try {
			int result = test();
			System.out.println("one��two�����ǣ�"+result);
		}catch(ArithmeticException e) {
			
		}catch(InputMismatchException e) {
			
		}catch(Exception e) {
			
		}
		test();
	}
	/**/
	/**
	 * ���Խ��������������ķ���
	 * @return �����������ݵ���
	 * @throws ArithmeticException
	 * @throws InputMismatchException
	 * throwsע����߱��������ܻ���������쳣
	 */
	public static int test() throws ArithmeticException,InputMismatchException{
		Scanner input = new Scanner(System.in);
		System.out.println("=====���㿪ʼ====");
	
			System.out.println("�������һ������");
			int one = input.nextInt();
			System.out.println("������ڶ���������");
			int two = input.nextInt();
			
			System.out.println("=====�������=====");
			return one/two;
		}
		
//	public static int test() throws Exception{
//		Scanner input = new Scanner(System.in);
//		System.out.println("=====���㿪ʼ====");
//	
//			System.out.println("�������һ������");
//			int one = input.nextInt();
//			System.out.println("������ڶ���������");
//			int two = input.nextInt();
//			
//			System.out.println("=====�������=====");
//			return one/two;
//		}
	
	}

