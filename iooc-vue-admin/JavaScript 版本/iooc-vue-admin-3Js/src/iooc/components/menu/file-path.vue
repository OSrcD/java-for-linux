<template>
	<div class="cl-menu-file-path">
		<el-select v-model="value" filterable clearable placeholder="请选择">
			<el-option
				v-for="item in list"
				:key="item.value"
				:label="item.value"
				:value="item.value"
			>
			</el-option>
		</el-select>
	</div>
</template>

<script>
const files = require
	.context("@/", true, /^.\/(views|pages).*(vue|js)/)
	.keys()
	.map(e => {
		return {
			value: e.substr(2)
		};
	});

export default {
	name: "cl-menu-file-path",

	props: {
		modelValue: String
	},

	emits: ["update:modelValue"],

	data() {
		return {
			value: "",
			list: files
		};
	},

	watch: {
		modelValue() {
			this.parse();
		},

		value(val) {
			this.$emit("update:modelValue", val);
		}
	},

	mounted() {
		this.parse();
	},

	methods: {
		parse() {
			this.value = this.modelValue || "";
		}
	}
};
</script>

<style lang="scss" scoped>
.cl-menu-file-path {
	width: 100%;

	:deep(.el-select) {
		width: 100%;
	}
}
</style>
