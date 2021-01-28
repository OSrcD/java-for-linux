![](https://tcs.teambition.net/storage/312127acc718c8e2813d8fa6447c13d2eeec?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYyMywiaWF0IjoxNjExODQzODIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyN2FjYzcxOGM4ZTI4MTNkOGZhNjQ0N2MxM2QyZWVlYyJ9.D1jtXb7bNhRUIpTXzS18IB_hygZj63s8x_u-BhYOBQw&download=image.png "")

![](https://tcs.teambition.net/storage/312101709499f0053df6ffa65a64d6391d30?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYyMywiaWF0IjoxNjExODQzODIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwMTcwOTQ5OWYwMDUzZGY2ZmZhNjVhNjRkNjM5MWQzMCJ9.yS7tB_Ldag_JPCgpK_jxwBjQd0grLJ9jHDbBjXt9beE&download=image.png "")

```java
package com.imooc.springcloud;

import lombok.Builder;
import lombok.Data;

@Data
@Builder
public class Product {

    private Long productId;

    private String description;

    private Long stock;
}



```

![](https://tcs.teambition.net/storage/31211a550e401a77e3e621e60a93c9ae78c0?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYyMywiaWF0IjoxNjExODQzODIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExYTU1MGU0MDFhNzdlM2U2MjFlNjBhOTNjOWFlNzhjMCJ9.ibX5_cs_6R65BXYuxU0IrZYkYVpTghMGGGSxMAag-x4&download=image.png "")

```java
package com.imooc.springcloud;

import lombok.extern.slf4j.Slf4j;
import org.springframework.web.bind.annotation.*;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

@RestController
@Slf4j
@RequestMapping("gateway")
public class GatewayController {

    public static final Map<Long, Product> items = new ConcurrentHashMap<>();

    @RequestMapping(value = "details", method = RequestMethod.GET)
    @ResponseBody
    public Product get(@RequestParam("pid") Long pid) {
        if (!items.containsKey(pid)) {
            Product prod = Product.builder()
                    .productId(pid)
                    .description("好吃不贵")
                    .stock(100L)
                    .build();
            /**
             * 不存在的时候 才 put 有可能两个方法同时执行到了这里 会产生线程不安全的操作
             * 在业务层次上 这可不是线程安全的
             */
            items.putIfAbsent(pid, prod);
        }

        return items.get(pid);

    }

    @RequestMapping(value = "placeOrder", method = RequestMethod.POST)
    public String buy(@RequestParam("pid") Long pid) {
        Product prod = items.get(pid);

        if (prod == null) {
            return "Product not found";
        } else if (prod.getStock() <= 0L) {
            return "Sold out";
        }
        /**
         * 有两个线程同时执行到了这里
         * 哪它接下来 执行 synchronized 的时候 如果不加 if 判断 哪都可能会处于有货状态
         * 就会发生超卖
         */
        synchronized (prod) {
            if (prod.getStock() <= 0L) {
                return "Sold out";
            }
            prod.setStock(prod.getStock() - 1);

        }
        return "Order Placed";
    }
}

```

![](https://tcs.teambition.net/storage/312180646e8465fe92ba7558a2f723646eba?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYyMywiaWF0IjoxNjExODQzODIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4MDY0NmU4NDY1ZmU5MmJhNzU1OGEyZjcyMzY0NmViYSJ9.efJ1BmsYo2hjnboMid7T6hjxuYxOhlrmQnckqX_wRmc&download=image.png "")

```java
package com.imooc.springcloud;

import org.springframework.cloud.gateway.route.RouteLocator;
import org.springframework.cloud.gateway.route.builder.RouteLocatorBuilder;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.core.annotation.Order;
import org.springframework.http.HttpMethod;

import java.time.ZonedDateTime;

@Configuration
public class GatewayConfiguration {

    /**
     * RouteLocator 地址定位
     * Bean 注解 会作为初始化的一部分 自然有一个在当前上下文中已经初始化好的 builder 传给你
     * Order 默认加载顺序为 2147483647
     */
    @Bean
    @Order
    public RouteLocator customizedRoutes(RouteLocatorBuilder builder) {
        return builder.routes()
                // 每一个 route 相当于 yml 配置的 element
                .route(r -> r.path("/java/**")
                        .and().method(HttpMethod.GET)
                        .and().header("name")
                        .filters(f -> f.stripPrefix(1)
                                .addResponseHeader("java-param", "gateway-config")
                        )
                        .uri("lb://FEIGN-CLIENT")
                )
                .route(r -> r.path("/seckill/**")
                        .and()
                        /**
                         * 告诉 Gateway 当前的这个路由规则 只在某个时间点以后生效
                         * now 也就是当前的时间点
                         * 它是说 当你服务启动加载完成以后 往后推迟一分钟生效
                         * 也就是 一分钟后才生效的秒杀场景
                         * before 是说在某个时间点以前 路由规则才生效 过了这个时间点就生效
                         * between 这个路由规则 会在这两个时间段生效
                         */
                        .after(ZonedDateTime.now().plusMinutes(1))
//                        .and().before()
//                        .and().between()
                        .filters(f -> f.stripPrefix(1))
                        .uri("lb://FEIGN-CLIENT")
                )
                // 把当前 builder 所有的属性全部组装最终返回一个完整的 RouteLocator 对象
                .build();

    }

}

```

![](https://tcs.teambition.net/storage/31212cccc73e544637d25379a2350590f911?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYyMywiaWF0IjoxNjExODQzODIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyY2NjYzczZTU0NDYzN2QyNTM3OWEyMzUwNTkwZjkxMSJ9.s3vZvwYuclEfZj9tP8x85siCp40N9T2G54nmDNspWXs&download=image.png "")

![](https://tcs.teambition.net/storage/312191c07fb275f8160dc1cdd91e74ffa7a6?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYyMywiaWF0IjoxNjExODQzODIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5MWMwN2ZiMjc1ZjgxNjBkYzFjZGQ5MWU3NGZmYTdhNiJ9.iopMF7kMR10MMU7Of_xurEKaA_T9gDDwRIBVAunSg5M&download=image.png "")

![](https://tcs.teambition.net/storage/31216755fa8079f82bff955becdecf6c87be?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYyMywiaWF0IjoxNjExODQzODIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2NzU1ZmE4MDc5ZjgyYmZmOTU1YmVjZGVjZjZjODdiZSJ9.L-BY1aTGvlz_1z-__c4yOUggQbCCWqpTr6CzfJRYQc8&download=image.png "")

![](https://tcs.teambition.net/storage/31218ad2d76e2645deeb83e6ca98ff755ddd?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYyMywiaWF0IjoxNjExODQzODIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4YWQyZDc2ZTI2NDVkZWViODNlNmNhOThmZjc1NWRkZCJ9.0WymMwuJacCA52svXSmZZaHC8909KWtKtTvcKWpk41I&download=image.png "")

通过网关调用

![](https://tcs.teambition.net/storage/3121639873d0cec2fb5b4f27f7eb46b9691f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYyMywiaWF0IjoxNjExODQzODIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2Mzk4NzNkMGNlYzJmYjViNGYyN2Y3ZWI0NmI5NjkxZiJ9.eHVzMgL4OgFI6ElTpYGs_beqScFJz6M7f4nXry24bXE&download=image.png "")

![](https://tcs.teambition.net/storage/31213a447b0181713c8f7faa63e45b7ca41f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYyMywiaWF0IjoxNjExODQzODIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzYTQ0N2IwMTgxNzEzYzhmN2ZhYTYzZTQ1YjdjYTQxZiJ9.eMPdiusIOF_wIktnCrkEGEoxvdLZgWHHaubJ-p5v5t8&download=image.png "")

测试时间

![](https://tcs.teambition.net/storage/3121680633d30d6d2ed41fd93722cea15283?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYyMywiaWF0IjoxNjExODQzODIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2ODA2MzNkMzBkNmQyZWQ0MWZkOTM3MjJjZWExNTI4MyJ9.XLa3O2pWwHCqJ3dX7CucGLAhGPa59DSyRT9bcBbw7oo&download=image.png "")

![](https://tcs.teambition.net/storage/31214f8fb2fd114c6eb06cc8762ced05801a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYyMywiaWF0IjoxNjExODQzODIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0ZjhmYjJmZDExNGM2ZWIwNmNjODc2MmNlZDA1ODAxYSJ9.UueVq4XyyBPmULpvIj7geIRZNK-Xgh20iONVI94Ogsk&download=image.png "")

![](https://tcs.teambition.net/storage/31210ffd515e9ec42e0f8b1a54e7788f3f3e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYyMywiaWF0IjoxNjExODQzODIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwZmZkNTE1ZTllYzQyZTBmOGIxYTU0ZTc3ODhmM2YzZSJ9.7ZNMLlFZ90HsMiKhllKbRoMjiujxzRGnH35mj1LEfs4&download=image.png "")





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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjQ0ODYyMywiaWF0IjoxNjExODQzODIzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.Jl5XAiQ48MgznzZ-cM5yW6Zg4ChFkHH7C1Q6suP65yU&download=image.png "")

