<template>
    <div class="io-upload__wrap">
        <div
            class="io-upload"
            :class="[
				`io-upload--${listType}`,
				{
					'is-multiple': multiple,
					'is-drag': drag
				}
			]"
        >
            <el-input class="io-upload__hidden" type="hidden" v-model="modelValue"></el-input>

            <el-upload
                :action="JAction"
                :accept="JAccept"
                :multiple="multiple"
                :limit="limit"
                :data="data"
                :name="name"
                :drag="drag"
                :list-type="listType"
                :file-list="fileList"
                :show-file-list="JShowFileList"
                :auto-upload="autoUpload"
                :disabled="disabled"
                :headers="{
					Authorization: token,
					...headers
				}"
                :http-request="action ? undefined : httpRequest"
                :on-remove="JOnRemove"
                :on-preview="JOnPreview"
                :on-success="jOnSuccess"
                :on-error="onError"
                :on-progress="onProgress"
                :on-change="onChange"
                :on-exceed="onExceed"
                :before-upload="jBeforeUpload"
                :before-remove="beforeRemove"
                :style="jStyle"
                v-loading="jLoading"
            >
                <slot>
                    <!-- picture-card -->
                    <template v-if="listType == 'picture-card'">
                        <i :class="['io-upload__icon', icon]"></i>
                        <span class="io-upload__text" v-if="text">{{ text }}</span>
                    </template>

                    <!-- file -->
                    <template v-else-if="listType == 'file'">
                        <el-button size="mini" type="primary" :loading="loading"
                        >点击上传
                        </el-button
                        >
                    </template>

                    <template v-else>
                        <div class="io-upload__cover" v-if="jUrls[0]">
                            <img v-if="jUrls[0].type == 'image'" :src="jUrls[0].url"/>

                            <span v-else>{{ _urls[0].name }}</span>
                        </div>

                        <template v-else>
                            <i :class="['io-upload__icon', icon]"></i>
                            <span class="io-upload__text" v-if="text">{{ text }}</span>
                        </template>
                    </template>
                </slot>
            </el-upload>
        </div>

        <io-dialog
            title="图片预览"
            v-model="preview.visible"
            :props="{
				width: previewWidth
			}"
        >
            <img width="100%" :src="preview.url" alt=""/>
        </io-dialog>
    </div>
</template>


<script>
import {defineComponent, ref, reactive, computed, watch} from "vue"
import {useStore} from "@/hooks/useStore"
import {baseUrlT} from "@/config";
import _ from "lodash";
import useService from "@/hooks/useService";
import {ElMessage} from "element-plus";

