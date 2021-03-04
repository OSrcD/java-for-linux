import Abstract from "@/admin/service/request/abstract";

export interface UserProps {
    username: string;
    password: string;
    captchaId: string;
    verifyCode: string;
}

interface CaptchaProps {
    height: number;
    width: number;
}

class User extends Abstract {

    // 获取验证码
    GetCaptcha({height, width}: CaptchaProps) {
        return this.getReq({
            url: "/comm/captcha",
            params: {
                height,
                width
            }
        })
    }

    // 登录
    userLogin(data: UserProps) {
        return this.postReq({
            url: "/comm/login",
            data
        })
    }

    UserLogout() {
        return this.postReq({
            url: "/comm/logout",
        });
    }


    // 获取用户信息
    GetCurrentUserInfo() {
        return this.getReq({
            url: "/comm/person"
        })
    }
}

let instance;
export default (() => {
    if (instance) return instance;
    instance = new User();
    return instance;
})();