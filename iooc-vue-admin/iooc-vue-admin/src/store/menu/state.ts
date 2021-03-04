import store from '@/utils/store';

import type {MenuStateTypes} from "@/store/interface"

export const state: MenuStateTypes = {
    // 视图路由，type=1
    routes: store.get("viewRoutes") || [],
    // 总菜单，已上下级合并
    group: store.get("menuGroup") || [],
    // showAMenu 模式下，顶级菜单的序号
    index: 0,
    // 左侧菜单
    menu: [],
    // 左侧菜单是否展开
    collapse: false,
    // 权限列表
    permission: store.get("permission") || [],
}
