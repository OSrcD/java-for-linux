package com.imooc.service;

import com.imooc.pojo.Stu;
import org.springframework.stereotype.Service;


public interface StuService {

    public Stu getStuInfo(int id);

    public void saveStu();

    public void updateStu(int id);

    public void deleteStu(int id);


}
