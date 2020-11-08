package com.opendev.controller;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.JsonObject;
import com.opendev.session.UserSession;
import org.kurento.client.*;
import org.kurento.jsonrpc.JsonUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.socket.CloseStatus;
import org.springframework.web.socket.TextMessage;
import org.springframework.web.socket.WebSocketSession;
import org.springframework.web.socket.handler.TextWebSocketHandler;

import java.io.IOException;
import java.util.concurrent.ConcurrentHashMap;

public class LiveController extends TextWebSocketHandler {


    // 序列化工具
    private static final Gson gson = new GsonBuilder().create();

    // 线程安全的hashMap
    private final ConcurrentHashMap<String, UserSession> viewers = new ConcurrentHashMap<>();

    // 注入与kms通信客户端
    @Autowired
    private KurentoClient kurento;

    // 媒体管线用于连接两个媒体元素之间的流
    private MediaPipeline pipeline;

    // 主播端session会话
    private UserSession presenterUserSession;

    /**
     * 处理客户端的数据包
     * @param session
     * @param message
     * @throws Exception
     */
    @Override
    protected void handleTextMessage(WebSocketSession session, TextMessage message) throws Exception {

        // 序列化消息到json对象
        JsonObject jsonMessage = gson.fromJson(message.getPayload(),JsonObject.class);

        switch (jsonMessage.get("id").getAsString()) {
            case "presenter":
                try {
                    // 处理主播端发来的SdpOffer
                    presenter(session, jsonMessage);
                }catch(Throwable t){
                    // 处理主播端发来的SdpOffer出现的异常处理
                    handleErrorResponse(t, session, "presenterResponse");
                }
                break;
            case "viewer":
                try {
                    // 处理观众端发来的SdpOffer
                    viewer(session, jsonMessage);
                }catch(Throwable t){
                    // 处理观众端发来的SdpOffer出现的异常处理
                    handleErrorResponse(t,session,"viewerResponse");
                }
                break;
            case "onIceCandidate":

                // 处理客户端发来的候选人信息
                onIceCandidate(session,jsonMessage);

                break;
            case "stop":

                // 停止直播相关的会话
                stop(session);
                break;
            default:
                break;
        }

    }



    /**
     * 客户端关闭连接，释放媒体管道
     * @param session
     * @param status
     * @throws Exception
     */
    @Override
    public void afterConnectionClosed(WebSocketSession session, CloseStatus status) throws Exception {
        // 关闭客户端会话
        stop(session);
    }

    /**
     * 处理主播端发来的SdpOffer
     * @param session
     * @param jsonMessage
     */
    private synchronized void presenter(final WebSocketSession session, JsonObject jsonMessage) throws IOException {

        // 如果当前没有主播在直播
        if (presenterUserSession == null) {

            // 实例化一个用户会话对象
            presenterUserSession = new UserSession(session);

            // 创建一个流媒体管道
            pipeline = kurento.createMediaPipeline();

            // 通过流媒体管道实例化一个流媒体端点元素
            WebRtcEndpoint presenterWebRtc = new WebRtcEndpoint.Builder(pipeline).build();

            // 在主播端会话设置流媒体端点元素成员属性
            presenterUserSession.setWebRtcEndpoint(presenterWebRtc);


            /**
             * 注册IceCandidate监听器 用于监听生成的候选人信息 并发送给主播客户端
             * 实现基于IceCandidate监听器事件监听器
             */
            presenterWebRtc.addIceCandidateFoundListener(new EventListener<IceCandidateFoundEvent>() {

                /**
                 * IceCandidate事件处理器
                 *
                 * @param event IceCandidateFoundEvent事件对象
                 */
                @Override
                public void onEvent(IceCandidateFoundEvent event) {

                    JsonObject response = new JsonObject();
                    response.addProperty("id", "iceCandidate");

                    // 从事件对象拿到事件的IceCandidate信息
                    response.add("candidate", JsonUtils.toJsonObject(event.getCandidate()));

                    // 拿到候选信息之后发送给主播端的客户端
                    try {
                        synchronized (session) {
                            session.sendMessage(new TextMessage(response.toString()));
                        }
                    } catch (IOException e) {
                        e.printStackTrace();
                    }

                }
            });

            // 开始处理客户端传过来的SdpOffer
            String sdpOffer = jsonMessage.getAsJsonPrimitive("sdpOffer").getAsString();

            // 处理SdpOffer并从KMS服务端返回Sdp应答信息
            String sdpAnswer = presenterWebRtc.processOffer(sdpOffer);

            // 发送sdpAnswer应答信息到主播端的客户端处理
            JsonObject response = new JsonObject();
            response.addProperty("id", "presenterResponse");
            response.addProperty("response", "accepted");
            response.addProperty("sdpAnswer", sdpAnswer);


            // 同步线程发送sdpAnswer应答
            synchronized (session) {

              presenterUserSession.sendMessage(response);

            }

            // 开始收集KMS的presenterWebRtc候选信息
            presenterWebRtc.gatherCandidates();

        } else {
            // 提示客户端另外一个主播用户正在直播
            JsonObject response = new JsonObject();
            response.addProperty("id","presenterResponse");
            response.addProperty("response","rejected");
            response.addProperty("message","另外一个主播用户正在直播，请稍后重试 ...");
            session.sendMessage(new TextMessage(response.toString()));
        }

    }

