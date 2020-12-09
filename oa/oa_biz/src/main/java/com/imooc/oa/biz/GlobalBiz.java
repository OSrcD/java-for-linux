package com.imooc.oa.biz;

import com.imooc.oa.entity.Employee;

public interface GlobalBiz {

    Employee login(String sn,String password);

    void changePassword(Employee employee);

}
