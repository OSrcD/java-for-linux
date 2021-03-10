package com.imooc.sc.dao.impl;

import com.imooc.sc.dao.CourseDao;
import com.imooc.sc.entiry.Course;
import com.imooc.sc.entiry.Student;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.RowMapper;
import org.springframework.stereotype.Repository;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.List;
@Repository
public class CourseDaoImpl implements CourseDao {
    @Autowired
    private JdbcTemplate jdbcTemplate;
    public void insert(Course course) {
        String sql = "insert into course(name,score) values(?,?)";
        jdbcTemplate.update(sql, course.getName(),course.getScore());

    }

    public void update(Course course) {
        String sql = "update course set name=?,score=? where id=?";
        jdbcTemplate.update(sql, course.getName(),course.getScore(),course.getId());
    }





    public void delete(int id) {
        String sql = "delete from course where id=?";
        jdbcTemplate.update(sql,id);

    }

    public Course select(int id) {
        String sql = "select * from course where id=?";
        return jdbcTemplate.queryForObject(sql,new CourseRowMapper(),id);
    }

    public List<Course> selectAll() {
        String sql = "select * from course";
        return jdbcTemplate.query(sql,new CourseRowMapper());
    }

    private class CourseRowMapper implements RowMapper<Course> {
        public Course mapRow(ResultSet resultSet, int i) throws SQLException {
            Course course = new Course();
            course.setId(resultSet.getInt("id"));
            course.setName(resultSet.getString("name"));
            course.setScore(resultSet.getInt("score"));
            return course;
        }
    }




}
