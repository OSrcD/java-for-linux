package jdbc;

import java.io.InputStream;
import java.sql.*;
import java.util.Properties;

public class jdbcUtil {

    public static void commit(Connection conn){
        if(null!=conn){
            try{
                conn.commit();
            }catch (SQLException e){
                e.printStackTrace();
            }
        }
    }


    public static void rollback(Connection conn){
        if(null !=conn){
            try{
                conn.rollback();
            }catch (SQLException e){
                e.printStackTrace();
            }
        }


    }

    public static void begin(Connection conn){
        if(null != conn){
            try{
                conn.setAutoCommit(false);
            }catch (SQLException e){
                e.printStackTrace();
            }
        }
    }

    public static Connection getConnection() throws Exception{
        Properties properties = new Properties();

        InputStream is = jdbcUtil.class.getClassLoader().getResourceAsStream("jdbc.properties");

        properties.load(is);

        String driver = properties.getProperty("driver");
        String username = properties.getProperty("username");
        String password = properties.getProperty("password");
        String url = properties.getProperty("jdbcUrl");
        Class.forName(driver);

        return DriverManager.getConnection(url,username,password);


    }


    public static void closeResources(Connection conn, Statement statement, ResultSet resultSet){
        if(null !=conn){
            try {
                conn.close();
            }catch (SQLException e){
                e.printStackTrace();
            }
        }
        if(null != statement){
            try {
                statement.close();
            }catch (SQLException e){
                e.printStackTrace();
            }
        }

        if(null != resultSet){
            try {
                resultSet.close();
            }catch(SQLException e){
                e.printStackTrace();
            }
        }
    }

}
