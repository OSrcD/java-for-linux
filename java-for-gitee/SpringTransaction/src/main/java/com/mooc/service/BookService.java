package com.mooc.service;

import com.mooc.beans.Book;

public interface BookService {
    /**
     * 向数据库新增加书籍信息
     * @param book 新增的书籍对象
     */
    void insertBook(Book book);

    /**
     *  更新数据库里的对应书籍信息
     * @param book 待更新的书籍对象
     */
    void updateBook(Book book);

    /**
     * 根据唯一编号查找对应的书籍
     * @param isbn 书籍的唯一编号
     * @return 返回查找的书籍对象
     */
    Book findBookByIsbn(String isbn);
}
