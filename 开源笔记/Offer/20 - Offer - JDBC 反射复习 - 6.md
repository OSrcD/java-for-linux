

JDBC

![](https://tcs.teambition.net/storage/3123741da77cbd060745e450b106cb2da1e9?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTk3OSwiaWF0IjoxNjE1NTQ3MTc5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM3NDFkYTc3Y2JkMDYwNzQ1ZTQ1MGIxMDZjYjJkYTFlOSJ9.YiriBnnRY7xfy6DCnHD0NnufUvJ674ZB8JxL0cXzm3o&download=image.png "")

@Test 

DriverManager.registerDrvier(new Driver()); # 注册驱动 会导致驱动注册 2 次

DriverManager.getConnection("jdbc:mysql:///数据库名",String,String) # 获取 Connection对象

connection.createStatement(); # 创建执行语句

connection.setAutoCommit(boolean)

connection.commit()

connection.rollback()

statement.executeQuery(String) # 执行 sql语句

statement.executeUpdate(String) # 执行插入sql语句 更新 删除

resultSet.next() # 是否有下一条数据

resultSet.getInt(String) # 以int获得字段值

resultSet.getString(String) # 以String 获得字段值

resultSet.close()

statement.close()

connection.close()

Class.forName("com.mysql.jdbc.Drvier") # 使用反射的形式注册 会去加载静态代码块



![](https://tcs.teambition.net/storage/31235c313bede7f141d44e2466a33ffd68d4?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTk3OSwiaWF0IjoxNjE1NTQ3MTc5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM1YzMxM2JlZGU3ZjE0MWQ0NGUyNDY2YTMzZmZkNjhkNCJ9.7iBy4jnKy1NUOq7uxa4qhXeOb9xS_9kk7pgnBCCYfNo&download=image.png "")

jdbc.properties 文件

driverClass=com.mysql.jdbc.Drvier

url=jdbc:mysql:///数据库名

username=root

password=toor

new Properties();

src 的文件会在classpath路径之下



获得类加载器 以流的形式获取资源 返回InputStream

类.class.getClassLoader().getResourceAsStream("jdbc.properties")

properties.load(InputStream)

properties.getProperty(String)



sql 注入

or 1=1

--

sql 占位符 ?

connection.prepareStatement(String)

preparedStatement.setString(int,String)

preparedStatement.setInt(int,int)

preparedStatement.setObject(int,Object)

preparedStatement.executeQuery()

preparedStatement.executeUpdate() # 增删改

preparedStatement.close()



c3p0 连接池





new ComboPooledDataSource() # 创建连接池

comboPooledDataSource.setDriverClass("com.mysql.jdbc.Driver")

comboPooledDataSource.setJdbcUrl("jdbc:mysq:///数据库名")

comboPooledDataSource.setUser(String)

comboPooledDataSource.setPassword(String)

comboPooledDataSource.setMaxPoolSize(int); # 最大连接池大小

comboPooledDataSource.setInitialPoolSize(int) # 初始化的时候有几个连接

comboPooledDateSource.getConnection()  # 获得Connection



 c3p0-config.xml



<c3p0-config>

<default-config>

<property name="driverClass">com.mysql.jdbc.Driver</proeprty>

<property name="jdbcUrl">jdbc:mysql:///数据库名</property>

<property name="user">root</property>

<property name="password">toor</property>

<property name="maxPoolSize">int</proeprty>

<property name="initialPoolSize">int</property>

<default-config>

</c3p0-config>



classLoader类用于加载.class 文件到 JVM 形成一个Class类 就是一个结构体 在jvm形成一个内存



class 可以表示接口和类 



.class

.getClass()

Class.forName(String)





class.getConstructor(Class<?>...) 获得有参数构造方法

class.getField(String) 获得属性字段

class.getDeclaredField(String) 获得私有属性

class.getMethod(String,Class<?>...) 获得方法

class.getDeclaredMethod(String,Class<?>...) 获得私有带参数方法



constructor.newInstance(Object...) 实例化有参的构造方法



field.set(Object,Object) 给属性赋值 第一个参数指定对象

field.get(Object) 获得属性 参数指定对象

field.setAccessible(boolean) 设置私有属性可访问





method.setAccessible(boolean) 

method.invoke(Object,Object...) 第一个参数指定调用的对象

 

![](https://tcs.teambition.net/storage/3123d5453be7f3c8750380dab256ef160cee?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTk3OSwiaWF0IjoxNjE1NTQ3MTc5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjNkNTQ1M2JlN2YzYzg3NTAzODBkYWIyNTZlZjE2MGNlZSJ9.rcX5gSy-diJSqCZF6xfHjptc9fegqALOUpkTKvcYTJM&download=image.png "")

静态工厂模式



public class Factory {

public static Interface getObject(String string){

if(string.equals("")){

return new MyObject();

}else if(string.equals("")){

return new MyOtherObject();

}else{

return null;

}

}

}



public class MyObject implements Interface {

public String getString(){

return "";

}

}



public class MyOtherObject implements Interface {

public String getString(){

return "";

}

}



public interface Interface {

public String getString();

}



Interface interface = Factory.getObject("");

interface.getString()









开源笔记

可 Pull Requests 协作写开源笔记

如果笔记图片无法访问 请访问 [teambition](https://tburl.in/0jDNvpbK) 原版开源笔记

gitee

[https://gitee.com/opendevel/java-for-linux](https://gitee.com/opendevel/java-for-linux)

github

[https://github.com/OSrcD/java-for-linux](https://github.com/OSrcD/java-for-linux)

teambition

[https://tburl.in/0jDNvpbK](https://tburl.in/0jDNvpbK)

开源视频

bilibili

[https://space.bilibili.com/77266754](https://space.bilibili.com/77266754)

开源博客

oschina

[https://my.oschina.net/u/4675154](https://my.oschina.net/u/4675154)

csdn

[https://blog.csdn.net/OpenDevel](https://blog.csdn.net/OpenDevel)

开源项目

gitee

[https://gitee.com/opendevel](https://gitee.com/opendevel)

github

[https://github.com/OSrcD](https://github.com/OSrcD)

开源赞赏

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTk3OSwiaWF0IjoxNjE1NTQ3MTc5LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.f2GRRSeqAFs2JKeuG8wKGu14dVuhVE1mxDDQIUVPciI&download=image.png "")

