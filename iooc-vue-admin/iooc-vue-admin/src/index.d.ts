import { Router, createRouter } from 'vue-router'
declare module "@vue/runtime-core" {
    interface ComponentCustomProperties {
        $service: any;
        $confirm: any;
    }
}