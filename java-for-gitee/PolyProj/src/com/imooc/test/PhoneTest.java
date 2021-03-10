package com.imooc.test;

import com.imooc.tel.FourthPhone;
import com.imooc.tel.INet;
import com.imooc.tel.SmartWatch;

public class PhoneTest {

    public static void main(String[] args) {
        FourthPhone phone = new FourthPhone();
        phone.call();
        phone.message();
        phone.vedio();
        phone.music();
        phone.photo();
        phone.network();

        System.out.println("====================");
        System.out.println(INet.TEMP);
        INet net = new SmartWatch();
        System.out.println(net.TEMP); // 接口静态属性
        INet.hear heat1 = new INet.hear();
        heat1.test();

        new INet(){

            @Override
            public void network() {

            }

            @Override
            public Object getMyClass() {
                return null;
            }

            @Override
            public void connection() {

            }
        }.connection();

    }
}
