

**插入数据**

**INSERT INTO imooc_user()VALUES(); INTO可以省略**





**INSERT INTO imooc_user(id,username,password,email,age,card,tel,salary,married,addr,sex)**

**VALUES(1,'king','king','382771946@qq.com',24,'230112197809871234',18635579617,888888.68,0,'北京','男');**



**插入数据省略**

**INSERT user VALUE(1,'king',24,'382771946@qq.com');**

**INSERT user VALUES(1,'king',24,'382771946@qq.com');**



**一次插入多条记录**

**INSERT user VALUES(NULL,'A',DEFAULT,DEFAULT),**

**(NULL,'b',56,'b@qq.com'),**

**(NULL,'c',14,'c@qq.com');**



**INSERT SET形式**

**INSERT user SET username='d',age=45,email='d@qq.com';**



**UPDATE SET**

**UPDATE user SET username='socialpg',age=18 ,email='qq@com' WHERE id=3;**





**查询指定库中的表**

**SELECT * FROM imooc.user1;**





**字段起别名**

**SELECT id AS '编号',username AS '用户名' , sex AS '性别'FROM user1;**





**数据库起别名**

**SELECT id,username FROM user1 AS u;**





**表名.字段名**

**SELECT user1.id,user1.username FROM user1;**





**<=>检测NULL值**

**SELECT id,username,age,userDesc FROM user1**

**WHERE userDesc <=> NULL;**



安全等于运算符 < = >



**IS NULL**

**SELECT id,username,age,userDesc FROM user1**

**WHERE userDesc IS NULL ;**



**IS NOT NULL 取反**

**SELECT id,username,age,userDesc FROM user1**

**WHERE userDesc IS NOT NULL ;**







**BETWEEN AND**

**SELECT id,username,age,userDesc FROM user1**

**WHERE age BETWEEN 18 AND 30;**



**NOT BETWEEN AND**

**SELECT id,username,age,salary FROM user1**

** WHERE salary NOT BETWEEN 18 AND 30;**



**IN指定集合范围**

**SELECT id,username,age FROM user1 WHERE id IN(1,3,5,7,9,29,45,78);**



**NOT IN 不在指定集合范围**

**SELECT id,username,age FROM user1 WHERE id NOT IN(1,3,5,7,9,29,45,78);**





**BETWEEN AND AND AND**

**SELECT id,username,age,sex,salary addr FROM user1**

** WHERE salary BETWEEN 60000 AND 100000 AND sex='男' AND addr='北京';**



**LIKE 模糊查询 字符串  LIKE不区分大小写的**

** SELECT id,username,age FROM user1 WHERE username LIKE 'king';**



**LIKE %% 任意一个字符**

** SELECT id,username,age,sex FROM user1 WHERE username LIKE '%三%';**



**LIKE %% 任意一个字符**

** SELECT id,username,age,sex FROM user1 WHERE username LIKE '%三%';**



**GROUP BY hash算法 过滤掉相同的，只保留一条第一次检索出来的数据作为代表，不同的记录成为不同的一个组,多的数据会第一显示出来，这是默认情况下，但可以通过函数显示出这个组中的详细的各个记录的信息，一组查该组的所有记录,会派出一个sex代表出来**

**分组会把查询到的第一条记录作为显示出来，分组是为了看有多少组**

**SELECT id,username,age,sex FROM user1 GROUP BY sex;**



**GROUP_CONCAT（字段）查看分组过后的指定字段的值组成这个组的指定字段值或成员，列出的值顺序是按照正常检索出来的数据**

**GROUP BY 和 GROUP_CONCAT函数**

**SELECT GROUP_CONCAT(username),age,sex,addr FROM user1 GROUP  BY sex;**



**COUNT(*) 统计有多少条记录数 就是每条每条记录**

**Count(1) (*)不一样 (1) (*)可以统计NULL值**

**count(数字)=count(*) **

**SELECT COUNT(*) AS total_users FROM user1;**



**COUNT(字段)在统计字段，如果字段值为空就不记录出来**

**SELECT COUNT(userDesc) FROM user1;**





**CONUT(*)配合GROUP BY 使用的时候 COUNT(*) 统计的是 GROUP BY 分组中的记录数**

**SELECT  sex,GROUP_CONCAT(username) AS usersDetail ,COUNT(*) AS toalUsers FROM user1 GROUP BY sex;**



**CONUT(*)配合GROUP BY 使用的时候 COUNT(*) 统计的是 GROUP BY 分组中的记录数**

**SELECT  sex,GROUP_CONCAT(username) AS usersDetail ,COUNT(*) AS toalUsers FROM user1 GROUP BY sex;**



**GROUP BY 是配合聚合函数使用的 聚合函数受GROUP BY 影响**

**SELECT addr,**

** GROUP_CONCAT(username) AS usersDetail,**

