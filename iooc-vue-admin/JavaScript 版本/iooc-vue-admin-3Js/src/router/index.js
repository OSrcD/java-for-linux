import {createRouter, createWebHistory} from "vue-router";
import routes from "./routes/pages";
import Store from "@/store";

const ignore = {
    token: ["/login", "/403", "/404", "/500", "/503"]
};

const router = createRouter({
    history: createWebHistory(process.env.BASE_URL),
    routes
});

router.beforeEach((to, from, next) => {
    if (Store.state.user.token) {
        Store.commit("ADD_PROCESS", {
            label: to.name,
            value: to.fullPath
        });
    } else {
        if (!ignore.token.some(e => to.path.includes(e))) {
            return next("/login");
        }
    }

    // H5 下关闭左侧菜单
    if (Store.getters.browser.isMobile) {
        Store.commit("COLLAPSE_MENU", true);
    }

    next();
});

export default router;
