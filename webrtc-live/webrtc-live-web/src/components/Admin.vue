<template>
  <div>
    <header>
      <!--Top-->
      <nav id="top">
        <div class="container">
          <div class="row">
            <div class="col-md-6 col-sm-6">
              <strong>欢迎来到天天吃货直播间</strong>
            </div>
            <div class="col-md-6 col-sm-6">
              <ul class="list-inline top-link link">
                <li><a href="#"><i class="fa fa-home"></i> 首页</a></li>
                <li><a href="#"><i class="fa fa-comments"></i> 联系</a></li>
                <li><a href="#"><i class="fa fa-question-circle"></i> 帮助</a></li>
              </ul>
            </div>
          </div>
        </div>
      </nav>

      <!--Navigation-->
      <nav id="menu" class="navbar">
        <div class="container">
          <div class="navbar-header"><span id="heading" class="visible-xs">菜单栏</span>
            <button type="button" class="btn btn-navbar navbar-toggle" data-toggle="collapse" data-target=".navbar-ex1-collapse"><i class="fa fa-bars"></i></button>
          </div>
          <div class="collapse navbar-collapse navbar-ex1-collapse">
            <ul class="nav navbar-nav">
              <li><a href="http://120.77.47.215:8080/foodie-shop"><i class="fa fa-home"></i> 首页</a></li>
              <li class="dropdown"><a href="#" class="dropdown-toggle" data-toggle="dropdown"><i class="fa fa-user"></i> 账号</a>
                <div class="dropdown-menu">
                  <div class="dropdown-inner">
                    <ul class="list-unstyled">
                      <li><a href="#">登录</a></li>
                      <li><a href="#">注册</a></li>
                    </ul>
                  </div>
                </div>
              </li>
              <li><a href="#"><i class="fa fa-envelope"></i> 联系</a></li>
            </ul>
          </div>
        </div>
      </nav>

      <div class="header-slide">
        <div id="owl-demo" class="owl-carousel">
        </div>
      </div>
    </header>
    <!-- Header -->

    <!-- /////////////////////////////////////////Content -->
    <div id="page-content" class="single-page">
      <div class="container">
        <div class="row">
          <div id="main-content" class="col-md-8">
            <div class="wrap-vid">
              <video ref="video" controls="controls"  autoplay width="100%" height="100%"></video>
            </div>
            <div class="share">
              <ul class="list-inline center">
                <li><a href="#" id="startLive" @click="startLive()" class="btn btn-twitter my-sub-top"><i class="fa "></i> 开始直播</a></li>
                <li><a href="#" id="stop" class="btn btn-twitter my-sub-top"><i class="fa "></i> 停止直播</a></li>
                <li><a href="#" id="test" @click="testMessage()" class="btn btn-twitter my-sub-top"><i class="fa "></i> 测试消息</a></li>
                <li><a href="#" class="btn btn-google my-sub-top"><i class="fa "></i> 哔哩哔哩</a></li>
                <li><a href="#" class="btn btn-twitter my-sub-top"><i class="fa "></i> 抖音</a></li>
                <li><a href="#" class="btn btn-pinterest my-sub-top"><i class="fa "></i> 快手</a></li>
                <li><a href="#" class="btn btn-facebook my-sub-top"><i class="fa "></i> 分享</a></li>
              </ul>
            </div>



            <!--					<div class="line"></div>-->

          </div>
          <div id="sidebar" class="col-md-4">
            <!---- Start Widget ---->
            <div class="widget wid-follow">
              <div class="heading my-top"><h4><i class="fa fa-users"></i> 关注</h4></div>
              <div class="content">
                <ul class="list-inline">
                  <li>
                    <a href="#/">
                      <div class="box-facebook my-top">
                        <span class="fa fa-facebook fa-2x icon"></span>
                        <span>0</span>
                        <span>粉丝</span>
                      </div>
                    </a>
                  </li>
                  <li>
                    <a href="#/">
                      <div class="box-twitter my-top">
                        <span class="fa fa-twitter fa-2x icon"></span>
                        <span>0</span>
                        <span>粉丝</span>
                      </div>
                    </a>
                  </li>
                  <li>
                    <a href="#/">
                      <div class="box-google my-top">
                        <span class="fa fa-google-plus fa-2x icon"></span>
                        <span>0</span>
                        <span>粉丝</span>
                      </div>
                    </a>
                  </li>
                </ul>
              </div>
              <!--						<div class="line"></div>-->
            </div>
            <!--					&lt;!&ndash;&#45;&#45; Start Widget &#45;&#45;&ndash;&gt;-->
            <!--					<div class="widget wid-post">-->

            <!--					</div>-->
            <!--					&lt;!&ndash;&#45;&#45; Start Widget &#45;&#45;&ndash;&gt;-->
            <!--					<div class="widget wid-news">-->

            <!--					</div>-->
          </div>
        </div>
      </div>
    </div>

    <footer  class="my-top" >
      <div class="bottom-footer">
        <div class="container">
          <div class="row">
            <div class="col-md-7 col-sm-7 copyright ">
              <span>请使用Chrome、Firefox、Edge浏览器，才能支持WebRTC直播</span>
            </div>
            <div class="col-md-5 col-sm-5 link">
              <div class="menu-footer-menu-container">
                <ul id="menu-footer-menu" class="menu list-inline">
                  <li><a href="#"><i class="fa fa-home"></i> 首页</a></li>
                  <li><a href="#"><i class="fa fa-comments"></i> 联系</a></li>
                  <li><a href="#"><i class="fa fa-question-circle"></i> 帮助</a></li>
                </ul>
              </div>
            </div>
          </div>
        </div>
      </div>
    </footer>
  </div>
