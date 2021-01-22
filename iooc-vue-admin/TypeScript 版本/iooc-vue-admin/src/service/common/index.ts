import {isDev, baseUrlT} from "@/config";
const {BaseService} = require("@/admin")
import {store} from "@/store";
import {v4 as uuidv4} from "uuid";

import {UserProps, CaptchaProps} from "../type"


export default class extends BaseService {
    /**
     * 文件上传参数
     *
     * @returns
     * @memberof CommonService
     */
    upload() {
        return {
            url: baseUrlT + "/comm/upload",
            token: store.state.user.token
        };
    }

    /**
     * OSS 文件上传
     */
    ossUpload(file: File, options: any) {
        const {onUploadProgress} = options || {};

        return new Promise((resolve, reject) => {
            this.apiAxios({
                url: "/comm/ossSign"
            })
                .then((res: any) => {
                    let data = new FormData();

                    for (let i in res) {
                        if (i != "host") {
                            data.append(i, res[i]);
                        }
                    }

                    const stru = (file.name || "").split(".");
                    const fileName = uuidv4() + "." + stru[stru.length - 1];

                    data.append("key", `app/${fileName}`);
                    data.append("file", file);

                    this.apiAxios({
                        url: isDev ? "@/oss-upload" : res.host,
                        method: "POST",
                        headers: {
                            "Content-Type": "multipart/form-data"
                        },
                        data,
                        onUploadProgress
                    })
                        .then(() => {
                            resolve(`${res.host}/app/${fileName}`);
                        })
                        .catch((err: Error) => {
                            reject(err);
                        });
                })
                .catch((err: Error) => {
                    reject(err);
                });
        });
    }

    /**
     * 获取 OSS 签名
     */
    ossSign() {
        return this.apiAxios({
            url: "/comm/ossSign"
        });
    }

    /**
     * 用户登录
     *
     * @param {*} { username, password, captchaId, verifyCode }
     * @returns
     * @memberof CommonService
     */
    userLogin({ username, password, captchaId, verifyCode }: UserProps) {
        return this.apiAxios({
            url: "/comm/login",
            method: "POST",
            data: {
                username,
                password,
                captchaId,
                verifyCode
            }
        });
    }

    /**
     * 用户退出
     */
    userLogout() {
        return this.apiAxios({
            url: "/comm/logout",
            method: "POST"
        });
    }

    /**
     * 用户信息
     *
     * @returns
     * @memberof CommonService
     */
    userInfo() {
        return this.apiAxios({
            url: "/comm/person"
        });
    }

    /**
     * 用户信息修改
     *
     * @param {*} params
     * @returns
     * @memberof CommonService
     */
    userUpdate(params: any) {
        return this.apiAxios({
            url: "/comm/person-update",
            method: "POST",
            data: {
                ...params
            }
        });
    }

    /**
     * 权限信息
     *
     * @returns
     * @memberof CommonService
     */
    permMenu() {
        return this.apiAxios({
            url: "/comm/permmenu"
        });
    }

    /**
     * 图片验证码 svg
     *
     * @param {*} { height, width }
     * @returns
     * @memberof CommonService
     */
    captcha({ height, width }: CaptchaProps) {
        return this.apiAxios({
            url: "/comm/captcha",

            params: {
                height,
                width
            }
        });
    }
}