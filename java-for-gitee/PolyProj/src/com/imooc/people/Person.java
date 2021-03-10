package com.imooc.people;

public class Person {

//    public static int age=13;
//    static int i = 5;
//    public Heart getHeart(){
//        new Heart().temp = 12;
//        return new Heart();
//    }
//
//    public void eat(){
//        System.out.println("人会吃东西");
//    }

    public static int age;

    public void eat(){
        System.out.println("人会吃东西");
    }

    public Object getHeart(){

        class Heart{
            public final int age = 13;
            int temp = 22;

            public void say(){
                System.out.println("hello");
            }

            public void eat(){

            }

            public String beat(){
                new Person().eat();
                return Person.age + "岁的心脏在跳动";
            }
        }

        return new Heart().beat();
    }


//    class Heart{
//        int age = 13;
//        int temp = 12;
//        public void eat(){
//            System.out.println("heart类的eat方法");
//        }
//
//        public String beat(){
//            eat();
//            return i+"心脏正在跳动";
//        }
//    }

//     public static class Heart{
//        int temp = 12;
//        public static int age = 13;
//
//        public static void say(){
//            System.out.println("hello");
//        }
//
//        public String beat(){
//            new Person().eat();
//            System.out.println(i);
//            return Person.age + "岁的心脏在跳动";
//        }
//    }

}
