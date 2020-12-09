package com.ossit.selenium;

import com.ossit.excel.FindString;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;

import java.util.List;

public class DoubleRepeat {


    public static void doubleRepeat(WebDriver webDriver, String fileName) throws InterruptedException {

        //爬取题目

        List<WebElement> qtexts =  webDriver.findElements(By.className("qtext"));

        for(int i=0;i<qtexts.size();i++){
            WebElement qtext = qtexts.get(i);

            System.out.println("标题题目是：" + qtext.getText());
            String  changeQtext = qtext.getText();
            if(changeQtext.charAt(0)=='（'){
                changeQtext = changeQtext.substring(9,changeQtext.length());
            }

            //重复寻找答案
            StringBuilder result =  DoubleRepeat.doubleRepeatAnswer(fileName,changeQtext);

             String[] filtetString = result.toString().trim().split(";");

             for(String eachString : filtetString){

                 StringBuilder sbEeachString = new StringBuilder(eachString.trim());
                 //选择答案选项
                 DoubleRepeat.selectAnswer(webDriver,sbEeachString,i);

             }



        }



        webDriver.findElement(By.name("next")).click();










    }


    /**
     * 重复寻找答案
     */
    public static StringBuilder doubleRepeatAnswer(String fileName,String webTitle){
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

        return result;
    }


    /**
     * 选择答案选项
     * @param webDriver
     * @param result
     */

    public static void selectAnswer(WebDriver webDriver,StringBuilder result,int count){
        List<WebElement> answers = webDriver.findElements(By.className("answer"));

        WebElement answer = answers.get(count);


        List<WebElement>   labels =  answer.findElements(By.tagName("label"));

        for(WebElement label : labels){
            if(label.getText().contains(result.toString())){
               WebElement idIsFor =  webDriver.findElement(By.id(label.getAttribute("for")));
                System.out.println("idIsFor标签名 = "+idIsFor.getTagName());
                if(!idIsFor.isSelected()){
                    idIsFor.click();
                }
                break;
            }
        }

    }



}
