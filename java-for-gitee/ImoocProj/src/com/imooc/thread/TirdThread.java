package com.imooc.thread;

import java.util.concurrent.Callable;

public class TirdThread implements Callable<String> {

    @Override
    public String call() throws Exception{
        String str = "第三种创建方式的方式";
        return str;
    }


}
