package com.imooc.springcloud;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class Controller {

    /**
     * 依赖注入
     * 这种直接从外部的文件夹加载
     */
    @Value("${name}")
    private String name;

    /**
     * 这种是首先把外部的属性注入到自己项目中的配置文件
     * 再从配置文件中注入
     */
    @Value("${myWords}")
    private String words;

    @GetMapping("/name")
    public String getName() {
        return name;
    }

    @GetMapping("/words")
    public String getWords() {
        return words;
    }

}
