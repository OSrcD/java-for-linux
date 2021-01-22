import {
    GetterTree,
    Module,
} from 'vuex'

import {AppStateTypes, AppGettersTypes, IRootState} from "@/store/interface"

const state: AppStateTypes = {
    info: {
        name: "vue3-element-admin"
    },
    conf: {
        // 是否显示一级菜单栏
        showAMenu: false,
        // 是否显示路由导航栏
        showRouteNav: true,
        // 是否显示页面进程栏
        showProcess: true
    }
}

export const getters: GetterTree<AppStateTypes, IRootState> & AppGettersTypes = {
    getAppInfo: state => state.info,
    getConf: state => state.conf
}

export const app: Module<AppStateTypes, IRootState> = {
    state,
    getters
}

export default app