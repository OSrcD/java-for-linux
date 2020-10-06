package com.imooc.controller;


import com.imooc.enums.YesOrNo;
import com.imooc.pojo.Carousel;
import com.imooc.service.CarouselService;
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

    @ApiOperation(value="获取首页轮播图列表",notes="获取首页轮播图列表",httpMethod="GET")
    @GetMapping("/carousel")
    public IMOOCJSONResult carousel(){
        List<Carousel> result = carouselService.queryAll(YesOrNo.YES.type);
        return IMOOCJSONResult.ok(result);
    }
}
