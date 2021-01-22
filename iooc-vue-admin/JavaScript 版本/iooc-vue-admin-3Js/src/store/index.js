import { createStore } from "vuex";

import getters from "./getters";
import app from "./modules/app";
import process from "./modules/process";
import menu from "./modules/menu";
import user from "./modules/user";

export default createStore({
	modules: {
		app,
		process,
		menu,
		user
	},
	getters
});
