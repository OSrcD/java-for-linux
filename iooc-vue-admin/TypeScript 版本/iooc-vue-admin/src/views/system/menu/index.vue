<template>
    <div>
        <io-crud ref="crud" @load="onLoad" :on-refresh="onRefresh" :on-delete="onDelete">
            <el-row type="flex">
                <io-refresh-btn/>
                <io-add-btn/>
            </el-row>

            <io-table ref="table" v-bind="tableList" @row-click="onRowClick" @row-contextmenu="onRowContextMenu">
                <template #column-name="{ scope }">
                    <span>{{ scope.row.name }}</span>
                    <el-tag
                        size="mini"
                        effect="dark"
                        type="danger"
                        v-if="!scope.row.isShow"
                        style="margin-left: 10px"
                    >隐藏
                    </el-tag
                    >
                </template>

                <!-- 图标 -->
                <template #column-icon="{ scope }">
                    <icon-svg :name="scope.row.icon" size="16px" style="margin-top: 5px"></icon-svg>
                </template>

                <!-- 权限 -->
                <template #column-perms="{ scope }">
                    <el-tag
                        v-for="(item, index) in scope.row.permList"
                        :key="index"
                        size="mini"
                        effect="dark"
                        style="margin: 2px; letter-spacing: 0.5px"
                    >{{ item }}
                    </el-tag
                    >
                </template>

                <!-- 路由 -->
                <template #column-router="{ scope }">
                    <el-link type="primary" :href="scope.row.router" v-if="scope.row.type == 1">{{
                            scope.row.router
                        }}
                    </el-link>
                    <span v-else>{{ scope.row.router }}</span>
                </template>

                <!-- 路由缓存 -->
                <template #column-keepAlive="{ scope }">
                    <template v-if="scope.row.type === 1">
                        <i class="el-icon-check" v-if="scope.row.keepAlive"></i>
                        <i class="el-icon-close" v-else></i>
                    </template>
                </template>

                <!-- 行新增 -->
                <template #slot-add="{ scope }">
                    <el-button
                        type="text"
                        size="mini"
                        @click="upsertAppend(scope.row)"
                        v-if="scope.row.type != 2"
                    >新增
                    </el-button
                    >
                </template>
            </io-table>

            <io-upsert ref="upsert" v-bind="upsertList" @open="onUpsertOpen" :on-submit="onUpsertSubmit"></io-upsert>
        </io-crud>

        <context-menu ref="contextMenu"></context-menu>
    </div>
</template>

<script lang="ts">
import {defineComponent, ref} from "vue"
import {deepTree} from "@/utils/role"
import useService from "@/hooks/useService";
import {useStore} from "@/hooks/useStore"
import {AllActionTypes} from "@/store/action-types";

