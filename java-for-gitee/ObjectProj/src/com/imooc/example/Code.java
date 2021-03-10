package com.imooc.example;

public class Code {
	public Code() {
		System.out.println("Code的构造方法");
		
	}
	
	static {
	
		System.out.println("产生Code类实例对象");
		System.out.println("Code的静态代码块");
	
	}
	
	{
		System.out.println("code的构造块");
		
	}
}
