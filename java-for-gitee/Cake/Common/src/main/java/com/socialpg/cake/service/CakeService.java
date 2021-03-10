package com.opendevel.cake.service;

import com.opendevel.cake.common.MyBatisUtils;
import com.opendevel.cake.entity.Cake;
import com.opendevel.cake.mapper.CakeMapper;
import org.apache.ibatis.session.SqlSession;

import java.util.Date;
import java.util.List;

/**
 * 蛋糕
 */
public class CakeService {

    /**
     * 分页查询蛋糕
     * @param page  要查询的页数
     * @param size  要查询的记录数
     * @return 蛋糕集合
     */
    public List<Cake> getCakesByCategoryId(Long categoryId,Integer page,Integer size){
        SqlSession sqlSession = MyBatisUtils.openSession();

        try {
            CakeMapper mapper = sqlSession.getMapper(CakeMapper.class);
            return mapper.getCakesByCategoryId(categoryId, (page-1)*size, page);
        } finally {
            sqlSession.close();
        }



    }

    /**
     * 新增蛋糕
     * @param cake 蛋糕信息
     */

    public void addCake(Cake cake){
        Date now = new Date();
        cake.setCreateTime(now);
        cake.setUpdateTime(now);
        SqlSession sqlSession = MyBatisUtils.openSession();
        try{
          CakeMapper mapper = sqlSession.getMapper(CakeMapper.class);

            mapper.addCake(cake);
            sqlSession.commit();
        }finally{
            sqlSession.close();
        }
    }

    /**
     * 统计给定分类ID下的蛋糕数量
     * @param categoryId    分类ID
     * @return  统计结果
     */
    public int countCakesByCategoryId(Long categoryId) {
        SqlSession sqlSession = MyBatisUtils.openSession();
        try {
            CakeMapper mapper = sqlSession.getMapper(CakeMapper.class);
            return mapper.countCakesByCategoryId(categoryId);
        } finally {
            sqlSession.close();
        }
    }

    /**
     * 根据ID查询对应的图片
     * @param id    蛋糕ID
     * @return  只包含图片信息的蛋糕实体
     */
    public Cake getCakeImg(Long id) {
        SqlSession sqlSession = MyBatisUtils.openSession();
        try {
            CakeMapper mapper = sqlSession.getMapper(CakeMapper.class);
            return mapper.getImg(id);
        } finally {
            sqlSession.close();
        }
    }

}
