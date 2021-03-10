package com.opendevel.reflect.test;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Comparator;
import java.util.List;
import java.util.Set;

import org.junit.Test;

;

public class ClassTest {

	public static <T> void show1(List<T> list){
		 for (Object object : list) {
		        System.out.println(object.toString());
		    }
		}

		public static void show2(List<?> list) {
		    for (Object object : list) {
		        System.out.println(object.toString());
		    }
		}
	
	
	
//	@Test
//	public void demo1() throws ClassNotFoundException {
//		Class clazz1= Person.class;
//		
//		Person person = new Person();
//		
//		Class clazz2 = person.getClass();
//		
//		Class clazz3 = Class.forName("com.opendevel.reflect.test.Person");
//		
//	
//		
//	}
	
	public static <T> void main(String[] args) {
	
		//????????????????????
		List<?> list = new ArrayList() ;
		Object object = new Object();
		
		List<?> list3 = new ArrayList<>();
		//boolean java.util.List.containsAll(Collection<?> c)
		list.containsAll(list3);
		//TTTTTTTTTTTTTTT
		List<T> list2 = new ArrayList<T>();
		
		list2.add((T) object);
		list2.sort((Comparator<? super T>) object);
		list2.sort(null);
		list2.addAll((Collection<? extends T>) object);
		
			if(list2 instanceof ArrayList) {
				System.out.println("������ͬ");
			}else {
				System.out.print("���Ͳ���ͬ");
			}
	}
}
