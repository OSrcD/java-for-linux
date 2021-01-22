import {defineComponent, computed} from "vue"
import {useStore} from "@/hooks/useStore"
import {AllActionTypes} from "@/store/action-types"
import {useRouter} from "vue-router"
import {href} from "@/utils/role"
import Notice from "./notice";
import AMenu from "./menu";
import RouteNav from "./routeNav/index.vue";

import {ElDropdown, ElDropdownItem, ElDropdownMenu} from "element-plus"

import {AllMutationTypes} from "@/store/mutation-types"

import "./index.scss"

export default defineComponent({
    setup() {
        const store = useStore()
        const router = useRouter()

        const userInfo = computed(() => store.getters.userInfo)
        const menuCollapse = computed(() => store.getters.menuCollapse)

        const collapse = () => {
            store.commit(AllMutationTypes.COLLAPSE_MENU, !menuCollapse.value)
        }

        const command = {
            "onCommand": (name: string) => {
                console.log(name, "name")
                switch (name) {
                    case "my":
                        router.push("/my/info");
                        break;
                    case "exit":
                        store.dispatch(AllActionTypes.LOGOUT).then(() => {
                            href("/login");
                        });
                        break;
                }
            }
        }


        return {
            collapse,
            userInfo,
            command
        }
    },

    render() {
        return (
            <div class="layout-topbar">
                <div class="layout-topbar__collapse" onClick={this.collapse}>
                    <icon-svg name="icon-menu"/>
                </div>
                {/*路由导航*/}
                <div class="layout-topbar__route-nav">
                    <RouteNav/>
                </div>
                {/*一级菜单*/}
                <div class="layout-topbar__menu">
                    <AMenu/>
                </div>
                <div class="flex1"/>
                {/*工具栏*/}
                <ul class="layout-topbar__tools">
                    <Notice/>
                </ul>
                {/*用户信息*/}
                {
                    this.userInfo && (
                        <div class="layout-topbar__user">
                            <ElDropdown trigger="click" {...this.command} hideOnClick={false} v-slots={{
                                dropdown: () => (
                                    <ElDropdownMenu  class="popper-dropdown-menu-user">
                                        <ElDropdownItem command="my">个人中心</ElDropdownItem>
                                        <ElDropdownItem command="exit">退出</ElDropdownItem>
                                    </ElDropdownMenu>
                                )
                            }}>
                                <span class="el-dropdown-link">
                                    <span class="name">{this.userInfo.username}</span>
                                    <img class="avatar" src={this.userInfo.headImg ? this.userInfo.headImg : require("@/assets/avatar.jpg")}/>
                                </span>
                            </ElDropdown>
                        </div>
                    )
                }
            </div>
        )
    }
})