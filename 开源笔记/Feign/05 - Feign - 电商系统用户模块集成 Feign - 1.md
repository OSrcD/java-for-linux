![](https://tcs.teambition.net/storage/31211d06b1e7f22c40b79f2ad9f5dfac7960?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExZDA2YjFlN2YyMmM0MGI3OWYyYWQ5ZjVkZmFjNzk2MCJ9.nKDtV4G9BJESZznXAYXF_u5z8HLbNEUjBUq-ZfZnoFY&download=image.png "")

![](https://tcs.teambition.net/storage/3121617ce11dac0f5bbd6b0a7bdf39991038?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2MTdjZTExZGFjMGY1YmJkNmIwYTdiZGYzOTk5MTAzOCJ9.BhsrqyNs5KwKgsL6S6CZoLcN2v246xgjLxsVRtGOkUg&download=image.png "")

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

    <artifactId>foodie-user-api</artifactId>

    <dependencies>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-cloud-shared-pojo</artifactId>
            <version>${project.version}</version>
        </dependency>

        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-user-pojo</artifactId>
            <version>${project.version}</version>
        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-web</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-openfeign</artifactId>
        </dependency>

    </dependencies>

</project>
```





service层也可以加上GetMapping给PostMan调用 如果用上了FeignClient 又用上了GetMapping 会在FeignClient 指定的ServerName 的Controller（寻找方法名一样的就可以 不一定要Controller）里寻找Service层定义的GetMapping映射 属性名 一致的方法名 

供其他微服务调用需要写成RestController

这个Controller跟实现它Service没有什么关系 只是一种规范规定一致 方便各个团队之间调用



![](https://tcs.teambition.net/storage/312180f3358bc79a6f05e2cf59b2a1b5c3cc?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4MGYzMzU4YmM3OWE2ZjA1ZTJjZjU5YjJhMWI1YzNjYyJ9.xGxNDtkzJ1uYC-eeKPE9zehIw1_60tKTYWi_3khRl_o&download=image.png "")

```java
package com.imooc.user.service;

import com.imooc.user.pojo.Users;
import com.imooc.user.pojo.bo.UserBO;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.*;

@FeignClient("foodie-user-service")
@RequestMapping("user-api")
public interface UserService {

    /**
     * 判断用户名是否存在
     * @param username
     * @return
     */
    @GetMapping("user/exists")
    boolean queryUsernameIsExist(@RequestParam("username") String username);

    /**
     * 创建用户
     * @param userBo
     * @return
     */
    @PostMapping("user")
    Users createUser(@RequestBody UserBO userBo);

    /**
     * 检索用户名和密码是否匹配，用于登录
     */
    @GetMapping("verify")
    Users queryUserForLogin(@RequestParam("username") String username,
                            @RequestParam("password") String password);
}

```





![](https://tcs.teambition.net/storage/31210047adae272d355c0af1894969258401?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwMDQ3YWRhZTI3MmQzNTVjMGFmMTg5NDk2OTI1ODQwMSJ9.F-CnSG30rEiiwY2z_Blecm1_eQ2gBFGMyC5G6QxMVwY&download=image.png "")

```java
package com.imooc.user.service;

import com.imooc.user.pojo.UserAddress;
import com.imooc.user.pojo.bo.AddressBO;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@FeignClient("foodie-user-service")
@RequestMapping("address-api")
public interface AddressService {

    /**
     * 根据用户id查询用户的收货地址列表
     * @param userId
     * @return
     */
    @GetMapping("addressList")
    List<UserAddress> queryAll(@RequestParam("userId") String userId);

    /**
     * 用户新增地址
     * @param addressBO
     */
    @PostMapping("address")
    void addNewUserAddress(@RequestBody AddressBO addressBO);

    /**
     * 用户修改地址
     * @param addressBO
     */
    @PutMapping("address")
    void updateUserAddress(@RequestBody AddressBO addressBO);

    /**
     * 根据用户id和地址id，删除对应的用户地址信息
     * @param userId
     * @param addressId
     */
    @DeleteMapping("address")
    void deleteUserAddress(@RequestParam("userId") String userId,
                           @RequestParam("addressId") String addressId);

    /**
     * 修改默认地址
     * @param userId
     * @param addressId
     */
    @PostMapping("setDefaultAddress")
    void updateUserAddressToBeDefault(@RequestParam("userId") String userId,
                                      @RequestParam("addressId") String addressId);


    /**
     * 根据用户id和地址id，查询具体的用户地址对象信息
     * @param userId
     * @param addressId
     * @return
     */
    @GetMapping("queryAddress")
    UserAddress queryUserAddress(@RequestParam("userId") String userId,
                                 @RequestParam(value = "addressId", required = false) String addressId);

}

```



![](https://tcs.teambition.net/storage/3121726d82187dd860d1a4c8b8c07e69113c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3MjZkODIxODdkZDg2MGQxYTRjOGI4YzA3ZTY5MTEzYyJ9.ZvJmWla9uN6RdUtKkozAKzcV5uwsXcN3jt_p2WwYJws&download=image.png "")

```java
package com.imooc.user.service.center;

import com.imooc.user.pojo.Users;
import com.imooc.user.pojo.bo.center.CenterUserBO;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.*;

@FeignClient("foodie-user-service")
@RequestMapping("center-user-api")
public interface CenterUserService {

    /**
     * 根据用户id查询用户信息
     * @param userId
     * @return
     */
    @GetMapping("profile")
    Users queryUserInfo(@RequestParam("userId") String userId);

    /**
     * 修改用户信息
     * @param userId
     * @param centerUserBO
     * @return
     */
    @PutMapping("profile/{userId}")
    Users updateUserInfo(@PathVariable("userId") String userId,
                         @RequestBody CenterUserBO centerUserBO);


    /**
     * 用户头像更新
     * @param userId
     * @param faceUrl
     * @return
     */
    @PostMapping("updatePhoto")
    Users updateUserFaceUrl(@RequestParam("userId") String userId,
                            @RequestParam("faceUrl") String faceUrl);

}

```



![](https://tcs.teambition.net/storage/3121fb856c3263a751cbed6d2c6026c51597?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmYjg1NmMzMjYzYTc1MWNiZWQ2ZDJjNjAyNmM1MTU5NyJ9.720OgEp9CbV6Cmw6cUgphSUYpLrLaDvdXRa6yuicxXA&download=image.png "")

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
    name: foodie-user-service # 微服务在注册中心的名字
  ### Feign - 当 Bean 名字一样的时候，允许覆盖注册
  main:
    allow-bean-definition-overriding: true
  profiles:
    active: dev
  datasource:                                           # 数据源的相关配置
    type: com.zaxxer.hikari.HikariDataSource          # 数据源类型：HikariCP
    driver-class-name: com.mysql.jdbc.Driver          # mysql驱动
#    url: jdbc:mysql://localhost:3306/foodie-shop-dev?useUnicode=true&characterEncoding=UTF-8&autoReconnect=true
    username: root
#    password: opendevel
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
  type-aliases-package: com.imooc.user.pojo          # 所有POJO类所在包路径
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



#  resources:
#    static-locations: classpath:/static



```



![](https://tcs.teambition.net/storage/3121b3991e2153595077d1d98e2a98d6dffa?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiMzk5MWUyMTUzNTk1MDc3ZDFkOThlMmE5OGQ2ZGZmYSJ9.YF-37JBxKSP24EbQJjo9ONM5Y2EpwA9iohVhBifdAMk&download=image.png "")

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

    <artifactId>foodie-item-api</artifactId>

    <dependencies>

        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-cloud-shared-pojo</artifactId>
            <version>${project.version}</version>
        </dependency>

        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-item-pojo</artifactId>
            <version>${project.version}</version>
        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-web</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-openfeign</artifactId>
        </dependency>

    </dependencies>

</project>
```



![](https://tcs.teambition.net/storage/31212d585784cf2600c18c2a22ae6d116ff0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyZDU4NTc4NGNmMjYwMGMxOGMyYTIyYWU2ZDExNmZmMCJ9.uBPz2KzGQXVccIGdSuktPg3eBwx7q3O7aExo-gGDVa8&download=image.png "")

```java
package com.imooc.item.service;

import com.imooc.item.pojo.Items;
import com.imooc.item.pojo.ItemsImg;
import com.imooc.item.pojo.ItemsParam;
import com.imooc.item.pojo.ItemsSpec;
import com.imooc.item.pojo.vo.CommentsLevelCountsVO;
import com.imooc.item.pojo.vo.ShopcartVO;
import com.imooc.pojo.PagedGridResult;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import java.util.List;

@FeignClient("foodie-item-service")
@RequestMapping("item-api")
public interface ItemService {

    /**
     * 根据商品id查询详情
     * @param itemId
     * @return
     */
    @GetMapping("item") Items queryItemsById(@RequestParam("itemId") String itemId);

    /**
     * 根据商品id查询商品图片列表
     * @param itemId
     * @return
     */
    @GetMapping("itemImages") List<ItemsImg> queryItemsImgList(@RequestParam("itemId") String itemId);

    /**
     * 根据商品id查询商品规格
     * @param itemId
     * @return
     */
    @GetMapping("itemSpecs") List<ItemsSpec> queryItemsSpecList(@RequestParam("itemId") String itemId);

    /**
     * 根据商品id查询商品参数
     * @param itemId
     * @return
     */
    @GetMapping("itemParam") ItemsParam queryItemsParam(@RequestParam("itemId") String itemId);


    /**
     * 根据商品id查询商品的评价等级数量
     * @param itemId
     * @return
     */
    @GetMapping("countComments") CommentsLevelCountsVO queryCommentsCounts(@RequestParam("itemId") String itemId);

    /**
     * 根据商品id查询商品的评价（分页）
     * @param itemId
     * @param level
     * @return
     */
    @GetMapping("pagedComments") PagedGridResult queryPagedComments(@RequestParam("itemId") String itemId,
                                              @RequestParam(value = "level",required=false) Integer level,
                                              @RequestParam(value = "page",required=false) Integer page,
                                              @RequestParam(value = "pageSize",required = false) Integer pageSize);

//    /**
//     * 搜索商品列表
//     * @param keywords
//     * @param sort
//     * @param page
//     * @param pageSize
//     * @return
//     */
//
//    public PagedGridResult searchItems(String keywords,String sort,
//                                       Integer page,Integer pageSize);
//
//    /**
//     * 根据分类Id搜索商品列表
//     * @param catId
//     * @param sort
//     * @param page
//     * @param pageSize
//     * @return
//     */
//    public PagedGridResult searchItems(Integer catId,String sort,
//                                       Integer page,Integer pageSize);

    /**
     * 根据规格ids查询最新的购物车中商品数据（用于刷新渲染购物车的商品数据）
     * @param specIds
     * @return
     */
    @GetMapping("getCartBySpecIds") List<ShopcartVO> queryItemsBySpecIds(@RequestParam("specIds") String specIds);

    /**
     * 根据商品规格id获取规格对象的具体信息
     * @param specId
     * @return
     */
    @GetMapping("singleItemSpec") ItemsSpec queryItemsSpecById(@RequestParam("specId") String specId);

    /**
     * 根据商品id获得商品图片主图url
     * @param itemId
     * @return
     */
    @GetMapping("primaryImage") String queryItemMainImgById(@RequestParam("itemId") String itemId);

    /**
     * 减少库存
     * @param specId
     * @param buyCounts
     */
    @PostMapping("decreaseStock") void decreaseItemSpecStock(@RequestParam("specId") String specId,
                                      @RequestParam("buyCounts") int buyCounts);

}

```



![](https://tcs.teambition.net/storage/31218b3d8aac83cb627685fe96dcfe635572?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4YjNkOGFhYzgzY2I2Mjc2ODVmZTk2ZGNmZTYzNTU3MiJ9.Zz9FvnvKPxGABLTC3KjyMFipNOQuah64Pa2Vk6BSO9s&download=image.png "")

```java
package com.imooc.item.service;

import com.imooc.pojo.PagedGridResult;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.*;

import java.util.Map;
@FeignClient("foodie-item-service")
@RequestMapping("item-comments-api")
public interface ItemCommentsService {


    /**
     * 我的评价查询 分页
     * @param userId
     * @param page
     * @param pageSize
     * @return
     */
    @GetMapping("myComments") PagedGridResult queryMyComments(@RequestParam("userId") String userId,
                                           @RequestParam(value = "page",required = false) Integer page,
                                           @RequestParam(value = "pageSize",required = false) Integer pageSize);

    /**
     * 会被订单中心调用
     * 看订单中心的源代码
     * @param map
     */
    @PostMapping("saveComments") void saveComments(@RequestBody Map<String, Object> map);
}

```



![](https://tcs.teambition.net/storage/312145189157456c870997c512f5d9591073?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0NTE4OTE1NzQ1NmM4NzA5OTdjNTEyZjVkOTU5MTA3MyJ9.Og9v_tKzz6rLrqtfz2CA6DnWMftRisKEydyZh_nFkJk&download=image.png "")

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
  main:
    allow-bean-definition-overriding: true
  profiles:
    active: dev
  datasource:                                           # 数据源的相关配置
    type: com.zaxxer.hikari.HikariDataSource          # 数据源类型：HikariCP
    driver-class-name: com.mysql.jdbc.Driver          # mysql驱动
#    url: jdbc:mysql://localhost:3306/foodie-shop-dev?useUnicode=true&characterEncoding=UTF-8&autoReconnect=true
    username: root
#    password: opendevel
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



#  resources:
#    static-locations: classpath:/static



```



![](https://tcs.teambition.net/storage/3121a141dd07a8919f59938b91d086cab935?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhMTQxZGQwN2E4OTE5ZjU5OTM4YjkxZDA4NmNhYjkzNSJ9.kftmOTnt6lSnDJ7PvuSMNxO_P0r4MXIHHTSdl4Xa8oY&download=image.png "")

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

    <artifactId>foodie-order-api</artifactId>

    <dependencies>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-cloud-shared-pojo</artifactId>
            <version>${project.version}</version>
        </dependency>

        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-order-pojo</artifactId>
            <version>${project.version}</version>
        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-web</artifactId>
        </dependency>

        <dependency>
            <groupId>org.springframework.cloud</groupId>
            <artifactId>spring-cloud-starter-openfeign</artifactId>
        </dependency>
    </dependencies>

</project>
```



![](https://tcs.teambition.net/storage/3121fa04d2235a0764a97d8c49993ed84dd6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmYTA0ZDIyMzVhMDc2NGE5N2Q4YzQ5OTkzZWQ4NGRkNiJ9.lxlQJum356ScqCoMBJlWKoCiQcNUgBpK5I2J6-5Vlak&download=image.png "")

```java
package com.imooc.order.service.center;

import com.imooc.order.pojo.OrderItems;
import com.imooc.order.pojo.bo.center.OrderItemsCommentBO;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@FeignClient("foodie-order-service")
@RequestMapping("order-comments-api")
public interface MyCommentsService {

    /**
     * 根据订单id查询关联的商品
     * @param orderId
     * @return
     */
    @GetMapping("orderItems") List<OrderItems> queryPendingComment(@RequestParam("orderId") String orderId);

    /**
     * 保存用户的评论
     * @param orderId
     * @param userId
     * @param commentList
     */
    @PostMapping("saveOrderComments") void saveComments(@RequestParam("orderId") String orderId,
                             @RequestParam("userId") String userId,
                             @RequestBody List<OrderItemsCommentBO> commentList);


    // TODO 移到了itemCommentsService里
//    /**
//     * 我的评价查询 分页
//     * @param userId
//     * @param page
//     * @param pageSize
//     * @return
//     */
//    public PagedGridResult queryMyComments(String userId, Integer page, Integer pageSize);
}

```





![](https://tcs.teambition.net/storage/31211faf37fae23b767d5efad21140025c0c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExZmFmMzdmYWUyM2I3NjdkNWVmYWQyMTE0MDAyNWMwYyJ9.ldVSFrxw9a_sIHOSr6791n7_OWFTd7TenaBYQCbxjws&download=image.png "")

```java
package com.imooc.order.service.center;


import com.imooc.order.pojo.Orders;
import com.imooc.order.pojo.vo.OrderStatusCountsVO;
import com.imooc.pojo.IMOOCJSONResult;
import com.imooc.pojo.PagedGridResult;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.*;

@FeignClient("foodie-order-service")
@RequestMapping("myorder-api")
public interface MyOrdersService {

    /**
     * 查询我的订单列表
     *
     * @param userId
     * @param orderStatus
     * @param page
     * @param pageSize
     * @return
     */
    @GetMapping("order/query") PagedGridResult queryMyOrders(@RequestParam("userId") String userId,
                                         @RequestParam("orderStatus") Integer orderStatus,
                                         @RequestParam(value = "page", required = false) Integer page,
                                         @RequestParam(value = "pageSize", required = false) Integer pageSize);

    /**
     * @Description: 订单状态 --> 商家发货
     */
    @PostMapping("order/delivered") void updateDeliverOrderStatus(@RequestParam("orderId") String orderId);

    /**
     * 查询我的订单
     *
     * @param userId
     * @param orderId
     * @return
     */
    @GetMapping("order/details") Orders queryMyOrder(@RequestParam("userId") String userId,
                               @RequestParam("orderId") String orderId);

    /**
     * 更新订单状态 —> 确认收货
     *
     * @return
     */
    @PostMapping("order/received") boolean updateReceiveOrderStatus(@RequestParam("orderId") String orderId);

    /**
     * 删除订单（逻辑删除）
     * @param userId
     * @param orderId
     * @return
     */
    @DeleteMapping("order") boolean deleteOrder(@RequestParam("userId") String userId,
                               @RequestParam("orderId") String orderId);

    /**
     * 查询用户订单数
     * @param userId
     */
    @GetMapping("order/counts") OrderStatusCountsVO getOrderStatusCounts(@RequestParam("userId") String userId);

    /**
     * 获得分页的订单动向
     * @param userId
     * @param page
     * @param pageSize
     * @return
     */
    @GetMapping("order/trend") PagedGridResult getOrdersTrend(@RequestParam("userId") String userId,
                                          @RequestParam("page") Integer page,
                                          @RequestParam("pageSize") Integer pageSize);

    @GetMapping("checkUserOrder") IMOOCJSONResult checkUserOrder(@RequestParam("userId") String userId,
                                          @RequestParam("orderId") String orderId);

}
```



![](https://tcs.teambition.net/storage/31217fe00a301dda845095ecab3b207dc7a6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3ZmUwMGEzMDFkZGE4NDUwOTVlY2FiM2IyMDdkYzdhNiJ9.LVVlOtcIP-FzUhOpHkhYluVD8Lo3IRDE7zA0ChRJJvc&download=image.png "")

```java
package com.imooc.order.service;

import com.imooc.order.pojo.OrderStatus;
import com.imooc.order.pojo.bo.PlaceOrderBO;
import com.imooc.order.pojo.bo.SubmitOrderBO;
import com.imooc.order.pojo.vo.OrderVO;
import com.imooc.pojo.ShopcartBO;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@FeignClient("foodie-order-service")
@RequestMapping("order-api")
public interface OrderService {

    /**
     * 用于创建订单相关信息
     * @param orderBO
     */
    @PostMapping("placeOrder") OrderVO createOrder(@RequestBody PlaceOrderBO orderBO);

    /**
     * 修改订单状态
     * @param orderId
     * @param orderStatus
     */
    @PostMapping("updateStatus") void updateOrderStatus(@RequestParam("orderId") String orderId,
                                  @RequestParam("orderStatus") Integer orderStatus);

    /**
     * 查询订单状态
     * @param orderId
     * @return
     */
    @GetMapping("orderStatus") OrderStatus queryOrderStatusInfo(@RequestParam("orderId") String orderId);

    /**
     * 关闭超时未支付订单
     */
    @PostMapping("closePendingOrders") void closeOrder();

}

```









![](https://tcs.teambition.net/storage/31219120972ba5ecc729c74804b5dd43b102?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5MTIwOTcyYmE1ZWNjNzI5Yzc0ODA0YjVkZDQzYjEwMiJ9.jLeSh3Fd8Q2Ll9zay3dYwn1VR6xZm3mtFOQfHY0nx-A&download=image.png "")

```java
package com.imooc.order.service.impl.center;

import com.imooc.enums.YesOrNo;
import com.imooc.item.service.ItemCommentsService;
import com.imooc.order.mapper.OrderItemsMapper;
import com.imooc.order.mapper.OrderStatusMapper;
import com.imooc.order.mapper.OrdersMapper;
import com.imooc.order.pojo.OrderItems;
import com.imooc.order.pojo.OrderStatus;
import com.imooc.order.pojo.Orders;
import com.imooc.order.pojo.bo.center.OrderItemsCommentBO;
import com.imooc.order.service.center.MyCommentsService;
import com.imooc.pojo.PagedGridResult;
import com.imooc.service.BaseService;
import org.n3r.idworker.Sid;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cloud.client.ServiceInstance;
import org.springframework.cloud.client.loadbalancer.LoadBalancerClient;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.client.RestTemplate;

import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@Service
public class MyCommentsServiceImpl extends BaseService implements MyCommentsService {

    @Autowired
    public OrderItemsMapper orderItemsMapper;

    @Autowired
    public OrdersMapper ordersMapper;

    @Autowired
    public OrderStatusMapper orderStatusMapper;

//    @Autowired
//    public ItemsCommentsMapperCustom itemsCommentsMapperCustom;
    // TODO feign章节里改成item-api
//    @Autowired
//    private LoadBalancerClient client;
//    @Autowired
//    private RestTemplate restTemplate;
    @Autowired
    private ItemCommentsService itemCommentsService;

    @Autowired
    private Sid sid;

    @Transactional(propagation = Propagation.SUPPORTS)
    @Override
    public List<OrderItems> queryPendingComment(String orderId) {
        OrderItems query = new OrderItems();
        query.setOrderId(orderId);
        return orderItemsMapper.select(query);
    }

    @Transactional(propagation = Propagation.REQUIRED)
    @Override
    public void saveComments(String orderId, String userId,
                             List<OrderItemsCommentBO> commentList) {

        // 1. 保存评价 items_comments
        for (OrderItemsCommentBO oic : commentList) {
            oic.setCommentId(sid.nextShort());
        }
        Map<String, Object> map = new HashMap<>();
        map.put("userId", userId);
        map.put("commentList", commentList);
//        itemsCommentsMapperCustom.saveComments(map);

        ServiceInstance instance = client.choose("FOODIE-ITEM-SERVICE");
        String url = String.format("http://%s:%s/item-comments-api/saveComments",
                instance.getHost(),
                instance.getPort());
        // TODO 偷个懒，不判断返回status，等下个章节用Feign重写
        restTemplate.postForLocation(url, map);

        // 2. 修改订单表改已评价 orders
        Orders order = new Orders();
        order.setId(orderId);
        order.setIsComment(YesOrNo.YES.type);
        ordersMapper.updateByPrimaryKeySelective(order);

        // 3. 修改订单状态表的留言时间 order_status
        OrderStatus orderStatus = new OrderStatus();
        orderStatus.setOrderId(orderId);
        orderStatus.setCommentTime(new Date());
        orderStatusMapper.updateByPrimaryKeySelective(orderStatus);
    }

    // TODO 移到了itemCommentService
//    @Transactional(propagation = Propagation.SUPPORTS)
//    @Override
//    public PagedGridResult queryMyComments(String userId,
//                                           Integer page,
//                                           Integer pageSize) {
//
//        Map<String, Object> map = new HashMap<>();
//        map.put("userId", userId);
//
//        PageHelper.startPage(page, pageSize);
//        List<MyCommentVO> list = itemsCommentsMapperCustom.queryMyComments(map);
//
//        return setterPagedGrid(list, page);
//    }
}


```



![](https://tcs.teambition.net/storage/3121944d9343a5a2ec3d948371e0f05faded?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5NDRkOTM0M2E1YTJlYzNkOTQ4MzcxZTBmMDVmYWRlZCJ9.-dxc-E35l7xzmO0vVllXd_R2ok_O4PuGN4zrN6SkJHM&download=image.png "")

```java
package com.imooc.order.service.impl.center;

import com.imooc.enums.YesOrNo;
import com.imooc.item.service.ItemCommentsService;
import com.imooc.order.mapper.OrderItemsMapper;
import com.imooc.order.mapper.OrderStatusMapper;
import com.imooc.order.mapper.OrdersMapper;
import com.imooc.order.pojo.OrderItems;
import com.imooc.order.pojo.OrderStatus;
import com.imooc.order.pojo.Orders;
import com.imooc.order.pojo.bo.center.OrderItemsCommentBO;
import com.imooc.order.service.center.MyCommentsService;
import com.imooc.pojo.PagedGridResult;
import com.imooc.service.BaseService;
import org.n3r.idworker.Sid;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cloud.client.ServiceInstance;
import org.springframework.cloud.client.loadbalancer.LoadBalancerClient;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.client.RestTemplate;

import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@Service
public class MyCommentsServiceImpl extends BaseService implements MyCommentsService {

    @Autowired
    public OrderItemsMapper orderItemsMapper;

    @Autowired
    public OrdersMapper ordersMapper;

    @Autowired
    public OrderStatusMapper orderStatusMapper;

//    @Autowired
//    public ItemsCommentsMapperCustom itemsCommentsMapperCustom;
    // TODO feign章节里改成item-api
//    @Autowired
//    private LoadBalancerClient client;
//    @Autowired
//    private RestTemplate restTemplate;
    @Autowired
    private ItemCommentsService itemCommentsService;

    @Autowired
    private Sid sid;

    @Transactional(propagation = Propagation.SUPPORTS)
    @Override
    public List<OrderItems> queryPendingComment(String orderId) {
        OrderItems query = new OrderItems();
        query.setOrderId(orderId);
        return orderItemsMapper.select(query);
    }

    @Transactional(propagation = Propagation.REQUIRED)
    @Override
    public void saveComments(String orderId, String userId,
                             List<OrderItemsCommentBO> commentList) {

        // 1. 保存评价 items_comments
        for (OrderItemsCommentBO oic : commentList) {
            oic.setCommentId(sid.nextShort());
        }
        Map<String, Object> map = new HashMap<>();
        map.put("userId", userId);
        map.put("commentList", commentList);
//        itemsCommentsMapperCustom.saveComments(map);

//        ServiceInstance instance = client.choose("FOODIE-ITEM-SERVICE");
//        String url = String.format("http://%s:%s/item-comments-api/saveComments",
//                instance.getHost(),
//                instance.getPort());
//        // TODO 偷个懒，不判断返回status，等下个章节用Feign重写
//        restTemplate.postForLocation(url, map);
        
        itemCommentsService.saveComments(map);

        // 2. 修改订单表改已评价 orders
        Orders order = new Orders();
        order.setId(orderId);
        order.setIsComment(YesOrNo.YES.type);
        ordersMapper.updateByPrimaryKeySelective(order);

        // 3. 修改订单状态表的留言时间 order_status
        OrderStatus orderStatus = new OrderStatus();
        orderStatus.setOrderId(orderId);
        orderStatus.setCommentTime(new Date());
        orderStatusMapper.updateByPrimaryKeySelective(orderStatus);
    }

    // TODO 移到了itemCommentService
//    @Transactional(propagation = Propagation.SUPPORTS)
//    @Override
//    public PagedGridResult queryMyComments(String userId,
//                                           Integer page,
//                                           Integer pageSize) {
//
//        Map<String, Object> map = new HashMap<>();
//        map.put("userId", userId);
//
//        PageHelper.startPage(page, pageSize);
//        List<MyCommentVO> list = itemsCommentsMapperCustom.queryMyComments(map);
//
//        return setterPagedGrid(list, page);
//    }
}

```



![](https://tcs.teambition.net/storage/312143b62877d5244d327e876b9a4741a395?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0M2I2Mjg3N2Q1MjQ0ZDMyN2U4NzZiOWE0NzQxYTM5NSJ9.cOkKEsmCorHRb3xjJHYGIF65UGutJgPjz56wddVkzVE&download=image.png "")



![](https://tcs.teambition.net/storage/3121f3071160d0e4e5f2cc759afb8c804bd1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmMzA3MTE2MGQwZTRlNWYyY2M3NTlhZmI4YzgwNGJkMSJ9.nOxvRH4gvxy3uhDtb8h9gz75GOPeax0P9hA5E5akTCA&download=image.png "")



![](https://tcs.teambition.net/storage/3121ed501ef5eeb20836bc71c88ecacd4f39?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlZDUwMWVmNWVlYjIwODM2YmM3MWM4OGVjYWNkNGYzOSJ9.JR93LE14-IqiaGvQ-MJAkaqHzgooxebu7U9u_l_OYfg&download=image.png "")

![](https://tcs.teambition.net/storage/312198ce40d5940a34d0b8248c5ad90ea7d0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5OGNlNDBkNTk0MGEzNGQwYjgyNDhjNWFkOTBlYTdkMCJ9.LaHwwQDrClUs0c_nbLcfymrNsksdtmdOVDuJnmtJcgM&download=image.png "")

![](https://tcs.teambition.net/storage/3121baafd4196cf4928629f27961926a98f7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiYWFmZDQxOTZjZjQ5Mjg2MjlmMjc5NjE5MjZhOThmNyJ9.W6YsdNUS_EQhTJqMIWYPTyXQgOdLR1u6meGkb2WigT0&download=image.png "")

```java
package com.imooc.order.service.impl;

import com.imooc.enums.OrderStatusEnum;
import com.imooc.enums.YesOrNo;
import com.imooc.item.pojo.Items;
import com.imooc.item.pojo.ItemsSpec;
import com.imooc.item.service.ItemService;
import com.imooc.order.mapper.OrderItemsMapper;
import com.imooc.order.mapper.OrderStatusMapper;
import com.imooc.order.mapper.OrdersMapper;
import com.imooc.order.pojo.OrderItems;
import com.imooc.order.pojo.OrderStatus;
import com.imooc.order.pojo.Orders;
import com.imooc.order.pojo.bo.PlaceOrderBO;
import com.imooc.order.service.OrderService;
import com.imooc.pojo.ShopcartBO;
import com.imooc.order.pojo.bo.SubmitOrderBO;
import com.imooc.order.pojo.vo.MerchantOrdersVO;
import com.imooc.order.pojo.vo.OrderVO;
//import com.imooc.user.service.AddressService;
//import com.imooc.item.service.ItemService;
import com.imooc.order.service.OrderService;
import com.imooc.user.pojo.UserAddress;
import com.imooc.user.service.AddressService;
import com.imooc.utils.DateUtil;
import org.n3r.idworker.Sid;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cloud.client.ServiceInstance;
import org.springframework.cloud.client.loadbalancer.LoadBalancerClient;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.client.RestTemplate;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

@Service
public class OrderServiceImpl implements OrderService {

    @Autowired
    private OrdersMapper ordersMapper;

    @Autowired
    private OrderItemsMapper orderItemsMapper;

    @Autowired
    private OrderStatusMapper orderStatusMapper;

    // TODO 学了Feign在来把注释打开
    @Autowired
    private AddressService addressService;
    @Autowired
    private ItemService itemService;
//    @Autowired
//    private LoadBalancerClient client;
//
//    @Autowired
//    private RestTemplate restTemplate;

    @Autowired
    private Sid sid;

    @Transactional(propagation = Propagation.REQUIRED)
    @Override
    public OrderVO createOrder(PlaceOrderBO placeOrderBO) {

        List<ShopcartBO> shopcartList = placeOrderBO.getItems();
        SubmitOrderBO submitOrderBO = placeOrderBO.getOrder();

        String userId = submitOrderBO.getUserId();
        String addressId = submitOrderBO.getAddressId();
        String itemSpecIds = submitOrderBO.getItemSpecIds();
        Integer payMethod = submitOrderBO.getPayMethod();
        String leftMsg = submitOrderBO.getLeftMsg();
        // 包邮费用设置为0
        Integer postAmount = 0;

        String orderId = sid.nextShort();

        // FIXME 等待feign章节再来简化
        UserAddress address = addressService.queryUserAddress(userId, addressId);
//        ServiceInstance instance = client.choose("FOODIE-USER-SERVICE");
//        String url = String.format("http://%s:%s/address-api/queryAddress" +
//                        "?userId=%s&addressId=%s",
//                instance.getHost(),
//                instance.getPort(),
//                userId, addressId);
//        // TODO 偷个懒，不判断返回status，等下个章节用Feign重写
//        UserAddress address = restTemplate.getForObject(url, UserAddress.class);

        // 1. 新订单数据保存
        Orders newOrder = new Orders();
        newOrder.setId(orderId);
        newOrder.setUserId(userId);

        newOrder.setReceiverName(address.getReceiver());
        newOrder.setReceiverMobile(address.getMobile());
        newOrder.setReceiverAddress(address.getProvince() + " "
                + address.getCity() + " "
                + address.getDistrict() + " "
                + address.getDetail());

//        newOrder.setTotalAmount();
//        newOrder.setRealPayAmount();
        newOrder.setPostAmount(postAmount);

        newOrder.setPayMethod(payMethod);
        newOrder.setLeftMsg(leftMsg);

        newOrder.setIsComment(YesOrNo.NO.type);
        newOrder.setIsDelete(YesOrNo.NO.type);
        newOrder.setCreatedTime(new Date());
        newOrder.setUpdatedTime(new Date());


        // 2. 循环根据itemSpecIds保存订单商品信息表
        String[] itemSpecIdArr = itemSpecIds.split(",");
        Integer totalAmount = 0;    // 商品原价累计
        Integer realPayAmount = 0;  // 优惠后的实际支付价格累计
        List<ShopcartBO> toBeRemovedShopcatdList = new ArrayList<>();
        for (String itemSpecId : itemSpecIdArr) {
            ShopcartBO cartItem = getBuyCountsFromShopcart(shopcartList, itemSpecId);
            // 整合redis后，商品购买的数量重新从redis的购物车中获取
            int buyCounts = cartItem.getBuyCounts();
            toBeRemovedShopcatdList.add(cartItem);

            // 2.1 根据规格id，查询规格的具体信息，主要获取价格
            // FIXME 等待feign章节再来简化queryItemSpecById
            ItemsSpec itemSpec = itemService.queryItemsSpecById(itemSpecId);
//            ServiceInstance itemApi = client.choose("FOODIE-ITEM-SERVICE");
//            url = String.format("http://%s:%s/item-api/singleItemSpec?specId=%s",
//                    itemApi.getHost(),
//                    itemApi.getPort(),
//                    itemSpecId);
//            ItemsSpec itemSpec = restTemplate.getForObject(url, ItemsSpec.class);

            totalAmount += itemSpec.getPriceNormal() * buyCounts;
            realPayAmount += itemSpec.getPriceDiscount() * buyCounts;

            // 2.2 根据商品id，获得商品信息以及商品图片
            String itemId = itemSpec.getItemId();
            // FIXME 等待feign章节再来简化
            // TODO 作业 -同学们自己改造
            Items item = itemService.queryItemsById(itemId);
//            Items item = null;
            // FIXME 等待feign章节再来简化
            // TODO 作业 -同学们自己改造
            String imgUrl = itemService.queryItemMainImgById(itemId);
//            String imgUrl = null;

            // 2.3 循环保存子订单数据到数据库
            String subOrderId = sid.nextShort();
            OrderItems subOrderItem = new OrderItems();
            subOrderItem.setId(subOrderId);
            subOrderItem.setOrderId(orderId);
            subOrderItem.setItemId(itemId);
            subOrderItem.setItemName(item.getItemName());
            subOrderItem.setItemImg(imgUrl);
            subOrderItem.setBuyCounts(buyCounts);
            subOrderItem.setItemSpecId(itemSpecId);
            subOrderItem.setItemSpecName(itemSpec.getName());
            subOrderItem.setPrice(itemSpec.getPriceDiscount());
            orderItemsMapper.insert(subOrderItem);

            // 2.4 在用户提交订单以后，规格表中需要扣除库存
            // FIXME 等待feign章节再来简化
            // TODO 作业 -同学们自己改造
            itemService.decreaseItemSpecStock(itemSpecId, buyCounts);
        }

        newOrder.setTotalAmount(totalAmount);
        newOrder.setRealPayAmount(realPayAmount);
        ordersMapper.insert(newOrder);

        // 3. 保存订单状态表
        OrderStatus waitPayOrderStatus = new OrderStatus();
        waitPayOrderStatus.setOrderId(orderId);
        waitPayOrderStatus.setOrderStatus(OrderStatusEnum.WAIT_PAY.type);
        waitPayOrderStatus.setCreatedTime(new Date());
        orderStatusMapper.insert(waitPayOrderStatus);

        // 4. 构建商户订单，用于传给支付中心
        MerchantOrdersVO merchantOrdersVO = new MerchantOrdersVO();
        merchantOrdersVO.setMerchantOrderId(orderId);
        merchantOrdersVO.setMerchantUserId(userId);
        merchantOrdersVO.setAmount(realPayAmount + postAmount);
        merchantOrdersVO.setPayMethod(payMethod);

        // 5. 构建自定义订单vo
        OrderVO orderVO = new OrderVO();
        orderVO.setOrderId(orderId);
        orderVO.setMerchantOrdersVO(merchantOrdersVO);
        orderVO.setToBeRemovedShopcatdList(toBeRemovedShopcatdList);

        return orderVO;
    }

    /**
     * 从redis中的购物车里获取商品，目的：counts
     * @param shopcartList
     * @param specId
     * @return
     */
    private ShopcartBO getBuyCountsFromShopcart(List<ShopcartBO> shopcartList, String specId) {
        for (ShopcartBO cart : shopcartList) {
            if (cart.getSpecId().equals(specId)) {
                return cart;
            }
        }
        return null;
    }

    @Transactional(propagation = Propagation.REQUIRED)
    @Override
    public void updateOrderStatus(String orderId, Integer orderStatus) {

        OrderStatus paidStatus = new OrderStatus();
        paidStatus.setOrderId(orderId);
        paidStatus.setOrderStatus(orderStatus);
        paidStatus.setPayTime(new Date());

        orderStatusMapper.updateByPrimaryKeySelective(paidStatus);
    }

    @Transactional(propagation = Propagation.SUPPORTS)
    @Override
    public OrderStatus queryOrderStatusInfo(String orderId) {
        return orderStatusMapper.selectByPrimaryKey(orderId);
    }

    @Transactional(propagation = Propagation.REQUIRED)
    @Override
    public void closeOrder() {

        // 查询所有未付款订单，判断时间是否超时（1天），超时则关闭交易
        OrderStatus queryOrder = new OrderStatus();
        queryOrder.setOrderStatus(OrderStatusEnum.WAIT_PAY.type);
        List<OrderStatus> list = orderStatusMapper.select(queryOrder);
        for (OrderStatus os : list) {
            // 获得订单创建时间
            Date createdTime = os.getCreatedTime();
            // 和当前时间进行对比
            int days = DateUtil.daysBetween(createdTime, new Date());
            if (days >= 1) {
                // 超过1天，关闭订单
                doCloseOrder(os.getOrderId());
            }
        }
    }

    @Transactional(propagation = Propagation.REQUIRED)
    void doCloseOrder(String orderId) {
        OrderStatus close = new OrderStatus();
        close.setOrderId(orderId);
        close.setOrderStatus(OrderStatusEnum.CLOSE.type);
        close.setCloseTime(new Date());
        orderStatusMapper.updateByPrimaryKeySelective(close);
    }
}

```







![](https://tcs.teambition.net/storage/3121336124756360bb34f3afca2a3c1396db?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzMzYxMjQ3NTYzNjBiYjM0ZjNhZmNhMmEzYzEzOTZkYiJ9.HL4pzl1aZZVC8VC7zcMYDauvcPISxDjNixrnf1T2RJs&download=image.png "")

```java
package com.imooc.order;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import org.springframework.cloud.openfeign.EnableFeignClients;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.scheduling.annotation.EnableScheduling;
import tk.mybatis.spring.annotation.MapperScan;

/**
 * Created by 半仙.
 */
@SpringBootApplication
// 扫描 mybatis 通用 mapper 所在的包
@MapperScan(basePackages = "com.imooc.order.mapper")
// 扫描所有包以及相关组件包
@ComponentScan(basePackages = {"com.imooc", "org.n3r.idworker"})
@EnableDiscoveryClient
@EnableScheduling
// TODO feign注解
@EnableFeignClients(basePackages = {
        "com.imooc.user.service",
        "com.imooc.item.service"
})
public class OrderApplication {

    public static void main(String[] args) {
        SpringApplication.run(OrderApplication.class, args);
    }

}

```

这个扫包路径 就会去从配置的@FeignClient 设置的Server Name 中 Service层接口方法定义的@GetRequest  @PostMapping 的映射名 根据这个映射名作为方法名 去在@EnableFeignClients中寻找包为xxx 级子包 的 一致的方法名 发起调用

![](https://tcs.teambition.net/storage/31213e708876529d7cf8d178e48d0e806178?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzZTcwODg3NjUyOWQ3Y2Y4ZDE3OGU0OGQwZTgwNjE3OCJ9.y7BWqT4TrkPdgIk72wvig82vW5uXoZCaRbjuP5bIMfQ&download=image.png "")







![](https://tcs.teambition.net/storage/31210b4f5605d5ac68a78b4f35d1da58e414?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwYjRmNTYwNWQ1YWM2OGE3OGI0ZjM1ZDFkYTU4ZTQxNCJ9.x__dHvgaXhBjQnu6aqqKhqFGlMobgP2W2Y_m5O9wx3Q&download=image.png "")

![](https://tcs.teambition.net/storage/31217fc4a2ebfe42ad3db70e85ef070dd89d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3ZmM0YTJlYmZlNDJhZDNkYjcwZTg1ZWYwNzBkZDg5ZCJ9.ghmpGYN_F8gkJg1ZUPkUEVDay7JdNsbz879PUOSilfw&download=image.png "")

```java
package com.imooc.order.controller.center;

import com.imooc.controller.BaseController;
import com.imooc.enums.YesOrNo;
import com.imooc.item.service.ItemCommentsService;
import com.imooc.order.pojo.OrderItems;
import com.imooc.order.pojo.Orders;
import com.imooc.order.pojo.bo.center.OrderItemsCommentBO;
import com.imooc.order.service.center.MyCommentsService;
import com.imooc.order.service.center.MyOrdersService;
import com.imooc.pojo.IMOOCJSONResult;
import com.imooc.pojo.PagedGridResult;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cloud.client.ServiceInstance;
import org.springframework.cloud.client.loadbalancer.LoadBalancerClient;
import org.springframework.http.HttpStatus;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.client.RestTemplate;

import java.util.List;

@Api(value = "用户中心评价模块", tags = {"用户中心评价模块相关接口"})
@RestController
@RequestMapping("mycomments")
public class MyCommentsController extends BaseController {

    @Autowired
    private MyCommentsService myCommentsService;

    @Autowired
    private MyOrdersService myOrdersService;

    @Autowired
    private ItemCommentsService itemCommentsService;
//    @Autowired
//    private LoadBalancerClient client;
//
//    @Autowired
//    private RestTemplate restTemplate;

    @ApiOperation(value = "查询订单列表", notes = "查询订单列表", httpMethod = "POST")
    @PostMapping("/pending")
    public IMOOCJSONResult pending(
            @ApiParam(name = "userId", value = "用户id", required = true)
            @RequestParam String userId,
            @ApiParam(name = "orderId", value = "订单id", required = true)
            @RequestParam String orderId) {

        // 判断用户和订单是否关联
        IMOOCJSONResult checkResult = myOrdersService.checkUserOrder(userId, orderId);
        if (checkResult.getStatus() != HttpStatus.OK.value()) {
            return checkResult;
        }
        // 判断该笔订单是否已经评价过，评价过了就不再继续
        Orders myOrder = (Orders)checkResult.getData();
        if (myOrder.getIsComment() == YesOrNo.YES.type) {
            return IMOOCJSONResult.errorMsg("该笔订单已经评价");
        }

        List<OrderItems> list = myCommentsService.queryPendingComment(orderId);

        return IMOOCJSONResult.ok(list);
    }


    @ApiOperation(value = "保存评论列表", notes = "保存评论列表", httpMethod = "POST")
    @PostMapping("/saveList")
    public IMOOCJSONResult saveList(
            @ApiParam(name = "userId", value = "用户id", required = true)
            @RequestParam String userId,
            @ApiParam(name = "orderId", value = "订单id", required = true)
            @RequestParam String orderId,
            @RequestBody List<OrderItemsCommentBO> commentList) {

        System.out.println(commentList);

        // 判断用户和订单是否关联
        IMOOCJSONResult checkResult = myOrdersService.checkUserOrder(userId, orderId);
        if (checkResult.getStatus() != HttpStatus.OK.value()) {
            return checkResult;
        }
        // 判断评论内容list不能为空
        if (commentList == null || commentList.isEmpty() || commentList.size() == 0) {
            return IMOOCJSONResult.errorMsg("评论内容不能为空！");
        }

        myCommentsService.saveComments(orderId, userId, commentList);
        return IMOOCJSONResult.ok();
    }

    @ApiOperation(value = "查询我的评价", notes = "查询我的评价", httpMethod = "POST")
    @PostMapping("/query")
    public IMOOCJSONResult query(
            @ApiParam(name = "userId", value = "用户id", required = true)
            @RequestParam String userId,
            @ApiParam(name = "page", value = "查询下一页的第几页", required = false)
            @RequestParam Integer page,
            @ApiParam(name = "pageSize", value = "分页的每一页显示的条数", required = false)
            @RequestParam Integer pageSize) {

        if (StringUtils.isBlank(userId)) {
            return IMOOCJSONResult.errorMsg(null);
        }
        if (page == null) {
            page = 1;
        }
        if (pageSize == null) {
            pageSize = COMMON_PAGE_SIZE;
        }

        // TODO 前方施工，学完Feign再来改造
        PagedGridResult grid = itemCommentsService.queryMyComments(userId,
                page,
                pageSize);
//        ServiceInstance instance = client.choose("FOODIE-ITEM-SERVICE");
//        String target = String.format("http://%s:%s/item-comments-api/myComments" +
//                        "?userId=%s&page=%s&pageSize=%s",
//                instance.getHost(),
//                instance.getPort(),
//                userId,
//                page,
//                pageSize);
//        // 偷个懒，不判断返回status，等下个章节用Feign重写
//        PagedGridResult grid = restTemplate.getForObject(target, PagedGridResult.class);
//
        return IMOOCJSONResult.ok(grid);
//
//        PagedGridResult grid = myCommentsService.queryMyComments(userId,
//                page,
//                pageSize);
//
//        return IMOOCJSONResult.ok(grid);
    }

}

```



![](https://tcs.teambition.net/storage/3121599cddbdb2cd17d97a8f7295061527cb?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1OTljZGRiZGIyY2QxN2Q5N2E4ZjcyOTUwNjE1MjdjYiJ9.Vyg5hDSa2zqVmJFiHViWxaZTtGpEJLor_w4pB6-WIAg&download=image.png "")

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
    name: foodie-order-service # 微服务在注册中心的名字
  main:
    allow-bean-definition-overriding: true
  profiles:
    active: dev
  datasource:                                           # 数据源的相关配置
    type: com.zaxxer.hikari.HikariDataSource          # 数据源类型：HikariCP
    driver-class-name: com.mysql.jdbc.Driver          # mysql驱动
#    url: jdbc:mysql://localhost:3306/foodie-shop-dev?useUnicode=true&characterEncoding=UTF-8&autoReconnect=true
    username: root
#    password: opendevel
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
  type-aliases-package: com.imooc.order.pojo         # 所有POJO类所在包路径
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



#  resources:
#    static-locations: classpath:/static



```







![](https://tcs.teambition.net/storage/312199c036e970404267b7b0e932b56b4389?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5OWMwMzZlOTcwNDA0MjY3YjdiMGU5MzJiNTZiNDM4OSJ9.xwBMi3NWsG42-i-H8-HQv3PfJRnrai3hzxF3HExUHtI&download=image.png "")

![](https://tcs.teambition.net/storage/312187fb6b2f32e60ccdf526d20bc34a66bd?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4N2ZiNmIyZjMyZTYwY2NkZjUyNmQyMGJjMzRhNjZiZCJ9.rhPAdI8tnuEu81FJz48hrS0A9Nvh8qxQWpa1HZc2w78&download=image.png "")

两个知识点

把Peer 1 和 Peer 2 配置过程中 替换为 Ip 地址 配置



双备份注册中心 如果你在Eureka 配置文件当中  开启了自己注册 如果 开启了 自动拉取注册信息 以及服务注册 那么 这两个注册中心  它会出现在 注册列表当中 当你不使用host name  而是使用IP Adress的时候 哪双备份注册中心 在这个列表当中 有时候 不仅显示在 available 分区当中 同时也会出现在 Not available 分区当中 怎么同一个实例 既出现在可用 又不可用 这个情况跟IP 和 HOST name 有那么一点关系 

用host name 会被识别两个不同的实例 



可以指定用 hostname 还是用ip地址注册









使用IP地址注册











![](https://tcs.teambition.net/storage/31215786e4a7a13f4616f1c875a01fa1a437?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1Nzg2ZTRhN2ExM2Y0NjE2ZjFjODc1YTAxZmExYTQzNyJ9.CmPUzV4PSMeR8KFHkVP0XuyI0dfzJXzbTrLhylFxUm8&download=image.png "")

```java
package com.imooc.order.service.impl.center;

import com.imooc.enums.YesOrNo;
import com.imooc.item.service.ItemCommentsService;
import com.imooc.order.mapper.OrderItemsMapper;
import com.imooc.order.mapper.OrderStatusMapper;
import com.imooc.order.mapper.OrdersMapper;
import com.imooc.order.pojo.OrderItems;
import com.imooc.order.pojo.OrderStatus;
import com.imooc.order.pojo.Orders;
import com.imooc.order.pojo.bo.center.OrderItemsCommentBO;
import com.imooc.order.service.center.MyCommentsService;
import com.imooc.pojo.PagedGridResult;
import com.imooc.service.BaseService;
import org.n3r.idworker.Sid;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cloud.client.ServiceInstance;
import org.springframework.cloud.client.loadbalancer.LoadBalancerClient;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.client.RestTemplate;

import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


@Service
@RestController
public class MyCommentsServiceImpl extends BaseService implements MyCommentsService {

    @Autowired
    public OrderItemsMapper orderItemsMapper;

    @Autowired
    public OrdersMapper ordersMapper;

    @Autowired
    public OrderStatusMapper orderStatusMapper;

//    @Autowired
//    public ItemsCommentsMapperCustom itemsCommentsMapperCustom;
    // TODO feign章节里改成item-api
//    @Autowired
//    private LoadBalancerClient client;
//    @Autowired
//    private RestTemplate restTemplate;
    @Autowired
    private ItemCommentsService itemCommentsService;

    @Autowired
    private Sid sid;

    @Transactional(propagation = Propagation.SUPPORTS)
    @Override
    public List<OrderItems> queryPendingComment(String orderId) {
        OrderItems query = new OrderItems();
        query.setOrderId(orderId);
        return orderItemsMapper.select(query);
    }

    @Transactional(propagation = Propagation.REQUIRED)
    @Override
    public void saveComments(String orderId, String userId,
                             List<OrderItemsCommentBO> commentList) {

        // 1. 保存评价 items_comments
        for (OrderItemsCommentBO oic : commentList) {
            oic.setCommentId(sid.nextShort());
        }
        Map<String, Object> map = new HashMap<>();
        map.put("userId", userId);
        map.put("commentList", commentList);
//        itemsCommentsMapperCustom.saveComments(map);

//        ServiceInstance instance = client.choose("FOODIE-ITEM-SERVICE");
//        String url = String.format("http://%s:%s/item-comments-api/saveComments",
//                instance.getHost(),
//                instance.getPort());
//        // TODO 偷个懒，不判断返回status，等下个章节用Feign重写
//        restTemplate.postForLocation(url, map);

        itemCommentsService.saveComments(map);

        // 2. 修改订单表改已评价 orders
        Orders order = new Orders();
        order.setId(orderId);
        order.setIsComment(YesOrNo.YES.type);
        ordersMapper.updateByPrimaryKeySelective(order);

        // 3. 修改订单状态表的留言时间 order_status
        OrderStatus orderStatus = new OrderStatus();
        orderStatus.setOrderId(orderId);
        orderStatus.setCommentTime(new Date());
        orderStatusMapper.updateByPrimaryKeySelective(orderStatus);
    }

    // TODO 移到了itemCommentService
//    @Transactional(propagation = Propagation.SUPPORTS)
//    @Override
//    public PagedGridResult queryMyComments(String userId,
//                                           Integer page,
//                                           Integer pageSize) {
//
//        Map<String, Object> map = new HashMap<>();
//        map.put("userId", userId);
//
//        PageHelper.startPage(page, pageSize);
//        List<MyCommentVO> list = itemsCommentsMapperCustom.queryMyComments(map);
//
//        return setterPagedGrid(list, page);
//    }
}

```



为什么写成Service还可以运行

MyCommentsServiceImpl  并没有作为一个微服务 提供方法调用 

只是在 订单微服务中 来进行注入调用 

如果需要对外提供服务 就要写成@RestController



![](https://tcs.teambition.net/storage/31216d9b86228406efb79d208c20f5690ff9?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2ZDliODYyMjg0MDZlZmI3OWQyMDhjMjBmNTY5MGZmOSJ9.rKN-nPUc-uFqKjSF8pVgIE1sPIFNKLMaQp98YxHbcsg&download=image.png "")

```text
[OrderItemsCommentBO{commentLevel=2, content='Sdf'}]
INFO  ServiceLogAspect:42 - ====== 开始执行 class com.imooc.order.service.impl.center.MyOrdersServiceImpl.checkUserOrder ======
Creating a new SqlSession
SqlSession [org.apache.ibatis.session.defaults.DefaultSqlSession@24df2799] was not registered for synchronization because synchronization is not active
JDBC Connection [HikariProxyConnection@774327529 wrapping com.mysql.cj.jdbc.ConnectionImpl@2fa5c610] will not be managed by Spring
==>  Preparing: SELECT id,user_id,receiver_name,receiver_mobile,receiver_address,total_amount,real_pay_amount,post_amount,pay_method,left_msg,extand,is_comment,is_delete,created_time,updated_time FROM orders WHERE id = ? AND user_id = ? AND is_delete = ? 
==> Parameters: 201015FD06S3R400(String), 201013ASBYNDSR1P(String), 0(Integer)
<==    Columns: id, user_id, receiver_name, receiver_mobile, receiver_address, total_amount, real_pay_amount, post_amount, pay_method, left_msg, extand, is_comment, is_delete, created_time, updated_time
<==        Row: 201015FD06S3R400, 201013ASBYNDSR1P, qweqw, 13232164554, 广东 广州 越秀区 qwe, 15000, 15000, 0, 1, , null, 1, 0, 2020-10-15 07:16:02, 2020-10-15 07:16:02
<==      Total: 1
Closing non transactional SqlSession [org.apache.ibatis.session.defaults.DefaultSqlSession@24df2799]
INFO  ServiceLogAspect:58 - ======== 执行结束，耗时：11 毫秒 ========
INFO  ServiceLogAspect:42 - ====== 开始执行 class com.imooc.order.service.impl.center.MyCommentsServiceImpl.saveComments ======
Creating a new SqlSession
Registering transaction synchronization for SqlSession [org.apache.ibatis.session.defaults.DefaultSqlSession@b0a2806]
JDBC Connection [HikariProxyConnection@1518632615 wrapping com.mysql.cj.jdbc.ConnectionImpl@2fa5c610] will be managed by Spring
==>  Preparing: UPDATE orders SET is_comment = ? WHERE id = ? 
==> Parameters: 1(Integer), 201015FD06S3R400(String)
<==    Updates: 1
Releasing transactional SqlSession [org.apache.ibatis.session.defaults.DefaultSqlSession@b0a2806]
Fetched SqlSession [org.apache.ibatis.session.defaults.DefaultSqlSession@b0a2806] from current transaction
==>  Preparing: UPDATE order_status SET comment_time = ? WHERE order_id = ? 
==> Parameters: 2021-01-18 20:28:24.493(Timestamp), 201015FD06S3R400(String)
<==    Updates: 1
Releasing transactional SqlSession [org.apache.ibatis.session.defaults.DefaultSqlSession@b0a2806]
INFO  ServiceLogAspect:58 - ======== 执行结束，耗时：44 毫秒 ========
Transaction synchronization committing SqlSession [org.apache.ibatis.session.defaults.DefaultSqlSession@b0a2806]
Transaction synchronization deregistering SqlSession [org.apache.ibatis.session.defaults.DefaultSqlSession@b0a2806]
Transaction synchronization closing SqlSession [org.apache.ibatis.session.defaults.DefaultSqlSession@b0a2806]
INFO  ConfigClusterResolver:43 - Resolving eureka endpoints via configuration


```



![](https://tcs.teambition.net/storage/312127f3ce80fdf6d1d193488bed0943e44b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyN2YzY2U4MGZkZjZkMWQxOTM0ODhiZWQwOTQzZTQ0YiJ9.qMnBopGt1Q8NsGO6mdnic9fZaB0an3oUPSDgUAnBQRM&download=image.png "")

```text
INFO  ServiceLogAspect:42 - ====== 开始执行 class com.imooc.item.service.impl.ItemCommentsServiceImpl.saveComments ======
Creating a new SqlSession
SqlSession [org.apache.ibatis.session.defaults.DefaultSqlSession@7371e27c] was not registered for synchronization because synchronization is not active
JDBC Connection [HikariProxyConnection@163363380 wrapping com.mysql.cj.jdbc.ConnectionImpl@cb5be32] will not be managed by Spring
==>  Preparing: INSERT INTO items_comments ( id, user_id, item_id, item_name, item_spec_id, sepc_name, comment_level, content, created_time, updated_time ) VALUES ( ?, ?, ?, ?, ?, ?, ?, ?, now(), now() ) 
==> Parameters: 210118FK0A5RN0H0(String), 201013ASBYNDSR1P(String), 12(String), null, null, null, 2(Integer), Sdf(String)
Closing non transactional SqlSession [org.apache.ibatis.session.defaults.DefaultSqlSession@7371e27c]
INFO  ServiceLogAspect:58 - ======== 执行结束，耗时：1041 毫秒 ========
INFO  ServiceLogAspect:42 - ====== 开始执行 class com.imooc.item.service.impl.ItemCommentsServiceImpl.saveComments ======
Creating a new SqlSession
SqlSession [org.apache.ibatis.session.defaults.DefaultSqlSession@7caf13dd] was not registered for synchronization because synchronization is not active
JDBC Connection [HikariProxyConnection@1985444013 wrapping com.mysql.cj.jdbc.ConnectionImpl@cb5be32] will not be managed by Spring
==>  Preparing: INSERT INTO items_comments ( id, user_id, item_id, item_name, item_spec_id, sepc_name, comment_level, content, created_time, updated_time ) VALUES ( ?, ?, ?, ?, ?, ?, ?, ?, now(), now() ) 
==> Parameters: 210118FK3HDKS1D4(String), 201013ASBYNDSR1P(String), 12(String), null, null, null, 2(Integer), Sdf(String)
Closing non transactional SqlSession [org.apache.ibatis.session.defaults.DefaultSqlSession@7caf13dd]
INFO  ServiceLogAspect:58 - ======== 执行结束，耗时：11 毫秒 ========
INFO  ConfigClusterResolver:43 - Resolving eureka endpoints via configuration


```

![](https://tcs.teambition.net/storage/312166e9520c86a5a38d916b4237e4799126?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2NmU5NTIwYzg2YTVhMzhkOTE2YjQyMzdlNDc5OTEyNiJ9.CPm5JNJnxLz6Y2APoJhwQinGY36TfyqNLC9wpz37OAs&download=image.png "")

```text
localhost:10003/mycomments/saveList?orderId=201015FD06S3R400&userId=201013ASBYNDSR1P

[
    {
        "itemId":"12",
        "content":"Sdf",
        "commentLevel":2
    }
]

{
    "status": 200,
    "msg": "OK",
    "data": null
}


```

![](https://tcs.teambition.net/storage/3121eb9ecc3d8bce854ed4aed7b419d4ae0d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlYjllY2MzZDhiY2U4NTRlZDRhZWQ3YjQxOWQ0YWUwZCJ9.NyZitzmpg-MrOWESp-3vadZznovav4JK9qwksna9xKA&download=image.png "")

![](https://tcs.teambition.net/storage/3121758b6fe93297c036e73d12e35d008b76?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3NThiNmZlOTMyOTdjMDM2ZTczZDEyZTM1ZDAwOGI3NiJ9.nmqHiDdvkgQ6Y7zifEsk2w0UAJL8jUTVRAgkG5InBbs&download=image.png "")



调用的整体过程

![](https://tcs.teambition.net/storage/31212b8a79f22776e923c16308379c2c43a4?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyYjhhNzlmMjI3NzZlOTIzYzE2MzA4Mzc5YzJjNDNhNCJ9.U8UT-JATyNbVKjKjCjeJWfaWg2mrvjY_7Engru70CPM&download=image.png "")

在这些包下寻找有FeignClient注解



![](https://tcs.teambition.net/storage/3121974cf72a7e19356c6754d13d58306722?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5NzRjZjcyYTdlMTkzNTZjNjc1NGQxM2Q1ODMwNjcyMiJ9._EmYyPuiQDw48yd8uunq0SYbxmJ4fPG-sAdG4Pe58Yg&download=image.png "")

![](https://tcs.teambition.net/storage/3121dc54b4783c8dbc4d4901d1cdf91478f1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkYzU0YjQ3ODNjOGRiYzRkNDkwMWQxY2RmOTE0NzhmMSJ9.3kDU5xHEEusy0pI2mmml63UpVumx7i-IyttGXPxa_XA&download=image.png "")

![](https://tcs.teambition.net/storage/312181aaa04399d73597b715167b607e57c6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4MWFhYTA0Mzk5ZDczNTk3YjcxNTE2N2I2MDdlNTdjNiJ9.pzi1yeZgj5ETdjJilk5SfIL_kxdDrXPN74GpSG0hJ2U&download=image.png "")

![](https://tcs.teambition.net/storage/3121efa47722a2ecfddeba18342212e476b7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlZmE0NzcyMmEyZWNmZGRlYmExODM0MjIxMmU0NzZiNyJ9.jeacJq35k8O6UmO3l65hmMkEiiZQsPn1JvD1lEztx40&download=image.png "")

![](https://tcs.teambition.net/storage/3121d5cc8440fface43204902dbac2a3c225?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkNWNjODQ0MGZmYWNlNDMyMDQ5MDJkYmFjMmEzYzIyNSJ9.VzAiBIul7w-KdunUsVXbQwzVa2Jv2sSFtW8WqSZFPKg&download=image.png "")

![](https://tcs.teambition.net/storage/31212ee1779c3e03e23bd4b64d02ffa30432?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyZWUxNzc5YzNlMDNlMjNiZDRiNjRkMDJmZmEzMDQzMiJ9.RVy4geSV7pDL1OvpPoxDNijVNBqgW0VvdvKOkhsp4ck&download=image.png "")

![](https://tcs.teambition.net/storage/31214018f2d9194e628d9e8a71dc7d1e91a7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0MDE4ZjJkOTE5NGU2MjhkOWU4YTcxZGM3ZDFlOTFhNyJ9.NbOPvISgaCu-yoEFerDtPbEuG_LLGqx7wP0RhnSIpLs&download=image.png "")

![](https://tcs.teambition.net/storage/3121b2f804128cf197ae121203c06b70d707?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiMmY4MDQxMjhjZjE5N2FlMTIxMjAzYzA2YjcwZDcwNyJ9.0hKbEEB9PqBRMRQ8IHdqojQRQfvj9SsyuF4YZ-95J1A&download=image.png "")

![](https://tcs.teambition.net/storage/312196348a38a46073cbd66be745ec9a6aad?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5NjM0OGEzOGE0NjA3M2NiZDY2YmU3NDVlYzlhNmFhZCJ9.kn6eVB-4on9zUn3ouGvhV3o_ZHExBdnNgoZSGKxeD0k&download=image.png "")

通过PostMapping 注解 在实现类里面寻找相同的方法

需要些上RestController 注解

![](https://tcs.teambition.net/storage/3121cb8e71e6da8eb3c5a095f62c6bedde16?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjYjhlNzFlNmRhOGViM2M1YTA5NWY2MmM2YmVkZGUxNiJ9.g2J1OMJoqqdFConu41N0H4nIa5HNRqoAIQYvpZ8PwMs&download=image.png "")

![](https://tcs.teambition.net/storage/31215836757b9c9018fc8677215a73d8a438?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1ODM2NzU3YjljOTAxOGZjODY3NzIxNWE3M2Q4YTQzOCJ9.Q8FhhJZAzaKNiUAeZqvoSS3xzpIBBAPhRDT4R9NYwno&download=image.png "")

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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTkwMCwiaWF0IjoxNjEyMTkxMTAwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.ehbm8AsuDr65Jp_DXCSu0qw5Q2T8UxPyXr7wORxDeNE&download=image.png "")

