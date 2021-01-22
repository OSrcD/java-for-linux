<template>
	<div class="ct">
		<el-row :gutter="20">
			<el-col :lg="6" :md="12" :xs="24">
				<div class="block">
					<p class="label">负载状态</p>

					<el-popover width="100" trigger="hover">
						<div class="system-perf-progress-popover">
							<ul>
								<li>CPU：{{ fixed2(cpu.perc) }} %</li>
								<li>内存：{{ fixed2(mem.perc) }} %</li>
							</ul>
						</div>

						<template #reference>
							<el-progress
								type="circle"
								:percentage="fixed2(lb.perc)"
								:color="status_color(lb.perc)"
							></el-progress>
						</template>
					</el-popover>
				</div>
			</el-col>

			<el-col :lg="6" :md="12" :xs="24">
				<div class="block">
					<p class="label">CPU存使用率</p>

					<el-progress
						type="circle"
						:percentage="fixed2(cpu.perc)"
						:color="status_color(cpu.perc)"
					></el-progress>
				</div>
			</el-col>

			<el-col :lg="6" :md="12" :xs="24">
				<div class="block">
					<p class="label">内存使用率</p>

					<el-popover width="100" trigger="hover">
						<div class="system-perf-progress-popover">
							<ul>
								<li>总数：{{ unit_size(mem.total) }}</li>
								<li>已使用：{{ unit_size(mem.used) }}</li>
							</ul>
						</div>

						<template #reference>
							<el-progress
								type="circle"
								:percentage="fixed2(mem.perc)"
								:color="status_color(mem.perc)"
							></el-progress>
						</template>
					</el-popover>
				</div>
			</el-col>

			<el-col :lg="6" :md="12" :xs="24" v-for="(item, index) in disk.list" :key="index">
				<div class="block">
					<p class="label">{{ item.mount }}</p>

					<el-popover width="100" trigger="hover">
						<div class="system-perf-progress-popover">
							<ul>
								<li>总数：{{ unit_size(item.size) }}</li>
								<li>已使用：{{ unit_size(item.used) }}</li>
							</ul>
						</div>

						<template #reference>
							<el-progress
								type="circle"
								:percentage="fixed2(item.use)"
								:color="status_color(item.use)"
							></el-progress>
						</template>
					</el-popover>
				</div>
			</el-col>
		</el-row>
	</div>
</template>

<script>
import CommonMixin from "./mixins";

export default {
	mixins: [CommonMixin],

	data() {
		return {
			lb: {
				perc: 0
			},
			redis: {
				options: {},
				perc: 0
			},
			mysql: {
				options: {},
				number: 0,
				perc: 0
			},
			cpu: {
				options: {},
				perc: 0
			},
			mem: {
				perc: 0,
				total: 0,
				used: 0
			},
			disk: {
				list: [],
				all: 0
			}
		};
	},

	methods: {
		refresh(res) {
			const { data } = res;
			const item = data[data.length - 1];

			this.toMysql(res, item.mysql);
			this.toRedis(res, item.redis);
			this.toCPU(res, item.server.cpu);
			this.toDisk(item.server.disk.filter(e => e.size));
			this.toMem(item.server.mem);
			this.toLB();
		},

		toLB() {
			let mem = this.mem.perc;
			let cpu = this.cpu.perc;

			if (mem >= 90) {
				this.lb.perc = mem;
			} else if (cpu >= 80) {
				this.lb.perc = cpu;
			} else {
				this.lb.perc = mem * 0.4 + cpu * 0.6;
			}
		},

		toCPU(t, cpu) {
			this.cpu.perc = cpu.currentload;
		},

		toMem(mem) {
			this.mem.perc = (mem.buffcache / mem.total) * 100;
			this.mem.total = mem.total;
			this.mem.used = mem.buffcache;
		},

		toDisk(disk) {
			this.disk.all = disk.reduce((a, b) => a + b.size, 0);

			this.disk.list = disk.map(e => {
				e.use = e.use.toFixed(2);

				return e;
			});
		},

		toRedis(t, item) {
			this.redis.perc = parseFloat(item.Memory.used_memory_dataset_perc);
		},

		toMysql(t, item) {
			let free = 0;
			let used = 0;

			item.mysqlSize.forEach(e => {
				free += parseFloat(e.data_free);
				used += parseFloat(e.data_size);
			});

			this.mysql.number = item.mysqlSize.length;
			this.mysql.perc = (used / (free + used)).toFixed(2);
		}
	}
};
</script>

<style lang="scss">
.system-perf-progress-popover {
	ul {
		li {
			list-style: none;
			line-height: 30px;
		}
	}
}
</style>

<style lang="scss" scoped>
.ct {
	background-color: #fff;

	.block {
		display: flex;
		justify-content: center;
		align-items: center;
		flex-direction: column;
		background-color: #fff;
		width: 100%;
		border-radius: 3px;
		padding: 20px;
		box-sizing: border-box;
		position: relative;
		height: 220px;
		cursor: pointer;

		.label {
			font-size: 16px;
			height: 40px;
		}

		.perc {
			position: absolute;
			padding: 5px 10px;
			background-color: #fff;
		}

		.c {
			height: 50px;

			.echarts {
				height: 100%;
				width: 100%;
			}
		}
	}
}
</style>
