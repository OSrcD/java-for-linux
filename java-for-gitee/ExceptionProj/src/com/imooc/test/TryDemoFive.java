package com.imooc.test;

public class TryDemoFive {
	public static void main(String[] args) {
		try {
			testThree();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static void testOne() throws HotelAgeException {
		 throw new HotelAgeException();
	}

	public static void testTwo() throws Exception {
		try { 
			testOne();
		} catch (HotelAgeException e) {
			throw new Exception("�����²������쳣1",e);
		}
	}

	public static void testThree() throws Exception {
		try {
			testTwo();
		} catch (Exception e) {
		  	throw new Exception("�����²������쳣2",e);
//			Exception e1 = new Exception("�����²������쳣2");
//			e1.initCause(e1);
//			throw e1;
		}
	}
}
