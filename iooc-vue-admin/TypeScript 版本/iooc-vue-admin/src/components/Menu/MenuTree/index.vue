<template>
    <div class="menu-tree">
        <!--    <p>{{treeList}}</p>-->
        <el-popover
            :width="500"
            ref="popover"
            placement="bottom-start"
            trigger="click"
            popper-class="popper-menu-tree"
        >

            <template #reference>
                <el-input v-model="name" readonly placeholder="请选择"></el-input>
            </template>

            <el-input size="small" v-model="filterValue">
                <i slot="prefix" class="el-input__icon el-icon-search"></i>
            </el-input>

            <el-tree
                ref="tree"
                node-key="menuId"
                :data="treeList"
                :props="props"
                :highlight-current="true"
                :expand-on-click-node="false"
                :default-expanded-keys="expandedKeys"
                :filter-node-method="filterNode"
                @current-change="currentChange"
            >
            </el-tree>
        </el-popover>

    </div>
</template>

<script lang="ts">
import {defineComponent, toRefs, reactive, watch, ref, computed, onMounted} from "vue"
import {deepTree} from "@/utils/role"
import {MenuApi} from "@/api"
import {MenuProps} from "@/store/interface"

interface StateProps {
    label: string;
    children: string;
}

interface StateProp {
    filterValue: string;
    list: MenuProps[];
    props: StateProps;
    expandedKeys: any[];
}

export default defineComponent({
    name: "menu-tree",
    props: {
        modelValue: String,
        value: String
    },
    emits: ['update:modelValue'],
    setup(props, context) {
        const tree = ref<any>()
        const state = reactive<StateProp>({
            filterValue: "",
            list: [],
            props: {
                label: "name",
                children: "children"
            },
            expandedKeys: [],
        })

        const name = computed(() => {
            const item = state.list.find((e) => e.id == props.modelValue);
            return item ? item.name : "一级菜单";
        })

        const treeList = computed(() => {
            return deepTree(state.list)
        })

        const filterNode = function (value: string, data: any) {
            if (!value) return true;
            return data.name.indexOf(value) !== -1;
        }

        const currentChange = function ({id}: string) {
            context.emit("update:modelValue", id)
        }

        const menuList = function () {
            MenuApi.GetMenuList().then(res => {
                let list = res.filter((e: MenuProps) => e.type != 2);

                list.unshift({
                    name: "一级菜单",
                    id: null,
                    children: []
                });

                state.list = list
            })
        }

        onMounted(() => {
            menuList()
        })

        watch(() => state.filterValue, (val) => {
            tree.value.filter(val)
        })

        return {
            ...toRefs(state),
            tree,
            treeList,
            name,
            filterNode,
            currentChange
        }
    }
})
</script>

<style scoped lang="scss">
.popper-menu-tree {
    width: 480px;
    box-sizing: border-box;

    .el-input {
        margin-bottom: 10px;
    }

    .el-tree {
    }
}
</style>