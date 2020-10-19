package com.imooc.controller.center;

import com.imooc.controller.BaseController;
import com.imooc.pojo.Users;
import com.imooc.pojo.bo.center.CenterUserBO;
import com.imooc.service.center.CenterUserService;
import com.imooc.utils.CookieUtils;
import com.imooc.utils.IMOOCJSONResult;
import com.imooc.utils.JsonUtils;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.BindingResult;
import org.springframework.validation.FieldError;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.validation.Valid;
import java.io.File;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@Api(value="用户信息接口",tags={"用户信息相关接口"})
@RestController
@RequestMapping("userInfo")
public class CenterUserController extends BaseController {


    @Autowired
    private CenterUserService centerUserService;


    @ApiOperation(value="用户头像修改",notes="用户头像修改",httpMethod="POST")
    @PostMapping("/update")
    public IMOOCJSONResult update(
            @ApiParam(name="userId",value="用户id",required = true)
            @RequestParam String userId,
            @ApiParam(name="file",value="用户头像", required = true)
            @RequestParam MultipartFile file,
            HttpServletRequest request,HttpServletResponse response){

        // 定义头像保存的地址
        String fileSpace = IMAGE_USER_FACE_LOCATION;

        // 在路径上为每一个用户增加一个userId，用于区分不同用户上传
        String uploadPathPrefix = File.separator + userId;

        // 开发文件上传
        if(file != null){

        }else{
            return IMOOCJSONResult.errorMsg("文件不能为空!");
        }

        return IMOOCJSONResult.ok();


    }




    @ApiOperation(value="修改用户信息",notes="修改用户信息",httpMethod="POST")
    @PostMapping("/update")
    public IMOOCJSONResult update(
            @ApiParam(name="userId",value="用户Id",required=true)
            @RequestParam String userId,
            @RequestBody @Valid CenterUserBO centerUserBO,
            BindingResult result,
            HttpServletRequest request,HttpServletResponse  response){

        // 判断BindingResult是否保存错误的验证信息，如果有，则直接return
        if (result.hasErrors()) {
            Map<String, String> errors = getErrors(result);
            return IMOOCJSONResult.errorMap(errors);
        }

        Users userResult = centerUserService.updateUserInfo(userId,centerUserBO);

        userResult = setNullProperty(userResult);
        CookieUtils.setCookie(request,response, "user",
                JsonUtils.objectToJson(userResult),true);

        // TODO 后续要改，增加令牌token，会整合进redis，分布式会话

        return IMOOCJSONResult.ok();
    }

    private Users setNullProperty(Users userResult){
        userResult.setPassword(null);
        userResult.setMobile(null);
        userResult.setEmail(null);
        userResult.setCreatedTime(null);
        userResult.setUpdatedTime(null);
        userResult.setBirthday(null);
        return userResult;
    }


    private Map<String,String> getErrors(BindingResult result){
        Map<String,String> map = new HashMap<>();
        List<FieldError> errorList = result.getFieldErrors();
        for(FieldError error : errorList){
            // 发生验证错误所对应的某一个属性
            String errorField = error.getField();
            // 验证错误信息
            String errorMsg = error.getDefaultMessage();

            map.put(errorField,errorMsg);
        }
        return map;

    }

}
