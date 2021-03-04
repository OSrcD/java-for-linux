import {Router} from "vue-router"

interface addRoutesProp {
    addRoutes: (list: any[], options?: any) => void;
    to: (str: string) => void
}

declare module "vue-router" {
    export interface Router {
        $plugin?: addRoutesProp
    }
}