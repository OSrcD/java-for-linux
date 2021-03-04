import {createStore, createLogger} from "vuex";
import {IRootState} from "@/store/interface";
import {MenuStoreModuleTypes} from "./menu/types";
import {AppStoreModuleTypes} from "./app/types";
import {UserStoreModuleTypes} from "./user/types";
import {ProcessStoreModuleTypes} from "./process/types";

import {AllActionTypes} from "./action-types"

import menuModel from "@/store/menu"
import appModel from "@/store/app/store";
import processModel from "@/store/process";
import userModel from "@/store/user";

export const store = createStore({
    plugins:
        process.env.NODE_ENV === 'production'
            ? []
            : [createLogger()],
    modules: {
        menu: menuModel,
        app: appModel,
        process: processModel,
        user: userModel,
    },
});

export type Store = MenuStoreModuleTypes<Pick<IRootState, "menu">> &
    AppStoreModuleTypes<Pick<IRootState, "app">> &
    UserStoreModuleTypes<Pick<IRootState, "user">> &
    ProcessStoreModuleTypes<Pick<IRootState, "process">>
