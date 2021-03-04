import {createApp, h} from 'vue'
import router from '@/router'
import routes from '@/router/routes/views';
import {store} from './store'

import {bootstrap} from "@/admin"

// @ts-ignore
import IoCrudVue from "io-crud-vue"
import "io-crud-vue/dist/index.css"

import {install as CompInstall} from "@/components"
import {install as PermInstall} from "@/admin/permission"

import ElementPlus from "element-plus";
import 'element-plus/lib/theme-chalk/index.css';
import locale from "element-plus/lib/locale/lang/zh-cn";

import App from './App';
import "@/icons"
import IconSvg from "@/components/IconSvg/index.vue"

import "@/assets/css/element-variables.scss";
import {AllActionTypes} from "@/store/action-types";

// echarts
import * as echarts from "echarts";
// @ts-ignore
import { plugin } from "echarts-for-vue";

const app = createApp(App)

app.component("icon-svg", IconSvg)

app.use(bootstrap, {
    store,
    router,
    ['view-routes']: routes,
})
    .use(store)
    .use(router)
    .use(CompInstall)
    .use(PermInstall)
    .use(ElementPlus, {locale})
    // @ts-ignore
    .use(IoCrudVue, {
        crud: {
            dict: {
                sort: {
                    prop: "order",
                    order: "sort"
                }
            },
            fn: {
                permission(that: any) {
                    const {permission} = that.$store.state.menu;
                    const {add, delete: del, update} = that.service.permission || {};

                    return {
                        add: permission.includes(add),
                        delete: permission.includes(del),
                        update: permission.includes(update)
                    };
                }
            }
        }
    })
    .use(plugin, { echarts, h })
    .mount("#app");
if (store.state.user.token) {
    store.dispatch(AllActionTypes.PERM_MENU)
    store.dispatch(AllActionTypes.USERINFO)
}
