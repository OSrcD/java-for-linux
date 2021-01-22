import {createRouter, createWebHistory} from 'vue-router'
import routes from "./routes/pages"
import {AllMutationTypes} from "@/store/mutation-types"

import {store} from "@/store";

const ignore = {
    token: ["/login", "/403", "/404", "/500", "/503"]
};

const router = createRouter({
    history: createWebHistory(process.env.BASE_URL),
    routes
});


router.beforeEach((to, from, next) => {

    if (store.state.user.token) {
        store.commit(AllMutationTypes.ADD_PROCESS, {
            label: to.path === "/" ? "首页" : (to.name as string),
            value: to.path
        })
    } else {
        if (!ignore.token.some((e) => to.path.includes(e))) {
            return next("/login");
        }
    }
    next()
})
export default router
