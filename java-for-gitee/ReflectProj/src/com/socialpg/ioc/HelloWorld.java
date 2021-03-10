package com.opendevel.ioc;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class HelloWorld {

	
	
	public static void main(String[] args) throws IllegalAccessException, IllegalArgumentException, InvocationTargetException {
		try {
			String className = readClassName();
			System.out.println(className);
			Class clz = Class.forName(className);
			Class [] params = new Class[3];
			params[0]=String.class;
			params[1]=int.class;
			params[2]=String.class;
			
		
			Constructor constructor = clz.getConstructor(params);
			
			Object[] argObjs = new Object[3];
			
			argObjs[0] = "Tony";
			argObjs[1]=18;
			argObjs[2]="�廪��ѧ";
			
			
			
			
			
			
			try {
				Student p =(Student)constructor.newInstance(argObjs);
				System.out.println(p);
				
				Class [] myStrobj = new Class[1];
				myStrobj[0]= String.class;
				
				
				
				
				Method method = clz.getMethod("setStr", myStrobj);	
				
				
				Object [] myMethodobj = new Object[1];
				myMethodobj[0]="Hi method";
				
				Object result =  method.invoke(p, myMethodobj);
				Student result1 = (Student)result;
				method = clz.getMethod("getStr");
				Object result2 = method.invoke(p);
				System.out.println(result2);
				
				
				
				try {
					Field name = clz.getDeclaredField("mystr");
					name.setAccessible(true);
					name.set(p, "Tony");
					
					
					Field age = clz.getDeclaredField("i");
					age.setAccessible(true);
					age.set(p, 20);
					
					
					System.out.println(name.get(p)+" "+age.get(p));
					
					
					
				} catch (NoSuchFieldException e) {
					e.printStackTrace();
				}
				
				
				
				
			} catch (InstantiationException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IllegalAccessException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IllegalArgumentException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (InvocationTargetException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}catch (ClassNotFoundException e) {
			e.printStackTrace();
		}catch (NoSuchMethodException e) {
			// TODO Auto-generated catch block
		} catch (SecurityException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	
	
	
	public static String readClassName() throws IOException {
		FileInputStream readfile = null;
		InputStreamReader ir = null;
		BufferedReader in =null;
		
		try {
			readfile = new FileInputStream("Configuration.ini");
			ir = new InputStreamReader(readfile);
			in = new BufferedReader(ir);
			String str = in.readLine();
			return str;
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		return null;
	}

}
