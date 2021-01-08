package com.test;

import com.imooc.Application;
import com.imooc.es.pojo.Stu;
import org.elasticsearch.action.index.IndexRequest;
import org.elasticsearch.action.search.SearchResponse;
import org.elasticsearch.index.query.QueryBuilders;
import org.elasticsearch.search.SearchHit;
import org.elasticsearch.search.SearchHits;
import org.elasticsearch.search.fetch.subphase.highlight.HighlightBuilder;
import org.elasticsearch.search.fetch.subphase.highlight.HighlightField;
import org.elasticsearch.search.sort.FieldSortBuilder;
import org.elasticsearch.search.sort.SortBuilder;
import org.elasticsearch.search.sort.SortOrder;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.data.domain.PageRequest;
import org.springframework.data.domain.Pageable;
import org.springframework.data.elasticsearch.core.ElasticsearchTemplate;
import org.springframework.data.elasticsearch.core.SearchResultMapper;
import org.springframework.data.elasticsearch.core.aggregation.AggregatedPage;
import org.springframework.data.elasticsearch.core.aggregation.impl.AggregatedPageImpl;
import org.springframework.data.elasticsearch.core.query.*;
import org.springframework.test.context.junit4.SpringRunner;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@RunWith(SpringRunner.class)
@SpringBootTest(classes = Application.class)
public class ESTest {

    @Autowired
    private ElasticsearchTemplate elasticsearchTemplate;

    /**
     * 不建议使用 ElasticsearchTemplate 对索引进行管理（创建索引，更新索引，删除索引）
     * 索引就像是数据库或者数据库中的表，我们平时是不会通过Java代码频繁的去创建修改删除数据库或者表的
     * 我们只会针对数据做CRUD的操作
     * 在es中也是同理，我们尽量使用 ElasticsearchTemplate 对文档数据做CRUD的操作
     * 1. 属性（FieldType）类型不灵活
     * 2. 主分片与副本分片数无法设置
     */
    @Test
    public void createIndexStu() {

        // 第一次会先创建索引 第二次以后只会新增数据
        Stu stu = new Stu();
        stu.setStuId(1003L);
        stu.setName("spider man");
        stu.setAge(28);
        stu.setMoney(99.8f);
        stu.setSign("i am super woman's husband");
        stu.setDescription("save world");
        // spring boot 会自动帮我们创建IndexQuery 只要把对象传入进行就行了
        IndexQuery indexQuery = new IndexQueryBuilder().withObject(stu).build();
        // 创建索引
        elasticsearchTemplate.index(indexQuery);

    }

    @Test
    public void deleteIndexStu() {
        elasticsearchTemplate.deleteIndex(Stu.class);
    }

    @Test
    public void updateStuDoc() {

        // 构建元数据
        Map<String, Object> sourceMap = new HashMap<>();
        sourceMap.put("sign", "I am not super man");
        sourceMap.put("money", 88.6f);
        sourceMap.put("age", "33");

        // 构建请求
        IndexRequest indexRequest = new IndexRequest();
        indexRequest.source(sourceMap);


        UpdateQuery updateQuery = new UpdateQueryBuilder()
                .withClass(Stu.class) // 2. 使用Stu类型
                .withId("1003") // 1.先找到Id
                .withIndexRequest(indexRequest) // 3.请求
                .build(); // 4.构建UpdateQuery

        // update stu set sign='abc',age=33,money=88.6 where docId='1002'
        elasticsearchTemplate.update(updateQuery);
    }


    @Test
    public void getStuDoc() {
        GetQuery getQuery = new GetQuery();
        getQuery.setId("1003");
        Stu stu = elasticsearchTemplate.queryForObject(getQuery, Stu.class);
        System.out.println(stu);
    }

    @Test
    public void deleteStuDoc() {
        elasticsearchTemplate.delete(Stu.class, "1003");
    }


    @Test
    public void searchStuDoc() {

        Pageable pageable = PageRequest.of(0, 2);

        SearchQuery query = new NativeSearchQueryBuilder()
                .withQuery(QueryBuilders.matchQuery("description", "save man"))
                .withPageable(pageable)
                .build();
        AggregatedPage<Stu> pagedStu = elasticsearchTemplate.queryForPage(query, Stu.class);
        System.out.println("检索后的总分页数目为：" + pagedStu.getTotalPages());
        List<Stu> stuList = pagedStu.getContent();
        for (Stu s : stuList) {
            System.out.println(s);
        }

    }

    @Test
    public void highlightStuDoc() {

        String preTag = "<font color='red'>";
        String postTag = "</font>";

        Pageable pageable = PageRequest.of(0, 10);

        SortBuilder sortBuilder = new FieldSortBuilder("money")
                .order(SortOrder.DESC);
        SortBuilder sortBuilderAge = new FieldSortBuilder("age")
                .order(SortOrder.ASC);

        SearchQuery query = new NativeSearchQueryBuilder()
                .withQuery(QueryBuilders.matchQuery("description", "save man"))
                .withHighlightFields(new HighlightBuilder.Field("description")
                        .preTags(preTag)
                        .postTags(postTag))
                .withSort(sortBuilder)
                .withSort(sortBuilderAge)
                .withPageable(pageable)
                .build();
        AggregatedPage<Stu> pagedStu = elasticsearchTemplate.queryForPage(query, Stu.class, new SearchResultMapper() {
            @Override
            public <T> AggregatedPage<T> mapResults(SearchResponse response, Class<T> clazz, Pageable pageable) {

                List<Stu> stuListHighlight = new ArrayList<>();

                SearchHits hits = response.getHits();
                for (SearchHit h : hits) {
                    HighlightField highlightField = h.getHighlightFields().get("description");
                    String description = highlightField.getFragments()[0].toString();

                    Object stuId = (Object)h.getSourceAsMap().get("stuId");
                    String name = (String)h.getSourceAsMap().get("name");
                    Integer age = (Integer)h.getSourceAsMap().get("age");
                    String sign = (String)h.getSourceAsMap().get("sign");
                    Object money = (Object)h.getSourceAsMap().get("money");

                    Stu stuHL = new Stu();
                    stuHL.setDescription(description);
                    stuHL.setStuId(Long.valueOf(stuId.toString()));
                    stuHL.setName(name);
                    stuHL.setAge(age);
                    stuHL.setSign(sign);
                    stuHL.setMoney(Float.valueOf(money.toString()));

                    stuListHighlight.add(stuHL);
                }

                if (stuListHighlight.size() > 0) {
                    return new AggregatedPageImpl<>((List<T>)stuListHighlight);
                }

                return null;
            }
        });
        System.out.println("检索后的总分页数目为：" + pagedStu.getTotalPages());
        List<Stu> stuList = pagedStu.getContent();
        for (Stu s : stuList) {
            System.out.println(s);
        }

    }


}
