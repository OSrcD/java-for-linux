package com.itmuch.contentcenter;


import com.alibaba.csp.sentinel.annotation.SentinelResource;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Service;

@Service
@Slf4j
public class TestService {
    
    @SentinelResource("common")
    public String common(){
        log.info("common....");
        return "common";
    }

}
