package com.imooc.os.dao.impl;

import com.imooc.os.dao.ProductDao;
import com.imooc.os.entity.Product;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.RowMapper;
import org.springframework.stereotype.Repository;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.List;

@Repository
public class ProductDaoImpl implements ProductDao {

    @Autowired
    private JdbcTemplate jdbcTemplate;

    public void insert(Product product) {
        String sql = "insert into products values(?,?,?,?,?)";
        jdbcTemplate.update(sql,product.getId(),product.getTitle(),product.getPrice(),product.getStock(),product.getStatus());

    }

    public void update(Product product) {
        String sql = "update products2 set title=?,price=?,stock=?,status=? where id=?";
        jdbcTemplate.update(sql,product.getTitle(),product.getPrice(),product.getStock(),product.getStatus(),product.getId());
    }

    public void delete(String id) {
        String sql = "delete from products where id=?";
        jdbcTemplate.update(sql,id);
    }

    public Product select(String id) {
        String sql = "select * from products where id=?";
        return jdbcTemplate.queryForObject(sql,new ProductRowMapper(),id);
    }

    public List<Product> select() {
        String sql = "select * from products";
        return jdbcTemplate.query(sql,new ProductRowMapper());
    }

    private class ProductRowMapper implements RowMapper<Product> {

        public Product mapRow(ResultSet resultSet, int i) throws SQLException {
            Product product = new Product();
            product.setId(resultSet.getString("id"));
            product.setTitle(resultSet.getString("title"));
            product.setPrice(resultSet.getDouble("price"));
            product.setStock(resultSet.getInt("stock"));
            product.setStatus(resultSet.getString("status"));
            return product;
        }
    }
}
