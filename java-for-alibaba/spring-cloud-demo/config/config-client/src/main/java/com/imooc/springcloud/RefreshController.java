package com.imooc.springcloud;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.cloud.context.config.annotation.RefreshScope;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/refresh")
/**
 * RefreshScope 从Config 端 重新拉取新的文件 创建一个新的实例 注入到所有上下游的依赖当中
 */
@RefreshScope
public class RefreshController {

    @Value("${words}")
    private String words;

    @GetMapping("/words")
    public String getWords() {
        return words;
    }
}
