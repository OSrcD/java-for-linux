import Layout from "@/pages/layout/index.vue";

export default function({ routes, router }) {
    router.$plugin = {
        addRoutes: (list, options) => {
            if (!options) {
                options = {};
            }

            list.map(e => {
                if (!e.component) {
                    let url = e.viewPath;

                    if (url) {
                        if (
                            /^(http[s]?:\/\/)([0-9a-z.]+)(:[0-9]+)?([/0-9a-z.]+)?(\?[0-9a-z&=]+)?(#[0-9-a-z]+)?/i.test(
                                e.viewPath
                            )
                        ) {
                            e.meta.iframeUrl = e.viewPath;
                            e.component = () => import(`@/pages/iframe/index.vue`);
                        } else {
                            e.component = () => import(`@/${e.viewPath}`);
                        }
                    } else {
                        e.redirect = "/404";
                    }
                }
            });

            router.addRoute({
                path: "/",
                component: Layout,
                children: [...list, ...routes]
            });
        },

        to: url => {
            if (router.path != url) {
                router.push(url);
            }
        }
    };
}
