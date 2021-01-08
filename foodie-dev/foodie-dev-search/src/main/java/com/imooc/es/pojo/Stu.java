package com.imooc.es.pojo;

import org.springframework.data.annotation.Id;
import org.springframework.data.elasticsearch.annotations.Document;
import org.springframework.data.elasticsearch.annotations.Field;
import org.springframework.data.elasticsearch.annotations.FieldType;

// 文档就是一个对象
@Document(indexName = "stu", type = "_doc", shards = 3, replicas = 0)
public class Stu {

    // spring boot 默认会生成与对象一样的值 _id 与 stuId 不写也可以 会自动随机生成
    @Id
    private Long stuId;

    // store 存储
    @Field(store = true)
    private String name;

    @Field(store = true)
    private Integer age;

    @Field(store = true, type = FieldType.Keyword)
    private String sign;

    @Field(store = true)
    private String description;

    @Field(store = true)
    private Float money;

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

    public Float getMoney() {
        return money;
    }

    public void setMoney(Float money) {
        this.money = money;
    }

    public Integer getAge() {
        return age;
    }

    public void setAge(Integer age) {
        this.age = age;
    }

    public String getSign() {
        return sign;
    }

    public void setSign(String sign) {
        this.sign = sign;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }
}
