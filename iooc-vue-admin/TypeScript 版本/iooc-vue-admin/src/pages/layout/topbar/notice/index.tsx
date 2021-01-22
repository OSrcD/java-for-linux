import {defineComponent, ref, onMounted} from "vue"

import "./index.scss"

export default defineComponent({
    setup() {
        const number = ref(9)

        return {
            number
        }
    },
    render() {
        return (
            <li class="app-tools-notice">
                <el-badge value={this.number} is-dot={this.number == 0}>
                    <i class="el-icon-message-solid"></i>
                </el-badge>
            </li>
        )
    }
})