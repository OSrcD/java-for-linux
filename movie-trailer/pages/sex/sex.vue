<template>
	<view class="page page-fill">
		
		<form @submit="formSubmitSex">
			
			<view class="page-block" style="margin-top: 20upx;">
				
				<radio-group class="radio-sex" @change="sexChange">
					<label class="radio-single">
						<radio value="1" :checked="sex == 1"/>男
					</label>
					<label class="radio-single">
						<radio value="0" :checked="sex == 0"/>女
					</label>
				</radio-group>
				
			</view>
			
			<button type="primary" form-type="submit" class="submitBtn">提交</button>
			
		</form>
		
	</view>
</template>

<script>
	export default {
		data() {
			return {
				globalUser: {},
				sex: "-1"
			};
		},
		onLoad() {
			var me = this;
			var globalUser = me.getGlobalUser("globalUser");
			me.globalUser = globalUser;
			me.sex = globalUser.sex;
		},
		methods:{
			sexChange(e) {
				this.sex = e.detail.value;
			},
			formSubmitSex() {
				var me = this;
				var sex = me.sex;
				
				uni.request({
					url: me.serverUrl + "/user/modifyUserinfo",
					data: {
						"userId": me.globalUser.id,
						"sex": sex
					},
					header: {
						"headerUserId": me.globalUser.id,
						"headerUserToken": me.globalUser.userUniqueToken
					},
					method: "POST",
					success(res) {
						var resData = res.data;
						// console.log(typeof(resData));
						if (resData.status == 200) {
							// 获得最新的用户数据
							var userInfo = resData.data;
							uni.setStorageSync("globalUser", userInfo);
							uni.navigateBack({
								delta: 1
							})
						} else if (resData.status == 502 || resData.status == 500) {
							uni.showToast({
								title: res.data.msg,
								image: "../../static/icos/error.png",
								duration: 2000
							})
						}
					}
				})
			
			}
		}
	}
</script>

<style>
/* 页面铺满屏幕 */
.page-fill {
	width:100%;
	height: 100%;
	position: absolute;
}

.radio-sex {
	display: flex;
	flex-direction: column;
}

.radio-single {
	padding: 20upx 20upx;
}

.submitBtn {
	width: 95%;
	margin-top: 40upx;
}
</style>
