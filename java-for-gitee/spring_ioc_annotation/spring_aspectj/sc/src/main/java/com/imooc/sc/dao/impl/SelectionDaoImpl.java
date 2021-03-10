package com.imooc.sc.dao.impl;

import com.imooc.sc.dao.SelectionDao;
import com.imooc.sc.entity.Selection;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Repository;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

@Repository
public class SelectionDaoImpl implements SelectionDao {

    @Autowired
    private JdbcTemplate jdbcTemplate;

    public void insert(List<Selection> seles) {
        String sql = "insert into selection values(?,?,?,?)";
        List<Object[]> objects = new ArrayList<Object[]>();
        for (Selection selection : seles) {
            Object o [] = new Object[4];
            o[0] = selection.getSid();
            o[1] = selection.getCid();
            o[2] = selection.getSelTime();
            o[3] = selection.getScore();
            objects.add(o);
        }
        jdbcTemplate.batchUpdate(sql,objects);
    }

    public void delete(int sid, int cid) {
        String sql = "delete from selection where student=?,course=?";
        jdbcTemplate.update(sql,sid,cid);
    }

    public List<Map<String, Object>> selectByStudent(int sid) {
        String sql =
                "select se.*,s.name sname,c.name cname from selection se " +
                "left join student s on se.student=s.id " +
                "left join course c on se.course = c.id" +
                " where student = ?";
        return jdbcTemplate.queryForList(sql,sid);
    }

    public List<Map<String, Object>> selectByCourse(int cid) {

        String sql =
                "select se.*,cou.name cname,stu.name sname from selection se " +
                 "left join student stu on" +
                " se.student = stu.id left join course cou on se.course = cou.id" +
                " where course=?";
        return jdbcTemplate.queryForList(sql,cid);
    }
}
