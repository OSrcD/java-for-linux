import {defineComponent, computed} from "vue"
import {useStore} from "@/hooks/useStore";
import {useRoute, useRouter} from "vue-router"

import {ElSubmenu, ElMenuItem, ElMenu} from "element-plus"

import {MenuProps} from "@/store/interface"

export default defineComponent({
    setup() {
        const store = useStore()
        const route = useRoute()
        const router = useRouter()

        const menuGroup = computed(() => store.getters.menuGroup)
        const menuCollapse = computed(() => store.getters.menuCollapse)

        const toView = (url: string) => {
            if (url != route.path) {
                router.push(url);
                // window.location.href = url
            }
        }

        const fn = (list: MenuProps[]) => {
            return list
                .filter((e: MenuProps) => e.isShow)
                .map((e: MenuProps) => {
                    let html = null;

                    if (e.type == 0) {
                        html = (
                            <ElSubmenu index={String(e.id)} key={e.id} v-slots={{
                                title: () => (
                                    <>
                                        <icon-svg name={e.icon}/>
                                        <span>{e.name}</span>
                                    </>
                                )
                            }}>
                                {e.children && fn(e.children)}
                            </ElSubmenu>
                        );
                    } else {
                        html = (
                            <ElMenuItem index={e.path} key={e.path}>
                                <icon-svg name={e.icon}/>
                                <span>{e.name}</span>
                            </ElMenuItem>
                        );
                    }

                    return html;
                });
        };


        const onSelect = {
            "onSelect": (index: string) => {
                router.push(index).catch(err => console.error(err))
                // if (index.indexOf("http://") > -1 || index.indexOf("https://") > -1) {
                //     window.open(index);
                // } else {
                //     router.push({
                //         path: index,
                //     }).catch(err => console.error(err))
                // }
            }
        }

        return {
            menuGroup,
            menuCollapse,
            toView,
            onSelect,
            fn
        }
    },

    render() {

        let el = this.fn(this.menuGroup);

        return (
            <ElMenu
                defaultActive={this.$route.path}
                collapseTransition={false}
                collapse={this.menuCollapse}
                {...this.onSelect}>
                {el}
            </ElMenu>
        )
    }
})
