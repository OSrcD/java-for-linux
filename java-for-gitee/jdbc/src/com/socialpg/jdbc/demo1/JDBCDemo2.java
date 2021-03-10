package com.opendevel.jdbc.demo1;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import org.junit.Test;



public class JDBCDemo2 {
	
	@Test
	
	public void demo5() {
		Connection conn = null;
		Statement stmt = null;
		ResultSet rs = null;
		
		try {
			Class.forName("com.mysql.jdbc.Driver");
			conn = DriverManager.getConnection("jdbc:mysql:///jdbctest","root","");
			
			stmt = conn.createStatement();
			String sql = "select * from user where uid=2";
			
			rs = stmt.executeQuery(sql);
			
			if(rs.next()) {
				System.out.println(rs.getInt("uid")+"  "+rs.getString("username")+"  "+rs.getString("password")+"  "+rs.getString("name"));
			}
			
			
			
		}catch(Exception e) {
			e.printStackTrace();
		}finally {
			if(rs!=null) {
				try {
					rs.close();
				} catch (SQLException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				rs=null;
			}
			
			
			if(stmt !=null) {
				try {
					stmt.close();
				} catch (SQLException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				stmt=null;
			}
			
			if(conn !=null) {
				try {
					conn.close();
				} catch (SQLException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				conn = null;
			}
		}
	}
	
	
	
	
	
	
	@Test
	public void demo4() {
		Connection conn = null;
		Statement stmt = null;
		ResultSet rs = null;
		
		try {
			Class.forName("com.mysql.jdbc.Driver");
			conn = DriverManager.getConnection("jdbc:mysql:///jdbctest","root","");
			stmt = conn.createStatement();
			
			String sql = "select * from user";
			
			rs = stmt.executeQuery(sql);
			
			
			while(rs.next()) {
				System.out.println(rs.getInt("uid")+"   "+rs.getString("username")+"  "+rs.getString("password") +"  "+rs.getString("name"));
			}
			
			
		}catch(Exception e) {
			e.printStackTrace();
		}finally {
			if(rs!=null) {
				try {
					rs.close();
				} catch (SQLException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				rs=null;
			}
			
			
			if(stmt !=null) {
				try {
					stmt.close();
				} catch (SQLException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				stmt=null;
			}
			
			if(conn !=null) {
				try {
					conn.close();
				} catch (SQLException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				conn = null;
			}
		}
		
	}
	
	@Test
	public void demo3() {
		Connection conn = null;
		Statement stmt = null;
		
		try {
			Class.forName("com.mysql.jdbc.Driver");
			conn = DriverManager.getConnection("jdbc:mysql:///jdbctest","root","");
			stmt = conn.createStatement();
			String sql = "delete from user where uid = 4";
			int i = stmt.executeUpdate(sql);
			
			if(i>0) {
				System.out.println("ɾ���ɹ���");
			}
		}catch(Exception e) {
			e.printStackTrace();
		}finally {
			if(stmt !=null) {
				try {
					stmt.close();
				} catch (SQLException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				stmt=null;
			}
			
			if(conn !=null) {
				try {
					conn.close();
				} catch (SQLException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				conn = null;
			}
		}
	}
	
	
	
	@Test
	public void demo2() {
		Connection conn = null;
		Statement stmt = null;
		try {
			
			Class.forName("com.mysql.jdbc.Driver");
			conn = DriverManager.getConnection("jdbc:mysql:///jdbctest","root","");
			stmt = conn.createStatement();
			String sql = "update user set username = 'qqq',password='456',name='����'  where uid= 4";
			int i= stmt.executeUpdate(sql);
			if(i>0) {
				System.out.println("�޸ĳɹ�");
			}
		}catch(Exception e) {
			e.printStackTrace();
		}finally {
			if(stmt !=null) {
				try {
					stmt.close();
				} catch (SQLException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				stmt=null;
			}
			
			if(conn !=null) {
				try {
					conn.close();
				} catch (SQLException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				conn = null;
			}
		}	
	
	}
	
	
	
	
	
	
	
	@Test
	public void demo1() {
		Connection conn = null;
		Statement stmt = null;
		try {
			Class.forName("com.mysql.jdbc.Driver");
			conn = DriverManager.getConnection("jdbc:mysql:///jdbctest","root","");
			stmt = conn.createStatement();
			String sql = "insert user value(null,'eee','123','����')";
			int i = stmt.executeUpdate(sql);
			
			if(i>0) {
				System.out.println("����ɹ�!");
			}
			
			
		}catch (Exception e) {
			e.printStackTrace();
		}finally {
			if(stmt !=null) {
				try {
					stmt.close();
				} catch (SQLException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				stmt=null;
			}
			
			if(conn !=null) {
				try {
					conn.close();
				} catch (SQLException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				conn = null;
			}
		}
	}
}