export default defineComponent({
    name: "io-upload",
    props: {
        value: [Array, String],
        modelValue: [Array, String],
        // 上传的地址，当为 comm 时，调用 /comm/upload 接口
        action: {
            type: String,
            default: ""
        },
        size: {
            type: [Array, String, Number],
            default: "128px"
        },
        icon: {
            type: String,
            default: "el-icon-upload"
        },
        text: {
            type: String,
            default: "选择文件"
        },
        accept: String,
        multiple: Boolean,
        limit: Number,
        data: Object,
        name: {
            type: String,
            default: "file"
        },
        drag: Boolean,
        listType: {
            type: String,
            default: "default"
        },
        showFileList: {
            type: Boolean,
            default: undefined
        },
        autoUpload: {
            type: Boolean,
            default: true
        },
        disabled: Boolean,
        headers: Object,
        onRemove: Function,
        onPreview: Function,
        onSuccess: Function,
        onError: Function,
        onProgress: Function,
        onChange: Function,
        onExceed: Function,
        beforeUpload: Function,
        beforeRemove: Function,
        previewWidth: {
            type: String,
            default: "500px"
        }
    },
    emits: ['update:modelValue', 'change'],
    setup(props, {emit}) {
        const store = useStore()
        const service = useService()

        let fileList = ref([])
        let urls = ref([])
        let loading = ref(false)
        let preview = reactive({
            visible: false,
            url: null
        })

        const token = computed(() => store.getters.token)
        const JAction = computed(() => {
            return props.action === "comm" ? baseUrlT + "/comm/upload" : props.action;
        })
        const JShowFileList = computed(() => {
            let f = null;

            switch (props.listType) {
                case "picture-card":
                case "file":
                    f = true;
                    break;
                default:
                    f = false;
                    break;
            }

            return props.showFileList === undefined ? f : props.showFileList;
        })
        const JAccept = computed(() => {
            switch (props.listType) {
                case "picture-card":
                    return "image/*";
                default:
                    return props.accept;
            }
        })
        const jLoading = computed(() => {
            return props.listType === "default" ? props.loading : false;
        })
        const jUrls = computed(() => {
            const format = {
                image: ["bmp", "jpg", "jpeg", "png", "tif", "gif", "svg"]
            };

            return urls.value.map((e) => {
                let arr = e.url.split(".");
                let suf = _.last(arr);
                e.type = format.image.includes(suf) ? "image" : null;
                return e;
            });
        })
        const jStyle = computed(() => {
            let arr = [];

            if (_.isArray(props.size)) {
                arr = props.size;
            } else {
                arr = [props.size, props.size];
            }

            const [height, width] = arr.map((e) => (_.isNumber(e) ? `${e}px` : e));

            if (props.listType === "default" && !props.drag) {
                return {
                    height,
                    width
                };
            } else {
                return {};
            }
        })

        watch(() => props.modelValue, (value) => {
            let list = [];

            if (props.multiple) {
                if (value instanceof Array) {
                    list = value;
                } else {
                    list = (value || "").split(",");
                }
            } else {
                if (value) {
                    list = [value];
                }
            }
            if (list.length !== 0) {
                const arr = list.filter(Boolean).map(url => {
                    return {
                        url,
                        uid: url
                    }
                })

                urls.value = _.clone(arr)
            }
        }, {immediate: true})

        // 更新值
        const update = function () {
            const str = urls.value.map(e => e.url).filter(Boolean).join(",")
            console.log(str, "urls.value")

            emit("update:modelValue", str);
            emit("change", str);
        }

        // 追加文件
        const append = function (data) {
            if (props.multiple) {
                urls.value.push(data);
            } else {
                urls.value = [data];
            }

            update();
        }

        // 删除文件
        const JOnRemove = function (file, fileList) {
            urls.value = urls.value.filter((e) => e.uid != file.uid);
            update();

            // 删除文件之前的钩子
            if (props.onRemove) {
                props.onRemove(file, urls.value);
            }
        }

        // 预览图片
        const JOnPreview = function (file) {
            preview.visible = true;
            preview.url = file.url;
        }

        // 上传前
        const jBeforeUpload = function (file) {
            loading.value = true;

            if (props.beforeUpload) {
                props.beforeUpload(file);
            }
        }

        // 上传成功
        const jOnSuccess = function (res, file) {
            loading.value = false;

            append({
                url: res.data,
                name: file.name,
                uid: file.uid
            });

            // 文件上传成功时的钩子
            if (props.onSuccess) {
                props.onSuccess(res, file.raw, this.urls);
            }
        }

        const httpRequest = function (req) {
            loading.value = true;


            console.log(service, "this.$service")
            service.common
                .ossUpload(req.file, {
                    onUploadProgress: (e) => {
                        if (props.onProgress) {
                            e.percent = parseInt((e.loaded / e.total) * 100);
                            props.onProgress(e, req.file);
                        }
                    }
                })
                .then((url) => {
                    jOnSuccess({data: url}, {raw: req.file});
                })
                .catch((err) => {
                    console.error("upload error", err);
                    ElMessage.error(err)

                    // 	文件上传失败时的钩子
                    if (props.onError) {
                        props.onError(err, req.file);
                    }
                })
                .done(() => {
                    loading.value = false
                });
        }

        return {
            token,
            JAction,
            JShowFileList,
            JAccept,
            jLoading,
            jUrls,
            jStyle,
            update,
            append,
            fileList,
            loading,
            preview,
            JOnRemove,
            JOnPreview,
            jBeforeUpload,
            jOnSuccess,
            httpRequest
        }
    }
})
</script>


<style lang="scss" scoped>
.io-upload {
    display: flex;
    flex-wrap: wrap;

    &__hidden {
        height: 0;
        width: 0;
    }

    &.is-multiple {
        .io-upload__wrap {
            margin-right: 10px;
        }
    }

    &--default {
        &:not(.is-drag) {
            /deep/ .el-upload {
                display: flex;
                align-items: center;
                justify-content: center;
                border: 1px dashed #d9d9d9;
                border-radius: 6px;
                cursor: pointer;
                position: relative;
                overflow: hidden;
                height: 100%;

                &:hover {
                    border-color: #409eff;
                }

                .io-upload__cover {
                    img {
                        display: block;
                        height: 100%;
                        width: 100%;
                    }
                }

                i {
                    font-size: 28px;
                    color: #8c939d;
                }
            }
        }
    }

    &--picture-card {
        /deep/ .el-upload {
            .io-upload__icon {
                position: relative;
                top: 4px;
            }
        }
    }

    &__icon + span {
        margin-left: 5px;
    }

    &__text {
        font-size: 14px;
    }
}
</style>
