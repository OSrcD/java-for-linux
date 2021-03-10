package com.imooc.project.test;

import java.io.IOException;
import java.io.Reader;
import java.util.List;
import com.github.pagehelper.Page;
import com.github.pagehelper.PageHelper;
import com.github.pagehelper.PageInfo;
import com.imooc.project.dao.PersonMapper;
import com.imooc.project.entity.Person;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;

 
public class MyBatisTest {
	public static SqlSessionFactory sqlSessionFactory = null;

	public static SqlSessionFactory getSqlSessionFactory() {
		if (sqlSessionFactory == null) {
			String resource = "mybatis-config.xml";
			try {
				Reader reader = Resources.getResourceAsReader(resource);
				sqlSessionFactory = new SqlSessionFactoryBuilder().build(reader);
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		return sqlSessionFactory;
	}

	/*public void testCollection()
	{
		SqlSession sqlSession = this.getSqlSessionFactory().openSession();

		PersonMapper personMapper = sqlSession.getMapper(PersonMapper.class);

		Person person=personMapper.getPersonByCollection(new int[]{1,2,3,4,5});

		System.out.println(person);

	}*/


	public  void getAllPersons()
	{
		SqlSession sqlSession = this.getSqlSessionFactory().openSession();

		PersonMapper personMapper = sqlSession.getMapper(PersonMapper.class);

		Page<Object> page=PageHelper.startPage(1,10);

		List<Person> persons=personMapper.getAllPersons();

		PageInfo pageInfo=new PageInfo(persons,9);
		for (Person person:persons)
		{
			System.out.println(person.getId());
		}

		System.out.println(page.getPageNum());//current page
		System.out.println(page.getTotal());//total
		System.out.println(page.getPageSize());//page size

		System.out.println(pageInfo.isIsFirstPage());

		System.out.println(pageInfo.getPages());// total pages

		int[] nums=pageInfo.getNavigatepageNums();

		for (int i = 0; i < nums.length; i++) {
			System.out.println(nums[i]);
		}


	}

	public static void main(String[] args) {

		new MyBatisTest().getAllPersons();


	}









	

 
  
	
}
