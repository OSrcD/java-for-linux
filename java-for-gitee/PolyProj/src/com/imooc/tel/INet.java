package com.imooc.tel;

public interface INet {

    void network();

    public  class hear{
        public void test(){
            System.out.println(INet.TEMP);
            System.out.println("I'm test");
        }
    }




    default Object getMyClass(){
        class myClass{

        }

        return new myClass();
    }

    // public static final int TEMP = 20;
    int TEMP = 20;

    default void connection(){
        System.out.println("我是接口中的默认方法");

    }

    static void stop(){
        System.out.println("我是接口中的静态方法");
    }
}
