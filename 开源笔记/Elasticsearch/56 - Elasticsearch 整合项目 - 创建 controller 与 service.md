## 数据库是int

## ES是long

![](https://tcs.teambition.net/storage/31215c3bc30bd6c9315182ef454d5f657b13?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzQyMiwiaWF0IjoxNjEwMjA4NjIyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1YzNiYzMwYmQ2YzkzMTUxODJlZjQ1NGQ1ZjY1N2IxMyJ9.V7QxbDIyxll5jymX0D_V-R0691VWOVd3D0N_HIJ1QkQ&download=image.png "")

```java
package com.imooc.es.pojo;

import org.springframework.data.annotation.Id;
import org.springframework.data.elasticsearch.annotations.Document;
import org.springframework.data.elasticsearch.annotations.Field;
import org.springframework.data.elasticsearch.annotations.FieldType;

@Document(indexName = "foodie-items-ik", type = "_doc", createIndex = false)
public class Items {

    @Id
    @Field(store = true, type = FieldType.Text, index = false)
    private String itemId;

    @Field(store = true, type = FieldType.Text, index = true)
    private String itemName;

    @Field(store = true, type = FieldType.Text, index = false)
    private String imgUrl;

    @Field(store = true, type = FieldType.Integer)
    private Integer price;

    @Field(store = true, type = FieldType.Integer)
    private Integer sellCounts;

    public String getItemId() {
        return itemId;
    }

    public void setItemId(String itemId) {
        this.itemId = itemId;
    }

    public String getItemName() {
        return itemName;
    }

    public void setItemName(String itemName) {
        this.itemName = itemName;
    }

    public String getImgUrl() {
        return imgUrl;
    }

    public void setImgUrl(String imgUrl) {
        this.imgUrl = imgUrl;
    }

    public Integer getPrice() {
        return price;
    }

    public void setPrice(Integer price) {
        this.price = price;
    }

    public Integer getSellCounts() {
        return sellCounts;
    }

    public void setSellCounts(Integer sellCounts) {
        this.sellCounts = sellCounts;
    }

    @Override
    public String toString() {
        return "Items{" +
                "itemId='" + itemId + '\'' +
                ", itemName='" + itemName + '\'' +
                ", imgUrl='" + imgUrl + '\'' +
                ", price=" + price +
                ", sellCounts=" + sellCounts +
                '}';
    }
}



```

![](https://tcs.teambition.net/storage/3121f00dfce768193906a65996b91dfde74c?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzQyMiwiaWF0IjoxNjEwMjA4NjIyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmMDBkZmNlNzY4MTkzOTA2YTY1OTk2YjkxZGZkZTc0YyJ9.Qkg_xhAZsO4xueUHQvKUz8LMBxcCGbALbSNqijN6Q30&download=image.png "")

```java
package com.imooc.controller;

import com.imooc.service.ItemsESService;
import com.imooc.utils.IMOOCJSONResult;
import com.imooc.utils.PagedGridResult;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("items")
public class ItemsController {

    @Autowired
    private ItemsESService itemsESService;

    @GetMapping("/hello")
    public Object hello() {
        return "Hello Elasticsearch~";
    }

    @GetMapping("/es/search")
    public IMOOCJSONResult search(
            String keywords,
            String sort,
            Integer page,
            Integer pageSize) {

        if (StringUtils.isBlank(keywords)) {
            return IMOOCJSONResult.errorMsg(null);
        }

        if (page == null) {
            page = 1;
        }

        if (pageSize == null) {
            pageSize = 20;
        }

        page --;

        PagedGridResult grid = itemsESService.searchItems(keywords,
                sort,
                page,
                pageSize);

        return IMOOCJSONResult.ok(grid);
    }

}


```

![](https://tcs.teambition.net/storage/312191e48279796c61b9a3263d3254a113f7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzQyMiwiaWF0IjoxNjEwMjA4NjIyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5MWU0ODI3OTc5NmM2MWI5YTMyNjNkMzI1NGExMTNmNyJ9.rB1ULBjASpwL9JVIwcuu7DDO2yWA3ZgVNVRP6aD0bMQ&download=image.png "")

```java
package com.imooc.service;

import com.imooc.utils.PagedGridResult;

public interface ItemsESService {

    public PagedGridResult searchItems(String keyword,
                                       String sort,
                                       Integer page,
                                       Integer pageSize);

}


```

![](https://tcs.teambition.net/storage/31218c1f089d669f9d2a41badfecad64675d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzQyMiwiaWF0IjoxNjEwMjA4NjIyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4YzFmMDg5ZDY2OWY5ZDJhNDFiYWRmZWNhZDY0Njc1ZCJ9.XRx-IkRp04R3eOiqBmIaUglj9-L_6ldII7hRpuq92xU&download=image.png "")

```java
package com.imooc.service.impl;

import com.imooc.service.ItemsESService;
import com.imooc.utils.PagedGridResult;

public class ItemsESServiceImpl implements ItemsESService {
    @Override
    public PagedGridResult searchItems(String keyword, String sort, Integer page, Integer pageSize) {
        return null;
    }
}


```



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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzQyMiwiaWF0IjoxNjEwMjA4NjIyLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.DECRRUSlFYcP2amwJnBZA2gUuSbOBCfENAacQHjZrcY&download=image.png "")

