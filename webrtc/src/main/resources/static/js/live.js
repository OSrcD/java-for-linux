var ws = new WebSocket('wss://' + location.host + '/call');  // 升级为WebSocket通信
var video; // 视频组件对象
var webRtcPeer; // 点对点通信对象


/**
 * 设置ICE
 * @type {{iceServers: [{urls: string}, {urls: [string], credential: string, username: string}]}}
 */
var iceServers={
    "iceServers":[
        {
            urls:"stun:127.0.0.1:3478"
        },
        {
            urls:[
                "turn:127.0.0.1:3478"
            ],
            username:"kurento",
            credential:"kurento"
        }
    ]
}

/**
 * 设置事件
 */
window.onload = function() {
    video = document.getElementById('video');

    $('#startLive').attr('onclick', 'startLive()');
    $('#checkLive').attr('onclick', 'checkLive()');
    $('#stop').attr('onclick', 'stop()');

}

// 窗口关闭之前，断开WebSocket会话连接
window.onbeforeunload = function() {
    stop();
    ws.close(); // 关闭与信令服务器的会话
}

/**
 * 开始实例化WebRtcPeer对象，设置候选收集监听回调函数，生成SDP提供，指定生成SDP回调函数
 */
function startLive() {

    if(!webRtcPeer){

        var options = {
            localVideo : video,
            onicecandidate : onIceCandidate,
            configuration: iceServers
        };

        webRtcPeer = new kurentoUtils.WebRtcPeer.WebRtcPeerSendonly(options, function (error) {

            if (error) {
                webRtcPeer = null;
                return alert('实例化主播端webRtcPeer对象失败： ' + error + ' 请重新刷新页面连接');
            }

            // 生成主播端的SDP提供
            webRtcPeer.generateOffer(onAnchorOfferSdp);



        });
    }else{
        alert("已经在直播，请先点击停止直播，再点击开始直播")
    }





}



/**
 * 异步监听
 * 回调函数,得到主播端的SDPOffer并发送给后端
 */
function onAnchorOfferSdp(error, offerSdp) {
    if (error) {
        return console.log('监听生成OfferSdp失败');
    }
    console.log('监听生成OfferSdp' + location.host);
    var message = {
        id : 'presenter', // presenter sendAnchorOfferSdp
        sdpOffer: offerSdp
    };

    // 发送主播端的OfferSdp
    sendMessage(message);

}

/**
 * 处理服务端发送过来的sdpAnswer处理给主播端
 * @param message
 */
function anchorProcessAnswer(message) {
    if(message.response != 'accepted'){
        var errorMsg = message.message ? message.message : '未知错误';
        console.log('信令服务器发送过来的不是accepted的请求：'+errorMsg);
        dispose(); // 断开连接
    }else{
        webRtcPeer.processAnswer(message.sdpAnswer, function (error) {
            if(error)
                return console.log("处理服务端发送过来的sdpAnswer处理给主播端错误： "+error);
        });
    }
}


/**
 * 异步监听
 * 公共回调函数
 * 收集候选通信数据，并发送给后端
 * @param candidate
 */
function onIceCandidate(candidate) {

    var message = {
        id : 'onIceCandidate',
        candidate : candidate
    };

    // 发送主播端或观众端的候选数据到服务端
    sendMessage(message);

}

/**
 * 公共处理服务端发送过来的候选人数据
 * @param message
 */
function serverSendIceCandidate(message) {
    webRtcPeer.addIceCandidate(message.candidate, function (error) {
        if(error)
            return console.log('添加服务端的候选人失败: ' + error);
    });


}


/**
 * 发送WebSocket请求到服务端
 */
function sendMessage(message) {
    // js对象序列化到字符串
    var jsonMessage = JSON.stringify(message);
    console.log("发送WebSocket请求到服务端:" + jsonMessage);

    //调用ws对象send接口
    ws.send(jsonMessage);

}


/**
 * 观众端查看直播
 */
function checkLive() {

    if(!webRtcPeer){
        var options = {
            remoteVideo : video,
            onicecandidate: onIceCandidate, //与主播共用同一个回调函数
            configuration: iceServers
        };

        webRtcPeer = new kurentoUtils.WebRtcPeer.WebRtcPeerRecvonly(options, function (error) {
            if (error) {
                webRtcPeer = null;
                return console.log('实例化观众端webRtcPeer失败 ' + error);
            }
            // 生成观众端的SDP提供，需要指定回调函数
            this.generateOffer(onAudienceOfferSdp);
        });
    }else{
        alert("已经在观看直播，请先点击停止观看，再点击查看直播")
    }



}

/**
 * 异步监听生成观众端的OfferSdp
 * @param error
 * @param offerSdp
 */
function onAudienceOfferSdp(error, offerSdp) {
    if (error) {
        return console.log('监听生成OfferSdp失败');
    }
    console.log('监听生成OfferSdp ' + location.host);
    var message = {
        id : 'viewer', // viewer sendAudienceOfferSdp
        sdpOffer: offerSdp
    };

    sendMessage(message);

}


/**
 * 处理服务端提供的sdp用于观众端
 * @param message
 */
function audienceProcessAnswer(message) {

    if (message.message == '当前没有主播在直播') {
        alert(message.message);
    }

    if(message.response != 'accepted'){
        var errorMsg = message.message ? message.message : '未知错误';
        console.log('信令服务器发送过来的不是accepted的请求：' + errorMsg);
        dispose();
    }else{
        webRtcPeer.processAnswer(message.sdpAnswer, function (error) {
            if(error)
                return console.log("处理服务端提供的sdp用于观众端错误： "+error);
        });
    }
}


// 监听WebSocket消息

ws.onmessage = function (message) {

    // 字符串序列化到JSON对象
    var parsedMessage = JSON.parse(message.data);

    console.log('接收到消息：' + message.data);

    switch (parsedMessage.id) {
        case 'presenterResponse': // presenterResponse anchorProcessAnswer
            anchorProcessAnswer(parsedMessage); // 处理服务端发送过来的sdpAnswer处理给主播端
            break;
        case 'viewerResponse': // viewerResponse audienceProcessAnswer
            audienceProcessAnswer(parsedMessage); // 处理服务端提供的sdp用于观众端
            break;
        case 'iceCandidate': // iceCandidate serverSendIceCandidate
            serverSendIceCandidate(parsedMessage) // 公共处理服务端发送过来的候选人数据
            break;
        case 'stopCommunication': // 主播端停止直播
            dispose(); // 调用dispose断开前端与服务器连接
            break;
        default:
            console.log('无法处理消息： ', parsedMessage);
    }

};

/**
 * 断开与kms流媒体服务器通信
 * 销毁webRtcPeer对象
 */
function dispose() {
    if (webRtcPeer){
        webRtcPeer.dispose();
        webRtcPeer = null;
    }
}

/**
 * 发送前端暂停观看或停止直播到信令服务器进行处理
 * 调用dispose断开前端与服务器连接
 */
function stop() {
    var message = {
        id : 'stop'
    }
    sendMessage(message);
    dispose();
}


