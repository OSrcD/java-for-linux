package com.itmuch.contentcenter;

import lombok.ToString;
import org.springframework.web.client.RestTemplate;

public class SentinelTest {
    public static void main1(String[] args) throws InterruptedException {
        RestTemplate restTemplate = new RestTemplate();

        for(int i = 0;i < 10000;i++){
            String Object = restTemplate.getForObject("http://localhost:8010/actuator/sentinel",String.class);
            Thread.sleep(500);
        }
    }

    @Override
    public String toString(){
        return super.toString();
    }


    public static void main(String[] args) throws InterruptedException {
        RestTemplate restTemplate = new RestTemplate();


        for(int i = 0;i < 10000; i++){
            Object String = restTemplate.getForObject("http://localhost:8010/test-a",String.class);
            System.out.println("----- " + String + "-----");
        }
    }


}
