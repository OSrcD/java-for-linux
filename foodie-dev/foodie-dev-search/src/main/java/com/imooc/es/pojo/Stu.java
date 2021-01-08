package com.imooc.es.pojo;

import org.springframework.data.annotation.Id;
import org.springframework.data.elasticsearch.annotations.Document;
import org.springframework.data.elasticsearch.annotations.Field;

// 文档就是一个对象
@Document(indexName = "stu", type = "_doc")
public class Stu {

    // spring boot 默认会生成与对象一样的值 _id 与 stuId 不写也可以 会自动随机生成
    @Id
    private Long stuId;

    // store 存储
    @Field(store = true)
    private String name;

    @Field(store = true)
    private Integer age;

    public Long getStuId() {
        return stuId;
    }

    public void setStuId(Long stuId) {
        this.stuId = stuId;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Integer getAge() {
        return age;
    }

    public void setAge(Integer age) {
        this.age = age;
    }
}
