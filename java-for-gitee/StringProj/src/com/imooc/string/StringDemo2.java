package com.imooc.string;

public class StringDemo2 {

	public static void main(String[] args) {
		String str = new String("JAVA��̻���,��ϲ��java���");
		
		System.out.println("�ַ�'A'���ַ����е�һ�γ��ֵ�λ��"+str.indexOf('A'));
		
		System.out.println("�Ӵ�\"���\"���ַ����е�һ�γ��ֵ�λ��"+str.indexOf("���"));
	
		System.out.println("�ַ�'A'���ַ��������һ�γ��ֵ�λ��"+str.lastIndexOf('A'));
		  
		System.out.println("�Ӵ�\"���\"���ַ��������һ�γ��ֵ�λ��"+str.lastIndexOf("���"));
		
		System.out.println("���ַ���indexֵΪ8��λ�ÿ�ʼ,�����ַ�\"���\"��һ�γ��ֵ�λ��"+str.indexOf("���",8));
	}

}
