package com.imooc.animal;

public class Book {
	private String bookName;
	private String author;
	private String chubanshe;
	private double price;
	
	public Book(String bookName,String author,String chubanshe,double price) {
		this.bookName=bookName;
		this.author=author;
		this.chubanshe=chubanshe;
		this.price=price;
	}
	
	
	
	
	public String getBookName() {
		return bookName;
	}




	public void setBookName(String bookName) {
		this.bookName = bookName;
	}




	public String getAuthor() {
		return author;
	}




	public void setAuthor(String author) {
		this.author = author;
	}




	public String getChubanshe() {
		return chubanshe;
	}




	public void setChubanshe(String chubanshe) {
		this.chubanshe = chubanshe;
	}




	public double getPrice() {
		return price;
	}




	public void setPrice(double price) {
		this.price = price;
	}




	public void shu() {
		System.out.println("图书价格最低10元");
		System.out.println("书名："+this.bookName);
		System.out.println("作者："+this.author);
		System.out.println("出版社："+this.chubanshe);
		System.out.println("价格："+this.price+"元");

	}
	
}
