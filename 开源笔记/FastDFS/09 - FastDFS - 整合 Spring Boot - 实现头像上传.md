![](https://tcs.teambition.net/storage/3121ffcb3a781e717ea33813be695ce02001?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDg5NDk4MywiaWF0IjoxNjEwMjkwMTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFmZmNiM2E3ODFlNzE3ZWEzMzgxM2JlNjk1Y2UwMjAwMSJ9.NXIQ4QdSBgH8B7KBQXk-PmUFuBeqz1pxflbIgjil1Pk&download=image.png "")

```java
package com.imooc.controller;

import com.github.pagehelper.util.StringUtil;
import com.imooc.pojo.Users;
import com.imooc.pojo.vo.UsersVO;
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
public class CenterUserController {


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

//        if (StringUtils.isNotBlank(path)) {
////            String finalUserFaceUrl = fileResource.getHost() + path;
//            String finalUserFaceUrl = fileResource.getOssHost() + path;
//
//            Users userResult = centerUserService.updateUserFace(userId, finalUserFaceUrl);
//
//            UsersVO usersVO = conventUsersVO(userResult);
//
//            CookieUtils.setCookie(request, response, "user",
//                    JsonUtils.objectToJson(usersVO), true);
//        } else {
//            return IMOOCJSONResult.errorMsg("上传头像失败");
//        }

        return IMOOCJSONResult.ok();
    }

}


```

![](https://tcs.teambition.net/storage/3121b63d6aac3f8e3e7d42dd551a90d1b23a?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDg5NDk4MywiaWF0IjoxNjEwMjkwMTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiNjNkNmFhYzNmOGUzZTdkNDJkZDU1MWE5MGQxYjIzYSJ9.OJ9LL1zDcL5s8FDslsNfmfp4sVlVR_cmvUK4b9zpVNY&download=image.png "")

```java
package com.imooc.service.impl;

import com.github.tobato.fastdfs.domain.fdfs.StorePath;
import com.github.tobato.fastdfs.service.FastFileStorageClient;
import com.imooc.service.FdfsService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

@Service
public class FdfsServiceImpl implements FdfsService {

    @Autowired
    private FastFileStorageClient fastFileStorageClient;

    @Override
    public String upload(MultipartFile file, String fileExName) throws Exception {
        StorePath storePath = fastFileStorageClient.uploadFile(file.getInputStream(),
                                file.getSize(),
                                fileExName,
                                null);
        String path = storePath.getFullPath();
        return path;
    }
}


```

![](https://tcs.teambition.net/storage/312102e604d4b5c84d965f4714dea87e1f98?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDg5NDk4MywiaWF0IjoxNjEwMjkwMTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjEwMmU2MDRkNGI1Yzg0ZDk2NWY0NzE0ZGVhODdlMWY5OCJ9.FJBbwjHHifH4Wp504DkoEMRnknUGZ-t9SIO96ARU-BY&download=image.png "")

![](https://tcs.teambition.net/storage/3121bab0899a08f505ca971c897a8c867b18?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDg5NDk4MywiaWF0IjoxNjEwMjkwMTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiYWIwODk5YTA4ZjUwNWNhOTcxYzg5N2E4Yzg2N2IxOCJ9.MRibynVUqzUv7Q7iF6cMCmmEdzD8fEemLvjFkqWqrSY&download=image.png "")

![](https://tcs.teambition.net/storage/312149c4a4b0cbae6f95f214297d54205cb4?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDg5NDk4MywiaWF0IjoxNjEwMjkwMTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE0OWM0YTRiMGNiYWU2Zjk1ZjIxNDI5N2Q1NDIwNWNiNCJ9.rRZexkqpgS6i6gKPOtySsw6G1nPujYmxEmHzsGwBPi0&download=image.png "")



![](https://tcs.teambition.net/storage/3121b648fb922892d4d725d6e8c55ae4c564?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDg5NDk4MywiaWF0IjoxNjEwMjkwMTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFiNjQ4ZmI5MjI4OTJkNGQ3MjVkNmU4YzU1YWU0YzU2NCJ9.4RLhBjiys6STEq3c3g9FWpuk7K-lq155CILwYvoWSIs&download=image.png "")

![](https://tcs.teambition.net/storage/312185f26ee29364728d0b4ceb5ae0eccf42?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDg5NDk4MywiaWF0IjoxNjEwMjkwMTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjE4NWYyNmVlMjkzNjQ3MjhkMGI0Y2ViNWFlMGVjY2Y0MiJ9.ot7AXJtU9iYMbSgWce5DTRuC5e5S9BGTT7TZIALHyp0&download=image.png "")

## 追踪服务器无法访问 关闭 centos 防火墙 重启 spring boot

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

![](https://tcs.teambition.net/storage/3121aed56e96d914e1046f3b498b493ce232?Signature=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJBcHBJRCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9hcHBJZCI6IjU5Mzc3MGZmODM5NjMyMDAyZTAzNThmMSIsIl9vcmdhbml6YXRpb25JZCI6IiIsImV4cCI6MTYxMDg5NDk4MywiaWF0IjoxNjEwMjkwMTgzLCJyZXNvdXJjZSI6Ii9zdG9yYWdlLzMxMjFhZWQ1NmU5NmQ5MTRlMTA0NmYzYjQ5OGI0OTNjZTIzMiJ9.4FbKzpUm6GkWmIL3XP-6bqLgZQPxgZILqLpcYNUSeVQ&download=image.png "")

