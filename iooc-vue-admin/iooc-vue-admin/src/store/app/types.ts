import {Store as VuexStore} from "vuex";
import {AppStateTypes, AppGettersTypes} from "@/store/interface";

export type AppStoreModuleTypes<S = AppStateTypes> = Omit<VuexStore<S>,
    "commit" | "getters" | "dispatch"> & {
    getters: {
        [K in keyof AppGettersTypes]: ReturnType<AppGettersTypes[K]>;
    };
};
