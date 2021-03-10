package com.imooc.anonymous;



public class peopleTest {
    public void getRead(Person person){
        person.reat();
    }

    public static void main(String[] args) {
        peopleTest peopleTest1 = new peopleTest();
        peopleTest1.getRead(new Person(){


            {
                // 构造代码块
            }



            @Override
            public void reat(){
                System.out.println("男生喜欢看科幻类书籍");
            }
        });

        peopleTest1.getRead(new Person(){
            @Override
            public void reat(){
                System.out.println("女生喜欢看");
            }
        });
    }
}