    // 处理客户端发来的候选人信息
    public void onIceCandidate(WebSocketSession session,JsonObject jsonMessage) {

        // 拿到客户端发来候选信息
        JsonObject candidate = jsonMessage.get("candidate").getAsJsonObject();

        // 声明一个UserSession对象
        UserSession user = null;

        // 如果主播端会话存在
        if (presenterUserSession != null) {
            // 判断当前的session是不是主播端session
            if (presenterUserSession.getSession() == session) {

                // 设置当前要处理的会话对象是主播端session
                user = presenterUserSession;

            } else {
                // 不是主播端就是观众端会话了
                user = viewers.get(session.getId());
            }
        }

        if (user != null) {

            /**
             * 为这个会话在kms添加候选信息以便进行流媒体传输通信
             * 封装候选信息到一个对象
             */

            IceCandidate cand = new IceCandidate(
                    candidate.get("candidate").getAsString(),
                    candidate.get("sdpMid").getAsString(),
                    candidate.get("sdpMLineIndex").getAsInt());
            // 开始会user添加候选人信息
            user.addCandidate(cand);
        }


    }

    /**
     * 处理观众端发来的SdpOffer
     * @param session
     * @param jsonMessage
     */
    public synchronized void viewer(final WebSocketSession session,JsonObject jsonMessage) throws IOException {

        /**
         * 判断是否有主播在直播
         */
        if (presenterUserSession == null || presenterUserSession.getWebRtcEndpoint() == null) {
            JsonObject response = new JsonObject();
            response.addProperty("id","viewerResponse");
            response.addProperty("response","rejected");
            response.addProperty("message", "当前没有直播在直播");
            session.sendMessage(new TextMessage(response.toString()));
        }else{

            /**
             * 如果当前内存中已经存在观看的用户
             */
            if (viewers.containsKey(session.getId())) {
                JsonObject response = new JsonObject();
                response.addProperty("id", "viewerResponse");
                response.addProperty("response", "rejected");
                response.addProperty("message", "你现在已经在观看直播了，如果要重新启动，请先停止观看，再点击观看直播");
                session.sendMessage(new TextMessage(response.toString()));
                return;
            }


        // 实例化一个新的观众对象
        UserSession viewer = new UserSession(session);

        // 把当前的会话添加到观众会话容器当中
        viewers.put(session.getId(), viewer);

        // 用当前的流媒体管道实例化一个新的观众媒体元素
        WebRtcEndpoint nextWebRtc = new WebRtcEndpoint.Builder(pipeline).build();

        // 添加候选监听器
        nextWebRtc.addIceCandidateFoundListener(new EventListener<IceCandidateFoundEvent>() {
            @Override
            public void onEvent(IceCandidateFoundEvent event) {
                JsonObject response = new JsonObject();
                response.addProperty("id","iceCandidate");

                // kms收集到自己的候选信息
                response.add("candidate", JsonUtils.toJsonObject(event.getCandidate()));
                try{
                    synchronized(session){
                        session.sendMessage(new TextMessage(response.toString()));
                    }
                }catch (IOException e){
                    e.printStackTrace();
                }
            }
        });

        // 设置观众对象自己的WebRtcEndpoint元素
        viewer.setWebRtcEndpoint(nextWebRtc);

        // 从主播端媒体元素的src端连接到当前观众端元素的sink端进行输，必须要媒体管道
        presenterUserSession.getWebRtcEndpoint().connect(nextWebRtc);

        // 处理sdpOffer提供
        String sdpOffer = jsonMessage.getAsJsonPrimitive("sdpOffer").getAsString();
        // 处理并拿到sdp应答
        String sdpAnswer = nextWebRtc.processOffer(sdpOffer);

        // 发送kms端的媒体元素的sdpAnswer应答
        JsonObject response = new JsonObject();
        response.addProperty("id", "viewerResponse");
        response.addProperty("response", "accepted");
        response.addProperty("sdpAnswer", sdpAnswer);


        // 同步发送消息
        synchronized (session) {
           viewer.sendMessage(response);
        }

        // 开始收集候选信息
        nextWebRtc.gatherCandidates();

    }
  }


    /**
     * 发送异常错误信息到前端
     */
    private void handleErrorResponse(Throwable throwable,WebSocketSession session,String responseId) throws IOException {
        JsonObject response = new JsonObject();
        response.addProperty("id",responseId);
        response.addProperty("response","rejected");
        response.addProperty("message",throwable.getMessage());
        session.sendMessage(new TextMessage(response.toString()));
    }


    /**
     * 停止直播相关的会话
     */
    private synchronized void stop(WebSocketSession session) throws IOException {
        String sessionId = session.getId();

        // 如果是主播端停止，则停止所有观看端的会话
        if (presenterUserSession != null && presenterUserSession.getSession().getId().equals(sessionId)) {

            for (UserSession viewer : viewers.values()) {
                JsonObject response = new JsonObject();
                response.addProperty("id", "stopCommunication");
                viewer.sendMessage(response);

            }

            // 释放媒体管线
            if (pipeline != null) {
                pipeline.release();
            }

            // 释放内存
            pipeline = null;
            presenterUserSession = null;
            viewers.clear();

            /**
             * 如果是观众端，则只销毁观众端会话，释放webRtcEndpoint元素
             */
        } else if (viewers.containsKey(sessionId)) {
            if (viewers.get(sessionId).getWebRtcEndpoint() != null) {
                viewers.get(sessionId).getWebRtcEndpoint().release();
            }
            viewers.remove(sessionId); // 移除websocket会话
        }

    }


}
