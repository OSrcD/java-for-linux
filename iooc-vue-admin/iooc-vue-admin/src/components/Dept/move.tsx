import {ComponentInternalInstance, defineComponent, getCurrentInstance, ref} from "vue"
import { deepTree } from "@/utils/role";
import useService from "@/hooks/useService";
import {ElMessage} from "element-plus";

export default defineComponent({
    name: "dept-move",
    emits: ['success', 'error'],
    setup(props, {emit}) {
        const form = ref<any>()
        const service = useService()
        const instance = getCurrentInstance() as ComponentInternalInstance

        const getDeptList = async function () {
            return await service.system.dept.list().then(deepTree);
        }
        const toMove = async function(ids: any) {
            let list = await getDeptList();

            console.log(list, "list")

            form.value.open({
                props: {
                    title: "部门转移",
                    width: "600px",
                },
                items: [
                    {
                        label: "选择部门",
                        prop: "dept",
                        component: {
                            name: "system-user__dept-move",
                            list: list,
                        }
                    }
                ],
                on: {
                    submit: (data: any, { done, close }: any) => {
                        if (!data.dept) {
                            ElMessage.warning("请选择部门")
                            return done();
                        }

                        const { name, id } = data.dept;

                        instance.proxy?.$confirm(`是否将用户转移到部门 ${name} 下`, "提示", {
                            type: "warning"
                        }).then(() => {
                            service.system.user
                                .move({
                                    departmentId: id,
                                    userIds: ids
                                })
                                .then((res: any) => {
                                    ElMessage.success("转移成功")
                                    emit("success", res);
                                    close();
                                })
                                .catch((err: any) => {
                                    ElMessage.error(err)
                                    emit("error", err);
                                    done();
                                });
                        }).catch(() => {});
                    }
                }
            })
        }

        return {
            form,
            toMove
        }
    },
    render() {
        return (
            <div class="io-dept-move">
                <io-form ref="form" />
            </div>
        )
    }
})
