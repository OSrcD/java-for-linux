package com.opendevel.reflect.test;

import java.lang.reflect.Method;

import org.junit.Test;

public class MethodTest {

	
	@Test
	public void demo1() throws Exception {
		Class class1 = Class.forName("com.opendevel.reflect.test.Person");
		
		Person p =(Person)class1.newInstance();
		
		
		Method method = class1.getMethod("eat");
		
		method.invoke(p);
		
		
		
		
	}
	
	@Test
	public void demo2() throws Exception {
		Class class1 = Class.forName("com.opendevel.reflect.test.Person");
		
		Person p =(Person)class1.newInstance();
		Method m = class1.getDeclaredMethod("run");
		m.setAccessible(true);
		m.invoke(p,null);
		
	}
	
	
	@Test
	public void demo3() throws Exception {
		Class class1 = Class.forName("com.opendevel.reflect.test.Person");
		Person p =(Person)class1.newInstance();
		Method method =	class1.getDeclaredMethod("sayHello",String.class);
		method.setAccessible(true);
		
		Object obj = method.invoke(p, "opendevel");
		System.out.println(obj);
		
	}
	
}
