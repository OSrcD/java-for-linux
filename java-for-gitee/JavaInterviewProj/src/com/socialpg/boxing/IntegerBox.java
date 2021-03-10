package com.opendevel.boxing;



public class IntegerBox {

	public static void main(String[] args) {
		System.out.println(new Integer(2) == 2);//true
		System.out.println(new Integer(2) == new Integer(2));//false
		System.out.println(Integer.valueOf(2) == Integer.valueOf(2)); //true
		System.out.println(Integer.valueOf(-129) == Integer.valueOf(-129)); //false
		System.out.println(Integer.valueOf(2).intValue()==2);//true
		System.out.println(new Integer(5).equals(new Integer(5)));//true

	}
	
	
	

}
