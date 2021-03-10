package com.imooc.set;

import java.util.ArrayList;
import java.util.Map.Entry;

import sun.security.action.GetBooleanAction;

public class MyList <T> {
	public  void SetData(Class<?> arg) {
      
     System.out.println(arg.getClass());

    }
	
	
	public  void SetData2(Class  arg) {
	      
	     System.out.println(arg.getClass());
	       
	   }

	public static void main(String[] args) {
		MyList myList = new MyList();
		
		myList.SetData(Class.class);
		myList.SetData(Object.class);
		myList.SetData2(Class.class);
		myList.SetData2(Object.class);
	
		
	}

}
