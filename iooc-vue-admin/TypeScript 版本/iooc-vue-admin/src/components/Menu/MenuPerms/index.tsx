import {onMounted, defineComponent, reactive, watch} from "vue"
import useService from "@/hooks/useService";
import {useStore} from "@/hooks/useStore"
import {ElCascader} from "element-plus"


export default defineComponent({
    name: "menu-perms",
    props: {
        modelValue: String,
        value: [String, Number, Array],
        props: Object,
        on: Object
    },
    inheritAttrs: false,
    emits: ["update:modelValue"],
    setup(props, {emit}) {
        const service = useService()
        const store = useStore()
        const state = reactive<any>({
            options: [],
            newValue: []
        })

        //=========================
        let options: any[] = [];
        let list: any[] = [];

        const flat = (obj: any) => {
            for (let i in obj) {
                let {permission} = obj[i];

                if (permission) {
                    list = [...list, Object.values(permission)].flat();
                } else {
                    flat(obj[i]);
                }
            }
        };

        flat(service);

        list.filter((e: any) => e.includes(":"))
            .map((e: any) => e.split(":"))
            .forEach((arr: any) => {
                const col = (i: number, d: any[]) => {
                    let key = arr[i];

                    let index = d.findIndex((e) => e.label == key);

                    if (index >= 0) {
                        col(i + 1, d[index].children);
                    } else {
                        let isLast = i == arr.length - 1;

                        d.push({
                            label: key,
                            value: key,
                            children: isLast ? null : []
                        });

                        if (!isLast) {
                            col(i + 1, d[d.length - 1].children || []);
                        }
                    }
                };

                col(0, options);
            });

        state.options = options

        //=======================

        onMounted(() => {
            parse()
        })

        const parse = function () {
            state.newValue = props.modelValue ? (props.modelValue as string).split(",").map((e: any) => e.split(":")) : [];
        }

        const ElChange = {
            "onChange": (row: any) => {
                let str = row.map((e: any) => e.join(":")).join(",")
                emit("update:modelValue", str)
            }
        }


        const ElProps = {
            multiple: true
        }
        return () => {
            return (
                <ElCascader options={state.options} props={ElProps} clearable filterable separator=":" style="width: 100%;" {...ElChange} v-model={state.newValue}/>
            )
        }
    }
})