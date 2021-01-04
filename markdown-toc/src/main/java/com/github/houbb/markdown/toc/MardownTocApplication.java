package com.github.houbb.markdown.toc;

import com.github.houbb.markdown.toc.constant.TocConstant;
import com.github.houbb.markdown.toc.core.impl.AtxMarkdownToc;

public class MardownTocApplication {

    public static void main(String[] args) {
        TocConstant.DEFAULT_TOC_HEAD = "# 目录";
        AtxMarkdownToc.newInstance()
                .charset("UTF-8")
                .write(true)
                .subTree(true).
                genTocFile("开源笔记/java-alibaba-p7/阶段三：分布式架构-逐个击破分布式核心问题（9-17周）/第10周 分布式搜索引擎-Elasticsearch/278-文档的基本操作 - 添加文档与自动映射.md");
    }
}
