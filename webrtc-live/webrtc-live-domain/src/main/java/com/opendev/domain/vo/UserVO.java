package com.opendev.domain.vo;

public class UserVO {

    public UserVO() {

    }

    public UserVO(String username, int roomNumber) {
        this.roomNumber = roomNumber;
        this.username = username;
    }

    private int roomNumber;

    private String username;

    public int getRoomNumber() {
        return roomNumber;
    }

    public void setRoomNumber(int roomNumber) {
        this.roomNumber = roomNumber;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }
}
