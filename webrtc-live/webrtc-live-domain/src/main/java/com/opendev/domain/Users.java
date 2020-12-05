package com.opendev.domain;

import org.kurento.client.MediaPipeline;
import org.kurento.client.WebRtcEndpoint;

import java.security.Principal;
import java.util.List;

public class Users {
    
    private String sdpOffer;
    
    private Principal principal;

    private int roomNumber;
    
    private boolean isStartLive;

    private List<Users> audiences;

    private Users anchor;

    private String username;

    private WebRtcEndpoint webRtcEndpoint;

    private MediaPipeline pipeline;

    public WebRtcEndpoint getWebRtcEndpoint() {
        return webRtcEndpoint;
    }

    public void setWebRtcEndpoint(WebRtcEndpoint webRtcEndpoint) {
        this.webRtcEndpoint = webRtcEndpoint;
    }

    public MediaPipeline getPipeline() {
        return pipeline;
    }

    public void setPipeline(MediaPipeline pipeline) {
        this.pipeline = pipeline;
    }

    public String getSdpOffer() {
        return sdpOffer;
    }

    public void setSdpOffer(String sdpOffer) {
        this.sdpOffer = sdpOffer;
    }

    public Principal getPrincipal() {
        return principal;
    }

    public void setPrincipal(Principal principal) {
        this.principal = principal;
    }

    public int getRoomNumber() {
        return roomNumber;
    }

    public void setRoomNumber(int roomNumber) {
        this.roomNumber = roomNumber;
    }

    public boolean getStartLive() {
        return isStartLive;
    }

    public void setStartLive(boolean startLive) {
        isStartLive = startLive;
    }

    public List<Users> getAudiences() {
        return audiences;
    }

    public void setAudiences(List<Users> audiences) {
        this.audiences = audiences;
    }

    public Users getAnchor() {
        return anchor;
    }

    public void setAnchor(Users anchor) {
        this.anchor = anchor;
    }


    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }


    @Override
    public String toString() {
        return "MyUser{" +
                "sdpOffer='" + sdpOffer + '\'' +
                ", principal=" + principal +
                ", roomNumber='" + roomNumber + '\'' +
                ", isStartLive=" + isStartLive +
                ", audiences=" + audiences +
                ", anchor=" + anchor +
                ", username='" + username + '\'' +
                ", webRtcEndpoint=" + webRtcEndpoint +
                ", pipeline=" + pipeline +
                '}';
    }
}
