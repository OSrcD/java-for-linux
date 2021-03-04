import {
    MenuStateTypes,
    MenuMutationsTypes,
    MenuGettersTypes,
    MenuActionsTypes
} from "@/store/interface";
import { Store as VuexStore, CommitOptions, DispatchOptions } from "vuex";

export type MenuStoreModuleTypes<S = MenuStateTypes> = Omit<
    VuexStore<S>,
    "commit" | "getters" | "dispatch"
    > & {
    commit<
        K extends keyof MenuMutationsTypes,
        P extends Parameters<MenuMutationsTypes[K]>[1]
        >(
        key: K,
        payload?: P,
        options?: CommitOptions
    ): ReturnType<MenuMutationsTypes[K]>;
} & {
    getters: {
        [K in keyof MenuGettersTypes]: ReturnType<MenuGettersTypes[K]>;
    };
} & {
    dispatch<K extends keyof MenuActionsTypes>(
        key: K,
        payload?: Parameters<MenuActionsTypes[K]>[1],
        options?: DispatchOptions
    ): ReturnType<MenuActionsTypes[K]>;
};
