package com.imooc.tel;

public class SmartWatch implements INet,INetN{
    public static final int TEMP = 30;


    @Override
    public void network() {

    }

    @Override
    public void connection() {
        INet.super.connection();

        INet.stop();
//        INet.super.network();
    }


}
