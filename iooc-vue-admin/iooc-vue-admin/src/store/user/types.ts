import {
    UserStateTypes,
    UserMutationsTypes,
    UserGettersTypes,
    UserActionsTypes
} from "@/store/interface";
import { Store as VuexStore, CommitOptions, DispatchOptions } from "vuex";

export type UserStoreModuleTypes<S = UserStateTypes> = Omit<
    VuexStore<S>,
    "commit" | "getters" | "dispatch"
    > & {
    commit<
        K extends keyof UserMutationsTypes,
        P extends Parameters<UserMutationsTypes[K]>[1]
        >(
        key: K,
        payload?: P,
        options?: CommitOptions
    ): ReturnType<UserMutationsTypes[K]>;
} & {
    getters: {
        [K in keyof UserGettersTypes]: ReturnType<UserGettersTypes[K]>;
    };
} & {
    dispatch<K extends keyof UserActionsTypes>(
        key: K,
        payload?: Parameters<UserActionsTypes[K]>[1],
        options?: DispatchOptions
    ): ReturnType<UserActionsTypes[K]>;
};
