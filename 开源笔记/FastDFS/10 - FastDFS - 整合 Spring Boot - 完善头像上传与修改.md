![](https://tcs.teambition.net/storage/3121c89190a7c5b96af5ab5ae36152f46090?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDg5NTAzMSwiaWF0IjoxNjEwMjkwMjMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjODkxOTBhN2M1Yjk2YWY1YWI1YWUzNjE1MmY0NjA5MCJ9.KcoYxzQjyjJ5PXSGzY6Js843RCr6d2oSQsDbY0QR5IE&download=image.png "")

```text
file.host=http://192.168.245.153:8888/

```

## 资源文件地址

![](https://tcs.teambition.net/storage/3121aecd0d33ac3a528f804ca69313312394?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDg5NTAzMSwiaWF0IjoxNjEwMjkwMjMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWNkMGQzM2FjM2E1MjhmODA0Y2E2OTMxMzMxMjM5NCJ9.w7ng7x2rQoMKxv0azOcdGiw4z_ndlABXk86AnAZTUtY&download=image.png "")

## 定义前缀

![](https://tcs.teambition.net/storage/3121672ca7c889037e952f59ec6a2f5795ab?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDg5NTAzMSwiaWF0IjoxNjEwMjkwMjMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE2NzJjYTdjODg5MDM3ZTk1MmY1OWVjNmEyZjU3OTVhYiJ9.wUplGL2XFMHzKVSuBl-EOHTvQvcU352JI4Zv098biRQ&download=image.png "")

![](https://tcs.teambition.net/storage/31219769e9fbae09a57ad38d37fc31d78172?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDg5NTAzMSwiaWF0IjoxNjEwMjkwMjMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5NzY5ZTlmYmFlMDlhNTdhZDM4ZDM3ZmMzMWQ3ODE3MiJ9.c6_wGLjatxMv__Ie_S09L847wvOchwuPV2S9iTONQJ0&download=image.png "")

```java
package com.imooc.resource;

import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.context.annotation.PropertySource;
import org.springframework.stereotype.Component;

@Component
@PropertySource("classpath:file.properties")
@ConfigurationProperties(prefix = "file")
public class FileResource {
    private String host;

    public String getHost() {
        return host;
    }

    public void setHost(String host) {
        this.host = host;
    }
}


```

![](https://tcs.teambition.net/storage/312156898a21eb3f0f76ebb3822163955aaf?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDg5NTAzMSwiaWF0IjoxNjEwMjkwMjMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE1Njg5OGEyMWViM2YwZjc2ZWJiMzgyMjE2Mzk1NWFhZiJ9.TxYy6iOZi-sQwdLjXsHNs04v1qakNzcdWYcqxR2oOVQ&download=image.png "")

```java
package com.imooc.controller;

import com.imooc.pojo.Orders;
import com.imooc.pojo.Users;
import com.imooc.pojo.vo.UsersVO;
import com.imooc.service.center.MyOrdersService;
import com.imooc.utils.IMOOCJSONResult;
import com.imooc.utils.RedisOperator;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;

import java.io.File;
import java.util.UUID;

@Controller
public class BaseController {

    @Autowired
    private RedisOperator redisOperator;

    public static final String REDIS_USER_TOKEN = "redis_user_token";


    public UsersVO conventUsersVO(Users user) {
        // 实现用户的redis会话
        String uniqueToken = UUID.randomUUID().toString().trim();
        redisOperator.set(REDIS_USER_TOKEN + ":" + user.getId(),
                uniqueToken);

        UsersVO usersVO = new UsersVO();
        BeanUtils.copyProperties(user, usersVO);
        usersVO.setUserUniqueToken(uniqueToken);
        return usersVO;
    }
}


```

![](https://tcs.teambition.net/storage/312120c89e338b456d358d681d864855d2c5?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDg5NTAzMSwiaWF0IjoxNjEwMjkwMjMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEyMGM4OWUzMzhiNDU2ZDM1OGQ2ODFkODY0ODU1ZDJjNSJ9.qt94RagCeSknjSAuajYC23NkkB1aPIu6_6kfePtRCfw&download=image.png "")

```java
package com.imooc.controller;

import com.github.pagehelper.util.StringUtil;
import com.imooc.pojo.Users;
import com.imooc.pojo.vo.UsersVO;
import com.imooc.resource.FileResource;
import com.imooc.service.FdfsService;
import com.imooc.service.center.CenterUserService;
import com.imooc.utils.CookieUtils;
import com.imooc.utils.IMOOCJSONResult;
import com.imooc.utils.JsonUtils;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@RestController
@RequestMapping("fdfs")
public class CenterUserController extends BaseController{

    @Autowired
    private FileResource fileResource;

    @Autowired
    private CenterUserService centerUserService;

    @Autowired
    private FdfsService fdfsService;

    @PostMapping("uploadFace")
    public IMOOCJSONResult uploadFace(
            String userId,
            MultipartFile file,
            HttpServletRequest request,
            HttpServletResponse response) throws Exception {

        String path = "";
        // 开始文件上传
        if (file != null) {
            // 获得文件上传的文件名称
            String fileName = file.getOriginalFilename();
            if (StringUtils.isNotBlank(fileName)) {

                // 文件重命名  imooc-face.png -> ["imooc-face", "png"]
                String fileNameArr[] = fileName.split("\\.");

                // 获取文件的后缀名
                String suffix = fileNameArr[fileNameArr.length - 1];

                if (!suffix.equalsIgnoreCase("png") &&
                        !suffix.equalsIgnoreCase("jpg") &&
                        !suffix.equalsIgnoreCase("jpeg") ) {
                    return IMOOCJSONResult.errorMsg("图片格式不正确！");
                }

                path = fdfsService.upload(file, suffix);

                System.out.println(path);
            }
        } else {
            return IMOOCJSONResult.errorMsg("文件不能为空！");
        }

        if (StringUtils.isNotBlank(path)) {
            String finalUserFaceUrl = fileResource.getHost() + path;
//            String finalUserFaceUrl = fileResource.getOssHost() + path;

            Users userResult = centerUserService.updateUserFaceUrl(userId, finalUserFaceUrl);

            UsersVO usersVO = conventUsersVO(userResult);

            CookieUtils.setCookie(request, response, "user",
                    JsonUtils.objectToJson(usersVO), true);
        } else {
            return IMOOCJSONResult.errorMsg("上传头像失败");
        }

        return IMOOCJSONResult.ok();
    }

}


```

![](https://tcs.teambition.net/storage/3121996d9cf2a0b74c1d198f509de707f285?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDg5NTAzMSwiaWF0IjoxNjEwMjkwMjMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5OTZkOWNmMmEwYjc0YzFkMTk4ZjUwOWRlNzA3ZjI4NSJ9.vVA5TfIcKJ4bQHvtMw8dr_L0mERjsOkVgVlY7PLjLno&download=image.png "")

![](https://tcs.teambition.net/storage/3121fba16b9eabb89e4c371402a9782d9b98?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDg5NTAzMSwiaWF0IjoxNjEwMjkwMjMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmYmExNmI5ZWFiYjg5ZTRjMzcxNDAyYTk3ODJkOWI5OCJ9.UMhQ33ZvNDqX2pzbuWv1IcVr9wv6yTscWQz1LZ3JOi8&download=image.png "")

![](https://tcs.teambition.net/storage/3121cf7153581bac0376ca8ebe69f744e9c9?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDg5NTAzMSwiaWF0IjoxNjEwMjkwMjMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFjZjcxNTM1ODFiYWMwMzc2Y2E4ZWJlNjlmNzQ0ZTljOSJ9.JJldwfKb1rnpfqm8EEYFPQRYfhXyp_FzrKg-rM00Q-s&download=image.png "")

![](https://tcs.teambition.net/storage/31213eda32544aa502bea52b3266d3daeed2?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDg5NTAzMSwiaWF0IjoxNjEwMjkwMjMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEzZWRhMzI1NDRhYTUwMmJlYTUyYjMyNjZkM2RhZWVkMiJ9.R4jCObqqpcxj-HSmAA2W-x21Fs7mSN2d0-I7iM8Btnw&download=image.png "")

![](https://tcs.teambition.net/storage/312186ba4ba7738bf47be022514e14bd585e?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDg5NTAzMSwiaWF0IjoxNjEwMjkwMjMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4NmJhNGJhNzczOGJmNDdiZTAyMjUxNGUxNGJkNTg1ZSJ9.pNiW9svu-Xe1j57R2KO60CgTwkiGXVkSNSc6WssgVuw&download=image.png "")

![](https://tcs.teambition.net/storage/312197645098217cd296c446e22409f4e9e4?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDg5NTAzMSwiaWF0IjoxNjEwMjkwMjMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE5NzY0NTA5ODIxN2NkMjk2YzQ0NmUyMjQwOWY0ZTllNCJ9.fhiQvpRkrs8awIdO-JGx5JyJsaSIyIdFjKJbgEz8m3Y&download=image.png "")

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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDg5NTAzMSwiaWF0IjoxNjEwMjkwMjMxLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.dhs80DaNaLBUyuvIyDIUJFCV5cHUZpYQLM4uD9XKJKA&download=image.png "")

