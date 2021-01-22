<template>
	<div class="cl-menu-icons">
		<el-popover
			ref="iconPopover"
			placement="bottom-start"
			trigger="click"
			popper-class="popper-menu-icon"
		>
			<el-row :gutter="10" class="list">
				<el-col :span="3" :xs="4" v-for="(item, index) in list" :key="index">
					<el-button
						size="mini"
						:class="{ 'is-active': item === modelValue }"
						@click="onSelect(item)"
					>
						<icon-svg :name="item"></icon-svg>
					</el-button>
				</el-col>
			</el-row>

			<template #reference>
				<el-input v-model="value" placeholder="请选择"></el-input>
			</template>
		</el-popover>
	</div>
</template>

<script>
import { iconList } from "@/icons";

export default {
	name: "cl-menu-icons",

	props: {
		modelValue: String
	},

	emits: ["update:modelValue"],

	data() {
		return {
			list: [],
			value: ""
		};
	},

	watch: {
		modelValue: {
			immediate: true,
			handler(val) {
				this.value = val || "";
			}
		}
	},

	mounted() {
		this.list = iconList();
	},

	methods: {
		onSelect(icon) {
			this.$emit("update:modelValue", icon);
		}
	}
};
</script>

<style lang="scss">
.popper-menu-icon {
	width: 480px !important;
	max-width: 90%;
	box-sizing: border-box;

	.list {
		height: 250px;
		overflow-y: auto;
		display: flex;
		flex-wrap: wrap;
	}

	.el-button {
		margin-bottom: 10px;
		height: 40px;
		width: 100%;
		padding: 0;

		.icon-svg {
			font-size: 18px;
			color: #444;
		}
	}
}
</style>
