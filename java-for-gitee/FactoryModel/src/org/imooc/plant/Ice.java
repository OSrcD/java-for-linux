package org.imooc.plant;

import org.imooc.component.Arms;
import org.imooc.component.Hair;

public class Ice implements Plant {

    private Hair hair;
    private Arms arms;


    public String getName(){
        return "蓝冰";
    }
    public void fight(){
        System.out.println("发射一颗冰子");
    }


    public Hair getHair() {
        return hair;
    }

    public void setHair(Hair hair) {
        this.hair = hair;
    }

    public Arms getArms() {
        return arms;
    }

    public void setArms(Arms arms) {
        this.arms = arms;
    }
}
