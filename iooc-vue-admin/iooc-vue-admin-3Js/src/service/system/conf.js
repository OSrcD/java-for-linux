import { BaseService, Service, Permission } from "@/iooc";

@Service("sys/conf")
class SysConf extends BaseService {
	@Permission("all")
	all() {
		return this.request({
			url: "/all"
		});
	}

	@Permission("save")
	save(data) {
		return this.request({
			url: "/save",
			method: "POST",
			data
		});
	}
}

export default SysConf;
