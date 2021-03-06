import {defineComponent} from "vue"
import "./index.scss";
import {contains} from "@/utils/role";

export default defineComponent({
    name: "context-menu",
    data() {
        return {
            visible: false,
            index: null,
            style: {
                left: 0,
                top: 0
            },
            list: []
        };
    },

    methods: {
        open(e: any, options: any) {
            let {pageX, pageY} = e || {};
            let {list} = options || {};

            let position = {
                left: pageX,
                top: pageY
            };

            if (list) {
                this.list = list;
            }

            this.visible = true;
            this.index = null;

            this.$nextTick(() => {
                const {clientHeight: h1, clientWidth: w1} = document.body;
                const {clientHeight: h2, clientWidth: w2} = this.$el.querySelector(
                    ".io-context-menu-box"
                );

                if (pageY + h2 > h1) {
                    position.top = h1 - h2 - 5;
                }

                if (pageX + w2 > w1) {
                    position.left = w1 - w2 - 5;
                }

                this.style = position;
            });
        },

        close() {
            this.visible = false;
            this.index = null;
        },

        clickRow(e: any, i: any) {
            this.index = i;

            if (e.disabled) {
                return false;
            }

            if (e.callback) {
                return e.callback(e, () => {
                    this.close();
                });
            }

            if (e.children) {
                // this.$set(e, "showChildren", !e.showChildren);
            } else {
                this.close();
            }
        },

    },

    mounted() {
        document.body.addEventListener("mousedown", (e) => {
            if (!contains(this.$el, e.target) && this.$el != e.target) {
                this.close();
            }
        });

        window.onresize = () => {
            this.close();
        };

        document.body.appendChild(this.$el);
    },

    render() {
        const { left, top } = this.style;
        const slot = this.$slots.default

        const deep = (list: any, level: any) => {
            return (
                <div class={["io-context-menu-box", level > 1 && "_append"]}>
                    {list
                        .filter((e: any) => !e.hidden)
                        .map((e: any, i: number) => {
                            let ind = `${level}-${i}`;

                            return (
                                <div
                                    class={{
                                        _ellipsis: e.ellipsis,
                                        _active: ind === this.index,
                                        _disabled: e.disabled
                                    }}>
                                    {e["prefix-icon"] && <i class={e["prefix-icon"]}></i>}
                                    <span
                                        onClick={() => {
                                            this.clickRow(e, ind);
                                        }}>
										{e.label}
									</span>
                                    {e["suffix-icon"] && <i class={e["suffix-icon"]}></i>}

                                    {e.children && e.showChildren && deep(e.children, level + 1)}
                                </div>
                            );
                        })}
                </div>
            );
        };

        return (
            this.visible && (
                <div class="io-context-menu" style={{ left: left + "px", top: top + "px" }}>
                    {slot ? slot() : deep(this.list, 1)}
                </div>
            )
        );
    }
})
