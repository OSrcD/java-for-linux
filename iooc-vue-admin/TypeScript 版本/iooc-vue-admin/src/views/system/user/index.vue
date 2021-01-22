<template>
    <div class="system-user">
        <div class="pane">
            <!-- 组织架构 -->
            <div class="dept" :class="[isExpand ? '_expand' : '_collapse']">
                <dept-tree
                    @row-click="onDeptRowClick"
                    @user-add="onDeptUserAdd"
                    @list-change="onDeptListChange"
                ></dept-tree>
            </div>

            <!-- 成员列表 -->
            <div class="user">
                <div class="header">
                    <div class="icon" @click="deptExpand">
                        <i class="el-icon-arrow-left" v-if="isExpand"></i>
                        <i class="el-icon-arrow-right" v-else></i>
                    </div>

                    <span>成员列表</span>
                </div>

                <div class="container">
                    <io-crud ref="crud" @load="onLoad" :on-refresh="onRefresh">
                        <el-row type="flex">
                            <io-refresh-btn />
                            <io-add-btn />
                            <io-delete-btn />
                            <el-button
                                v-permission="service.system.user.permission.move"
                                size="mini"
                                style="margin-left: 10px"
                                type="success"
                                :disabled="selects.ids.length == 0"
                                @click="toMove"
                            >转移</el-button
                            >
                            <io-flex />
                            <io-search-key />
                        </el-row>



                        <el-row>
                            <io-table
                                ref="table"
                                v-bind="tableList"
                                @selection-change="onSelectionChange"
                            >
                                <!-- 头像 -->
                                <template #column-headImg="{ scope }">
                                    <io-avatar
                                        shape="square"
                                        size="medium"
                                        :src="defaultAvatar(scope.row.headImg)"
                                        :style="{ margin: 'auto' }"
                                    >
                                    </io-avatar>
                                </template>

                                <!-- 权限 -->
                                <template #column-roleName="{ scope }">
                                    <el-tag
                                        v-for="(item, index) in scope.row.roleNameList"
                                        :key="index"
                                        disable-transitions
                                        size="small"
                                        effect="dark"
                                        style="margin: 2px"
                                    >{{ item }}</el-tag
                                    >
                                </template>

                                <!-- 单个转移 -->
                                <template #slot-move-btn="{ scope }">
                                    <el-button
                                        v-permission="service.system.user.permission.move"
                                        type="text"
                                        size="mini"
                                        @click="toMove(scope.row)"
                                    >转移</el-button
                                    >
                                </template>
                            </io-table>
                        </el-row>

                        <el-row type="flex">
                            <io-flex></io-flex>
                            <io-pagination></io-pagination>
                        </el-row>

                        <io-upsert
                            ref="upsert"
                            :items="upsertList.items"
                            :onSubmit="onUpsertSubmit"
                            @open="onUpsertOpen"
                        ></io-upsert>
                    </io-crud>
                </div>
            </div>
        </div>

        <!-- 部门移动 -->
        <dept-move ref="deptMove" @success="refresh({ page: 1 })"></dept-move>
    </div>
</template>

<script lang="ts">
import {defineComponent, ref, reactive, h} from "vue"
import {isPc} from "@/utils/role"
import useService from "@/hooks/useService";


