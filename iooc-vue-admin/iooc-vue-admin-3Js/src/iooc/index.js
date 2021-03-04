
import { Service, Permission } from "./decorator";
import { BaseService } from "./service";
import SET_SERVICE from "./service/load";
import SET_ROUTER from "./router";
import SET_COMPONENT from "./components";

async function bootstrap(app, options) {
    const { store, router, "view-routes": routes } = options;

    SET_ROUTER({ router, routes })
    app.config.globalProperties.$service = SET_SERVICE({ store });
    app.config.globalProperties.$store = store;

    SET_COMPONENT(app);

    router.$plugin.addRoutes(store.state.menu.routes);

}

export {bootstrap, BaseService, Service, Permission}