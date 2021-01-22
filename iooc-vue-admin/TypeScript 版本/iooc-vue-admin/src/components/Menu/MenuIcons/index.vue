<template>
    <div class="menu-icons">
        <el-popover
            :width="500"
            ref="iconPopover"
            placement="bottom-start"
            trigger="click"
            popper-class="popper-menu-icon"
        >

            <template #reference>
                <el-input v-model="modelValue" readonly placeholder="请选择"></el-input>
            </template>

            <el-row :gutter="10" class="list">
                <el-col :span="3" :xs="4" v-for="(item, index) in list" :key="index">
                    <el-button
                        size="mini"
                        :class="{ 'is-active': item === modelValue }"
                        @click="onSelect(item)"
                    >
                        <icon-svg :name="item"></icon-svg>
                    </el-button>
                </el-col>
            </el-row>
        </el-popover>
    </div>
</template>

<script lang="ts">
import {defineComponent, reactive, toRefs, onMounted, watch, ref} from "vue"
import {iconList} from "@/icons";

export default defineComponent({
    name: "menu-icons",
    inheritAttrs: false,

    props: {
        modelValue: String,
        value: String
    },
    emits: ["update:modelValue"],
    setup(props, context) {

        const iconName = ref()
        const state = reactive<any>({
            list: []
        })

        onMounted(() => {
            state.list = iconList()
        })

        const onSelect = function (icon: string) {
            context.emit("update:modelValue", icon)
        }

        return {
            ...toRefs(state),
            onSelect,
            iconName
        }
    }

})
</script>

<style scoped lang="scss">
.popper-menu-icon {
    width: 480px;
    max-width: 90%;
    box-sizing: border-box;

    .list {
        height: 250px;
        overflow-y: auto;
        display: flex;
        flex-wrap: wrap;
    }

    .el-button {
        margin-bottom: 10px;
        height: 40px;
        width: 100%;
        padding: 0;

        .icon-svg {
            font-size: 18px;
            color: #444;
        }
    }
}
</style>