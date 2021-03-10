package com.imooc.test;

import java.io.IOException;
import java.util.Scanner;

public class TryDemoFour {

	public static void main(String[] args) {
		try {
			testAge();
		} catch (HotelAgeException e) {
			System.out.println(e.getMessage());
			System.out.println("�Ƶ�ǰ̨������Ա�����������ס�Ǽ�");
		}catch(Exception e) {
			e.printStackTrace();
		}
	}

	/*public static void testAge() { 

		try {
			System.out.println("���������䣺");
			Scanner input = new Scanner(System.in);
			int age = input.nextInt();
			if (age < 18 || age > 80) {
				throw new Exception("18�����£�80�����ϵ�ס�ͱ�����������ͬ");
			} else {
				System.out.println("��ӭ��ס���Ƶ�");
			}

		} catch (Exception e) {
			e.printStackTrace();
		}
	}*/
	public static void testAge() throws HotelAgeException  {

			System.out.println("���������䣺");
			Scanner input = new Scanner(System.in);
			int age = input.nextInt();
			if (age < 18 || age > 80) {
//				throw new ArithmeticException("18�����£�80�����ϵ�ס�ͱ�����������ͬ");
				throw new HotelAgeException();
			} else {
				System.out.println("��ӭ��ס���Ƶ�");
			}

	
	}

}
