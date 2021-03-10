package com.opendevel.annotation;

public class UseMyAnnotion {
	@MyAnnotation(name = "opendevel")
	public void show(String str) {
		System.out.println(str);
	}
}
