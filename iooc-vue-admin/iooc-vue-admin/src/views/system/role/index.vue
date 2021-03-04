<template>
    <io-crud @load="onLoad">
        <el-row type="flex">
            <io-refresh-btn />
            <io-add-btn />
            <io-delete-btn />
            <io-flex />
            <io-search-key />
        </el-row>

        <el-row>
            <io-table v-bind="table"> </io-table>
        </el-row>

        <el-row type="flex">
            <io-flex />
            <io-pagination />
        </el-row>

        <io-upsert v-bind="upsert"></io-upsert>
    </io-crud>
</template>

<script lang="ts">
import {defineComponent} from "vue"
import useService from "@/hooks/useService";

export default defineComponent({
    setup() {
        const upsert = {
                props: {
                    width: "800px"
                },
                items: [
                    {
                        prop: "name",
                        label: "名称",
                        span: 12,
                        component: {
                            name: "el-input",
                            attrs: {
                                placeholder: "请填写名称"
                            }
                        },
                        rules: {
                            required: true,
                            message: "名称不能为空"
                        }
                    },
                    {
                        prop: "label",
                        label: "标识",
                        span: 12,
                        component: {
                            name: "el-input",
                            attrs: {
                                placeholder: "请填写标识"
                            }
                        },
                        rules: {
                            required: true,
                            message: "标识不能为空"
                        }
                    },
                    {
                        prop: "remark",
                        label: "备注",
                        span: 24,
                        component: {
                            name: "el-input",
                            props: {
                                type: "textarea",
                                rows: 4
                            },
                            attrs: {
                                placeholder: "请填写备注"
                            }
                        }
                    },
                    {
                        label: "功能权限",
                        prop: "menuIdList",
                        value: [],
                        component: {
                            name: "role-tree"
                        }
                    },
                    {
                        label: "数据权限",
                        prop: "departmentIdList",
                        value: [],
                        component: {
                            name: "dept-check"
                        }
                    }
                ]
            }
        const table = {
            props: {
                "default-sort": {
                    prop: "createTime",
                    order: "descending"
                }
            },
            columns: [
                {
                    type: "selection",
                    align: "center",
                    width: "60"
                },
                {
                    prop: "name",
                    label: "名称",
                    align: "center",
                    "min-width": 150
                },
                {
                    prop: "label",
                    label: "标识",
                    align: "center",
                    "min-width": 120
                },
                {
                    prop: "remark",
                    label: "备注",
                    align: "center",
                    "show-overflow-tooltips": true,
                    "min-width": 150
                },
                {
                    prop: "createTime",
                    label: "创建时间",
                    align: "center",
                    sortable: "custom",
                    "min-width": 150
                },
                {
                    prop: "updateTime",
                    label: "更新时间",
                    align: "center",
                    sortable: "custom",
                    "min-width": 150
                },
                {
                    label: "操作",
                    align: "center",
                    type: "op"
                }
            ]
        }
        const service = useService()

        const onLoad = function ({ ctx, app }: any) {
            ctx.service(service.system.role).done();

            app.refresh();
        }

        return {
            upsert,
            table,
            onLoad
        }
    }
})
</script>
