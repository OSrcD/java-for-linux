package com.imooc.animal;

public class Test2 {

	public static void main(String[] args) {
		Monkey one = new Monkey();
		System.out.println("名称:"+one.name);
		System.out.println("特征:"+one.feature);
		Monkey two = new Monkey("白头叶猴","头上有白毛，喜欢吃树叶");
		System.out.println("======================");
		System.out.println("名称:"+two.name);
		System.out.println("特征:"+two.feature);
	}

}
