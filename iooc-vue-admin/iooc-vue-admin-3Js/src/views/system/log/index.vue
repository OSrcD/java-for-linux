<template>
    <io-crud ref="crud" @load="onLoad">
        <el-row type="flex">
            <io-refresh-btn></io-refresh-btn>

            <el-button
                size="mini"
                type="danger"
                @click="clear"
            >
                清空
            </el-button>

            <io-filter label="日志保存天数">
                <el-input-number
                    controls-position="right"
                    size="mini"
                    :max="10000"
                    :min="1"
                    v-model="day"
                    @blur="saveDay"
                ></el-input-number>
            </io-filter>

            <io-flex />
            <io-search-key placeholder="请输入请求地址, 参数，ip地址"></io-search-key>
        </el-row>

        <el-row>
            <io-table v-bind="table"></io-table>
        </el-row>

        <el-row type="flex">
            <io-pagination></io-pagination>
        </el-row>
    </io-crud>
</template>

<script>
import { mapGetters } from "vuex";

export default {
    data() {
        return {
            day: 1,
            table: {
                props: {
                    "default-sort": {
                        prop: "createTime",
                        order: "descending"
                    }
                },
                columns: [
                    {
                        type: "index",
                        label: "#",
                        align: "center",
                        width: 60
                    },
                    {
                        prop: "userId",
                        label: "用户ID",
                        align: "center"
                    },
                    {
                        prop: "name",
                        label: "昵称",
                        align: "center",
                        minWidth: "150"
                    },
                    {
                        prop: "action",
                        label: "请求地址",
                        align: "center",
                        minWidth: "200",
                        "show-overflow-tooltip": true
                    },
                    {
                        prop: "params",
                        label: "参数",
                        align: "center",
                        minWidth: "200",
                        "show-overflow-tooltip": true
                    },
                    {
                        prop: "ip",
                        label: "ip",
                        minWidth: "180",
                        align: "center"
                    },
                    {
                        prop: "ipAddr",
                        label: "ip地址",
                        minWidth: "150",
                        align: "center"
                    },
                    {
                        prop: "createTime",
                        label: "创建时间",
                        minWidth: "150",
                        align: "center",
                        sortable: true
                    }
                ]
            }
        };
    },

    computed: {
        ...mapGetters(["permission"])
    },

    created() {
        this.$service.system.log.getKeep().then(res => {
            this.day = Number(res);
        });
    },

    methods: {
        onLoad({ ctx, app }) {
            ctx.service(this.$service.system.log).done();
            app.refresh();
        },

        saveDay() {
            this.$service.system.log.setKeep(this.day).then(() => {
                this.$message.success("保存成功");
            });
        },

        clear() {
            this.$confirm("是否要清空日志", "提示", {
                type: "warning"
            })
                .then(() => {
                    this.$service.system.log
                        .clear()
                        .then(() => {
                            this.$message.success("清空成功");
                            this.$refs["crud"].refresh();
                        })
                        .catch(err => {
                            this.$message.error(err);
                        });
                })
                .catch(() => {});
        }
    }
};
</script>
