import BaseService from "./service/request/abstract";
// @ts-ignore
import {Service, Permission} from "./decorator";
// @ts-ignore
import SET_SERVICE from "./service/load";
// import SET_CRUD from "./crud"
import {SET_ROUTER} from "./router"
import {App} from "vue";

async function bootstrap(app: App, options: { store: any; router: any; "view-routes": any; "io-crud": any; }) {
    const {store, router, ["view-routes"]: routes, ["io-crud"]: crud} = options;

    SET_ROUTER({router, routes});

    app.config.globalProperties.$service = SET_SERVICE({store});

    console.log(store.state.menu.routes, "store.state.menu.routes")
    router.$plugin.addRoutes(store.state.menu.routes);
}

export {
    BaseService,
    Service,
    Permission,
    bootstrap
}
