package com.imooc.mybatis;

import com.imooc.mybatis.dao.GoodsDAO;
import com.imooc.mybatis.dto.GoodsDTO;
import com.imooc.mybatis.entity.Goods;
import com.imooc.mybatis.utils.MyBatisUtils;
import org.apache.ibatis.session.SqlSession;
import org.junit.Test;

import java.util.List;

//JUNIT单元测试类
public class MyBatisTestor {

    @Test
    public void testSelectByPriceRange() throws Exception{
        SqlSession sqlSession = null;
        try{
            sqlSession = MyBatisUtils.openSession();
            GoodsDAO goodsDAO =  sqlSession.getMapper(GoodsDAO.class);
            List<Goods> list =goodsDAO.selectByPriceRange(500f,0f,20);
            System.out.println(list.size());
        }catch(Exception e){
            throw e;
        }finally{
            if(sqlSession != null){
                MyBatisUtils.closeSession(sqlSession);
            }
        }
    }

    @Test
    public void testInsert()throws Exception{
        SqlSession sqlSession = null;
        try{
            sqlSession = MyBatisUtils.openSession();
            Goods good = new Goods();
            good.setTitle("测试商品");
            good.setSubTitle("测试子标题");
            good.setOriginalCost(200f);
            good.setCurrentPrice(100f);
            good.setDiscount(0.5f);
            good.setIsFreeDelivery(1);
            good.setCategoryId(43);
            GoodsDAO goodsDAO = sqlSession.getMapper(GoodsDAO.class);
            int num = goodsDAO.insert(good);
            sqlSession.commit();
            System.out.println(good.getGoodsId());
        }catch(Exception e){

            if(sqlSession != null){
                sqlSession.rollback();
            }
            throw e;
        }finally{
            if(sqlSession != null){
                MyBatisUtils.closeSession(sqlSession);
            }
        }
    }

    @Test
    public void testSelectAll()throws Exception{
        SqlSession session = null;
        try{
            session = MyBatisUtils.openSession();
            GoodsDAO goodsDAO = session.getMapper(GoodsDAO.class);
            List<GoodsDTO> goods = goodsDAO.selectAll();
            System.out.println(goods.size());
        }catch(Exception e){
            if(session != null){
                session.rollback();
            }
            throw e;
        }finally{
            MyBatisUtils.closeSession(session);
        }
    }
}
