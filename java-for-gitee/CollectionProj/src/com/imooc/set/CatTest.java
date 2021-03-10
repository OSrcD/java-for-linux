package com.imooc.set;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

public class CatTest {
	
	public static void main(String[] args) {
		Cat huahua = new Cat("����",12,"Ӣ����ëè");
		Cat fanfan = new Cat("����",3,"�л���԰è");
		
		Set<Cat> set = new HashSet<Cat>(); 
		set.add(huahua);
		set.add(fanfan);
		 Iterator <Cat> it = set.iterator();
		 while(it.hasNext()) {
			 System.out.println(it.next());
		 }
		 Cat huahua01 = new Cat("����",12,"Ӣ����ëè");
		 set.add(huahua01);
		 System.out.println("**********************************");
		 System.out.println("����ظ����ݺ�ĳ���è��Ϣ");
		 
		 it = set.iterator();
		 
		 while(it.hasNext()) {
			 System.out.println(it.next());
			 
		 }
		 
		
		System.out.println("**************************");
		 
		Cat huahua02 = new Cat("��������",2,"Ӣ����ëè");
		set.add(huahua02);
		System.out.println("��ӻ���������ĳ���è��Ϣ��");
		 
		it = set.iterator();
		 while(it.hasNext()) {
			 System.out.println(it.next());
			 
		 }
		 
		 System.out.println("*********************************");
		  
		 if(set.contains(huahua)) {
			 System.out.println("�����ҵ��ˣ�");
			 System.out.println(huahua);
		 }else {
			 System.out.println("����û�ҵ���");
		 }
		 
		 System.out.println("**********************************");
		 System.out.println("ͨ�����ֲ��һ�����Ϣ");
		 boolean flag=false;
		 Cat c=null;
		 it = set.iterator();
		 while(it.hasNext()) {
			 c = it.next();//object
			 if(c.getName().equals("����")) {
				 flag=true;
				 break;
			 } 
		 } 
		 if(flag) {
			 System.out.println("�����ҵ���");
			 System.out.println(c);
		 }else {
			 System.out.println("����û�ҵ�");
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
		 System.out.println("ɾ���������������");
		 for(Cat cat:set) {
			 System.out.println(cat);
		 }
		 
		 
		 System.out.println("**********************************");
		boolean flag1 =  set.removeAll(set);
		 
		if(set.isEmpty()) {
			System.out.println("è��������");
		}else {
			System.out.println("è���ڡ�������");
			
		}
	} 

}
