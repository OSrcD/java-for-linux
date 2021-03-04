import Abstract from "@/admin/service/request/abstract";
// import {Permission} from "@/jacking/decorator"

class Menu extends Abstract {
    // 获取权限信息
    GetPermMenu() {
        return this.getReq({
            url: "/comm/permmenu"
        })
    }

    // @Permission("list")
    GetMenuList() {
        return this.getReq({
            url: "/sys/menu/list"
        })
    }

    DelMenuIds(ids: string) {
        return this.postReq({
            url: '/sys/menu/delete',
            data: {
                ids
            }
        })
    }

    AddMenuList(data: any) {
        return this.postReq({
            url: "/sys/menu/add",
            data
        })
    }
}

let instance;
export default (() => {
    if (instance) return instance;
    instance = new Menu();
    return instance;
})();
