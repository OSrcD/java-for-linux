package com.mooc.beans;

import java.sql.Date;

/**
 * 书籍实体类
 */
public class Book {
    private String isbn;
    private String name;
    private float price;
    private Date pubdate;

    public Book() {
    }

    public Book(String isbn, String name, float price, Date pubdate) {
        super();
        this.isbn = isbn;
        this.name = name;
        this.price = price;
        this.pubdate = pubdate;
    }

    public String getIsbn() {
        return isbn;
    }

    public void setIsbn(String isbn) {
        this.isbn = isbn;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public float getPrice() {
        return price;
    }

    public void setPrice(float price) {
        this.price = price;
    }

    public Date getPubdate() {
        return pubdate;
    }

    public void setPubdate(Date pubdate) {
        this.pubdate = pubdate;
    }

    @Override
    public String toString() {
        return "Book{" +
                "isbn='" + isbn + '\'' +
                ", name='" + name + '\'' +
                ", price=" + price +
                ", pubdate=" + pubdate +
                '}';
    }
}
