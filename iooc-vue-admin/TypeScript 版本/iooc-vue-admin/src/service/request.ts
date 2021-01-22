import axios from "axios";
import NProgress from "nprogress";
import "nprogress/nprogress.css";
import {store} from "@/store";
import router from "@/router";


axios.defaults.timeout = 600000;
axios.defaults.withCredentials = true;

axios.defaults.validateStatus = function (status) {
    return status >= 200 && status <= 500;
};

NProgress.configure({
    showSpinner: false
});

// Ignore urls
const ignore = {
    NProgress: ["/sys/info/record"],
    token: ["/login", "/captcha"]
};


axios.interceptors.request.use(
    (config) => {
        if (config.url) {
            if (!ignore.token.some((e) => config.url?.includes(e))) {
                config.headers["Authorization"] = store.state.user.token || "";
            }

            if (!ignore.NProgress.some((e) => config.url?.includes(e))) {
                NProgress.start();
            }
        }

        console.log(
            `[${config.method}]`,
            config.url,
            config.method == "get" ? config.params : config.data
        );

        console.log(config, "config")
        return config;
    },
    (error) => {
        return Promise.reject(error);
    }
);

// Response
axios.interceptors.response.use(
    async (res) => {
        NProgress.done();

        if (res.status == 401) {
            if (res.config.url?.includes("/logout")) {
                store.dispatch("userRemove");
            } else {
                await store.dispatch("userLogout");
            }

            location.href = "/login";
        }

        if (res.status == 403) {
            router.$plugin?.to("/403");
        }

        if (res.status != 200) {
            return Promise.reject(`[code: ${res.status}] ${res.config.url}`);
        }

        if (!res.data) {
            return res;
        }

        const { code, data, message } = res.data;

        switch (code) {
            case 1000:
                return data;
            default:
                return Promise.reject(message);
        }
    },
    (error) => {
        NProgress.done();

        router.$plugin?.to("/502");
        return Promise.reject(error);
    }
);

export default axios;
