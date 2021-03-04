export default [
    {
        path: '/404',
        name: '404',
        component: () => import("@/pages/404")
    },
    {
        path: '/403',
        name: '403',
        component: () => import('@/pages/403')
    },
    {
        path: '/503',
        name: '503',
        component: () => import('@/pages/503')
    },
    {
        path: '/500',
        name: '500',
        component: () => import('@/pages/500')
    },
    {
        path: '/login',
        name: 'login',
        component: () => import('@/pages/Login/demo.vue')
    },
    {
        path: "/:pathMatch(.*)*",
        redirect: "/404"
    }
];
