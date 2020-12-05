package com.opendev.controller.http;

import com.opendev.domain.Users;
import com.opendev.domain.manager.UserManager;
import com.opendev.domain.vo.UserListVO;
import com.opendev.domain.vo.UserVO;
import com.opendev.utils.IMOOCJSONResult;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.ArrayList;
import java.util.Collection;

@RestController
@RequestMapping("/anchor")
public class HttpAnchorController {


    @RequestMapping("/isStartLive")
    public IMOOCJSONResult isStartLive(){

        Collection<Users> users = UserManager.users.values();
        UserListVO userListVO = new UserListVO();
        userListVO.setUserList(new ArrayList<UserVO>());
        for (Users user : users) {
            if(user.getStartLive()){
                userListVO.getUserList().add(new UserVO(user.getUsername(), user.getRoomNumber()));
            }
        }
        return IMOOCJSONResult.ok(userListVO);
    }


}
