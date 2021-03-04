const {BaseService, Service, Permission} = require("@/admin")

@Service("sys/department")
export default class extends BaseService {
    @Permission("order")
    order(data: any) {
        return this.postReq({
            url: "/order",
            data
        })
    }
}
