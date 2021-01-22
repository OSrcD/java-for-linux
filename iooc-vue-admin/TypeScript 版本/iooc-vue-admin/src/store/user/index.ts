import { Module } from "vuex";
import { UserStateTypes, IRootState } from "@/store/interface";
import { getters } from "./getters";
import { actions } from "./actions";
import { mutations } from "./mutations";
import { state } from "./state";

// Module
const user: Module<UserStateTypes, IRootState> = {
    state,
    getters,
    mutations,
    actions
};

export default user;
