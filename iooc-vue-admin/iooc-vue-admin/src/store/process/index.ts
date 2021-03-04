import { Module } from "vuex";
import { ProcessStateTypes, IRootState } from "@/store/interface";
import { getters } from "./getters";
import { mutations } from "./mutations";
import { state } from "./state";

// Module
const process: Module<ProcessStateTypes, IRootState> = {
    state,
    getters,
    mutations,
};

export default process;
