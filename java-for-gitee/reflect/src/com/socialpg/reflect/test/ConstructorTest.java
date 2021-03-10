package com.opendevel.reflect.test;

import java.lang.reflect.Constructor;

import org.junit.Test;

public class ConstructorTest {

	@Test
	public void demo1() throws Exception {
		Class class1 = Class.forName("com.opendevel.reflect.test.Person");
		Constructor c = class1.getConstructor();
		Person person = (Person)c.newInstance();
//		person.eat();
	}
	
	
	@Test
	
	public void demo2() throws Exception {
		Class class1 =	Class.forName("com.opendevel.reflect.test.Person");
		Constructor c = class1.getConstructor(String.class,String.class);
		
		Person person = (Person)c.newInstance("����","��");
		System.out.println(person);
	}
	
	
}
