package com.imooc.user.center;

import com.imooc.controller.BaseController;
import com.imooc.user.pojo.Users;
import com.imooc.user.pojo.bo.center.CenterUserBO;
import com.imooc.user.resource.FileUpload;
import com.imooc.user.service.center.CenterUserService;
import com.imooc.utils.CookieUtils;
import com.imooc.utils.DateUtil;
import com.imooc.pojo.IMOOCJSONResult;
import com.imooc.utils.JsonUtils;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.apache.commons.io.IOUtils;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.BindingResult;
import org.springframework.validation.FieldError;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.validation.Valid;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@Api(value = "用户信息接口", tags = {"用户信息相关接口"})
@RestController
@RequestMapping("userInfo")
public class CenterUserController extends BaseController {


    @Autowired
    private CenterUserService centerUserService;

    @Autowired
    private FileUpload fileUpload;




    @ApiOperation(value = "用户头像修改", notes = "用户头像修改", httpMethod = "POST")
    @PostMapping("/uploadFace")
    public IMOOCJSONResult uploadFace(
            @ApiParam(name = "userId", value = "用户id", required = true)
            @RequestParam String userId,
            @ApiParam(name = "file", value = "用户头像", required = true)
            @RequestParam MultipartFile file,
            HttpServletRequest request, HttpServletResponse response) {

        // 定义头像保存的地址
//        String fileSpace = IMAGE_USER_FACE_LOCATION;
        String fileSpace = fileUpload.getImageUserFaceLocation(); // /Users/virtualman/Downloads/temp/workspace/images/foodie/faces



        // 在路径上为每一个用户增加一个userId，用于区分不同用户上传
        String uploadPathPrefix = File.separator + userId; //  / 201013ASBYNDSR1P

        // 开发文件上传
        if (file != null) {
            FileOutputStream fileOutputStream = null;
            InputStream inputStream = null;
            try {

                // 获得文件上传的文件名称
                String fileName = file.getOriginalFilename(); // xxx.png xxx.jpg xxx.jpeg

                if (StringUtils.isNotBlank(fileName)) {


                    // 文件重命名 imooc-face.png -> ["imooc-face","png"]
                    String[] fileNameArr = fileName.split("\\.");


                    // 获得文件的后缀名
                    String suffix = fileNameArr[fileNameArr.length - 1]; // png jpe jpeg

                    if (!suffix.equalsIgnoreCase("png") &&
                            !suffix.equalsIgnoreCase("jpg") &&
                            !suffix.equalsIgnoreCase("jpeg")) {

                        return IMOOCJSONResult.errorMsg("图片格式不正确！");

                    }


                    // face-{userId}.png
                    // 文件名称重组 覆盖式上传，增量式: 额外拼接当前时间
                    String newFileName = "face-" + userId + "." + suffix; // face- 201013ASBYNDSR1P . png

                    /**
                     * 上传文件头像最终保存位置
                     * /Users/virtualman/Downloads/temp/workspace/images/foodie/faces /201013ASBYNDSR1P / face-201013ASBYNDSR1P.png
                     */
                    String finalFilePath = fileSpace + uploadPathPrefix + File.separator + newFileName;
                    // 用于提供给web服务访问的地址
                    uploadPathPrefix += ( "/" + newFileName); // /201013ASBYNDSR1P / face-201013ASBYNDSR1P.png




                    // /Users/virtualman/Downloads/temp/workspace/images/foodie/faces /201013ASBYNDSR1P / face-201013ASBYNDSR1P.png
                    File outFile = new File(finalFilePath);

                    if (outFile.getParentFile() != null) { // 只要存在相应的父类目录

                        /**
                         * 创建文件夹
                         * 在/Users/virtualman/Downloads/temp/workspace/images/foodie/faces创建下面目录
                         * /201013ASBYNDSR1P
                         */
                        outFile.getParentFile().mkdirs();
                    }


                    /**
                     * 文件输出保存到目录
                     * /Users/virtualman/Downloads/temp/workspace/images/foodie/faces/201013ASBYNDSR1P/face-201013ASBYNDSR1P.png
                     */
                    fileOutputStream = new FileOutputStream(outFile);
                    inputStream = file.getInputStream();
                    IOUtils.copy(inputStream, fileOutputStream); // 当两个流连接在一起就形成了pipeline

                }
            } catch (IOException e) {
                e.printStackTrace();
            }finally{
                if (fileOutputStream != null) {
                    try {
                        fileOutputStream.flush();
                        fileOutputStream.close(); // 防止内存泄露
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            }

        } else {
            return IMOOCJSONResult.errorMsg("文件不能为空!");
        }

        // 获取图片服务地址
        String imageServerUrl = fileUpload.getImageServerUrl(); // http://localhost:8088/foodie/faces

        /**
         * 由于浏览器可能存在缓存情况，所以在这里，我们需要加上时间戳来保证更新后的图片可以及时刷新
         * http://localhost:8088/foodie/faces /201013ASBYNDSR1P?t= 20201021122213
         */
        String finalUserFaceUrl = imageServerUrl + uploadPathPrefix +
                "?t=" + DateUtil.getCurrentDateString(DateUtil.DATE_PATTERN);

        // 更新用户头像到数据库
        Users userResult = centerUserService.updateUserFaceUrl(userId,finalUserFaceUrl); // http://localhost:8088/foodie/faces/201013ASBYNDSR1P?t=20201021122213

//        UsersVO usersVO = conventUsersVO(userResult);

        userResult = setNullProperty(userResult);
        CookieUtils.setCookie(request, response, "user",
                JsonUtils.objectToJson(userResult), true);

        return IMOOCJSONResult.ok();


    }


    @ApiOperation(value = "修改用户信息", notes = "修改用户信息", httpMethod = "POST")
    @PostMapping("/update")
    public IMOOCJSONResult update(
            @ApiParam(name = "userId", value = "用户Id", required = true)
            @RequestParam String userId,
            @RequestBody @Valid CenterUserBO centerUserBO,
            BindingResult result,
            HttpServletRequest request, HttpServletResponse response) {

        // 判断BindingResult是否保存错误的验证信息，如果有，则直接return
        if (result.hasErrors()) {
            Map<String, String> errors = getErrors(result);
            return IMOOCJSONResult.errorMap(errors);
        }

        Users userResult = centerUserService.updateUserInfo(userId, centerUserBO);

        // 增加令牌token，会整合进redis，分布式会话
//        UsersVO usersVO = conventUsersVO(userResult);

        userResult = setNullProperty(userResult);
        CookieUtils.setCookie(request, response, "user",
                JsonUtils.objectToJson(userResult), true);

        return IMOOCJSONResult.ok();
    }

    private Users setNullProperty(Users userResult) {
        userResult.setPassword(null);
        userResult.setMobile(null);
        userResult.setEmail(null);
        userResult.setCreatedTime(null);
        userResult.setUpdatedTime(null);
        userResult.setBirthday(null);
        return userResult;
    }


    private Map<String, String> getErrors(BindingResult result) {
        Map<String, String> map = new HashMap<>();
        List<FieldError> errorList = result.getFieldErrors();
        for (FieldError error : errorList) {
            // 发生验证错误所对应的某一个属性
            String errorField = error.getField();
            // 验证错误信息
            String errorMsg = error.getDefaultMessage();

            map.put(errorField, errorMsg);
        }
        return map;

    }

}
