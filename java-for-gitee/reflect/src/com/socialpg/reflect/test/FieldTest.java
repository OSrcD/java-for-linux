package com.opendevel.reflect.test;

import java.lang.reflect.Field;

import org.junit.Test;


public class FieldTest {
	
	@Test
	public void demo1() throws Exception {
		
	 Class class1 =	Class.forName("com.opendevel.reflect.test.Person");
	 
	 Field field =	class1.getField("name");
	
	 Person p = (Person) class1.newInstance();
	 
	 field.set(p, "����");
	 
	 
	 Object obj =	field.get(p);
	 System.out.println(obj);
	}
	
	
	@Test
	public void demo2() throws Exception {
		
		 Class class1 =	Class.forName("com.opendevel.reflect.test.Person");
		 Field field =	class1.getDeclaredField("sex");
		 Person p =(Person)class1.newInstance();
		 field.setAccessible(true);
		 field.set(p, "��");
		 Object obj = field.get(p);
		 System.out.println(obj);
		 System.out.println(p);
		 
		 
	}
	
	
}
