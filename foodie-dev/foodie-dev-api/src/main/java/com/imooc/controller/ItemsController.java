package com.imooc.controller;

import com.imooc.pojo.Items;
import com.imooc.pojo.ItemsImg;
import com.imooc.pojo.ItemsParam;
import com.imooc.pojo.ItemsSpec;
import com.imooc.pojo.vo.CommentsLevelCountsVO;
import com.imooc.pojo.vo.ItemInfoVO;
import com.imooc.service.ItemService;
import com.imooc.utils.IMOOCJSONResult;
import com.imooc.utils.PagedGridResult;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@Api(value="商品接口",tags={"商品信息展示的相关接口"})
@RestController
@RequestMapping("items")
public class ItemsController extends BaseController {


    @Autowired
    private ItemService itemService;



    @ApiOperation(value="查询商品详情",notes="查询商品详情",httpMethod = "GET")
    @GetMapping("/info/{itemId}")
    public IMOOCJSONResult info(
            @ApiParam(name="itemId",value="商品id",required=true)
            @PathVariable String itemId){

        if(StringUtils.isEmpty(itemId))
            return IMOOCJSONResult.ok(null);

        Items items  = itemService.queryItemsById(itemId);
        List<ItemsImg> itemsImgList = itemService.queryItemsImgList(itemId);
        List<ItemsSpec> itemsSpecList = itemService.queryItemsSpecList(itemId);
        ItemsParam itemsParam = itemService.queryItemsParam(itemId);

        ItemInfoVO itemInfoVO = new ItemInfoVO();
        itemInfoVO.setItem(items);
        itemInfoVO.setItemImgList(itemsImgList);
        itemInfoVO.setItemSpecList(itemsSpecList);
        itemInfoVO.setItemParams(itemsParam);
        return IMOOCJSONResult.ok(itemInfoVO);
    }


    @ApiOperation(value="查询商品评价等级",notes="查询商品评价等级",httpMethod="GET")
    @GetMapping("/commentLevel")
    public IMOOCJSONResult commentLevel(
            @ApiParam(name="itemId",value="商品id",required = true)
            @RequestParam String itemId){

        if(StringUtils.isBlank(itemId)){
            return IMOOCJSONResult.errorMsg(null);
        }

        CommentsLevelCountsVO countsVO = itemService.queryCommentsCounts(itemId);

        return IMOOCJSONResult.ok(countsVO);
    }

    @ApiOperation(value="查询商品评论",notes="查询商品评论",httpMethod="GET")
    @GetMapping("/comments")
    public IMOOCJSONResult comments(
            @ApiParam(name="itemId",value="商品id",required=true)
            @RequestParam String itemId,
            @ApiParam(name="level",value="评价等级",required=false)
            @RequestParam Integer level,
            @ApiParam(name="page",value="查询下一页的第几页",required=false)
            @RequestParam Integer page,
            @ApiParam(name="pageSize",value="分页的每一页显示的条数",required=false)
            @RequestParam Integer pageSize){

        if(StringUtils.isBlank(itemId)){
            return IMOOCJSONResult.errorMsg(null);
        }

        if(page == null){
            page = 1;
        }

        if(pageSize == null){
            pageSize = COMMENT_PAGE_SIZE;
        }

        PagedGridResult grid = itemService.queryPagedComments(itemId,
                                                                level,
                                                                page,
                                                                pageSize);
        return IMOOCJSONResult.ok(grid);
    }

    @ApiOperation(value="搜索商品列表",notes="搜索商品列表",httpMethod="GET")
    @GetMapping("/search")
    public IMOOCJSONResult search(
            @ApiParam(name="keywords",value="关键字",required=true)
            @RequestParam String keywords,
            @ApiParam(name="sort",value="排序",required=false)
            @RequestParam String sort,
            @ApiParam(name="page",value="查询下一页的第几页",required=false)
            @RequestParam Integer page,
            @ApiParam(name="pageSize",value="分页的每一页显示的条数",required=false)
            @RequestParam Integer pageSize){

        if(StringUtils.isBlank(keywords)){
            return IMOOCJSONResult.errorMsg(null);
        }

        if(page == null){
            page = 1;
        }

        if(pageSize == null){
            pageSize = PAGE_SIZE;
        }

        PagedGridResult grid = itemService.searchItems(keywords,sort,page,pageSize);

        return IMOOCJSONResult.ok(grid);

    }

    @ApiOperation(value="通过分类id搜索商品列表",notes="通过分类id搜索商品列表",httpMethod="GET")
    @GetMapping("/catItems")
    public IMOOCJSONResult catItems(
            @ApiParam(name="catId",value="三级分类id",required=true)
            @RequestParam Integer catId,
            @ApiParam(name="sort",value="排序",required=false)
            @RequestParam String sort,
            @ApiParam(name="page",value="查询下一页的第几页",required=false)
            @RequestParam Integer page,
            @ApiParam(name="pageSize",value="分页的每一页显示的条数",required=false)
            @RequestParam Integer pageSize){

        if(catId == null){
            return IMOOCJSONResult.errorMsg(null);
        }

        if(page == null){
            page = 1;
        }

        if(pageSize == null){
            pageSize = PAGE_SIZE;
        }

        PagedGridResult grid = itemService.searchItems(catId,
                sort,
                page,
                pageSize);

        return IMOOCJSONResult.ok(grid);

    }

}
