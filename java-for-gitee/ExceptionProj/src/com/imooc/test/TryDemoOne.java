package com.imooc.test;


import java.util.InputMismatchException;
import java.util.Scanner;

public class TryDemoOne {

	public static void main(String[] args) {
//		 int one = 12;
//		 int two =2;
//		 System.out.println("one��two������"+(one/two));
		 Scanner input = new Scanner(System.in);
		 System.out.println("====���㿪ʼ====");
		 try {
			 System.out.print("�������һ������");
		 	int one = input.nextInt();
		 	System.out.print("������ڶ�������");
		 	int two = input.nextInt();
		 	System.out.println("one��two������:"+(one/two));
		 }catch(ArithmeticException e) {
			 System.exit(1);
			 System.out.println("��������Ϊ��");
			 e.printStackTrace();
		 }catch(InputMismatchException e) {
			 System.out.println("����������");
			 e.printStackTrace(); 
		 }catch(Exception e) {
			System.out.println("���������~~~");
			e.printStackTrace();
		 }finally{
			 System.out.println("====�������====");
		 }
		
		}

}
