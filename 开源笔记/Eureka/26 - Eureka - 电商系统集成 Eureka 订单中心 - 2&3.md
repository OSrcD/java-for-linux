![]( "")

![](https://tcs.teambition.net/storage/312114970acc8bc2674ad6920e9377621c7d?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjQzNywiaWF0IjoxNjEyMTkxNjM3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExNDk3MGFjYzhiYzI2NzRhZDY5MjBlOTM3NzYyMWM3ZCJ9.24a7gxGtDBqqlwixAz8Mcf25POx1dawWFZaEIMVMUX0&download=image.png "")

```java
package com.imooc.order.service.impl.center;

import com.imooc.enums.YesOrNo;
import com.imooc.order.mapper.OrderItemsMapper;
import com.imooc.order.mapper.OrderStatusMapper;
import com.imooc.order.mapper.OrdersMapper;
import com.imooc.order.pojo.OrderItems;
import com.imooc.order.pojo.OrderStatus;
import com.imooc.order.pojo.Orders;
import com.imooc.order.pojo.bo.center.OrderItemsCommentBO;
import com.imooc.order.service.center.MyCommentsService;
import com.imooc.pojo.PagedGridResult;
import com.imooc.service.BaseService;
import org.n3r.idworker.Sid;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cloud.client.ServiceInstance;
import org.springframework.cloud.client.loadbalancer.LoadBalancerClient;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.client.RestTemplate;

import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@Service
public class MyCommentsServiceImpl extends BaseService implements MyCommentsService {

    @Autowired
    public OrderItemsMapper orderItemsMapper;

    @Autowired
    public OrdersMapper ordersMapper;

    @Autowired
    public OrderStatusMapper orderStatusMapper;

//    @Autowired
//    public ItemsCommentsMapperCustom itemsCommentsMapperCustom;
    // TODO feign章节里改成item-api
    @Autowired
    private LoadBalancerClient client;
    @Autowired
    private RestTemplate restTemplate;

    @Autowired
    private Sid sid;

    @Transactional(propagation = Propagation.SUPPORTS)
    @Override
    public List<OrderItems> queryPendingComment(String orderId) {
        OrderItems query = new OrderItems();
        query.setOrderId(orderId);
        return orderItemsMapper.select(query);
    }

    @Transactional(propagation = Propagation.REQUIRED)
    @Override
    public void saveComments(String orderId, String userId,
                             List<OrderItemsCommentBO> commentList) {

        // 1. 保存评价 items_comments
        for (OrderItemsCommentBO oic : commentList) {
            oic.setCommentId(sid.nextShort());
        }
        Map<String, Object> map = new HashMap<>();
        map.put("userId", userId);
        map.put("commentList", commentList);
//        itemsCommentsMapperCustom.saveComments(map);

        ServiceInstance instance = client.choose("FOODIE-ITEM-SERVICE");
        String url = String.format("http://%s:%s/item-comments-api/saveComments",
                instance.getHost(),
                instance.getPort());
        // TODO 偷个懒，不判断返回status，等下个章节用Feign重写
        restTemplate.postForLocation(url, map);

        // 2. 修改订单表改已评价 orders
        Orders order = new Orders();
        order.setId(orderId);
        order.setIsComment(YesOrNo.YES.type);
        ordersMapper.updateByPrimaryKeySelective(order);

        // 3. 修改订单状态表的留言时间 order_status
        OrderStatus orderStatus = new OrderStatus();
        orderStatus.setOrderId(orderId);
        orderStatus.setCommentTime(new Date());
        orderStatusMapper.updateByPrimaryKeySelective(orderStatus);
    }

    // TODO 移到了itemCommentService
//    @Transactional(propagation = Propagation.SUPPORTS)
//    @Override
//    public PagedGridResult queryMyComments(String userId,
//                                           Integer page,
//                                           Integer pageSize) {
//
//        Map<String, Object> map = new HashMap<>();
//        map.put("userId", userId);
//
//        PageHelper.startPage(page, pageSize);
//        List<MyCommentVO> list = itemsCommentsMapperCustom.queryMyComments(map);
//
//        return setterPagedGrid(list, page);
//    }
}

```

![](https://tcs.teambition.net/storage/3121551a11f958c91ab0b0fc218a6367da83?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjQzNywiaWF0IjoxNjEyMTkxNjM3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1NTFhMTFmOTU4YzkxYWIwYjBmYzIxOGE2MzY3ZGE4MyJ9.EZdaiB2kBpaqGLUpPCnmJ0ZWdOnUL8CUJdS7TJUpph4&download=image.png "")

![](https://tcs.teambition.net/storage/312154fde0942939da95a475d626cdf15443?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjQzNywiaWF0IjoxNjEyMTkxNjM3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1NGZkZTA5NDI5MzlkYTk1YTQ3NWQ2MjZjZGYxNTQ0MyJ9.kVusBdPYv_og47BEuHZouke41aMkaUVzfwbGO_j0X9A&download=image.png "")

![](https://tcs.teambition.net/storage/31211cf696ed541560a060ad950bb741fe2f?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjQzNywiaWF0IjoxNjEyMTkxNjM3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjExY2Y2OTZlZDU0MTU2MGEwNjBhZDk1MGJiNzQxZmUyZiJ9.p5VgBInRCkU4RwrgHkN3kK1BX-jU4PkWXRCxxkWibVo&download=image.png "")

![](https://tcs.teambition.net/storage/3121a6129b239ee9be0c0f23540239b9209e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjQzNywiaWF0IjoxNjEyMTkxNjM3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhNjEyOWIyMzllZTliZTBjMGYyMzU0MDIzOWI5MjA5ZSJ9.GkrNoCFd87MtA-_c67ssesazVQzmpBLuIn79Y6UMf94&download=image.png "")

![](https://tcs.teambition.net/storage/312179e61b4eaa951dc1886a86e6c0521f79?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjQzNywiaWF0IjoxNjEyMTkxNjM3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE3OWU2MWI0ZWFhOTUxZGMxODg2YTg2ZTZjMDUyMWY3OSJ9.kprNodnkgMrMRrOcnZbP8QMIyh2xdNLvgKmBUbbOORg&download=image.png "")

## 启动

![](https://tcs.teambition.net/storage/312169bb0d0ad773235cb68444517f65de97?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjQzNywiaWF0IjoxNjEyMTkxNjM3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2OWJiMGQwYWQ3NzMyMzVjYjY4NDQ0NTE3ZjY1ZGU5NyJ9.pV27-zGAgZKMjdxzogD7MwUpB_hWpTSynh9AW5vUJc4&download=image.png "")

![](https://tcs.teambition.net/storage/312159b1abd8ea470f32ff4d8bc2dfc3f1bd?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjQzNywiaWF0IjoxNjEyMTkxNjM3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1OWIxYWJkOGVhNDcwZjMyZmY0ZDhiYzJkZmMzZjFiZCJ9.G0sko_6ACU_EXleDXXfqUxfqyR0ScKyj-c2bdn-Z6r0&download=image.png "")

![](https://tcs.teambition.net/storage/3121c2e11c5516fe4f7bb6d184f893159829?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjQzNywiaWF0IjoxNjEyMTkxNjM3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjMmUxMWM1NTE2ZmU0ZjdiYjZkMTg0Zjg5MzE1OTgyOSJ9.EKgAnOLKwaN-qoqlI9h7pm9EHehU27VQJdznoZFKQns&download=image.png "")

![](https://tcs.teambition.net/storage/312193a3a3fa604c05c5e4a35ec0a5b9f1df?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjQzNywiaWF0IjoxNjEyMTkxNjM3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5M2EzYTNmYTYwNGMwNWM1ZTRhMzVlYzBhNWI5ZjFkZiJ9.Sd8dFEEgueC6uA2FdKidQgySMyBaFVwhREF5_5NDT10&download=image.png "")









开源笔记

可 Pull Requests 协作写开源笔记

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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMjc5NjQzNywiaWF0IjoxNjEyMTkxNjM3LCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.1M3t0w3WyBCGrEv9jgC_KKDxG-6kThlQERfuOkkytzs&download=image.png "")

