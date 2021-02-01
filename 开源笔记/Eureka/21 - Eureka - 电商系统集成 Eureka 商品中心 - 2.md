![](https://tcs.teambition.net/storage/3121d2f56e492c072b95ee09f630cbbdbcd7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkMmY1NmU0OTJjMDcyYjk1ZWUwOWY2MzBjYmJkYmNkNyJ9._8vEPQLdtHv0hC516tR1MXyx3who6B04smcUtqMoFd4&download=image.png "")

![](https://tcs.teambition.net/storage/3121495bb759118941a13c8284fc02b5255c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0OTViYjc1OTExODk0MWExM2M4Mjg0ZmMwMmI1MjU1YyJ9.5-qy6XaB8fLN4oWIiOxurkrUSoY_m4y_NZRGrIBXBzM&download=image.png "")

![](https://tcs.teambition.net/storage/3121ef076c68e073566dc2d0f20cffc2278b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlZjA3NmM2OGUwNzM1NjZkYzJkMGYyMGNmZmMyMjc4YiJ9.aBXZUOQ31_v_mwgisWHsbiHdayB8zolfE5rPao1P6BM&download=image.png "")

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

        <!-- TODO Feign dependencies -->

    </dependencies>

</project>
```

## 复制

![](https://tcs.teambition.net/storage/3121273bd6b862a8c504d600dbd8d7a7c667?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyNzNiZDZiODYyYThjNTA0ZDYwMGRiZDhkN2E3YzY2NyJ9.YLNi1X-lMZ9Qrocr3n5Y3S4KMK1ZFlPVwJFgC4n6-Fg&download=image.png "")

## 修改

![](https://tcs.teambition.net/storage/312142ab08e8af6eddd96a4d418e64619d59?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0MmFiMDhlOGFmNmVkZGQ5NmE0ZDQxOGU2NDYxOWQ1OSJ9.yF3zGfcCruciTcikBLvZgGhwycml1OTisr_nknyr0AA&download=image.png "")

```java
package com.imooc.item.service;

import com.imooc.item.pojo.Items;
import com.imooc.item.pojo.ItemsImg;
import com.imooc.item.pojo.ItemsParam;
import com.imooc.item.pojo.ItemsSpec;
import com.imooc.item.pojo.vo.CommentsLevelCountsVO;
import com.imooc.item.pojo.vo.ShopcartVO;
import com.imooc.pojo.PagedGridResult;

import java.util.List;

public interface ItemService {

    /**
     * 根据商品id查询详情
     * @param itemId
     * @return
     */
    public Items queryItemsById(String itemId);

    /**
     * 根据商品id查询商品图片列表
     * @param itemId
     * @return
     */
    public List<ItemsImg> queryItemsImgList(String itemId);

    /**
     * 根据商品id查询商品规格
     * @param itemId
     * @return
     */
    public List<ItemsSpec> queryItemsSpecList(String itemId);

    /**
     * 根据商品id查询商品参数
     * @param itemId
     * @return
     */
    public ItemsParam queryItemsParam(String itemId);


    /**
     * 根据商品id查询商品的评价等级数量
     * @param itemId
     * @return
     */
    public CommentsLevelCountsVO queryCommentsCounts(String itemId);

    /**
     * 根据商品id查询商品的评价（分页）
     * @param itemId
     * @param level
     * @return
     */
    public PagedGridResult queryPagedComments(String itemId, Integer level,
                                              Integer page, Integer pageSize);

    /**
     * 搜索商品列表
     * @param keywords
     * @param sort
     * @param page
     * @param pageSize
     * @return
     */
    public PagedGridResult searchItems(String keywords,String sort,
                                       Integer page,Integer pageSize);

    /**
     * 根据分类Id搜索商品列表
     * @param catId
     * @param sort
     * @param page
     * @param pageSize
     * @return
     */
    public PagedGridResult searchItems(Integer catId,String sort,
                                       Integer page,Integer pageSize);

    /**
     * 根据规格ids查询最新的购物车中商品数据（用于刷新渲染购物车的商品数据）
     * @param specIds
     * @return
     */
    public List<ShopcartVO> queryItemsBySpecIds(String specIds);

    /**
     * 根据商品规格id获取规格对象的具体信息
     * @param specId
     * @return
     */
    public ItemsSpec queryItemsSpecById(String specId);

    /**
     * 根据商品id获得商品图片主图url
     * @param imgId
     * @return
     */
    public String queryItemMainImgById(String imgId);

    /**
     * 减少库存
     * @param specId
     * @param buyCounts
     */
    public void decreaseItemSpecStock(String specId,int buyCounts);

}


```

## 接口层要对外提供服务 声明成Controller 会有RequestMapping 路径的配置  把路径配置在接口层 这样在接口上 声明的注解 继承到实现类当中 服务之间调用 通过Feign组件来调用  调用方直接拿到这接口就可以去寻址了

![](https://tcs.teambition.net/storage/31211f785093c707ed0a8602e01b0aee3ad3?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExZjc4NTA5M2M3MDdlZDBhODYwMmUwMWIwYWVlM2FkMyJ9.gQCCqUDuv3UVG0i4hsGa4DwaCXVHQVVSZ5saV5WUhvg&download=image.png "")

![](https://tcs.teambition.net/storage/3121353927e4387a2c73280bad5e73a64206?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzNTM5MjdlNDM4N2EyYzczMjgwYmFkNWU3M2E2NDIwNiJ9.R1xMdMnkPoRDVpjj0E3PrE9-2eWBJZ_8iRfJdKw6xaw&download=image.png "")

![](https://tcs.teambition.net/storage/31212b38c3a49032300f7f4be653af6e1bcc?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyYjM4YzNhNDkwMzIzMDBmN2Y0YmU2NTNhZjZlMWJjYyJ9.pcF-2oDCfdOupZ54txQoDdgZcNeQUpSpiPafBRgaPmI&download=image.png "")

![](https://tcs.teambition.net/storage/3121cf0cad7d882ad0e1ae18eddd814fdfa1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjZjBjYWQ3ZDg4MmFkMGUxYWUxOGVkZGQ4MTRmZGZhMSJ9.7DdAz1kdHxy4Mi0RhWvWXiHVtcdtG2ukD4XC0LdQjgU&download=image.png "")

![](https://tcs.teambition.net/storage/31219ffb0db9149256cde1f2cb09f47818f7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5ZmZiMGRiOTE0OTI1NmNkZTFmMmNiMDlmNDc4MThmNyJ9.kBnBTsbPeyr7UAzF-grCAMX72ibAMprNTCeKRWeoiSA&download=image.png "")

![](https://tcs.teambition.net/storage/3121511bf6fbc77005d458a31ca087773296?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1MTFiZjZmYmM3NzAwNWQ0NThhMzFjYTA4Nzc3MzI5NiJ9.3w0HAR3p7ksqeVam6pODpnwQbwtnHM1dRXXaeI3bOc8&download=image.png "")

![](https://tcs.teambition.net/storage/3121a4966c1697490e63c4fe9fd343e00dd1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhNDk2NmMxNjk3NDkwZTYzYzRmZTlmZDM0M2UwMGRkMSJ9.QGQDmrsLHI7E3jIXurs4i75A9iaEeWFY5-z5SOcLuc8&download=image.png "")

![](https://tcs.teambition.net/storage/31212acdd7373d11417cb0717e560866cde8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyYWNkZDczNzNkMTE0MTdjYjA3MTdlNTYwODY2Y2RlOCJ9.0J4WMjX7DBkXEk1TUHJHmHeVWmi1mTFojIE9pv6_mj4&download=image.png "")

![](https://tcs.teambition.net/storage/31217bd1b1e19c7e31afd229e72984d91fb1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3YmQxYjFlMTljN2UzMWFmZDIyOWU3Mjk4NGQ5MWZiMSJ9._cC2F37A53TabIsEI_7k3RY3ylXCsNSDuw2ysbA-9KQ&download=image.png "")

![](https://tcs.teambition.net/storage/31217e996b506f0cd324f9859009da3cedb2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3ZTk5NmI1MDZmMGNkMzI0Zjk4NTkwMDlkYTNjZWRiMiJ9.OHHyrvBmc1IG7yIVh7X0T15_0dDYWK-JqbYuJdUC3qk&download=image.png "")

![](https://tcs.teambition.net/storage/3121cdbf4080058a1fdb319304dd6c256a20?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjZGJmNDA4MDA1OGExZmRiMzE5MzA0ZGQ2YzI1NmEyMCJ9.oEot1ctZcgePEfBOdt3vqomBxWSnlkjk3N8H2mHijok&download=image.png "")

![](https://tcs.teambition.net/storage/31211a3bb987dccbae966766f034d8f238b8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExYTNiYjk4N2RjY2JhZTk2Njc2NmYwMzRkOGYyMzhiOCJ9.mOVv2RCHMpeAUAipSKNmg_0UYeheiP_WA7Wjv4qjtec&download=image.png "")

![](https://tcs.teambition.net/storage/312158537d6ff1e8adffdcecbc4e598cb229?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1ODUzN2Q2ZmYxZThhZGZmZGNlY2JjNGU1OThjYjIyOSJ9.uDmpRVPOoOkJOurQuV-n7VoUYU1DRxnC6sD8tXI499Y&download=image.png "")

![](https://tcs.teambition.net/storage/3121bad893018706a975b9755871cbbfb2ad?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiYWQ4OTMwMTg3MDZhOTc1Yjk3NTU4NzFjYmJmYjJhZCJ9.Xzaw22gIfjXvydJd8hGJHWMCvx2ubQruG5QjmXyNqGg&download=image.png "")

![](https://tcs.teambition.net/storage/3121ec6ca965e0ace6edd3a3ce027e648698?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlYzZjYTk2NWUwYWNlNmVkZDNhM2NlMDI3ZTY0ODY5OCJ9.JRWE8iSMZ__-auER0irICBCQ_hJxFygWttcfKPORfMc&download=image.png "")

![](https://tcs.teambition.net/storage/3121f8b8a2ef30aef14edd6710c02d42d96b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmOGI4YTJlZjMwYWVmMTRlZGQ2NzEwYzAyZDQyZDk2YiJ9.ilddN77LcsZgbstfdbNRn28qcgnd81zqTR3KK_B5_48&download=image.png "")

```java
package com.imooc.item.service;

import com.imooc.item.pojo.Items;
import com.imooc.item.pojo.ItemsImg;
import com.imooc.item.pojo.ItemsParam;
import com.imooc.item.pojo.ItemsSpec;
import com.imooc.item.pojo.vo.CommentsLevelCountsVO;
import com.imooc.item.pojo.vo.ShopcartVO;
import com.imooc.pojo.PagedGridResult;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import java.util.List;

@RequestMapping("item-api")
public interface ItemService {

    /**
     * 根据商品id查询详情
     * @param itemId
     * @return
     */
    @GetMapping("item")
    public Items queryItemsById(@RequestParam("itemId") String itemId);

    /**
     * 根据商品id查询商品图片列表
     * @param itemId
     * @return
     */
    @GetMapping("itemImages")
    public List<ItemsImg> queryItemsImgList(@RequestParam("itemId") String itemId);

    /**
     * 根据商品id查询商品规格
     * @param itemId
     * @return
     */
    @GetMapping("itemSpecs")
    public List<ItemsSpec> queryItemsSpecList(@RequestParam("itemId") String itemId);

    /**
     * 根据商品id查询商品参数
     * @param itemId
     * @return
     */
    @GetMapping("itemParam")
    public ItemsParam queryItemsParam(@RequestParam("itemId") String itemId);


    /**
     * 根据商品id查询商品的评价等级数量
     * @param itemId
     * @return
     */
    @GetMapping("countComments")
    public CommentsLevelCountsVO queryCommentsCounts(@RequestParam("itemId") String itemId);

    /**
     * 根据商品id查询商品的评价（分页）
     * @param itemId
     * @param level
     * @return
     */
    @GetMapping("pagedComments")
    public PagedGridResult queryPagedComments(@RequestParam("itemId") String itemId,
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
    @GetMapping("getCartBySpecIds")
    public List<ShopcartVO> queryItemsBySpecIds(@RequestParam("specIds") String specIds);

    /**
     * 根据商品规格id获取规格对象的具体信息
     * @param specId
     * @return
     */
    @GetMapping("singleItemSpec")
    public ItemsSpec queryItemsSpecById(@RequestParam("specId") String specId);

    /**
     * 根据商品id获得商品图片主图url
     * @param itemId
     * @return
     */
    @GetMapping("primaryImage")
    public String queryItemMainImgById(@RequestParam("itemId") String itemId);

    /**
     * 减少库存
     * @param specId
     * @param buyCounts
     */
    @PostMapping("decreaseStock")
    public void decreaseItemSpecStock(@RequestParam("specId") String specId,
                                      @RequestParam("buyCounts") int buyCounts);

}

```

## 复制

```java
/**
 * 我的评价查询 分页
 * @param userId
 * @param page
 * @param pageSize
 * @return
 */
public PagedGridResult queryMyComments(String userId,Integer page,Integer pageSize);

```

![](https://tcs.teambition.net/storage/3121dee7ac489b2d7896b7c4966702d0a430?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkZWU3YWM0ODliMmQ3ODk2YjdjNDk2NjcwMmQwYTQzMCJ9.3MQwF9_RbHBCBIWcYKslsLhliObB0NKq-a4NU_oNdME&download=image.png "")

![](https://tcs.teambition.net/storage/3121c3e0c529082a683a986e1ba8a3f65049?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjM2UwYzUyOTA4MmE2ODNhOTg2ZTFiYThhM2Y2NTA0OSJ9.-txWbY_DPYiXE45KBE53W4ApYAjh7ZYsDUaI-InuaRc&download=image.png "")

```java
package com.imooc.item.service;

import com.imooc.pojo.PagedGridResult;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

@RequestMapping("item-comments-api")
public interface ItemCommentsService {


    /**
     * 我的评价查询 分页
     * @param userId
     * @param page
     * @param pageSize
     * @return
     */
    @GetMapping("myComments")
    public PagedGridResult queryMyComments(@RequestParam("userId") String userId,
                                           @RequestParam(value = "page",required = false) Integer page,
                                           @RequestParam(value = "pageSize",required = false) Integer pageSize);

}

```

![](https://tcs.teambition.net/storage/3121b5420530cff01ee84658e73df719fd6c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiNTQyMDUzMGNmZjAxZWU4NDY1OGU3M2RmNzE5ZmQ2YyJ9.VagnuJMs0BbapwyzogoVYfvlOvDC6J9eikw8-yDN7io&download=image.png "")

```java
package com.imooc.item.service;

import com.imooc.pojo.PagedGridResult;
import org.springframework.web.bind.annotation.*;

import java.util.Map;

@RequestMapping("item-comments-api")
public interface ItemCommentsService {


    /**
     * 我的评价查询 分页
     * @param userId
     * @param page
     * @param pageSize
     * @return
     */
    @GetMapping("myComments")
    public PagedGridResult queryMyComments(@RequestParam("userId") String userId,
                                           @RequestParam(value = "page",required = false) Integer page,
                                           @RequestParam(value = "pageSize",required = false) Integer pageSize);

    /**
     * 会被订单中心调用
     * 看订单中心的源代码
     * @param map
     */
    @PostMapping("saveComments")
    public void saveComments(@RequestBody Map<String, Object> map);
}

```

![](https://tcs.teambition.net/storage/3121d7db66c0ee35c668f0a6d777ce5597b2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkN2RiNjZjMGVlMzVjNjY4ZjBhNmQ3NzdjZTU1OTdiMiJ9.2sv1Cbb1UyvrVp5gO1HpdCFmZlpRv5zIPJ5S5LxQDyw&download=image.png "")

![](https://tcs.teambition.net/storage/3121ba332883fcf3db61e0e2f06379129db3?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiYTMzMjg4M2ZjZjNkYjYxZTBlMmYwNjM3OTEyOWRiMyJ9.4PkBiYbcuM4yhXhXt1YCY_HTYYLQI6q10idHODgmlME&download=image.png "")

![](https://tcs.teambition.net/storage/31217a9d62c758cfaaac69ab329ae3c67bea?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3YTlkNjJjNzU4Y2ZhYWFjNjlhYjMyOWFlM2M2N2JlYSJ9.-g5oOR_nQIxviBZsxTRoMOOPx9j1KnWB9cQXXqW7hLA&download=image.png "")

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

    <artifactId>foodie-item-service</artifactId>

    <dependencies>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-item-api</artifactId>
            <version>${project.version}</version>
        </dependency>
        <dependency>
            <groupId>${project.groupId}</groupId>
            <artifactId>foodie-item-mapper</artifactId>
            <version>${project.version}</version>
        </dependency>
    </dependencies>

</project>

```

## 复制

![](https://tcs.teambition.net/storage/3121dc7b55b003b6a428058492694f6b6719?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkYzdiNTViMDAzYjZhNDI4MDU4NDkyNjk0ZjZiNjcxOSJ9.1blr-IqLduRS-vPCEN3bNfm1ZSlBUNc6O8C_IEjugYk&download=image.png "")

![](https://tcs.teambition.net/storage/3121cb013f45bf97ae5884ae1d2820c5a93e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjYjAxM2Y0NWJmOTdhZTU4ODRhZTFkMjgyMGM1YTkzZSJ9.lCgkTu4koLR7Bs417cKd1k3MOjOzVz8jL8c4ag7pHMY&download=image.png "")

![](https://tcs.teambition.net/storage/31211bf92b2db7717bbd611534e6f009337e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExYmY5MmIyZGI3NzE3YmJkNjExNTM0ZTZmMDA5MzM3ZSJ9.pSAattLeXNeNKJpPxyggqP1i0rPxBtpu0cnnCHhDO1Q&download=image.png "")

![](https://tcs.teambition.net/storage/3121f0e4900718495082dacd5720ca55cca1?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmMGU0OTAwNzE4NDk1MDgyZGFjZDU3MjBjYTU1Y2NhMSJ9.4xScsvEMWU-pjy0wgeqJmQDHqYi3ZzlViLWUM59JfZ8&download=image.png "")

```xml
package com.imooc.item.mapper;

import com.imooc.item.pojo.Items;
import com.imooc.my.mapper.MyMapper;

public interface ItemsMapper extends MyMapper<Items> {
}
```

![](https://tcs.teambition.net/storage/3121b9fb46967892d94dcebd7fbf9df7f612?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiOWZiNDY5Njc4OTJkOTRkY2ViZDdmYmY5ZGY3ZjYxMiJ9.n2nIWten0qbjSW89kBvzdB-Z5So2xLNxheX8fqb4qHI&download=image.png "")

```java
package com.imooc.item.mapper;

import com.imooc.item.pojo.ItemsParam;
import com.imooc.my.mapper.MyMapper;

public interface ItemsParamMapper extends MyMapper<ItemsParam> {
}
```

![](https://tcs.teambition.net/storage/3121bfa5c2f1e9be4f05fb48a2b60f714117?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiZmE1YzJmMWU5YmU0ZjA1ZmI0OGEyYjYwZjcxNDExNyJ9.nfMH-yJu7uJi3Z6LLgIm6rg4ioQRBGEWGmMSgzzCJXA&download=image.png "")

## 注释掉

![](https://tcs.teambition.net/storage/3121e8530309f70dc7c01bfe9b325b4ae0d6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlODUzMDMwOWY3MGRjN2MwMWJmZTliMzI1YjRhZTBkNiJ9.NL-2jSC_7NzOEep7GMxL-rdkvGwq-1Bsnev3BrIUynQ&download=image.png "")

![](https://tcs.teambition.net/storage/312137174e32e3f3dd73787b2512995e2db6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzNzE3NGUzMmUzZjNkZDczNzg3YjI1MTI5OTVlMmRiNiJ9.k_yVBxa8490jBR_Jwj12p7FOrQbk4ZxoNCTK21nL-ps&download=image.png "")

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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjMzMCwiaWF0IjoxNjEyMTkxNTMwLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.HQlBQVwa1I0hj_b8ex4TDYvaRNXMaCcCYbGj8etolcM&download=image.png "")

