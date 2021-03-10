package com.mooc.springtransactions;

import java.sql.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.simple.SimpleJdbcInsert;
import org.springframework.jdbc.datasource.DataSourceTransactionManager;
import org.springframework.transaction.PlatformTransactionManager;
import org.springframework.transaction.TransactionStatus;
import org.springframework.transaction.support.DefaultTransactionDefinition;
import org.springframework.transaction.support.TransactionCallback;
import org.springframework.transaction.support.TransactionCallbackWithoutResult;
import org.springframework.transaction.support.TransactionTemplate;

import com.mooc.beans.Book;
import com.mooc.utils.TemplateUtils;

/**
 * Spring的两种编程模式演示
 * 
 * @author Solo cui
 *
 */
public class ProTransExample {
	// 事务模板：第二种事务编程模式
	// private TransactionTemplate transactionTemplate ;

	// 数据持久化操作
	public void addBook(final Book book) {
		// 获取事务模板对象
		TransactionTemplate tt = TemplateUtils.getTransactionTemplate();
		// 可设置事务属性，如隔离级别、超时时间等,如：
		// tt.setIsolationLevel(TransactionDefinition.ISOLATION_READ_UNCOMMITTED);

		tt.execute(new TransactionCallbackWithoutResult() {
			protected void doInTransactionWithoutResult(TransactionStatus s) {
				try {
					// 数据库操作1
					// JdbcTemplate jdbcTemplate
					// =TemplateUtils.getJdbcTemplate();
					// jdbcTemplate.execute(sql);
					// 简单模板化新增数据
					SimpleJdbcInsert simpleInsert = TemplateUtils.getSimpleJdbcTemplate();
					simpleInsert.withTableName("books").usingColumns("isbn", "name", "price", "pubdate");
					Map<String, Object> parameters = new HashMap<String, Object>();
					parameters.put("isbn", book.getIsbn());
					parameters.put("name", book.getName());
					parameters.put("price", book.getPrice());
					parameters.put("pubdate", book.getPubdate());
					simpleInsert.execute(parameters);
					System.out.println("新增数据成功！");
					// 或者DAO数据操作模式：
					// BookDAO.save(book);
				} catch (Exception e) {
					s.setRollbackOnly();
					e.printStackTrace();
				}
			}
		});
	}

	public Book findBookByIsbn(final String isbn) {
		TransactionTemplate tt = TemplateUtils.getTransactionTemplate();
		Book book = null;
		@SuppressWarnings("unchecked")
		List<Map<String, Object>> books = (List<Map<String, Object>>) tt.execute(new TransactionCallback<Object>() {
			public Object doInTransaction(TransactionStatus arg0) {
				JdbcTemplate jdbcTemplate = TemplateUtils.getJdbcTemplate();
				return jdbcTemplate
						.queryForList("select isbn,name,price,pubdate from books where isbn ='" + isbn + "'");
			}
		});
		if (books != null) {// 封装获取的数据
			Map<String, Object> m = (Map) books.get(0);
			book = new Book();
			book.setIsbn(m.get("isbn").toString());
			book.setName(m.get("name").toString());
			book.setPrice((Float) m.get("price"));
			book.setPubdate((Date) m.get("pubdate"));
		}
		return book;
	}

	// 1、编程式事务管理：事务管理器PlatformTransactionManager方式实现
	public void updateBookByIsbn(Book book) {
		//第一步：获取JDBC事务管理器
		DataSourceTransactionManager dtm = TemplateUtils.getDataSourceTransactionManager();
		// 第二步：创建事务管理器属性对象
		DefaultTransactionDefinition transDef = new DefaultTransactionDefinition(); // 定义事务属性
		// 根据需要，设置事务管理器的相关属性
		// 设置传播行为属性
		transDef.setPropagationBehavior(DefaultTransactionDefinition.PROPAGATION_REQUIRED);
		// 第三步：获得事务状态对象
		TransactionStatus ts = dtm.getTransaction(transDef);
		// 第四步：基于当前事务管理器,获取数据源，创建操作数据库的JDBC模板对象
		JdbcTemplate jt = new JdbcTemplate(dtm.getDataSource());
		try {//第五步：业务操作
			jt.update("update books set price="+book.getPrice()+",name='"+book.getName()
			              +"'  where isbn='"+book.getIsbn()+"' ");
			// 其它数据操作如增删
			//第六步：提交事务
			dtm.commit(ts); // 如果不commit，则更新无效果
		} catch (Exception e) {
			dtm.rollback(ts);
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		ProTransExample pte = new ProTransExample();
		Book book = pte.findBookByIsbn("128-166-890-China");
		book.setName("华夏龙图腾");
		book.setPrice(128.5f);
		pte.updateBookByIsbn(book);
		/*
		 *1-新增书籍
		 * Date pd = new Date(System.currentTimeMillis()); Book book = new
		 * Book(); book.setIsbn("120-166-990-China"); book.setName("人性的弱点");
		 * book.setPrice(65.6f); book.setPubdate(pd);
		 */		
		// pte.addBook(book);
		//2-查找书籍
		/*Book bk = pte.findBookByIsbn("120-166-890-China");
		System.out.println("书籍名称：" + bk.getName());*/
		//3-更新书籍名称和价格

	}

}


