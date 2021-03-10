package com.opendevel.jdbc.utils;

import java.io.IOException;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Properties;

public class JDBCUtils {
	private static final String driverClass;
	private static final String url;
	private static final String username;
	private static final String password;
	
	static {
		Properties props = new Properties();
		
		
		InputStream is = JDBCUtils.class.getClassLoader().getResourceAsStream("jdbc.properties");
		
		
		try {
			props.load(is);
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		
		driverClass = props.getProperty("driverClass");
		url = props.getProperty("url");
		username = props.getProperty("username");
		password = props.getProperty("password");
	}
	
	
	public static void loadDriver() throws ClassNotFoundException {
		Class.forName(driverClass);
	}
	
	
	public static Connection getConnection() throws Exception {
		loadDriver();
		Connection conn = DriverManager.getConnection(url,username,password);
		return conn;
	}
	
	
	public static void release(Statement stmt,Connection conn) {
		if(stmt!=null) {
			try {
				stmt.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
			
			stmt=null;
		}
		
		
		if(conn !=null) {
			try {
				conn.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
			conn=null;
		}
		
	}
	
	
	
	public static void release(ResultSet rs,Statement stmt,Connection conn) {
		if(rs!=null) {
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
				e.printStackTrace();
			}
			
			stmt=null;
		}
		
		
		if(conn !=null) {
			try {
				conn.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
			conn=null;
		}
	}
	
	
	
	
	
}
