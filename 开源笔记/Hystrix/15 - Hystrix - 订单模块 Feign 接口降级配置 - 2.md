![](https://tcs.teambition.net/storage/3121aabd00ff14d1985a0336c50386f6ea29?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc2MywiaWF0IjoxNjEyMTkwOTYzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhYWJkMDBmZjE0ZDE5ODVhMDMzNmM1MDM4NmY2ZWEyOSJ9.GBjT5CJGnx5Clf7uGfU_SDhBIleYJpiEcgyzeL6IOz0&download=2020-09-17%20055006.png "")

![](https://tcs.teambition.net/storage/3121965dae6beeda6b279fc5810420a15688?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc2MywiaWF0IjoxNjEyMTkwOTYzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5NjVkYWU2YmVlZGE2YjI3OWZjNTgxMDQyMGExNTY4OCJ9.UrW_Np5L1h6MjNcs5j77yilifFHIW9oeTIsp8S07qro&download=2020-09-17%20055023.png "")

假的RequestMapping



![](https://tcs.teambition.net/storage/312196f7537d07f8efcfa5f8634475533d56?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc2MywiaWF0IjoxNjEyMTkwOTYzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5NmY3NTM3ZDA3ZjhlZmNmYTVmODYzNDQ3NTUzM2Q1NiJ9.wOvTIEM2v9wGS0h71Z-LJmC7uV9nDkz6S75edFJMOXQ&download=image.png "")



静默降级

![](https://tcs.teambition.net/storage/312143eb38376864176e5ac964d0b3f72b22?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc2MywiaWF0IjoxNjEyMTkwOTYzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0M2ViMzgzNzY4NjQxNzZlNWFjOTY0ZDBiM2Y3MmIyMiJ9.O0GfgCYm_-TLTVNg6G_qSVqNG92b6RvkfCvAZOhHe_Q&download=image.png "")

```java
package com.imooc.order.fallback.itemservice;

import com.google.common.collect.Lists;
import com.imooc.item.pojo.vo.MyCommentVO;
import com.imooc.pojo.PagedGridResult;
import feign.hystrix.FallbackFactory;
import org.springframework.stereotype.Component;

import java.util.Map;

@Component
public class ItemCommentsFallbackFactory implements FallbackFactory<ItemCommentsFeignClient> {
    @Override
    public ItemCommentsFeignClient create(Throwable throwable) {
        return new ItemCommentsFeignClient() {

            @Override
            public PagedGridResult queryMyComments(String userId, Integer page, Integer pageSize) {
                MyCommentVO commentVO = new MyCommentVO();
                commentVO.setContent("正在加载中");
                PagedGridResult result = new PagedGridResult();
                result.setRows(Lists.newArrayList(commentVO));
                result.setTotal(1);
                result.setRecords(1);
                return result;
            }

            @Override
            public void saveComments(Map<String, Object> map) {

            }
        };
    }
}

```

![](https://tcs.teambition.net/storage/3121c2ccea6e19d837f4836c5407fc9e991f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc2MywiaWF0IjoxNjEyMTkwOTYzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjMmNjZWE2ZTE5ZDgzN2Y0ODM2YzU0MDdmYzllOTkxZiJ9.aPQ8G2aa-_hDb_NeYXJSL3TsPYtRRFvuYaFDe9iYQkc&download=image.png "")

```java
package com.imooc.order.fallback.itemservice;

import com.imooc.item.service.ItemCommentsService;
import org.springframework.cloud.openfeign.FeignClient;


/**
 * 讨厌的地方来了，对于需要在调用端指定降级业务的场景来说，由于@RequestMapping和@xxxMapping注解
 * 可以从原始接口上继承，因此不能配置两个完全一样的访问路径，否则启动报错。
 * <p>
 * 在我们的实际案例中，ItemCommentsService上面定义了RequestMapping，同时
 * ItemCommentsServiceFeign继承自ItemCommentsService，因此相当于在Spring上下文
 * 中加载了两个访问路径一样的方法，会报错"Ambiguous mapping"
 * <p>
 * 解决问题的思路就是，避免让Spring的上下文中，同时加载两个访问路径相同的方法
 * <p>
 * 解决方案：
 * 1）在启动类扫包的时候，不要把原始Feign接口扫描进来
 * 具体做法：可以使用EnableFeignClients注解的clients属性，只加载需要的Feign接口
 * * 优点：服务提供者和服务调用者都不需要额外的配置
 * * 缺点：启动的时候配置麻烦一点，要指定加载每一个用到的接口
 * <p>
 * 2) 原始Feign接口不要定义RequestMapping注解
 * 优点：启动的时候直接扫包即可，不用指定加载接口
 * 缺点：a, 服务提供者要额外配置路径访问的注解
 * b, 任何情况下，即使不需要在调用端定义fallback类，服务调用者都需要声明一个
 * <p>
 * 3) 原始Feign接口不要定义@FeignClients注解，这样就不会被加载到上下文当中
 * * 优点：启动的时候直接扫包即可，不用指定加载接口，服务提供者不用额外配置
 * * 缺点：任何情况下，服务调用者都需要声明一个额外@FeignCliet接口
 * <p>
 * 各有利弊，按照喜好来选就行，个人比较喜欢1），毕竟懒人
 */
//@FeignClient(value = "foodie-item-service", fallback = ItemCommentsFallback.class)
@FeignClient(value = "foodie-item-service", fallbackFactory = ItemCommentsFallbackFactory.class)
public interface ItemCommentsFeignClient extends ItemCommentsService {

}

```

![](https://tcs.teambition.net/storage/31218a420ad6ea1831be65afc47236cd9a21?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc2MywiaWF0IjoxNjEyMTkwOTYzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4YTQyMGFkNmVhMTgzMWJlNjVhZmM0NzIzNmNkOWEyMSJ9.7AWvnpSURs2UHImKv57Vd4yzloP6at6pLTNiwpnqrek&download=image.png "")

```java
package com.imooc.order.fallback.itemservice;

import com.google.common.collect.Lists;
import com.imooc.item.pojo.vo.MyCommentVO;
import com.imooc.pojo.PagedGridResult;
import org.springframework.stereotype.Component;
import org.springframework.web.bind.annotation.RequestMapping;

import java.util.Map;

@Component
@RequestMapping("JokeJoke")
public class ItemCommentsFallback implements ItemCommentsFeignClient {

    @Override
    // HystrixCommand - 可以实现多级降级
    public PagedGridResult queryMyComments(String userId, Integer page, Integer pageSize) {
        MyCommentVO commentVO = new MyCommentVO();
        commentVO.setContent("正在加载中");
        PagedGridResult result = new PagedGridResult();
        result.setRows(Lists.newArrayList(commentVO));
        result.setTotal(1);
        result.setRecords(1);
        return result;
    }

    @Override
    public void saveComments(Map<String, Object> map) {

    }
}

```

![](https://tcs.teambition.net/storage/3121dc82e6be0f1b3f13b0fce42a0ec95c47?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc2MywiaWF0IjoxNjEyMTkwOTYzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFkYzgyZTZiZTBmMWIzZjEzYjBmY2U0MmEwZWM5NWM0NyJ9.HR1mxaB68ESTz_xUSm4x4MhFpNogfE6pwJLeEEI5cjY&download=image.png "")

![](https://tcs.teambition.net/storage/3121648f14f5dba9bdf086d56db8f7dc44ce?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc2MywiaWF0IjoxNjEyMTkwOTYzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2NDhmMTRmNWRiYTliZGYwODZkNTZkYjhmN2RjNDRjZSJ9.Eypj48f-F2K8obcTMBl4pTPp77I0vBUN7UgP8x1wBCE&download=image.png "")

![](https://tcs.teambition.net/storage/3121ead25cabb0d5644e7c5348ebd10dbca7?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc2MywiaWF0IjoxNjEyMTkwOTYzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFlYWQyNWNhYmIwZDU2NDRlN2M1MzQ4ZWJkMTBkYmNhNyJ9.JL1aoMW8iSItaeQqRSeu8hAgKDGU1sC8-X_yPy2rYWM&download=image.png "")

```json
{
    "status": 200,
    "msg": "OK",
    "data": {
        "page": 0,
        "total": 1,
        "records": 1,
        "rows": [
            {
                "commentId": null,
                "content": "正在加载中",
                "createdTime": null,
                "itemId": null,
                "itemName": null,
                "specName": null,
                "itemImg": null
            }
        ]
    }
}

```

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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NTc2MywiaWF0IjoxNjEyMTkwOTYzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.yHj1xctSiYcCz_QHeHIk9rING7zfj5zAKxO5kJEV6hA&download=image.png "")

