package com.imooc.controller;


import com.imooc.enums.YesOrNo;
import com.imooc.pojo.Carousel;
import com.imooc.pojo.Category;
import com.imooc.service.CarouselService;
import com.imooc.service.CategoryService;
import com.imooc.utils.IMOOCJSONResult;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@Api(value="首页",tags={"首页展示相关的接口"})
@RestController
@RequestMapping("/index")
public class IndexController {

    @Autowired
    private CarouselService carouselService;

    @Autowired
    private CategoryService categoryService;

    @ApiOperation(value="获取首页轮播图列表",notes="获取首页轮播图列表",httpMethod="GET")
    @GetMapping("/carousel")
    public IMOOCJSONResult carousel(){
        List<Carousel> result = carouselService.queryAll(YesOrNo.YES.type);
        return IMOOCJSONResult.ok(result);
    }

    /**
     * 首页分类展示需求:
     * 1. 第一次刷新主页查询大分类，渲染展现到首页
     * 2. 如果鼠标移到大分类，则加载其子分类的内容，如果已经存在子分类，则不需要加载（懒加载）
     */
    @ApiOperation(value="获取商品分类(一级分类)",notes="获取商品分类(一级分类)",httpMethod = "GET")
    @GetMapping("/cats")
    public IMOOCJSONResult cats() {
        List<Category> result = categoryService.queryAllRootLevelCat();
        return IMOOCJSONResult.ok(result);
    }
}
