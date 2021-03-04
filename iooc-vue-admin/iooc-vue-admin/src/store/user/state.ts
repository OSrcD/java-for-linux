import store from "@/utils/store";
import {UserStateTypes} from "@/store/interface"

export const state: UserStateTypes = {
    token: store.get("token"),
    userInfo: {
        username: store.get("username") || "Jason",
        userId: store.get("userId") || null,
    }
}
