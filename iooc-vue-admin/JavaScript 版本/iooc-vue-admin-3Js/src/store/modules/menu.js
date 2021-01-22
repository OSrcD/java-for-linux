import store from "@/utils/store";
import { ElMessage } from "element-plus";
import { deepTree, revisePath, isArray } from "@/iooc/utils";
import router from "@/router";

export default {
	state: {
		// 视图路由，type=1
		routes: store.get("viewRoutes") || [],
		// 总菜单，已上下级合并
		group: store.get("menuGroup") || [],
		// showAMenu 模式下，顶级菜单的序号
		index: 0,
		// 左侧菜单
		menu: [],
		// 左侧菜单是否展开
		collapse: true,
		// 权限列表
		permission: store.get("permission") || []
	},
	actions: {
		permMenu({ commit, state }) {
			return new Promise((resolve, reject) => {
				this.$service.common
					.permMenu()
					.then(res => {
						if (!isArray(res.menus)) {
							console.error("Invalid menus. Expected Array", res.menus);
							res.menus = [];
						}

						if (!isArray(res.perms)) {
							console.error("Invalid perms. Expected Array", res.perms);
							res.perms = [];
						}

						const routes = res.menus
							.filter(e => e.type != 2)
							.map(e => {
								return {
									id: e.id,
									parentId: e.parentId,
									path: revisePath(e.router || e.id),
									viewPath: e.viewPath,
									type: e.type,
									name: e.name,
									icon: e.icon,
									orderNum: e.orderNum,
									isShow: e.isShow,
									meta: {
										keepAlive: e.keepAlive
									},
									children: []
								};
							});

						// 格式化菜单
						const menuGroup = deepTree(routes);

						// 设置权限
						commit("SET_PERMIESSION", res.perms);
						// 设置菜单组
						commit("SET_MENU_GROUP", menuGroup);
						// 设置视图路由
						commit(
							"SET_VIEW_ROUTES",
							routes.filter(e => e.type == 1)
						);
						// 设置菜单
						commit("SET_MENU_LIST", state.index);

						resolve(menuGroup);
					})
					.catch(err => {
						console.error("菜单加载异常", err);
						ElMessage.error("菜单加载异常");
						reject(err);
					});
			});
		}
	},
	mutations: {
		SET_MENU_GROUP(state, list) {
			state.group = list;
			store.set("menuGroup", list);
		},

		SET_VIEW_ROUTES(state, list) {
			router.$plugin.addRoutes(list);

			state.routes = list;
			store.set("viewRoutes", list);
		},

		SET_MENU_LIST(state, index) {
			const { showAMenu } = this.state.app.conf;

			if (showAMenu) {
				const { children = [] } = state.group[index] || {};

				state.index = index;
				state.menu = children;
			} else {
				state.menu = state.group;
			}
		},

		SET_PERMIESSION(state, list) {
			state.permission = list;
			store.set("permission", list);
		},

		COLLAPSE_MENU(state, val = false) {
			state.collapse = val;
		}
	}
};
