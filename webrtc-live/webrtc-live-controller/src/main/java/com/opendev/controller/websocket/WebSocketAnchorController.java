package com.opendev.controller.websocket;

import com.opendev.domain.Users;
import com.opendev.domain.bo.CandidateBO;
import com.opendev.domain.bo.SdpOfferBO;
import com.opendev.domain.manager.UserManager;
import com.opendev.utils.JsonUtils;
import org.kurento.client.*;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.messaging.handler.annotation.MessageMapping;
import org.springframework.messaging.simp.SimpMessagingTemplate;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestBody;
import java.security.Principal;
import java.util.Random;

@Controller
public class WebSocketAnchorController {


    @Autowired
    private SimpMessagingTemplate simpMessagingTemplate;


    @MessageMapping("/Anchor")
    public void presenter(@RequestBody SdpOfferBO sdpOffer, Principal principal){
        System.out.println(principal.getName());
        Users user = UserManager.users.get(principal.getName());
        user.setSdpOffer(sdpOffer.getSdpOffer());
        System.out.println(user);
        user.setStartLive(true);
        user.setRoomNumber((new Random().nextInt(90)) + 10);
        MediaPipeline mediaPipeline = UserManager.kurentoClient.createMediaPipeline();
        WebRtcEndpoint webRtcEndpoint = new WebRtcEndpoint.Builder(mediaPipeline).build();
        user.setWebRtcEndpoint(webRtcEndpoint);
        user.setPipeline(mediaPipeline);
        user.setPrincipal(principal);


        webRtcEndpoint.addIceCandidateFoundListener(new EventListener<IceCandidateFoundEvent>() {
            @Override
            public void onEvent(IceCandidateFoundEvent event) {
                String serverCdanidate = JsonUtils.objectToJson(event.getCandidate());
                simpMessagingTemplate.convertAndSendToUser(user.getUsername(),"/topic/serverIceCandidate",serverCdanidate);
            }
        });

        String sdpAnswer = user.getWebRtcEndpoint().processOffer(user.getSdpOffer());


        simpMessagingTemplate.convertAndSendToUser(user.getUsername(),"/topic/AnchorResponse",sdpAnswer);

        user.getWebRtcEndpoint().gatherCandidates();
    }

    @MessageMapping("/onIceCandidate")
    public void onIceCandidate(@RequestBody CandidateBO candidate, Principal principal){
        String username = principal.getName();
        Users users = UserManager.users.get(username);
        System.out.println(users + "客户端发送onIceCandidate消息" + candidate.getCandidate() );
        IceCandidate iceCandidate = new IceCandidate(candidate.getCandidate(), candidate.getSdpMid(), candidate.getSdpMLineIndex());
        if (users != null) {
            users.getWebRtcEndpoint().addIceCandidate(iceCandidate);
            System.out.println("添加客户端发送来的onIceCandidate成功");
        }

    }



}
