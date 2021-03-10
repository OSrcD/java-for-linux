package com.opendevel.reflect;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;

public class newinsance {

	public static void main(String[] args) throws ClassNotFoundException, NoSuchMethodException, SecurityException, InstantiationException, IllegalAccessException, IllegalArgumentException, InvocationTargetException {
		Class clz =Class.forName("java.lang.String");
		
		Constructor [] con = clz.getDeclaredConstructors();
		
		Class [] params = new Class[1];
		String [] strt = new String[1];
		params[0] = String.class;
		
		Constructor constructor =  clz.getConstructor(params);
	
		String [] argObjs = new String[1];
		
		
		argObjs[0] = "Hello";
		
		String str2=(String)constructor.newInstance(argObjs);
		System.out.println(str2.toString());
		
		params[0] = String.class;
		
		
		
		
		
		
		
		
	
		
		try {
			String str = (String)clz.newInstance();
		} catch (InstantiationException e) {
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			e.printStackTrace();
		}
	}

}
