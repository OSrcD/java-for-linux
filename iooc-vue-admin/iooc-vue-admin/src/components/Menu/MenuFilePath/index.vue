<template>
    <el-autocomplete
        style="width: 100%"
        v-model="newValue"
        :fetch-suggestions="querySearch"
        placeholder="请输入内容"
    ></el-autocomplete>
</template>

<script lang="ts">
import {defineComponent, ref, watch, onMounted} from "vue"

const files = require.context("@/", true, /^.\/(views|pages).*(vue|tsx|ts)/)
    .keys().map((e) => {
        return {
            value: e.substr(2)
        };
    })

export default defineComponent({
    name: "menu-file-path",
    inheritAttrs: false,
    props: {
        value: [String],
        modelValue: String
    },
    emits: ["update:modelValue"],
    setup(props, ctx) {
        const newValue = ref("")

        const parse = function () {
            newValue.value = props.modelValue || ""
        }

        const querySearch = function (qs: string, cb: any) {
            const res = qs ? files.filter(createFilter(qs)) : files;
            cb(res);
        }

        const createFilter = function (qs: string) {
            return (restaurant: any) => {
                return restaurant.value.toLowerCase().indexOf(qs.toLowerCase()) >= 0;
            };
        }

        onMounted(() => {
            parse()
        })

        watch(() => props.modelValue, () => {
            parse()
        })
        watch(() => newValue.value, (val) => {
            ctx.emit("update:modelValue", val);
        })

        return {
            newValue,
            querySearch
        }
    }
})
</script>