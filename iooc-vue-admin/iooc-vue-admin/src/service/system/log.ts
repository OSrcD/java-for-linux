const {BaseService, Service, Permission} = require("@/admin")

@Service("sys/log")
export default class extends BaseService {
    @Permission("clear")
    clear() {
        return this.postReq({
            url: "/clear",
        });
    }

    @Permission("get-keep")
    getKeep() {
        return this.getReq({
            url: "/get-keep"
        });
    }

    @Permission("set-keep")
    setKeep(value: any) {
        return this.postReq({
            url: "/set-keep",
            data: {
                value
            }
        });
    }
}