</template>

<script>

import WebRtcPeer from 'kurento-utils/lib/WebRtcPeer'

export default {
  name: "Admin.vue",
  data(){
    return {
      webRtcPeer: null,
      video: null,
      socket: null,
      stompClient: null
    }
  },
  methods:{
    startLive(){
      let _this = this;
      _this.video = _this.$refs.video;
      if (!_this.webRtcPeer) {
        var options = {
          localVideo: _this.video,
          onicecandidate: _this.onIceCandidate,
        };
        // 1
        _this.webRtcPeer = new WebRtcPeer.WebRtcPeerSendonly(options,function(error){
          if(error){
            _this.webRtcPeer = null
            alert('实例化主播端webRtcPeer对象失败： ' + error + ' 请重新刷新页面连接');
          }
          alert("webRtcPeer = " + _this.webRtcPeer);
          _this.webRtcPeer.generateOffer(_this.onAnchorOfferSdp);
        });

      }else{
        alert("已经在直播，请先点击停止直播，再点击开始直播")
      }
    },
    // 3
    onIceCandidate(candidate){
      let _this = this;
      var myCandidate = JSON.stringify(candidate);
      alert("candidate = " + myCandidate)
      _this.stompClient.send("/webrtc/onIceCandidate", {}, myCandidate);

    },

    // 2
    onAnchorOfferSdp(error, offerSdp) {
      let _this = this;
      if(error) {
        alert('监听生成OfferSdp失败');
      }
      alert('监听生成OfferSdp' + location.host);
      alert('offerSdp : ' + offerSdp);
      var sdpOffer = {
        'sdpOffer': offerSdp
      };

      var s = JSON.stringify(sdpOffer);
      alert("mySdpOffer+"+ s);
      alert("mySdpOffer=" + sdpOffer.sdpOffer);
      _this.stompClient.send("/webrtc/Anchor", {}, s);
    },
    testMessage(){
      let _this = this;
      _this.stompClient.send("/webrtc/test", {}, "发送测试消息");
    },
    serverIceCandidate(candidate){
      let _this = this;
      alert("开始添加addIceCandidate = " + candidate);
      _this.webRtcPeer.addIceCandidate(candidate,function(error){
        if(error)
          return alert("addIceCandidate失败 = " + error);
      })
    },
    AnchorResponse(sdpAnswer){
      let _this = this;
      alert("开始处理processAnswer = " + sdpAnswer);
      _this.webRtcPeer.processAnswer(sdpAnswer,function(error){
        if (error) {
          return alert("AnchorResponse失败 = " + error);
        }
      })
    }

  },
  created: function () {
    let _this = this;

     _this.socket = new SockJS("https://192.168.43.15:8080/live");
    _this.stompClient = Stomp.over(_this.socket);
    _this.stompClient.connect({},function (frame){
      _this.stompClient.subscribe('/topic/test', function (message) {
        alert(message.body);
      });

      _this.stompClient.subscribe('/user/topic/serverIceCandidate',function(message){
        alert('serverIceCandidate = ' + message.body)
        _this.serverIceCandidate(message.body);
      });

      _this.stompClient.subscribe('/user/topic/AnchorResponse', function (message) {
        alert('AnchorResponse = ' + message.body);
        _this.AnchorResponse(message.body);
      });

    })
  },
  mounted:function (){
    let _this = this;
  }
}



</script>

<style scoped>

</style>
