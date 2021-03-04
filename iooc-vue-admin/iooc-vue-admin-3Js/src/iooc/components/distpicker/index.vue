<template>
	<div class="cl-distpicker">
		<el-cascader
			v-model="value"
			:options="data"
			:filterable="filterable"
			:size="size"
			clearable
			:props="{
				label: 'name',
				value: 'code',
				multiple,
				...props
			}"
			@change="onChange"
		>
		</el-cascader>
	</div>
</template>

<script>
import DataList from "./data.json";

export default {
	props: {
		modelValue: [String, Array],
		options: Object,
		filterable: Boolean,
		multiple: Boolean,
		size: String,
		props: Object
	},

	emits: ["update:modelValue"],

	data() {
		return {
			value: undefined,
			data: DataList
		};
	},

	watch: {
		modelValue: {
			immediate: true,
			handler(val) {
				this.value = val;
			}
		}
	},

	methods: {
		onChange(arr) {
			this.$emit("update:modelValue", arr);
			this.$emit("change", arr);
		}
	}
};
</script>

<style lang="scss" scoped>
.cl-distpicker {
	:deep(.el-cascader) {
		width: 100%;
	}
}
</style>
