package com.imooc.animal;

public class ImplementsITest extends ImplementsITestSuper implements ITest,ITest2 {

    @Override
    public void network() {
        System.out.println("接口实现类的network");
        this.connection();
        ITest.super.connection();
    }

    @Override
    public void connection() {
        ITest.stop();


    }


}
