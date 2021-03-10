package com.imooc.flow;

import java.sql.SQLOutput;
import java.util.Scanner;

public class WeekDemo01 {



    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int i = sc.nextInt();

        switch(i){
            case 1:
                System.out.println(i);break;
            case 2:
                System.out.println(i);break;
            case 3:
                System.out.println(i);break;
            case 5:
                System.out.println(i);break;
            case 6:
                System.out.println(i);break;
            case 7:
                System.out.println(i);break;
            default:
                System.out.println(i);break;
        }




        String s = sc.next();
        switch(s){
            case "q":
                System.out.println(s);
                break;
            case "w":
                System.out.println(s);
                System.out.println(s);break;
            default:
                System.out.println(s);break;

        }
        Color d;
        Color c = Color.BLUE; // Color BLUE = new Color();会进行各个静态成员属性实例化
        switch(c){
            case RED: // Color RED 被实例化过的静态常量对象;
                System.out.println("红色");
                break;
            case GREEN:
                System.out.println("绿色");
                break;
            case BLUE:
                System.out.println("蓝色");
                break;

        }


        for(Color color : Color.values()){ // Color.values() 父类Enum的静态方法
            System.out.println(color);
        }


        Color[] arr = Color.values();

        for (Color color : arr) {
            System.out.println(color.ordinal());
        }

        System.out.println(Color.valueOf("RED"));
        System.out.println("---------------------------------------------");
        Color c2 = Color.RED;
        c2.ColorInfo();

        if(true);{

        }


        while(i>5);
        {

        }

        do{

        }while(i>5);{

        };

    }

    enum Color{ // final class Color
        RED(),GREEN,BLUE; // public static final Color RED = new Color();

        private Color(){
            System.out.println(this.toString());
        }

        public void ColorInfo(){
            System.out.println("ColorInfo Method");
        }
    }



}
