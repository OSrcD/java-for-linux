import {defineComponent, ref, computed} from "vue"
import {useStore} from "@/hooks/useStore"
import DeepMenu from "./DeepMenu"

import "./index.scss"

export default defineComponent({
    setup() {
        const store = useStore()

        const visible = ref(true)
        const menuCollapse = computed(() => store.getters.menuCollapse)

        return {
            menuCollapse,
            visible
        }
    },
    render() {
        return (
            <div class="app-slider">
                <div class="logo">
                    {!this.menuCollapse && (
                        <>
                            <img style="width: 40px" src={require("@/assets/logo.png")} />
                            <h3 style="color: white;margin-left:20px;">Vue3-Admin</h3>
                        </>
                    )}
                    {this.menuCollapse && <img style="width: 40px" src={require("@/assets/logo.png")} />}
                </div>
                {
                    this.visible && (
                        <div class="menu">
                            <DeepMenu/>
                        </div>
                    )
                }
            </div>
        )
    }
})