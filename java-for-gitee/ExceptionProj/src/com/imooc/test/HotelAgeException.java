package com.imooc.test;

public class HotelAgeException extends Exception {
	public HotelAgeException() {
		super("18�����£�80�����ϵ�ס�ͱ�����������ͬ");
	}
}

class SubException extends HotelAgeException{
	 
}
