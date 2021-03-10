package com.imooc.sc.dao.impl;

import com.imooc.sc.dao.SelectionDao;
import com.imooc.sc.entiry.Selection;
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
        List<Object [] > list = new ArrayList<Object[]>();

        for(Selection sel:seles){
            Object [] args  = new Object[4];
            args[0] = sel.getSid();
            args[1] = sel.getCid();
            args[2] = sel.getSelTime();
            args[3] = sel.getScore();
            list.add(args);


        }
        jdbcTemplate.batchUpdate(sql,list);



    }

    public void delete(int sid,int cid) {
        String sql = "delete from selection where student=? and course=?";
        jdbcTemplate.update(sql, sid,cid);
    }

    public List<Map<String, Object>> selectByStudent(int sid) {
        String sql = "select se.*,stu.name sname,cou.name cname from selection " +
                "se left join student stu on se.student = stu.id " +
                "left join course cou on se.course = cou.id " +
                " where student = ?";
        return jdbcTemplate.queryForList(sql,sid);
    }

    public List<Map<String, Object>> selectByCourse(int cid) {
        String sql = "select se.*,stu.name sname,cou.name cname from selection " +
                "se left join student stu on se.student = stu.id " +
                "left join course cou on se.course = cou.id " +
                " where course = ?";
        return jdbcTemplate.queryForList(sql,cid);
    }
}
