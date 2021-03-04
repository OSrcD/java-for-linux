import {defineComponent, reactive, ref, computed, watch, nextTick, onMounted, toRefs} from "vue"
import {useRouter} from 'vue-router'
import {useStore} from "@/hooks/useStore"
import {AllMutationTypes} from "@/store/mutation-types"

import "./index.scss"
import {ProcessListProps} from "@/store/interface";

interface StyleProps {
    left: string;
    top: string;
}

interface MenuProps {
    visible: boolean;
    current: any;
    style: StyleProps;
}

export default defineComponent({

    mounted() {
        this.$el.oncontextmenu = (event: Event) => {
            event.returnValue = false;
        };
    },
    setup() {
        const store = useStore()
        const router = useRouter()
        const app_process__scroller = ref<null | HTMLElement>(null)
        let menu = reactive<MenuProps>({
            visible: false,
            current: {},
            style: {
                left: "0px",
                top: "0px"
            }
        })

        const isHit = ref(false)
        const page = ref(1)

        const processList = computed(() => store.getters.processList)


        onMounted(() => {
            document.body.addEventListener("click", () => {
                if (menu.visible) {
                    menu.visible = false;
                }
            });
        })

        const onTap = (e: MouseEvent, item: any) => {
            e.stopPropagation()
            isHit.value = item.active
            if (e.button == 0) {
                router.push(item.value)
            } else {
                menu.visible = true
                menu.current = item
                menu.style.left = e.pageX + "px"
                menu.style.top = e.pageY + "px"
            }
        }
        const toPath = () => {
            const active = processList.value.find((e: ProcessListProps) => e.active)
            if (!active) {
                const next = processList.value[processList.value.length - 1];
                router.push(next ? next.value : "/");
            }
        }

        const onClose = (cmd: string) => {
            const {current} = menu

            switch (cmd) {
                case "current":
                    onDel(processList.value.findIndex((e: ProcessListProps) => e.value == current.value));
                    break;
                case "other":
                    store.commit(AllMutationTypes.SET_PROCESS, processList.value.filter((e: ProcessListProps) => e.value == current.value || e.value == "/"))
                    break;

                case "all":
                    store.commit(AllMutationTypes.SET_PROCESS, processList.value.filter((e: ProcessListProps) => e.value == "/"))
                    break;
            }

            toPath()
        }

        const onDel = (index: number) => {
            store.commit(AllMutationTypes.DEL_PROCESS, index)
            toPath()
        }

        const toLeft = () => {
            let scroller = app_process__scroller.value
            scroller?.scrollTo(scroller?.scrollLeft - 100, 0)
        }
        const toRight = () => {
            let scroller = app_process__scroller.value
            scroller?.scrollTo(scroller?.scrollLeft + 100, 0)
        }

        return {
            app_process__scroller,
            onClose,
            menu,
            isHit,
            onTap,
            onDel,
            processList,
            toLeft,
            toRight
        }
    },

    render() {
        return (
            <div class="app-process">
                <div class="app-process__left hidden-xs-only" onClick={this.toLeft}>
                    <i class="el-icon-arrow-left"></i>
                </div>

                <div ref="app_process__scroller" class="app-process__scroller">
                    {
                        this.processList.map((item: any, index: number) => {
                            return (
                                <div class={{
                                    "block": true,
                                    "active": item.active
                                }} key={index} data-index={index}
                                     onMousedown={(e) => {
                                         this.onTap(e, item);
                                     }}
                                >
                                    <span>{item.label}</span>
                                    {index > 0 && (<i class="el-icon-close active" onMousedown={(e) => {
                                        e.stopPropagation()
                                        this.onDel(index)
                                    }}/>)}
                                </div>
                            )
                        })
                    }
                </div>

                <div class="app-process__right hidden-xs-only" onClick={this.toRight}>
                    <i class="el-icon-arrow-right"></i>
                </div>


                <ul class="context-menu" v-show={this.menu.visible} style={this.menu.style}>
                    {this.isHit && <li onClick={() => this.onClose("current")}>关闭当前</li>}
                    <li onClick={() => this.onClose('other')}>关闭其他</li>
                    <li onClick={() => this.onClose('all')}>关闭所有</li>
                </ul>
            </div>
        )
    }
})