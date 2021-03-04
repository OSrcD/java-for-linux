
export default [
    {
        path: '/',
        component: () => import("@/Home.vue")
    },
    {
        path: "/my/info",
        name: "用户信息",
        component: () => import("@/pages/My/info.vue")
    }
];
