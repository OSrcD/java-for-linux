package com.opendevel.jdbc.dao;

import com.opendevel.jdbc.bean.User;
import com.opendevel.jdbc.common.ConnectionUtil;

import java.sql.*;


public class UserDAO {

    /**
     * 用户登录
     * @param username 用户名
     * @param password 密码
     * @return  成功返回用户Bean 失败返回空
     */
    public User login(String username,String password){
        Connection conn = ConnectionUtil.getConnection();
        String sql = "select * from user where username = ? and password = ? ";
        PreparedStatement stmt = null;
        ResultSet rs = null;
        User user = null;
        try {
            stmt = conn.prepareStatement(sql);
            stmt.setString(1,username);
            stmt.setString(2, password);

            rs = stmt.executeQuery();

            while (rs.next()){
                user = new User();
                user.setId(rs.getLong("id"));
                user.setName(rs.getString("username"));
                user.setPassword(rs.getString("password"));
                user.setRealName(rs.getString("real_name"));
                user.setBirthday(rs.getDate("birthday"));
                user.setPhone(rs.getString("phone"));
                user.setAddress(rs.getString("address"));
            }
        } catch (SQLException e) {
            System.out.println("登录失败。");
            e.printStackTrace();
        }finally {
            ConnectionUtil.release(rs, stmt, conn);
        }


        return user;

    }


    /**
     * 根据ID查询用户信息
     * @param id
     * @return
     */

    public User getUserById(Long id){
        Connection conn = ConnectionUtil.getConnection();
        String sql = "select * from user where id = ? ";
        PreparedStatement stmt = null;
        ResultSet rs = null;
        User user = null;
        try {
            stmt = conn.prepareStatement(sql);
            stmt.setLong(1,id);

            rs = stmt.executeQuery();

            while (rs.next()){
                user = new User();
                user.setId(rs.getLong("id"));
                user.setName(rs.getString("username"));
                user.setPassword(rs.getString("password"));
                user.setRealName(rs.getString("real_name"));
                user.setBirthday(rs.getDate("birthday"));
                user.setPhone(rs.getString("phone"));
                user.setAddress(rs.getString("address"));
            }
        } catch (SQLException e) {
            System.out.println("查询用户信息失败");
            e.printStackTrace();
        }finally {
            ConnectionUtil.release(rs, stmt, conn);
        }


        return user;

    }


    public  boolean updateUser(User user){
        Connection conn = ConnectionUtil.getConnection();
        String sql = "UPDATE  user SET username = ?,password = ?,real_name = ?, birthday = ?,phone = ?,address = ? where id =?";
        PreparedStatement stmt = null;
        try {
            stmt = conn.prepareStatement(sql);
            stmt.setString(1,user.getName());
            stmt.setString(2,user.getPassword());
            stmt.setString(3,user.getRealName());
            stmt.setDate(4,new Date(user.getBirthday().getTime()));
            stmt.setString(5,user.getPhone());
            stmt.setString(6,user.getAddress());
            stmt.setLong(7,user.getId());


            stmt.execute();


        } catch (SQLException e) {
            System.out.println("查询用户信息失败");
            e.printStackTrace();
            return false;
        }finally {
            ConnectionUtil.release(null, stmt, conn);
        }


        return true;

    }


}
