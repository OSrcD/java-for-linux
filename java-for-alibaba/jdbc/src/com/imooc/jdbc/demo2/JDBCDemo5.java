package com.imooc.jdbc.demo2;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import org.junit.Test;

import com.opendevel.jdbc.utils.JDBCUtils;

public class JDBCDemo5 {
	
	
	@Test
	public void demo5() {
		Connection conn = null;
		PreparedStatement pstmt = null;
		ResultSet rs = null;
		
		
		try {
			conn = JDBCUtils.getConnection();
			String sql = "select * from user where uid=?";
			pstmt = conn.prepareStatement(sql);
		
			
			pstmt.setObject(1, 2);
			pstmt.executeQuery();
			rs = pstmt.executeQuery();
			
			if(rs.next()) {
				System.out.println(rs.getInt("uid")+" "+rs.getString("username")+"  "+rs.getString("password")+"  "+rs.getString("name"));
			}
			
			
		} catch (Exception e) {
			e.printStackTrace();
		}finally {
			JDBCUtils.release(rs,pstmt,conn);
		}
	}
	
	@Test
	public void demo4() {
		
		

		
		
		
		
		
		
		Connection conn = null;
		PreparedStatement pstmt = null;
		ResultSet rs = null;
		
		try {
			conn = JDBCUtils.getConnection();
			String sql = "select * from user";
			
			pstmt = conn.prepareStatement(sql);
			
			rs = pstmt.executeQuery();
			
			while(rs.next()) {
				System.out.println(rs.getInt("uid")+" "+rs.getString("username")+"  "+rs.getString("password")+"  "+rs.getString("name"));
			}
			
			
		} catch (Exception e) {
			e.printStackTrace();
		}finally {
			JDBCUtils.release(rs,pstmt,conn);
		}
	
	}
	
	
	
	
	
	
	
	@Test
	public void demo3() {
		Connection conn =null;
		PreparedStatement pstmt = null;
		
		try {
			conn = JDBCUtils.getConnection();
			String sql = "delete from user where uid=?";
			pstmt = conn.prepareStatement(sql);
			pstmt.setInt(1, 6);
			int num = pstmt.executeUpdate();
			
			if(num>0) {
				System.out.println("ɾ���ɹ�");
			}
			
		} catch (Exception e) {
			
		}finally {
			JDBCUtils.release(pstmt, conn);
		}
		
	}
	
	
	
	
	
	@Test
	public void demo2() {
		Connection conn = null;
		PreparedStatement pstmt = null;
		try {
			conn = JDBCUtils.getConnection();
			String sql = "update user set username=?,password=?,name=? where uid=?";
			pstmt = conn.prepareStatement(sql);
			pstmt.setString(1, "www");
			pstmt.setString(2, "123456");
			pstmt.setString(3, "����");
			pstmt.setInt(4, 6);
			int num = pstmt.executeUpdate();
			if(num > 0) {
				System.out.println("�޸ĳɹ�");
			}
		} catch (Exception e) {
			// TODO: handle exception
		}finally {
			JDBCUtils.release(pstmt, conn);
		}
	
		
		
	}
	
	
	
	
	
	
	@Test
	public void demo1() {
		Connection conn = null;
		PreparedStatement pstmt = null;
		
		try {
			conn = JDBCUtils.getConnection();
			String sql = "insert into user values(null,?,?,?)";
			pstmt = conn.prepareStatement(sql);
			pstmt.setString(1, "qqq");
			pstmt.setString(2, "123");
			pstmt.setString(3, "����");
			int num = pstmt.executeUpdate();
			if(num > 0) {
				System.out.println("����ɹ���");
			}
		}catch(Exception e) {
			e.printStackTrace();
			
		}finally {
			JDBCUtils.release(pstmt, conn);
		}
		
		
	}
	
	
}
