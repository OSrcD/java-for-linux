package com.imooc.item.service.impl;

import com.github.pagehelper.PageHelper;
import com.github.pagehelper.PageInfo;
import com.imooc.enums.CommentLevel;
import com.imooc.enums.YesOrNo;
import com.imooc.item.mapper.*;
import com.imooc.item.pojo.*;
import com.imooc.pojo.PagedGridResult;
import com.imooc.item.pojo.vo.CommentsLevelCountsVO;
import com.imooc.item.pojo.vo.ItemCommentVO;
import com.imooc.item.pojo.vo.ShopcartVO;
import com.imooc.item.service.ItemService;
import com.imooc.utils.DesensitizationUtil;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.bind.annotation.RestController;
import tk.mybatis.mapper.entity.Example;

import java.util.*;

@RestController
@Slf4j
public class ItemServiceImpl implements ItemService {

    @Autowired
    private ItemsMapper itemsMapper;
    @Autowired
    private ItemsImgMapper itemsImgMapper;
    @Autowired
    private ItemsSpecMapper itemsSpecMapper;
    @Autowired
    private ItemsParamMapper itemsParamMapper;
    @Autowired
    private ItemsCommentsMapper itemsCommentsMapper;
    @Autowired
    private ItemsMapperCustom itemsMapperCustom;

    @Transactional(propagation = Propagation.SUPPORTS)
    @Override
    public Items queryItemsById(String itemId) {
        return itemsMapper.selectByPrimaryKey(itemId);
    }

    @Transactional(propagation = Propagation.SUPPORTS)
    @Override
    public List<ItemsImg> queryItemsImgList(String itemId) {
        Example itemsImgExp = new Example(ItemsImg.class);
        Example.Criteria criteria = itemsImgExp.createCriteria();
        criteria.andEqualTo("itemId",itemId);
            return itemsImgMapper.selectByExample(itemsImgExp);
    }

    @Transactional(propagation = Propagation.SUPPORTS)
    @Override
    public List<ItemsSpec> queryItemsSpecList(String itemId) {
        Example itemsSpecExp = new Example(ItemsSpec.class);
        Example.Criteria criteria = itemsSpecExp.createCriteria();
        criteria.andEqualTo("itemId",itemId);
        return itemsSpecMapper.selectByExample(itemsSpecExp);

    }

    @Transactional(propagation = Propagation.SUPPORTS)
    @Override
    public ItemsParam queryItemsParam(String itemId) {
        Example itemsParamExp = new Example(ItemsParam.class);
        Example.Criteria criteria = itemsParamExp.createCriteria();
        criteria.andEqualTo("itemId",itemId);
        return itemsParamMapper.selectOneByExample(itemsParamExp);
    }

    @Transactional(propagation = Propagation.SUPPORTS)
    @Override
    public CommentsLevelCountsVO queryCommentsCounts(String itemId) {

        Integer goodCounts = getCommentsCounts(itemId,CommentLevel.GOOD.type);

        Integer normalCounts = getCommentsCounts(itemId,CommentLevel.NORMAL.type);

        Integer badCounts = getCommentsCounts(itemId,CommentLevel.BAD.type);

        Integer totalCounts = goodCounts + normalCounts + badCounts;

        CommentsLevelCountsVO countsVO = new CommentsLevelCountsVO();

        countsVO.setGoodCounts(goodCounts);

        countsVO.setNormalCounts(normalCounts);

        countsVO.setBadCounts(badCounts);

        countsVO.setTotalCounts(badCounts);

        return countsVO;
    }

    Integer getCommentsCounts(String itemId,Integer level){

        ItemsComments condition = new ItemsComments();

        condition.setItemId(itemId);

        if(level != null){
            condition.setCommentLevel(level);
        }

        return itemsCommentsMapper.selectCount(condition);

    }

