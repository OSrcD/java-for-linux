import type {MenuProps} from "@/store/interface"
const routerMode = "history";

export function firstMenu(list: MenuProps[]) {
    let path: string | undefined = "";

    const fn = (arr: MenuProps[] | undefined) => {
        arr?.forEach((e) => {
            if (e.type == 1) {
                if (!path) {
                    path = e.router;
                }
            } else {
                fn(e.children);
            }
        });
    };

    fn(list);

    return path || "/404";
}

export function orderBy(list: any[], key: any) {
    return list.sort((a, b) => a[key] - b[key]);
}

export function deepTree(list: MenuProps[]): MenuProps[] {


    let newList: MenuProps[] = [];
    let map: any = {};

    list.forEach(e => {
        if (e.id) {
            return map[e.id] = e
        }
    });

    list.forEach(e => {
        let parent
        if (e.parentId) {
            parent = map[e.parentId];
        }

        if (parent) {
            (parent.children || (parent.children = [])).push(e);
        } else {
            if (!e.parentId) {
                newList.push(e);
            }
        }
    });


    const fn = (list: MenuProps[]) => {
        list.map(e => {
            if (e.children instanceof Array) {
                e.children = orderBy(e.children, 'sort');

                if (e.children) {
                    fn(e.children);
                }
            }
        });
    };

    let arr = newList.filter(e => e.id == null)

    newList.map(e => {
        if (e.id != null && arr.length !== 0) {
            arr[0].children?.push(e)
        }
    })

    if (arr.length === 0) {
        fn(newList);
        return orderBy(newList, 'orderNum');
    } else {
        fn(arr);
        return orderBy(arr, 'orderNum');
    }

}

export const revisePath = (path: string) => {
    if (!path) {
        return '';
    }

    if (path[0] === '/') {
        return path;
    } else {
        return `/${path}`;
    }
};

export function isArray(value: any) {
    if (typeof Array.isArray === "function") {
        return Array.isArray(value);
    } else {
        return Object.prototype.toString.call(value) === "[object Array]";
    }
}


export function revDeepTree(list = []) {
    let d: any = [];

    const deep = (list: any) => {
        list.forEach((e: any) => {
            d.push(e);

            if (e.children && isArray(e.children)) {
                deep(e.children);
            }
        });
    };

    deep(list || []);

    return d;
}

export function isPc() {
    const userAgentInfo = navigator.userAgent;
    const Agents = ["Android", "iPhone", "SymbianOS", "Windows Phone", "iPad", "iPod"];
    let flag = true;
    for (let v = 0; v < Agents.length; v++) {
        if (userAgentInfo.indexOf(Agents[v]) > 0) {
            flag = false;
            break;
        }
    }
    return flag;
}

export function contains(parent: any, node: any) {
    // @ts-ignore
    if (document.documentElement.contains) {
        return parent !== node && parent.contains(node);
    } else {
        while (node && (node = node.parentNode)) if (node === parent) return true;
        return false;
    }
}

export function href(path: string, newWindow?: any) {
    let { search, origin } = window.location;

    let url = "";

    if (routerMode == "history") {
        url = origin + path;
    } else {
        url = origin + search + "#" + path;
    }

    if (newWindow) {
        window.open(url);
    } else {
        window.location.href = url;
    }
}


export function getBrowser() {
    let ua = navigator.userAgent.toLowerCase();
    let btypeInfo = (ua.match(/firefox|chrome|safari|opera/g) || "other")[0];
    if ((ua.match(/msie|trident/g) || [])[0]) {
        btypeInfo = "msie";
    }
    let pc = "";
    let prefix = "";
    let plat = "";

    let isTocuh =
        "ontouchstart" in window || ua.indexOf("touch") !== -1 || ua.indexOf("mobile") !== -1;
    if (isTocuh) {
        if (ua.indexOf("ipad") !== -1) {
            pc = "pad";
        } else if (ua.indexOf("mobile") !== -1) {
            pc = "mobile";
        } else if (ua.indexOf("android") !== -1) {
            pc = "androidPad";
        } else {
            pc = "pc";
        }
    } else {
        pc = "pc";
    }
    switch (btypeInfo) {
        case "chrome":
        case "safari":
        case "mobile":
            prefix = "webkit";
            break;
        case "msie":
            prefix = "ms";
            break;
        case "firefox":
            prefix = "Moz";
            break;
        case "opera":
            prefix = "O";
            break;
        default:
            prefix = "webkit";
            break;
    }
    plat = ua.indexOf("android") > 0 ? "android" : navigator.platform.toLowerCase();
    return {
        version: (ua.match(/[\s\S]+(?:rv|it|ra|ie)[\/: ]([\d.]+)/) || [])[1],
        plat: plat,
        type: btypeInfo,
        pc: pc,
        prefix: prefix,
        isMobile: pc == "pc" ? false : true
    };
}