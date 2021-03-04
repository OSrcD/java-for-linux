const {BaseService, Service, Permission} = require("@/admin")

@Service("sys/info")
export default class extends BaseService {
    @Permission("record")
    record() {
        return this.getReq({
            url: "/record"
        });
    }
}
