import {ActionTree} from 'vuex'
import {ActionTypes} from './type/action-types'
import {UserActionsTypes, UserStateTypes, IRootState} from '@/store/interface'
import {MutationTypes} from "./type/mutation-types";

import {UserApi} from "@/api"
import type {UserProps} from "@/api/user"
import {AllMutationTypes} from "@/store/mutation-types";
import {AllActionTypes} from "@/store/action-types";


export const actions: ActionTree<UserStateTypes, IRootState> & UserActionsTypes = {
    [ActionTypes.LOGIN]({commit}, userInfo: UserProps) {
        return new Promise((resolve, reject) => {
            UserApi.userLogin(userInfo).then(res => {
                commit(MutationTypes.SET_TOKEN, res)
                resolve()
            }).catch(e => {
                reject(e)
            })
        })
    },
    [ActionTypes.USERINFO]({commit}) {
        return new Promise((resolve, reject) => {
            UserApi.GetCurrentUserInfo().then(res => {
                commit(MutationTypes.SET_USERINFO, res)
                resolve()
            }).catch(e => reject(e))
        })
    },
    [ActionTypes.LOGOUT]({dispatch}) {
        return new Promise((resolve) => {
            UserApi.UserLogout().then(() => {
                dispatch(AllActionTypes.USER_REMOVE)
                resolve();
            })
        })
    },
    [ActionTypes.USER_REMOVE]({commit}) {
        commit(AllMutationTypes.CLEAR_USER);
        commit(AllMutationTypes.CLEAR_TOKEN);
        commit(AllMutationTypes.RESET_PROCESS);
        commit(AllMutationTypes.SET_MENU_GROUP, []);
        commit(AllMutationTypes.SET_VIEW_ROUTES, []);
        commit(AllMutationTypes.SET_MENU_LIST, 0);
    }
}