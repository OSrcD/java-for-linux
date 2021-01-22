import { createApp, h } from "vue";
import App from "./App.vue";

// iooc
import { bootstrap } from "@/iooc";
// router
import router from "@/router";
import routes from "@/router/routes/views";

// store
import store from "@/store";

// element-plus
import ElementPlus from "element-plus";
import "@/assets/css/element-variables.scss";
import locale from "element-plus/lib/locale/lang/zh-cn";

// io-crud-vue
import IoCrudVue from "io-crud-vue"
import "io-crud-vue/dist/index.css"

// echarts
import * as echarts from "echarts";
import { plugin } from "echarts-for-vue";

// svg
import "@/icons";



createApp(App)
    .use(bootstrap, {
        store,
        router,
        ["view-routes"]: routes
    })
    .use(store)
    .use(router)
    .use(ElementPlus, { locale })
    .use(IoCrudVue, {
        crud: {
            dict: {
                sort: {
                    prop: "order",
                    order: "sort"
                }
            },
            fn: {
                permission(that) {
                    const { permission } = that.$store.state.menu;
                    const { add, delete: del, update } = that.service.permission || {};

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

// App load
store.dispatch("appLoad");
