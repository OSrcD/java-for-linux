import instance from './intercept';
import {AxiosRequest, CustomResponse} from './types';

import {ElMessage} from "element-plus";


import {baseUrlT} from '@/config'

import {store} from "@/store"

class BaseService {
    private readonly permission: any;
    private namespace: any;
    private proxy: string | undefined;

    constructor() {
        const crud = {
            page: "page",
            list: "list",
            info: "info",
            add: "add",
            delete: "delete",
            update: "update"
        }

        if (!this.permission) {
            this.permission = {};
        }
        for (let i in crud) {
            if (this.namespace) {
                // @ts-ignore
                this.permission[i] = this.namespace.replace(/\//g, ":") + ":" + crud[i];
            } else {
                // @ts-ignore
                this.permission[i] = crud[i];
            }
        }

    }

    protected headers: object = {
        ContentType: 'application/json;charset=UTF-8',
    }


    private apiAxios({
                         headers = this.headers,
                         method,
                         url,
                         data,
                         params,
                         responseType,
                         onUploadProgress
                     }: AxiosRequest): Promise<any> {

        Object.assign(headers, {
            Authorization: store.state.user.token || ""
        });

        let path = "";
        if (process.env.NODE_ENV == "development") {
            path = this.proxy || baseUrlT;
        } else {
            if (this.proxy) {
                path = url;
            } else {
                path = baseUrlT;
            }
        }
        if (this.namespace) {
            path += "/" + this.namespace;
        }
        if (url.indexOf("http") === 0) {
        } else if (url[0] === "@") {
            url = url.replace("@", "");
        } else {
            url = path + url;
        }


        return new Promise((resolve, reject) => {
            instance({
                headers,
                method,
                url,
                params,
                data,
                responseType,
                onUploadProgress
            }).then((res) => {
                // 200:服务端业务处理正常结束
                if (res.status === 200) {
                    if (res.data) {
                        if (res.data.code === 1000) {
                            resolve(res.data.data);
                        } else {
                            ElMessage.error(res.data.message)
                            resolve({
                                status: false,
                                message: res.data?.errorMessage || (url + '请求失败'),
                                data: res.data?.data,
                                origin: res.data
                            });
                        }
                    } else {
                        if (res.statusText === "OK") {
                            // resolve(); 原代码
                            resolve(null); // 修改后的代码
                        }
                    }

                } else {
                    resolve({status: false, message: res.data?.errorMessage || (url + '请求失败'), data: null});
                }
            }).catch((err) => {
                const message = err.message
                ElMessage.error(message)
                // eslint-disable-next-line
                reject({status: false, message, data: null});
            });
        });
    }

    // 封装CRUD公共函数

    list(params: any) {
        return this.apiAxios({
            url: "/list",
            params
        });
    }

    page(params: any) {
        return this.apiAxios({
            url: "/page",
            params
        });
    }

    info(params: any) {
        return this.apiAxios({
            url: "/info",
            params
        });
    }

    update(data: any) {
        return this.apiAxios({
            url: "/update",
            method: "POST",
            data
        });
    }

    delete(data: any) {
        return this.apiAxios({
            url: "/delete",
            method: "POST",
            data
        });
    }

    add(data: any) {
        return this.apiAxios({
            url: "/add",
            method: "POST",
            data
        });
    }


    /**
     * GET类型的网络请求
     */
    protected getReq({baseURL, headers, url, data, params, responseType}: AxiosRequest) {
        return this.apiAxios({baseURL, headers, method: 'GET', url, data, params, responseType});
    }

    /**
     * POST类型的网络请求
     */
    protected postReq({baseURL, headers, url, data, params, responseType}: AxiosRequest) {
        return this.apiAxios({baseURL, headers, method: 'POST', url, data, params, responseType});
    }

    /**
     * PUT类型的网络请求
     */
    protected putReq({baseURL, headers, url, data, params, responseType}: AxiosRequest) {
        return this.apiAxios({baseURL, headers, method: 'PUT', url, data, params, responseType});
    }

    /**
     * PATCH类型的网络请求
     */
    protected patchReq({baseURL, headers, url, data, params, responseType}: AxiosRequest) {
        return this.apiAxios({baseURL, headers, method: 'PATCH', url, data, params, responseType});
    }

    /**
     * DELETE类型的网络请求
     */
    protected deleteReq({baseURL, headers, url, data, params, responseType}: AxiosRequest) {
        return this.apiAxios({baseURL, headers, method: 'DELETE', url, data, params, responseType});
    }
}

export default BaseService;
