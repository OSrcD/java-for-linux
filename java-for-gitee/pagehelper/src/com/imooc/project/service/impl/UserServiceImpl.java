package com.imooc.project.service.impl;

import com.imooc.project.dao.PersonMapper;
import com.imooc.project.dao.UserDao;
import com.imooc.project.dao.impl.UserDaoImpl;
import com.imooc.project.entity.Person;
import com.imooc.project.entity.User;
import com.imooc.project.service.UserService;
import com.imooc.project.util.PageUtil;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;

import java.io.IOException;
import java.io.Reader;
import java.util.List;

public class UserServiceImpl implements UserService {
    private UserDao userDao = new UserDaoImpl();


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



    @Override
    public List<Person> getAllUsersBypageHelper() {
        SqlSession sqlSession = this.getSqlSessionFactory().openSession();
        PersonMapper personMapper = sqlSession.getMapper(PersonMapper.class);

        List<Person> persons = personMapper.getAllPersons();

        return persons;
    }

    @Override
    public PageUtil getAllUsers(String num) throws Exception {
        int currentPageNum=1;

        if(null!=num && !num.trim().equals("")){
            currentPageNum = Integer.parseInt(num);
        }

        int totalRecords = userDao.totalRecords();

        PageUtil pu = new PageUtil(currentPageNum, totalRecords);

        List<User> users = userDao.getAllUsers(pu.getStartIndex(), pu.getPageSize());

        pu.setRecords(users);

        return pu;
    }
}
