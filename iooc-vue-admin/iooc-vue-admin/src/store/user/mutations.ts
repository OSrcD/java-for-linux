import { MutationTree } from 'vuex'
import {MutationTypes} from "./type/mutation-types"
import {UserStateTypes, UserMutationsTypes, MenuStateTypes} from '@/store/interface'
import store from "@/utils/store";


export const mutations: MutationTree<UserStateTypes> & UserMutationsTypes = {
    [MutationTypes.SET_TOKEN](state: UserStateTypes, {token}: any) {
        state.token = token
        store.set("token", token);
        // const {token, user_id, username} = payload
        // state.token = token;
        // state.userInfo.username = username;
        // state.userInfo.userId = user_id
        // store.set("token", token);
        // store.set("username", username);
        // store.set("userId", user_id);
    },
    [MutationTypes.SET_USERINFO](state: UserStateTypes, payload: any) {
        state.userInfo = payload;
        store.set("userInfo", payload);
    },
    [MutationTypes.CLEAR_TOKEN](state: UserStateTypes) {
        state.token = null;
        state.userInfo.username = null;
        state.userInfo.userId = null;
        store.remove("token");
        store.remove("username");
        store.remove("userId");
    },
    [MutationTypes.CLEAR_USER](state: UserStateTypes) {
        state.userInfo = {
            userId: null,
            username: null,
        };
        store.remove("userInfo");
    }
}