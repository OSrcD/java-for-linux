package com.itmuch.contentcenter.sentineltest;

import com.alibaba.csp.sentinel.adapter.servlet.callback.UrlCleaner;
import org.apache.commons.lang.math.NumberUtils;
import org.springframework.stereotype.Component;

import java.util.Arrays;

@Component
public class MyUrlCleaner implements UrlCleaner {

    @Override
    public String clean(String s) {

        String[] split = s.split("/");
        return Arrays.stream(split)
                .map(string ->{
                    if(NumberUtils.isNumber(string)){
                        return "{number}";
                    }
                        return string;


                })
                .reduce((a,b) -> a+"/"+b)
                .orElse("");


    }
}
