package com.opendevel.annotation;

public class SafeVarargsDemo {
	@SafeVarargs
	public  static <T> void  display(T... args) {
		for(T myargs:args) {
			System.out.println(myargs.getClass().getName()+" "+myargs);
		}
	}
	
	public static void main(String[] args) {
		SafeVarargsDemo svd = new SafeVarargsDemo();
		svd.display("1","2","3");
		svd.display(1,"2","3",5.0f);
	}

}
