// @ts-ignore
import IoCrudVue from "io-crud-vue"


export default function ({app, crud}: any) {
    app.use(IoCrudVue, crud)
}
