<template>
    <div class="io-role-tree" v-loading="loading">
        <p>{{ title }}</p>

        <el-input placeholder="输入关键字进行过滤" v-model="keyword" size="small"> </el-input>

        <div class="scroller">
            <el-tree
                :data="list"
                :props="propsTree"
                :default-checked-keys="checked"
                :filter-node-method="filterNode"
                highlight-current
                node-key="id"
                show-checkbox
                ref="elTree"
                @check-change="save"
            >
            </el-tree>
        </div>
    </div>
</template>

<script lang="ts">
import {defineComponent, reactive, ref, watch, onMounted} from "vue"
import { deepTree } from "@/utils/role";
import useService from "@/hooks/useService";
import {ElMessage} from "element-plus";

export default defineComponent({
    name: "role-tree",
    props: {
        modelValue: Array,
        value: Array,
        title: String
    },
    emits: ['update:modelValue'],
    setup(props, {emit}) {
        const service = useService()
        let elTree = ref<any>()
        let list = ref<any>([])
        let checked  = ref<any>([])
        let keyword = ref("")
        let loading = ref(false)
        let propsTree = {
            label: "name",
            children: "children"
        }

        watch(() => keyword.value, (val) => {
            elTree.value.filter(val);
        })

        watch(() => props.modelValue, (newVal) => {
            refreshTree(newVal);
        })

        onMounted(() => {
            refresh()
        })

        const refreshTree = function (val: any) {
            if (!val) {
                checked.value = [];
            }

            let ids: any[] = [];

            // 处理半选状态
            let fn = (arr: any) => {
                arr.forEach((e: any) => {
                    if (e.children) {
                        fn(e.children);
                    } else {
                        ids.push(Number(e.id));
                    }
                });
            };

            fn(list.value);

            checked.value = ids.filter((id) => (val || []).includes(id));

        }

        const refresh = function () {
            service.system.menu
                .list()
                .then((res: any) => {
                    list.value = deepTree(res);

                    refreshTree(props.value);
                })
                .catch((err: any) => {
                    ElMessage.error(err)
                });
        }

        const filterNode = function (val: any, data: any) {
            if (!val) return true;
            return data.name.includes(val);
        }

        const save = function () {
            // 选中的节点
            const checked = elTree.value.getCheckedKeys();
            // 半选中的节点
            const halfChecked = elTree.value.getHalfCheckedKeys();

            emit("update:modelValue", [...checked, ...halfChecked]);
        }

        return {
            list,
            checked,
            keyword,
            props,
            loading,
            propsTree,
            refreshTree,
            refresh,
            filterNode,
            save,
            elTree
        }

    }
})
</script>

<style scoped>

</style>