export default defineComponent({
    setup() {
        const service = useService()
        const store = useStore()
        const crud = ref<any>()
        const upsert = ref<any>()
        const table = ref<any>()
        const contextMenu = ref<any>()


        const tableList = {
            props: {
                "row-key": "id"
            },
            columns: [
                {
                    prop: "name",
                    label: "名称",
                    width: 200
                },
                {
                    prop: "icon",
                    label: "图标",
                    align: "center",
                    width: 80
                },
                {
                    prop: "type",
                    label: "类型",
                    align: "center",
                    width: 100,
                    dict: [
                        {
                            label: "目录",
                            value: 0,
                            type: "success"
                        },
                        {
                            label: "菜单",
                            value: 1,
                            type: "danger"
                        },
                        {
                            label: "权限",
                            value: 2
                        }
                    ]
                },
                {
                    prop: "router",
                    label: "节点路由",
                    align: "center",
                    "min-width": 160
                },
                {
                    prop: "keepAlive",
                    label: "路由缓存",
                    align: "center",
                    width: 100
                },
                {
                    prop: "viewPath",
                    label: "文件路径",
                    align: "center",
                    "min-width": 200,
                    "show-overflow-tooltip": true
                },
                {
                    prop: "perms",
                    label: "权限",
                    "header-align": "center",
                    "min-width": 300
                },
                {
                    prop: "orderNum",
                    label: "排序号",
                    align: "center",
                    width: 90
                },
                {
                    prop: "updateTime",
                    label: "更新时间",
                    align: "center",
                    sortable: "custom",
                    width: 150
                },
                {
                    label: "操作",
                    align: "center",
                    type: "op",
                    layout: ["slot-add", "edit", "delete"]
                }
            ]
        }
        const upsertList = {
            on: {
                open() {
                    console.log("打开")
                }
            },
            props: {
                width: "800px"
            },
            items: [
                {
                    prop: "type",
                    value: 0,
                    label: "节点类型",
                    span: 24,
                    component: {
                        name: "el-radio-group",
                        options: [
                            {
                                label: "目录",
                                value: 0,
                            },
                            {
                                label: "菜单",
                                value: 1,
                            },
                            {
                                label: "权限",
                                value: 2
                            }
                        ],
                        onChange: (index: number) => {
                            changeType(index)
                        }
                    }
                },
                {
                    prop: "name",
                    label: "节点名称",
                    span: 24,
                    component: {
                        name: "el-input",
                        attrs: {
                            placeholder: "请输入节点名称"
                        }
                    },

                    rules: {
                        required: true,
                        message: "名称不能为空"
                    }
                },
                {
                    prop: "parentId",
                    label: "上级节点",
                    span: 24,
                    component: {
                        name: "menu-tree"
                    }
                },
                {
                    prop: "router",
                    label: "节点路由",
                    span: 24,
                    hidden: true,
                    component: {
                        name: "el-input",
                        attrs: {
                            placeholder: "请输入节点路由"
                        }
                    }
                },
                {
                    prop: "keepAlive",
                    value: true,
                    label: "路由缓存",
                    span: 24,
                    component: {
                        name: "el-radio-group",
                        options: [
                            {
                                label: "开启",
                                value: true
                            },
                            {
                                label: "关闭",
                                value: false
                            }
                        ]
                    }
                },
                {
                    prop: "isShow",
                    label: "是否显示",
                    span: 24,
                    value: true,
                    hidden: false,
                    component: {
                        name: "el-switch"
                    }
                },
                {
                    prop: "viewPath",
                    label: "文件路径",
                    span: 24,
                    hidden: true,
                    component: {
                        name: "menu-file-path"
                    }
                },
                {
                    prop: "icon",
                    label: "节点图标",
                    span: 24,
                    component: {
                        name: "menu-icons"
                    }
                },
                {
                    prop: "orderNum",
                    label: "排序号",
                    span: 24,
                    component: {
                        name: "el-input-number",
                        props: {
                            placeholder: "请填写排序号",
                            min: 0,
                            max: 99,
                            "controls-position": "right"
                        }
                    }
                },
                {
                    prop: "perms",
                    label: "权限",
                    span: 24,
                    hidden: true,
                    component: {
                        name: "menu-perms"
                    }
                }
            ]
        }

        const onLoad = function ({ctx, app}: any) {
            ctx.service(service.system.menu)
                .set("dict", {api: {page: "list", update: "update"}})
                .done();

            app.refresh();
        }

        const changeType = function (index: any) {
            const {toggleItem} = upsert.value;
            toggleItem("router", index == 1);
            toggleItem("viewPath", index == 1);
            toggleItem("keepAlive", index == 1);
            toggleItem("icon", index != 2);
            toggleItem("perms", index == 2);
            toggleItem("isShow", index != 2);
        }

        const onUpsertOpen = function (isEdit: Boolean, data: any) {
            changeType(data ? data.type : 0)
        }

        const onRefresh = function (params: any, {next, render}: any) {
            service.system.menu.list().then((list) => {
                list.map((e) => {
                    e.permList = e.perms ? e.perms.split(",") : [];
                });
                render(deepTree(list));
            });
        }

        const upsertAppend = function ({type, id}: any) {
            crud.value.rowAppend({
                parentId: id,
                type: type + 1
            })
        }

        const setPermission = function ({ id }) {
            crud.value.rowAppend({
                parentId: id,
                type: 2
            })
        }

        const onDelete = async function (selections: any[], {next}: any) {
            await next({
                ids: selections.map(e => e.id).join(",")
            });
            updateMenu();
        }

        const onRowClick = function (row: any, column: any) {
            if (column.property && row.children) {
                table.value.toggleRowExpansion(row);
            }
        }

        const onUpsertSubmit = async function (isEdit: boolean, data: any, { next }: any) {
            await next(data);
            updateMenu();
        }

        const updateMenu = function () {
            store.dispatch(AllActionTypes.PERM_MENU)
        }


        const onRowContextMenu = function (row: any, column: any, event: Event) {
            const {rowEdit, rowDelete} = crud.value
            let list = [
                {
                    label: "编辑",
                    callback: (e, close) => {
                        rowEdit(row);
                        close();
                    }
                },
                {
                    label: "删除",
                    callback: (e, close) => {
                        rowDelete(row);
                        close();
                    }
                }
            ];

            if (row.type != 2) {
                list.unshift({
                    label: "新增",
                    callback: (e, close) => {
                        upsertAppend(row);
                        close();
                    }
                });
            }

            if (row.type == 1) {
                list.push({
                    label: "权限",
                    callback: (e, close) => {
                        setPermission(row);
                        close();
                    }
                });
            }

            contextMenu.value.open(event, {
                list
            })
            // this.$refs["context-menu"].open(event, {
            //     list
            // });

            event.preventDefault();
        }

        return {
            onLoad,
            onRefresh,
            tableList,
            upsertAppend,
            crud,
            table,
            upsert,
            onRowClick,
            onRowContextMenu,
            contextMenu,
            upsertList,
            onUpsertOpen,
            service,
            onUpsertSubmit,
            onDelete
        }
    }
})
</script>

<style scoped>

</style>
