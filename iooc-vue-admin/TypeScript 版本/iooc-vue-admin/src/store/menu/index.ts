import { Module } from "vuex";
import { MenuStateTypes, IRootState } from "@/store/interface";
import { getters } from "./getters";
import { actions } from "./actions";
import { mutations } from "./mutations";
import { state } from "./state";

// Module
const menu: Module<MenuStateTypes, IRootState> = {
    state,
    getters,
    mutations,
    actions
};

export default menu;