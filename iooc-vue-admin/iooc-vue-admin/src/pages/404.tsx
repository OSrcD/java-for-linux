import {defineComponent} from "vue"
import ErrorPage from "@/components/ErrorPage"

export default defineComponent({
    render() {
        return (
            <ErrorPage code={404} desc="找不到您要查找的页面"/>
        )
    }
})