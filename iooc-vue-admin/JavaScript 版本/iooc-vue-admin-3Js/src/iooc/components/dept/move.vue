<template>
	<div class="cl-dept-move">
		<io-form ref="form">
			<template #slot-move="{scope}">
				<div
					:style="{
						border: '1px solid #eee',
						'border-radius': '3px',
						padding: '2px'
					}"
				>
					<el-tree
						:data="list"
						:props="{
							label: 'name'
						}"
						node-key="id"
						highlight-current
						@node-click="
							e => {
								scope['dept'] = e;
							}
						"
					></el-tree>
				</div>
			</template>
		</io-form>
	</div>
</template>

<script>
import { deepTree } from "../../utils";

export default {
	data() {
		return {
			list: []
		};
	},

	methods: {
		async getDeptList() {
			return await this.$service.system.dept.list().then(deepTree);
		},

		async toMove(ids) {
			this.list = await this.getDeptList();

			this.$refs["form"].open({
				props: {
					title: "部门转移",
					width: "600px",
				},
				items: [
					{
						label: "选择部门",
						prop: "dept",
						component: {
							name: "slot-move"
						}
					}
				],
				on: {
					submit: (data, { done, close }) => {
						if (!data.dept) {
							this.$message.warning("请选择部门");
							return done();
						}

						const { name, id } = data.dept;

						this.$confirm(`是否将用户转移到部门 ${name} 下`, "提示", {
							type: "warning"
						})
							.then(() => {
								this.$service.system.user
									.move({
										departmentId: id,
										userIds: ids
									})
									.then(res => {
										this.$message.success("转移成功");
										this.$emit("success", res);
										close();
									})
									.catch(err => {
										this.$message.error(err);
										this.$emit("error", err);
										done();
									});
							})
							.catch(() => {});
					}
				}
			});
		}
	}
};
</script>
