import {MutationTree} from 'vuex'
import {MutationTypes} from "./type/mutation-types"
import {MenuStateTypes, MenuMutationsTypes, MenuProps, AppStateTypes} from '@/store/interface'

import store2 from '@/utils/store';
import router from '@/router'

import {store} from "@/store";

export const mutations: MutationTree<MenuStateTypes> & MenuMutationsTypes = {
    [MutationTypes.SET_MENU_LIST](state, index: number) {
        const {showAMenu} = store.state.app.conf
        if (showAMenu) {
            const {children = []} = state.group[index] || {};

            state.index = index;
            state.menu = children;
        } else {
            state.menu = state.group;
        }
    },
    // 设置菜单组
    [MutationTypes.SET_MENU_GROUP](state, list: MenuProps[]) {
        state.group = list
        store2.set("menuGroup", list);
    },
    [MutationTypes.SET_PERMIESSION] (state, list: any) {
        state.permission = list
        store2.set("permission", list);
    },
    // 设置路由视图
    [MutationTypes.SET_VIEW_ROUTES](state, list: MenuProps[]) {
        router.$plugin?.addRoutes(list)
        state.routes = list;
        store2.set('viewRoutes', list);
    },
    [MutationTypes.COLLAPSE_MENU](state, value: boolean) {
        state.collapse = value
    }
}