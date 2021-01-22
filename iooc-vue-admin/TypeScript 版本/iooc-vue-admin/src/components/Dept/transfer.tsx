import {defineComponent} from "vue"
import {ElTree} from "element-plus"

export default defineComponent({
    name: "system-user__dept-move",
    props: {
        list: Array
    },
    emits: ['update:modelValue'],
    setup(props, {emit}) {
        const selectRow = function (e: any) {
            emit("update:modelValue", e)
        }

        return {
            selectRow
        }
    },
    render() {
        const click = {
            "onNodeClick": (e: any) => {
                this.selectRow(e)
            }
        }
        return (
            <div
                style={{
                    border: "1px solid #eee",
                    borderRadius: '3px',
                    padding: "2px"
                }}>
                <ElTree
                    data={this.$props.list}
                    props={{
                        label: "name"
                    }}
                    nodeKey="id"
                    highlightCurrent={true}
                    {...click}
                />
            </div>
        );
    }
})