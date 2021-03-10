package com.imooc.mybatis.utils;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;

import java.io.Reader;

public class MyBatisUtils {
    private static SqlSessionFactory sqlSessionFactory = null;

    static{
        Reader reader = null;

        try {
            reader = Resources.getResourceAsReader("mybatis-config.xml");
            sqlSessionFactory = new SqlSessionFactoryBuilder().build(reader);
        }catch(Exception e){
            e.printStackTrace();
            throw new ExceptionInInitializerError(e);
        }
    }


    public static SqlSession openSession(){

        return sqlSessionFactory.openSession(false);
    }

    public static void closeSqlSession(SqlSession sqlSession) {

            if(sqlSession!=null){
                sqlSession.close();
            }

    }


}

