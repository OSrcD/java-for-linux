import { baseUrl, isDev } from "@/config/env";
import { BaseService } from "@/iooc";
import store from "@/store";
import { v4 as uuidv4 } from "uuid";

class Common extends BaseService {
    /**
     * 文件上传参数
     *
     * @returns
     * @memberof CommonService
     */
    upload() {
        return {
            url: baseUrl + "/comm/upload",
            token: store.state.user.token
        };
    }

    /**
     * OSS 文件上传
     */
    ossUpload(file, options) {
        const { onUploadProgress } = options || {};

        return new Promise((resolve, reject) => {
            this.request({
                url: "/comm/ossSign"
            })
                .then(res => {
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

                    this.request({
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
                        .catch(err => {
                            reject(err);
                        });
                })
                .catch(err => {
                    reject(err);
                });
        });
    }

    /**
     * 获取 OSS 签名
     */
    ossSign() {
        return this.request({
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
    userLogin({ username, password, captchaId, verifyCode }) {
        return this.request({
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
        return this.request({
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
        return this.request({
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
    userUpdate(params) {
        return this.request({
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
        return this.request({
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
    captcha({ height, width }) {
        return this.request({
            url: "/comm/captcha",
            params: {
                height,
                width
            }
        });
    }
}

export default Common;
