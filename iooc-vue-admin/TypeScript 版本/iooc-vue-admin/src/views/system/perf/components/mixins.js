export default {
	methods: {
		unit_size(v) {
			if (v === 0) return "0 B";
			let k = 1024;
			let sizes = ["B", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB"];
			let i = Math.floor(Math.log(v) / Math.log(k));

			return (v / Math.pow(k, i)).toPrecision(3) + " " + sizes[i];
		},
		fixed2(v) {
			return v ? parseFloat(parseFloat(v).toFixed(2)) : 0;
		},
		status_color(v) {
			if (v < 50) {
				return "#67C23A";
			}

			if (v < 70) {
				return "#E6A23C";
			}

			if (v < 100) {
				return "#F56C6C";
			}
		}
	}
};
