<template>
	<view class="page">

		<!-- 使用自定义标签 -->
		<!-- <helloComp myval="Hello Next~~"></helloComp>
	   <trailerStars innerScore="5.1" showNum="0"></trailerStars> -->

		<!-- 轮播图 start -->
		<swiper :indicator-dots="true" :autoplay="true" class="carousel">

			<swiper-item v-for="carousel in carouselList">
				<navigator open-type="navigate" :url="'../movie/movie?trailerId=' + carousel.movieId">
					<image :src="carousel.image" class="carousel"></image>
				</navigator>
			</swiper-item>

			<!-- <swiper-item>
				<image src="../../static/carousel/batmanvssuperman.png" class="carousel"></image>
			</swiper-item>
			<swiper-item>
				<image src="../../static/carousel/spiderman.png" class="carousel"></image>
			</swiper-item> -->
		</swiper>
		<!-- 轮播图 end -->

		<!-- 热门超英 start -->
		<view class="page-block super-hot">
			<view class="hot-title-wapper">
				<image src="../../static/icos/hot.png" class="hot-ico"></image>
				<view class="hot-title">
					热门超英
				</view>
			</view>
		</view>

		<scroll-view scroll-x="true" class="page-block hot">

			<view class="single-poster" v-for="superhero in hotSuperheroList">
				<view class="poster-wapper">
					<navigator open-type="navigate" :url="'../movie/movie?trailerId=' + superhero.id">
						<image :src="superhero.cover" class="poster"></image>
					</navigator>
					<view class="movie-name">
						{{superhero.name}}
					</view>
					<trailerStars :innerScore="superhero.score" showNum="1"></trailerStars>
					<!-- <view class="movie-score-wapper">
						<image src="../../static/icos/star-yellow.png" class="star-ico"></image>
						<image src="../../static/icos/star-yellow.png" class="star-ico"></image>
						<image src="../../static/icos/star-yellow.png" class="star-ico"></image>
						<image src="../../static/icos/star-yellow.png" class="star-ico"></image>
						<image src="../../static/icos/star-gray.png" class="star-ico"></image>
						<view class="movie-score">
							9.1
						</view>
					</view> -->
				</view>
			</view>


		</scroll-view>

		<!-- 热门超英 end -->


		<!-- 热门预告 start -->
		<view class="page-block super-hot">
			<view class="hot-title-wapper">
				<image src="../../static/icos/interest.png" class="hot-ico"></image>
				<view class="hot-title">
					热门预告
				</view>
			</view>
		</view>

		<view class="hot-movies page-block">

			<video 
				:id="trailer.id"
				:data-playingindex="trailer.id"
				@play="meIsPlaying"
				v-for="trailer in hotTrailerList" 
				:src="trailer.trailer" 
				:poster="trailer.poster" 
				class="hot-movie-single"
				 controls></video>

		</view>

		<!-- 热门预告 end -->
		
		<!-- 猜你喜欢 start -->
		<view class="page-block super-hot">
			<view class="hot-title-wapper">
				<image src="../../static/icos/guess-u-like.png" class="hot-ico"></image>
				<view class="hot-title">
					猜你喜欢
				</view>
			</view>
		</view>

		<view class="page-block guess-u-like">
			
			<view class="single-like-movie" v-for="(guess,gIndex) in guessULikeList">
				
				<navigator open-type="navigate" :url="'../movie/movie?trailerId=' + guess.id">
					<image :src="guess.cover" class="like-movie"></image>
				</navigator>
				
				<view class="movie-desc">
					<view class="movie-title">
						{{guess.name}}
					</view>
					<trailerStars :innerScore="9.1" showNum="0"></trailerStars>
					<view class="movie-info">
						{{guess.basicInfo}}
					</view>
					<view class="movie-info">
						{{guess.releaseDate}}
					</view>
				</view>
				
				<view class="movie-oper" :data-gIndex="gIndex" @click="praiseMe">
					<image src="../../static/icos/praise.png" class="praise-ico"></image>
					<view class="praise-me">
						点赞
					</view>
					<view :animation="animationDataArr[gIndex]" class="praise-me animation-opacity">
						+1
					</view>
				</view>
			</view>
			
			<!-- <view class="single-like-movie">
				<image src="http://122.152.205.72:88/superhero/DC/GreenLantern/cover.jpg" class="like-movie"></image>
				
				<view class="movie-desc">
					<view class="movie-title">
						蝙蝠侠大战超人蝙蝠侠大战超人蝙蝠侠大战超人
					</view>
					<trailerStars :innerScore="9.1" showNum="0"></trailerStars>
					<view class="movie-info">
						2018 / 美国 / 科幻 动作
					</view>
					<view class="movie-info">
						本·阿弗莱克 / 亨利·卡维尔 / 艾米·亚当斯 / 盖尔·加朵
					</view>
				</view>
				
				<view class="movie-oper" @click="praiseMe">
					<image src="../../static/icos/praise.png" class="praise-ico"></image>
					<view class="praise-me">
						点赞
					</view>
					<view :animation="animationData" class="praise-me animation-opacity">
						+1
					</view>
				</view>
			</view> -->
			
		</view>
		
		<!-- 猜你喜欢 end -->
	</view>
