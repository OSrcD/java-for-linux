package com.opendevel.annotation;

import java.lang.annotation.ElementType;

public class SuppressWarningsDemo {
	@SuppressWarnings({"deprecated"})
	public static void main(String[] args) throws ClassNotFoundException {
		SuppressWarningsDemo ss =new SuppressWarningsDemo() ;
	    
		new Thread().stop();
	
		
	}

}
