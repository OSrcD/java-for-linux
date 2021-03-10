package com.imooc.test;

public class StaticLoad {
	public int filed;
	public int fliedTwo=2;
	
	public static StaticLoadTwo myStaticLoadTwo = new StaticLoadTwo(); 
	public static int staticFiled=3;
	
	
	static{
		
	}
	
	{
		
	}
	public StaticLoad() {
		System.out.println("我是StaticLoad");
	}
	
	public static void main(String[] args) {
		StaticLoad myStaticLoad = new StaticLoad();
		myStaticLoad.staticFiled=5;
	}

}


class StaticLoadTwo{
	public int filed;
	public int filedTwo=2;
	public static int staticFiled=3;
	static {
		new StaticLoad();
	}
	public StaticLoadTwo() {
		System.out.println("我是StaticLoadTwo");
	}
}
