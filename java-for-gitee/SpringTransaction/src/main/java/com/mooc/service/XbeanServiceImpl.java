package com.mooc.service;

import com.mooc.beans.Xbean;
import org.springframework.transaction.annotation.Transactional;

@Transactional
public class XbeanServiceImpl  implements XbeanService{
    @Override
    public Xbean getXbean(int id) {
        Xbean xb = new Xbean() ;
        xb.setName("业务Bean的ID="+id);
        xb.setName("Bean默认名称");
        return xb ;
    }

    @Override
    public void insertXbean(Xbean xb) {
        throw new UnsupportedOperationException();
    }
}
