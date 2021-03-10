import com.imooc.sc.entity.Student;
import org.reactivestreams.Subscription;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.RowMapper;
import reactor.core.publisher.Flux;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.time.Duration;
import java.util.*;
import java.util.function.Consumer;

public class Test<T> {



    private JdbcTemplate jdbcTemplate;

    {
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("spring.xml");

        jdbcTemplate = (JdbcTemplate)applicationContext.getBean("jdbcTemplate");

    }

    public void testExecute(){
        jdbcTemplate.execute("create table user1(id int,name varchar(20))");

    }


    public void testUpdate(){
        String sql = "Insert into student(name,sex)values(?,?)";
        jdbcTemplate.update(sql,new Object[]{"张飞","男"});
    }


    public void testUpdate2(){
        String sql = "update student set sex=? where id=?";
        jdbcTemplate.update(sql,"女","1");
    }

    @org.junit.Test
    public void testBatchUpdate(){
        String[] sql ={
                "insert into student(name,sex)values('关羽','女')",
                "insert into student(name,sex)values('刘备','男')",
                "update student set sex='男' where id=1"
        };
        jdbcTemplate.batchUpdate(sql);

    }

    @org.junit.Test
    public void testBatchUpdate2(){
        String sql = "insert into selection(student,course)values(?,?)";
        List<Object[]> list = new ArrayList <Object[]> ();
        list.add(new Object[]{1,1001});
        list.add(new Object[]{1,1003});
        jdbcTemplate.batchUpdate(sql,list);

    }

    @org.junit.Test
    public void testQuerySimple1(){
        String sql = "select count(*) from student";
        int i = jdbcTemplate.queryForObject(sql, Integer.class);

        System.out.println(i);
    }

    @org.junit.Test
    public void testQuerySimple2(){
        String sql = "select name from student where sex=?";
        List<String> list = jdbcTemplate.queryForList(sql,String.class,"男");
        System.out.println(list);
    }

    @org.junit.Test
    public void testQueryMap1(){
        String sql = "select * from student where id=?";
        Map<String,Object> map = jdbcTemplate.queryForMap(sql,1);
        System.out.println(map);
    }

    @org.junit.Test
    public void testQueryMap2(){
        String sql = "select * from student";
        List<Map<String,Object>> list = jdbcTemplate.queryForList(sql);
        System.out.println(list);
    }

    @org.junit.Test
    public void testQueryEntity1(){
        String sql = "select * from student where id=?";
        Student student = jdbcTemplate.queryForObject(sql,new StudentRowMapper(),1);

        System.out.println(student);

    }

    @org.junit.Test
    public void testQueryEntity2(){
        String sql = "select * from student";
        List<Student> list = jdbcTemplate.query(sql,new StudentRowMapper());

        System.out.println(list);

    }




    private class StudentRowMapper implements RowMapper<Student>{

        public Student mapRow(ResultSet resultSet, int i) throws SQLException {
            Student student = new Student();
            student.setId(resultSet.getInt("id"));
            student.setName(resultSet.getString("name"));
            student.setBorn(resultSet.getDate("born"));
            student.setSex(resultSet.getString("sex"));
            return student;
        }
    }




}
