package com.imooc.jdbc.demo3;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import org.junit.Test;

import com.mchange.v2.c3p0.ComboPooledDataSource;
import com.opendevel.jdbc.utils.JDBCUtils;
import com.opendevel.jdbc.utils.JDBCUtils2;

public class DataSourceDemo1 {
	
	
	@Test
	public void demo2() {

		Connection conn = null;
		PreparedStatement pstmt = null;
		ResultSet rs = null;
		
		try {
//			ComboPooledDataSource dataSource = new ComboPooledDataSource();
//			conn = dataSource.getConnection();
			
			conn = JDBCUtils2.getConnection();
			String sql = "select * from user";
			
			pstmt = conn.prepareStatement(sql);
			
			rs = pstmt.executeQuery();
			
			while(rs.next()) {
				System.out.println(rs.getInt("uid")+"  "+rs.getString("username")+"  "+rs.getString("password")+"  "+rs.getString("name"));
			}
		
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally {
			JDBCUtils2.release(rs, pstmt, conn);
		}
		
	
	}
	
	
	
	
	@Test
	public void demo1() {

		Connection conn = null;
		PreparedStatement pstmt = null;
		ResultSet rs = null;
		
		try {
			ComboPooledDataSource dataSource = new ComboPooledDataSource();
			dataSource.setDriverClass("com.mysql.jdbc.Driver");
			dataSource.setJdbcUrl("jdbc:mysql:///jdbctest");
			dataSource.setUser("root");
			dataSource.setPassword("");
			dataSource.setMaxPoolSize(20);
			dataSource.setInitialPoolSize(3);
			conn = dataSource.getConnection();
			
			String sql = "select * from user";
			
			pstmt = conn.prepareStatement(sql);
			
			rs = pstmt.executeQuery();
			
			while(rs.next()) {
				System.out.println(rs.getInt("uid")+"  "+rs.getString("username")+"  "+rs.getString("password")+"  "+rs.getString("name"));
			}
			
			
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally {
			JDBCUtils.release(rs, pstmt, conn);
		}
		
		
	
	}
}
