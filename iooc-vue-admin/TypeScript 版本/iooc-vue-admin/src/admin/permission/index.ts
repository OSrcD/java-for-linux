import {App, DirectiveBinding} from "vue"
import {store} from '@/store'

function change(el: any, binding: DirectiveBinding) {
    el.style.display = checkPerm(binding.value) ? el.getAttribute("_display") : "none";
}

function parse(value: any) {
    const permission = store.state.menu.permission;

    if (typeof value == "string") {
        return value ? permission.some((e) => e.includes(value.replace(/\s/g, ""))) : false;
    } else {
        return Boolean(value);
    }
}

export const checkPerm = (value: any) => {
    if (!value) {
        return false;
    }

    if (Object.prototype.toString.call(value) === "[object Object]") {
        if (value.or) {
            return value.or.some(parse);
        }

        if (value.and) {
            return !value.and.some((e: any) => !parse(e));
        }
    }

    return parse(value);
};



const install = (app: App) => {
    app.directive("permission", {
        mounted(el, binding) {
            el.setAttribute("_display", el.style.display || "")
            change(el, binding);
        },
        updated: change
    });
};

export {
    install
}