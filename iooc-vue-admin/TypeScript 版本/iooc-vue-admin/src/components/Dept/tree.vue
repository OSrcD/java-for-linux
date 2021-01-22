<template>
    <div class="io-dept-tree">
        <div class="io-dept-tree__header">
            <div>组织架构</div>

            <ul class="io-dept-tree__op">
                <li>
                    <el-tooltip content="刷新">
                        <i class="el-icon-refresh" @click="refresh()"></i>
                    </el-tooltip>
                </li>

                <li v-if="drag && isPc">
                    <el-tooltip content="拖动排序">
                        <i class="el-icon-s-operation" @click="isDrag = true"></i>
                    </el-tooltip>
                </li>

                <li class="no" v-show="isDrag">
                    <el-button type="text" size="mini" @click="treeOrder(true)">保存</el-button>
                    <el-button type="text" size="mini" @click="treeOrder(false)">取消</el-button>
                </li>
            </ul>
        </div>

        <div class="io-dept-tree__container" @contextmenu.prevent="openCM">
            <el-tree
                node-key="id"
                highlight-current
                default-expand-all
                :data="list"
                :props="{
					label: 'name'
				}"
                :draggable="isDrag"
                :allow-drag="allowDrag"
                :allow-drop="allowDrop"
                :expand-on-click-node="false"
                v-loading="loading"
                @node-contextmenu="openCM"
            >
                <template v-slot="{ node, data }">
                    <div class="io-dept-tree__node">
						<span class="io-dept-tree__node-label" @click="rowClick(data)">{{
                                node.label
                            }}</span>
                        <span
                            class="io-dept-tree__node-icon"
                            v-if="!isPc"
                            @click="openCM($event, data, node)"
                        >
							<i class="el-icon-more"></i>
						</span>
                    </div>
                </template>
            </el-tree>
        </div>

        <!-- 部门编辑 -->
        <io-form ref="deptUpsert"> </io-form>

        <!-- 右键按钮 -->
        <context-menu ref="contextMenu"></context-menu>
    </div>
</template>

<script lang="ts">
import {defineComponent, reactive, ref, toRefs, ComponentInternalInstance, getCurrentInstance} from "vue"
import {deepTree, revDeepTree, isArray, isPc} from "@/utils/role"
import useService from "@/hooks/useService";
import {ElMessage} from "element-plus";

import type {MenuProps} from "@/store/interface"

