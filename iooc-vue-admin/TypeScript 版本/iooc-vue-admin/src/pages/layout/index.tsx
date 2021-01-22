import {computed, defineComponent} from "vue"
import {useStore} from "@/hooks/useStore"
import Process from "./process"
import Topbar from "./topbar";
import Slider from "./slider";
import "./index.scss"

export default defineComponent({

    setup() {
        const store = useStore()
        const menuCollapse = computed(() => store.getters.menuCollapse)
        const showProcess = computed(() => store.getters.getConf.showProcess)
        return {
            menuCollapse,
            showProcess
        }
    },

    render() {

        return (
            <>
                <div class={{
                    "page-layout": true,
                    "collapse": this.menuCollapse
                }}>
                    <div class="page-layout__left">
                        <Slider/>
                    </div>

                    <div class="page-layout__right">
                        <div class="page-layout__topbar">
                            <Topbar/>
                        </div>

                        {
                            this.showProcess && (
                                <div class="page-layout__process">
                                    <Process/>
                                </div>
                            )
                        }
                        <div class="page-layout__container">
                            <div class="page-layout__view">
                                <router-view/>
                            </div>
                        </div>
                    </div>
                </div>
            </>
        )
    }
})

