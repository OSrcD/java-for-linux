package jdbc;

import java.sql.Connection;
import java.sql.PreparedStatement;

public class BatchTesOne {
    public static void main(String[] args) throws Exception {
        Connection conn = null;

        PreparedStatement preparedStatement = null;

        conn = jdbcUtil.getConnection();

        jdbcUtil.begin(conn);

        String sql = "insert into t_user(username,address) values(?,?)";

        preparedStatement = conn.prepareStatement(sql);

        long beginTime = System.currentTimeMillis();

        for (int i=0;i<10000;i++){
            preparedStatement.setString(1, "hello"+(i+1));
            preparedStatement.setString(2, "world"+(i+1));
            preparedStatement.executeUpdate();

        }
        jdbcUtil.commit(conn);

        long endTime = System.currentTimeMillis();

        System.out.println("total time:"+(endTime-beginTime));




    }
}
