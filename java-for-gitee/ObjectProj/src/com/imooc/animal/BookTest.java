package com.imooc.animal;

public class BookTest {

	public static void main(String[] args) {
		Book one = new Book("��¥��","��ѩ��","������ѧ������",10.0);
			one.shu();	
		System.out.println("===================================");
		one.setBookName("С��ɵ�");
		one.setAuthor("����");
		one.setChubanshe("�й�����������");
		one.setPrice(55.5);
		one.shu();
	}

}
