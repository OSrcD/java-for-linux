

mybatis-config.xml



<configuration>

<settings>

下划线到驼峰转换

<setting name="mapUnderscoreToCamelCase value="true" /> 

</settings>



<environments default="dev">

<environment id="dev">

使用jdbc进行事务管理

<transactionManager type="JDBC"></transcationManger>

 使用连接池的方式进行连接

<datasource type="POOLED">

<property name="driver" value="com.mysql.jdbc.Driver" />

<property name="url" value="jdbc:mysql:///数据库名" />

<property name="username" value="root" />

<property name="password" value="toor" />

</datasource>

</environment>

</environments>



<mappers>

<mapper resource="mappers/mapper.xml"/>

</mappers>

</configuration>



Resources.getSourceAsStream("mybatis-config.xml")



new SqlSessionFactoryBuilder().build(Reader)

sqlSessionFactory.openSession()

sqlSession.getConnection()

sqSession.close()



type="POOLED" connection.close() 会回收到连接池当中

type="UNPOOLED" connection.close() 会直接关闭连接





mapper.xml



<mapper namespace="命名空间id">

<select id="起id名字" resultType="指定返回类型" parameterType="指定参数类型">

#{value}

/select>

</mapper>



sqlSession.selectList(String) 查询多条数据返回 List

sqlSession.selectOne(String,Object) 查询一条 带参数



parameterType="java.util.Map"

#{min} 

#{max}

#{limit}

Map map = new HashMap();

map.put("min",Object);

map.put("max",Object)

map.put("limit",Object)



sqlSession.selectList(String,Object) 指定参数查询多条数据返回List



多表关联查询

from 商品表 as items, 分类表 as category

where items.category_id = category.id

resultType="java.util.Map" # 多表关联查询

用selectList查询出来的列是乱序的

resultType="java.util.LinkedHashMap" # 实现了Map 多表关联查询 

查询出来是按照数据表正序的

‘1’ as test  # test为key value为1

