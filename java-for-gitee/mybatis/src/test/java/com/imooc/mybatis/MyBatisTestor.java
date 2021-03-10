package com.imooc.mybatis;


import com.github.pagehelper.Page;
import com.github.pagehelper.PageHelper;
import com.imooc.mybatis.dto.GoodsDTO;
import com.imooc.mybatis.entity.Goods;
import com.imooc.mybatis.entity.GoodsDetail;
import com.imooc.mybatis.utils.MyBatisUtils;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.junit.Test;

import java.io.IOException;
import java.io.Reader;
import java.sql.Connection;
import java.util.*;


public class MyBatisTestor {

    @Test
    public void testSqlSessionFactory() throws IOException {

        Reader reader = Resources.getResourceAsReader("mybatis-config.xml");
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(reader);

        System.out.println("SessionFactory加载成功");
        SqlSession sqlSession = null;
        try {
            sqlSession = sqlSessionFactory.openSession();
            Connection connection = sqlSession.getConnection();

            System.out.println(connection);
        }catch(Exception e){
            e.printStackTrace();
        }finally{
            if(!(Objects.equals(null,sqlSession))){
                sqlSession.close();
                System.out.println("释放资源");
            }
        }
    }

    @Test
    public void testMyBatisUtils() throws Exception{
        SqlSession sqlSession = null;
        try {
            sqlSession = MyBatisUtils.openSession();
            Connection connection = sqlSession.getConnection();
            System.out.println(connection);
        }catch(Exception e){
            e.printStackTrace();
            throw e;
        }finally{
            if(sqlSession != null){
                MyBatisUtils.closeSqlSession(sqlSession);
            }
        }
    }

    @Test
    public void testSelectAll() throws Exception{
        SqlSession sqlSession = null;
        try{
            sqlSession = MyBatisUtils.openSession();
            /**
             * "list":Ljava/util/List;, "Ljava/util/List<Lcom/imooc/mybatis/entity/Goods;>;"
             */
            List<Goods> goods = sqlSession.<Goods>selectList("goods.selectAll");
            List<Goods> list = goods;
            System.out.println(list);
            for(Goods g : list){
                System.out.println(g.getTitle());
            }
        }catch(Exception e){
            throw e;
        }finally{
            MyBatisUtils.closeSqlSession(sqlSession);
        }
    }

    @Test
    public void testSelectByID() throws Exception {
        SqlSession sqlSession = null;

        try{
            sqlSession = MyBatisUtils.openSession();
            Goods g = sqlSession.selectOne("goods.selectById",1602);
            System.out.println(g.getTitle());
        }catch(Exception e){
            throw e;
        }finally{
            if(sqlSession != null){
                MyBatisUtils.closeSqlSession(sqlSession);
            }
        }
    }


    @Test
    public void testSelectByPriceRange(){
        SqlSession sqlSession = null;
        try{
            sqlSession = MyBatisUtils.openSession();
            Map param = new HashMap();
            param.put("max",500);
            param.put("min",100);
            param.put("limt",10);
            List<Goods> goods = sqlSession.selectList("selectByPriceRange",param);
            for (Goods good : goods) {
                System.out.println(good.getTitle() + ":" + good.getCurrentPrice());
            }
        }catch(Exception e){
            throw e;
        }finally{
            if(sqlSession != null) {
                MyBatisUtils.closeSqlSession(sqlSession);
            }
        }
    }


    @Test
    public void testSelectGoodsMap() throws Exception{
        SqlSession sqlSession = null;
        try{
            sqlSession = MyBatisUtils.openSession();
            List<Map> list =sqlSession.selectList("selectGoodsMap");
            for(Map m : list){
                System.out.println(m);
            }
        }catch(Exception e){
            throw e;
        }finally{
            if(sqlSession != null){
                MyBatisUtils.closeSqlSession(sqlSession);
            }
        }
    }


    @Test
    public void testSelectGoodsDTO() throws Exception{
        SqlSession sqlSession = null;
        try{
            sqlSession = MyBatisUtils.openSession();
            List<GoodsDTO> GoodsDTOList = sqlSession.selectList("selectGoodsDTO");
            for(GoodsDTO g : GoodsDTOList){
                System.out.println(g.getGoods().getTitle());
            }
        }catch(Exception e){
            throw e;
        }finally{
            if(sqlSession != null){
                MyBatisUtils.closeSqlSession(sqlSession);
            }
        }
    }

