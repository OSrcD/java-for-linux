package com.imooc.set;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

public class CatTest {
	
	public static void main(String[] args) {
		Cat huahua = new Cat("花花",12,"英国短毛猫");
		Cat fanfan = new Cat("凡凡",3,"中华田园猫");
		
		Set<Cat> set = new HashSet<Cat>(); 
		set.add(huahua);
		set.add(fanfan);
		 Iterator <Cat> it = set.iterator();
		 while(it.hasNext()) {
			 System.out.println(it.next());
		 }
		 Cat huahua01 = new Cat("花花",12,"英国短毛猫");
		 set.add(huahua01);
		 System.out.println("**********************************");
		 System.out.println("添加重复数据后的宠物猫信息");
		 
		 it = set.iterator();
		 
		 while(it.hasNext()) {
			 System.out.println(it.next());
			 
		 }
		 
		
		System.out.println("**************************");
		 
		Cat huahua02 = new Cat("花花二代",2,"英国短毛猫");
		set.add(huahua02);
		System.out.println("添加花花二代后的宠物猫信息：");
		 
		it = set.iterator();
		 while(it.hasNext()) {
			 System.out.println(it.next());
			 
		 }
		 
		 System.out.println("*********************************");
		  
		 if(set.contains(huahua)) {
			 System.out.println("花花找到了！");
			 System.out.println(huahua);
		 }else {
			 System.out.println("花花没找到！");
		 }
		 
		 System.out.println("**********************************");
		 System.out.println("通过名字查找花花信息");
		 boolean flag=false;
		 Cat c=null;
		 it = set.iterator();
		 while(it.hasNext()) {
			 c = it.next();//object
			 if(c.getName().equals("花花")) {
				 flag=true;
				 break;
			 } 
		 } 
		 if(flag) {
			 System.out.println("花花找到了");
			 System.out.println(c);
		 }else {
			 System.out.println("花花没找到");
		 }
		 
		  Set<Cat> set1 = new HashSet <Cat>();
		 for(Cat cat:set) {
			 if(cat.getMonth()<5){
//				 set.remove(cat);
				 set1.add(cat);
			 }
			 
		 }
		 
		 set.removeAll(set1);
		 System.out.println("**********************************");
		 System.out.println("删除花花后代的数据");
		 for(Cat cat:set) {
			 System.out.println(cat);
		 }
		 
		 
		 System.out.println("**********************************");
		boolean flag1 =  set.removeAll(set);
		 
		if(set.isEmpty()) {
			System.out.println("猫都不见了");
		}else {
			System.out.println("猫还在。。。。");
			
		}
	} 

}
