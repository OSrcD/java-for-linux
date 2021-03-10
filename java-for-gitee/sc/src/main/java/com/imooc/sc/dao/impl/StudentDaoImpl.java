package com.imooc.sc.dao.impl;

import com.imooc.sc.dao.StudentDao;
import com.imooc.sc.entiry.Student;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.RowMapper;
import org.springframework.stereotype.Repository;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.List;


@Repository
public class StudentDaoImpl implements StudentDao {

    @Autowired
    private JdbcTemplate jdbcTemplate;

    public void insert(Student stu) {
        String sql = "insert into student(name,sex,born) values(?,?,?)";
        jdbcTemplate.update(sql, stu.getName(),stu.getSex(),stu.getBorn());
    }

    public void update(Student stu) {
        String sql = "update student set name=?,sex=?,born=? where id = ?";
        jdbcTemplate.update(sql, stu.getName(),stu.getSex(),stu.getId());
    }

    public void delete(int id) {
        String sql = "delete from student where id=?";
        jdbcTemplate.update(sql, id);
    }

    public Student select(int id) {
        String sql = "select * from student where id=?";
        return jdbcTemplate.queryForObject(sql, new StudentRowMapper(),id);

    }

    public List<Student> selectAll() {
        String sql = "select * from student";
        return jdbcTemplate.query(sql,new StudentRowMapper());
    }



    private class StudentRowMapper implements RowMapper<Student>{
        public Student mapRow(ResultSet resultSet, int i) throws SQLException {
            Student stu = new Student();
            stu.setId(resultSet.getInt("id"));
            stu.setName(resultSet.getString("name"));
            stu.setSex(resultSet.getString("sex"));
            stu.setBorn(resultSet.getDate("born"));
            return stu;
        }
    }


}
