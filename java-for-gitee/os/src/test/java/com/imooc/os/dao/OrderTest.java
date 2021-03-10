package com.imooc.os.dao;

import org.junit.Test;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.List;

public class OrderTest {

    private String driver = "com.mysql.jdbc.Driver";
    private String url = "jdbc:mysql://localhost:3306/os?useUnicode=true&characterEncoding=utf8";

    private String username = "root";
    private String password = "opendevel";

    @Test
    public void addOrder(){
        try {
            Class.forName(driver);
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        Connection connection = null;
        try {
             connection =  DriverManager.getConnection(url,username,password);
             connection.setAutoCommit(false);
             Statement statement = connection.createStatement();
             statement.execute("insert into orders values('100002','100001',2,2499,now(),null,null,'刘备','13232164227','成都','待发货')");
             statement.execute("update products set stck=stock-2 where id = '100001' ");
             statement.close();
             connection.commit();
        } catch (SQLException throwables) {
            throwables.printStackTrace();
            try {
                connection.rollback();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }finally{
            try {
                connection.close();
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }
        }
    }




}
