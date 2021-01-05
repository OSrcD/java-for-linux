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
                genTocFile("/Users/virtualman/IdeaProjects/java-for-linux/README-GITEE.md");
    }
}
