<template name="helloComp">		<!-- 定义组件的名称为helloComp -->
	<view>
		{{msg}}
		<view>
			<input type="text" :value="myval" class="txt"/>
		</view>
	</view>
</template>

<script>
	export default {
		
		// 定义组件的名称为helloComp
		name: "helloComp",
		
		data() {
			return {
				msg: "你好，这是自定义组件~~~"
			};
		},
		
		// 定义组件内部使用的属性
		props: {
			// 自定义一个变量，用于接受父组件（首页或者其他页面）传入的参数值
			myval: {
				type: String	// 定义这个参数的类型
			}
		}
		
	}
</script>

<style>
	.txt {
		color: green;  
	}
</style>
