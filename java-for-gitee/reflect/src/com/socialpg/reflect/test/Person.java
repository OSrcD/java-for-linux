package com.opendevel.reflect.test;

public class Person {
	
	
	
	public Person() {
		super();
	}
	public Person(String name, String sex) {
		super();
		this.name = name;
		this.sex = sex;
	}
	public String name;
	private String sex;
//	public String getName() {
//		return name;
//	}
//	public void setName(String name) {
//		this.name = name;
//	}
//	public String getSex() {
//		return sex;
//	}
//	public void setSex(String sex) {
//		this.sex = sex;
//	}
//	
	public void eat() {
		System.out.println("��......");
	}
	
	private void run() {
		System.out.println("��......");
	}
	
	public String sayHello(String name) {
		return "Hello "+name;
	}
	
	
	@Override
	public String toString() {
		return "Person [name=" + name + ", sex=" + sex + "]";
	}
	
	
}
