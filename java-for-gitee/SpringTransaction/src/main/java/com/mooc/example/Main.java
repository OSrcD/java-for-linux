package com.mooc.example;

import com.mooc.service.XbeanService;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import static java.lang.System.out;

public class Main {
    public static void main(final String[] args) throws Exception {
        ApplicationContext ctx = new ClassPathXmlApplicationContext("/springContextExample.xml");//, MainBoot.class
        out.println(ctx);

        XbeanService xbeanService = (XbeanService)ctx.getBean("xbeanService");
       out.println( xbeanService.getXbean(123));
    }
}
