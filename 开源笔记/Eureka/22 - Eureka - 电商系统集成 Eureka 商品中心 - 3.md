## 复制

![](https://tcs.teambition.net/storage/312187fdd2a0a9fb22651bfe0d4c85344dcb?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4N2ZkZDJhMGE5ZmIyMjY1MWJmZTBkNGM4NTM0NGRjYiJ9.eIFenBDDXxqXj6_nKpf7tTJ2cA494z72ns2T-R7iJl0&download=image.png "")

![](https://tcs.teambition.net/storage/3121d37b5df546995d4a5949633a42f33226?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkMzdiNWRmNTQ2OTk1ZDRhNTk0OTYzM2E0MmYzMzIyNiJ9.8cgcj1J-nDB5lU7QUHSgBPHDBmfv1Gm3CHHYdyWMzsA&download=image.png "")

```java
package com.imooc.item.service.impl;

import com.github.pagehelper.PageHelper;
import com.imooc.item.mapper.ItemsCommentsMapperCustom;
import com.imooc.item.pojo.vo.MyCommentVO;
import com.imooc.item.service.ItemCommentsService;
import com.imooc.pojo.PagedGridResult;
import com.imooc.service.BaseService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

@RestController
public class ItemCommentsServiceImpl extends BaseService implements ItemCommentsService {

    @Autowired
    private ItemsCommentsMapperCustom itemsCommentsMapperCustom;

    @Transactional(propagation = Propagation.SUPPORTS)
    @Override
    public PagedGridResult queryMyComments(@RequestParam("userId") String userId,
                                           @RequestParam(value = "page",required = false) Integer page,
                                           @RequestParam(value = "pageSize",required = false) Integer pageSize){
        Map<String, Object> map = new HashMap<>();
        map.put("userId",userId);
        PageHelper.startPage(page, pageSize);
        List<MyCommentVO> list = itemsCommentsMapperCustom.queryMyComments(map);
        return setterPagedGrid(list,page);
    }

    @Override
    public void saveComments(Map<String, Object> map) {

    }
}


```

![](https://tcs.teambition.net/storage/31211cda5bfd4532de5376d0f8c9aa9a8818?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExY2RhNWJmZDQ1MzJkZTUzNzZkMGY4YzlhYTlhODgxOCJ9.TV7s-MY-v2SDtX00qto_wrff3jS3iCNS4juqpITEnk0&download=image.png "")

```java
package com.imooc.item.service.impl;

import com.github.pagehelper.PageHelper;
import com.imooc.item.mapper.ItemsCommentsMapperCustom;
import com.imooc.item.pojo.vo.MyCommentVO;
import com.imooc.item.service.ItemCommentsService;
import com.imooc.pojo.PagedGridResult;
import com.imooc.service.BaseService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

@RestController
public class ItemCommentsServiceImpl extends BaseService implements ItemCommentsService {

    @Autowired
    private ItemsCommentsMapperCustom itemsCommentsMapperCustom;

    @Transactional(propagation = Propagation.SUPPORTS)
    @Override
    public PagedGridResult queryMyComments(@RequestParam("userId") String userId,
                                           @RequestParam(value = "page",required = false) Integer page,
                                           @RequestParam(value = "pageSize",required = false) Integer pageSize){
        Map<String, Object> map = new HashMap<>();
        map.put("userId",userId);
        PageHelper.startPage(page, pageSize);
        List<MyCommentVO> list = itemsCommentsMapperCustom.queryMyComments(map);
        return setterPagedGrid(list,page);
    }

    @Override
    public void saveComments(Map<String, Object> map) {
        itemsCommentsMapperCustom.saveComments(map);
    }
}


```

![](https://tcs.teambition.net/storage/3121dcab04160cb429afc4ea8fe0d0dd36de?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkY2FiMDQxNjBjYjQyOWFmYzRlYThmZTBkMGRkMzZkZSJ9.wIwtelDDaKtJY5-P_yVMUEp2s4pvm91LtjBrHmrN0_k&download=image.png "")

![](https://tcs.teambition.net/storage/312164f639cf524baabab663f7ecbcda272f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2NGY2MzljZjUyNGJhYWJhYjY2M2Y3ZWNiY2RhMjcyZiJ9.Qx9KhZjuH57aKiF3k9v1hg76x2PnyZBqZM-PsaTF4tw&download=image.png "")

![](https://tcs.teambition.net/storage/3121e1fdb1d3d2618f75be0d4be5f51fe1c6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlMWZkYjFkM2QyNjE4Zjc1YmUwZDRiZTVmNTFmZTFjNiJ9.XoiKAkk4DrP0ul4ZisZGUIkQI-UZyjkgJ-1mrRn0Xzk&download=image.png "")

```java
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <parent>
        <artifactId>foodie-cloud</artifactId>
        <groupId>com.imooc</groupId>
        <version>1.0-SNAPSHOT</version>
        <relativePath>../../../pom.xml</relativePath>
    </parent>
    <modelVersion>4.0.0</modelVersion>

    <artifactId>foodie-item-web</artifactId>

    <dependencies>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-item-service</artifactId>
            <version>${project.version}</version>
        </dependency>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-cloud-web-components</artifactId>
            <version>${project.version}</version>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-netflix-eureka-client</artifactId>
        </dependency>
    </dependencies>

    <build>
        <plugins>
            <plugin>
                <groupId>org.springframework.boot</groupId>
                <artifactId>spring-boot-maven-plugin</artifactId>
                <configuration>
                    <mainClass></mainClass>
                </configuration>
                <executions>
                    <execution>
                        <goals>
                            <goal>repackage</goal>
                        </goals>
                    </execution>
                </executions>
            </plugin>
        </plugins>
    </build>

</project>

```

## 复制

![](https://tcs.teambition.net/storage/31218926ee7531026810fe99cef35df8492f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4OTI2ZWU3NTMxMDI2ODEwZmU5OWNlZjM1ZGY4NDkyZiJ9.b0XdUmBsiqjFGUKQytvU9uhuCWNm_sgPC9Hd7VZdOZY&download=image.png "")

## 复制

![](https://tcs.teambition.net/storage/312187a35eab2097e76cd9e3ff22a6a328c5?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4N2EzNWVhYjIwOTdlNzZjZDllM2ZmMjJhNmEzMjhjNSJ9.fl6KFFUgNKsUb7rAGSDvieLOinHMfYax3pFZ0W6uhyA&download=image.png "")

![](https://tcs.teambition.net/storage/3121657ecdbc4a8e934709ae04c0c484f209?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2NTdlY2RiYzRhOGU5MzQ3MDlhZTA0YzBjNDg0ZjIwOSJ9.lFib0C8z0TlC6i3r7xr5RgndGUtXYR9faQXNJolSni4&download=image.png "")

![](https://tcs.teambition.net/storage/3121720819e9a026564afa11a9225619aa3d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3MjA4MTllOWEwMjY1NjRhZmExMWE5MjI1NjE5YWEzZCJ9.NyA_1vnSwzAvySsSUWD6JIdKHtdg6qbH2xlhZK7Uti0&download=image.png "")

```java
package com.imooc.item;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.autoconfigure.security.servlet.SecurityAutoConfiguration;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import org.springframework.context.annotation.ComponentScan;
import tk.mybatis.spring.annotation.MapperScan;

@SpringBootApplication(exclude = {SecurityAutoConfiguration.class})
// 扫描 mybatis 通用 mapper 所在的包
@MapperScan(basePackages="com.imooc.item.mapper")
// 扫描所有包以及相关组件包
@ComponentScan(basePackages={"com.imooc","org.n3r.idworker"})
@EnableDiscoveryClient
public class ItemApplication {
    public static void main(String[] args) {
        SpringApplication.run(ItemApplication.class, args);
    }
}


```

## 复制

![](https://tcs.teambition.net/storage/3121d34ddface154542761110c6e573947ea?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkMzRkZGZhY2UxNTQ1NDI3NjExMTBjNmU1NzM5NDdlYSJ9.rXeaDT4RlyoxtMT38KuQ1OPvPPPQuie_pY3VO6mJFMQ&download=image.png "")

![](https://tcs.teambition.net/storage/3121291664b71b2f22d23b970ad303f098fc?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyOTE2NjRiNzFiMmYyMmQyM2I5NzBhZDMwM2YwOThmYyJ9.9ckPnFAZeusNuamztC2D0F-Ze035u56c6lCrhC7OVcE&download=image.png "")

![](https://tcs.teambition.net/storage/3121aaef4f8bed5634aff5f2c5891f30d778?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhYWVmNGY4YmVkNTYzNGFmZjVmMmM1ODkxZjMwZDc3OCJ9.YHq-UhzNkDuxnluHjTEShS56qBUKmQUtOkQE_6GqjZ4&download=image.png "")

![](https://tcs.teambition.net/storage/31212f7966fd9f864c6a3989811c37bfeee2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyZjc5NjZmZDlmODY0YzZhMzk4OTgxMWMzN2JmZWVlMiJ9.dhOJSSuF1c_MRxpROqrbuGs9xEZGib2eS6hufA9qIrs&download=image.png "")

```java
package com.imooc.item.controller;

import com.imooc.controller.BaseController;
import com.imooc.item.pojo.Items;
import com.imooc.item.pojo.ItemsImg;
import com.imooc.item.pojo.ItemsParam;
import com.imooc.item.pojo.ItemsSpec;
import com.imooc.item.pojo.vo.CommentsLevelCountsVO;
import com.imooc.item.pojo.vo.ItemInfoVO;
import com.imooc.item.pojo.vo.ShopcartVO;
import com.imooc.item.service.ItemService;
import com.imooc.pojo.IMOOCJSONResult;
import com.imooc.pojo.PagedGridResult;
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
            pageSize = COMMON_PAGE_SIZE;
        }

        PagedGridResult grid = itemService.queryPagedComments(itemId,
                                                                level,
                                                                page,
                                                                pageSize);
        return IMOOCJSONResult.ok(grid);
    }

//    @ApiOperation(value="搜索商品列表",notes="搜索商品列表",httpMethod="GET")
//    @GetMapping("/search")
//    public IMOOCJSONResult search(
//            @ApiParam(name="keywords",value="关键字",required=true)
//            @RequestParam String keywords,
//            @ApiParam(name="sort",value="排序",required=false)
//            @RequestParam String sort,
//            @ApiParam(name="page",value="查询下一页的第几页",required=false)
//            @RequestParam Integer page,
//            @ApiParam(name="pageSize",value="分页的每一页显示的条数",required=false)
//            @RequestParam Integer pageSize){
//
//        if(StringUtils.isBlank(keywords)){
//            return IMOOCJSONResult.errorMsg(null);
//        }
//
//        if(page == null){
//            page = 1;
//        }
//
//        if(pageSize == null){
//            pageSize = PAGE_SIZE;
//        }
//
//        PagedGridResult grid = itemService.searchItems(keywords,sort,page,pageSize);
//
//        return IMOOCJSONResult.ok(grid);
//
//    }
//
//    @ApiOperation(value="通过分类id搜索商品列表",notes="通过分类id搜索商品列表",httpMethod="GET")
//    @GetMapping("/catItems")
//    public IMOOCJSONResult catItems(
//            @ApiParam(name="catId",value="三级分类id",required=true)
//            @RequestParam Integer catId,
//            @ApiParam(name="sort",value="排序",required=false)
//            @RequestParam String sort,
//            @ApiParam(name="page",value="查询下一页的第几页",required=false)
//            @RequestParam Integer page,
//            @ApiParam(name="pageSize",value="分页的每一页显示的条数",required=false)
//            @RequestParam Integer pageSize){
//
//        if(catId == null){
//            return IMOOCJSONResult.errorMsg(null);
//        }
//
//        if(page == null){
//            page = 1;
//        }
//
//        if(pageSize == null){
//            pageSize = PAGE_SIZE;
//        }
//
//        PagedGridResult grid = itemService.searchItems(catId,
//                sort,
//                page,
//                pageSize);
//
//        return IMOOCJSONResult.ok(grid);
//
//    }

    // 用于用户长时间未登陆网站，刷新购物车中的数据（主要是商品价格），类似京东淘宝
    @ApiOperation(value="根据商品规格ids查找最新的商品数据",notes="根据商品规格ids查找最新的商品数据",httpMethod="GET")
    @GetMapping("/refresh")
    public IMOOCJSONResult refresh(
            @ApiParam(name="itemSpecIds",value="拼接的规格ids",required=true,example="1001,1003,1005")
            @RequestParam String itemSpecIds){

        if(StringUtils.isBlank(itemSpecIds)){
            return IMOOCJSONResult.ok();
        }

        List<ShopcartVO> list = itemService.queryItemsBySpecIds(itemSpecIds);

        return IMOOCJSONResult.ok(list);
    }

}

```

## 复制

![](https://tcs.teambition.net/storage/31213ee5149e4ef1408e5af03f57bbee96be?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzZWU1MTQ5ZTRlZjE0MDhlNWFmMDNmNTdiYmVlOTZiZSJ9.YD-Q8p6PKGHGy9mLHqNvyFjzRBku9MHyy-mTK7ahF74&download=image.png "")

![](https://tcs.teambition.net/storage/312167168c485399631a7f191971ba332d26?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2NzE2OGM0ODUzOTk2MzFhN2YxOTE5NzFiYTMzMmQyNiJ9.Me5gKZeRKBXvsTAVyFPBPEodI_aeM675kl79OGvIQ9c&download=image.png "")

## 有些配置项 配置文件 有一定的加载顺序的 引入配置中心 要保证在服务启动先去拉取配置文件

## 要把配置中心 配置在Spring Boot yml中 如果我们同时要关注配置中心的高可用 哪就要把配置中心挂到 注册中心里 所以配置中心和注册中心都放在了同一个配置文件中

![](https://tcs.teambition.net/storage/31217d41ee82af5f8131ee1eff3d6e9ffbc4?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3ZDQxZWU4MmFmNWY4MTMxZWUxZWZmM2Q2ZTlmZmJjNCJ9.rnBUyk4I-GOPekO5Gan_oZ7ouZfoI5nWq9RABycgCxY&download=image.png "")

![](https://tcs.teambition.net/storage/31210343d5bb33151cecabd96169fc21fa12?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwMzQzZDViYjMzMTUxY2VjYWJkOTYxNjlmYzIxZmExMiJ9.51Tyiy4EJgWoh8du_UcSrj7-m58ZI9hGuZyWlrR2epg&download=image.png "")

```yaml
############################################################
#
# Eureka注册中心
#
############################################################
eureka:
  client:
    serviceUrl:
      defaultZone: http://localhost:20000/eureka/
```

![](https://tcs.teambition.net/storage/31215459554750511a270840d056de16b062?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1NDU5NTU0NzUwNTExYTI3MDg0MGQwNTZkZTE2YjA2MiJ9.ENjo1vMDAHgG9C1RKDKL3mtXagQ7eQHYvNEOWw6Ozy8&download=image.png "")

![](https://tcs.teambition.net/storage/3121373c5cf6fd25e965ca4faf2e01254829?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzNzNjNWNmNmZkMjVlOTY1Y2E0ZmFmMmUwMTI1NDgyOSJ9.K0MvCdolpjgACDP-d0LqP3Z0L3TVsZv2RSYt5yfZIR0&download=image.png "")

![](https://tcs.teambition.net/storage/31211bfdaa58d4efce7dd7faa3b3562b2daa?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExYmZkYWE1OGQ0ZWZjZTdkZDdmYWEzYjM1NjJiMmRhYSJ9.0jbX8i_ab91ac3elZkzyaL80hG87cvPWriD1bvI4jyo&download=image.png "")

```yaml
############################################################
#
# web访问端口号  约定：8088
#
############################################################
server:
#  port: 8088
  tomcat:
    uri-encoding: UTF-8
  max-http-header-size: 80KB

############################################################
#
# 配置数据源信息
# !!! 更改application name
#
############################################################
spring:
  application:
    name: foodie-item-service # 微服务在注册中心的名字
  profiles:
    active: dev
  datasource:                                           # 数据源的相关配置
    type: com.zaxxer.hikari.HikariDataSource          # 数据源类型：HikariCP
    driver-class-name: com.mysql.jdbc.Driver          # mysql驱动
#    url: jdbc:mysql://localhost:3306/foodie-shop-dev?useUnicode=true&characterEncoding=UTF-8&autoReconnect=true
    username: root
#    password: SocialPG
    hikari:
      connection-timeout: 30000       # 等待连接池分配连接的最大时长（毫秒），超过这个时长还没可用的连接则发生SQLException， 默认:30秒
      minimum-idle: 5                 # 最小连接数
      maximum-pool-size: 20           # 最大连接数
      auto-commit: true               # 自动提交
      idle-timeout: 600000            # 连接超时的最大时长（毫秒），超时则被释放（retired），默认:10分钟
      pool-name: DateSourceHikariCP   # 连接池名字
      max-lifetime: 1800000           # 连接的生命时长（毫秒），超时而且没被使用则被释放（retired），默认:30分钟 1800000ms
      connection-test-query: SELECT 1
  servlet:
    multipart:
      max-file-size: 512000      # 文件上传大小限制为500kb
      max-request-size: 512000  # 请求大小限制为500kb
#  session:
#    store-type: redis
############################################################
#
# mybatis 配置
# !!! 更改路径
#
############################################################
mybatis:
  type-aliases-package: com.imooc.item.pojo          # 所有POJO类所在包路径
  mapper-locations: classpath:mapper/*.xml      # mapper映射文件
#  configuration:
#    log-impl: org.apache.ibatis.logging.stdout.StdOutImpl
############################################################
#
# mybatis mapper 配置
#
############################################################
# 通用 Mapper 配置
mapper:
  mappers: com.imooc.my.mapper.MyMapper
  not-empty: false    # 在进行数据库操作的的时候，判断表达式 username != null, 是否追加 username != ''
  identity: MYSQL

# 分页插件配置
pagehelper:
  helperDialect: mysql
  supportMethodsArguments: true



  resources:
    static-locations: classpath:/static



```

![](https://tcs.teambition.net/storage/3121ae60fd63d47adadf6b6c14247651f859?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZTYwZmQ2M2Q0N2FkYWRmNmI2YzE0MjQ3NjUxZjg1OSJ9.vZBMQnHISQew8FMM7lEfoeCYiaqLTXNCesuLpK1MtEU&download=image.png "")

![](https://tcs.teambition.net/storage/3121653f3e36da837c3ca85ef008d1661b7e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2NTNmM2UzNmRhODM3YzNjYTg1ZWYwMDhkMTY2MWI3ZSJ9.jtJgFdRHy5VoS39kmJnwvCt8dU9hDVxpCE8cQyzddAg&download=image.png "")

```yaml
server:
  port: 10001

spring:
  datasource:                                           # 数据源的相关配置
    # 拆分数据源到独立database instance，或者独立schema
#    url: jdbc:mysql://localhost:3306/foodie-cloud-item?useUnicode=true&characterEncoding=UTF-8&autoReconnect=true
    url: jdbc:mysql://localhost:3306/foodie-shop-dev?useUnicode=true&characterEncoding=UTF-8&autoReconnect=true
    password: SocialPG
  redis:
    # Redis 单机单实例
    database: 0
    host: 192.168.245.138
    port: 6379
    password: imooc
    # Redis 哨兵模式
#    database: 1
#    password: imooc
#    sentinel:
#      master: imooc-master
#      nodes: 192.168.245.138:26379,192.168.245.139:26379,192.168.245.140:26379
#    password: imooc
#    cluster:
#      nodes: 192.168.245.141:6379,192.168.245.142:6379,192.168.245.143:6379,192.168.245.144:6379,192.168.245.145:6379,192.168.245.146:6379

mybatis:
  configuration:
    log-impl: org.apache.ibatis.logging.stdout.StdOutImpl
```

![](https://tcs.teambition.net/storage/3121829f6aedaf438127acc88bcb6bb2fb60?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4MjlmNmFlZGFmNDM4MTI3YWNjODhiY2I2YmIyZmI2MCJ9.bROyrELhf94ZRDy--mdjsV98etJw-cFPC7t29E29uQ8&download=image.png "")

```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <parent>
        <artifactId>foodie-cloud</artifactId>
        <groupId>com.imooc</groupId>
        <version>1.0-SNAPSHOT</version>
        <relativePath>../../../pom.xml</relativePath>
    </parent>
    <modelVersion>4.0.0</modelVersion>

    <artifactId>foodie-item-web</artifactId>

    <dependencies>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-item-service</artifactId>
            <version>${project.version}</version>
        </dependency>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-cloud-web-components</artifactId>
            <version>${project.version}</version>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-netflix-eureka-client</artifactId>
        </dependency>
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-commons</artifactId>
        </dependency>
        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-commons</artifactId>
        </dependency>
    </dependencies>

    <build>
        <plugins>
            <plugin>
                <groupId>org.springframework.boot</groupId>
                <artifactId>spring-boot-maven-plugin</artifactId>
                <configuration>
                    <mainClass>com.imooc.item.ItemApplication</mainClass>
                </configuration>
                <executions>
                    <execution>
                        <goals>
                            <goal>repackage</goal>
                        </goals>
                    </execution>
                </executions>
            </plugin>
        </plugins>
    </build>

</project>
```

## 启动

![](https://tcs.teambition.net/storage/312102f7ab942bef37e79b018e432f754197?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwMmY3YWI5NDJiZWYzN2U3OWIwMThlNDMyZjc1NDE5NyJ9.eewg8SMC8BUhWm06Sn4HBruekdo3eHt2V6BSC_hPYDY&download=image.png "")

![](https://tcs.teambition.net/storage/31211255daf6a5e550bc8ddb2d373975e6dc?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExMjU1ZGFmNmE1ZTU1MGJjOGRkYjJkMzczOTc1ZTZkYyJ9.EuowqDFTokNL_sKFbLpy-B2N9wIUnTUBakYCD0mBzLI&download=image.png "")

```java
package com.imooc.config;

import org.springframework.boot.web.client.RestTemplateBuilder;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.client.RestTemplate;
import org.springframework.web.servlet.config.annotation.InterceptorRegistry;
import org.springframework.web.servlet.config.annotation.ResourceHandlerRegistry;
import org.springframework.web.servlet.config.annotation.WebMvcConfigurer;

@Configuration
public class WebMvcConfig implements WebMvcConfigurer {

    // 实现静态资源的映射
    @Override
    public void addResourceHandlers(ResourceHandlerRegistry registry)  {
        registry.addResourceHandler("/**")
                .addResourceLocations("classpath:/META-INF/resources/") // 映射swagger2
//                .addResourceLocations("file:/workspaces/images/");  // 映射本地静态资源
                .addResourceLocations("file:/Users/virtualman/Downloads/temp/workspace/images/"); // 映射本地静态资源

    }

    @Bean
    public RestTemplate restTemplate(RestTemplateBuilder builder) {
        return builder.build();

    }

//    @Bean
//    public UserTokenInterceptor userTokenInterceptor() {
//        return new UserTokenInterceptor();
//    }

//    /**
//     * 注册拦截器
//     * @param registry
//     */
//    @Override
//    public void addInterceptors(InterceptorRegistry registry){
//
//        registry.addInterceptor(userTokenInterceptor())
//                .addPathPatterns("/hello")
//                .addPathPatterns("/shopcart/add")
//                .addPathPatterns("/shopcart/del")
//                .addPathPatterns("/address/list")
//                .addPathPatterns("/address/add")
//                .addPathPatterns("/address/update")
//                .addPathPatterns("/address/setDefault")
//                .addPathPatterns("/address/delete")
//                .addPathPatterns("/orders/*")
//                .addPathPatterns("/center/*")
//                .addPathPatterns("/userInfo/*")
//                .addPathPatterns("/myorders/*")
//                .addPathPatterns("/mycomments/*")
//                .excludePathPatterns("/myorders/deliver")
//                .excludePathPatterns("/orders/notifyMerchantOrderPaid");
//
//        WebMvcConfigurer.super.addInterceptors(registry);
//    }

}

```

## 启动

![](https://tcs.teambition.net/storage/31212f8b9f19419d1d591ed29cc20d2f8b53?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyZjhiOWYxOTQxOWQxZDU5MWVkMjljYzIwZDJmOGI1MyJ9.ZSz5rKU46bVDDQ80VXQDmyQDuQVsmg0hDQWgzGzPVbY&download=image.png "")

![](https://tcs.teambition.net/storage/3121034fdaa16debd470d2f3f7fb4f510d45?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwMzRmZGFhMTZkZWJkNDcwZDJmM2Y3ZmI0ZjUxMGQ0NSJ9.kjas2rN0axCYrbR7C-rUCBO0qthZJe-RUIEC_kKBeO8&download=image.png "")

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE mapper PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN" "http://mybatis.org/dtd/mybatis-3-mapper.dtd">
<mapper namespace="com.imooc.item.item.mapper.ItemsMapperCustom">
    <select id="queryItemComments" parameterType="Map" resultType="com.imooc.item.pojo.vo.ItemCommentVO">
        SELECT
            ic.comment_level as commentLevel,
            ic.content as content,
            ic.sepc_name as sepcName,
            ic.created_time as createdTime,
            u.face as userFace,
            u.nickname as nickname
        FROM
            items_comments ic
        LEFT JOIN
            users u
        ON
            ic.user_id = u.id
        WHERE
            ic.item_id = #{paramsMap.itemId}
        <if test=" paramsMap.level != null and paramsMap.level != '' ">
            AND ic.comment_level = #{paramsMap.level}
        </if>
    </select>

    <!--<select id="searchItems" parameterType="Map" resultType="com.imooc.item.item.pojo.vo.SearchItemsVO">
    SELECT
        i.id as itemId,
        i.item_name as itemName,
        i.sell_counts as sellCounts,
        ii.url as imgUrl,
        tempSpec.price_discount as price
    FROM
        items i
    LEFT JOIN
        items_img ii
    ON
        i.id = ii.item_id
    LEFT JOIN
        (SELECT item_id,MIN(price_discount) as price_discount FROM items_spec GROUP BY item_id) tempSpec
    ON
        i.id = tempSpec.item_id
    WHERE
        ii.is_main = 1
        <if test="paramsMap.keywords != null and paramsMap.keywords != ''">
            AND i.item_name like '%${paramsMap.keywords}%'
        </if>
        ORDER BY
        <choose>
            <when test="paramsMap.sort == &quot;c&quot;">
                i.sell_counts desc
            </when>

            <when test="paramsMap.sort == &quot;p&quot;">
                tempSpec.price_discount asc
            </when>
            <otherwise>
                i.item_name asc
            </otherwise>
        </choose>
    </select>
    &lt;!&ndash; k：默认，代表默认排序，根据name &ndash;&gt;
    &lt;!&ndash; c：根据销量排序 &ndash;&gt;
    &lt;!&ndash; p：根据价格排序 &ndash;&gt;

    <select id="searchItemsByThirdCat" parameterType="Map" resultType="com.imooc.item.item.pojo.vo.SearchItemsVO">
        SELECT
            i.id as itemId,
            i.item_name as itemName,
            i.sell_counts as sellCounts,
            ii.url as imgUrl,
            tempSpec.price_discount as price
        FROM
            items i
        LEFT JOIN
            items_img ii
        ON
            i.id = ii.item_id
        LEFT JOIN
            (SELECT item_id,MIN(price_discount) as price_discount FROM items_spec GROUP BY item_id) tempSpec
        ON
            i.id = tempSpec.item_id
        WHERE
            ii.is_main = 1
            AND
            i.cat_id = #{paramsMap.catId}
        ORDER BY
        <choose>
            <when test="paramsMap.sort == &quot;c&quot;">
                i.sell_counts desc
            </when>

            <when test="paramsMap.sort == &quot;p&quot;">
                tempSpec.price_discount asc
            </when>
            <otherwise>
                i.item_name asc
            </otherwise>
        </choose>
    </select>-->

    <select id="queryItemsBySpecIds" parameterType="List" resultType="com.imooc.item.item.pojo.vo.ShopcartVO">
        SELECT
            t_items.id as itemId,
            t_items.item_name as itemName,
            t_items_img.url as itemImgUrl,
            t_items_spec.id as specId,
            t_items_spec.`name` as specName,
            t_items_spec.price_discount as priceDiscount,
            t_items_spec.price_normal as priceNormal
        FROM
            items_spec t_items_spec
        LEFT JOIN
            items t_items
        ON
            t_items.id = t_items_spec.item_id
        LEFT JOIN
            items_img t_items_img
        ON
            t_items_img.item_id = t_items.id
        WHERE
            t_items_img.is_main = 1
            AND
                t_items_spec.id IN
                <foreach collection="paramsList" index="index" item="specId" open="(" separator="," close=")">
                    #{specId}
                </foreach>
    </select>

    <update id="decreaseItemSpecStock">

        update
            items_spec
        SET
            stock = stock - #{pendingCounts}
        WHERE
            id = #{specId}
        AND
            stock >= #{pendingCounts}
    </update>

</mapper>

```

![](https://tcs.teambition.net/storage/31210b601d7587ec23159fe38b48637d35fd?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwYjYwMWQ3NTg3ZWMyMzE1OWZlMzhiNDg2MzdkMzVmZCJ9.aghggF08SQKJ2VrNgvwcJqSkTlpCzUuUW5HDogC51es&download=image.png "")

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE mapper PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN" "http://mybatis.org/dtd/mybatis-3-mapper.dtd">
<mapper namespace="com.imooc.item.item.mapper.ItemsMapperCustom">
    <select id="queryItemComments" parameterType="Map" resultType="com.imooc.item.pojo.vo.ItemCommentVO">
        SELECT
            ic.comment_level as commentLevel,
            ic.content as content,
            ic.sepc_name as sepcName,
            ic.created_time as createdTime,
            u.face as userFace,
            u.nickname as nickname
        FROM
            items_comments ic
        LEFT JOIN
            users u
        ON
            ic.user_id = u.id
        WHERE
            ic.item_id = #{paramsMap.itemId}
        <if test=" paramsMap.level != null and paramsMap.level != '' ">
            AND ic.comment_level = #{paramsMap.level}
        </if>
    </select>

    <!--<select id="searchItems" parameterType="Map" resultType="com.imooc.item.item.pojo.vo.SearchItemsVO">
    SELECT
        i.id as itemId,
        i.item_name as itemName,
        i.sell_counts as sellCounts,
        ii.url as imgUrl,
        tempSpec.price_discount as price
    FROM
        items i
    LEFT JOIN
        items_img ii
    ON
        i.id = ii.item_id
    LEFT JOIN
        (SELECT item_id,MIN(price_discount) as price_discount FROM items_spec GROUP BY item_id) tempSpec
    ON
        i.id = tempSpec.item_id
    WHERE
        ii.is_main = 1
        <if test="paramsMap.keywords != null and paramsMap.keywords != ''">
            AND i.item_name like '%${paramsMap.keywords}%'
        </if>
        ORDER BY
        <choose>
            <when test="paramsMap.sort == &quot;c&quot;">
                i.sell_counts desc
            </when>

            <when test="paramsMap.sort == &quot;p&quot;">
                tempSpec.price_discount asc
            </when>
            <otherwise>
                i.item_name asc
            </otherwise>
        </choose>
    </select>
    &lt;!&ndash; k：默认，代表默认排序，根据name &ndash;&gt;
    &lt;!&ndash; c：根据销量排序 &ndash;&gt;
    &lt;!&ndash; p：根据价格排序 &ndash;&gt;

    <select id="searchItemsByThirdCat" parameterType="Map" resultType="com.imooc.item.item.pojo.vo.SearchItemsVO">
        SELECT
            i.id as itemId,
            i.item_name as itemName,
            i.sell_counts as sellCounts,
            ii.url as imgUrl,
            tempSpec.price_discount as price
        FROM
            items i
        LEFT JOIN
            items_img ii
        ON
            i.id = ii.item_id
        LEFT JOIN
            (SELECT item_id,MIN(price_discount) as price_discount FROM items_spec GROUP BY item_id) tempSpec
        ON
            i.id = tempSpec.item_id
        WHERE
            ii.is_main = 1
            AND
            i.cat_id = #{paramsMap.catId}
        ORDER BY
        <choose>
            <when test="paramsMap.sort == &quot;c&quot;">
                i.sell_counts desc
            </when>

            <when test="paramsMap.sort == &quot;p&quot;">
                tempSpec.price_discount asc
            </when>
            <otherwise>
                i.item_name asc
            </otherwise>
        </choose>
    </select>-->

    <select id="queryItemsBySpecIds" parameterType="List" resultType="com.imooc.item.pojo.vo.ShopcartVO">
        SELECT
            t_items.id as itemId,
            t_items.item_name as itemName,
            t_items_img.url as itemImgUrl,
            t_items_spec.id as specId,
            t_items_spec.`name` as specName,
            t_items_spec.price_discount as priceDiscount,
            t_items_spec.price_normal as priceNormal
        FROM
            items_spec t_items_spec
        LEFT JOIN
            items t_items
        ON
            t_items.id = t_items_spec.item_id
        LEFT JOIN
            items_img t_items_img
        ON
            t_items_img.item_id = t_items.id
        WHERE
            t_items_img.is_main = 1
            AND
                t_items_spec.id IN
                <foreach collection="paramsList" index="index" item="specId" open="(" separator="," close=")">
                    #{specId}
                </foreach>
    </select>

    <update id="decreaseItemSpecStock">

        update
            items_spec
        SET
            stock = stock - #{pendingCounts}
        WHERE
            id = #{specId}
        AND
            stock >= #{pendingCounts}
    </update>

</mapper>
```

![](https://tcs.teambition.net/storage/312170f7d15db6c5dae62233af17e07fa09f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3MGY3ZDE1ZGI2YzVkYWU2MjIzM2FmMTdlMDdmYTA5ZiJ9.R-QIA2JwdOHPZpoXKXqaHC5t1GS5JNIS6Wcefuede4s&download=image.png "")

![](https://tcs.teambition.net/storage/3121a5d84a2dfe48efa89fde731f85c51029?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhNWQ4NGEyZGZlNDhlZmE4OWZkZTczMWY4NWM1MTAyOSJ9.h_trB0_d0ujxASt3QO9pRle3EC6FIRp8K0KnDEABYJk&download=image.png "")

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE mapper PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN" "http://mybatis.org/dtd/mybatis-3-mapper.dtd">
<mapper namespace="com.imooc.item.mapper.ItemsSpecMapper">
  <resultMap id="BaseResultMap" type="com.imooc.item.pojo.ItemsSpec">
    <!--
      WARNING - @mbg.generated
    -->
    <id column="id" jdbcType="VARCHAR" property="id" />
    <result column="item_id" jdbcType="VARCHAR" property="itemId" />
    <result column="name" jdbcType="VARCHAR" property="name" />
    <result column="stock" jdbcType="INTEGER" property="stock" />
    <result column="discounts" jdbcType="DECIMAL" property="discounts" />
    <result column="price_discount" jdbcType="INTEGER" property="priceDiscount" />
    <result column="price_normal" jdbcType="INTEGER" property="priceNormal" />
    <result column="created_time" jdbcType="TIMESTAMP" property="createdTime" />
    <result column="updated_time" jdbcType="TIMESTAMP" property="updatedTime" />
  </resultMap>
</mapper>
```

![](https://tcs.teambition.net/storage/3121fc5c12945476f32de847bbbd1552ba6e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmYzVjMTI5NDU0NzZmMzJkZTg0N2JiYmQxNTUyYmE2ZSJ9.bUHqTjNttPc5MNb2EIvm3mMeKbm2eoWPXZmbsq2WP-k&download=image.png "")

![](https://tcs.teambition.net/storage/3121ad5fd83b9da501a20effe30b703e36c7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZDVmZDgzYjlkYTUwMWEyMGVmZmUzMGI3MDNlMzZjNyJ9.o4f7mRpDc0KdioEtJto0ZiXHNaOGsh5ABJPNcW6UdFM&download=image.png "")

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE mapper PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN" "http://mybatis.org/dtd/mybatis-3-mapper.dtd">
<mapper namespace="com.imooc.item.mapper.ItemsMapperCustom">
    <select id="queryItemComments" parameterType="Map" resultType="com.imooc.item.pojo.vo.ItemCommentVO">
        SELECT
            ic.comment_level as commentLevel,
            ic.content as content,
            ic.sepc_name as sepcName,
            ic.created_time as createdTime,
            u.face as userFace,
            u.nickname as nickname
        FROM
            items_comments ic
        LEFT JOIN
            users u
        ON
            ic.user_id = u.id
        WHERE
            ic.item_id = #{paramsMap.itemId}
        <if test=" paramsMap.level != null and paramsMap.level != '' ">
            AND ic.comment_level = #{paramsMap.level}
        </if>
    </select>

    <!--<select id="searchItems" parameterType="Map" resultType="com.imooc.item.pojo.vo.SearchItemsVO">
    SELECT
        i.id as itemId,
        i.item_name as itemName,
        i.sell_counts as sellCounts,
        ii.url as imgUrl,
        tempSpec.price_discount as price
    FROM
        items i
    LEFT JOIN
        items_img ii
    ON
        i.id = ii.item_id
    LEFT JOIN
        (SELECT item_id,MIN(price_discount) as price_discount FROM items_spec GROUP BY item_id) tempSpec
    ON
        i.id = tempSpec.item_id
    WHERE
        ii.is_main = 1
        <if test="paramsMap.keywords != null and paramsMap.keywords != ''">
            AND i.item_name like '%${paramsMap.keywords}%'
        </if>
        ORDER BY
        <choose>
            <when test="paramsMap.sort == &quot;c&quot;">
                i.sell_counts desc
            </when>

            <when test="paramsMap.sort == &quot;p&quot;">
                tempSpec.price_discount asc
            </when>
            <otherwise>
                i.item_name asc
            </otherwise>
        </choose>
    </select>
    &lt;!&ndash; k：默认，代表默认排序，根据name &ndash;&gt;
    &lt;!&ndash; c：根据销量排序 &ndash;&gt;
    &lt;!&ndash; p：根据价格排序 &ndash;&gt;

    <select id="searchItemsByThirdCat" parameterType="Map" resultType="com.imooc.item.pojo.vo.SearchItemsVO">
        SELECT
            i.id as itemId,
            i.item_name as itemName,
            i.sell_counts as sellCounts,
            ii.url as imgUrl,
            tempSpec.price_discount as price
        FROM
            items i
        LEFT JOIN
            items_img ii
        ON
            i.id = ii.item_id
        LEFT JOIN
            (SELECT item_id,MIN(price_discount) as price_discount FROM items_spec GROUP BY item_id) tempSpec
        ON
            i.id = tempSpec.item_id
        WHERE
            ii.is_main = 1
            AND
            i.cat_id = #{paramsMap.catId}
        ORDER BY
        <choose>
            <when test="paramsMap.sort == &quot;c&quot;">
                i.sell_counts desc
            </when>

            <when test="paramsMap.sort == &quot;p&quot;">
                tempSpec.price_discount asc
            </when>
            <otherwise>
                i.item_name asc
            </otherwise>
        </choose>
    </select>-->

    <select id="queryItemsBySpecIds" parameterType="List" resultType="com.imooc.item.pojo.vo.ShopcartVO">
        SELECT
            t_items.id as itemId,
            t_items.item_name as itemName,
            t_items_img.url as itemImgUrl,
            t_items_spec.id as specId,
            t_items_spec.`name` as specName,
            t_items_spec.price_discount as priceDiscount,
            t_items_spec.price_normal as priceNormal
        FROM
            items_spec t_items_spec
        LEFT JOIN
            items t_items
        ON
            t_items.id = t_items_spec.item_id
        LEFT JOIN
            items_img t_items_img
        ON
            t_items_img.item_id = t_items.id
        WHERE
            t_items_img.is_main = 1
            AND
                t_items_spec.id IN
                <foreach collection="paramsList" index="index" item="specId" open="(" separator="," close=")">
                    #{specId}
                </foreach>
    </select>

    <update id="decreaseItemSpecStock">

        update
            items_spec
        SET
            stock = stock - #{pendingCounts}
        WHERE
            id = #{specId}
        AND
            stock >= #{pendingCounts}
    </update>

</mapper>
```

![](https://tcs.teambition.net/storage/312107688b2bf448fbdd6787126016cb5993?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwNzY4OGIyYmY0NDhmYmRkNjc4NzEyNjAxNmNiNTk5MyJ9._vo5haWa7MgTIqfbRNB4FUYm-22KUxOHHbPsD-hvS0k&download=image.png "")

![](https://tcs.teambition.net/storage/3121043c501bac51368444d4cd9b3bcbdcbd?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwNDNjNTAxYmFjNTEzNjg0NDRkNGNkOWIzYmNiZGNiZCJ9.VhnAlKBceYMVajmBgCq_743Vs0ANnC1QlNZO4azyMds&download=image.png "")

```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <parent>
        <artifactId>foodie-cloud</artifactId>
        <groupId>com.imooc</groupId>
        <version>1.0-SNAPSHOT</version>
        <relativePath>../../../pom.xml</relativePath>
    </parent>
    <modelVersion>4.0.0</modelVersion>

    <artifactId>foodie-item-web</artifactId>

    <dependencies>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-item-service</artifactId>
            <version>${project.version}</version>
        </dependency>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-cloud-web-components</artifactId>
            <version>${project.version}</version>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-netflix-eureka-client</artifactId>
        </dependency>

    </dependencies>

    <build>
        <plugins>
            <plugin>
                <groupId>org.springframework.boot</groupId>
                <artifactId>spring-boot-maven-plugin</artifactId>
                <configuration>
                    <mainClass>com.imooc.item.ItemApplication</mainClass>
                </configuration>
                <executions>
                    <execution>
                        <goals>
                            <goal>repackage</goal>
                        </goals>
                    </execution>
                </executions>
            </plugin>
        </plugins>
    </build>

</project>
```

![](https://tcs.teambition.net/storage/3121626c69730634e2b99885030d47410398?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2MjZjNjk3MzA2MzRlMmI5OTg4NTAzMGQ0NzQxMDM5OCJ9.k0cnw3jx9DP3f5GqUFPreZAgaXdSx64bKQyN-bQM9Vw&download=image.png "")

![](https://tcs.teambition.net/storage/312195b2ec22836a39223cf3d59024539b69?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5NWIyZWMyMjgzNmEzOTIyM2NmM2Q1OTAyNDUzOWI2OSJ9.F3eSnjAC9PmIHp2y-ZZEY5gvtwuYwZBuLpurlOA_RsU&download=image.png "")

![](https://tcs.teambition.net/storage/3121336c8e7207d4d968076240dfbbfa6f97?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzMzZjOGU3MjA3ZDRkOTY4MDc2MjQwZGZiYmZhNmY5NyJ9.8vZIrF4eQNTanf2FBUyfoPwgXea3birpGwe4Ej5A87E&download=image.png "")

![](https://tcs.teambition.net/storage/3121145cd7fbfcb191222acec825b14c2b20?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExNDVjZDdmYmZjYjE5MTIyMmFjZWM4MjViMTRjMmIyMCJ9.8HPqHez754HeFIFeRDGy5l87Cg-5_B0Uha5qXPCteUM&download=image.png "")

## 从页面向后台发起指令会失败   没有网关



开源笔记

可 Pull Requests 协作写开源笔记

gitee

[https://gitee.com/opendevel/java-for-linux](https://gitee.com/opendevel/java-for-linux)

github

[https://github.com/OSrcD/java-for-linux](https://github.com/OSrcD/java-for-linux)

teambition

[https://tburl.in/0jDNvpbK](https://tburl.in/0jDNvpbK)

开源视频

bilibili

[https://space.bilibili.com/77266754](https://space.bilibili.com/77266754)

开源博客

oschina

[https://my.oschina.net/u/4675154](https://my.oschina.net/u/4675154)

csdn

[https://blog.csdn.net/OpenDevel](https://blog.csdn.net/OpenDevel)

开源项目

gitee

[https://gitee.com/opendevel](https://gitee.com/opendevel)

github

[https://github.com/OSrcD](https://github.com/OSrcD)

开源赞赏

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjM0NywiaWF0IjoxNjEyMTkxNTQ3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.7xaqFCYCKKvNMwJ395VrYKH0t7ObLAI9reXplW-fclA&download=image.png "")

