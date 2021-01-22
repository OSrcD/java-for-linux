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
			<el-input class="io-upload__hidden" type="hidden"></el-input>

			<el-upload
				:action="_action"
				:accept="_accept"
				:multiple="multiple"
				:limit="limit"
				:data="data"
				:name="name"
				:drag="drag"
				:list-type="listType"
				:file-list="fileList"
				:show-file-list="_showFileList"
				:auto-upload="autoUpload"
				:disabled="disabled"
				:headers="{
					Authorization: token,
					...headers
				}"
				:http-request="action ? undefined : httpRequest"
				:on-remove="_onRemove"
				:on-preview="_onPreview"
				:on-success="_onSuccess"
				:on-error="onError"
				:on-progress="onProgress"
				:on-change="onChange"
				:on-exceed="onExceed"
				:before-upload="_beforeUpload"
				:before-remove="beforeRemove"
				:style="_style"
				v-loading="_loading"
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
							>点击上传</el-button
						>
					</template>

					<template v-else>
						<div class="io-upload__cover" v-if="_urls[0]">
							<img v-if="_urls[0].type == 'image'" :src="_urls[0].url" />

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
			<img width="100%" :src="preview.url" alt="" />
		</io-dialog>
	</div>
</template>

<script>
import { mapGetters } from "vuex";
import { baseUrl, upload } from "@/config/env";
import { clone, isArray, last, isNumber } from "@/iooc/utils";

export default {
	props: {
		modelValue: [Array, String],
		// 上传的地址，当为 comm 时，调用 /comm/upload 接口
		action: {
			type: String,
			default: upload.action || ""
		},
		// 尺寸
		size: {
			type: [Array, String, Number],
			default: upload.size || "128px"
		},
		// 显示图标
		icon: {
			type: String,
			default: upload.icon || "el-icon-upload"
		},
		// 显示文案
		text: {
			type: String,
			default: upload.text || "选择文件"
		},
		// 上传的文件类型
		accept: {
			type: String,
			default: upload.accept || ""
		},
		// 上传的文件字段名
		name: {
			type: String,
			default: upload.name || "file"
		},
		// 文件列表的类型
		listType: {
			type: String,
			default: "default"
		},
		// 是否显示已上传文件列表
		showFileList: {
			type: Boolean,
			default: undefined
		},
		// 是否自带上传
		autoUpload: {
			type: Boolean,
			default: true
		},
		// 是否多选
		multiple: Boolean,
		// 最大允许上传个数
		limit: Number,
		// 上传时附带的额外参数
		data: Object,
		// 是否拖拽
		drag: Boolean,
		// 是否禁用
		disabled: Boolean,
		// 设置上传的请求头部
		headers: Object,
		// 文件列表移除文件时的钩子
		onRemove: Function,
		// 点击文件列表中已上传的文件时的钩子
		onPreview: Function,
		// 文件上传成功时的钩子
		onSuccess: Function,
		// 文件上传失败时的钩子
		onError: Function,
		// 文件上传时的钩子
		onProgress: Function,
		// 文件状态改变时的钩子
		onChange: Function,
		// 文件超出个数限制时的钩子
		onExceed: Function,
		// 上传文件之前的钩子
		beforeUpload: Function,
		// 删除文件之前的钩子
		beforeRemove: Function,
		// 预览图片的宽度
		previewWidth: {
			type: String,
			default: "500px"
		}
	},

	data() {
		return {
			fileList: [],
			urls: [],
			loading: false,
			preview: {
				visible: false,
				url: null
			}
		};
	},

	computed: {
		...mapGetters(["token"]),

		_action() {
			return this.action == "comm" ? baseUrl + "/comm/upload" : this.action;
		},

		_showFileList() {
			let f = null;

			switch (this.listType) {
				case "picture-card":
				case "file":
					f = true;
					break;
				default:
					f = false;
					break;
			}

			return this.showFileList === undefined ? f : this.showFileList;
		},

		_accept() {
			switch (this.listType) {
				case "picture-card":
					return this.accept || "image/*";
				default:
					return this.accept;
			}
		},

		_loading() {
			return this.listType == "default" ? this.loading : false;
		},

		_urls() {
			const format = {
				image: ["bmp", "jpg", "jpeg", "png", "tif", "gif", "svg"]
			};

			return this.urls.map(e => {
				let arr = e.url.split(".");
				let suf = last(arr);
				e.type = format.image.includes(suf) ? "image" : null;
				return e;
			});
		},

		_style() {
			let arr = [];

			if (isArray(this.size)) {
				arr = this.size;
			} else {
				arr = [this.size, this.size];
			}

			const [height, width] = arr.map(e => (isNumber(e) ? `${e}px` : e));

			if (this.listType == "default" && !this.drag) {
				return {
					height,
					width
				};
			} else {
				return {};
			}
		}
	},

	watch: {
		modelValue: {
			immediate: true,
			handler: "parseValue"
		}
	},

	methods: {
		// 解析参数
		parseValue(value) {
			let list = [];

			if (this.multiple) {
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

			// 比较数据，避免重复动画
			if (list.join(",") !== this.urls.map(e => e.url).join(",")) {
				this.fileList = list.filter(Boolean).map(url => {
					return {
						url,
						uid: url
					};
				});

				// 设置 URLS
				this.urls = clone(this.fileList);
			}
		},

		// 更新值
		update() {
			const urls = this.urls
				.map(e => e.url)
				.filter(Boolean)
				.join(",");

			this.$emit("update:modelValue", urls);
			this.$emit("change", urls);
		},

		// 追加文件
		append(data) {
			if (this.multiple) {
				this.urls.push(data);
			} else {
				this.urls = [data];
			}

			this.update();
		},

		// 删除文件
		_onRemove(file) {
			this.urls = this.urls.filter(e => e.uid != file.uid);
			this.update();

			// 删除文件之前的钩子
			if (this.onRemove) {
				this.onRemove(file, this.urls);
			}
		},

		// 预览图片
		_onPreview(file) {
			this.preview.visible = true;
			this.preview.url = file.url;

			if (!file.url) {
				let item = this.urls.find(e => e.uid == file.uid);

				if (item) {
					this.preview.url = item.url;
				}
			}
		},

		// 上传前
		_beforeUpload(file) {
			this.loading = true;

			if (this.beforeUpload) {
				return this.beforeUpload(file, {
					done: () => {
						this.loading = false;
					}
				});
			}

			return true;
		},

		// 上传成功
		_onSuccess(res, file) {
			this.loading = false;

			this.append({
				url: res.data,
				name: file.raw.name,
				uid: file.raw.uid
			});

			// 文件上传成功时的钩子
			if (this.onSuccess) {
				this.onSuccess(res, file.raw, this.urls);
			}
		},

		// 重设上传请求
		httpRequest(req) {
			this.loading = true;

			this.$service.common
				.ossUpload(req.file, {
					onUploadProgress: e => {
						if (this.onProgress) {
							e.percent = parseInt((e.loaded / e.total) * 100);
							this.onProgress(e, req.file);
						}
					}
				})
				.then(url => {
					this._onSuccess({ data: url }, { raw: req.file });
				})
				.catch(err => {
					console.error("upload error", err);
					this.$message.error(err);

					// 	文件上传失败时的钩子
					if (this.onError) {
						this.onError(err, req.file);
					}
				})
				.done(() => {
					this.loading = false;
				});
		}
	}
};
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
			:deep(.el-upload) {
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
		:deep(.el-upload) {
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
