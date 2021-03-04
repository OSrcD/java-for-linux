import {defineComponent} from "vue"
import ErrorPage from "@/components/ErrorPage"

export default defineComponent({
    render() {
        return (
            <ErrorPage code={503} desc="马上回来"/>
        )
    }
})