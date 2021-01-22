import {ActionContext, DispatchOptions} from "vuex";

import {MutationTypes as MenuMutationTypes} from "./menu/type/mutation-types"
import {MutationTypes as ProcessMutationTypes} from "./process/type/mutation-types"
import {MutationTypes as UserMutationTypes} from "./user/type/mutation-types"

import {ActionTypes as MenuActionTypes} from "./menu/type/action-types"
import {ActionTypes as UserActionTypes} from "./user/type/action-types"

export interface IRootState {
    menu: MenuStateTypes,
    app: AppStateTypes,
    process: ProcessStateTypes,
    user: UserStateTypes,
}


export type AllMutationsTypes<S = MenuStateTypes> = {
    [MenuMutationTypes.SET_MENU_LIST](state: S, payload: any): void
    [MenuMutationTypes.SET_PERMIESSION](state: S, payload: any): void
    [MenuMutationTypes.COLLAPSE_MENU](state: S, value: boolean): void
    [MenuMutationTypes.SET_MENU_GROUP](state: S, payload: MenuProps[]): void
    [MenuMutationTypes.SET_VIEW_ROUTES](state: S, payload: MenuProps[]): void
    [ProcessMutationTypes.ADD_PROCESS](state: S, payload: ProcessListProps): void,
    [ProcessMutationTypes.DEL_PROCESS](state: S, index: number): void
    [ProcessMutationTypes.SET_PROCESS](state: S, payload: ProcessListProps[]): void
    [ProcessMutationTypes.RESET_PROCESS](state: S): void
    [UserMutationTypes.SET_TOKEN](state: S, payload: any): void,
    [UserMutationTypes.SET_USERINFO](state: S, payload: any): void
    [UserMutationTypes.CLEAR_TOKEN](state: S): void
    [UserMutationTypes.CLEAR_USER](state: S): void
}

// ======================================= Menu ======================================= //
// state
export interface MenuProps {
    createTime?: string;
    icon?: string;
    id?: string;
    keepAlive?: number;
    name?: string;
    orderNum?: number;
    parentId?: string;
    perms?: string;
    router?: any;
    type?: number;
    updateTime?: string;
    viewPath?: string;
    isShow?: number;
    path?: string;
    permList?: any[];
    children?: MenuProps[]
}

export type MenuStateTypes = {
    routes: any;
    group: any;
    index: number;
    menu: MenuProps[];
    collapse: boolean;
    permission: any[],
}
// getters
export type MenuGettersTypes = {
    // 菜单是否展开
    menuCollapse(state: MenuStateTypes): boolean,
    // 总菜单列表
    menuGroup(state: MenuStateTypes): any,
    // 菜单列表
    menuList(state: MenuStateTypes): any,
    // 路由视图
    routes(state: MenuStateTypes): any,
    // 权限
    permission(state: MenuStateTypes): any
}

// mutations
export type MenuMutationsTypes<S = MenuStateTypes> = {
    [MenuMutationTypes.SET_MENU_LIST](state: S, payload: any): void
    [MenuMutationTypes.COLLAPSE_MENU](state: S, value: boolean): void
    [MenuMutationTypes.SET_MENU_GROUP](state: S, payload: MenuProps[]): void
    [MenuMutationTypes.SET_VIEW_ROUTES](state: S, payload: MenuProps[]): void
    [MenuMutationTypes.SET_PERMIESSION](state: S, payload: any): void
}

// actions
export type MenuAugmentedActionContext = {
    commit<K extends keyof AllMutationsTypes>(
        key: K,
        payload: Parameters<AllMutationsTypes[K]>[1]
    ): ReturnType<AllMutationsTypes[K]>
} & Omit<ActionContext<MenuStateTypes, IRootState>, 'commit'>

export interface MenuActionsTypes {
    [MenuActionTypes.PERM_MENU](
        {commit}: MenuAugmentedActionContext,
        payload: any
    ): Promise<any>
}


// ======================================= app ======================================= //
interface AppInfoProp {
    name: string
}

interface AppConfProp {
    showAMenu: Boolean;
    showRouteNav: Boolean;
    showProcess: Boolean
}

export type AppStateTypes = {
    info: AppInfoProp;
    conf: AppConfProp
}

export type AppGettersTypes = {
    // 应用信息
    getAppInfo(state: AppStateTypes): object,
    // 应用配置
    getConf(state: AppStateTypes): AppConfProp
}

// ======================================= process ======================================= //
export interface ProcessListProps {
    label: string;
    value: string;
    active?: boolean;
}

export type ProcessStateTypes = {
    list: ProcessListProps[]
}

export type ProcessMutations<S = ProcessStateTypes> = {
    [ProcessMutationTypes.ADD_PROCESS](state: S, payload: ProcessListProps): void,
    [ProcessMutationTypes.DEL_PROCESS](state: S, index: number): void
    [ProcessMutationTypes.SET_PROCESS](state: S, payload: ProcessListProps[]): void
    [ProcessMutationTypes.RESET_PROCESS](state: S): void
}

export type ProcessGettersTypes = {
    processList(state: ProcessStateTypes): any
}


// ======================================= user ======================================= //
interface UserInfo {
    username: string | null;
    userId: string | null
}

export type UserStateTypes = {
    token?: string | null;
    userInfo: UserInfo;
}

export type UserMutationsTypes<S = UserStateTypes> = {
    [UserMutationTypes.SET_TOKEN](state: S, payload: any): void,
    [UserMutationTypes.SET_USERINFO](state: S, payload: any): void
    [UserMutationTypes.CLEAR_TOKEN](state: S): void
    [UserMutationTypes.CLEAR_USER](state: S): void
}

export type UserGettersTypes = {
    // 授权标识
    token(state: UserStateTypes): any,
    userInfo(state: UserStateTypes): any,
}
// Actions contracts

export type UserAugmentedActionContext = {
    commit<K extends keyof AllMutationsTypes>(
        key: K,
        payload?: Parameters<AllMutationsTypes[K]>[1]
    ): ReturnType<AllMutationsTypes[K]>,
    dispatch<K extends keyof UserActionsTypes>(
        key: K,
        payload?: Parameters<UserActionsTypes[K]>[1],
        options?: DispatchOptions,
    ): ReturnType<UserActionsTypes[K]>
} & Omit<ActionContext<UserStateTypes, IRootState>, 'commit'>


export interface UserActionsTypes {
    [UserActionTypes.LOGIN](
        {commit}: UserAugmentedActionContext,
        payload: any
    ): any,

    [UserActionTypes.USERINFO](
        {commit}: UserAugmentedActionContext
    ): any,

    [UserActionTypes.LOGOUT](
        {dispatch}: UserAugmentedActionContext
    ): Promise<any>,

    [UserActionTypes.USER_REMOVE](
        {commit}: UserAugmentedActionContext
    ): void
}