</template>

<script>
	// import common from "../../common/common.js";
	// 导入自定义组件
	import helloComp from "../../components/helloComp.vue";
	import trailerStars from "../../components/trailerStars.vue";

	export default {
		data() {
			return {
				carouselList: [],
				hotSuperheroList: [],
				hotTrailerList: [],
				guessULikeList: [],
				
				animationData: {},
				animationDataArr: [
					{}, {}, {}, {}, {}
				]
			}
		},
		onUnload() {
			// 页面卸载的时候，清除动画数据
			this.animationData = {};
			this.animationDataArr = [
				{}, {}, {}, {}, {}
			];
		},
		onPullDownRefresh() {
			this.refresh();
		},
		onHide() {
			if (this.videoContext) {
				this.videoContext.pause();
			}
		},
		onLoad() {
			var me = this;
			
			// #ifdef APP-PLUS || MP-WEIXIN
			// 在页面创建的时候，创建一个临时动画对象
			this.animation = uni.createAnimation();
			// #endif
			
			// 获取common.js中的服务器地址
			// var serverUrl = common.serverUrl;
			// 通过挂载到main.js中获取服务器的地址，作为全局变量
			var serverUrl = me.serverUrl;

			// 请求轮播图数据
			uni.request({
				url: serverUrl + '/index/carousel/list',
				method: "POST",
				header:{
					'content-type':'application/x-www-form-urlencoded'
				},
				data:{
					qq:'466481615'
				},
				success: (res) => {
					// console.log(res.data);

					// 获取真实数据之前，务必判断状态是否为200
					if (res.data.status == 200) {
						var carouselList = res.data.data;
						me.carouselList = carouselList;
					}

				}
			});

			// 查询热门超英
			uni.request({
				url: serverUrl + '/index/movie/hot?type=superhero',
				method: "POST",
				header:{
					'content-type':'application/x-www-form-urlencoded'
				},
				data:{
					qq:'466481615'
				},
				success: (res) => {
					// console.log(res.data);
					// 获取真实数据之前，务必判断状态是否为200
					if (res.data.status == 200) {
						var hotSuperheroList = res.data.data;
						me.hotSuperheroList = hotSuperheroList;
					}

				}
			});
			// 查询热门预告
			uni.request({
				url: serverUrl + '/index/movie/hot?type=trailer',
				method: "POST",
				header:{
					'content-type':'application/x-www-form-urlencoded'
				},
				data:{
					qq:'466481615'
				},
				success: (res) => {
					// 获取真实数据之前，务必判断状态是否为200
					if (res.data.status == 200) {
						var hotTrailerList = res.data.data;
						me.hotTrailerList = hotTrailerList;
					}

				}
			});
			
			me.refresh();
		},
		methods: {
			// 播放一个视频的时候，需要暂停其他正在播放的视频
			meIsPlaying(e) {
				var me = this;
				var trailerId = "";
				if (e) {
					trailerId = e.currentTarget.dataset.playingindex;
					me.videoContext = uni.createVideoContext(trailerId);
				}
				var hotTrailerList = me.hotTrailerList;
				for (var i = 0; i < hotTrailerList.length ; i ++) {
					var tempId = hotTrailerList[i].id;
					if (tempId != trailerId) {
						uni.createVideoContext(tempId).pause();
					}
				}
			},
			refresh() {
				var me = this;
				
				uni.showLoading({
					mask: true
				});
				uni.showNavigationBarLoading();
				
				
				var serverUrl = me.serverUrl;
				// 查询猜你喜欢数据列表
				uni.request({
					url: serverUrl + '/index/guessULike',
					method: "POST",
					header:{
						'content-type':'application/x-www-form-urlencoded'
					},
					data:{
						qq:'466481615'
					},
					success: (res) => {
						// 获取真实数据之前，务必判断状态是否为200
						if (res.data.status == 200) {
							var guessULikeList = res.data.data;
							me.guessULikeList = guessULikeList;
						}
					},
					complete: () => {
						uni.hideNavigationBarLoading();
						uni.hideLoading();
						uni.stopPullDownRefresh();
					}
				});
			},
			// 实现点赞动画效果
			praiseMe(e) {
				// #ifdef APP-PLUS || MP-WEIXIN
				var gIndex = e.currentTarget.dataset.gindex;
				console.log(gIndex);
				// return;
				// 构建动画数据，并且通过step来表示这组动画的完成
				this.animation.translateY(-60).opacity(1).step({
					duration: 400
				});
				
				// 导出动画数据到view组件，实现组件的动画效果
				// this.animationData = this.animation.export();
				this.animationData = this.animation;
				this.animationDataArr[gIndex] = this.animationData.export();

				// 还原动画
				setTimeout(function() {
					this.animation.translateY(0).opacity(0).step({
						duration: 0
					});
					this.animationData = this.animation;
					this.animationDataArr[gIndex] = this.animationData.export();
				}.bind(this), 500)
				// #endif
			}
		},
		components: {
			helloComp,
			trailerStars
		}
	}
</script>

<style>
	@import url("index.css");
</style>
