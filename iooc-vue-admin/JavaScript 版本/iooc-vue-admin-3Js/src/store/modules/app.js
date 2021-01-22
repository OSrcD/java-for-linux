import { app } from "@/config/env";
import { getBrowser } from "@/iooc/utils";

export default {
	state: {
		info: {
			name: "cool-admin"
		},
		conf: {
			...app
		},
		browser: {
			isMobile: false
		}
	},

	actions: {
		appLoad() {
			if (this.state.user.token) {
				this.dispatch("permMenu");
				this.dispatch("userInfo");
			}
		}
	},

	mutations: {
		SET_BROWSER(state) {
			state.browser = getBrowser();
		}
	}
};
