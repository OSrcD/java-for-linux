package com.opendevel.jdbc.demo1;

import java.sql.Connection;
import java.sql.Statement;

import org.junit.Test;

import com.opendevel.jdbc.utils.JDBCUtils;

public class JDBCDemo3 {
	
	@Test
	
	public void demo1() {
		Connection conn = null;
		Statement stmt = null;
		try{
			conn =  JDBCUtils.getConnection();
			stmt = conn.createStatement();
			
			String sql = "insert into user values(null,'fff','123','С��')";
			int num = stmt.executeUpdate(sql);
			
			if(num > 0) {
				System.out.println("����ɹ�");
			}
			
		}catch (Exception e) {
			e.printStackTrace();
		}finally {
			JDBCUtils.release(stmt, conn);
		}
	}
	
}
