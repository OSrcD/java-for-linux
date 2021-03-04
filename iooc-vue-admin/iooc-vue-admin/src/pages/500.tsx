import {defineComponent} from "vue"
import ErrorPage from "@/components/ErrorPage"

export default defineComponent({
    render() {
        return (
            <ErrorPage code={500} desc="糟糕，出了点问题"/>
        )
    }
})