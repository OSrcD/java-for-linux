package com.mooc.beans;

public class Xbean {
    private int xid;
    private String name;

    public int getXid() {
        return xid;
    }

    public void setXid(int xid) {
        this.xid = xid;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "Xbean{" +
                "xid=" + xid +
                ", name='" + name + '\'' +
                '}';
    }
}
