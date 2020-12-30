package com.ossit;

import com.ossit.excel.FindString;
import com.ossit.selenium.DoubleRepeat;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;

import java.awt.*;
import java.awt.event.InputEvent;
import java.util.List;
import java.util.concurrent.TimeUnit;


public class CrackPhone
{
    public static void main( String[] args ) throws AWTException, InterruptedException {
        System.setProperty("webdriver.chrome.driver", "/Users/virtualman/IdeaProjects/AutoHomework/src/main/resource/chromedriver");

        WebDriver webDriver = new ChromeDriver();

        webDriver.manage().timeouts().implicitlyWait(30, TimeUnit.SECONDS);
        webDriver.get("http://whois.chinaz.com/reverse?ddlSearchMode=3");
        //用户名

        int j=1;
        int n=0;
        int count =0;
        int count2 =0;
        int num1=0;
        int first1=0;
        int first2=0;
        int first3=0;
        for(int i=0;i<=999;i++){
            count++;
            count2++;
            num1++;

            if(num1>=10){
                num1=0;
            }




            if(count==10){
                n++;
                count=0;
            }

            if(count2==100){
                j++;
                count2=0;
            }

            if(n>=10){
                n=0;
            }

            if(j>=10){
                j=0;
            }


            if((""+j+""+n+""+num1+""+"").equals("")){
                System.out.println("破解完成");
                break;
            }





            final WebElement username = webDriver.findElement(By.xpath("//*[@id=\"host\"]"));
            username.sendKeys(""+j+""+n+""+num1+""+"");


            final WebElement check = webDriver.findElement(By.xpath("//*[@id=\"search\"]"));
            check.click();

            final WebElement title = webDriver.findElement(By.xpath("//*[@id=\"ajaxInfo\"]/ul/li[2]"));
            if(!(title.getText().equals("暂无相关数据，请核对后再查询。"))){
                System.out.println("破解成功");
                break;
            }
        }




    } //else if
}










