<template>
    <div class="page-my-info">
        <div class="title">基本信息</div>

        <el-form size="small" label-width="100px" :model="form" :disabled="saving">
            <el-form-item label="头像">
                <io-upload v-model="form.headImg"></io-upload>
            </el-form-item>

            <el-form-item label="昵称">
                <el-input v-model="form.nickName" placeholder="请填写昵称"></el-input>
            </el-form-item>

            <el-form-item label="密码">
                <el-input type="password" v-model="form.password"></el-input>
            </el-form-item>

            <el-form-item label="">
                <el-button type="primary" @click="save" :disabled="saving">保存修改</el-button>
            </el-form-item>
        </el-form>
    </div>
</template>

<script lang="ts">
import {defineComponent, computed, reactive, ref, onMounted} from "vue"
import {useStore} from "@/hooks/useStore"
import {AllActionTypes} from "@/store/action-types"
import useService from "@/hooks/useService";
import {ElMessage} from "element-plus";

export default defineComponent({
    setup() {
        const store = useStore()
        const service = useService()

        let form = ref<any>({})
        const saving = ref(false)

        const userInfo = computed(() => store.getters.userInfo)

        onMounted(() => {
            form.value = userInfo.value
        })

        const save = function () {
            saving.value = true

            const {headImg, nickName, password} = form.value

            service.common.userUpdate({
                headImg,
                nickName,
                password
            }).then(() => {
                form.password = "";
                ElMessage.success("修改成功")
                store.dispatch(AllActionTypes.USERINFO)
            }).catch((err: any) => {
                ElMessage.error(err);
            }).done(() => {
                saving.value = false;
            });
        }

        return {
            userInfo,
            form,
            saving,
            save
        }
    }
})
</script>

<style lang="scss">
.page-my-info {
    background-color: #fff;
    height: 100%;
    padding: 20px;
    box-sizing: border-box;

    .el-form {
        width: 400px;
        max-width: 100%;
    }

    .title {
        color: #000;
        margin-bottom: 30px;
        font-size: 15px;
    }
}
</style>