![](https://tcs.teambition.net/storage/3123e4e63eb38fbc87a6e312139b8920218e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTk4NSwiaWF0IjoxNjE1NTQ3MTg1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjNlNGU2M2ViMzhmYmM4N2E2ZTMxMjEzOWI4OTIwMjE4ZSJ9.lbIOoYhnFlssKPIsQgwEmpXCYM-pHnWkF3NpATBSb5E&download=image.png "")

![](https://tcs.teambition.net/storage/312371f4f74ba3ac72c7b618ae0f1f25ffe4?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTk4NSwiaWF0IjoxNjE1NTQ3MTg1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM3MWY0Zjc0YmEzYWM3MmM3YjYxOGFlMGYxZjI1ZmZlNCJ9.So1Wcg7rcVQmsddIXy0brtZsdIsP2jD3muOnRl35ndU&download=image.png "")

resultMap 结果映射 用于DTO对象

DTO 内部会关联一个对象 同时扩展该对象的属性

提前new 好 内嵌对象

id 用于主键

DTO里面的对象需要使用

对象名.属性名来指定

<resultMap id="" type="指定映射DTO类型">

<id property="内嵌对象名.属性名" column="数据库字段名" />

<result property="属性名“ column="Sql语句指定的临时值" /> # 1 as test 这个 test就是column 并且test也是对象的属性名

</resultMap>



指定id

<select resultMap="resultMap.id">

</select>



column 可以重复

property 不能重复



selectList("命名空间ID") 返回List

selectList("命名空间ID","带参") Map LinkedHashMap #{} 返回List

selectOne("命名空间ID") 返回Object

selectOne("命名空间ID","带参")#{value} 返回Object





数据库事务 插入 删除 更新数据的时候先把数据放入数据库事务日志

如果有一个插入数据失败就全部回滚

如果全部都插入成功就会真正提交数据库记录里

![](https://tcs.teambition.net/storage/312385460f01b44631c61a12ca1639d12bd8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTk4NSwiaWF0IjoxNjE1NTQ3MTg1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM4NTQ2MGYwMWI0NDYzMWM2MWExMmNhMTYzOWQxMmJkOCJ9.3Y_Xa6C9Sl6XLWvunxLvg1l1oaDT1wdOIiS170WWYDk&download=image.png "")

sqlSessionfactory.openSession(boolean) 设置为 false 关闭事务自动提交



插入 没有 resultType resultMap

插入时 主键自动增加

插入对象需要写id属性 不需要和数据库一样 嵌套查询中可以指定 才能在插入的时候 MyBatis赋值给这个ID 直接用打印流打印出来

<insert id="" parameterType="">

</insert>



sqlSession.insert(String)

sqlSession.insert(String,Object)

sqlSession.commit()

sqlSession.rollback()





select last_insert_id() 不会出现并发主键混乱



嵌套在insert标签中查询

order 有 AFTER  和 BEFORE

keyProperty="对象主键属性名" 

<selectKey resultType="主键类型" keyProperty="对象主键属性名" order="BEFER|AFTER" >

select last_insert_id()

</selectKey>



<update id="" parameterType="">

</update>



<delete id="" parameterType="Integer">

#{value}

</delete>

sqlSession.update(String)

sqlSession.update(String,Object)

sqlSession.delete(String)

sqlSession.delete(String,Object)



${} 不能防SQL 注入 原文传值 不能是外界输入

#{} 可以防SQL注入 帮整个语句加"" 预编译 底层使用 ? 传参

or 1=1 or

' "" 都可以表示字符串





工作流程

sqlSessionFactory 解析 mybatis-config.xml 文件

sqlSession 解析 mapper.xml 文件



动态SQL 

所谓的动态SQL 就是动态拼接SQL语句 一般用在select 标签当中

where 1=1 防止 where and 

可以去掉where 使用 <where> 就不用写 1=1 了 MyBatis 会帮你加上 1=1

<where>

<if test="传入属性名 != null and 传入属性名 != ' '  ">

and 数据库字段名=#{传入属性名}

</if>

<choose>

<when test="传入属性名" == 转义字符串>

数据字段名相关操作

</when>

<otherwise>

数据库字段名相关操作

<otherwise>

</choose>



</where>



xml 特殊字符需要转义



二级缓存

MyBatis本质使用了 map 键值对来缓存对象

![](https://tcs.teambition.net/storage/312396375b03e40a97da9f0a56f15805a0ab?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTk4NSwiaWF0IjoxNjE1NTQ3MTg1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM5NjM3NWIwM2U0MGE5N2RhOWYwYTU2ZjE1ODA1YTBhYiJ9.CjSCLlmhy2g0pkFVk29pDPTqEB65NUwWn9_9xPh485Q&download=image.png "")

一级缓存查询都会被缓存下来

二级缓存默认所有查询都会被缓存下来

写操作commit提交时会对namespace缓存强制清空

useCache=false 表示不使用缓存

flushCache=true 强制清空缓存 执行完某一条SQL语句后 对namespace所有缓存进行清空

![](https://tcs.teambition.net/storage/312378273cd38eb7bca97f30b164bf5b9296?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTk4NSwiaWF0IjoxNjE1NTQ3MTg1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM3ODI3M2NkMzhlYjdiY2E5N2YzMGIxNjRiZjViOTI5NiJ9.UYjgqv2Z5zwD2uZYUsE43THmgfqvbHijnmEx7a_-4Zk&download=image.png "")

一级缓存用sqlSession执行两次select是同一个缓存 不会执行sql语句

如果用不同的sqlSession 对象执行的话 两个sqlSession不会使用同一个缓存

可通过sqlSession.commit() 方法 强制清空namespace缓存 包括一级缓存





开启二级缓存

evication 回收

flushInterval 清空缓存时间 单位为毫秒

size 缓存对象大小

readOnly 是否只读缓存

<cache evication=”LRU“ flushInterval="" size="" readOnly="true|false">



开启了二级缓存以后 两个不同的sqlSession会被缓存下来

缓存命中率公式：使用缓存次数/sqlSession 每次执行sql语句次数（使用缓存不打印sql语句也算一次） = 缓存命中率

比如使用缓存次数为1/sql语句次数为2 = 0.5



写操作会清空二级缓存



![](https://tcs.teambition.net/storage/3123f4c543ca3b5db1c078b123db22925031?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTk4NSwiaWF0IjoxNjE1NTQ3MTg1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjNmNGM1NDNjYTNiNWRiMWMwNzhiMTIzZGIyMjkyNTAzMSJ9.BxpBBRuI_sC-D9kDLfiBD_IpKA40u56pCLnJ853CDXE&download=image.png "")

FIFO无法有效提高缓存的命中率

 

SOFT 软引用 

WEAK 弱引用

不是MyBatis自身的管理，jvm垃圾回收器根据对象的引用状态来是否将这个缓存对象进行移除，作为SOFT软引用，相对弱一些，jvm会根据对象的引用状况来决定这个对象是否被移除掉。WEAK比SOFT更加为积极一些，进行移除的时候，它的扫描会更加的频繁，这两个是由jvm来控制的。百分之80%都会使用LRU



不推荐用list作为缓存对象

因为返回list查询结果一般是多变的 缓存命中率比较低

 

t_goods表 现在有一千四百多个商品，那么相应的在内存足够的情况下 size应该大于一千四百



缓存对象的副本，每一次取出对象都是不同的，安全性较高

对副本的修改，不会影响程序的全局

 

对其中的某一个副本进行修改，哪并不是影响程序的全局

相比起，我们缓存的用途，往往缓存的数据在取出来以后并不会做修改，即便做了修改，也会马上做数据的新增和保存。





UseCache使用缓存

当前selectAll查询所有的形式并不推荐把查询结果放入缓存

因为全局查询的时候这个数据量实在是太大了，假设如果没有limit关键字约束，现在呢，我们是有一千四百多个商品，这个sql返回的是一个List，List放入缓存的时候会当做一个对象，现在这个List一下子包含了1400多个goods对象，对于内存的使用是很大的，现在是1400个，过两年可能变成了10万个，哪你每次缓存存储的时候都是要保存10万个数据，对于内存压力可想而知，同时像这种 一下子返回很多数据的查询，它的缓存命中率也是比较低的，像诸如这种sql语句，并不推荐使用缓存，设置为false就可以了



只需保留单个实体对象缓存



不要去保留大量的list查询结果，这样缓存命中率是比较低的



是否只读true：每次返回缓存对象本身

False:每次返回缓存对象副本，每一次取出对象都是不同的。效率降低，安全高

 

执行完整个SQL以后立即强制清空缓存 

表示这条SQL语句不使用缓存

![](https://tcs.teambition.net/storage/312356b7890dc7d27b92d8099cfb00ead35e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTk4NSwiaWF0IjoxNjE1NTQ3MTg1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM1NmI3ODkwZGM3ZDI3YjkyZDgwOTljZmIwMGVhZDM1ZSJ9.7Vx7sKBzwJmSEHiEdDteEoVdl23OmpLIIGKftD93QOo&download=image.png "")

<select userCache=false|true flushCache=true|falce>

</select>



一对多查询 

在一个有外键的对象里面 写一个List



多对多查询要通过 中间的两个外键来left join  

中间表为中心

where条件也是中间表的



一对多查询

一的对象里放一个 List 作为多的对象

在 mapper 文件标签里 写

<id />

<collection property="指向多的List对象名" select=”namepsace.id“ column="外键代入查询"> </collection>



多对一查询

在多的对象放一个一的对象

在mapper文件标签里写

<resultMap>

<id />

<result property="多的对象外键名" column="数据库外键名" />

<association property="指向一的对象名" select="namespace.id" column="数据库外键代入查询">

</assocication>

</resultMap>



分页

变 offset

select * from users limit offset,size

总记录数

select count(*) from users; 



在mybatis-config.xml 文件配置



<plugins>

<plugin interceptor="com.github.pagehelper.PageInterceptor">

<property name="helperDialect"  value="mysql" />

<property name="reasonable" value="true" />

</plugin>

</plugins>





PageHelper.startPage(int,int)

Page<实体> page = sqlSession.selectList("namespace.id")

page.getPages(); 获得总分页

page.getTotal() 获得总记录数

page.getStartRow() 获得开始行号

page.getEndRow() 获得结束行号

page.getPageNum() 获得当前是第几页

List<实体> = page.getResult() 获得当前页的数据





连接池



extends UnpooledDataSourceFactory

构造函数

this.dataSource = new ComboPooledDataSource();



<datasource type="com.opendevel.datasource.unpooledDataSourceFactory">

<property name="driverClass" value="com.mysql.jdbc.Driver" />

<property name="jdbcUrl" value="jdbc:mysql:///数据库名" />

<property name="user" value="root" />

<property name="password" value="toor" />

<property name="initialPoolSize" value="" />

<property name="maxPoolSize" value="" />

<property name="minPoolSize" value="" />

</datasource>



批处理



List list =new ArrayList();



sqlSession.insert("",list);



Collection代表迭代的数据源从哪里来

list指代了从外侧传入List集合



批量插入

在values后面写

<insert id="" parameterType="java.util.List">

<foreach collection="list" item="item" index="index" separator="," >

()

</foreach>

</insert>





批量删除

<delete id="" parameterType="java.util.List">

<foreach collection="list" item="item" index="index" open="(" close=")" separator=",">



</foreach>

</delete>



sqlSession.insert("delete.id",list)



new Date().getTime() 返回long型的时间



注解

@param("别名") 外侧传入的参数





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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTk4NSwiaWF0IjoxNjE1NTQ3MTg1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.gBsxUkB-ohSif1jseI-kkiLMimvKCMIJK_k1EtrgOjg&download=image.png "")