export default defineComponent({
    setup() {
        const service = useService()
        const isExpand = ref(isPc())
        const crud = ref<any>()
        const upsert = ref<any>()
        const deptMove = ref<any>()
        const selects = reactive({
            dept: {},
            ids: []
        })
        const dept = ref([])
        const tableList = {
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
                        prop: "headImg",
                        label: "头像",
                        align: "center"
                    },
                    {
                        prop: "name",
                        label: "姓名",
                        align: "center",
                        "min-width": 150
                    },
                    {
                        prop: "username",
                        label: "用户名",
                        align: "center",
                        "min-width": 150
                    },
                    {
                        prop: "nickName",
                        label: "昵称",
                        align: "center",
                        "min-width": 150
                    },
                    {
                        prop: "departmentName",
                        label: "部门名称",
                        align: "center",
                        "min-width": 150
                    },
                    {
                        prop: "roleName",
                        label: "角色",
                        "header-align": "center",
                        "min-width": 200
                    },
                    {
                        prop: "phone",
                        label: "手机号码",
                        align: "center",
                        "min-width": 150
                    },
                    {
                        prop: "remark",
                        label: "备注",
                        align: "center",
                        "min-width": 150
                    },
                    {
                        prop: "status",
                        label: "状态",
                        align: "center",
                        "min-width": 120,
                        dict: [
                            {
                                label: "启用",
                                value: 1,
                                type: "success"
                            },
                            {
                                label: "禁用",
                                value: 0,
                                type: "danger"
                            }
                        ]
                    },
                    {
                        prop: "createTime",
                        label: "创建时间",
                        align: "center",
                        sortable: "custom",
                        "min-width": 150
                    },
                    {
                        align: "center",
                        type: "op",
                        layout: ["slot-move-btn", "edit", "delete"],
                        width: "160px"
                    }
                ]
            }
        const upsertList = {
            items: [
                {
                    prop: "headImg",
                    label: "头像",
                    span: 24,
                    component: {
                        name: "io-upload",
                        props: {
                            text: "选择头像",
                            icon: "el-icon-picture"
                        }
                    }
                },
                {
                    prop: "name",
                    label: "姓名",
                    span: 24,
                    component: {
                        name: "el-input",
                        attrs: {
                            placeholder: "请填写姓名"
                        }
                    },
                    rules: {
                        required: true,
                        message: "姓名不能为空"
                    }
                },
                {
                    prop: "nickName",
                    label: "昵称",
                    span: 12,
                    component: {
                        name: "el-input",
                        attrs: {
                            placeholder: "请填写昵称"
                        }
                    },
                    rules: {
                        required: true,
                        message: "昵称不能为空"
                    }
                },
                {
                    prop: "username",
                    label: "用户名",
                    span: 12,
                    component: {
                        name: "el-input",
                        attrs: {
                            placeholder: "请填写用户名"
                        }
                    },
                    rules: [
                        {
                            required: true,
                            message: "用户名不能为空"
                        }
                    ]
                },
                {
                    prop: "password",
                    label: "密码",
                    span: 12,
                    hidden: true,
                    component: {
                        name: "el-input",
                        attrs: {
                            placeholder: "请填写密码",
                            type: "password"
                        }
                    },
                    rules: [
                        {
                            min: 6,
                            max: 16,
                            message: "密码长度在 6 到 16 个字符"
                        }
                    ]
                },
                {
                    prop: "roleIdList",
                    label: "角色",
                    span: 24,
                    value: [],
                    component: {
                        name: "io-role-select",
                        props: {
                            props: {
                                "multiple-limit": 3
                            }
                        }
                    },
                    rules: {
                        required: true,
                        message: "角色不能为空"
                    }
                },
                {
                    prop: "phone",
                    label: "手机号码",
                    span: 12,
                    component: {
                        name: "el-input",
                        attrs: {
                            placeholder: "请填写手机号码"
                        }
                    }
                },
                {
                    prop: "email",
                    label: "邮箱",
                    span: 12,
                    component: {
                        name: "el-input",
                        attrs: {
                            placeholder: "请填写邮箱"
                        }
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
                    prop: "status",
                    label: "状态",
                    value: 1,
                    component: {
                        name: "el-radio-group",
                        options: [
                            {
                                label: "开启",
                                value: 1
                            },
                            {
                                label: "关闭",
                                value: 0
                            }
                        ]
                    }
                },
                {
                    prop: "tips",
                    hidden: true,
                    component: {
                        name: "j-warning"
                    }
                }
            ]
        }


        const refresh = function (params: any) {
            crud.value.refresh(params);
        }

        const onDeptRowClick = function ({ item, ids }: any) {
            selects.dept = item;
            refresh({
                page: 1,
                departmentIds: ids.join(",")
            });

            if (!isPc()) {
                isExpand.value = false;
            }
        }

        const onDeptUserAdd = function () {
            crud.value.rowAppend({
                departmentId: item.id
            });
        }

        const onDeptListChange = function (list: any) {
            dept.value = list
        }

        const deptExpand = function () {
            isExpand.value = !isExpand.value;
        }

        const onLoad = function ({ ctx, app }: any) {
            ctx.service(service.system.user).done();

            app.refresh();
        }

        const onRefresh = async function (params: any, { next, render }: any) {
            let { list } = await next(params);

            list.map((e: any) => {
                if (e.roleName) {
                    e.roleNameList = e.roleName.split(",")
                }

                e.status = Boolean(e.status);
            });

            render(list);
        }

        const onSelectionChange = function (selection: any) {
            selects.ids = selection.map((e) => e.id)
        }

        const defaultAvatar = function (url: any) {
            if (!url) {
                return require("@/assets/icon/default-avatar.png");
            }

            return url
        }

        const onUpsertSubmit = function (isEdit: boolean, data: any, { next }: any) {
            let departmentId = data.departmentId;

            if (!departmentId) {
                departmentId = selects.dept.id;

                if (!departmentId) {
                    departmentId = dept.value[0].id;
                }
            }

            next({
                ...data,
                departmentId
            });
        }

        const onUpsertOpen = function (isEdit: boolean) {
            upsert.value.toggleItem("password", isEdit);
            upsert.value.toggleItem("tips", !isEdit);
        }

        const toMove = async function (e) {
            let ids = [];

            if (!e.id) {
                ids = selects.ids;
            } else {
                ids = [e.id];
            }

            deptMove.value.toMove(ids);
        }

        return {
            isExpand,
            crud,
            dept,
            onDeptRowClick,
            onDeptUserAdd,
            onDeptListChange,
            selects,
            service,
            upsert,
            deptExpand,
            onLoad,
            onRefresh,
            tableList,
            upsertList,
            deptMove,
            onSelectionChange,
            defaultAvatar,
            onUpsertSubmit,
            onUpsertOpen,
            toMove,
            refresh
        }
    }
})
</script>


<style lang="scss" scoped>
.system-user {
    .pane {
        display: flex;
        height: 100%;
        width: 100%;
        position: relative;
    }

    .dept {
        height: 100%;
        width: 300px;
        max-width: calc(100% - 50px);
        background-color: #fff;
        transition: width 0.3s;
        margin-right: 10px;
        flex-shrink: 0;

        &._collapse {
            margin-right: 0;
            width: 0;
        }
    }

    .user {
        width: calc(100% - 310px);
        flex: 1;

        .header {
            display: flex;
            align-items: center;
            justify-content: center;
            height: 40px;
            position: relative;
            background-color: #fff;

            span {
                font-size: 14px;
                white-space: nowrap;
                overflow: hidden;
            }

            .icon {
                position: absolute;
                left: 0;
                top: 0;
                font-size: 18px;
                color: $color-main;
                cursor: pointer;
                background-color: #fff;
                height: 40px;
                width: 80px;
                line-height: 40px;
                padding-left: 10px;
            }
        }
    }

    .dept,
    .user {
        overflow: hidden;
        .container {
            height: calc(100% - 40px);
        }
    }

    @media only screen and (max-width: 768px) {
        .dept {
            width: calc(100% - 100px);
        }
    }
}
</style>