** COUNT(*) AS totalUsers,**

** SUM(age) AS sum_age,**

** MAX(age) AS max_age,**

** MIN(age) AS min_age,**

** AVG(age) AS avg_age**

** FROM user1**

** GROUP BY addr;**



**WITH ROLLUP 会在最后一条记录加上各个分组合和聚合函数统计的结果相加到一起**

**SELECT GROUP_CONCAT(username) AS usersDetail,COUNT(*) AS totalUsers FROM user1 GROUP BY sex WITH ROLLUP;**



**With rollup（使用汇总）分组出来的各个字段值总和到一条记录里面去**



**POSITION 按照SELECT的顺序字段位置分**

**SELECT addr,**

** GROUP_CONCAT(username) AS usersDetail,**

** COUNT(*) AS totalUsers,**

** SUM(age) AS sum_age,**

** MAX(age) AS max_age,**

** MIN(age) AS min_age,**

** AVG(age) AS avg_age**

** FROM user1**

** GROUP BY 1;**



**GROUP BY 是按照 SELECT 中的字段位置**



**Having是二次 是对分组的结果 受分组影响 可以加 聚合函数 select查询的列**

**SELECT addr,**

** GROUP_CONCAT(username) AS userDetail,**

** COUNT(*) AS totalUsers**

** FROM user1**

** GROUP BY addr HAVING COUNT(*);**

**先分组后select 列名后having **



**Group 查询出来的结果 按照 数据库存储每一行数据顺序**



**having只能是select中出现的**

**group by 可以不是select中出现的**



**Having是根据select中的列得出的结果 再次指定条件筛选，也可接select中出现的聚合函数也算是二次筛选**

**Having可接select查询出来的结果别名 二次筛选**

**Having可通过别名**

**SELECT addr,**

** GROUP_CONCAT(username) AS userDetail,**

** COUNT(*) AS totalUsers**

** FROM user1**

** GROUP BY addr HAVING totalUsers**

**>=3;**



**ORDER BY DESC 降序 ASC升序**

**SELECT id,username,age FROM user1 ORDER BY id DESC;**



**多个ORDER BY,一个ORDER BY 不能满足可通过多个**

**SELECT id,username,age FROM user1 ORDER BY age ASC,id ASC;**



**RAND() 返回[0-1) 随机排序**

**SELECT id,username,age FROM user1 ORDER BY RAND();**



**LIMIT显示5条记录**

**SELECT id,username,age,sex FROM user1 LIMIT 5;**



**LIMIT从指定显示记录**

**从零开始显示5条**

**0代表一个记录**

**4代表5条记录**

**SELECT id,username,age,sex FROM user1 LIMIT 0,5;**



**LIMIT分页实现 从第4条开始显示3条也就是到6条 包括4本身 LIMIT受ORDER BY影响**

**SELECT id,username,age,sex FROM user1 LIMIT 3,3;**



**分页中变的是offset就行了**



**Group BY 还可以先被where 再GroupBy**



**综合练习**

**SELECT addr,**

** GROUP_CONCAT(username) AS usersDetail,**

** COUNT(*) AS totalUsers,**

** SUM(age) AS sum_age,**

** MAX(age) AS min_age,**

** AVG(age) AS avg_age**

** FROM user1**

** WHERE id>=2**

** GROUP BY addr**

** HAVING totalUsers>=2**

** ORDER BY totalUsers ASC**

** LIMIT 0,1;**



**笛卡尔积 相等于二层循环 第一个记录数*第二个表记录数**

**SELECT emp.id,emp.username,emp.age,dep.depName FROM emp,dep;**



**Group where having**

**先where 第一次筛选后 group 分组后聚合函数后having二次筛选 **



**一个表（部门表）是4条记录，另外一个表（员工表）6条记录**

**每一个员工表一个记录重复都被部门表用不同的记录查询出来**

**6*4=24 笛卡尔积**

**两个for循环  1秒之内只能处理万级数据**



**超过三张表性能低**

**分开查询再组合 进行优化**

**ON相当于where条件**



**一对一 内连接 INNER JOIN ON 条件 交集共有**

**SELECT e.id,e.username,e.age,d.depName FROM  emp AS e INNER JOIN dep AS d on e.depId = d.id;**



**内连接会查询两个表中符合连接条件的记录**

**就是两个表都有 and 存在才行**

**交集部分 共有部分**

**数学符号是A∩B**



**左连接 LEFT OUTER JOIN 显示左表所有记录 以ON为条件 右边符合的显示 不符合的右表以NULL形式显示**

**SELECT e.id,e.username,e.age,d.depName,d.depDesc**

** FROM emp AS e**

** LEFT OUTER JOIN dep AS d**

** ON e.depId=d.id;**



**左连接是 左边是主表 右边是从表**

