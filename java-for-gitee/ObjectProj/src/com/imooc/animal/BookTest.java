package com.imooc.animal;

public class BookTest {

	public static void main(String[] args) {
		Book one = new Book("红楼梦","曹雪芹","人民文学出版社",10.0);
			one.shu();	
		System.out.println("===================================");
		one.setBookName("小李飞刀");
		one.setAuthor("古龙");
		one.setChubanshe("中国长安出版社");
		one.setPrice(55.5);
		one.shu();
	}

}
