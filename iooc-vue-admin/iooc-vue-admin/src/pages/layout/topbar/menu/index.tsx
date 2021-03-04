import {defineComponent, ref, onMounted, computed} from "vue"
import {useStore} from "@/hooks/useStore"
import {useRoute, useRouter} from "vue-router"

import {firstMenu} from "@/utils/role"

import {MutationTypes} from "@/store/menu/type/mutation-types"

export default defineComponent({
    setup() {
        const store = useStore()
        const route = useRoute()
        const index = ref("0")
        const menuGroup = computed(() => store.getters.menuGroup)
        const conf = computed(() => store.getters.getConf)

        onMounted(() => {
            menuGroup.value.forEach((e: any, i: number) => {
                if (route.path.includes(e.path) && e.path != "/") {
                    index.value = String(i)
                    store.commit(MutationTypes.SET_MENU_LIST, i)
                }
            });
        })

        return {
            index,
            menuGroup,
            conf
        }
    },

    render() {
        return (
            <>
                {
                    this.conf.showAMenu && (
                        <div class="app-topbar-menu">
                            <el-menu defaultActive={this.index} mode="horizontal">
                                {
                                    this.menuGroup.map((item: any, index: number) => (
                                        <el-menu-item index={`${index}`} key={index}>
                                            <icon-svg name={item.icon} />
                                            <span>{item.name}</span>
                                        </el-menu-item>
                                    ))
                                }
                            </el-menu>
                        </div>
                    )
                }
            </>
        )
    }
})