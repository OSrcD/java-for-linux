package com.imooc.springcloud.hystrix;

import com.imooc.springcloud.Friend;
import com.imooc.springcloud.MyService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Component;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestParam;

/**
 * Fallback 针对MyService容错类
 */
@Slf4j
@Component
public class Fallback implements MyService {

    /**
     * 回调降级方法
     * @return
     */
    @Override
    public String error() {
        log.info("Fallback：I'm not a black sheep any more");
        return "Fallback：I'm not a black sheep any more";
    }

    @Override
    public String sayHi() {
        return null;
    }

    @Override
    public Friend sayHiPost(@RequestBody Friend friend) {
        return null;
    }

    @Override
    public String retry(@RequestParam(name="timeout") int timeout) {
        return "You are late !";
    }

}
