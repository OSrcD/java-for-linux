package com.github.houbb.markdown.toc;

import com.github.houbb.markdown.toc.constant.TocConstant;
import com.github.houbb.markdown.toc.core.impl.AtxMarkdownToc;

public class MardownTocMain {

    public static void main(String[] args) {
        TocConstant.DEFAULT_TOC_HEAD = "# 目录";
        AtxMarkdownToc.newInstance()
                .charset("UTF-8")
                .write(true)
                .subTree(true).
                genTocFile("java-alibaba-p7/阶段三：分布式架构-逐个击破分布式核心问题（9-17周）/第10周 分布式搜索引擎-Elasticsearch/276-mappings自定义创建映射/276-mappings自定义创建映射.md");
    }
}
