const {BaseService, Service, Permission} = require("@/admin")

@Service("sys/user")
export default class extends BaseService {
    @Permission("move")
    move(data: any) {
        return this.postReq({
            url: "/move",
            data
        })
    }
}
