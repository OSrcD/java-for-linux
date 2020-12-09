package com.imooc.oa.dao;

import com.imooc.oa.entity.Department;
import com.imooc.oa.entity.Employee;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository("employeeDao")
public interface EmployeeDao {
    void delete(String sn);
    void insert(Employee employee);
    void update(Employee employee);
    Employee select(String sn);
    List<Employee> selectAll();
}
