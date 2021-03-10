package com.opendevel.jdbc.demo1;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import org.junit.Test;

import com.mysql.jdbc.Driver;

public class JDBCDemo1 {
	
	@Test
	public  void demo1() {
		Connection conn = null;
		Statement stmt = null;
		ResultSet  rs  = null;
		
		try {
			DriverManager.registerDriver(new Driver());
			
			 conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/jdbctest", "root", "");
			String sql = "select * from user";
			
			 stmt = conn.createStatement();
			
			 rs =  stmt.executeQuery(sql);
			
			
			while(rs.next()) {
				int uid =rs.getInt("uid");
				String username = rs.getString("username");
				String password = rs.getString("password");
				String name = rs.getString("name");
			
				System.out.println(uid+"   "+username+"   "+password+"   "+name);
			}
			
			
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally {
			if(rs != null) {
				try {
					rs.close();
				} catch (SQLException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				rs=null;
			}
			if(stmt!=null) {
				try {
					stmt.close();
				} catch (SQLException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				stmt=null;
			}
			if(conn!=null) {
				try {
					conn.close();
				} catch (SQLException e) {
					e.printStackTrace();
				}
				conn=null;
			}
		}
		
		
		
	}
	

	
}
