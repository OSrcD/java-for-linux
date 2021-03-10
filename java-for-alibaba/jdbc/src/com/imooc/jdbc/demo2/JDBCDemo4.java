package com.imooc.jdbc.demo2;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;

import org.junit.Test;

import com.opendevel.jdbc.utils.JDBCUtils;

public class JDBCDemo4 {
	
	
	@Test
	public void demo1() {
		boolean flag = JDBCDemo4.login2("aaa' or '1=1", "111");
	
		if(flag==true) {
			System.out.println("��½�ɹ���");
		}else {
			System.out.println("��½ʧ��");
		}
	}
	
	
	
	public static boolean login2(String username,String password) {
		Connection conn = null;
		PreparedStatement pstmt = null;
		ResultSet rs = null;
		boolean flag = false;
		try {
			conn = JDBCUtils.getConnection();
			String sql = "select * from user where username = ? and password = ?";
			pstmt = conn.prepareStatement(sql);
			pstmt.setString(1, username);
			pstmt.setString(2, password);
			
			rs = pstmt.executeQuery();
			System.out.println(sql);
			if(rs.next()) {
				flag = true;
			}else {
				flag = false;
			}
			
		}catch(Exception e) {
			e.printStackTrace();
		}finally {
			JDBCUtils.release(rs,pstmt,conn);
		}
		

		return flag;
		
		
		
	}
	
	
	
	

	public static boolean login(String username,String password) {
		
		Connection conn = null;
		Statement stmt  =  null;
		ResultSet rs = null;
		boolean flag = false;
		try {
			conn = JDBCUtils.getConnection();
			stmt = conn.createStatement();
			String sql = "select * from user where username = '"+username+"' and password = '"+password+"' ";
			System.out.println(sql);
			rs = stmt.executeQuery(sql);
			
			if(rs.next()) {
				flag = true;
			}else {
				flag = false;
			}
		}catch(Exception e) {
			e.printStackTrace();
		}finally {
			JDBCUtils.release(rs,stmt,conn);
		}
		
		
		return flag;
		
		
	}
	
	
}
