package com.opendevel.reflect;

import java.lang.reflect.Method;
import java.lang.reflect.Modifier;

public class Reflect {
	public static void main(String[] args) {
		try {
			Class c = Class.forName("java.lang.String");
			Method [] methods = c.getMethods();
			for(Method method : methods) {
				System.out.println(Modifier.toString(method.getModifiers()));
				System.out.println(" "+method.getReturnType().getName()+" ");
				System.out.println(method.getName()+"();");
			}
			
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
	}
}
