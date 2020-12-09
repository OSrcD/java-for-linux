package com.ossit.selenium;


import com.ossit.excel.FindString;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;

import java.util.List;
import java.util.concurrent.TimeUnit;

public class AutoHomework {



    public static void main(String[] args) throws InterruptedException {
        String fileName = "/Users/virtualman/IdeaProjects/AutoHomework/src/main/resource/互联网营销（专20春）-第一次测验-参考答案.xlsx";


        System.setProperty("webdriver.chrome.driver", "/Users/virtualman/IdeaProjects/AutoHomework/src/main/resource/chromedriver");

        WebDriver webDriver = new ChromeDriver();

        webDriver.manage().timeouts().implicitlyWait(30, TimeUnit.SECONDS);
        webDriver.get("http://course.ougd.cn/login/index.php");
        //用户名
        final WebElement  username = webDriver.findElement(By.xpath("//*[@id=\"username\"]"));
                                                                                                                                                        username.sendKeys("18160001450873");


        //密码
         final WebElement password = webDriver.findElement(By.xpath("//*[@id=\"password\"]"));


                                                                                                                                                  password.sendKeys("19911228");
         //记住密码
        webDriver.findElement(By.xpath("//*[@id=\"rememberusername\"]")).click();


        //登录

        webDriver.findElement(By.xpath("//*[@id=\"loginbtn\"]")).click();

        webDriver.findElement(By.xpath("//*[@id=\"nav-drawer\"]/nav/a[22]/div/div/span[2]")).click();
        webDriver.findElement(By.xpath("//*[@id=\"region-main\"]/div/div/ul/li[2]/ul/li[4]/a/div/span")).click();
        webDriver.findElement(By.xpath("//*[@id=\"module-236409\"]/div/div/div[2]/div/a/span")).click();
        //*[@id="module-236467"]/div/div/div[2]/div/a/span
        //*[@id="module-236426"]/div/div/div[2]/div/a/span
         List<WebElement> element = webDriver.findElements(By.className("btn-secondary"));

         for(WebElement wd : element){

             if(wd.getText().equals("再次尝试此测验")){
                 wd.click();
                 webDriver.findElement(By.xpath("//*[@id=\"id_submitbutton\"]")).click();
             }else if(wd.getText().equals("继续上次答题")){
                 wd.click();


                 while(webDriver.findElement(By.name("next")).getAttribute("value").equals("下一页")
                 || webDriver.findElement(By.name("next")).getAttribute("value").equals("结束答题…")){

                     DoubleRepeat.doubleRepeat(webDriver, fileName);

                 }



             } //else if
         }




    }
}
