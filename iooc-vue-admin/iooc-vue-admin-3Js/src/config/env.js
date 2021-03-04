import { getUrlParam } from "@/iooc/utils";
import store from "store";

// 路由模式
const routerMode = "history";

// 开发模式
const isDev = process.env.NODE_ENV === "development";

// Host
const host = "https://show.cool-admin.com";

// 请求地址
const baseUrl = (function() {
    let proxy = getUrlParam("proxy");

    if (proxy) {
        store.set("proxy", proxy);
    } else {
        proxy = store.get("proxy") || "dev";
    }

    switch (process.env.NODE_ENV) {
        case "development":
            return `/${proxy}/admin`;
        case "production":
            return `/api/admin`;
        default:
            return "";
    }
})();

// Socket
const socketUrl = (isDev ? `${host}` : "") + "/socket";

// 阿里字体图标库 https://at.alicdn.com/t/**.css
const iconfontUrl = ``;

// 程序配置参数
const app = {
    // 是否显示一级菜单栏
    showAMenu: false,
    // 是否显示路由导航栏
    showRouteNav: true,
    // 是否显示页面进程栏
    showProcess: true
};

// 上传配置
const upload = {
    // 上传的地址
    action: "",
    // 上传的文件类型
    accept: "",
    // 上传的文件字段名
    name: "file",
    // 尺寸
    size: "128px",
    // 显示图标
    icon: "el-icon-upload",
    // 显示文案
    text: "选择文件"
};

export { routerMode, baseUrl, socketUrl, iconfontUrl, app, isDev, upload };
