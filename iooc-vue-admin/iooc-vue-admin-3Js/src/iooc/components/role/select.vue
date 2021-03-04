<template>
	<el-select v-model="value" v-bind="props" multiple @change="onChange" v-if="visible">
		<el-option
			v-for="(item, index) in list"
			:value="item.id"
			:label="item.name"
			:key="index"
		></el-option>
	</el-select>
</template>

<script>
export default {
	props: {
		modelValue: [String, Number, Array],
		props: Object
	},

	emits: ["update:modelValue"],

	data() {
		return {
			list: [],
			value: [],
			visible: true
		};
	},

	watch: {
		modelValue: {
			immediate: true,
			handler(val) {
				if (!(val instanceof Array)) {
					this.value = [val];
				} else {
					this.value = val || [];
				}
			}
		}
	},

	created() {
		this.visible = false;

		this.$service.system.role
			.list()
			.then(res => {
				this.list = res;
			})
			.done(() => {
				this.visible = true;
			});
	},

	methods: {
		onChange(val) {
			this.$emit("update:modelValue", val);
		}
	}
};
</script>
