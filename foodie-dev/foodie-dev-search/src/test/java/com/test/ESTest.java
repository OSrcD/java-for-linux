package com.test;

import com.imooc.Application;
import com.imooc.es.pojo.Stu;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.data.elasticsearch.core.ElasticsearchTemplate;
import org.springframework.data.elasticsearch.core.query.IndexQuery;
import org.springframework.data.elasticsearch.core.query.IndexQueryBuilder;
import org.springframework.test.context.junit4.SpringRunner;

@RunWith(SpringRunner.class)
@SpringBootTest(classes = Application.class)
public class ESTest {

    @Autowired
    private ElasticsearchTemplate elasticsearchTemplate;

    @Test
    public void createIndexStu() {

        // 第一次会先创建索引 第二次以后只会新增数据
        Stu stu = new Stu();
        stu.setStuId(1002L);
        stu.setName("spider man");
        stu.setAge(22);

        // spring boot 会自动帮我们创建IndexQuery 只要把对象传入进行就行了
        IndexQuery indexQuery = new IndexQueryBuilder().withObject(stu).build();
        // 创建索引
        elasticsearchTemplate.index(indexQuery);

    }
}
