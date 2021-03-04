<template>
	<div class="cl-menu-perms">
		<el-cascader
			v-model="value"
			:options="options"
			:props="{ multiple: true }"
			separator=":"
			clearable
			filterable
			@change="onChange"
		></el-cascader>
	</div>
</template>

<script>
export default {
	props: {
		modelValue: [String, Number, Array]
	},

	emits: ["update:modelValue"],

	data() {
		return {
			options: [],
			value: []
		};
	},

	watch: {
		modelValue() {
			this.parse();
		}
	},

	created() {
		let options = [];
		let list = [];

		const flat = obj => {
			for (let i in obj) {
				let { permission } = obj[i];

				if (permission) {
					list = [...list, Object.values(permission)].flat();
				} else {
					flat(obj[i]);
				}
			}
		};

		flat(this.$service);

		list.filter(e => e.includes(":"))
			.map(e => e.split(":"))
			.forEach(arr => {
				const col = (i, d) => {
					let key = arr[i];

					let index = d.findIndex(e => e.label == key);

					if (index >= 0) {
						col(i + 1, d[index].children);
					} else {
						let isLast = i == arr.length - 1;

						d.push({
							label: key,
							value: key,
							children: isLast ? null : []
						});

						if (!isLast) {
							col(i + 1, d[d.length - 1].children || []);
						}
					}
				};

				col(0, options);
			});

		this.options = options;
	},

	mounted() {
		this.parse();
	},

	methods: {
		parse() {
			this.value = this.modelValue ? this.modelValue.split(",").map(e => e.split(":")) : [];
		},

		onChange(row) {
			this.$emit("update:modelValue", row.map(e => e.join(":")).join(","));
		}
	}
};
</script>

<style lang="scss" scoped>
.cl-menu-perms {
	:deep(.el-cascader) {
		width: 100%;
	}
}
</style>
