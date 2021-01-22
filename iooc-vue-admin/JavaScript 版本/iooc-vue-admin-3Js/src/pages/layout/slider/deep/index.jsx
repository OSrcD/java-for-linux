import {defineComponent, computed} from "vue"
import {useStore} from "vuex";
import {useRoute, useRouter} from "vue-router"

import {ElSubmenu, ElMenuItem, ElMenu} from "element-plus"

export default defineComponent({
    name: "deep-menu",
    setup() {
        const store = useStore()
        const route = useRoute()
        const router = useRouter()
        const menuGroup = computed(() => store.getters.menuGroup)
        const menuCollapse = computed(() => store.getters.menuCollapse)

        const toView = (url) => {
            if (url != route.path) {
                router.push(url);
            }
        }

        const fn = (list) => {
            return list
                .filter((e) => e.isShow !== 0)
                .map((e) => {
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
        let el = fn(menuGroup.value);

        const onSelect = {
            "onSelect": (index) => {
                router.push(index).catch(err => console.error(err))
            }
        }

        return {
            menuGroup,
            menuCollapse,
            toView,
            onSelect,
            el
        }
    },
    render() {
        return (
            <ElMenu
                defaultActive={this.$route.path}
                collapseTransition={false}
                collapse={this.menuCollapse}
                {...this.onSelect}>
                {this.el}
            </ElMenu>
        )
    }
})