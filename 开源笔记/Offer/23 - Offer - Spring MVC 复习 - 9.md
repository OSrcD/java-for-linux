MVC 设计模式

C 就是 Controller 层

M 就是 Service层 Dao & Pojo层 DataBase层

V 就是视图层 比如 jsp



三层架构 

Web层 = V + C

Service层 = M

Dao & Pojo层 = M

DataBase 层 = M



Dispatcher 调度器 分发器 派发器 控制器 

HandlerExecutionChain 包含HandlerInterceptor 和 Handler

![](https://tcs.teambition.net/storage/31234581a76872a9ba1595e48250df4eb412?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MjAwOCwiaWF0IjoxNjE1NTQ3MjA4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM0NTgxYTc2ODcyYTliYTE1OTVlNDgyNTBkZjRlYjQxMiJ9.pYLKI207gIS7skHYiEmcgHd7IwR26DPhqxfSAAQjIgI&download=image.png "")

1. 客户端请求Dispatcher

1. Dispatcher 通过 HandlerMapping 获取Handler 返回 HandlerExecutionChain

1. 请求HandlerAdapter 验证表单数据 类型转换 封装到Bean对象

1. 执行Handler 返回 ModelAndView

1. DispatcherServlet 拿到 ModelAndView 请求 ViewResolver 解析为物理视>图返回 View

1. DispatcherServlet 返回给浏览器渲染



<servlet>

<servlet-name>SpringMVC</servlet-name>

<servlet-class>DispatcherServlet</servlet-class>

<init-param>

<param-name>contextConfigLocation</param-name>

<param-value>classpath:applicationContext.xml</param-vlaue>

</init-param>

</servlet>



<serlvet-mapping>

<servlet-name>SpringMVC</servlet-name>

<url-pattern>/</url-pattern>

</servlet-mapping>



implements Controller

handleRequest(HttpServletRequest,HttpSerlvetResponse)

new ModelAndView();

modelAndView.addObject(String,Object)

modelAndView.setViewName(String);



<bean id="simpleUrlHandlerMapping" class="SimpleUrlHandlerMapping">

<property name="mappings">

<props>

<prop key="/handleRequest">controller</prop>

</props>

</property>

</bean>



<bean id="controller" class="Controller">

</bean>



<bean class="InternelResourceViewResolver">

<property name="prefix" value="/WEB-INF/pages/" />

<property name="suffix" value=".jsp" />

</bean>

return "/WEB-INF/pages/index.jsp"



@Controller 标注是一个Controller类



@RequestMapping("/路径")

@RequestMapping(value = "/路径")

String handleRequest(Model)

model.addAttribute(String,Object)

return "" // 相当于modelAndView.setViewName("")

还有

Map<String,Object> map // 相当于Model

map.put(String,Object);

return ""



处理中文乱码

<filter>

<filter-name>characterEncodingFilter</filter-name>

<filter-class>CharacterEncodingFilter</filter-class>

<init-param>

<param-name>encoding</param-name>

<param-value>UTF-8</param-value>

</init-param>

<init-param>

<param-name>forceEncoding</param-name>

<param-value>true</param-value>

</init-param>

</filter>



<filter-mapping>

<filter-name>characterEncodingFilter</filter-name>

<url-pattern>/*</url-pattern>

</filter-mapping>



配置DispatcherServlet 放行静态资源

<servlet-mapping>

<servlet-name>default</servlet-name>

<url-pattern>*.css</url-pattern>

</servlet-mapping>





Spring MVC 数据绑定



HandlerAdapter 调用HttpMessageConverter 把表单中的数据封装到形式参数里面去





@ResponseBody 直接返回数据到前端



@RequestBody 注解将请求当中的json字符串转换为对象

@RequestParam(value="请求参数名") 将请求指定的参数名拿出来绑定到特定形参里面去



整形绑定

?id=

@RequestParam(value="id") int id



包装类绑定

?id=

@RequestParam(value="id") Integer id // 自动装箱



?key=value&key=value

数组类型绑定

String[] string

存进去的都是value



对象类型绑定

前端 name=“对象属性名” 跟java对象属性名一样

级联对象 name="级联对象名.属性名" java对象中包含另外一个对象名





List 集合绑定

集合不能直接绑定

需要定义类包含一个List集合

private class Class{

private List<对象> list

}

绑定的时候写Class class

前端使用属性名 name ="list[0].对象属性名"

list[0].级联对象名.对象属性名





Map 集合绑定

class Class {

Map<String,对象名> map

}

绑定的时候写 Class class

前端写 name="map['对象键名'].对象属性名"

级联对象 name="map['对象键名'].级联对象名.对象属性名"



Set 集合绑定

class Class{

提前 new

Set<对象> set = new HashSet<>()

}

需要提前初始化

public Class{

set.add(new 对象());

set.add(new 对象());

}

绑定的时候写 Class class

前端写 name="set[0].对象属性名"

级联绑定 name="set[0].级联对象名.对象属性名"



Json类型绑定

<mvc:annotation>

<mvc:message-converters>

<bean class="MappingJackson2HttpMessageConverter" />

</mvc:message-converters>

</mvc:annotation

在对象上使用 @RequestBody

前端使用JSON.stringify(json对象)

@ResponseBody 把数据类型转换为Json格式



Restful风格

Get 获取资源 /参数值

Post 增加资源 json字符串

Put 修改资源 json字符串

Delete 删除资源 /参数值

直接写参数值就行了



将前端的Post请求隐藏域的 Put Delete 转换为特定的请求需要配置过滤器

<filter>

<filter-name>hiddenHttpMethodFilter</fitler-name>

<filter-class>HiddenHttpMethodFilter</filter-class>

</filter>



<filter-mapping>

<filter-name>hiddenHttpMethodFilter</filter-name>

<url-pattern>/*</url-pattern>

<filter-mapping>



@PostMapping(value="/")

@GetMapping(value="/getById/{id}") 把请求参数值起一个别名为id  比如 /getById/1

@PathVariable(value="id" int id) 把别名id 赋值给当前形参

@PutMapping(value="/")

@DeleteMapping(value="/")

return "redirect:/getAll" 重定向到getAll









把当前的Post请求转换为Put请求

<input type="hidden" name="_method" value="PUT" />





<input type="hidden" name="_method" value="DELETE" />



拦截器

配置名

[servlet-name]-servlet.xml 跟 web.xml 同目录 也是在WEB-INF目录下

applicationContext-serlvet.xml



命名空间配置

必须放到WEB-INF目录下

放到DispatcherServlet下

<init-param>

<param-name>namespace</param-name>

<param-value>applicationContext</param-value>

</init-param>



通过contextConfigLocation 文件放大resource目录下

<init-param>

<param-name>contextConfigLocation</param-name>

<param-value>classpath:applicationContext.xml</param-value>

</init-param>



过滤器是拦截Request对象的请求和Response对象的响应 使用Filter接口



拦截器可以拦截方法的 使用jdk动态代理来拦截



类级别 @RequestMapping("/index") 起了一个前缀 /index



浏览器发起请求->doFilter->spring aop -> servlet.service->调用完service方法返回响应spring aop后处理->dofilter后处理->浏览器接收请求

![](https://tcs.teambition.net/storage/3123b1e09a1f733300db1252cf6abdb05de0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MjAwOCwiaWF0IjoxNjE1NTQ3MjA4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjNiMWUwOWExZjczMzMwMGRiMTI1MmNmNmFiZGIwNWRlMCJ9.lAPAJS-ZtRHC5llyn01XVHEJK2Q5pSXEPMgSjBaRK-g&download=image.png "")

![](https://tcs.teambition.net/storage/312319fbda858a3e6d6bd2e1c8082f81a103?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MjAwOCwiaWF0IjoxNjE1NTQ3MjA4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjMxOWZiZGE4NThhM2U2ZDZiZDJlMWM4MDgyZjgxYTEwMyJ9.6p2jQGc2UQj2LuDmPycdfPIM5JrZ6a3jHnntOFfGr20&download=image.png "")

implements HandlerInterceptor

preHandle(HttpServletRequest,HttpServletResponse,Object handler)

handler.getClass() // 当前执行的类 也就是 class 包名.IndexController

handler // 直接打印Controller的toString()方法

return false 终止请求

postHandle(HttpServletRequest,HttpServletResponse,Object handler)



afterCompletion(HttpServletRequest,HttpServletResponse,Object handler)



<mvc:interceptors>

<mvc:interceptor>

<mvc:mapping path="/index/*" /> 只能匹配一级

<mvc:mapping path="/index/**" /> 递归可匹配子级

<mvc:exclude-mapping path="/index/category/*" /> 忽略这个路径

<bean class="拦截器"></bean>

</mvc:interceptor>



<mvc:interceptor>

<mvc:mapping path="/index/*" /> 只能匹配一级

<mvc:mapping path="/index/**" /> 递归可匹配子级

<mvc:exclude-mapping path="/index/category/*" /> 忽略这个路径

<bean class="另外一个拦截器"></bean>

</mvc:interceptor>

</mvc:interceptors>



拦截器栈 按照配置顺序执行

两个拦截器

第一个拦截器preHandler return true 

第二个拦截器preHandler return false

没有执行Controller方法就不会有 postHandler执行

return 为false的就不会执行拦截器里面的 postHandler afterCompletion了

只会执行return 为 true的第一个拦截器的 afterCompletion



postHandler和afterCompletion是逆序执行



DS调用视图解析器解析

视图解析器解析成物理视图，装载模型数据返回的时候然后

执行过滤器的aftercompletion方法

DS把视图解析器填充好的模型数据的物理视图返回给客户端浏览器渲染







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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MjAwOCwiaWF0IjoxNjE1NTQ3MjA4LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.N9U-YgDFj5oFCu_8rbqFja9TcnSxJE06utWhb_vGEaM&download=image.png "")

