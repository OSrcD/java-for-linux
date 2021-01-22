import { BaseService, Service, Permission } from "@/iooc";

@Service("sys/log")
class SysLog extends BaseService {
	@Permission("clear")
	clear() {
		return this.request({
			url: "/clear",
			method: "POST"
		});
	}

	@Permission("get-keep")
	getKeep() {
		return this.request({
			url: "/get-keep"
		});
	}

	@Permission("set-keep")
	setKeep(value) {
		return this.request({
			url: "/set-keep",
			method: "POST",
			data: {
				value
			}
		});
	}
}

export default SysLog;
