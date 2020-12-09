package com.ossit.selenium;

import com.ossit.excel.FindString;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;

import java.util.List;

public class SingleRepeat {

    public static void singleRepeat(WebDriver webDriver, String fileName) throws InterruptedException {

        List<WebElement> spanElement =   webDriver.findElements(By.tagName("span"));
        boolean flag =false;
        for (WebElement webElement : spanElement) {
            System.out.print(webElement.getText());
            if(webElement.getText().equals("标记题目")){
                flag = true;
                continue;
            }


            if(flag){

                String webTitle = webElement.getText();

                if((webTitle.trim().equals("测验导航") ||
                        webTitle.trim().equals("）") ||
                        webTitle.trim().equals("（") ||
                        webTitle.trim().equals("《")
                )) {


                    List<WebElement> spanElement1 = webDriver.findElement(By.className("qtext"))
                            .findElement(By.tagName("p")).findElements(By.tagName("span"));

                    if (spanElement1.size() == 0) {
                        spanElement1 = webDriver.findElement(By.className("qtext")).findElements(By.tagName("p"));

                    }


                    for (WebElement tempelement : spanElement1) {
                        if (!(tempelement.getText().trim().equals("）") || tempelement.getText().trim().equals("（"))) {
                            webTitle = tempelement.getText().trim();
                        }
                    }


                    System.out.println(spanElement1.size());
                }
                System.out.println("spanElement1 = "+webTitle);


//                System.out.println(webTitle);
                StringBuilder result = FindString.findString(fileName,webTitle);
                System.out.println("答案："+result);

                if(result == null){
                    for(int i=1;i<webTitle.length();i++) {
                        System.out.println("i="+i);
                        String subTile = webTitle.substring(0,webTitle.length()-i);
                        System.out.println(subTile);
                        result = FindString.findString(fileName,subTile);
                        System.out.println(result);
                        if(result!=null){
                            break;
                        }
                    }

                }


                System.out.println("??????????");

                WebElement answer = webDriver.findElement(By.className("formulation"));

                List<WebElement> subAnswer =  answer.findElements(By.tagName("label"));
                List<WebElement> inputTag  = answer.findElements(By.tagName("input"));
                for(WebElement forSubAnswer : subAnswer){

                    if(forSubAnswer.getText().contains(result.toString())){
                        System.out.println(forSubAnswer.getText());
                        webDriver.findElement(By.id(forSubAnswer.getAttribute("for"))).click();
                        webDriver.findElement(By.name("next")).click();
                        break;
                    }


                }




                flag = false;
                break;
            }
        }//for

    }

}
