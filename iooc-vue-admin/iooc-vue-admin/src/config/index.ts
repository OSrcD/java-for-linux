export const isDev = process.env.NODE_ENV === 'development'
import store from "@/utils/store"

function getUrlParam(name: string) {
    let reg = new RegExp("(^|&)" + name + "=([^&]*)(&|$)");
    let r = window.location.search.substr(1).match(reg);
    if (r != null) return decodeURIComponent(r[2]);
    return null;
}
// 请求地址
export const baseUrlT = (function () {
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
export default {
    baseUrl: {
        dev: 'http://49.232.210.33:7003/admin',
        pro: 'http://49.232.210.33:7003/admin'
    },
    baseUrlT
}