**右连接是 右边是主表 左边是从表**

**主表是全部记录 从表是符合条件的记录**



**右连接 RIGHT OUTER JOIN 显示右表所有记录 以ON为条件 左表符合的显示 不符合的右表以NULL形式显示**

**SELECT e.id,e.username,e.age,d.depName,d.depDesc FROM  emp AS e RIGHT OUTER JOIN  dep AS d   ON e.depId=d.id;**





**三表复合多表连查单表关系  缺点性能不好**

**SELECT p.id,p.productName,p.price,c.cateName,a.username,a.email**

** FROM products AS p JOIN admin AS a ON p.adminId = a.id**

** JOIN cate AS c ON p.cateId=c.id WHERE p.price<1000**

** ORDER BY p.price DESC LIMIT 0,2;**



**多表查询没有 单表分批查询 合并起来的效率要高**

**不要使用超过三张表 性能差**





**四表**

**SELECT p.id,p.productName,p.price,c.cateName,a.username,a.email**

** FROM products AS p JOIN admin AS a ON p.adminId = a.id**

** JOIN cate AS c ON p.cateId=c.id WHERE p.price<1000**

** ORDER BY p.price DESC LIMIT 0,2;**



 **                   子查询**

**IN 在集合中查询**

**SELECT * FROM emp WHERE id IN (1,2,3,4);**



**SELECT * FROM emp WHERE depId IN (SELECT id FROM dep);**



**NOT IN 不在集合中查询**



**SELECT * FROM emp WHERE depId NOT IN (SELECT id FROM dep);**





**>= 子查询**

**SELECT id,username,score FROM stu WHERE score>=**

**(SELECT score FROM level WHERE id=1);**





**EXISTS 子查询 true || false**

**SELECT * FROM emp WHERE EXISTS (SELECT * FROM dep WHERE id=1);**



**>= any最小值  all最大值**



**SELECT * FROM stu WHERE score >= ANY(SELECT score FROM level);**



**= ANY等于任意值 存在ANY中的任意值才返回**

**SELECT * FROM stu**

**WHERE score = ANY(SELECT score FROM level);**





**!= <> ALL不等于任意值 不存在ALL中的任意值都会返回**

**SELECT * FROM stu**

**WHERE score != ALL(SELECT score FROM level);**





**<= any最大值  all最小值**

**SELECT * FROM stu**

** WHERE score < ALL(SELECT score FROM level);**



**DISTINCT去掉重复的列select查询**

**SELECT DISTINCT(username) FROM user2;**



**联合查询 UNION 合并重复数据  留下不重复针对多个表的，单个表就不用**

**SELECT * FROM user1**

**UNION SELECT * FROM user2;**



**UNION ALL 简单的合并 两个表并在一起**

**就是一个数据表放在上面，另外一个数据表放在下面**

**SELECT * FROM user1**

**UNION ALL SELECT * FROM user2;**



**自连接 无限极分类 虚拟出两种相同的表，只不过在创建表时的条件不一样 查询所有分类信息，并且得到父类**

**SELECT  s.id,s.cateName AS sCateName,p.cateName AS pCateName**

** FROM cate AS s LEFT JOIN cate AS p ON s.pid=p.id;**



**自连接 无限极分类 虚拟出两种相同的表，只不过在创建表时的条件不一样 查询所有分类信息及其子分类**

** SELECT  p.id,p.cateName AS pCateName,s.cateName AS sCateName**

** FROM cate AS s RIGHT JOIN cate AS p ON p.id=s.pid;**



**自连接 分组 查询所有的分类及其子分类的数目**

**SELECT  p.id,p.cateName AS pCateName,COUNT(s.cateName) AS count**

** FROM cate AS s**

** RIGHT JOIN cate AS p**

** ON p.id=s.pid**

** GROUP BY p.cateName ORDER BY id ASC;**



**Count 统计 group by的分组里的一个组数目**

** **

**先执行完group by 前面语句**

**再分组**

**所以count是分组之前统计的**



**Count不记录null值**



**全连接**

**SELECT * FROM TableA FULL OUTER JOIN TableB ON TableA.name = TableB.name**

**WHERE Table.id IS NULL OR TableB.id IS NULL**



![](https://tcs.teambition.net/storage/3123f673b1edf669f3727f97344e95012f62?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkzNywiaWF0IjoxNjE1NTQ3MTM3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjNmNjczYjFlZGY2NjlmMzcyN2Y5NzM0NGU5NTAxMmY2MiJ9.kCz_TuPPoyljScI7IMFwMo-bGq0NcNj4AGPDX1YmTe0&download=image.png "")



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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkzNywiaWF0IjoxNjE1NTQ3MTM3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.6qv4RtXYNWp6iiW8Dh4_OSkxF_pgAUJni_uzO32VvkY&download=image.png "")

