package com.mooc.service;

import com.mooc.beans.Book;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.RowMapper;
import org.springframework.jdbc.core.support.JdbcDaoSupport;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.List;

/**
 * POJO服务类
 */
public class BookServiceImpl extends JdbcDaoSupport implements BookService {

    //r若不继承JdbcDaoSupport,则可按下面方式进行数据源的注入
    /*private JdbcTemplate jdbcTemplate;
    public void setDataSource(DataSource dataSource) {
        this.jdbcTemplate = new JdbcTemplate(dataSource);
    }*/
        @Override
    public void insertBook(Book book) {
            String sql= "insert books(isbn,name,price,pubdate) values"
                    +"('"+book.getIsbn()+"','"+book.getName()+"',"+book.getPrice()+",'"+book.getPubdate()+"')" ;
        this.getJdbcTemplate().update(sql);
    }

    @Override
    public void updateBook(Book book) {
        String sql = "update books set name='"+book.getName()+"' where isbn='"+book.getIsbn()+"' ";
        this.getJdbcTemplate().update(sql);
    }

    @Override
    public Book findBookByIsbn(String isbn) {
        String sql =   "select isbn,name,price,pubdate from books where isbn ='" + isbn + "'" ;
       List<Book> books =  this.getJdbcTemplate().query(sql,new RowMapper<Book>() {
            public Book mapRow(ResultSet rs, int rowNum) throws SQLException {
                Book bk  = new Book();
                bk.setIsbn(rs.getString("isbn"));
                bk.setName(rs.getString("name"));
                bk.setPrice(rs.getFloat("price"));
                bk.setPubdate(rs.getDate("pubdate"));
                return bk;
            }
        });
        return books!=null?books.get(0):null ;
    }
}
