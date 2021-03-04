import {defineComponent} from "vue"
import ErrorPage from "@/components/ErrorPage"

export default defineComponent({
    render() {
        return (
            <ErrorPage code={403} desc="您无权访问此页面"/>
        )
    }
})