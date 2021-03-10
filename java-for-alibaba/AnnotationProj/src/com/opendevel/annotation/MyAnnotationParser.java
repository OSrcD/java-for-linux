package com.opendevel.annotation;

import java.lang.reflect.Method;

public class MyAnnotationParser {

	public static void main(String[] args) throws Exception {

		Class clazz = Class.forName("com.opendevel.annotation.UseMyAnnotion");
			
		UseMyAnnotion useMyAnnotion = (UseMyAnnotion)clazz.newInstance();
		Method method = clazz.getMethod("show", String.class);
		MyAnnotation annotation = method.getAnnotation(MyAnnotation.class);

		
		String name = annotation.name();
		
		
		method.invoke(useMyAnnotion, name);
		
		
	}

}
