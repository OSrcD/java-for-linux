<template>
    <div class="page-login">
        <div class="box">
            <img class="logo" src="@/assets/logo.png" alt="" />
            <p class="desc">Vue3-element-admin 快速开发后台权限管理系统</p>

            <el-form ref="form" class="form" size="medium" :disabled="saving">
                <el-form-item label="用户名">
                    <el-input
                            placeholder="请输入用户名"
                            v-model="username"
                            maxlength="20"
                            auto-complete="off"
                    ></el-input>
                </el-form-item>

                <el-form-item label="密码">
                    <el-input
                            type="password"
                            placeholder="请输入密码"
                            v-model="password"
                            maxlength="20"
                            auto-complete="off"
                    ></el-input>
                </el-form-item>

                <el-form-item label="验证码" class="captcha">
                    <el-input
                            placeholder="请输入图片验证码"
                            maxlength="4"
                            v-model="verifyCode"
                            auto-complete="off"
                            @keyup.enter.native="next"
                    ></el-input>

                    <captcha
                            ref="captcha"
                            class="value"
                            v-model="captchaId"
                            @change="captchaChange"
                    ></captcha>
                </el-form-item>
            </el-form>

            <el-button round size="mini" class="submit-btn" @click="next" :loading="saving"
            >登录</el-button
            >
        </div>
    </div>
</template>


<script lang="ts">

    interface UserProps {
        username: string;
        password: string;
        captchaId: string;
        verifyCode: string;
    }

    import {defineComponent, ref, reactive, toRefs, onMounted} from "vue"
    import {ElMessage} from "element-plus"
    import Captcha from "@/components/Common/captcha.vue"
    import {useStore} from "@/hooks/useStore"
    import {useRouter} from "vue-router"
    import {AllActionTypes} from "@/store/action-types"
    export default defineComponent({
        components: {
            Captcha
        },
        setup() {
            const store = useStore()
            const router = useRouter()
            const form = reactive<UserProps>({
                username: "admin",
                password: "123456",
                captchaId: "",
                verifyCode: ""
            })
            const saving = ref(false)
            const captcha = ref()

            const captchaChange = () => {
                form.verifyCode = ""
            }




            onMounted(() => {

                // if (captcha.value) {
                //     console.log((captcha.value as Captcha).refresh())
                // }
            })

            const next = async () => {
                console.log(form, "form")
                if (!form.username) {
                    return ElMessage.warning("用户名不能为空");
                }

                if (!form.password) {
                    return ElMessage.warning("密码不能为空");
                }

                if (!form.verifyCode) {
                    return ElMessage.warning("图片验证码不能为空");
                }

                saving.value = true

                try {

                    await store.dispatch(AllActionTypes.LOGIN, form)

                    await store.dispatch(AllActionTypes.USERINFO)

                    const [first] = await store.dispatch(AllActionTypes.PERM_MENU)

                    if (!first) {
                        ElMessage.error("该账号没有权限");
                    } else {
                        router.push("/");
                    }

                    saving.value = false
                } catch (e) {
                    captcha.value.refresh()
                    saving.value = false
                    ElMessage.error(e)
                }
            }

            return {
                saving,
                ...toRefs(form),
                captchaChange,
                next,
                captcha
            }
        }

    })
</script>


<style lang="scss" scoped>
    .page-login {
        height: 100vh;
        width: 100vw;
        position: relative;
        background-color: $color-main;

        .box {
            display: flex;
            flex-direction: column;
            justify-content: center;
            align-items: center;
            height: 500px;
            width: 500px;
            position: absolute;
            left: calc(50% - 250px);
            top: calc(50% - 250px);

            .logo {
                height: 50px;
                margin-bottom: 20px;
            }

            .desc {
                color: #ccc;
                font-size: 12px;
                margin-bottom: 60px;
                letter-spacing: 1px;
            }

            /deep/.el-form {
                width: 300px;
                border-radius: 3px;

                .el-form-item {
                    margin-bottom: 20px;

                    &__label {
                        color: #ccc;
                    }
                }

                .el-input {
                    .el-input__inner {
                        border: 0;
                        border-bottom: 0.5px solid #999;
                        border-radius: 0;
                        padding: 0;
                        background-color: transparent;
                        color: #ccc;
                        transition: border-color 0.3s;
                        position: relative;

                        &:focus {
                            border-color: #fff;
                            color: #fff;
                        }

                        &:-webkit-autofill {
                            -webkit-text-fill-color: #fff !important;
                            -webkit-box-shadow: 0 0 0px 1000px transparent inset !important;
                            transition: background-color 50000s ease-in-out 0s;
                        }
                    }
                }

                .captcha {
                    position: relative;

                    .value {
                        position: absolute;
                        bottom: 1px;
                        right: 0;
                    }
                }
            }

            .submit-btn {
                margin-top: 40px;
                border-radius: 30px;
                padding: 10px 40px;
                color: #000;
            }
        }
    }
</style>
