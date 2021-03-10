package com.imooc.mybatis.dao;

import com.imooc.mybatis.dto.GoodsDTO;
import com.imooc.mybatis.entity.Goods;
import org.apache.ibatis.annotations.*;

import java.util.List;

public interface GoodsDAO {

    @Select("select * from t_goods where current_price between #{min} and #{max} order by current_price limit 0,#{limt}")
    public List<Goods> selectByPriceRange(@Param("max") Float max, @Param("min")Float min, @Param("limt")Integer limt);


    @Insert("insert into t_goods(title,sub_title,original_cost,current_price,discount,is_free_delivery,category_id) VALUES (#{title},#{subTitle},#{originalCost},#{currentPrice},#{discount},#{isFreeDelivery},#{categoryId})")
    @SelectKey(statement = "select last_insert_id()" , before = false , keyProperty = "goodsId" , resultType=Integer.class)
    public int insert(Goods goods);

    @Select("select * from t_goods")
    @Results({
            @Result(column="goods_id",property="goodsId",id=true),
            @Result(column="current_price",property="currentPrice"),
            @Result(column="title",property="title")
    })
    public List<GoodsDTO> selectAll();
}
