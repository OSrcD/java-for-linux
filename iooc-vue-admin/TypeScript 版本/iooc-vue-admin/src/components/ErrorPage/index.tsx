import {defineComponent, ref, computed} from "vue"
import {useStore, mapGetters} from 'vuex';
import {useRouter} from "vue-router"

import "./index.scss"

export default defineComponent({
    props: {
        code: Number,
        desc: String
    },
    name: "ErrorPage",
    setup() {
        const store = useStore()
        const router = useRouter()
        const url = ref<string>("")

        const navTo = () => {
            router.push(url.value)
        }

        const back = () => {
            history.back();
        }

        const home = () => {
            router.push("/")
        }

        const login = () => {

        }

        return {
            navTo,
            back,
            home,
            login
        }
    },

    render() {
        return (
            <div class="error-page">
                <h1 class="code">{this.$props.code}</h1>
                <p class="desc">{this.$props.desc}</p>

                <div class="router">

                    <el-button size="medium" round onClick={this.navTo}>跳转</el-button>
                </div>

                <div class="link">
                    <el-link class="to-home" onClick={this.home}>
                        回到首页
                    </el-link>

                    <el-link class="to-back" onClick={this.back}>返回上一页</el-link>

                    <el-link class="to-login" onClick={this.login}>重新登录</el-link>
                </div>

                <p class="copyright">Copyright © vue3-element-admin 2020</p>
            </div>
        )
    }
})