    @Test
    public void testInsert() throws Exception {
        SqlSession sqlSession = null;
        try{
            sqlSession = MyBatisUtils.openSession();
            Goods goods = new Goods();
            goods.setTitle("测试商品");
            goods.setSubTitle("测试子标题");
            goods.setOriginalCost(200f);
            goods.setCurrentPrice(100f);
            goods.setDiscount(0.5f);
            goods.setIsFreeDelivery(1);
            goods.setCategoryId(43);
            int num = sqlSession.insert("goods.insert",goods);
            sqlSession.commit();
            System.out.println(goods.getGoodsId());
        }catch(Exception e){
            if(sqlSession != null){
                sqlSession.rollback();
            }
            throw e;
        }finally{
            if(sqlSession != null){
                MyBatisUtils.closeSqlSession(sqlSession);
            }
        }
    }


    @Test
    public void testUpdate() throws Exception{
        SqlSession sqlSession = null;
        try{
            sqlSession = MyBatisUtils.openSession();
            Goods goods = sqlSession.selectOne("goods.selectById",739);
            goods.setTitle("更新测试商品");
            int num = sqlSession.update("goods.update",goods);
            System.out.println(num);
            sqlSession.commit();
        }catch(Exception e){
            if(sqlSession != null){
                sqlSession.rollback();
            }

            throw e;

        }finally{
            if(sqlSession != null){
                MyBatisUtils.closeSqlSession(sqlSession);
            }
        }
    }

    @Test
    public void testDelete() throws Exception{
        SqlSession sqlSession = null;
        try{
            sqlSession = MyBatisUtils.openSession();
            int num = sqlSession.delete("goods.delete",739);
            sqlSession.commit();
        }catch(Exception e){
            if(sqlSession != null){
                sqlSession.rollback();
            }
            throw e;

        }finally{
            MyBatisUtils.closeSqlSession(sqlSession);
        }
    }


    @Test
    public void testSelectByTitle() throws Exception{
        SqlSession sqlSession = null;
        try{
            sqlSession = MyBatisUtils.openSession();
            Map param = new HashMap();
            param.put("title","'' or 1=1 or title='【欧洲直邮】德国Hipp喜宝有机奶粉pre段 600g*2'");
            param.put("order","order by title desc");
            System.out.println(param.get("title"));
            List<Goods> list = sqlSession.selectList("goods.selectByTitle",param);
            for(Goods good : list){
                System.out.println(good.getTitle() + ":" + good.getCurrentPrice());
            }
        }catch(Exception e){
            throw e;
        }finally{
            MyBatisUtils.closeSqlSession(sqlSession);
        }
    }

    @Test
    public void testDynamicSQL() throws Exception{
        SqlSession sqlSession = null;
        try{
            sqlSession = MyBatisUtils.openSession();
            Map param = new HashMap();
            param.put("categoryId",44);
            param.put("currentPrice",500);
            List<Goods> list = sqlSession.selectList("goods.dynamicSQL",param);
            for(Goods g : list){
                System.out.println(g.getTitle() + ":" + g.getCategoryId()+":"+g.getCurrentPrice());

            }


        }catch(Exception e){
            throw e;
        }finally{
            if(sqlSession != null){
                MyBatisUtils.closeSqlSession(sqlSession);
            }
        }
    }


    @Test
    public void testLv1Cache() throws Exception{
        SqlSession sqlSession = null;
        try{
            sqlSession = MyBatisUtils.openSession();
            Goods good = sqlSession.selectOne("goods.selectById", 1603);
            Goods good1 = sqlSession.selectOne("goods.selectById",1603);
            System.out.println(good.hashCode() + ":" + good1.hashCode());
        }catch(Exception e){
            throw e;
        }finally{
            if(sqlSession != null){
                MyBatisUtils.closeSqlSession(sqlSession);
            }
        }


        try{
            sqlSession = MyBatisUtils.openSession();
            Goods good = sqlSession.selectOne("goods.selectById", 1603);
            sqlSession.commit();
            Goods good1 = sqlSession.selectOne("goods.selectById",1603);
            System.out.println(good.hashCode() + ":" + good1.hashCode());
        }catch(Exception e){
            throw e;
        }finally{
            if(sqlSession != null){
                MyBatisUtils.closeSqlSession(sqlSession);
            }
        }

    }

    @Test
    public void testLv2Cache() throws Exception{
        SqlSession sqlSession = null;
        try{
            sqlSession = MyBatisUtils.openSession();
            Goods good = sqlSession.selectOne("goods.selectById", 1603);
            System.out.println(good.hashCode());
        }catch(Exception e){
            throw e;
        }finally{
            if(sqlSession != null){
                MyBatisUtils.closeSqlSession(sqlSession);
            }
        }


        try{
            sqlSession = MyBatisUtils.openSession();

            Goods good = sqlSession.selectOne("goods.selectById", 1603);
            sqlSession.commit();
            Goods good2 = sqlSession.selectOne("goods.selectById", 1603);
            System.out.println(good.hashCode());
        }catch(Exception e){
            throw e;
        }finally{
            if(sqlSession != null){
                MyBatisUtils.closeSqlSession(sqlSession);
            }
        }

    }


