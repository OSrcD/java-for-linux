package com.imooc.animal;

public class CatTest {

	public static void main(String[] args) {
		Cat one = new Cat(-3);
//		one.setName("凡凡");
//		one.setMonth(-3);
		
		if(one.getMonth()==0) {
			return;
		}
		System.out.println("昵称:"+one.getName());
		System.out.println("年龄"+one.getMonth());
		System.out.println("体重"+one.getWeight());
		System.out.println("品种"+one.getSpecies());
		one.run();
		System.out.println(18+3+6+7+5+2+6+4+2+5+1+2+2+5+8+3+5+4+1+4+8+5+3+1+2+5+1+2+1+2+3+1+2+2+2+3+2+1+2+6+7+1+3+2+2+1+2+2+1+3+1+6+1+2+11+1+1+4+1+1+2+1+1+1+3+2+1+1+2+9+1+3+6+6+1+5+3+5+4+5+3+5+1+3+4+4+1+2+3+2+3+3+7+4+1+2+1+1+1+2+4+4+8+4+1+6+244+10+6+25+12+12+8+15+3+21+10+2+12+4+10+9);
	}
	

}
