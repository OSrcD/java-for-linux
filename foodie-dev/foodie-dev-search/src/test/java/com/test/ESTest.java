package com.test;

import com.imooc.Application;
import com.imooc.es.pojo.Stu;
import org.elasticsearch.action.index.IndexRequest;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.data.elasticsearch.core.ElasticsearchTemplate;
import org.springframework.data.elasticsearch.core.query.*;
import org.springframework.test.context.junit4.SpringRunner;

import java.util.HashMap;
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
        stu.setAge(22);
        stu.setMoney(15.5f);
        stu.setSign("i am spider man");
        stu.setDescription("I wish i am spider man");
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

}
