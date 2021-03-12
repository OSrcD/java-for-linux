通过DNS服务器解析 拿到IP地址 浏览器去访问 服务器响应

![](https://tcs.teambition.net/storage/312338e4c6e1096330b459438d63e7e82dec?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkxNywiaWF0IjoxNjE1NTQ3MTE3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjMzOGU0YzZlMTA5NjMzMGI0NTk0MzhkNjNlN2U4MmRlYyJ9.pxvY2XsNkIBMBut3s7xWhaqIRZEvikQBcJyhr1EEaUI&download=image.png "")

J2EE 核心模块 Servlet JDBC WebSocket

tomcat 默认地址 8080 

https 端口 443

http端口 80



HttpServletRequest 请求对象

HttpServletResponse 响应对象

HttpSession 用户会话

ServletContext 应用全局对象

PrintWriter 输出对象

this 当前页面对象

PageContext 页面上下文对象 中转站 获取其他对象 

ServletConfig 应用配置对象

Throwable 应用异常对象

RequestDispatch 请求控制器对象

Cookie 对象



继承HttpServlet



service(HttpServletRequest,HttpServletResponse) 处理所有请求 重写了该方法默认调用该方法

HttpServlet.doGet(HttpServletRequest,HttpServletResponse) 处理 get 请求 没有重写Service方法 会判断请求是什么方法就进入什么方法 Get请求用于查询

HttpServlet.doPost(HttpServletRequest,HttpServletReponse) 处理post请求 用于增删改

init(ServletConfig)

 destroy()



PrintStream 格式化字节输出流

PrintWriter 格式化字符输出流

PrintWriter.println(String) 写html代码 字符串等 服务器会自动返回放到Response里面



HttpServletRequest.getParameter(String) 拿到请求参数 /映射地址?name=xxx

HttpServletRequest.getParameterValues(String); 接收多个同名的参数 浏览器get请求有多个相同的名称 ?name=xx&name=xx  返回一个 字符串数组 

HttpServletRequest.getHeader(String)

HttpServletRequest.getReuqestDispatcher("转发Servlet映射路径").forward(HttpServletRequest,HttpServletReponse)  方法间的跳转 一次请求 从一个servlet 跳转到另外一个Servlet 

HttpServletRequest.setAttribute(String,String)

HttpServletRequest.getAttribute(String)



HttpServletResponse.getWriter() 获得PrintWriter

HttpServletResponse.setContentType(String)

HttpServletResponse.sendRedirect(String) 上下文路径加映射地址 url会变 二次请求 第一个Servlet被销毁了 拿不到Attribute











<servlet>

<servlet-name>字符串</servlet-name>

<servlet-class>包名</servlet-class>

<load-on-startup>0-9999</load-on-startup> 启动时加载Servlet 负数表示不加载 

</servelt>



<servlet-mapping>

<servlet-name>字符串</servlet-name>

<url-pattern>/</url-pattern>

</servlet-mapping>



jdk 新特性 文本块

"""

"""



![](https://tcs.teambition.net/storage/31238b4c8b16cfa875e01352bb3fc9b2e9c8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkxNywiaWF0IjoxNjE1NTQ3MTE3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM4YjRjOGIxNmNmYTg3NWUwMTM1MmJiM2ZjOWIyZTljOCJ9.XYPtEniRB5ZIu4CoNhn0RMoC7rQhZaYy_WVSLQzyY8Y&download=image.png "")

get方法 ?xx=xx 浏览器的 Query String Parameters 里面 key:value 也就是放在url

post 方法参数放到请求体 放在浏览器的Form Data里面 key:value



Servlet的生命周期

调用默认构造方法

调用init(ServletConfig)



根据请求调用 service 方法 或者 doGet doPost方法



销毁方法 destroy() 重新加载 Tomcat 会销毁 servlet  加代码的方式



@WebServlet("/") 配置映射路径

@WebServlet(urlPatterns="/",loadOnStartup=数字) 配置映射路径 启动时加载



请求行 

方法  Post Get 





请求头 

header User-Agent:xxxx;

Content-Type:xxxxx





Host:

Cookie:JSESSIONID=xxxx



请求体





响应行 状态码

响应头 

Content-Type:text/html;charset=utf-8 



响应体



text/html:charset=utf-8 响应html

text/plain;charset=utf-8 响应纯文本 字符串

text/xml;charset=utf-8 响应xml文本

application/x-msdownload;charset=utf-8 下载当前文本文件







cookie 

浏览器内置对象



new Cookie(String,Object);

HttpServletResponse.addCookie(Cookie) 服务端发送Cookie给浏览器 在响应头里面 set-cookie:key=value

之后通过浏览器在Header 携带 Cookie:key=value 发送给服务端

HttpServletRequest.getCookies(); 拿到Cookie数组

Cookie.getName() 拿到Key

Cookie.getValue() 拿到Value

Cookie 有效期是当前浏览器所有tap窗口 关闭就失效  了

cookie.setMaxAge(int) 设置Cookie有效期 秒单位





session 和浏览器窗口绑定 没人访问默认30分钟 关闭浏览器cookie会失效 但是服务端session没失效 tomcat会在30分钟之后没人使用删除

一个浏览器窗口对应一个session

Cookie:JSESSIONID=uui_d

httpServletRequest.getSession() 获取一个Session对象 在Tomcat内存堆区域开辟一个Session存储空间 需要getSession只能有set-cookie

通过响应set-cookie:JSESSIONID=值 给浏览器

httpSession.setAttribute(String,Object)

httpSession.getAttribute(String)

httpSession.getId();拿到JESSIONID值









SerlvetContext 

只有一个

应用启动就被创建 重启或关闭的时候销毁

httpServletRequest.getServletContext()

servletContext.setAttribute(String,Object)

servletContext.getAttribute(String)





Post请求乱码

Tomcat默认使用 ISO-8859-1 字符集 西欧字符集

解决方案1

new String(string.getBytes("iso-8859-1"),"utf-8")

解决方案2

httpServletRequest.setCharacterEncoding("utf-8")



使用过滤器 或者拦截器



Spring Boot 设置字符集

server.tomcat.uri-encoding=UTF-8



get 请求乱码问题

在server.xml 文件 设置 <Connector URIEncoding="UTF-8" /> 

Tomcat 7 以前需要设置 7是 ISO-8859-1

Tomcat 8 默认就是这个



webxml常用配置



如果当前文件有index.html 和default.html 默认以index为首页

如果当前文件只有default.html 就以default为首页

<welcome-file-list>

<welcome-file>index.html</welcome-file>

<welcome-file>default.html</welcome-file>

</welcom-file-list>



@WebServlet("*") 通配符

xml 配置也能用通配符



httpServletRequest.getRequestURL() 获取浏览器地址栏全路径url



配置Servlet的参数

<init-param>

<param-name></param-name>

<param-value></param-value>

</init-param>



通过

servletConfig.getInitParameter(String)



配置 ServletContext 的参数

<context-param>

<param-name></param-name>

<param-value></param-value>

</context-param>

servletContext.getInitParameter(String)





配置错误页面

<error-page>

<error-code>404</error-code>

<location>指定webapp目录里面的html文件比如  /error/404.html</location>

</error-page>







pageContext.getRequest()

pageContext.getReponse()

pageContext.getSession()

pageContext.getServletContext()



在错误页获得异常信息

exception.getMessage()

获得抛出异常的类

exception.getClass().getSimpleName()



tomcat里面把webapps路径映射为\访问不用加工程上下文

server.xml

<Context docBase="war包目录" path="/">





Json



JSON.parse(String) 把json字符串解析为json对象

JSON.stringify(Object)把json对象解析为json字符串



fastjson

JSON.toJSONString(Object) 把对象解析为json字符串

JSON.parseObject(String,Object.class) 把json字符串解析为对象

JSON.parseArray(String,Object.class) 把json Array解析为List对象





java 过滤器

过滤器是Web应用启动就创建

web应用重启或者销毁 过滤器对象才被销毁

过滤器是对请求和响应对象的拦截



过滤器创建的顺序 取决于 在 web.xml 文件配置的顺序

过滤器链的调用顺序也是取决于在 web.xml 文件配置的顺序

调用 filterChain.doFilter(ServletRequest,ServletReponse) 交给tomcat服务器 后调用过滤器 如果没有就调用servlet的service方法

拦截器是对方法的拦截



![](https://tcs.teambition.net/storage/3123a26c0075eab0f322b031631d0df49698?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkxNywiaWF0IjoxNjE1NTQ3MTE3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjNhMjZjMDA3NWVhYjBmMzIyYjAzMTYzMWQwZGY0OTY5OCJ9.vk1LKc1ZR4BxCQ7VthOs3K7KgzNX84ubTD5v4MKMOWE&download=image.png "")

![](https://tcs.teambition.net/storage/31239ed903fdd41612f4f7b27877075bf8e8?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkxNywiaWF0IjoxNjE1NTQ3MTE3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM5ZWQ5MDNmZGQ0MTYxMmY0ZjdiMjc4NzcwNzViZjhlOCJ9.Kjvj3djiiVhFmDo_H5ktBGnyP8oFO0bxIrx_VJgA4mk&download=image.png "")





httpServletRequest.getContextPath(); 获得工程名





实现 Filter

doFilter(ServletRequest,ServetResponse,FilterChain)

init(FilterConfig)

destroy()



<filter>

<filter-name></filter-name>

<filter-class></filter-class>

过滤器初始化参数

<init-param>

<param-name></param-name>

<param-value></param-value>

</init-param>

</filter>



<filter-mapping>

<filter-name></filter-name>

<url-pattern>*或者/*</url-pattern>

request 默认 正常的访问方式

include 需要在其他jsp页面设置 <jsp:include page="/test2.jsp" /> 过滤器映射拦截的是其他jsp页面

forward 需要在jsp页面调用 request.getRequestDispatcher("").forward();  过滤器映射拦截的是转发到的页面 在过滤器doFIlter触发 转发同样也 可以被拦截到

error 需要配合error-page元素使用 访问错误页 过滤器映射拦截到的是错误页

可以配置多个dispatcher 但是调用的时候发检测是那种资源匹配方式，会以一种资源调用结果方式生效



<dispatcher>REQUEST</dispatcher>

<dispatcher>INCLUDE</dispatcher>

<dispatcher>FORWARD</dispatcher>

<dispatcher>ERROR</dispatcher>

</filter-mapping>







web启动会创建过滤器对象 

执行构造方法

执行init方法

拦截到匹配的url会执行doFilter方法

修改类文件触发销毁方法





filterConfig.getInitParameter(String)



过滤器编码

在doFilter方法调用 servletRequest.setCharacterEncoding("utf-8")



return 直接拦截掉





request 默认

include

forward

error



httpServletResponse.sendError(404); 返回错误码 如果配置了error-page 就会去调用该页面



调用顺序是注册的顺序



后处理也是调用dofilter 在filterChain.dofilter();下面的代码

浏览器发起请求->doFilter->spring aop -> servlet.service->调用完service方法返回响应spring aop后处理->dofilter后处理->浏览器接收请求



监听器

监听人是tomcat



监听器就是tomcat提供的监听器 

被监听器就是tomcat的内置对象

监听器事件就是被监听器触发的事件

监听器处理事件，就是tomcat会回调监听器处理事件

对象事件就是封装了获取对象和对象成员属性



架构 多个层组成

层 多个模块组成

模块多个组件组成

组件 多个包组成

包 多个类组成





监听对象

ServletContext

HttpSession

ServletRequest



监听器

ServletRequestAttributeListener



ServletRequestListener

reuqestInitialized(ServletRequestEvent)

servletRequestEvent.getServletRequest()

requestDestroyed(ServletRequestEvent)



ServletContextListener

ContextDestroyed(ServletContextEvent) 销毁对象

servletContextEvent.getServletContext()

ContextInitialized(ServletContextEvent) 创建对象



ServletContextAttributeListener

attributeAdded(ServletContextAttributeEvent) 属性添加

ServletContextAttributeEvent.getName() 获得key

ServletContextAttributeEvent.getValue() 获得value

attributeRemoved(ServletContextAttributeEvent) 属性移除

attributeReplaced(ServletContextAttributeEvent) 属性替换



HttpSessionAttributeListener



HttpSessionListener

sessionCreated(HttpSessionEvent) 

HttpSessionEvent.getSession(); 必须调用httpServletRequest.getSession()创建session对象就调用这个方法

sessionDestroyed(HttpSessionEvent) session对象销毁





HttpSessionBindingListener 在用户实体对象里实现这个接口 针对的是某个对象在Session的变     动

valueBound(HttpSessionBindingEvent) 从httpSession.setAttribute该用户实体对象时调用

HttpSessionBindingEvent.getName() 拿到的是 httpSession.setAttribute(key,new 用户实体对象) 

valueUnbound(HttpSessionBindingEvent) 监听器对象从Http会话内修改或移除 销毁时调用 比如httpSession.removeAttribute(key) 删除属性 



ServletContext 先创建

监听器是tomcat 启动应用的时候创建的 调用构造方法

监听对象的发生的事件 就会执行监听器里面的方法

<listener>

<listener-class>类名</listener-class>

</listener>

可触发销毁事件

![](https://tcs.teambition.net/storage/31231596e8615de5f95f4aaae6fd76aa4c6b?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkxNywiaWF0IjoxNjE1NTQ3MTE3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjMxNTk2ZTg2MTVkZTVmOTVmNGFhYWU2ZmQ3NmFhNGM2YiJ9.taXdCCGba4aPCUdZqsB5Pxk4CbizpSSSvEt1ecSG-F4&download=image.png "")

监听器对象与过滤器对象创建取决于创建的顺序

多个监听器监听同一个对象 取决于配置文件的注册顺序

而销毁的时候是逆序

![](https://tcs.teambition.net/storage/31237d3a98a7290716340f9ecde8a27b9cf0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkxNywiaWF0IjoxNjE1NTQ3MTE3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM3ZDNhOThhNzI5MDcxNjM0MGY5ZWNkZThhMjdiOWNmMCJ9.JxqRdls9XcoJmhF6JWaTPAEDSneATPgxTOqIC98rMHg&download=image.png "")

![](https://tcs.teambition.net/storage/3123200393ce02280e700a6e6f9be7961dcc?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkxNywiaWF0IjoxNjE1NTQ3MTE3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjMyMDAzOTNjZTAyMjgwZTcwMGE2ZTZmOWJlNzk2MWRjYyJ9.NwaeC0JRq_6WLWkMHBbQh2ihuumHCB8huqRt3aU88S4&download=image.png "")

httpSession.getCreationTime() session 创建时间 返回long

new Date(long)

直接用System.out.println(打印Date) 美国的格式化

![](https://tcs.teambition.net/storage/31238d1318c6d6d60b402c5224e7fd11e140?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkxNywiaWF0IjoxNjE1NTQ3MTE3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM4ZDEzMThjNmQ2ZDYwYjQwMmM1MjI0ZTdmZDExZTE0MCJ9.vEL7V3V_T-MLaGKdrts5-0aIDYblMeFLOdcSRFPZ5WE&download=image.png "")



配置session有效期 单位为分钟

<session-config>

<session-timeout>1</session-timeout>

</session-config>

httpServletRequest.getRequestURI(); 获得工程 名 和映射地址 包含参数

![](https://tcs.teambition.net/storage/31234086bd90c0d7b14f42bb5a0274a927ab?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkxNywiaWF0IjoxNjE1NTQ3MTE3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjM0MDg2YmQ5MGMwZDdiMTRmNDJiYjVhMDI3NGE5MjdhYiJ9.3mgmynjW45fFrdqlv833GvmGF_-MqZHhvDsYCxFWld4&download=image.png "")

![](https://tcs.teambition.net/storage/3123c30ff5ccb6b0773a68a3b21449b13bc4?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkxNywiaWF0IjoxNjE1NTQ3MTE3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjNjMzBmZjVjY2I2YjA3NzNhNjhhM2IyMTQ0OWIxM2JjNCJ9.mVUCOUUi0z7oaXHIfcJV7YebWuYemlmBQ6jD4AJ07Pk&download=image.png "")



@WebFilter("/*") 注解配置



@webListener 注解配置

@ServletComponentScan



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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxNjE1MTkxNywiaWF0IjoxNjE1NTQ3MTE3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.-46xMfKwH0sfQxYIKRmeX38vUsZgL7cAtPumSX3VDh4&download=image.png "")

