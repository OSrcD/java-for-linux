package com.imooc.example;

public class CodeBlock {

	{
		System.out.println("����CodeBlock��ʵ������");
		System.out.println("CodeBlock�Ĺ����");	
	}
	
	static {
		System.out.println("CodeBlock�ľ�̬�����");
		CodeBlockMain();
		Code one = new Code();
	}
	
	
	public static void CodeBlockMain() {
		System.out.println("CodeBlock������");
	}
	
	public CodeBlock() {
		System.out.println("CodeBlock�Ĺ��췽��");
	}
	
	
	public static void main(String[] args) {
		CodeBlock two = new CodeBlock();
		
	}

}
