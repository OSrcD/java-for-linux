<template>
    <div class="common-captcha" @click="refresh">
        <div class="svg" v-html="svg" v-if="svg"></div>

        <img class="base64" :src="base64" alt="" v-else/>
    </div>
</template>

<script lang="ts">
    import {defineComponent, ref, onMounted} from "vue"
    import useService from "@/hooks/useService";

    export default defineComponent({
        emits: ['update:modelValue', 'change'],
        name: "Captcha",
        setup(props, context) {
            const svg = ref("")
            const base64 = ref("")

            const service = useService()

            const refresh = () => {
                service.common.captcha({height: 36, width: 110}).then(res => {
                    const {captchaId, data} = res
                    if (data.includes("data:image/png;base64,")) {
                        base64.value = data
                    } else {
                        svg.value = data;
                    }
                    context.emit("update:modelValue", captchaId)
                    context.emit("change", { base64: base64.value, svg: svg.value, captchaId })
                })
            }

            onMounted(() => {
                refresh()

            })

            const performRefresh = () => {
                console.log("000")
            }

            return {
                svg,
                base64,
                refresh,
                performRefresh
            }
        }
    })
</script>

<style lang="scss" scoped>
    .common-captcha {
        height: 36px;
        cursor: pointer;
        background-color: #000;

        .svg {
            height: 100%;
        }

        .base64 {
            height: 100%;
        }
    }
</style>
