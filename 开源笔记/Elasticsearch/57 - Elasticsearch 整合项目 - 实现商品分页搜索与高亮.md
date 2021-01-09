![](https://tcs.teambition.net/storage/3121294878e14f49c0286124ea8597e01d50?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzQyOSwiaWF0IjoxNjEwMjA4NjI5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyOTQ4NzhlMTRmNDljMDI4NjEyNGVhODU5N2UwMWQ1MCJ9.6VH2-KlVst6P0fxhj1D2Rlb5ha4cEQApL3sTINiEjyE&download=image.png "")



![](https://tcs.teambition.net/storage/3121f912c752c8ecae809c42c3ff06cdf4ba?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzQyOSwiaWF0IjoxNjEwMjA4NjI5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmOTEyYzc1MmM4ZWNhZTgwOWM0MmMzZmYwNmNkZjRiYSJ9.4jTJw3sLh4PbXUIn2KRgSVySq9fmZl7jV5PKCHbJ0o4&download=image.png "")

## 分页信息

## 总的命中的一个数量

## Rows Content

## 每页所展示的数据 每页有多少条数据查询出来 每分1页有多少条数据

## page

## 当前是第几页

## total totalPage 总的页数

## records totalElements 总的记录数

## 每页20条数据 总页数4 总记录数是61

![](https://tcs.teambition.net/storage/31219f86f6aa1b68f149e5e65b788bf88028?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzQyOSwiaWF0IjoxNjEwMjA4NjI5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5Zjg2ZjZhYTFiNjhmMTQ5ZTVlNjViNzg4YmY4ODAyOCJ9.VkDAT5mimo3mKy3JrHn4nexV5VkYWC5sZtzX1NYBeX4&download=image.png "")

```java
package com.imooc.service.impl;

import com.imooc.es.pojo.Items;
import com.imooc.es.pojo.Stu;
import com.imooc.service.ItemsESService;
import com.imooc.utils.PagedGridResult;
import org.elasticsearch.action.search.SearchResponse;
import org.elasticsearch.index.query.QueryBuilders;
import org.elasticsearch.search.SearchHit;
import org.elasticsearch.search.SearchHits;
import org.elasticsearch.search.fetch.subphase.highlight.HighlightBuilder;
import org.elasticsearch.search.fetch.subphase.highlight.HighlightField;
import org.elasticsearch.search.sort.FieldSortBuilder;
import org.elasticsearch.search.sort.SortBuilder;
import org.elasticsearch.search.sort.SortOrder;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.domain.PageRequest;
import org.springframework.data.domain.Pageable;
import org.springframework.data.elasticsearch.core.ElasticsearchTemplate;
import org.springframework.data.elasticsearch.core.SearchResultMapper;
import org.springframework.data.elasticsearch.core.aggregation.AggregatedPage;
import org.springframework.data.elasticsearch.core.aggregation.impl.AggregatedPageImpl;
import org.springframework.data.elasticsearch.core.query.NativeSearchQueryBuilder;
import org.springframework.data.elasticsearch.core.query.SearchQuery;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

@Service
public class ItemsESServiceImpl implements ItemsESService {

    @Autowired
    private ElasticsearchTemplate esTemplate;

    @Override
    public PagedGridResult searchItems(String keywords, String sort, Integer page, Integer pageSize) {

        String preTag = "<font color='red'>";
        String postTag = "</font>";

        Pageable pageable = PageRequest.of(page, pageSize);


        String itemNameFiled = "itemName";

        SearchQuery query = new NativeSearchQueryBuilder()
                .withQuery(QueryBuilders.matchQuery(itemNameFiled, keywords))
                .withHighlightFields(new HighlightBuilder.Field(itemNameFiled)
                        .preTags(preTag)
                        .postTags(postTag)
                )
                .withPageable(pageable)
                .build();
        AggregatedPage<Items> pagedItems = esTemplate.queryForPage(query, Items.class, new SearchResultMapper() {
            @Override
            public <T> AggregatedPage<T> mapResults(SearchResponse response, Class<T> clazz, Pageable pageable) {

                List<Items> itemHighLightList = new ArrayList<>();

                SearchHits hits = response.getHits();
                for (SearchHit h : hits) {
                    HighlightField highlightField = h.getHighlightFields().get(itemNameFiled);
                    String itemName = highlightField.getFragments()[0].toString();

                    String itemId = (String)h.getSourceAsMap().get("itemId");
                    String imgUrl = (String)h.getSourceAsMap().get("imgUrl");
                    Integer price = (Integer)h.getSourceAsMap().get("price");
                    Integer sellCounts = (Integer)h.getSourceAsMap().get("sellCounts");

                    Items item = new Items();
                    item.setItemId(itemId);
                    item.setItemName(itemName);
                    item.setImgUrl(imgUrl);
                    item.setPrice(price);
                    item.setSellCounts(sellCounts);

                    itemHighLightList.add(item);
                }

                return new AggregatedPageImpl<>((List<T>)itemHighLightList,
                        pageable,
                        response.getHits().totalHits);
            }
        });
//        System.out.println("检索后的总分页数目为：" + pagedStu.getTotalPages());
//        List<Stu> stuList = pagedStu.getContent();
//        for (Stu s : stuList) {
//            System.out.println(s);
//        }

        PagedGridResult gridResult = new PagedGridResult();
        gridResult.setRows(pagedItems.getContent());
        gridResult.setPage(page + 1);
        gridResult.setTotal(pagedItems.getTotalPages());
        gridResult.setRecords(pagedItems.getTotalElements());

        return gridResult;
    }


}


```

![](https://tcs.teambition.net/storage/31216d12bc6f3f6b7c9be0c768d5f46b82bf?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzQyOSwiaWF0IjoxNjEwMjA4NjI5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2ZDEyYmM2ZjNmNmI3YzliZTBjNzY4ZDVmNDZiODJiZiJ9.Ctxtct5G-C_x7Y7oDF5urLipAD4EAxtXtJf8-G0mu1s&download=image.png "")

![](https://tcs.teambition.net/storage/3121b2cf38fd09f2e377259b5fa0bfc32b7e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzQyOSwiaWF0IjoxNjEwMjA4NjI5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiMmNmMzhmZDA5ZjJlMzc3MjU5YjVmYTBiZmMzMmI3ZSJ9.B262r5wIpsS83Q6G4oIoN85tn_cxYbASvM4mjXccH8I&download=image.png "")

 





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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDgxMzQyOSwiaWF0IjoxNjEwMjA4NjI5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.r08IbTJSdyRgHlrFEQF3WglgCtlG_Hsedr8tgR7PXcw&download=image.png "")