    @Test
    public void testOneToMany() throws Exception{
        SqlSession sqlSession = null;

        try{
            sqlSession = MyBatisUtils.openSession();
            List<Goods> goods = sqlSession.selectList("goods.selectOneToMany");
           for(Goods g : goods){
               System.out.println(g.getTitle() + ":" + g.getGoodsDetails().size());
           }
        }catch(Exception e){
            throw e;
        }finally{
            if(sqlSession != null){
                MyBatisUtils.closeSqlSession(sqlSession);
            }
        }
    }

    @Test
    public void testManyToOne() throws Exception{
        SqlSession sqlSession = null;
        try{
            sqlSession = MyBatisUtils.openSession();
            List<GoodsDetail> goodsDetails = sqlSession.selectList("goodsDetail.selectManyToOne");
            for(GoodsDetail goodsDetail : goodsDetails) {
                if (!(Objects.equals(goodsDetail.getGoods(), null))) {
                    System.out.println(goodsDetail.getGdPicUrl() + ":" + goodsDetail.getGoods().getTitle());

                }
            }
        }catch(Exception e){
            throw e;
        }finally{
            if(sqlSession != null){
                MyBatisUtils.closeSqlSession(sqlSession);
            }
        }
    }

    @Test
    public void testSelectPage() throws Exception{
        SqlSession sqlSession = null;
        try{
             sqlSession = MyBatisUtils.openSession();
             PageHelper.startPage(2,10);

            Page<Goods> page =(Page)sqlSession.selectList("goods.selectPage");

            System.out.println(page.getPages());
            System.out.println(page.getTotal());
            System.out.println(page.getStartRow());
            System.out.println(page.getEndRow());
            System.out.println(page.getPageNum());
            List<Goods> list = page.getResult();
            for(Goods g : list){
                System.out.println(g.getTitle());
            }
            System.out.println();

        }catch(Exception e){
            throw e;
        }finally{
            if(sqlSession != null){
                MyBatisUtils.closeSqlSession(sqlSession);
            }
        }
    }


    @Test
    public void testBatchInsert() throws Exception{
        SqlSession sqlSession = null;
        try{
            long st = new Date().getTime();
            sqlSession = MyBatisUtils.openSession();
            List list = new ArrayList();
            for(int i=0;i<10000;i++){
                Goods g = new Goods();
                g.setTitle("测试商品");
                g.setSubTitle("测试子标题");
                g.setOriginalCost(200f);
                g.setCurrentPrice(100f);
                g.setDiscount(0.5f);
                g.setIsFreeDelivery(1);
                g.setCategoryId(43);
                list.add(g);
            }
            sqlSession.insert("goods.batchInsert",list);
            sqlSession.commit();
            long et = new Date().getTime();
            System.out.println((et-st) + "毫秒");
        }catch(Exception e){
            if(sqlSession != null){
                sqlSession.rollback();
            }
            throw e;
        }finally{
            MyBatisUtils.closeSqlSession(sqlSession);
        }
    }

    @Test
    public void testInsert1() throws Exception{
        SqlSession sqlSession = null;
        try{
            long st = new Date().getTime();
            sqlSession = MyBatisUtils.openSession();
            List list = new ArrayList();
            for(int i=0;i<10000;i++){
                Goods g = new Goods();
                g.setTitle("测试商品");
                g.setSubTitle("测试子标题");
                g.setOriginalCost(200f);
                g.setCurrentPrice(100f);
                g.setDiscount(0.5f);
                g.setIsFreeDelivery(1);
                g.setCategoryId(43);
                sqlSession.insert("goods.insert",g);
            }

            sqlSession.commit();
            long et = new Date().getTime();
            System.out.println((et-st) + "毫秒");
        }catch(Exception e){
            if(sqlSession != null){
                sqlSession.rollback();
            }
            throw e;
        }finally{
            MyBatisUtils.closeSqlSession(sqlSession);
        }
    }


    @Test
    public void testBatchDelete() throws Exception {
        SqlSession sqlSession = null;
        try{
            long st = new Date().getTime();
            sqlSession = MyBatisUtils.openSession();
            List list = new ArrayList();
            list.add(1920);
            list.add(1921);
            list.add(1922);
            sqlSession.delete("goods.batchDelete",list);
            sqlSession.commit();
            long et = new Date().getTime();
            System.out.println("执行时间：" + (et - st) + "毫秒");
        }catch(Exception e){
            if(sqlSession != null){
                sqlSession.rollback();
            }
            throw e;

        }finally{
            MyBatisUtils.closeSqlSession(sqlSession);
        }
    }

}
