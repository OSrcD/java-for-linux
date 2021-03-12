Spring IOC 原理 工厂 + 配置文件 +反射



配置文件 applicationContext.xml



<beans>

<bean id="" class=""> </bean>

</beans>



new ClassPathXmlApplicationContext("applicationContext.xml")

applicationContext.getBean(String);



IOC 控制反转



DI的基础是IOC



自动装配就是 IOC+DI的结合



注入属性

<property name="属性名" value="注入的值" />



BeanFactory 是在getBean的时候才生成对象

ApplicationContext 是在读取配置文件的时候就生成对象了



![](https://tcs.teambition.net/storage/31237ceac26ec5b7594ecb975420cba8aefd?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTk5MSwiaWF0IjoxNjE1NTQ3MTkxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM3Y2VhYzI2ZWM1Yjc1OTRlY2I5NzU0MjBjYmE4YWVmZCJ9.d2UH_v6V9bC9Db-vm0afd24UUWUi-g3Zok-9n1kwuAs&download=image.png "")

BeanFactory  

XmlBeanFactory ApplicationContext 继承

FileSystemXmlApplicationContext 实现

ClassPathXmlApplicationContext 实现



new FileSystemXmlApplicationContext("磁盘文件")



new XmlBeanFactory(new ClassPathResource("applicationContext.xml"))



new XmlBeanFactory(new FileSystemResource("磁盘文件"))



Bean 实例化三种方式

通过类的构造方法

通过静态工厂

<bean id="" class="" factory-method="静态工厂方法名" />



通过实例工厂

<bean id="" class="" />

<bean id="" factory-bean="指向上面的 bean id" factory-method="指向实例工厂方法名" />



bean 常用属性

id 是唯一的

如果有特殊字符需要使用name 也要唯一

scope 属性

singleton 单实例 默认

prototype 多实例

request 每一次请求都会创建一个新的bean 作用域在ServletContext环境下

session 不同session创建不同的bean 作用域在ServletContext





<bean init-method="指定初始化bean的时候调用方法名" destroy-method="指向销毁bean的调用方法名scope=singleton有效"> 

</bean>

当调用applicationContext.close()方法 会触发bean的销毁方法



bean的生命周期

1. 初始化构造方法 getBean()

1. 依赖注入 set方法设置属性 property

1. 实现 BeanNameAware 执行 setBeanName(String) # bean 标签配置的名字

1. 实现 BeanFactoryAware 或 ApplicationContextAware 执行 setApplicationContext(ApplicationContext) 方法 # 了解工厂

1. 另外一个类实现 BeanPostProcessor 执行postProcessBeforeInitialization(Object bean,String beanName) # 每个bean初始化的时候都会去调用这个方法 初始化前方法

1. 实现 InitializingBean 执行 afterPropertiesSet() # 属性设置后

1. 调用bean配置的init-method # bean的初始化方法

1. 执行 postProcessAfterInitialization(Object,String) # 之前实现的BeanPostProcessor 每个bean初始化的时候都会去调用这个方法 初始化后方法

1. 执行业务方法

1. 实现 DisposableBean 执行destroy() 方法 # 需要调用 applicationContext.close()方法 执行 Spring的销毁方法

1. 执行 bean配置的 destroy-method 方法 # 需要调用 applicationContext.close()方法 bean 销毁方法



Object proxy  = Proxy.newProxyInstance(object.getClass().getClassLoader(),object.getClass().getInterfaces(),new InvocationHandler(){

invoke(Object proxy,Method method,Object[] args){

return method.invoke(Object,Object...);

}

});



构造方法注入

<constructor-arg name="" value/ref="" />



set方法注入

<property name="" value/ref=""



p 名称空间注入

p:属性名=""

p:对象属性名-ref="bean.id"



spel属性注入 在value=里写

#{'属性值'}

不能使用ref 可以使用这种形式

#{'bean.id'}

 #{bean.id.实例方法名()} # 调用bean的方法注入 前提是已经有bean 在另外一个bean注入



注入数组 list

<property name="">

<list>

<value></value>

<value></value>

<ref></ref>

</list>

</property>



注入set

<property name="">

<set>

<value></value>

<ref></ref>

</set>

</property>



注入map

<property name="">

<map>

<entry key="" value="" />

<entry key="" ref="" />

</map>

</property>



注入 properties

<property name="">

<props>

<prop key=""></prop>

<prop key=""></prop>

</props>

</property>



开启注解扫描

<context:component-scan base-package="" />



Bean 注解

@Component("id")

@Service("id")

@Controller("id")

@Repository("id")

属性注入

@Value("属性值") 可以没有set方法 可以用在private修饰上 如果有需要写在set方法上 

@Autowired 默认按照类型注入 会忽略名字 类型是按照当前声明的类型 如果有两个bean类型相同 则按照名字注入 # 相当于ref Required默认为true 一定要找到匹配的Bean

可以用在set方法上

@Qualifier("bean名称") 配合使用 注入指定bean的名称



@Resource(name="bean名称") 相当于AQ两个注解



其他

@PostConstruct 相当于 init-method

@PreDestory 相当于 destroy-method

@Scope("singleton/prototype/session/request")



代理类会抽取实现类原有代码 是一个平级类





![](https://tcs.teambition.net/storage/3123aacf528ab3ea7b1cb5dd0ff8fc4cca03?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTk5MSwiaWF0IjoxNjE1NTQ3MTkxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjNhYWNmNTI4YWIzZWE3YjFjYjVkZDBmZjhmYzRjY2EwMyJ9.e1VgBqGfspcWfHw-kPTxHfV0O_VZBlA97cplPFYj7so&download=image.png "")

![](https://tcs.teambition.net/storage/3123e9d1f553546a0de6ac1c300fbe8b4d53?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTk5MSwiaWF0IjoxNjE1NTQ3MTkxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjNlOWQxZjU1MzU0NmEwZGU2YWMxYzMwMGZiZThiNGQ1MyJ9.1ik0PkEenAHdg_mSdyTUaV2DmWr6QsSms3SWBZk-D7Q&download=image.png "")

![](https://tcs.teambition.net/storage/3123fe9076d7ae44355fc5ba0edfe5630080?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTk5MSwiaWF0IjoxNjE1NTQ3MTkxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjNmZTkwNzZkN2FlNDQzNTVmYzViYTBlZGZlNTYzMDA4MCJ9.XNr0VjGvpMtCksGKiJ2Mv8PtWe18jBLr_kxG213Oujc&download=image.png "")

Spring 的底层代理机制有两种方式，一个是jdk的动态代理，另外一个是cglib的代理机制



invoke 就是hook方法

method.getName() 方法名

代理类相当于一个实现类 因为抽取了实现类的代码到代理类 并且 implements 了接口 继承了 Proxy 对象



CGLIB是一种底层的字节码增强的技术 目标类就是父类 在创建代理类的时候 会创建一个子类 并且代理类是子类代理类



new Enhancer();

enhancer.setSuperClass(new Dao())

enhancer.setCallback(new MethodInterceptor(){

intercept(Object proxy,Method method,Object[] args,MethodProxy methodProxy) {

return methodProxy.invokeSuper(proxy,args);

}

});

return enhancer.create()



advisor 一般切面 指对所有方法进行拦截



implements MethodBeforeAdvice



before(Method method,Object[] args,Object target)



<bean id="代理id" class="ProxyFactoryBean">

<property name="target" ref="bean.id" />

<property name="proxyInterfaces" value="包类" />

<property name="proxyTargetClass" value="true为使用cglib代理"/>

<property name="interceptorNames" value="拦截器bean.id/切面bean"/>

<property name="optimize" value="true 强制使用cglib代理"

</bean>



@RunWith(SpringJUnit4ClassRunner.class)

@ContextConfiguration("classpath:applicationContext.xml")



会对所有目标方法进行增强







具有切入点的 基于正则表达式

implements MethodInterceptor



invoke(MethodInvocation)

return methodInvocation.proceed();



<bean id="" class="RegexpMethodPointcutAdvisor">

<property name="pattern" value=".* ,.*指定方法名.*" />

<property name="advice" ref="bean.id" />

</bean>



根据bean名称自动创建代理 不能增强特点方法

<bean class="BeanNameAutoProxyCreator">

<property name="beanNames" value="*Dao" />

<property name="interceptorNames" value="bean.id" />

</bean>



根据切面信息自动创建代理

<bean id="" class="RegexpMethodPointcutAdvisor">

<property name="pattern" value="类名.方法名" />

<property name="advice" ref="bean.id" />

</bean>



<bean class="DefaultAdvisorAutoProxyCreator">

</bean>



aspectj

配置自动产生代理

<aop:aspectj-autoproxy />



@Aspect 切面类

@Before(value="execution(修饰符 返回类型 方法名(参数)异常)")

JoinPoint 打印出切入点信息 execution(void 包名.类名.方法名())



后置通知

@AfterReturning(value="",returning="object")

Object object 返回值 名字要一样



环绕通知

@Around(value="")

ProceedingJoinPoint

proceedingJoinPoint.proceed() 执行目标方法 返回值为Object



异常通知

@AfterThrowing(value="",throwing="e")

Throwable e 名字要一样

 e.getMessage()



最终通知

@After(value="")



切点命名

@Pointcut(value="")

private void pointcut(){}

可以在@Before(value="pointcut()")

以后改@Pointcut(value="")就行了



aspectj xml方式开发



<aop:config>

<aop:pointcut id="切点id" expression="execution("")" />

<aop:aspect ref="bean.id切面类">

<aop:before method="切面类方法名" pointcut-ref="切点id" />

<aop:after-returning method="" pointcut-ref="" returing="object" />

<aop:around method="" pointcut-ref=""  />

<aop:after-throwing method="" pointcut-ref=""  throwing="e" />

<aop:after method="" pointcut-ref="" />

</aop:aspect>

</aop:config>



Spring 事务



事务就是事



begin;

一条或以上SQL语句

commit / rollback



事务ACID

A 原子性 事务不能被分割 要么全部执行成功 要么全部执行失败 不会执行一半 被一半成功 另外一半失败

C 一致性 在原子性基础上 业务从一个一致性状态变到另外一个一致性状态

I 隔离性 并发事务执行 一个事务不能被另外一个事务影响

D 持久性 事务一旦提交就不能更改了

MySQL 是默认提交事务的



InnoDB 引擎支持事务



隔离性 并发事务引来的问题



脏读：读取的数据不是永久的数据

事务B：1.将 '1' 号商品库存改为0

事务A：2.读取 '1' 号商品库存

事务B：3.回滚

解决：只能读取永久性的数据，两个事务不允许互相去操作读取，会话独立



不可重复读：两次读取的数据不一致

事务A：1.读取'1'号商品库存为100

事务B：2.将 '1' 商品库存改为0

事务B：3.提交

事务A：4.读取'1'号商品库存为0

解决：加锁、锁行、锁记录



幻读：修改所有数据为0 之后读取所有数据发现还有

事务A：1.将所有商品库存改为0

事务B：2.插入一个库存为100的新商品'2'

事务B：3.提交

事务A：4.读取所有商品库 发现还有一个商品库存为100

解决：锁表



MySQL数据库隔离级别

![](https://tcs.teambition.net/storage/31231d5281ba9f56a5565dabc982d57d0c6f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTk5MSwiaWF0IjoxNjE1NTQ3MTkxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjMxZDUyODFiYTlmNTZhNTU2NWRhYmM5ODJkNTdkMGM2ZiJ9._twu6iif1ocQJRJ0Wjx7fl3N4B79oJn537SoLihca6A&download=image.png "")

MySQL默认是可重复读



在数据库设置事务隔离级别

![](https://tcs.teambition.net/storage/3123991bc66f78cd5ad0aaaf0c2e8959b759?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTk5MSwiaWF0IjoxNjE1NTQ3MTkxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM5OTFiYzY2Zjc4Y2Q1YWQwYWFhZjBjMmU4OTU5Yjc1OSJ9.b58tD-QJ5lsQQ2Xw3e-BS7Me5qy1Yb-9Xu1_MouQydU&download=image.png "")

mysql 事务处理 人工

begin;

sql语句

commit/rollback;





JDBC事务处理

同一个Connection对象才能封装为一个事务

默认自动提交

关闭事务自动提交

connection.setAutoCommit(false);

提交事务

connection.commit();

回滚事务

connection.rollback();

用try 中执行多条sql语句

sql语句发送异常

cache中回滚 数据 就不会插入到数据库中



JDBC默认隔离级别是可重复读

![](https://tcs.teambition.net/storage/31232914634546b9b87830dfb5cb89ae38e7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTk5MSwiaWF0IjoxNjE1NTQ3MTkxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjMyOTE0NjM0NTQ2YjliODc4MzBkZmI1Y2I4OWFlMzhlNyJ9.5zXti8Uyy8AHUA8OYOyCJRo-YmvelJRnkvp-yizS2Ls&download=image.png "")

serializable 串行化



Spring 事务处理

TD TS PL是接口

PL的箭头表示引用这些对象

DSTM是类 箭头是实现PL

![](https://tcs.teambition.net/storage/3123e57e372baffc3e5d4d18bf01ac7f1ea0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTk5MSwiaWF0IjoxNjE1NTQ3MTkxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjNlNTdlMzcyYmFmZmMzZTVkNGQxOGJmMDFhYzdmMWVhMCJ9.ASZTUw-8KJO99eE9zcGksp5Y03hUe2S33ibKVOF2SJg&download=image.png "")

![](https://tcs.teambition.net/storage/31234fb0a655b71b6fb92f72f0dcf2e80b7d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTk5MSwiaWF0IjoxNjE1NTQ3MTkxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM0ZmIwYTY1NWI3MWI2ZmI5MmY3MmYwZGNmMmU4MGI3ZCJ9.IT2qKlj9kF4JccpDd5tY6Qm2jDdo6ALPw2KMmTifkXg&download=image.png "")

TransactionDefinition 接口





一个事务多长时间，没有响应，就觉得事务出问题了，就把事务销毁

TIMEOUT_DEFAULT 默认超时 30秒



Spring 事务传播行为

![](https://tcs.teambition.net/storage/312360f6972545f9e879fc7de5d75a24a5a7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTk5MSwiaWF0IjoxNjE1NTQ3MTkxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM2MGY2OTcyNTQ1ZjllODc5ZmM3ZGU1ZDc1YTI0YTVhNyJ9.xTGVAVcjroxN84tS0XEPI0xcsZyaoemUPX3BHpWCct8&download=image.png "")

Required 必须的

Supports 支持

Mandatory 强制性的

Requires_new 需要新的

Not_supported 不支持

Never 从来没有

Nested 嵌入



propagation.required

支持当前事务,如果当前没有事务就新建一个事务

propagation.supported

支持当前事务,如果当前没有事务就以非事务运行

propagation.mandatory

支持当前事务,如果当前没有事务就抛出异常

propagation.requires_new

新建事务,如果当前有事务就挂起

propagation.not_supported

以非事务运行,如果当前有事务就挂起

propagation.never

以非事务运行,如果当前存在事务就抛异常

propagation.nested

如果当前有事务就内嵌一个新的事务运行,如果没有就新建事务







基于底层 API 的编程 式事务管理



<bean id="driverManagerDataSource" class="DriverManagerDataSource">

<property name="driverClassName" value="com.mysql.jdbc.Driver" />

<property name="url" value="jdbc:mysql:///数据库名" />

<property name="username" value="root" />

<property name="password" value="toor" />

</bean>



<bean id="dataSourceTransactionManager" class="DataSourceTransactionManager">

<property name="dataSource" ref="driverManagerDataSource" />

</bean>



<bean id="defaultTransactionDefinition" class="DefaultTransactionDefinition">

<property name="propagationBehaviorName" value="PROPAGATION.REQUIRED" />

</bean>



@Autowired

PlatformTransactionManager platformTransaction

@Autowired

TransactionDefinition



TransactionStatus = platformTransaction.getTransaction(TransactionDefinition)

platformTransaction.commit(transactionStatus)

platformTransaction.rollback(transactionStatus)



基于 TransactionTemplate 编程式事务管理



<bean id="transactionTemplate" class="TransactionTemplate">

<property name="transactionManager" ref="dataSourceTransactionManager" />

</bean>



@Autowired

TransactionTemplate 

里面内置平台事务管理器

内置事务定义

内置事务状态

内置commit



transactionTemplate.execute(new TransactionCallback(){

doInTransaction(TransactionStatus){

try{



}cache(){

transactionStatus.setRollbackOnly() // 不需要抛异常 执行这个方法事务会手动回滚 

}

}

});



基于TransactionInterceptor 声明式事务处理



不需要事务定义

<bean id="transactionInterceptor" class="TransactionInterceptor">

<property name="transactionManager" ref="dataSourceTransactionManager" />

<property name="transactionAttributes">

<props>

<prop key="方法名*">PROPAGATION_REQURIED,readOnly</prop>

<prop key="*">PROPAGATION_REQUIRED</prop>

</props>

</property>

</bean>



readOnly，设置为true时，mysql只能查询，若增删改会异常：



<bean id="代理类名基于接口名用于@Autowired" class="ProxyFactoryBean">

<property name="target" ref="实现类id" />

<property name="interceptorNames">

<list>

<idref bean="transactionInterceptor" />

</list>

</property>

</bean>





基于TransactionProxyFactoryBean 声明式事务

<bean id="代理名" class="TransactionProxyFactoryBean">



<property name="transactionManager" value=""/>



<property name="transationAttributes" >



</property>



<property name="target" ref="id" />



</bean>







基于<tx> 命名空间的声明式事务管理



<tx:advice id="advice" transaction-manager="dataSourceTransactionManager">

<tx:attributes>

<tx:method name="方法名*" propagation="REQUIRED" read-only="true" />

<tx:method name="*" propagation="REQUIRED" />

</tx:attributes>

</tx:advice>



<aop:config>

<aop:pointcut id="" expression="execution()" />

<aop:advisor pointcut-ref="id" advice-ref="advice"/>

</aop:config>



基于@Transactional的声明式事务管理

<tx:annotation-driven transaction-manager="dataSourceTransactionManager" />

@Trsanctional(propagation = Propagation.REQUIRED) 默认





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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTk5MSwiaWF0IjoxNjE1NTQ3MTkxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.UWCp7pggJzYiVmRwSzWAKwY-ya8nfj7FWMNGd9Fq1Zw&download=image.png "")

