import {
    ProcessStateTypes,
    ProcessMutations,
    ProcessGettersTypes
} from "@/store/interface";
import {Store as VuexStore, CommitOptions} from "vuex";

export type ProcessStoreModuleTypes<S = ProcessStateTypes> = Omit<VuexStore<S>,
    "commit" | "getters" | "dispatch"> & {
    commit<K extends keyof ProcessMutations,
        P extends Parameters<ProcessMutations[K]>[1]>(
        key: K,
        payload?: P,
        options?: CommitOptions
    ): ReturnType<ProcessMutations[K]>;
} & {
    getters: {
        [K in keyof ProcessGettersTypes]: ReturnType<ProcessGettersTypes[K]>;
    };
};
