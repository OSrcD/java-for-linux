import {ActionTree} from 'vuex'
import {ActionTypes} from './type/action-types'
import {AllMutationTypes} from "@/store/mutation-types"
import {MenuActionsTypes, MenuStateTypes, IRootState, MenuProps} from "@/store/interface"
import {revisePath, deepTree, isArray} from "@/utils/role"
import {MenuApi} from "@/api"
import {ElMessage} from "element-plus"

export const actions: ActionTree<MenuStateTypes, IRootState> & MenuActionsTypes = {
    [ActionTypes.PERM_MENU]({commit, state}) {
        return new Promise((resolve, reject) => {
            MenuApi.GetPermMenu().then(res => {
                if (!isArray(res.menus)) {
                    console.error("Invalid menus. Expected Array", res.menus);
                    res.menus = [];
                }

                if (!isArray(res.perms)) {
                    console.error("Invalid perms. Expected Array", res.perms);
                    res.perms = [];
                }

                const routes = res.menus
                    .filter((e: MenuProps) => e.type != 2)
                    .map((e: MenuProps) => {
                        return {
                            id: e.id,
                            parentId: e.parentId,
                            path: revisePath(e.router || e.id),
                            viewPath: e.viewPath,
                            type: e.type,
                            name: e.name,
                            icon: e.icon,
                            orderNum: e.orderNum,
                            isShow: e.isShow,
                            meta: {
                                keepAlive: e.keepAlive
                            },
                            children: []
                        };
                    });

                // 格式化菜单
                const menuGroup = deepTree(routes);

                // 设置权限
                commit(AllMutationTypes.SET_PERMIESSION, res.perms);

                // 设置菜单组
                commit(AllMutationTypes.SET_MENU_GROUP, menuGroup)

                // 设置视图路由
                commit(AllMutationTypes.SET_VIEW_ROUTES, routes.filter((e: MenuProps) => e.type === 1))

                // 设置菜单
                commit(AllMutationTypes.SET_MENU_LIST, state.index);

                resolve(menuGroup)
            }).catch((err: Error) => {
                console.error("菜单加载异常", err);
                ElMessage.error("菜单加载异常");
                reject(err);
            });
        })
    },
}