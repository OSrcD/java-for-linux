import {GetterTree} from 'vuex'
import {MenuStateTypes, MenuGettersTypes, IRootState} from '@/store/interface'

export const getters: GetterTree<MenuStateTypes, IRootState> & MenuGettersTypes = {
    menuCollapse: state => state.collapse,
    menuGroup: state => state.group,
    menuList: state => state.menu,
    routes: state => state.routes,
    permission: state => state.permission
}