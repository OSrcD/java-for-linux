

![](https://tcs.teambition.net/storage/3121f8495f69854b25c6352c78df4958f086?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjAyMywiaWF0IjoxNjEyMTkxMjIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmODQ5NWY2OTg1NGIyNWM2MzUyYzc4ZGY0OTU4ZjA4NiJ9.ruY-9jPrAvnJQKmBlEcv8tYHNr-YlnlYbtB3IZ_vIxY&download=2020-09-17%20052625.png "")

![](https://tcs.teambition.net/storage/31217a51ecafa7d717ef7ca2804180f44363?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjAyMywiaWF0IjoxNjEyMTkxMjIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3YTUxZWNhZmE3ZDcxN2VmN2NhMjgwNDE4MGY0NDM2MyJ9.ESFnC37C75a5A8aLzP3XZW5AQ_PnqXUYNltOhgvwyKU&download=%E6%9C%AA%E6%A0%87%E9%A2%98-1.png "")

![](https://tcs.teambition.net/storage/3121511740efd9801ae19ec9be32cb61f966?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjAyMywiaWF0IjoxNjEyMTkxMjIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1MTE3NDBlZmQ5ODAxYWUxOWVjOWJlMzJjYjYxZjk2NiJ9.YNJSyq_QgI3-iu1fE80-24Ijvd_if2Nlac34flirtwQ&download=2020-09-17%20053501.png "")

![](https://tcs.teambition.net/storage/31212bfbc73dc597090f3c7ae62193d6014a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjAyMywiaWF0IjoxNjEyMTkxMjIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyYmZiYzczZGM1OTcwOTBmM2M3YWU2MjE5M2Q2MDE0YSJ9.csXQuaPVo0i_pCPSQT5wId_WWK9FMB6yBCr2gIU5Xjo&download=image.png "")

![](https://tcs.teambition.net/storage/3121a31e2b0dcbe2669cd5cf79cf91692a54?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjAyMywiaWF0IjoxNjEyMTkxMjIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhMzFlMmIwZGNiZTI2NjljZDVjZjc5Y2Y5MTY5MmE1NCJ9.zVpWLiOKkWX71UnIjEgmVV-PmddO7ZfrE9WteirqUjw&download=image.png "")

```java
package com.imooc.cart.service;

import com.imooc.pojo.ShopcartBO;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

/**
 * Created by 半仙.
 */
@RequestMapping("cart-api")
public interface CartService {

    @PostMapping("addItem")
    public boolean addItemToCart(@RequestParam("userId") String userId,
                                 @RequestBody ShopcartBO shopcartBO);

    @PostMapping("removeItem")
    public boolean removeItemFromCart(@RequestParam("userId") String userId,
                                      @RequestParam("itemSpecId") String itemSpecId);

    @PostMapping("clearCart")
    public boolean clearCart(@RequestParam("userId") String userId);

}

```

![](https://tcs.teambition.net/storage/31214503bf61073e9a26fa7de08cd7f29ca6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjAyMywiaWF0IjoxNjEyMTkxMjIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0NTAzYmY2MTA3M2U5YTI2ZmE3ZGUwOGNkN2YyOWNhNiJ9.-yXfo36jeWha5iAv9FznRn6ZRlhpCWU30wFgrexBE6c&download=image.png "")

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

    <artifactId>foodie-cart-api</artifactId>

    <dependencies>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-cloud-shared-pojo</artifactId>
            <version>${project.version}</version>
        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-web</artifactId>
        </dependency>

        <!-- TODO Feign dependencies-->

    </dependencies>

</project>
```

![](https://tcs.teambition.net/storage/3121d9534db438ad016c9d073d655438bb68?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjAyMywiaWF0IjoxNjEyMTkxMjIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkOTUzNGRiNDM4YWQwMTZjOWQwNzNkNjU1NDM4YmI2OCJ9.j-H2iP7jXCiNp4D2LwVPA2-tYG018B3Q8y2hUworRNU&download=image.png "")

![](https://tcs.teambition.net/storage/3121b8cb5e0490727c07f3cd6e12bd7d08c7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjAyMywiaWF0IjoxNjEyMTkxMjIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiOGNiNWUwNDkwNzI3YzA3ZjNjZDZlMTJiZDdkMDhjNyJ9.s6OJ5994DhJv8mB35qyNuX5CF_5sU5Whyi1NPoPu_Pw&download=image.png "")

```java
package com.imooc.cart.service.impl;

import com.imooc.cart.service.CartService;
import com.imooc.pojo.ShopcartBO;
import com.imooc.utils.JsonUtils;
import com.imooc.utils.RedisOperator;
import lombok.extern.slf4j.Slf4j;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.ArrayList;
import java.util.List;

import static com.imooc.controller.BaseController.FOODIE_SHOPCART;

/**
 * Created by 半仙.
 */
@RestController
@Slf4j
public class CartServiceImpl implements CartService {

    @Autowired
    private RedisOperator redisOperator;

    @Override
    public boolean addItemToCart(@RequestParam("userId") String userId,
                                 @RequestBody ShopcartBO shopcartBO) {
        // 前端用户在登录的情况下，添加商品到购物车，会同时在后端同步购物车到redis缓存
        // 需要判断当前购物车中包含已经存在的商品，如果存在则累加购买数量
        String shopcartJson = redisOperator.get(FOODIE_SHOPCART + ":" + userId);
        List<ShopcartBO> shopcartList = null;
        if (StringUtils.isNotBlank(shopcartJson)) {
            // redis中已经有购物车了
            shopcartList = JsonUtils.jsonToList(shopcartJson, ShopcartBO.class);
            // 判断购物车中是否存在已有商品，如果有的话counts累加
            boolean isHaving = false;
            for (ShopcartBO sc: shopcartList) {
                String tmpSpecId = sc.getSpecId();
                if (tmpSpecId.equals(shopcartBO.getSpecId())) {
                    sc.setBuyCounts(sc.getBuyCounts() + shopcartBO.getBuyCounts());
                    isHaving = true;
                }
            }
            if (!isHaving) {
                shopcartList.add(shopcartBO);
            }
        } else {
            // redis中没有购物车
            shopcartList = new ArrayList<>();
            // 直接添加到购物车中
            shopcartList.add(shopcartBO);
        }

        // 覆盖现有redis中的购物车
        redisOperator.set(FOODIE_SHOPCART + ":" + userId, JsonUtils.objectToJson(shopcartList));

        return true;
    }

    @Override
    public boolean removeItemFromCart(@RequestParam("userId") String userId,
                                      @RequestParam("itemSpecId") String itemSpecId) {
        // 用户在页面删除购物车中的商品数据，如果此时用户已经登录，则需要同步删除redis购物车中的商品
        String shopcartJson = redisOperator.get(FOODIE_SHOPCART + ":" + userId);
        if (StringUtils.isNotBlank(shopcartJson)) {
            // redis中已经有购物车了
            List<ShopcartBO> shopcartList = JsonUtils.jsonToList(shopcartJson, ShopcartBO.class);
            // 判断购物车中是否存在已有商品，如果有的话则删除
            for (ShopcartBO sc: shopcartList) {
                String tmpSpecId = sc.getSpecId();
                if (tmpSpecId.equals(itemSpecId)) {
                    shopcartList.remove(sc);
                    break;
                }
            }
            // 覆盖现有redis中的购物车
            redisOperator.set(FOODIE_SHOPCART + ":" + userId, JsonUtils.objectToJson(shopcartList));
        }

        return true;
    }

    @Override
    public boolean clearCart(@RequestParam("userId") String userId) {
        redisOperator.del(FOODIE_SHOPCART + ":" + userId);
        return true;
    }
}

```

![](https://tcs.teambition.net/storage/31213c3daa4e3ae9bc6cf128f544951c2619?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjAyMywiaWF0IjoxNjEyMTkxMjIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzYzNkYWE0ZTNhZTliYzZjZjEyOGY1NDQ5NTFjMjYxOSJ9.q4iuLdS44-FWV5rrrDvNDxLP9b4BIkiGjlmocS8X0Rc&download=image.png "")

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

    <artifactId>foodie-cart-service</artifactId>

    <dependencies>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-cart-api</artifactId>
            <version>${project.version}</version>
        </dependency>

        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-cloud-common</artifactId>
            <version>${project.version}</version>
        </dependency>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-cloud-web-components</artifactId>
            <version>${project.version}</version>
        </dependency>
    </dependencies>

</project>
```

![](https://tcs.teambition.net/storage/31215de5f74f08a23578290af177ca656a03?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjAyMywiaWF0IjoxNjEyMTkxMjIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1ZGU1Zjc0ZjA4YTIzNTc4MjkwYWYxNzdjYTY1NmEwMyJ9.kELusdCL4jJpHAljd4uIKYzEGEwU0QVM2-Tx-4ML7K0&download=image.png "")

```java
package com.imooc.cart;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import org.springframework.context.annotation.ComponentScan;
import tk.mybatis.spring.annotation.MapperScan;

/**
 * Created by 半仙.
 */
@SpringBootApplication
// 扫描 mybatis 通用 mapper 所在的包
@MapperScan(basePackages = "com.imooc.cart.mapper")
// 扫描所有包以及相关组件包
@ComponentScan(basePackages = {"com.imooc", "org.n3r.idworker"})
@EnableDiscoveryClient
// TODO feign注解
public class CartApplication {

    public static void main(String[] args) {
        SpringApplication.run(CartApplication.class, args);
    }

}

```

![](https://tcs.teambition.net/storage/31218cefc6b10bb9aeae488ffc656bc0067e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjAyMywiaWF0IjoxNjEyMTkxMjIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4Y2VmYzZiMTBiYjlhZWFlNDg4ZmZjNjU2YmMwMDY3ZSJ9.9Y0nkLabAhF8T_tJjpDRKfUsDGCx-khCyn6DPsTyxm4&download=image.png "")

```java
package com.imooc.cart.controller;

import com.imooc.cart.service.CartService;
import com.imooc.controller.BaseController;
import com.imooc.pojo.ShopcartBO;
import com.imooc.pojo.IMOOCJSONResult;
import com.imooc.utils.JsonUtils;
import com.imooc.utils.RedisOperator;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.util.ArrayList;
import java.util.List;

@Api(value = "购物车接口controller", tags = {"购物车接口相关的api"})
@RequestMapping("shopcart")
@RestController
public class ShopcatController extends BaseController {

    @Autowired
    private RedisOperator redisOperator;

    @Autowired
    private CartService cartService;

    @ApiOperation(value = "添加商品到购物车", notes = "添加商品到购物车", httpMethod = "POST")
    @PostMapping("/add")
    public IMOOCJSONResult add(
            @RequestParam String userId,
            @RequestBody ShopcartBO shopcartBO,
            HttpServletRequest request,
            HttpServletResponse response
    ) {

        if (StringUtils.isBlank(userId)) {
            return IMOOCJSONResult.errorMsg("");
        }

        System.out.println(shopcartBO);

        cartService.addItemToCart(userId, shopcartBO);
        return IMOOCJSONResult.ok();
    }

    @ApiOperation(value = "从购物车中删除商品", notes = "从购物车中删除商品", httpMethod = "POST")
    @PostMapping("/del")
    public IMOOCJSONResult del(
            @RequestParam String userId,
            @RequestParam String itemSpecId,
            HttpServletRequest request,
            HttpServletResponse response
    ) {

        if (StringUtils.isBlank(userId) || StringUtils.isBlank(itemSpecId)) {
            return IMOOCJSONResult.errorMsg("参数不能为空");
        }

        cartService.removeItemFromCart(userId, itemSpecId);
        return IMOOCJSONResult.ok();
    }

    // TODO 1） 购物车清空功能
    //      2) 加减号 - 添加、减少商品数量
    //         +1 -1 -1 = 0  =>  -1 -1 +1 = 1 (问题： 如何保证前端请求顺序执行)

}

```

![](https://tcs.teambition.net/storage/3121571d155f302dcd9ac5edf6f7dde95beb?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjAyMywiaWF0IjoxNjEyMTkxMjIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1NzFkMTU1ZjMwMmRjZDlhYzVlZGY2ZjdkZGU5NWJlYiJ9.-Rw2xikLXh5WJ3YCzrnWjVNcdhZdhwR9eQtq-1M1cSw&download=image.png "")



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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjAyMywiaWF0IjoxNjEyMTkxMjIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.RFCwk22e1OR4J6ZH1zqdzYxLC2t4p08wakyQQyF1-V4&download=image.png "")

