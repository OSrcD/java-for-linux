package com.imooc.project.dao.impl;

import com.imooc.project.dao.BaseDao;
import com.imooc.project.dao.UserDao;
import com.imooc.project.entity.User;
import org.apache.commons.dbutils.QueryRunner;
import org.apache.commons.dbutils.handlers.BeanHandler;
import org.apache.commons.dbutils.handlers.BeanListHandler;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.List;

public class UserDaoImpl extends BaseDao implements UserDao {

    QueryRunner queryRunner = new QueryRunner();


    @Override
    public List<User> getAllUsers(int startIndex, int pageSize) throws Exception {
        String sql = "select * from t_user limit ?,?";

        List<User> users=null;

        users = queryRunner.query(this.getConnection(),sql,new BeanListHandler<User>(User.class),new Object[]{startIndex,pageSize});

        return users;
    }

    @Override
    public int totalRecords() throws Exception {
       int result = 0 ;
        Connection conn = this.getConnection();
        PreparedStatement ps = null;

        ResultSet rs = null;
        String sql = "select  count(*) cout from t_user";

        ps =conn.prepareStatement(sql);

        rs = ps.executeQuery();

        if(rs.next()){
            result=rs.getInt("count");

        }

        return result;

    }
}
