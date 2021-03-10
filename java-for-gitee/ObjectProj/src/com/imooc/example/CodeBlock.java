package com.imooc.example;

public class CodeBlock {

	{
		System.out.println("产生CodeBlock类实例对象");
		System.out.println("CodeBlock的构造块");	
	}
	
	static {
		System.out.println("CodeBlock的静态代码块");
		CodeBlockMain();
		Code one = new Code();
	}
	
	
	public static void CodeBlockMain() {
		System.out.println("CodeBlock主方法");
	}
	
	public CodeBlock() {
		System.out.println("CodeBlock的构造方法");
	}
	
	
	public static void main(String[] args) {
		CodeBlock two = new CodeBlock();
		
	}

}
