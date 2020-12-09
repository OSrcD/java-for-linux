package com.imooc.oa.dao;

import com.imooc.oa.entity.Department;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository("departmentDao")
public interface DepartmentDao {
     void delete(String sn);
     void update(Department department);
     void insert(Department department);
     Department select(String sn);
     List<Department> selectAll();
}