    @Transactional(propagation = Propagation.SUPPORTS)
    @Override
    public PagedGridResult queryPagedComments(String itemId,
                                                  Integer level,
                                                  Integer page,
                                                  Integer pageSize) {

        Map<String,Object> map = new HashMap<>();
        map.put("itemId",itemId);
        map.put("level",level);

        // mybatis-pagehelper

        /**
         * page: 第几页
         * pageSize：每页显示条数
         */
        PageHelper.startPage(page,pageSize);

        List<ItemCommentVO> list = itemsMapperCustom.queryItemComments(map);

        for(ItemCommentVO vo : list){
            vo.setNickname(DesensitizationUtil.commonDisplay(vo.getNickname()));
        }

        return setterPagedGrid(list, page);
    }



    private PagedGridResult setterPagedGrid(List<?> list, Integer page) {
        PageInfo<?> pageList = new PageInfo<>(list);
        PagedGridResult grid = new PagedGridResult();
        grid.setPage(page);
        grid.setRows(list);
        grid.setTotal(pageList.getPages()); // 有几页
        grid.setRecords(pageList.getTotal()); // 每次取出总数
        return grid;
    }

//    @Transactional(propagation = Propagation.SUPPORTS)
//    @Override
//    public PagedGridResult searchItems(String keywords, String sort, Integer page, Integer pageSize) {
//
//        Map<String,Object> map = new HashMap<>();
//        map.put("keywords",keywords);
//        map.put("sort",sort);
//
//        PageHelper.startPage(page,pageSize);
//        List<SearchItemsVO>  list = itemsMapperCustom.searchItems(map);
//
//        return setterPagedGrid(list,page);
//    }
//
//    @Transactional(propagation = Propagation.SUPPORTS)
//    @Override
//    public PagedGridResult searchItems(Integer catId, String sort, Integer page, Integer pageSize) {
//        Map<String,Object> map = new HashMap<>();
//        map.put("catId",catId);
//        map.put("sort",sort);
//
//        PageHelper.startPage(page,pageSize);
//        List<SearchItemsVO> list = itemsMapperCustom.searchItemsByThirdCat(map);
//
//        return setterPagedGrid(list,page);
//    }

    @Transactional(propagation = Propagation.SUPPORTS)
    @Override
    public List<ShopcartVO> queryItemsBySpecIds(String specIds) {

        String[] ids = specIds.split(",");
        List<String> specIdsList = new ArrayList<>();
        Collections.addAll(specIdsList,ids);

        return itemsMapperCustom.queryItemsBySpecIds(specIdsList);


    }

    @Transactional(propagation = Propagation.SUPPORTS)
    @Override
    public ItemsSpec queryItemsSpecById(String specId) {
        return itemsSpecMapper.selectByPrimaryKey(specId);
    }

    @Transactional(propagation = Propagation.SUPPORTS)
    @Override
    public String queryItemMainImgById(String itemId) {
        ItemsImg itemsImg = new ItemsImg();
        itemsImg.setItemId(itemId);
        itemsImg.setIsMain(YesOrNo.YES.type);
        ItemsImg result = itemsImgMapper.selectOne(itemsImg);
        return result != null ? result.getUrl() : "";

    }

    @Transactional(propagation = Propagation.REQUIRED)
    @Override
    public void decreaseItemSpecStock(String specId, int buyCounts) {

        // synchronized 不推荐使用，集群下无用、性能低下
        // 锁数据库：不推荐，导致数据库性能低下
        // 分布式锁


        // lockUtil.getLock(); -- 加锁

        // 1. 查询库存
        int stock = 10;

        // 2. 判断库存，是否能够减少到0以下
        if(stock - buyCounts <0){
            // 提示用户库存不够
//            10 - 3 - 3 - 5 = -1
        }

        // lockUtil.unLock(); -- 解锁

        int result = itemsMapperCustom.decreaseItemSpecStock(specId,buyCounts);

        if(result != 1){
            throw new RuntimeException("订单创建失败，原因：库存不足！");
        }
    }


}
