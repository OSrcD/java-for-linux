

Spring Boot 目录结构

![](https://tcs.teambition.net/storage/31232d847784749b44c2fa9bc3fb0adafa59?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MDAwNSwiaWF0IjoxNjE1NTQ1MjA1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjMyZDg0Nzc4NDc0OWI0NGMyZmE5YmMzZmIwYWRhZmE1OSJ9.WP35L0_GN2cbgEX3zwLQ69sHv-6lLK7SahdY367iBLU&download=image.png "")

Static中放应用开发保存的css js 图片这些静态文件

Template用于保存表示层的页面像jsp HTML



Parant创建基础引用

 

Spring-boot-starter-parent帮我们自动引入了spring boot中最基础的组件，所有spring boot都要依赖于它才能进行构建

  

其次我们需要在我们工程中增加spring boot 的真正的依赖



这里spring-boot-starter-web 使用了一系列的starter启动器来描述工程所要支持的功能



这里starter-web代表向当前的工程中增加支持java web的能力

不需要写版本号，因为在上面parent已经提前写了



<parent>

<groupId>org.springframework.boot</groupId>

<artifactId>spring-boot-starter-parent</artifactId>

<version></version>

</parent>



<dependencies>

<dependency>

<groupId>org.springframework.boot</groupId>

<artifactId>spring-boot-starter-web</artifactId>

</dependency>

</dependencies>



定义spring boot的打包方式

Build标签用于打包方式

Spring boot 是通过插件的形式来帮助我们进行项目的构建

增加plugins 一系列插件

Plugin插件

  

Spring-boot-maven-plugin这个东西就可以帮助我们打包时，自动将所有的类和资源整合成一个独立的可运行的jar包



<build>

<plugins>

<plugin>

<groupId>org.springframework.boot</groupId>

<artifactId>spring-boot-maven-plugin</artifactId>

</plugin>

</plugins>

</build>



@SpringBootApplication

public class Class{

public static void main(String[] args){

SpringApplication.run(Class.class);

}

}



Spring Boot 启动流程



加载配置文件

application.properties 



自动装配 就是组件级的IOC+DI

spring-boot-starter-web



加载组件

@Entity



应用初始化

初始化 Tomcat 组件

初始化 日志组件





Spring Boot 常用配置

server.port=80 指定端口

server.servlet.context-path=/springboot 增加应用上下文

logging.file=/usr/local/springboot/springboot.log  指定日志文件输出路径

logging.level.root=debug/info/warn/error/fatal 日志输出级别 默认是info

debug=true 开启调试模式 日志级别强制改为debug

spring.datasource.driver-class-name=com.mysql.jdbc.Driver

spring.datasource.url=jdbc:mysql:///数据库名

spring.datasource.username=root

spring.datasource.password=toor



spring:

 profiles:

  active: dev/prd

yml 格式自定义配置文件

key:

 key: value





注入配置文件自定义属性 会自动进行类型转换

@value("${key.key}")



String.format("%s",变量名);





环境配置文件

application-dev.yml

application-prd.yml

application.yml

bootstrap.yml 优先加载





打包 

mvn package 将当前工程打包为jar

启动 java -jar xxx.jar

与jar包同一目录的配置文件可被加载 覆盖jar包内部的



@EnableAutoConfiguration 开启自动装配



Spring boot 应用监控

management.endpoints.web.exposure.include=*

management.endpoint.health.show-details=always

http://localhost:8080/actuator/refresh





Spring boot 常用注解

@SpringBootApplication

@Repository

@Service

@RestController = @Controller @ResponseBody

@ResponseBody

@Component

@Autowired

@Qualifier("")

@Resource(name="name")

@RequestMapping

@RequestParam(value="请求参数名") 不写value 默认 以参数的默认名

@PathVariable





@EnableAutoConfiguration

@Configuration 相当于xml <beans></beans>

@Bean // new 对象 在方法上 需要@Configuration 配合使用

@ComponentScan(basePackages={String})

@Profiles("dev/prd") 需要配合@Configuration 在环境不同加载类

@ConfigurationProperties(prefix="xxx") 前缀

@PropertySource("classpath:xxx.properties")

@RestControllerAdvice 捕获异常通知类

@ExceptionHandler(Class) 捕获指定的异常类



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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MDAwNSwiaWF0IjoxNjE1NTQ1MjA1LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.9kmR9btTOuslSPaYH1aOZ0SydK9afB7MujfkuZhK39Y&download=image.png "")