export default defineComponent({
    name: "dept-tree",
    props: {
        drag: {
            type: Boolean,
            default: true
        },
        level: {
            type: Number,
            default: 99
        }
    },
    emits: ["list-change", "user-add", "row-click"],
    setup(props, {emit}) {
        const service = useService()
        const instance = getCurrentInstance() as ComponentInternalInstance

        const state = reactive<any>({
            list: [],
            loading: false,
            isDrag: false,
            isPc: isPc()
        })

        const contextMenu = ref<any>()
        const deptUpsert = ref<any>()

        const allowDrag = function ({ data }: any) {
            return data.parentId;
        }

        const allowDrop = function (draggingNode, dropNode) {
            return dropNode.data.parentId;
        }

        const refresh = function () {
            state.isDrag = false;
            state.loading = true;

            service.system.dept
                .list()
                .then((res) => {
                    state.list = deepTree(res);
                    emit("list-change", state.list);
                })
                .done(() => {
                    state.loading = false;
                });
        }

        const rowClick = function (e: any) {
            console.log(e, "eeee")
            contextMenu.value.close();
            let ids = revDeepTree(e.children).map((e) => e.id);
            ids.unshift(e.id);
            emit("row-click", { item: e, ids });
        }

        const rowEdit = function (e: any) {
            const method = e.id ? "update" : "add";

            deptUpsert.value.open({
                props: {
                    title: "编辑部门",
                    width: "550px",
                    // "label-width": "100px"
                },
                items: [
                    {
                        label: "部门名称",
                        prop: "name",
                        value: e.name,
                        component: {
                            name: "el-input",
                            attrs: {
                                placeholder: "请填写部门名称"
                            }
                        },
                        rules: {
                            required: true,
                            message: "部门名称不能为空"
                        }
                    },
                    {
                        label: "上级部门",
                        prop: "parentId",
                        value: e.parentName || "...",
                        component: {
                            name: "el-input",
                            attrs: {
                                disabled: true
                            }
                        }
                    },
                    {
                        label: "排序",
                        prop: "orderNum",
                        value: e.orderNum || 0,
                        component: {
                            name: "el-input-number",
                            props: {
                                "controls-position": "right",
                                min: 0,
                                max: 100
                            }
                        }
                    }
                ],
                on: {
                    submit: (data: any, { done, close }: any) => {
                        service.system.dept[method]({
                            id: e.id,
                            parentId: e.parentId,
                            name: data.name,
                            orderNum: data.orderNum
                        })
                            .then(() => {
                                ElMessage.success(`新增部门${data.name}成功`);
                                close();
                                refresh();
                            })
                            .catch((err) => {
                                ElMessage.error(err);
                                done();
                            });
                    }
                }
            })
        }

        const rowDel = function (e: any) {
            const del = (f: any) => {
                service.system.dept
                    .delete({
                        ids: e.id,
                        deleteUser: f
                    })
                    .then(() => {
                        if (f) {
                            ElMessage.success("删除成功");
                        } else {
                            instance.proxy?.$confirm("该部门用户已移动到部门顶级", "删除成功")
                        }
                    })
                    .done(() => {
                        refresh();
                    });
            };

            instance.proxy?.$confirm("该操作会删除部门下的所有用户，是否确认？", "提示", {
                type: "warning",
                confirmButtonText: "直接删除",
                cancelButtonText: "保留用户",
                distinguishCancelAndClose: true
            }).then(() => {
                del(true);
            })
                .catch((action) => {
                    if (action == "cancel") {
                        del(false);
                    }
                });
        }

        const treeOrder = function (f: any) {
            if (f) {
                instance.proxy?.$confirm("部门架构已发生改变，是否保存？", "提示", {
                    type: "warning"
                }).then(() => {
                    let ids = [];

                    const deep = (list: MenuProps[], pid: string) => {
                        list.forEach((e) => {
                            e.parentId = pid;
                            ids.push(e);

                            if (e.children && isArray(e.children)) {
                                deep(e.children, e.id);
                            }
                        });
                    };

                    deep(state.list, null);

                    service.system.dept
                        .order(
                            ids.map((e, i) => {
                                return {
                                    id: e.id,
                                    parentId: e.parentId,
                                    orderNum: i
                                };
                            })
                        )
                        .then(() => {
                            ElMessage.success("更新排序成功");
                        })
                        .catch((err) => {
                            ElMessage.error(err);
                        })
                        .done(() => {
                            refresh();
                            state.isDrag = false;
                        });
                })
                    .catch(() => {});
            } else {
                refresh();
            }
        }

        const openCM = function (e: any, d: any, n: any) {
            let list = [
                {
                    label: "新增",
                    "suffix-icon": "el-icon-plus",
                    hidden: n && n.level >= props.level,
                    callback: (item: any, done: any) => {
                        rowEdit({
                            name: "",
                            parentName: d.name,
                            parentId: d.id
                        });
                        done();
                    }
                },
                {
                    label: "编辑",
                    "suffix-icon": "el-icon-edit",
                    callback: (item, done) => {
                        rowEdit(d);
                        done();
                    }
                }
            ];

            if (!d) {
                d = state.list[0];
            }

            if (d.parentId) {
                list.push({
                    label: "删除",
                    "suffix-icon": "el-icon-delete",
                    callback: (item, done) => {
                        rowDel(d);
                        done();
                    }
                });
            }

            list.push({
                label: "新增成员",
                "suffix-icon": "el-icon-user",
                callback: (item, done) => {
                    emit("user-add", d);
                    done();
                }
            });

            contextMenu.value.open(e, {
                list
            });
        }

        refresh()

        return {
            ...toRefs(state),
            contextMenu,
            deptUpsert,
            allowDrag,
            allowDrop,
            rowClick,
            rowEdit,
            rowDel,
            treeOrder,
            openCM,
            refresh
        }
    }
})
</script>


<style lang="scss" scoped>
.io-dept-tree {
    height: 100%;
    width: 100%;

    &__header {
        display: flex;
        align-items: center;
        height: 40px;
        padding: 0 10px;
        background-color: #fff;
        letter-spacing: 1px;
        position: relative;

        div {
            font-size: 14px;
            color: $color-main;
            flex: 1;
            white-space: nowrap;
        }

        i {
            font-size: 18px;
            color: $color-main;
            cursor: pointer;
        }
    }

    /deep/.el-tree-node__content {
        height: 36px;
    }

    &__op {
        display: flex;

        li {
            display: flex;
            justify-content: center;
            align-items: center;
            list-style: none;
            margin-left: 5px;
            padding: 5px;
            cursor: pointer;

            &:not(.no):hover {
                background-color: #eee;
            }
        }
    }

    &__container {
        height: calc(100% - 40px);
        overflow-y: auto;
        overflow-x: hidden;

        /deep/.el-tree-node__content {
            margin: 0 5px;
        }
    }

    &__node {
        display: flex;
        align-items: center;
        width: 100%;
        box-sizing: border-box;

        &-label {
            flex: 1;
            font-size: 14px;
            overflow: hidden;
            text-overflow: ellipsis;
            white-space: nowrap;
        }

        &-icon {
            height: 28px;
            width: 28px;
            line-height: 28px;
            text-align: center;
            margin-right: 5px;
        }
    }
}
</style>
